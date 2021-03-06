<?php

#
# XiVO Web-Interface
# Copyright (C) 2006-2016 Avencall
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
$array['index'] = 'index.php';

/*
 * XIVO SECTION
 *
 */

$array['xivo'] = 'xivo/index.php';
$array['xivo/configuration'] = 'xivo/configuration/index.php';
$array['xivo/preferences'] = 'xivo/preferences.php';
$array['xivo/help'] = 'xivo/help.php';
$array['xivo/logoff'] = 'xivo/logoff.php';

// just check is user can access webservices
$array['xivo/configuration/json/restricted/check'] = 'xivo/configuration/json.php/restricted/check/';

// just for monit local requesting
$array['xivo/ui/monit'] = 'xivo/ui.php/monit/';

// just for monitoring page refresh
$array['xivo/configuration/json/restricted/support/monitoring'] = 'xivo/configuration/json.php/restricted/support/monitoring/';

$array['xivo/configuration/json/private/support/monitoring'] = 'xivo/configuration/json.php/private/support/monitoring/';


// manage
$array['xivo/configuration/manage/user'] = 'xivo/configuration/index.php/manage/user/';
$array['xivo/configuration/manage/entity'] = 'xivo/configuration/index.php/manage/entity/';
$array['xivo/configuration/manage/server'] = 'xivo/configuration/index.php/manage/server/';
$array['xivo/configuration/manage/ldapserver'] = 'xivo/configuration/index.php/manage/ldapserver/';
$array['xivo/configuration/manage/directories'] = 'xivo/configuration/index.php/manage/directories/';
$array['xivo/configuration/manage/accesswebservice'] = 'xivo/configuration/index.php/manage/accesswebservice/';
$array['xivo/configuration/manage/certificate'] = 'xivo/configuration/index.php/manage/certificate/';
$array['xivo/configuration/manage/ha'] = 'xivo/configuration/index.php/manage/ha/';
$array['xivo/configuration/manage/general'] = 'xivo/configuration/index.php/manage/general/';

$array['xivo/configuration/json/restricted/manage/entity'] = 'xivo/configuration/json.php/restricted/manage/entity/';

$array['xivo/configuration/json/private/manage/entity'] = 'xivo/configuration/json.php/restricted/manage/entity/';


// network
$array['xivo/configuration/network/interface'] = 'xivo/configuration/index.php/network/interface/';
$array['xivo/configuration/network/resolvconf'] = 'xivo/configuration/index.php/network/resolvconf/';
$array['xivo/configuration/network/mail'] = 'xivo/configuration/index.php/network/mail/';
$array['xivo/configuration/network/dhcp'] = 'xivo/configuration/index.php/network/dhcp/';

$array['xivo/configuration/json/restricted/network/interface'] = 'xivo/configuration/json.php/restricted/network/interface/';
$array['xivo/configuration/json/restricted/network/resolvconf'] = 'xivo/configuration/json.php/restricted/network/resolvconf/';
$array['xivo/configuration/json/restricted/network/mail'] = 'xivo/configuration/json.php/restricted/network/mail/';
$array['xivo/configuration/json/restricted/network/dhcp'] = 'xivo/configuration/json.php/restricted/network/dhcp/';

$array['xivo/configuration/json/private/network/interface'] = 'xivo/configuration/json.php/private/network/interface/';
$array['xivo/configuration/json/private/network/resolvconf'] = 'xivo/configuration/json.php/private/network/resolvconf/';
$array['xivo/configuration/json/private/network/mail'] = 'xivo/configuration/json.php/private/network/mail/';
$array['xivo/configuration/json/private/network/dhcp'] = 'xivo/configuration/json.php/private/network/dhcp/';


// support
$array['xivo/configuration/support/xivo'] = 'xivo/configuration/index.php/support/xivo/';
$array['xivo/configuration/support/alerts'] = 'xivo/configuration/index.php/support/alerts/';
$array['xivo/configuration/support/limits'] = 'xivo/configuration/index.php/support/limits/';


// provisioning
$array['xivo/configuration/provisioning/general'] = 'xivo/configuration/index.php/provisioning/general/';
$array['xivo/configuration/provisioning/configregistrar'] = 'xivo/configuration/index.php/provisioning/configregistrar/';
$array['xivo/configuration/provisioning/configdevice'] = 'xivo/configuration/index.php/provisioning/configdevice/';
$array['xivo/configuration/provisioning/plugin'] = 'xivo/configuration/index.php/provisioning/plugin/';

