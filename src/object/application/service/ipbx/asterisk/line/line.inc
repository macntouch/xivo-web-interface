<?php

#
# XiVO Web-Interface
# Copyright (C) 2006-2016 Avencall
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#


dwho_file::required(array(XIVO_PATH_OBJECT,'application','service','ipbx','asterisk.inc'),true);
require_once(dwho_file::joinpath(XIVO_PATH_OBJECT,'confd', 'client.inc'));
require_once(dwho_file::joinpath(XIVO_PATH_OBJECT,'confd', 'facade', 'line.inc'));

class xivo_application_service_asterisk_line extends xivo_application_asterisk_abstract
{
	protected $_dso				= null;
	protected $_contextlist		= false;
	protected $_linefeatures 	= false;
	protected $_protocolname	= false;
	protected $_protocol		= false;
	protected $_entity			= false;
	protected $_conf			= array();
	private $_line_facade		= null;
	private $_sccp_option_mapper	= null;
	private $_sip_option_mapper	= null;

	public function __construct(&$service,&$dso,$param=null,$components=true)
	{
		parent::__construct($service);

		if(is_object($dso) === false)
			trigger_error('Invalid Datastorage object',E_USER_ERROR);

		$this->_dso = &$dso;

		if(($this->_linefeatures = &$this->_service->get_module('linefeatures')) === false
		|| ($_XOBJ = dwho_gct::get('xivo_object')) === false
		|| ($this->_entity = &$_XOBJ->get_module('entity')) === false)
			return(false);

		$client = ConfdClient::default_config();
		$this->_line_facade = new LineFacade($client);
		$this->_sccp_option_mapper = new SCCPOptionMapper();
		$this->_sip_option_mapper = new SIPOptionMapper();

		return(true);
	}

	public function get_nb($arr=null,$disable=null)
	{
		return($this->_dso->get_nb($arr,$disable));
	}

	public function get($id,$ipbxinfos=false)
	{
		$this->_info = $this->_origin = array();
		$this->_protocolname = false;

		$line = $this->_line_facade->get($id);
		if ($line === null) {
			return false;
		}

		$this->_info['line'] = $this->_origin['line'] = $line['line'];
		$this->_info['endpoint'] = $this->_origin['endpoint'] = $line['endpoint'];
		$this->_protocolname = $line['line']['protocol'];

		switch ($this->_protocolname) {
			case CONFD_LINE_PROTO_SCCP:
				$res = $this->_sccp_option_mapper->split_endpoint_options($this->_info['endpoint']);
				$this->_info['hidden_options'] = $res['hidden'];
				$this->_info['extra'] = $res['extra'];
				break;
			case CONFD_LINE_PROTO_SIP:
				$res = $this->_sip_option_mapper->split_endpoint_options($this->_info['endpoint']);
				$this->_info['free_options'] = $res['free'];
				$this->_info['extra'] = $res['extra'];
				break;
		}

		if ($ipbxinfos === true) {
			$this->_get_ipbx_infos();
		}

		return $this->_info;
	}

	function _get_ipbx_infos()
	{
		$this->_info['ipbx'] = false;

		if ($this->_protocolname === CONFD_LINE_PROTO_SIP) {
			$peer_name = $this->_info['endpoint']['username'];
			$ipbx_response = $this->_service->sip_show_peer($peer_name);
		} else {
			return false;
		}

		$ipbx_infos = $this->_parse_ipbx_infos($ipbx_response);

		$this->_info['ipbx'] = $ipbx_infos;
		return true;
	}

	function _parse_ipbx_infos($ipbx_response)
	{
		$ipbx_response_lines = explode("\n", $ipbx_response);

		$ipbx_infos = array();
		foreach($ipbx_response_lines as $line)
		{
			if (strstr($line, 'XIVO_USERID = '))
			{
				$item = explode('=',$line);
				$ipbx_infos['xivo_userid'] = trim($item[1]);
			} else {
				if (strpos($line,':'))
				{
					$item = explode(':',$line,2);

					// Remove bad characters and normalize the key values
					$item[0] = str_replace(array('.'),'',$item[0]);
					$item[0] = trim(str_replace(array('*','=','->'),' ',$item[0]));
					$item[0] = strtolower(str_replace(array(' ','-'),'_',$item[0]));

					$info_key = $item[0];
					$info_value = trim($item[1]);

					if (empty($info_value)) {
						$info_value = '&nbsp;';
					} else {
						$info_value = htmlspecialchars($info_value);
					}

					$ipbx_infos[$info_key] = $info_value;
				}
			}
		}
		return $ipbx_infos;
	}

