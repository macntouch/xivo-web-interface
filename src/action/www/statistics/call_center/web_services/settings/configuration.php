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

$access_category = 'settings';
$access_subcategory = 'configuration';

include(dwho_file::joinpath(dirname(__FILE__),'..','_common.php'));

$act = $_QRY->get('act');

switch($act)
{
	case 'view':
		if ($_QRY->get('id') === null)
		{
			$http_response->set_status_line(404);
			$http_response->send(true);
		}
		$appstats_conf = &$_XOBJ->get_application('stats_conf');

		if(($info = $appstats_conf->get($_QRY->get('id'))) === false)
		{
			$http_response->set_status_line(204);
			$http_response->send(true);
		}

		$_TPL->set_var('info',$info);
		break;
	case 'add':
		$appstats_conf = &$_XOBJ->get_application('stats_conf');

		if($appstats_conf->add_from_json() === true)
			$status = 200;
		else
			$status = 400;

		$http_response->set_status_line($status);
		$http_response->send(true);
		break;
	case 'edit':
		$appstats_conf = &$_XOBJ->get_application('stats_conf');

		if(($stats_conf = $appstats_conf->get($_QRY->get('id'))) === false)
			$status = 404;
		elseif($appstats_conf->edit_from_json($stats_conf) === true)
			$status = 200;
		else
			$status = 400;

		$http_response->set_status_line($status);
		$http_response->send(true);
		break;
	case 'delete':
		$appstats_conf = &$_XOBJ->get_application('stats_conf');

		if($appstats_conf->get($_QRY->get('id')) === false)
			$status = 404;
		else if($appstats_conf->delete() === true)
			$status = 200;
		else
			$status = 500;

		$http_response->set_status_line($status);
		$http_response->send(true);
		break;
	case 'search':
		$appstats_conf = &$_XOBJ->get_application('stats_conf', null, false);

		if(($list = $appstats_conf->get_stats_conf_search($_QRY->get('search'))) === false)
		{
			$http_response->set_status_line(204);
			$http_response->send(true);
		}

		$_TPL->set_var('list',$list);
		break;
	case 'list':
	default:
		$act = 'list';

		$appstats_conf = &$_XOBJ->get_application('stats_conf', null, false);

		if(($list = $appstats_conf->get_stats_conf_list()) === false)
		{
			$http_response->set_status_line(204);
			$http_response->send(true);
		}

		$_TPL->set_var('list',$list);
}

$_TPL->set_var('act',$act);
$_TPL->set_var('sum',$_QRY->get('sum'));
$_TPL->display('/genericjson');

?>