$array['xivo/configuration/json/restricted/provisioning/general'] = 'xivo/configuration/json.php/restricted/provisioning/general/';
$array['xivo/configuration/json/restricted/provisioning/autoprov'] = 'xivo/configuration/json.php/restricted/provisioning/autoprov/';

$array['xivo/configuration/json/private/provisioning/general'] = 'xivo/configuration/json.php/private/provisioning/general/';
$array['xivo/configuration/json/private/provisioning/autoprov'] = 'xivo/configuration/json.php/private/provisioning/autoprov/';
$array['xivo/configuration/json/private/provisioning/configregistrar'] = 'xivo/configuration/json.php/private/provisioning/configregistrar/';

$array['xivo/configuration/ui/provisioning/plugin'] = 'xivo/configuration/ui.php/provisioning/plugin';
$array['xivo/configuration/ui/provisioning/configs'] = 'xivo/configuration/ui.php/provisioning/configs';
$array['xivo/configuration/ui/provisioning/configure'] = 'xivo/configuration/ui.php/provisioning/configure';
$array['xivo/configuration/ui/provisioning/devices'] = 'xivo/configuration/ui.php/provisioning/devices';

// controlsystem
$array['xivo/configuration/controlsystem/commonconf'] = 'xivo/configuration/index.php/controlsystem/commonconf/';
$array['xivo/configuration/controlsystem/network'] = 'xivo/configuration/index.php/controlsystem/network/';


/*
 * SERVICE SECTION
 *
 */

$array['service/ipbx'] = 'service/ipbx/index.php';

// general_settings
$array['service/ipbx/general_settings/sip'] = 'service/ipbx/index.php/general_settings/sip/';
$array['service/ipbx/general_settings/iax'] = 'service/ipbx/index.php/general_settings/iax/';
$array['service/ipbx/general_settings/sccp'] = 'service/ipbx/index.php/general_settings/sccp/';
$array['service/ipbx/general_settings/voicemail'] = 'service/ipbx/index.php/general_settings/voicemail/';
$array['service/ipbx/general_settings/phonebook'] = 'service/ipbx/index.php/general_settings/phonebook/';
$array['service/ipbx/general_settings/advanced'] = 'service/ipbx/index.php/general_settings/advanced/';
$array['service/ipbx/general_settings/outboundmwi'] = 'service/ipbx/index.php/general_settings/outboundmwi/';

$array['service/ipbx/json/restricted/general_settings/sip'] = 'service/ipbx/json.php/restricted/general_settings/sip/';
$array['service/ipbx/json/restricted/general_settings/iax'] = 'service/ipbx/json.php/restricted/general_settings/iax/';
$array['service/ipbx/json/restricted/general_settings/sccp'] = 'service/ipbx/json.php/restricted/general_settings/sccp/';
$array['service/ipbx/json/restricted/general_settings/voicemail'] = 'service/ipbx/json.php/restricted/general_settings/voicemail/';
$array['service/ipbx/json/restricted/general_settings/phonebook'] = 'service/ipbx/json.php/restricted/general_settings/phonebook/';
$array['service/ipbx/json/restricted/general_settings/advanced'] = 'service/ipbx/json.php/restricted/general_settings/advanced/';
$array['service/ipbx/json/restricted/general_settings/outboundmwi'] = 'service/ipbx/json.php/restricted/general_settings/outboundmwi/';

$array['service/ipbx/json/private/general_settings/sip'] = 'service/ipbx/json.php/private/general_settings/sip/';
$array['service/ipbx/json/private/general_settings/iax'] = 'service/ipbx/json.php/private/general_settings/iax/';
$array['service/ipbx/json/private/general_settings/voicemail'] = 'service/ipbx/json.php/private/general_settings/voicemail/';
$array['service/ipbx/json/private/general_settings/phonebook'] = 'service/ipbx/json.php/private/general_settings/phonebook/';
$array['service/ipbx/json/private/general_settings/advanced'] = 'service/ipbx/json.php/private/general_settings/advanced/';
$array['service/ipbx/json/private/general_settings/outboundmwi'] = 'service/ipbx/json.php/private/general_settings/outboundmwi/';


