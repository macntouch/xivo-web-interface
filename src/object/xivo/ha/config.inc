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

$array = array();
$array['element'] = array();

$array['element']['active'] = array();
$array['element']['active']['value']   = array(0,1);
$array['element']['active']['default'] = 0;
$array['element']['active']['set']     = true;

$array['element']['netaddr'] = array();
$array['element']['netaddr']['default'] = '';

$array['element']['netmask'] = array();
$array['element']['netmask']['default'] = '';

$array['element']['mcast'] = array();
$array['element']['mcast']['default'] = '';

$array['element']['node1_ip'] = array();
$array['element']['node1_ip']['default'] = '';

$array['element']['node1_name'] = array();
$array['element']['node1_name']['default'] = '';

$array['element']['node2_ip'] = array();
$array['element']['node2_ip']['default'] = '';

$array['element']['node2_name'] = array();
$array['element']['node2_name']['default'] = '';

$array['element']['cluster_name'] = array();
$array['element']['cluster_name']['default'] = '';

$array['element']['cluster_group'] = array();
$array['element']['cluster_group']['value']   = array(0,1);
$array['element']['cluster_group']['default'] = 0;
$array['element']['cluster_group']['set']     = true;

$array['element']['cluster_itf_data'] = array();
$array['element']['cluster_itf_data']['default'] = '';

$array['element']['cluster_itf_master_ip'] = array();
$array['element']['cluster_itf_master_ip']['default'] = '';

$array['element']['cluster_itf_slave_ip'] = array();
$array['element']['cluster_itf_slave_ip']['default'] = '';

$array['element']['cluster_monitor'] = array();
$array['element']['cluster_monitor']['default'] = 0;

$array['element']['cluster_timeout'] = array();
$array['element']['cluster_timeout']['default'] = 0;

$array['element']['cluster_mailto'] = array();
$array['element']['cluster_mailto']['default'] = '';
$array['element']['cluster_mailto']['null'] = true;

$array['element']['cluster_pingd'] = array();
$array['element']['cluster_pingd']['default'] = '';
$array['element']['cluster_pingd']['null'] = true;


### filters ###
$array['filter'] = array();

?>