<?php

#
# XiVO Web-Interface
# Copyright (C) 2006-2011  Avencall
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

dwho::load_class('dwho_prefs');
$prefs = new dwho_prefs('phonebook');

$act     = isset($_QR['act']) === true ? $_QR['act'] : '';
$page    = dwho_uint($prefs->get('page', 1));
$search  = strval($prefs->get('search', ''));
$context = strval($prefs->get('context', ''));
$sort    = $prefs->flipflop('sort', 'displayname');

$param = array();
$param['act'] = 'list';

if($search !== '')
	$param['search'] = $search;

$appphonebook = &$ipbx->get_application('phonebook');

switch($act)
{
	case 'add':
		$result = $fm_save = $error = null;

		if(isset($_QR['fm_send']) === true && dwho_issa('phonebook',$_QR) === true)
		{
			if($appphonebook->set_add($_QR) === false
			|| $appphonebook->add() === false)
			{
				$fm_save = false;
				$result = $appphonebook->get_result();
				$error  = $appphonebook->get_error();
			}
			else
			{
				$ipbx->discuss(array('xivo[phonebooklist,update]'));
				$ipbx->discuss_dird(array('update-phonebook'));
				$_QRY->go($_TPL->url('service/ipbx/pbx_services/phonebook'),$param);
			}
		}

		if(dwho_issa('phonebook',$result) === false || empty($result['phonebook']) === true)
			$result['phonebook'] = null;

		if(dwho_issa('phonebookaddress',$result) === false || empty($result['phonebookaddress']) === true)
			$result['phonebookaddress'] = null;

		if(dwho_issa('phonebooknumber',$result) === false || empty($result['phonebooknumber']) === true)
			$result['phonebooknumber'] = null;

		$dhtml = &$_TPL->get_module('dhtml');
		$dhtml->set_js('js/dwho/submenu.js');

		$_TPL->set_var('info'   ,$result);
		$_TPL->set_var('error'  ,$error);
		$_TPL->set_var('fm_save',$fm_save);
		$_TPL->set_var('element',$appphonebook->get_elements());
		$_TPL->set_var('territory',dwho_i18n::get_territory_translated_list());
		break;
	case 'edit':
		$appphonebook = &$ipbx->get_application('phonebook');

		if(isset($_QR['id']) === false || ($info = $appphonebook->get($_QR['id'])) === false)
			$_QRY->go($_TPL->url('service/ipbx/pbx_services/phonebook'),$param);

		$result = $fm_save = $error = null;
		$return = &$info;

		if(isset($_QR['fm_send']) === true && dwho_issa('phonebook',$_QR) === true)
		{
			$return = &$result;

			if($appphonebook->set_edit($_QR) === false
			|| $appphonebook->edit() === false)
			{
				$fm_save = false;
				$result = $appphonebook->get_result();
				$error  = $appphonebook->get_error();
			}
			else
			{
				$ipbx->discuss(array('xivo[phonebooklist,update]'));
				$ipbx->discuss_dird(array('update-phonebook'));
				$_QRY->go($_TPL->url('service/ipbx/pbx_services/phonebook'),$param);
			}
		}

		if(dwho_issa('phonebook',$return) === false || empty($return['phonebook']) === true)
			$return['phonebook'] = null;

		if(dwho_issa('phonebookaddress',$return) === false || empty($return['phonebookaddress']) === true)
			$return['phonebookaddress'] = null;

		if(dwho_issa('phonebooknumber',$return) === false || empty($return['phonebooknumber']) === true)
			$return['phonebooknumber'] = null;

		$dhtml = &$_TPL->get_module('dhtml');
		$dhtml->set_js('js/dwho/submenu.js');

		$_TPL->set_var('id'              , $info['phonebook']['id']);
		$_TPL->set_var('info'            , $return);
		$_TPL->set_var('error'           , $error);
		$_TPL->set_var('phonebookaddress', $return['phonebookaddress']);
		$_TPL->set_var('phonebooknumber' , $return['phonebooknumber']);
		$_TPL->set_var('fm_save',$fm_save);
		$_TPL->set_var('element',$appphonebook->get_elements());
		$_TPL->set_var('territory',dwho_i18n::get_territory_translated_list());
		break;
	case 'delete':
		$param['page'] = $page;

		if(isset($_QR['id']) === false || $appphonebook->get($_QR['id']) === false)
			$_QRY->go($_TPL->url('service/ipbx/pbx_services/phonebook'),$param);

		$appphonebook->delete();

		$ipbx->discuss(array('xivo[phonebooklist,update]'));
		$ipbx->discuss_dird(array('update-phonebook'));
		$_QRY->go($_TPL->url('service/ipbx/pbx_services/phonebook'),$param);
		break;
	case 'deletes':
		$param['page'] = $page;

		if(($values = dwho_issa_val('phonebook',$_QR)) === false)
			$_QRY->go($_TPL->url('service/ipbx/pbx_services/phonebook'),$param);

		$nb = count($values);

		for($i = 0;$i < $nb;$i++)
		{
			if($appphonebook->get($values[$i]) !== false)
				$appphonebook->delete();
		}

		$ipbx->discuss(array('xivo[phonebooklist,update]'));
		$ipbx->discuss_dird(array('update-phonebook'));
		$_QRY->go($_TPL->url('service/ipbx/pbx_services/phonebook'),$param);
		break;
	case 'import':
		if(isset($_QR['fm_send']) === true)
		{
			$appphonebook->import_csv();
			$ipbx->discuss(array('xivo[phonebooklist,update]'));
			$ipbx->discuss_dird(array('update-phonebook'));
			$_QRY->go($_TPL->url('service/ipbx/pbx_services/phonebook'),$param);
		}

		$_TPL->set_var('import_file',$appphonebook->get_config_import_file());
		break;

	case 'list':
	default:
		$act = 'list';
		$prevpage = $page - 1;
		$nbbypage = XIVO_SRE_IPBX_AST_NBBYPAGE;

		$order = array();
		//$order['displayname'] = SORT_ASC;
		//$order['firstname'] = SORT_ASC;
		//$order['lastname'] = SORT_ASC;
		$order[$sort[1]] = $sort[0];

		$limit = array();
		$limit[0] = $prevpage * $nbbypage;
		$limit[1] = $nbbypage;

		if($search !== '')
			$list = $appphonebook->get_phonebook_search($search,$order,$limit);
		else
			$list = $appphonebook->get_phonebook_list($order,$limit);

		$total = $appphonebook->get_cnt();

		if($list === false && $total > 0 && $prevpage > 0)
		{
			$param['page'] = $prevpage;
			$_QRY->go($_TPL->url('service/ipbx/pbx_services/phonebook'),$param);
		}

		$_TPL->set_var('total',$total);
		$_TPL->set_var('pager',dwho_calc_page($page,$nbbypage,$total));
		$_TPL->set_var('list',$list);
		$_TPL->set_var('search',$search);
		$_TPL->set_var('sort',$sort);
}

$_TPL->set_var('act',$act);

$menu = &$_TPL->get_module('menu');
$menu->set_top('top/user/'.$_USR->get_info('meta'));
$menu->set_left('left/service/ipbx/'.$ipbx->get_name());
$menu->set_toolbar('toolbar/service/ipbx/'.$ipbx->get_name().'/pbx_services/phonebook');

$_TPL->set_bloc('main','service/ipbx/'.$ipbx->get_name().'/pbx_services/phonebook/'.$act);
$_TPL->set_struct('service/ipbx/'.$ipbx->get_name());
$_TPL->display('index');

?>