// pbx_settings
$array['service/ipbx/pbx_settings/users'] = 'service/ipbx/index.php/pbx_settings/users/';
$array['service/ipbx/pbx_settings/groups'] = 'service/ipbx/index.php/pbx_settings/groups/';
$array['service/ipbx/pbx_settings/meetme'] = 'service/ipbx/index.php/pbx_settings/meetme/';
$array['service/ipbx/pbx_settings/voicemail'] = 'service/ipbx/index.php/pbx_settings/voicemail/';
$array['service/ipbx/pbx_settings/devices'] = 'service/ipbx/index.php/pbx_settings/devices/';
$array['service/ipbx/pbx_settings/lines'] = 'service/ipbx/index.php/pbx_settings/lines/';

$array['service/ipbx/json/restricted/pbx_settings/users'] = 'service/ipbx/json.php/restricted/pbx_settings/users/';
$array['service/ipbx/json/restricted/pbx_settings/lines'] = 'service/ipbx/json.php/restricted/pbx_settings/lines/';
$array['service/ipbx/json/restricted/pbx_settings/devices'] = 'service/ipbx/json.php/restricted/pbx_settings/devices/';
$array['service/ipbx/json/restricted/pbx_settings/groups'] = 'service/ipbx/json.php/restricted/pbx_settings/groups/';
$array['service/ipbx/json/restricted/pbx_settings/meetme'] = 'service/ipbx/json.php/restricted/pbx_settings/meetme/';
$array['service/ipbx/json/restricted/pbx_settings/voicemail'] = 'service/ipbx/json.php/restricted/pbx_settings/voicemail/';

$array['service/ipbx/json/restricted/call_management/incall'] = 'service/ipbx/json.php/restricted/call_management/incall/';
$array['service/ipbx/json/restricted/call_management/outcall'] = 'service/ipbx/json.php/restricted/call_management/outcall/';
$array['service/ipbx/json/restricted/trunk_management/sip'] = 'service/ipbx/json.php/restricted/trunk_management/sip/';
$array['service/ipbx/json/restricted/trunk_management/iax'] = 'service/ipbx/json.php/restricted/trunk_management/iax/';
$array['service/ipbx/json/restricted/trunk_management/custom'] = 'service/ipbx/json.php/restricted/trunk_management/custom/';
$array['service/ipbx/json/restricted/pbx_services/phonebook'] = 'service/ipbx/json.php/restricted/pbx_services/phonebook/';

$array['service/ipbx/json/private/pbx_settings/users'] = 'service/ipbx/json.php/private/pbx_settings/users/';
$array['service/ipbx/json/private/pbx_settings/lines'] = 'service/ipbx/json.php/private/pbx_settings/lines/';
$array['service/ipbx/json/private/pbx_settings/devices'] = 'service/ipbx/json.php/private/pbx_settings/devices/';
$array['service/ipbx/json/private/pbx_settings/groups'] = 'service/ipbx/json.php/private/pbx_settings/groups/';
$array['service/ipbx/json/private/pbx_settings/meetme'] = 'service/ipbx/json.php/private/pbx_settings/meetme/';
$array['service/ipbx/json/private/pbx_settings/voicemail'] = 'service/ipbx/json.php/private/pbx_settings/voicemail/';

$array['service/ipbx/ui/pbx_settings/users'] = 'service/ipbx/ui.php/pbx_settings/users/';
$array['service/ipbx/ui/pbx_settings/users/search'] = 'service/ipbx/ui.php/pbx_settings/users/search/';
$array['service/ipbx/ui/pbx_settings/users/groups'] = 'service/ipbx/ui.php/pbx_settings/users/groups/';
$array['service/ipbx/ui/pbx_settings/users/groups/search'] = 'service/ipbx/ui.php/pbx_settings/users/groups/search/';
$array['service/ipbx/ui/pbx_settings/users/queues'] = 'service/ipbx/ui.php/pbx_settings/users/queues/';
$array['service/ipbx/ui/pbx_settings/users/queues/search'] = 'service/ipbx/ui.php/pbx_settings/users/queues/search/';
$array['service/ipbx/ui/pbx_settings/users/meetme'] = 'service/ipbx/ui.php/pbx_settings/users/meetme/';
$array['service/ipbx/ui/pbx_settings/users/meetme/search'] = 'service/ipbx/ui.php/pbx_settings/users/meetme/search/';
$array['service/ipbx/ui/pbx_settings/users/paging'] = 'service/ipbx/ui.php/pbx_settings/users/paging/';
$array['service/ipbx/ui/pbx_settings/users/paging/search'] = 'service/ipbx/ui.php/pbx_settings/users/paging/search/';
$array['service/ipbx/ui/pbx_settings/users/voicemail'] = 'service/ipbx/ui.php/pbx_settings/users/voicemail/';
$array['service/ipbx/ui/pbx_settings/users/voicemail/search'] = 'service/ipbx/ui.php/pbx_settings/users/voicemail/search/';
$array['service/ipbx/ui/pbx_settings/users/voicemail/view'] = 'service/ipbx/ui.php/pbx_settings/users/voicemail/view/';
$array['service/ipbx/ui/pbx_settings/users/extension/view'] = 'service/ipbx/ui.php/pbx_settings/users/extension/view/';
$array['service/ipbx/ui/pbx_settings/groups'] = 'service/ipbx/ui.php/pbx_settings/groups/';
$array['service/ipbx/ui/pbx_settings/meetme'] = 'service/ipbx/ui.php/pbx_settings/meetme/';
$array['service/ipbx/ui/pbx_settings/voicemail'] = 'service/ipbx/ui.php/pbx_settings/voicemail/';
$array['service/ipbx/ui/pbx_settings/extension/search'] = 'service/ipbx/ui.php/pbx_settings/extension/search/';


