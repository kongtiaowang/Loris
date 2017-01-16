// Add Record 
function addRecord() {
    // get values
    var content = $("#content").val();
    // Add record
    $.post("ajax/addRecord.php", {
        content: content
    }, function (data, status) {
        // close the popup
        $("#add_new_record_modal").modal("hide");
        // read records again
        readRecords();
         
        // clear fields from the popup
        $("#content").val("");
    });
}
 
// READ records
function readRecords() {
    $.get("ajax/readRecords.php", {}, function (data, status) {
        $(".records_content").html(data);
       //alert(data);
    });
}

function DeleteUser(id) {
    var conf = confirm("Are you sure, do you really want to delete User?");
    if (conf == true) {
        $.post("ajax/deleteUser.php", {
                id: id
            },
            function (data, status) {
                // reload Users by using readRecords();
                readRecords();
            }
        );
    }
}
 



$(document).ready(function () {
   //  READ recods on page load
    readRecords(); // calling function
});
