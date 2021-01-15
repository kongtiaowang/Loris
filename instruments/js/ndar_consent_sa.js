$(document).ready(function() {
  
  $("#savecontinue").unbind( "click" );
 
  $("#savecontinue").click(function(e) {
    console.log("save clicked");
      var comment = $('[name = "commentId"]').val();
      var NDAR_consent_SA = $('[name = "NDAR_consent_SA"]').val();
      var isSafari = navigator.vendor.indexOf("Apple")==0 && /\sSafari\//.test(navigator.userAgent); // true or false
      
    if (NDAR_consent_SA == '') {
        alert("Please select an option.");
        return false;
    } else  {
        $.ajax({
            type: 'POST',
            async: isSafari,
            data: { comment: comment,
                NDAR_consent_SA: NDAR_consent_SA
            },
            url: '/UpdateNDARConsetSA.php',
            success: function(data) {
                var form = $("#test_form");
                $("<input>").attr({
                        type: 'hidden',
                        name: 'nextpage',
                        value: '1'
                        }).appendTo(form);
                form.submit();
            },
            error: function(data) {
            }
        });        
      return false;
    }
    
  });
});
