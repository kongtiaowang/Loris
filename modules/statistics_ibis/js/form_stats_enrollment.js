/*global document, $*/
function updateEnrollmentTab() {       
    var EnrollmentProject = document.getElementById("EnrollmentProject");
    var EnrollmentSite = document.getElementById("EnrollmentSite");
    var EnrollmentSubProject = document.getElementById("EnrollmentSubProject");
    var request = $.ajax({
        url: loris.BaseURL + '/statistics_ibis/stats_enrollment/?dynamictabs=dynamictabs&EnrollmentProject=' + EnrollmentProject.value + '&EnrollmentSite=' + EnrollmentSite.value+ '&EnrollmentSubProject=' + EnrollmentSubProject.value,
        type: 'GET',
        data: 'html',
        success: function(response) {
            $('#enrollment').html(response);
        }
   });
}
function getSubProjects()
{
    var en_pr_id = document.getElementById("EnrollmentProject").value;
    request = $.ajax({
        url: loris.BaseURL + "/statistics_ibis/ajax/getSubProjects.php",
        type: "get",
        dataType: "json",
        data: {"project_id" : en_pr_id},
        success: function(data) {
            $("#EnrollmentSubProject > option").remove();
            if (data == 0) {

                var $enrollsubp_dropdown = $('#EnrollmentSubProject');
                $enrollsubp_dropdown.append(new Option("All SubProjects", ''));

            }
            else {
                var result = JSON.stringify(data)
                var $enrollsubp_dropdown = $('#EnrollmentSubProject');
                var obj = $.parseJSON(result);
                $enrollsubp_dropdown.append(new Option("All SubProjects", ''));
                for (var prop in obj) {

                    $enrollsubp_dropdown.append(new Option(obj[prop], prop));
                }

            }
            $("#EnrollmentSubProject").find("option").addClass("form-control option");
        }


    });
}