// call_management
$array['service/ipbx/call_management/incall'] = 'service/ipbx/index.php/call_management/incall/';
$array['service/ipbx/call_management/outcall'] = 'service/ipbx/index.php/call_management/outcall/';
$array['service/ipbx/call_management/rightcall'] = 'service/ipbx/index.php/call_management/rightcall/';
$array['service/ipbx/call_management/callfilter'] = 'service/ipbx/index.php/call_management/callfilter/';
$array['service/ipbx/call_management/pickup'] = 'service/ipbx/index.php/call_management/pickup/';
$array['service/ipbx/call_management/schedule'] = 'service/ipbx/index.php/call_management/schedule/';
$array['service/ipbx/call_management/cel'] = 'service/ipbx/index.php/call_management/cel/';

$array['service/ipbx/json/restricted/call_management/incall'] = 'service/ipbx/json.php/restricted/call_management/incall/';
$array['service/ipbx/json/restricted/call_management/outcall'] = 'service/ipbx/json.php/restricted/call_management/outcall/';
$array['service/ipbx/json/restricted/call_management/pickup'] = 'service/ipbx/json.php/restricted/call_management/pickup/';
$array['service/ipbx/json/restricted/call_management/cel'] = 'service/ipbx/json.php/restricted/call_management/cel/';
$array['service/ipbx/json/restricted/call_management/schedule'] = 'service/ipbx/json.php/restricted/call_management/schedule/';

$array['service/ipbx/json/private/call_management/incall'] = 'service/ipbx/json.php/private/call_management/incall/';
$array['service/ipbx/json/private/call_management/pickup'] = 'service/ipbx/json.php/private/call_management/pickup/';
$array['service/ipbx/json/private/call_management/cel'] = 'service/ipbx/json.php/private/call_management/cel/';
$array['service/ipbx/json/private/call_management/schedule'] = 'service/ipbx/json.php/private/call_management/schedule/';

$array['service/ipbx/ui/call_management/schedule'] = 'service/ipbx/ui.php/call_management/schedule/';


// trunk_management
$array['service/ipbx/trunk_management/sip'] = 'service/ipbx/index.php/trunk_management/sip/';
$array['service/ipbx/trunk_management/iax'] = 'service/ipbx/index.php/trunk_management/iax/';
$array['service/ipbx/trunk_management/custom'] = 'service/ipbx/index.php/trunk_management/custom/';

$array['service/ipbx/json/restricted/trunk_management/sip'] = 'service/ipbx/json.php/restricted/trunk_management/sip/';
$array['service/ipbx/json/restricted/trunk_management/iax'] = 'service/ipbx/json.php/restricted/trunk_management/iax/';
$array['service/ipbx/json/restricted/trunk_management/custom'] = 'service/ipbx/json.php/restricted/trunk_management/custom/';


// pbx_services
$array['service/ipbx/pbx_services/sounds'] = 'service/ipbx/index.php/pbx_services/sounds/';
$array['service/ipbx/pbx_services/musiconhold'] = 'service/ipbx/index.php/pbx_services/musiconhold/';
$array['service/ipbx/pbx_services/extenfeatures'] = 'service/ipbx/index.php/pbx_services/extenfeatures/';
$array['service/ipbx/pbx_services/paging'] = 'service/ipbx/index.php/pbx_services/paging/';
$array['service/ipbx/pbx_services/phonebook'] = 'service/ipbx/index.php/pbx_services/phonebook/';

