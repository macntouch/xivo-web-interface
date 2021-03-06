<?php

#
# XiVO Web-Interface
# Copyright (C) 2006-2016 Avencall
# Copyright (C) 2016 Proformatique Inc.
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

$array['element']['uuid'] = array();
$array['element']['uuid']['null'] = false;

$array['element']['firstname'] = array();
$array['element']['firstname']['default'] = '';

$array['element']['lastname'] = array();
$array['element']['lastname']['default'] = '';

$array['element']['entityid'] = array();
$array['element']['entityid']['default'] = 0;

$array['element']['callerid'] = array();
$array['element']['callerid']['default'] = '';
$array['element']['callerid']['null'] = true;

$array['element']['agentid'] = array();
$array['element']['agentid']['default'] = 0;
$array['element']['agentid']['null'] = true;

$array['element']['ringseconds'] = array();
$array['element']['ringseconds']['default'] = 30;
$array['element']['ringseconds']['setdef'] = true;

$array['element']['simultcalls'] = array();
$array['element']['simultcalls']['value'] = array(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20);
$array['element']['simultcalls']['default'] = 5;
$array['element']['simultcalls']['setdef'] = true;

$array['element']['enableclient'] = array();
$array['element']['enableclient']['value'] = array(0,1);
$array['element']['enableclient']['default'] = 0;
$array['element']['enableclient']['set'] = true;

$array['element']['loginclient'] = array();
$array['element']['loginclient']['default'] = '';

$array['element']['passwdclient'] = array();
$array['element']['passwdclient']['default'] = '';

$array['element']['cti_profile_id'] = array();
$array['element']['cti_profile_id']['default'] = '';
$array['element']['cti_profile_id']['null'] = true;

$array['element']['enablehint'] = array();
$array['element']['enablehint']['value'] = array(0,1);
$array['element']['enablehint']['default'] = 1;
$array['element']['enablehint']['set'] = true;

$array['element']['enablevoicemail'] = array();
$array['element']['enablevoicemail']['value'] = array(0,1);
$array['element']['enablevoicemail']['default'] = 0;
$array['element']['enablevoicemail']['set'] = true;

$array['element']['enablexfer'] = array();
$array['element']['enablexfer']['value'] = array(0,1);
$array['element']['enablexfer']['default'] = 0;
$array['element']['enablexfer']['set'] = true;

$array['element']['dtmf_hangup'] = array();
$array['element']['dtmf_hangup']['value'] = array(0,1);
$array['element']['dtmf_hangup']['default'] = 0;
$array['element']['dtmf_hangup']['set'] = true;

$array['element']['enableonlinerec'] = array();
$array['element']['enableonlinerec']['value'] = array(0,1);
$array['element']['enableonlinerec']['default'] = 0;
$array['element']['enableonlinerec']['set'] = true;

$array['element']['callrecord'] = array();
$array['element']['callrecord']['value'] = array(0,1);
$array['element']['callrecord']['default'] = 0;
$array['element']['callrecord']['set'] = true;

$array['element']['incallfilter'] = array();
$array['element']['incallfilter']['value'] = array(0,1);
$array['element']['incallfilter']['default'] = 0;
$array['element']['incallfilter']['set'] = true;

$array['element']['enablednd'] = array();
$array['element']['enablednd']['value'] = array(0,1);
$array['element']['enablednd']['default'] = 0;
$array['element']['enablednd']['set'] = true;

$array['element']['enablerna'] = array();
$array['element']['enablerna']['value'] = array(0,1);
$array['element']['enablerna']['default'] = 0;
$array['element']['enablerna']['set'] = true;

$array['element']['destrna'] = array();
$array['element']['destrna']['default'] = '';

$array['element']['enablebusy'] = array();
$array['element']['enablebusy']['value'] = array(0,1);
$array['element']['enablebusy']['default'] = 0;
$array['element']['enablebusy']['set'] = true;

$array['element']['destbusy'] = array();
$array['element']['destbusy']['default'] = '';

$array['element']['enableunc'] = array();
$array['element']['enableunc']['value'] = array(0,1);
$array['element']['enableunc']['default'] = 0;
$array['element']['enableunc']['set'] = true;

