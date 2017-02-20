#!/bin/sh

cd /var/www/loris/tools
php CouchDB_Import_Demographics.php
php CouchDB_Import_Instruments.php
php CouchDB_Import_MRI.php
php CouchDB_Import_Derived_ADOS.php
php CouchDB_Import_RadiologicalReview.php
#php CouchDB_Confirm_Integrity.php

#curl -H 'Content-Type: application/json' -X POST http://driusan:Vital1@couchhost:5984/_replicate -d '{"source":"ibisunfiltered", "target":"ibisfiltered", "filter":"DQG-2.0/IBISSites"}'
curl -H 'Content-Type: application/json' -X POST http://admin:MxedMdia=40sheets@nihace_couch:5984/_replicate -d '{"source":"ibisunfiltered", "target":"ibisfilteredlogin", "filter":"DQG-2.0/IBISSites"}'

#curl -X GET http://driusan:Vital1@couchhost:5984/ibisfiltered/_design/DQG-2.0/_view/categories > /dev/null

# Keep the unfiltered indexes up to date too, so 
# that it can be used for testing.
curl -X GET http://admin:MxedMdia=40sheets@nihace_couch:5984/ibisfilteredlogin/_design/DQG-2.0/_view/categories > /dev/null &
curl -X GET http://admin:MxedMdia=40sheets@nihace_couch:5984/ibisunfiltered/_design/DQG-2.0/_view/categories > /dev/null
