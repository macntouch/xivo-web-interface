<?php

#
# XiVO Web-Interface
# Copyright (C) 2006-2015  Avencall
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

abstract class dwho_gateclass
{
	private static $_class = array();

	public static function set($obj,$name='')
	{
		$name = (string) $name;

		if(is_object($obj) === false)
			return false;
		else if($name === '')
			$name = get_class($obj);

		if($name !== '' && preg_match('/^[a-z0-9\-_]+$/i',$name) !== 1)
			return false;
		#else if(isset(self::$_class[$name]) === false)
		self::$_class[$name] = $obj;

		return true;
	}

	public static function get($name)
	{
		$r = false;

		$name = (string) $name;

		if(isset(self::$_class[$name]) === true)
			$r = self::$_class[$name];

		return $r;
	}

	public static function set_get($obj,$name='')
	{
		$r = false;

		$name = (string) $name;

		if(self::set($obj,$name) === true)
			$r = self::get(($name === '' ? get_class($obj) : $name));

		return $r;
	}

	public static function is_valid($name)
	{
		return (isset(self::$_class[$name]) === true && is_object(self::$_class[$name]) === true);
	}
}

abstract class dwho_gct
{
	public static function set($obj,$name='')
	{
		return dwho_gateclass::set($obj,$name);
	}

	public static function get($name)
	{
		return dwho_gateclass::get($name);
	}

	public static function set_get($obj,$name='')
	{
		return dwho_gateclass::set_get($obj,$name);
	}

	public static function is_valid($name)
	{
		return dwho_gateclass::is_valid($name);
	}
}

?>