	public function prepare_codec(&$element)
	{
		if(empty($this->_info) === true)
			return(false);

		$protocols = array('sip', 'sccp');

		foreach ($protocols as $protocol)
		{
			$allow_value = $element['protocol'][$protocol]['allow']['value'];
			$tmp = array();
			foreach($allow_value as $key => $value)
				$tmp[$value] = $value;
			$element['protocol'][$protocol]['allow']['value'] = $tmp;
		}
	}

	public function get_elements()
	{
		$r = array();

		$r['protocol'] = $this->_service->get_protocol_element();
		$this->prepare_codec($r);

		return($r);
	}

	public function get_lines_search($search,$where=array(),$disable=null,$order=null,$limit=null,$assoc=false)
	{
		return($this->_get_lines('search',$disable,$search,$where,$order,$limit,$assoc));
	}

	public function get_lines_list($where=array(),$disable=null,$order=null,$limit=null,$assoc=false)
	{
		return($this->_get_lines('list',$disable,'',$where,$order,$limit,$assoc));
	}

	private function _get_lines(
			$action,
			$disable=null,
			$search='',
			$where=array(),
			$order=null,
			$limit=null,
			$assoc=false)
	{
		$search = strval($search);

		switch($action)
		{
			case 'search':
				$rs = $this->_dso->search($search,$where,$disable,$order,$limit);
				break;
			case 'list':
			default:
				$rs = $this->_dso->get_all($where,$disable,$order,$limit);
		}

		$this->_cnt = $this->_dso->get_cnt();

		if($rs === false || ($nb = count($rs)) === 0)
			return(false);

		$r = array();

		for($i = 0;$i < $nb;$i++)
		{
			$ref = &$rs[$i];

			$linefeatures = dwho_array_startswith_key($ref,'linefeatures.',true);
			$linefeatures = $this->_linefeatures->_prepare($linefeatures);

			$r[$linefeatures['id']] = array();

			$userfeatures = dwho_array_startswith_key($ref,'userfeatures.',true);

			if (is_array($userfeatures) === true
			&& isset($userfeatures['firstname'], $userfeatures['lastname']))
				$linefeatures['useridentity'] = $userfeatures['firstname'].' '.$userfeatures['lastname'];
			else
				$linefeatures['useridentity'] = '-';

			switch($linefeatures['protocol'])
			{
				case XIVO_SRE_IPBX_AST_PROTO_SIP:
					$sip = dwho_array_startswith_key($ref,'usersip.',true);
					$sip['identity'] = strtoupper($sip['protocol']).'/'.$sip['name'];
					$r[$linefeatures['id']] = array_merge($sip,$linefeatures);
					break;
				case XIVO_SRE_IPBX_AST_PROTO_SCCP:
					$sccp = dwho_array_startswith_key($ref,'sccpline.',true);
					$sccp['protocol'] = 'SCCP';
					$sccp['identity'] = strtoupper($sccp['protocol']).'/'.$sccp['name'];
					$r[$linefeatures['id']] = array_merge($sccp,$linefeatures);
					break;
				case XIVO_SRE_IPBX_AST_PROTO_CUSTOM:
					$custom = dwho_array_startswith_key($ref,'usercustom.',true);
					$custom['identity'] = $custom['interface'];
					$r[$linefeatures['id']] = array_merge($custom,$linefeatures);
					break;
			}

			$entity = dwho_array_startswith_key($ref,'entity.',true);
			$r[$linefeatures['id']]['entity'] = $this->_entity->_prepare($entity);
		}

		if(empty($r) === true)
			return(false);
		else if((bool) $assoc === false)
			return(array_values($r));

		return($r);
	}

	public function set_add($arr,$protocolname)
	{
		if ($protocolname !== CONFD_LINE_PROTO_CUSTOM
		&& $protocolname !== CONFD_LINE_PROTO_SIP) {
			return false;
		}

		$this->_protocolname = $protocolname;

		return($this->_set('add',$arr));
	}

	public function set_edit($arr)
	{
		if(empty($this->_info) === true)
			return(false);

		return($this->_set('edit',$arr));
	}

