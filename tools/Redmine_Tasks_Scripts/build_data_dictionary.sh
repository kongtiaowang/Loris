#!/bin/bash

###############################################################################
# Uses the lorsiform_parser script to build file ip_output.txt for every      #
# instrument in directory ../project/instruments/. This script assucmes all   #
# instruments have a base name that matches NDB_BVL_Instrument*.class.inc     #
# It will also append to file ip_output.txt the concatenated contents of all  #
# files in /var/www/loris/project/instruments whoc basename matches pattern   #
# *.linst. The data dictionary is then updated based on the contents of the   #
# ip_output.txt file                                                          #
#                                                                             #
#  WARNING THIS FILE ACTIVELY AFFECTS THE DATABASE INDICATED BY CONFIG.XML.   #
#                                                                             #
###############################################################################
    cd /var/www/loris/tools
    find ../project/instruments/NDB_BVL_Instrument*.class.inc | php lorisform_parser.php &&
    cat /var/www/loris/project/instruments/*.linst >> /var/www/loris/tools/ip_output.txt &&
    php exporters/data_dictionary_builder.php
