$(document).ready(function() {
  
  $("#savecontinue").unbind( "click" );
  
  $("#savecontinue").click(function(e) {
//    e.preventDefault();
    console.log("save clicked");
      var mail_consent = $('[name = "mail_tooth_kit"]').val();
      var comment = $('[name = "commentId"]').val();
      var consent = $('[name = "consent"]').val();
    if ($('[name="consent"]').val() == 'yes' && $('[name="mail_tooth_kit"]').val() != '') {
        $.ajax({
            type: 'POST',
            data: { mail_consent: mail_consent,
                    consent: consent,
                    comment: comment },
            url: '/UpdateConsent.php',
        });
        
        var form = $("#test_form");
        $("<input>").attr({
                        type: 'hidden',
                        name: 'nextpage',
                        value: '1'
                    }).appendTo(form);
        form.submit();
    } else if ($('[name="consent"]').val() == 'no' && $('[name="mail_tooth_kit"]').val() != '') {
        $.ajax({
            type: 'POST',
            data: { mail_consent: mail_consent,
                    consent: consent,
                    comment: comment },
            url: '/UpdateConsent.php',
            success: function(data) {
            }
        });
      alert("You have chosen 'No' to participate in the air pollution study, we thank you for your time. If you wish to consent, please choose 'Yes' to proceed.");
      return false;
    } else if ($('[name = "mail_tooth_kit"]').val() == '') {
        alert("Do you want to get the tooth fairy kit?. Please select an option.");
        return false;
    } else {
        $.ajax({
            type: 'POST',
            data: { mail_consent: mail_consent,
                    comment: comment },
            url: '/UpdateConsent.php',
            success: function(data) {
            }
        });

      alert("You must select 'Yes' to continue to the air pollution study questionnaire.");
      return false;
    }
    
  });
});