	private function _set($action,$arr)
	{
		$this->_reset();

		$this->_set_line($action, $arr);
		$this->_set_endpoint($action, $arr);

		// make sure the page is redisplayed with the fields filled on error
		switch ($this->_protocolname) {
			case CONFD_LINE_PROTO_SCCP:
				$res = $this->_sccp_option_mapper->split_endpoint_options($this->_result['endpoint']);
				$this->_set_result('extra', $res['extra']);
				break;
			case CONFD_LINE_PROTO_SIP:
				$res = $this->_sip_option_mapper->split_endpoint_options($this->_result['endpoint']);
				$this->_set_result('free_options', $res['free']);
				$this->_set_result('extra', $res['extra']);
				break;
		}

		return true;
	}

	private function _set_line($action, $arr)
	{
		if ($action === 'add') {
			$line = array(
				'context' => $arr['protocol']['context'],
			);
		} else {
			$line = $this->_info['line'];
		}

		$this->_set_result('line', $line);
	}

	private function _set_endpoint($action, $arr)
	{
		if ($action === 'add') {
			$endpoint = array();
		} else {
			$endpoint = $this->_info['endpoint'];
		}

		switch ($this->_protocolname) {
			case CONFD_LINE_PROTO_CUSTOM:
				$endpoint['interface'] = $arr['protocol']['interface'];
				break;
			case CONFD_LINE_PROTO_SCCP:
				$options = array();
				if (isset($this->_info['hidden_options'])) {
					$options = $this->_info['hidden_options'];
				} else {
					$options = array();
				}
				if (isset($arr['protocol']['disallow'])) {
					$options[] = array('disallow', $arr['protocol']['disallow']);
				}
				if (isset($arr['protocol']['allow'])) {
					$options[] = array('allow', implode(',',$arr['protocol']['allow']));
				}

				$endpoint['options'] = $options;
				break;
			case CONFD_LINE_PROTO_SIP:
				$endpoint['username'] = $arr['protocol']['name'];
				$endpoint['secret'] = $arr['protocol']['secret'];

				$options = array();
				if (!empty($arr['protocol']['language'])) {
					$options[] = array('language', $arr['protocol']['language']);
				}
				if (!empty($arr['protocol']['callerid'])) {
					$options[] = array('callerid', $arr['protocol']['callerid']);
				}
				if (!empty($arr['protocol']['nat'])) {
					$options[] = array('nat', $arr['protocol']['nat']);
				}
				if (!empty($arr['protocol']['dtmfmode'])) {
					$options[] = array('dtmfmode', $arr['protocol']['dtmfmode']);
				}
				if (!empty($arr['protocol']['qualify'])) {
					$options[] = array('qualify', $arr['protocol']['qualify']);
				}
				if (isset($arr['protocol']['disallow'])) {
					$options[] = array('disallow', $arr['protocol']['disallow']);
				}
				if (isset($arr['protocol']['allow'])) {
					$options[] = array('allow', implode(',',$arr['protocol']['allow']));
				}
				if (isset($arr['options'])) {
					for($i = 0; $i < count($arr['options']['optionname']); $i++) {
						$name = $arr['options']['optionname'][$i];
						$value = $arr['options']['optionvalue'][$i];
						if ($name === 'host') {
							$endpoint['host'] = $value;
						} elseif ($name === 'type') {
							$endpoint['type'] = $value;
						} elseif (trim($name) !== '' && trim($value) !== '') {
							$options[] = array($name, $value);
						}
					}
				}

				$endpoint['options'] = $options;
				break;
		}

		$this->_set_result('endpoint', $endpoint);
	}

	function add()
	{
		if ($this->_protocolname === false) {
			return false;
		}

		$line = $this->_line_facade->create($this->_result['line'], $this->_result['endpoint'], $this->_protocolname);

		return $line !== null;
	}

	function edit()
	{
		if (empty($this->_info) === true
		|| $this->_protocolname === false) {
			return false;
		}

		return $this->_line_facade->update_endpoint($this->_info['endpoint']['id'], $this->_result['endpoint'], $this->_protocolname);
	}

	function delete()
	{
		if (empty($this->_info) === true
		|| $this->_protocolname === false) {
			return false;
		}

		$this->_line_facade->delete($this->_info['line']['id']);

		return true;
	}

