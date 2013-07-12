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
$array['xivoserver'] = array();
$array['xivoserver']['option'] = array();
$array['xivoserver']['option']['ssl_verifypeer'] = false;

$array['ldapfilter'] = array();

$array['supported_vendors'] = array('aastra', 'polycom', 'snom', 'thomson', 'yealink', 'cisco');

$array['useragent_to_vendor'] = array();
$array['useragent_to_vendor']['aastra'] = 'aastra';
$array['useragent_to_vendor']['polycom'] = 'polycom';
$array['useragent_to_vendor']['snom'] = 'snom';
$array['useragent_to_vendor']['thomson'] = 'thomson';
$array['useragent_to_vendor']['yealink'] = 'yealink';
$array['useragent_to_vendor']['allegro'] = 'cisco';
$array['useragent_to_vendor']['cisco'] = 'cisco';

?>