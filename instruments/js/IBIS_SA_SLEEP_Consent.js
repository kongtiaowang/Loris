$(document).ready(function () {

  $("#savecontinue").unbind("click");

  $("#savecontinue").click(function (e) {
    console.log("save clicked");
    var comment = $('[name = "commentId"]').val();
    var IBIS_SA_SLEEP_Consent = $('[name = "IBIS_SA_SLEEP_Consent"]').val();
    var isSafari = navigator.vendor.indexOf("Apple") == 0 && /\sSafari\//.test(navigator.userAgent); // true or false

    if (IBIS_SA_SLEEP_Consent == '') {
      alert("Please select an option.");
      return false;
    } else {
      $.ajax({
        type: 'POST',
        async: isSafari,
        data: {
          comment: comment,
          IBIS_SA_SLEEP_Consent: IBIS_SA_SLEEP_Consent
        },
        url: '/UpdateIBISSASLEEPConsent.php',
        success: function (data) {
          var form = $("#test_form");
          $("<input>").attr({
            type: 'hidden',
            name: 'nextpage',
            value: '1'
          }).appendTo(form);
          form.submit();
        },
        error: function (data) {
        }
      });
      return false;
    }

  });
});