	function enable()
	{
		if ($this->_protocolname === false
		|| ($this->_protocol = &$this->_service->get_protocol_module($this->_protocolname)) === false) {
			return false;
		}

		$r = true;

		$this->_status = 'enable';
		$this->_return = array();

		if($this->enable_protocol() === false
		|| $this->enable_linefeatures() === false)
		{
			$r = false;
			$this->_reverse_enable_disable();
		}

		$this->_status = '';

		return($r);
	}

	function disable()
	{
		if ($this->_protocolname === false
		|| ($this->_protocol = &$this->_service->get_protocol_module($this->_protocolname)) === false) {
			return false;
		}

		$r = true;

		$this->_status = 'disable';
		$this->_return = array();

		if($this->disable_protocol() === false
		|| $this->disable_linefeatures() === false)
		{
			$r = false;
			$this->_reverse_enable_disable();
		}

		$this->_status = '';

		return(true);
	}

	function enable_protocol()
	{
		return($this->_enable_disable_protocol(false));
	}

	function disable_protocol()
	{
		return($this->_enable_disable_protocol(true));
	}

	function _enable_disable_protocol($disable=false)
	{
		if((bool) $disable === false)
			$r = $this->_protocol->enable($this->_info['endpoint']['id']);
		else
			$r = $this->_protocol->disable($this->_info['endpoint']['id']);

		if($this->_status === 'enable' || $this->_status === 'disable')
			$this->_return['protocol'] = $r;

		return($r);
	}

	function enable_linefeatures()
	{
		return($this->_enable_disable_linefeatures(false));
	}

	function disable_linefeatures()
	{
		return($this->_enable_disable_linefeatures(true));
	}

	function _enable_disable_linefeatures($disable=false)
	{
		if((bool) $disable === false)
			$r = $this->_linefeatures->enable($this->_info['line']['id']);
		else
			$r = $this->_linefeatures->disable($this->_info['line']['id']);

		if($this->_status === 'enable' || $this->_status === 'disable')
			$this->_return['linefeatures'] = $r;

		return($r);
	}

	function _reverse_enable_disable()
	{
		if(($this->_status !== 'enable' && $this->_status !== 'disable') === true
		|| is_array($this->_return) === false
		|| empty($this->_return) === true)
			return(false);

		$disable = $this->_status === 'enable';

		$this->_status = '';

		foreach($this->_return as $key => $val)
		{
			if($val === false)
				continue;

			switch($key)
			{
				case 'protocol':
					$this->_enable_disable_protocol($disable);
					break;
				case 'linefeatures':
					$this->_enable_disable_linefeatures($disable);
					break;
			}
		}

		return(true);
	}

	function gen_password($len, $lower=false)
	{
		$pwd = '';
		for($i = 0; $i < $len; $i++)
		{
			$r = mt_rand(0, 35);
			$pwd .= $r < 10?$r:chr($r-10+65);
		}

		if($lower)
			$pwd = strtolower($pwd);

		return $pwd;
	}
}


class SCCPOptionMapper {

	private $extra_options = array(
			'allow',
			'disallow',
	);

	public function split_endpoint_options($endpoint)
	{
		$extra = array();
		$hidden = array();

		foreach($endpoint['options'] as $endpoint_option) {
			$name = $endpoint_option[0];
			if (in_array($name, $this->extra_options)) {
				$extra[$name] = $endpoint_option[1];
			} else {
				$hidden[] = $endpoint_option;
			}
		}

		return array('extra' => $extra, 'hidden' => $hidden);
	}
}


class SIPOptionMapper {

	private $extra_options = array(
			'allow',
			'callerid',
			'disallow',
			'dtmfmode',
			'language',
			'qualify',
			'nat',
	);

	public function split_endpoint_options($endpoint)
	{
		$free = array();
		$extra = array();

		if (isset($endpoint['host'])) {
			$free[] = array('host', $endpoint['host']);
		}
		if (isset($endpoint['type'])) {
			$free[] = array('type', $endpoint['type']);
		}

		foreach($endpoint['options'] as $endpoint_option) {
			$name = $endpoint_option[0];
			if (in_array($name, $this->extra_options)) {
				$extra[$name] = $endpoint_option[1];
			} else {
				$free[] = $endpoint_option;
			}
		}

		return array('free' => $free, 'extra' => $extra);
	}
}

?>
