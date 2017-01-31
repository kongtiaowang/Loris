#!/usr/bin/nodejs

var sjcl = require('./../instruments/js/sjcl.js')
var fs = require('fs');
var csv = require("fast-csv")

if ((process.argv[2] === undefined) || (process.argv[3] === undefined)) {
  console.log("usage: ./air_pollution_decrypt.js [csv-file] [passcode]")
  process.exit(1)
}

// 'CenterID',  'CandID',  'Visit_label',  'Date_taken',  'name',  'address_line1',  'address_line2',  'city',  'state',  'zip_code',  'additional_comments'

var stream = fs.createReadStream(process.argv[2]);

var csvStream = csv
    .parse({quote:"'", headers: true})
    .on("data", function(data) {
       if (data['name']) {
         console.log(data['CandID'] + ', "' + sjcl.decrypt(process.argv[3], data['name']) + '"')
      }
    })
    .on("end", function(){
         console.log("done");
    })

stream.pipe(csvStream);