$array['element']['destunc'] = array();
$array['element']['destunc']['default'] = '';

$array['element']['context'] = array();
$array['element']['context']['default'] = '';

$array['element']['musiconhold'] = array();
$array['element']['musiconhold']['default'] = XIVO_SRE_IPBX_AST_MOH_DEFAULT;

$array['element']['outcallerid'] = array();
$array['element']['outcallerid']['value'] = array('default','anonymous');
$array['element']['outcallerid']['default'] = 'default';
$array['element']['outcallerid']['setdef'] = true;

$array['element']['outcallerid-type'] = array();
$array['element']['outcallerid-type']['value'] = array('default','anonymous','custom');
$array['element']['outcallerid-type']['default'] = 'default';
$array['element']['outcallerid-type']['unset'] = true;

$array['element']['outcallerid-custom'] = array();
$array['element']['outcallerid-custom']['default'] = '';
$array['element']['outcallerid-custom']['unset'] = true;

$array['element']['mobilephonenumber'] = array();
$array['element']['mobilephonenumber']['default'] = '';

$array['element']['email'] = array();
$array['element']['email']['default'] = '';
$array['element']['email']['null'] = true;

$array['element']['userfield'] = array();
$array['element']['userfield']['default'] = '';

$array['element']['bsfilter'] = array();
$array['element']['bsfilter']['value'] = array('no','boss','secretary');
$array['element']['bsfilter']['default'] = 'no';
$array['element']['bsfilter']['setdef'] = true;

$array['element']['preprocess_subroutine'] = array();
$array['element']['preprocess_subroutine']['default'] = '';
$array['element']['preprocess_subroutine']['null'] = true;

$array['element']['language'] = array();
$array['element']['language']['value'] = dwho_i18n::get_supported_language_list();
$array['element']['language']['default'] = '';
$array['element']['language']['null'] = true;

$array['element']['timezone'] = array();
$array['element']['timezone']['default'] = '';

$array['element']['description'] = array();
$array['element']['description']['default'] = '';

$array['element']['ringintern'] = array();
$array['element']['ringintern']['default'] = '';

$array['element']['ringextern'] = array();
$array['element']['ringextern']['default'] = '';

$array['element']['ringgroup'] = array();
$array['element']['ringgroup']['default'] = '';

$array['element']['ringforward'] = array();
$array['element']['ringforward']['default'] = '';

$array['element']['rightcallcode'] = array();
$array['element']['rightcallcode']['default'] = '';

$array['element']['func_key_private_template_id'] = array();
$array['element']['func_key_private_template_id']['default'] = '';

$array['element']['func_key_template_id'] = array();
$array['element']['func_key_template_id']['default'] = '';
$array['element']['func_key_template_id']['null'] = true;


$array['filter'] = array();
$array['filter']['firstname'] = array('cast' => 'sgraph','maxlen' => 128);
$array['filter']['lastname'] = array('set' => false,'chk' => 2,'cast' => 'sgraph','maxlen' => 128);
$array['filter']['entityid'] = array('cast' => 'ulongint');
$array['filter']['callerid'] = array('set'	=> false,
				     'chk'	=> 2,
				     'maxlen'	=> 80,
				     'regexp'	=> '/^'.XIVO_SRE_IPBX_AST_REGEXP_CALLERID.'$/u',
				     'notag'	=> false);
$array['filter']['agentid'] = array('set' => false,'chk' => 2,'cast' => 'ulongint');
$array['filter']['ringseconds'] = array('set' => false,'chk' => 2,'cast' => 'uint','between' => array(0,60));
$array['filter']['simultcalls'] = array('set' => false,'chk' => 2,'cast' => 'uint','between' => array(1,20));
$array['filter']['enableclient'] = array('bool' => true);
$array['filter']['loginclient'] = array('set'		=> false,
					'chk'		=> 2,
					'minlen'	=> 2,
					'maxlen'	=> 254,
					'regexp'	=> '/^[a-zA-Z0-9-\._~\!\$&\'\(\)\*\+,;=%@]+$/');
