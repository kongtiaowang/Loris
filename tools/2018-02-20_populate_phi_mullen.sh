#!/bin/sh

cd /var/www/loris/tools

php fix_timepoint_date_problems.php add_instrument 867237 2442 mullen
php fix_timepoint_date_problems.php add_instrument 813346 3461 mullen

php assign_missing_instruments.php confirm