$array['service/ipbx/json/restricted/pbx_services/phonebook'] = 'service/ipbx/json.php/restricted/pbx_services/phonebook/';
$array['service/ipbx/json/restricted/pbx_services/extenfeatures'] = 'service/ipbx/json.php/restricted/pbx_services/extenfeatures/';

$array['service/ipbx/json/private/pbx_services/extenfeatures'] = 'service/ipbx/json.php/private/pbx_services/extenfeatures/';

# special..
$array['service/ipbx/json/phonebook/local'] = 'service/ipbx/json.php/phonebook/local/';


// system_management
$array['service/ipbx/system_management/backupfiles'] = 'service/ipbx/index.php/system_management/backupfiles/';
$array['service/ipbx/system_management/configfiles'] = 'service/ipbx/index.php/system_management/configfiles/';
$array['service/ipbx/system_management/context'] = 'service/ipbx/index.php/system_management/context/';
$array['service/ipbx/system_management/ldapfilter'] = 'service/ipbx/index.php/system_management/ldapfilter/';

$array['service/ipbx/json/restricted/system_management/context'] = 'service/ipbx/json.php/restricted/system_management/context/';
$array['service/ipbx/json/restricted/system_management/extensions'] = 'service/ipbx/json.php/restricted/system_management/extensions/';

$array['service/ipbx/json/private/system_management/context'] = 'service/ipbx/json.php/private/system_management/context/';


// control_system
$array['service/ipbx/control_system/logfiles'] = 'service/ipbx/index.php/control_system/logfiles/';
$array['service/ipbx/control_system/reload'] = 'service/ipbx/index.php/control_system/reload/';
$array['service/ipbx/control_system/restart'] = 'service/ipbx/index.php/control_system/restart/';
$array['service/ipbx/control_system/cti_restart'] = 'service/ipbx/index.php/control_system/cti_restart/';
$array['service/ipbx/control_system/dird_restart'] = 'service/ipbx/index.php/control_system/dird_restart/';


/*
 * CTI SECTION
 *
 */

$array['cti'] = 'cti/index.php';
$array['cti/general'] = 'cti/index.php/general';
$array['cti/presences'] = 'cti/index.php/presences/';
$array['cti/phonehints'] = 'cti/index.php/phonehints/';
$array['cti/profiles'] = 'cti/index.php/profiles/';
$array['cti/directories'] = 'cti/index.php/directories/';
$array['cti/reversedirectories'] = 'cti/index.php/reversedirectories/';
$array['cti/displays'] = 'cti/index.php/displays/';
$array['cti/contexts'] = 'cti/index.php/contexts/';
$array['cti/sheetactions'] = 'cti/index.php/sheetactions/';
$array['cti/sheetevents'] = 'cti/index.php/sheetevents/';


/*
 * CALLCENTER SECTION
 *
 */

$array['callcenter'] = 'callcenter/index.php';
$array['callcenter/settings/queues'] = 'callcenter/index.php/settings/queues/';
$array['callcenter/settings/queuepenalty'] = 'callcenter/index.php/settings/queuepenalty/';
$array['callcenter/settings/agents'] = 'callcenter/index.php/settings/agents/';
$array['callcenter/settings/queueskills'] = 'callcenter/index.php/settings/queueskills/';
$array['callcenter/settings/queueskillrules'] = 'callcenter/index.php/settings/queueskillrules/';

$array['service/ipbx/json/restricted/call_center/agents'] =
$array['callcenter/json/restricted/settings/agents'] = 'callcenter/json.php/restricted/settings/agents/';
$array['service/ipbx/json/restricted/call_center/queues'] =
$array['callcenter/json/restricted/settings/queues'] = 'callcenter/json.php/restricted/settings/queues/';
$array['service/ipbx/json/restricted/call_center/queuepenalty'] =
$array['callcenter/json/restricted/settings/queuepenalty'] = 'callcenter/json.php/restricted/settings/queuepenalty/';
$array['service/ipbx/json/restricted/call_center/queueskills'] =
$array['callcenter/json/restricted/settings/queueskills'] = 'callcenter/json.php/restricted/settings/queueskills/';
$array['service/ipbx/json/restricted/call_center/queueskillrules'] =
$array['callcenter/json/restricted/settings/queueskillrules'] = 'callcenter/json.php/restricted/settings/queueskillrules/';

