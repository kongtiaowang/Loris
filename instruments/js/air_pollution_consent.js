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
    } else {
      alert("You must select 'Yes' to continue"); 
      return false;
    }
    
  });
});
