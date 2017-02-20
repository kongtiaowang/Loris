curl -H 'Content-Type: application/json' -X POST http://admin:MxedMdia=40sheets@nihace_couch:5984/_replicate -d '{"source":"ibisunfiltered", "target":"ibisfilteredlogin", "filter":"DQG-2.0/IBISSites"}'
curl -X GET http://admin:MxedMdia=40sheets@nihace_couch:5984/ibisfilteredlogin/_design/DQG-2.0/_view/categories