$array['service/ipbx/json/private/call_center/agents'] =
$array['callcenter/json/private/settings/agents'] = 'callcenter/json.php/private/settings/agents/';
$array['service/ipbx/json/private/call_center/queues'] =
$array['callcenter/json/private/settings/queues'] = 'callcenter/json.php/private/settings/queues/';
$array['service/ipbx/json/private/call_center/queuepenalty'] =
$array['callcenter/json/private/settings/queuepenalty'] = 'callcenter/json.php/private/settings/queuepenalty/';
$array['callcenter/json/private/settings/queueskills'] = 'callcenter/json.php/private/settings/queueskills/';
$array['callcenter/json/private/settings/queueskillrules'] = 'callcenter/json.php/private/settings/queueskillrules/';

$array['service/ipbx/ui/call_center/agents'] =
$array['callcenter/ui/settings/agents'] = 'callcenter/ui.php/settings/agents/';
$array['service/ipbx/ui/call_center/queues'] =
$array['callcenter/ui/settings/queues'] = 'callcenter/ui.php/settings/queues/';

/*
 * MUNIN STATS SECTION
 *
 */

$array['graphs'] = 'graphs/index.php';
$array['graphs/munin/nginx'] = 'graphs/munin/index.php/nginx';
$array['graphs/munin/postgresql'] = 'graphs/munin/index.php/postgresql';
$array['graphs/munin/asterisk'] = 'graphs/munin/index.php/asterisk';
$array['graphs/munin/disk'] = 'graphs/munin/index.php/disk';
$array['graphs/munin/time'] = 'graphs/munin/index.php/time';
$array['graphs/munin/postfix'] = 'graphs/munin/index.php/postfix';
$array['graphs/munin/processes'] = 'graphs/munin/index.php/processes';
$array['graphs/munin/network'] = 'graphs/munin/index.php/network';
$array['graphs/munin/system'] = 'graphs/munin/index.php/system';
$array['graphs/munin/other'] = 'graphs/munin/index.php/other';

/*
 * STATISTICS SECTION
 *
 */

$array['statistics'] = 'statistics/index.php';
$array['statistics/call_center'] = 'statistics/index.php/call_center';
$array['statistics/call_center/data/stats1'] = 'statistics/index.php/call_center/data/stats1';
$array['statistics/call_center/data/stats2'] = 'statistics/index.php/call_center/data/stats2';
#$array['statistics/call_center/data/stats3'] = 'statistics/index.php/call_center/data/stats3';
$array['statistics/call_center/data/stats4'] = 'statistics/index.php/call_center/data/stats4';
$array['statistics/call_center/settings/configuration'] = 'statistics/index.php/call_center/settings/configuration/';
$array['statistics/switchboard'] = 'statistics/index.php/switchboard';
$array['statistics/switchboard/data'] = 'statistics/index.php/switchboard/data';

$array['statistics/call_center/json/private/settings/configuration'] = 'statistics/call_center/json.php/private/settings/configuration/';
$array['statistics/call_center/json/private/data/stats1'] = 'statistics/call_center/json.php/private/data/stats1/';
$array['statistics/call_center/json/private/data/stats2'] = 'statistics/call_center/json.php/private/data/stats2/';
#$array['statistics/call_center/json/private/data/stats3'] = 'statistics/call_center/json.php/private/data/stats3/';
$array['statistics/call_center/json/private/data/stats4'] = 'statistics/call_center/json.php/private/data/stats4/';

$array['statistics/call_center/json/restricted/settings/configuration'] = 'statistics/call_center/json.php/restricted/settings/configuration/';
$array['statistics/call_center/json/restricted/data/stats1'] = 'statistics/call_center/json.php/restricted/data/stats1/';
$array['statistics/call_center/json/restricted/data/stats2'] = 'statistics/call_center/json.php/restricted/data/stats2/';
#$array['statistics/call_center/json/restricted/data/stats3'] = 'statistics/call_center/json.php/restricted/data/stats3/';
$array['statistics/call_center/json/restricted/data/stats4'] = 'statistics/call_center/json.php/restricted/data/stats4/';

dwho_include_extra_files_from_dir(XIVO_EXTRA.'/url.d', $array);

?>
