#!/bin/bash
    cd /var/www/loris/tools
    find ../project/instruments/NDB_BVL_Instrument*.class.inc \( ! -name "NDB_BVL_Instrument_air_pollution.class.inc"  \) | php lorisform_parser.php &&
    cat /var/www/loris/project/instruments/*.linst >> /var/www/loris/tools/ip_output.txt &&
    php data_dictionary_builder.php
