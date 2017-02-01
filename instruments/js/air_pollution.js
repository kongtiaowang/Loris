$(document).ready(function() {
  console.log("ready");

  $("#finalize").unbind( "click" );
  console.log("unbind click");

  $("#finalize").click(function(e) {
    console.log("save clicked");

    // Check user inputs
    var errors = 0;
    
    if ( !$('[name="proband_birthdate[Y]"]').val() ) { errors++; }
    if ( !$('[name="proband_birthdate[M]"]').val() ) { errors++; }
    if ( !$('[name="proband_birthdate[d]"]').val() ) { errors++; }
    if ( !$('[name="from1b41[Y]"]').val() ) { errors++; }
    if ( !$('[name="from1b41[M]"]').val() ) { errors++; }
    if ( !$('[name="to1b41[Y]"]').val() ) { errors++; }
    if ( !$('[name="to1b41[M]"]').val() ) { errors++; }
    if ( !$('[name="fromatb1[Y]"]').val() ) { errors++; }
    if ( !$('[name="fromatb1[M]"]').val() ) { errors++; }
    if ( !$('[name="toatb1[Y]"]').val() ) { errors++; }
    if ( !$('[name="toatb1[M]"]').val() ) { errors++; }
    $('.required').each(function() { 
      if ( !$(this).val() ) { errors++; }
    });
    
    if(errors > 0) {
      alert("Please fill in all required fields");
      return false;
    } else {
    
        // are you sure?
        var question = "Are you sure all fields are filled correctly and OK to be submitted?";
        var status = confirm(question);
        
        if( status !== false ){
            // all class to be encrypted
            $('.encrypt').each(function() {
              var crypted = sjcl.encrypt($('[name="code"]').val(), $(this).val());
              $(this).val(crypted);

              // rename encrypt field to be submitable
              $(this).attr('name', $(this).attr('name').replace('_remove',''));
            });

            // text area exception
            var crypted = sjcl.encrypt($('[name="code"]').val(), $('[name="additional_comments"]').val());
            $('[name="additional_comments"]').val(crypted);

            // empty code before submission
            $('[name="code"]').val("*Deleted for Submission*");
            console.log("fields crypted, submitting..."); //status is TRUE

            var form = $("#test_form");
            $("<input>").attr({
              type: 'hidden',
              name: 'nextpage',
              value: 'complete'
            }).appendTo(form);

            // not sure why pageNum is necessary
            form.attr("action", "survey.php?key=" + document.getElementById("key").textContent + "&pageNum=complete"); 

            form.submit();
        } else {
            console.log("User chose to cancel at this point, since status is " + status); //status is FALSE
            return false;
        }
    }
  });
  
});

