#!/usr/bin/nodejs

var sjcl = require('./sjcl.js')
var fs = require('fs');
var csv = require("fast-csv")

if ((process.argv[2] === undefined) || (process.argv[3] === undefined)) {
  console.log("usage: ./air_pollution_decrypt.js [csv-file] [passcode]")
  process.exit(1)
}

var line, head;
var encrypted = ['proband_name', 'address_line1m1', 'address_line2m1', 'citym1', 'statem1', 'zip_codem1', 'address_line1m2', 'address_line2m2', 'citym2', 'statem2', 'zip_codem2', 'address_line1m3', 'address_line2m3', 'citym3', 'statem3', 'zip_codem3', 'address_line1m4', 'address_line2m4', 'citym4', 'statem4', 'zip_codem4', 'address_line1m5', 'address_line2m5', 'citym5', 'statem5', 'zip_codem5', 'address_line1b1', 'address_line2b1', 'cityb1', 'stateb1', 'zip_codeb1', 'address_line1b2', 'address_line2b2', 'cityb2', 'stateb2', 'zip_codeb2', 'address_line1b3', 'address_line2b3', 'cityb3', 'stateb3', 'zip_codeb3', 'address_line1b4', 'address_line2b4', 'cityb4', 'stateb4', 'zip_codeb4', 'address_line1b5', 'address_line2b5', 'cityb5', 'stateb5', 'zip_codeb5', 'address_line1b6', 'address_line2b6', 'cityb6', 'stateb6', 'zip_codeb6', 'additional_comments'];

var print_head = (function() {
var executed = false;
 return function () {
   if (!executed) {
       executed = true;
       head = head.substring(0, head.length - 2);
       console.log(head);
   }
 };
})();

var stream = fs.createReadStream(process.argv[2]);

var csvStream = csv
    .parse({quote:"'", headers: true})
    .on("data", function(data) {
       if (data['CandID']) {
           line = "";
           head = "";
           
           for (column in data) {
             if (encrypted.indexOf(column) > -1) {
               head += '"' + column + '", ';
               line += '"' + sjcl.decrypt(process.argv[3], data[column]) + '", ';
               // console.log(column + "'" + data[column] + "', ");
             } else {
               head += '"' + column + '", ';
               line += '"' + data[column] + '", ';
               // console.log(column + '"' + data[column] + '", ');
             }
           }
                    
           print_head();
           line = line.substring(0, line.length - 2);
           console.log(line);
      }
    })
    .on("end", function(){
         // console.log("done");
    })

stream.pipe(csvStream);



