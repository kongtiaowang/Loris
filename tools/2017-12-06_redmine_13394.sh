#!/bin/sh

cd /var/www/loris/tools

php fix_timepoint_date_problems.php add_instrument 391729 5097 ados2_module2

php assign_missing_instruments.php confirm