$array['filter']['passwdclient'] = array('set'		=> false,
					 'chk'		=> 2,
					 'minlen'	=> 4,
					 'maxlen'	=> 64,
					 'regexp'	=> '/^[a-zA-Z0-9-\._~\!\$&\'\(\)\*\+,;=:%]+$/');
$array['filter']['cti_profile_id'] = array('set' => false,'chk' => 2,'cast' => 'ulongint');
$array['filter']['enablehint'] = array('bool' => true);
$array['filter']['enablevoicemail'] = array('bool' => true);
$array['filter']['enablexfer'] = array('bool' => true);
$array['filter']['dtmf_hangup'] = array('bool' => true);
$array['filter']['enableonlinerec'] = array('bool' => true);
$array['filter']['callrecord'] = array('bool' => true);
$array['filter']['incallfilter'] = array('bool' => true);
$array['filter']['enablednd'] = array('bool' => true);
$array['filter']['enablerna'] = array('bool' => true);
$array['filter']['destrna'] = array('set' => false,'chk' => 2,'regexp' => '/^\+?[0-9\*#]+$/','maxlen' => 128);
$array['filter']['enablebusy'] = array('bool' => true);
$array['filter']['destbusy'] = array('set' => false,'chk' => 2,'regexp' => '/^\+?[0-9\*#]+$/','maxlen' => 128);
$array['filter']['enableunc'] = array('bool' => true);
$array['filter']['destunc'] = array('set' => false,'chk' => 2,'regexp' => '/^\+?[0-9\*#]+$/','maxlen' => 128);
$array['filter']['musiconhold'] = array('set' => false,'chk' => 2,'cast' => 'sgraph','maxlen' => 20);
$array['filter']['outcallerid'] = array('set' => false,
					'chk'		=> 2,
					'maxlen'	=> 80,
					'regexp'	=> '/^'.XIVO_SRE_IPBX_AST_REGEXP_CALLERID.'$/u',
					'notag'		=> false);
$array['filter']['bsfilter'] = array('set' => false,'chk' => 2,'key' => array('no','boss','secretary'));
$array['filter']['mobilephonenumber'] = array('set'	=> false,
					      'chk'	=> 2,
					      'regexp'	=> '/^\+?[0-9\*#]+$/',
					      'maxlen'	=> 128);
$array['filter']['email'] = array('set' => false,'chk' => 2,'maxlen' => 254);
$array['filter']['preprocess_subroutine'] = array('set' => false,
						  'chk'	=> 2,
						  'callback' => 'xivo_service_asterisk::chk_context',
						  'callbackarg' => array(array(
							XIVO_SRE_IPBX_AST_CONTEXT_AUTHENTICATION,
							XIVO_SRE_IPBX_AST_CONTEXT_ZONEMESSAGES)));
$array['filter']['userfield'] = array('set'	=> false,
					      'chk'	=> 2,
					      'maxlen'	=> 128);
$array['filter']['language'] = array('set' => false,'chk' => 2,'minlen' =>5,'maxlen' => 5,'key' => dwho_i18n::get_supported_language_list());
$array['filter']['timezone'] = array('set' => false,'chk' => 2);
$array['filter']['description'] = array('set' => false,'chk' => 2,'maxlen' => 1000,'cast' => 'sgraph_crlf_tab','eol' => true);
$array['filter']['ringintern'] = array('set' => false,'chk' => 2,'maxlen' => 64);
$array['filter']['ringextern'] = array('set' => false,'chk' => 2,'maxlen' => 64);
$array['filter']['ringgroup'] = array('set' => false,'chk' => 2,'maxlen' => 64);
$array['filter']['ringforward'] = array('set' => false,'chk' => 2,'maxlen' => 64);
$array['filter']['rightcallcode'] = array('set'	=> false,'chk' => 2,'regexp' => '/^[0-9]+$/','maxlen' => 15);
$array['filter']['func_key_private_template_id'] = array('cast' => 'ulongint');
$array['filter']['func_key_template_id'] = array('set' => false,'chk' => 2,'cast' => 'ulongint');

?>
