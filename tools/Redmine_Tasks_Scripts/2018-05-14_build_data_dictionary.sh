#!/bin/bash
    cd /var/www/loris/tools
    find ../project/instruments/NDB_BVL_Instrument*.class.inc | php lorisform_parser.php && php data_dictionary_builder.php
