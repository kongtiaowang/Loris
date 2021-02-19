#!/bin/sh

cd /var/www/loris/tools

printf "Before Imports\n"
# php CouchDB_Import_figs.php
# php CouchDB_Import_Demographics.php
php CouchDB_Import_demographics_ibis.php
php CouchDB_Import_Instruments_ibis.php
php CouchDB_Import_MRI_ibis.php
php CouchDB_Import_Derived_ADOS.php
# php CouchDB_Import_RadiologicalReview_Ibis.php
php CouchDB_Confirm_Integrity_ibis.php

#curl -H 'Content-Type: application/json' -X POST http://driusan:Vital1@couchhost:5984/_replicate -d '{"source":"ibisunfiltered", "target":"ibisfiltered", "filter":"DQG-2.0/IBISSites"}'
#curl -H 'Content-Type: application/json' -X POST http://admin:MxedMdia=40sheets@nihace_couch:5984/_replicate -d '{"source":"ibisunfiltered", "target":"ibisfilteredlogin", "filter":"DQG-2.0/IBISSites"}'

#curl -X GET http://driusan:Vital1@couchhost:5984/ibisfiltered/_design/DQG-2.0/_view/categories > /dev/null

# Keep the unfiltered indexes up to date too, so that it can be used for testing.
# curl -X GET http://admin:MxedMdia=40sheets@nihace_couch:5984/ibisfilteredlogin/_design/DQG-2.0/_view/categories > /dev/null &

printf "Before Curl\n"
curl -X GET http://admin:MxedMdia=40sheets@nihace_couch:5984/ibisunfiltered/_design/DQG-2.0/_view/categories > /dev/null
printf "After Curl\n"
