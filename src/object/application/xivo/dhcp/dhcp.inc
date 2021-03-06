<?php

#
# XiVO Web-Interface
# Copyright (C) 2006-2014  Avencall
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

dwho_file::required(array(XIVO_PATH_OBJECT,'application','xivo.inc'),true);

class xivo_application_xivo_object_dhcp extends xivo_application_xivo_object_abstract
{
	var $_commonconf = false;
	var $_dhcp       = false;

	public function __construct(&$xobj)
	{
		parent::__construct($xobj);

		if(($this->_commonconf  = &$this->_xobj->get_module('commonconf')) === false
				|| ($this->_dhcp = &$this->_xobj->get_module('dhcp')) === false)
			return(false);

		return(true);
	}

	function get()
	{
		$data = $this->_dhcp->get(1);
		return $data;
	}

	function set($arr)
	{
		$this->_reset();

		if(($rs = $this->_dhcp->chk_values($arr)) === false)
			$this->_set_errors($this->_dhcp->get_filter_error());

		if($this->get_errnb() > 0)
			return false;

		if ($rs['active'] === 1 && (empty($rs['pool_start']) || empty($rs['pool_end'])))
		{
			$this->_set_errors(array('pool_start' => 'empty', 'pool_end' => 'empty'));
			return(false);
		}

		if($this->_dhcp->edit(1, $rs) === false)
			return false;

		// notify commonconf needs to be updated
		return $this->_commonconf->notify_changes();
	}
}

?>
