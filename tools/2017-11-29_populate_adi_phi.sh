#!/bin/sh

cd /var/www/loris/tools

php fix_timepoint_date_problems.php add_instrument 160908 5148 adi_r_subject
php fix_timepoint_date_problems.php add_instrument 273365 5075 adi_r_subject
php fix_timepoint_date_problems.php add_instrument 304981 5637 adi_r_subject
php fix_timepoint_date_problems.php add_instrument 371545 5193 adi_r_subject
php fix_timepoint_date_problems.php add_instrument 391404 5131 adi_r_subject
php fix_timepoint_date_problems.php add_instrument 636689 5235 adi_r_subject
php fix_timepoint_date_problems.php add_instrument 728624 4990 adi_r_subject
php fix_timepoint_date_problems.php add_instrument 750055 5230 adi_r_subject
php fix_timepoint_date_problems.php add_instrument 774024 5119 adi_r_subject
php fix_timepoint_date_problems.php add_instrument 895607 5310 adi_r_subject

php assign_missing_instruments confirm