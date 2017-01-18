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

function GetTodoDetails(id) {

    $("#hidden_user_id").val(id);
    $.post("ajax/readTodoDetails.php", {
            id: id
        },
        function (data, status) {
          var todo = JSON.parse(data);
            $("#update_content").val(todo.content);
        }
    );
    // Open modal popup
    $("#update_todo_modal").modal("show");
}

function DeleteTodo(id) {
    var conf = confirm("Are you sure, do you really want to delete this todo?");
    if (conf == true) {
        $.post("ajax/deleteTodo.php", {
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


