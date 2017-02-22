var lines = '';
var head = '';

var encrypted = ['proband_name', 'address_line1m1', 'address_line2m1', 'citym1', 'statem1', 'zip_codem1', 'address_line1m2', 'address_line2m2', 'citym2', 'statem2', 'zip_codem2', 'address_line1m3', 'address_line2m3', 'citym3', 'statem3', 'zip_codem3', 'address_line1m4', 'address_line2m4', 'citym4', 'statem4', 'zip_codem4', 'address_line1m5', 'address_line2m5', 'citym5', 'statem5', 'zip_codem5', 'address_line1b1', 'address_line2b1', 'cityb1', 'stateb1', 'zip_codeb1', 'address_line1b2', 'address_line2b2', 'cityb2', 'stateb2', 'zip_codeb2', 'address_line1b3', 'address_line2b3', 'cityb3', 'stateb3', 'zip_codeb3', 'address_line1b4', 'address_line2b4', 'cityb4', 'stateb4', 'zip_codeb4', 'address_line1b5', 'address_line2b5', 'cityb5', 'stateb5', 'zip_codeb5', 'address_line1b6', 'address_line2b6', 'cityb6', 'stateb6', 'zip_codeb6', 'additional_comments'];

 
var calcChecksum = function(event) {
  var code = document.getElementById("code").value;
  var reversed = parseInt("EDB88320", 16)
  var cs = crc32_compute_string(reversed, code);

  document.getElementById("cs").innerHTML = "<h5>" + cs + "</h5>";
};
 
 
var openFile = function(event) {

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
           try {
             line += '"' + sjcl.decrypt(code, row[key]) + '", ';
           }
           catch(err) {
             line += '"' + row[key] + '", ';
           }
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


/*
 * JavaScript CRC-32 implementation
 * http://www.simplycalc.com/crc32-source.php
 */
 
function crc32_generate(polynomial) {
    var table = new Array()
    var i, j, n
    
    for (i = 0; i < 256; i++) {
        n = i
        for (j = 8; j > 0; j--) {
            if ((n & 1) == 1) {
                n = (n >>> 1) ^ polynomial
            } else {
                n = n >>> 1
            }
        }
        table[i] = n
    }

    return table
}

function crc32_initial() {
    return 0xFFFFFFFF
}

function crc32_final(crc) {
    crc = ~crc
    return crc < 0 ? 0xFFFFFFFF + crc + 1 : crc
}

function crc32_compute_string(polynomial, str) {
    var crc = 0
    var table = crc32_generate(polynomial)
    var i
    
    crc = crc32_initial()
    
    for (i = 0; i < str.length; i++)
        crc = (crc >>> 8) ^ table[str.charCodeAt(i) ^ (crc & 0x000000FF)]
        
    crc = crc32_final(crc)
    return crc
}

function crc32_compute_buffer(polynomial, data) {
    var crc = 0
    var dataView = new DataView(data)
    var table = crc32_generate(polynomial)
    var i
    
    crc = crc32_initial()
    
    for (i = 0; i < dataView.byteLength; i++)
        crc = (crc >>> 8) ^ table[dataView.getUint8(i) ^ (crc & 0x000000FF)]
        
    crc = crc32_final(crc)
    return crc
}

