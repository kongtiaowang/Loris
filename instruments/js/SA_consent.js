$(document).ready(function() {
  
  $("#savecontinue").unbind( "click" );
 
  $("#savecontinue").click(function(e) {
    console.log("save clicked");
      var comment = $('[name = "commentId"]').val();
      var SA_consent = $('[name = "SA_consent"]').val();
      var isSafari = navigator.vendor.indexOf("Apple")==0 && /\sSafari\//.test(navigator.userAgent); // true or false
      
    if (SA_consent == '') {
        alert("Please select an option.");
        return false;
    } else  {
        $.ajax({
            type: 'POST',
            async: isSafari,
            data: { comment: comment,
                    SA_consent: SA_consent
            },
            url: '/UpdateSAConsent.php',
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
