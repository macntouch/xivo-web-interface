<?php

#
# XiVO Web-Interface
# Copyright (C) 2006-2016  Avencall
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

require_once(dwho_file::joinpath(XIVO_PATH_OBJECT,'user','abstract.inc'));

class xivo_user_admin extends xivo_user_abstract
{
	public function __construct()
	{
		parent::__construct();

		$this->_load_config(XIVO_PATH_OBJECT.DWHO_SEP_DIR.'user');
		$this->_load_dso();

		if(is_object($this->_dso) === false)
			trigger_error('Invalid datastorage in '.__CLASS__,E_USER_ERROR);

		$this->load_by_session();
		$this->_load_acl();
	}

	function add($arr)
	{
		$this->reset_error();

		if(is_array($arr) === false
		|| ($arr_filter = $this->_load_filter('add', $arr['meta'])) === false)
		{
			$this->_error['system'] = 'system error';
			$this->_errornb++;
			return(false);
		}

		$filter = new dwho_filter($arr_filter);

		$err = false;
		if($filter->chk($arr) === false)
		{
			$this->_error = &$filter->get_error();
			$err = true;
		}

		if($this->exists(array('login' => $arr['login'])))
		{
			$this->_error['login'] = 'alreadyexist';
			$err = true;
		}

		if($err)
			return(false);

		return(parent::add($filter->get_result()));
	}

	function edit($meta,$arr)
	{
		if(is_array($arr) === false
		|| isset($arr['id']) === false
		|| ($arr_filter = $this->_load_filter('edit',$meta)) === false)
			return(false);

		$filter = new dwho_filter($arr_filter);

		if($filter->chk($arr) === false)
		{
			$this->_error = &$filter->get_error();
			return(false);
		}

		return($this->_dso->edit($arr['id'],$filter->get_result()));
	}
}

?>
