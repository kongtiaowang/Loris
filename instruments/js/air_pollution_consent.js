$(document).ready(function() {

  $("#savecontinue").unbind("click");
  console.log("unbind click");

  $("#savecontinue").click(function(e) {
    console.log("save clicked");
    
    if ($('[name="consent"]').val() == 'yes') {
        var form = $("#test_form");
        $("<input>").attr({
          type: 'hidden',
          name: 'nextpage',
          value: '1'
        }).appendTo(form);

       form.submit();
    } else if ($('[name="consent"]').val() == 'no') {
        var consent=$('[name="consent"]').val();
        var comment=$('[name="commentId"]').val();
        alert("no");
        $.ajax({
            type: 'POST',
            data: { consent: consent,
                    comment: comment },
            url: 'candidate_parameters/ajax/UpdateConsent.php',
            success: function(data) {
                alert(data);
            }
        });
      alert("You have chosen not to consent to participating in the air pollution study, we thank you for your time. If you wish to consent, please choose 'Yes' to proceed."); 
      return false;  
    } else {
      alert("You must select 'Yes' to continue"); 
      return false;
    }
    
  });
});
