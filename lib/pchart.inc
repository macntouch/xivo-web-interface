<?php

#
# XiVO Web-Interface
# Copyright (C) 2006-2011  Proformatique <technique@proformatique.com>
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

require_once(DWHO_PATH_ROOT.DIRECTORY_SEPARATOR.'file.inc');

function dwho_load_lib_pchart($libdir)
{
    $r = dwho_file::read_d($libdir,'file',FILE_R_OK);
    sort($r);
    
    $tree = array();
    foreach($r as $file)
    {
        if(ereg('.class',$file)) {
            require_once($libdir.$file);
            array_push($tree,$libdir.$file);
        }
    }

    return($tree);
}

?>