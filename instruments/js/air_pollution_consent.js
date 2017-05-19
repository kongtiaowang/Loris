$(document).ready(function() {
  
  $("#savecontinue").unbind( "click" );
 
  $("#savecontinue").click(function(e) {
    console.log("save clicked");
      var mail_consent = $('[name = "mail_tooth_kit"]').val();
      var comment = $('[name = "commentId"]').val();
      var consent = $('[name = "consent"]').val();
      var isSafari = navigator.vendor.indexOf("Apple")==0 && /\sSafari\//.test(navigator.userAgent); // true or false
      
    if (mail_consent == '') {
        alert("Do you want to get the tooth fairy kit?. Please select an option.");
        return false;
    } else if (consent == 'yes') {
        $.ajax({
            type: 'POST',
            async: isSafari,
            data: { comment: comment,
                    mail_consent: mail_consent,
                    consent: consent
            },
            url: '/UpdateConsent.php',
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
    } else if (consent == 'no') {
        $.ajax({
            type: 'POST',
            async: isSafari,
            data: { comment: comment,
                    mail_consent: mail_consent,
                    consent: consent
            },
            url: '/UpdateConsent.php',
            success: function(data) {
            }
        });
      alert("You have chosen 'No' to participate in the air pollution study, we thank you for your time. If you wish to consent, please choose 'Yes' to proceed.");
      return false;
    } else {
        $.ajax({
            type: 'POST',
            async: isSafari,
            data: { comment: comment, 
                    mail_consent: mail_consent
                  },
            url: '/UpdateConsent.php',
            success: function(data) {
            }
        });

      alert("You must select 'Yes' to continue to the air pollution study questionnaire.");
      return false;
    }
    
  });
});
