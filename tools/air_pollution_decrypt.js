#!/usr/bin/nodejs

var sjcl = require('./sjcl.js')
var fs = require('fs');
var csv = require("fast-csv")

if ((process.argv[2] === undefined) || (process.argv[3] === undefined)) {
  console.log("usage: ./air_pollution_decrypt.js [csv-file] [passcode]")
  process.exit(1)
}

// 'CenterID',  'CandID',  'Visit_label',  'Date_taken',  'proband_name',  'address_line1m1',  'address_line2m1',  'citym1',  'statem1',  'zip_codem1',  'additional_comments'

var stream = fs.createReadStream(process.argv[2]);

var csvStream = csv
    .parse({quote:"'", headers: true})
    .on("data", function(data) {
       if (data['CandID']) {
         console.log(data['CandID'] + ', "' + sjcl.decrypt(process.argv[3], data['proband_name']) + '"' + ', "' + sjcl.decrypt(process.argv[3], data['address_line1m1']) + '"')
      }
    })
    .on("end", function(){
         console.log("done");
    })

stream.pipe(csvStream);

