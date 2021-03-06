<?php
#
# XiVO Web-Interface
# Copyright (C) 2012-2014  Avencall
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

xivo_service_asterisk::required(array('abstract','abstract.inc'),true);

class xivo_service_asterisk_cti_profile_xlet extends xivo_service_asterisk_abstract
{
	var $_dso			= null;
	var $_name			= 'cti_profile_xlet';
	var $_filter		= false;
	var $_origin		= false;
	var $_origin_list	= false;

	public function __construct(&$sre,&$dso)
	{
		if(is_object($sre) === false)
			trigger_error('Invalid service in '.__CLASS__,E_USER_ERROR);

		if(is_object($dso) === false)
			trigger_error('Invalid datastorage in '.__CLASS__,E_USER_ERROR);

		$this->_sre = &$sre;
		$this->_dso = &$dso;

		$this->_load_config();
	}

	function _prepare($data)
	{
		$data['profile_id'] = (int) $data['profile_id'];
		$data['xlet_id'] = (int) $data['xlet_id'];
		$data['layout_id'] = (int) $data['layout_id'];
		$data['closable'] = dwho_bool($data['layout_id']);
		$data['movable'] = dwho_bool($data['movable']);
		$data['floating'] = dwho_bool($data['floating']);
		$data['scrollable'] = dwho_bool($data['scrollable']);
		$data['order'] = ($data['order'] === null) ? null : (int) $data['order'];

		return($data);
	}
}

?>
