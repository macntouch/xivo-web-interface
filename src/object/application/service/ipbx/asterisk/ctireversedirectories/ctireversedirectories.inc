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

dwho_file::required(array(XIVO_PATH_OBJECT,'application','service','ipbx','asterisk.inc'),true);

class xivo_application_service_asterisk_ctireversedirectories extends xivo_application_asterisk_abstract
{
	var $_ctireversedirectories = false;

	public function __construct(&$service,$param=null,$components=true)
	{
		parent::__construct($service);

		if(($this->_ctireversedirectories = &$this->_service->get_module('ctireversedirectories')) === false)
			return false;

		return true;
	}

	function get()
	{
		$data = $this->_ctireversedirectories->get(1);

		return $data;
	}

	function set($arr)
	{
		$this->_reset();

		if(($rs = $this->_ctireversedirectories->chk_values($arr)) === false)
		{
			$this->_set_error($this->_ctireversedirectories->get_filter_error());
			return false;
		}

		$keys = array('directories');
		foreach(array_keys($arr) as $key)
		{
			if(!in_array($key, $keys))
				unset($arr[$key]);
		}

		if($this->_ctireversedirectories->edit(1, $arr) === false)
			return false;

		return true;
	}
}

?>
