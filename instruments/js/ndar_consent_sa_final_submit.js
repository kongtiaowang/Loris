$(document).ready(function() {


  $("#goback").remove();
  $("#finalize").unbind( "click" );
  console.log("unbind click");


  

  $("#finalize").click(function(e) {
    console.log("save clicked");




        // are you sure?
        var question = "Are you ready to submit the Information?";
        var status = confirm(question);
        
        if( status !== false ){

            var form = $("#test_form");
            $("<input>").attr({
              type: 'hidden',
              name: 'nextpage',
              value: 'complete'
            }).appendTo(form);

            form.submit();
        } else {
            console.log("User chose to cancel at this point, since status is " + status); // status is FALSE
            return false;
        }

  });
  
});
