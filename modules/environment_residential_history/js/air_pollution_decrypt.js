var lines = '';
var head = '';

var encrypted = ['proband_name', 'address_line1m1', 'address_line2m1', 'citym1', 'statem1', 'zip_codem1', 'address_line1m2', 'address_line2m2', 'citym2', 'statem2', 'zip_codem2', 'address_line1m3', 'address_line2m3', 'citym3', 'statem3', 'zip_codem3', 'address_line1m4', 'address_line2m4', 'citym4', 'statem4', 'zip_codem4', 'address_line1m5', 'address_line2m5', 'citym5', 'statem5', 'zip_codem5', 'address_line1b1', 'address_line2b1', 'cityb1', 'stateb1', 'zip_codeb1', 'address_line1b2', 'address_line2b2', 'cityb2', 'stateb2', 'zip_codeb2', 'address_line1b3', 'address_line2b3', 'cityb3', 'stateb3', 'zip_codeb3', 'address_line1b4', 'address_line2b4', 'cityb4', 'stateb4', 'zip_codeb4', 'address_line1b5', 'address_line2b5', 'cityb5', 'stateb5', 'zip_codeb5', 'address_line1b6', 'address_line2b6', 'cityb6', 'stateb6', 'zip_codeb6', 'additional_comments'];
   
  var openFile = function(event) {

    console.log("In FileReader");
    var code = document.getElementById("code").value;
    var input = event.target;

    var reader = new FileReader();
    reader.onload = function(event){

      var result = Papa.parse(event.target.result, {quoteChar: "'", header: true});
      
      result.data.forEach(function (row) {
        var line = '';
      
        for (var key in row) {
           if (encrypted.indexOf(key) > -1) {
             head += '"' + key + '", ';
             line += '"' + sjcl.decrypt(code, row[key]) + '", ';
           } else {
             head += '"' + key + '", ';
             line += '"' + row[key] + '", ';
           }
         }
         
         line = line.substring(0, line.length - 2);
         lines += line + "\n";
       });
          
       head = head.substring(0, head.length - 2);
       document.getElementById("output").value = head + '\n' + lines;

    };
    reader.readAsText(input.files[0]);

  };



