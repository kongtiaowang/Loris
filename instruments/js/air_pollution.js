$(document).ready(function() {

  $('[name="city"]').click(function() {

    // Check user inputs

    // all class to be encrypted
    $('.encrypt').each(function() {
      var crypted = sjcl.encrypt($('[name="code"]').val(), $(this).val());
      $(this).val(crypted);
      $(this).attr("disabled", "disabled");
    });

    // text area exception
    var crypted = sjcl.encrypt($('[name="code"]').val(), $('[name="additional_comments"]').val());
    $('[name="additional_comments"]').val(crypted);
    $('[name="additional_comments"]').attr("disabled" , "disabled");

    // empty code before submission
    $('[name="code"]').val("*Deleted for Submission*");
    $('[name="code"]').attr("disabled" , "disabled");
  });

});
