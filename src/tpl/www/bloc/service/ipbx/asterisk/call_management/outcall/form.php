<?php

#
# XiVO Web-Interface
# Copyright (C) 2006-2016  Avencall
# Copyright (C) 2016  Proformatique Inc.
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

$form = &$this->get_module('form');
$url = &$this->get_module('url');

$element = $this->get_var('element');
$context_list = $this->get_var('context_list');

$outcalltrunk = $this->get_var('outcalltrunk');
$rightcall    = $this->get_var('rightcall');
$schedules    = $this->get_var('schedules');
$info         = $this->get_var('info');

if ($info['outcall']['hangupringtime'] === null) {
	$hangupringtime = $element['outcall']['hangupringtime']['default'];
} else {
	$hangupringtime = $info['outcall']['hangupringtime'];
}
if ($hangupringtime == 0) {
	$hangupringtime = '';
}
?>

<div id="sb-part-first" class="b-nodisplay">
<?php
	echo	$form->text(array('desc'	=> $this->bbf('fm_outcall_name'),
				  'name'	=> 'outcall[name]',
				  'labelid'	=> 'outcall-name',
				  'size'	=> 15,
				  'default'	=> $element['outcall']['name']['default'],
				  'value'	=> $this->get_var('info','outcall','name'),
				  'error'	=> $this->bbf_args('error',
						   $this->get_var('error', 'outcall', 'name')) ));

if($context_list !== false):
	echo	$form->select(array('desc'	=> $this->bbf('fm_outcall_context'),
				    'name'	=> 'outcall[context]',
				    'labelid'	=> 'outcall-context',
				    'key'	=> 'identity',
				    'altkey'	=> 'name',
				    'default'	=> $element['outcall']['context']['default'],
				    'selected'	=> $this->get_var('info','outcall','context')),
			      $context_list);
else:
	echo	'<div id="fd-outcall-context" class="txt-center">',
		$url->href_htmln($this->bbf('create_context'),
				'service/ipbx/system_management/context',
				'act=add'),
		'</div>';
endif;

	echo	$form->checkbox(array('desc'	=> $this->bbf('fm_outcall_useenum'),
				      'name'	=> 'outcall[useenum]',
				      'labelid'	=> 'useenum',
				      'checked'	=> $this->get_var('info','outcall','useenum'),
				      'default'	=> $element['outcall']['useenum']['default']));
?>
<?php
	echo	$form->checkbox(array('desc'	=> $this->bbf('fm_outcall_internal'),
				      'name'	=> 'outcall[internal]',
				      'labelid'	=> 'internal',
				      'checked'	=> $this->get_var('info','outcall','internal'),
				      'default'	=> $element['outcall']['internal']['default'])),

		$form->text(array('desc'	=> $this->bbf('fm_outcall_preprocess-subroutine'),
				  'name'	=> 'outcall[preprocess_subroutine]',
				  'labelid'	=> 'outcall-preprocess-subroutine',
				  'size'	=> 15,
				  'default'	=> $element['outcall']['preprocess_subroutine']['default'],
				  'value'	=> $this->get_var('info','outcall','preprocess_subroutine'),
				  'error'	=> $this->bbf_args('error',
						   $this->get_var('error', 'outcall', 'preprocess_subroutine')) )),

		$form->text(array('desc' => $this->bbf('fm_outcall_hangupringtime'),
				    'name'    => 'outcall[hangupringtime]',
				    'labelid' => 'outcall-hangupringtime',
				    'size'    => 15,
				    'help'    => $this->bbf('hlp_fm_outcall_hangupringtime'),
				    'value'   => $hangupringtime,
				    'error'   => $this->bbf_args('error',
						    $this->get_var('error', 'outcall', 'hangupringtime')) ));

if($outcalltrunk['list'] !== false):
?>
<div id="outcalltrunklist" class="fm-paragraph fm-description">
	<p>
		<label id="lb-outcalltrunk" for="it-outcalltrunk"><?=$this->bbf('fm_outcalltrunk');?></label>
	</p>
		<?=$form->jq_select(array('paragraph'	=> false,
					 	'label'		=> false,
            			'name'    	=> 'outcalltrunk[]',
						'id' 		=> 'outcalltrunk',
						'key'		=> 'identity',
				       	'altkey'	=> 'id',
            			'selected'  => $outcalltrunk['slt']),
					$outcalltrunk['list']);?>
</div>
<div class="clearboth"></div>
<?php
else:
	echo	'<div class="txt-center">',
		$url->href_htmln($this->bbf('create_trunk'),
				'service/ipbx/trunk_management/sip',
				'act=add'),
		'</div>';
endif;
?>
	<div class="fm-paragraph fm-description">
		<p>
			<label id="lb-outcall-description" for="it-outcall-description"><?=$this->bbf('fm_outcall_description');?></label>
		</p>
		<?=$form->textarea(array('paragraph'	=> false,
					 'label'	=> false,
					 'name'		=> 'outcall[description]',
					 'id'		=> 'outcall-description',
					 'cols'		=> 60,
					 'rows'		=> 5,
					 'default'	=> $element['outcall']['description']['default'],
					 'error'	=> $this->bbf_args('error',
						   $this->get_var('error', 'outcall', 'description')) ),
				   $this->get_var('info','outcall','description'));?>
	</div>
</div>

<div id="sb-part-exten" class="b-nodisplay">
	<div class="sb-list">
<?php $this->file_include('bloc/service/ipbx/asterisk/call_management/outcall/exten'); ?>
	</div>
</div>

<div id="sb-part-rightcalls" class="b-nodisplay">
<?php
	if($rightcall['list'] !== false):
?>
<div id="rightcalllist" class="fm-paragraph fm-description">
		<?=$form->jq_select(array('paragraph'	=> false,
					 	'label'		=> false,
            			'name'    	=> 'rightcall[]',
						'id' 		=> 'it-rightcall',
						'key'		=> 'identity',
				       	'altkey'	=> 'id',
            			'selected'  => $rightcall['slt']),
					$rightcall['list']);?>
</div>
<div class="clearboth"></div>
<?php
	else:
		echo	'<div class="txt-center">',
			$url->href_htmln($this->bbf('create_rightcall'),
					'service/ipbx/call_management/rightcall',
					'act=add'),
			'</div>';
	endif;
?>
</div>


<div id="sb-part-schedule" class="b-nodisplay">
<?php
	if($schedules === false):
		echo	'<div class="txt-center">',
			$url->href_htmln($this->bbf('create_schedules'),
					'service/ipbx/call_management/schedule',
					'act=add'),
			'</div>';
	else:
		echo $form->select(array('desc'	=> $this->bbf('fm_outcall_schedule'),
				    'name'	    => 'schedule_id',
				    'labelid'	  => 'schedule_id',
						'key'	      => 'name',
						'altkey'    => 'id',
						'empty'     => true,
				    'selected'	=> $this->get_var('info', 'schedule_id')),
			      $schedules);
	endif;
?>
</div>
