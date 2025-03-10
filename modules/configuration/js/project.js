$(document).ready(function() {
    "use strict";
    $('div').tooltip();
    $(".saveproject").click(function(e) {
        var form = $(e.currentTarget).closest('form');

        var ProjectID = $(form.find(".ProjectID")).val();
        var Name = $(form.find(".projectName")).val();
        var Alias = $(form.find(".projectAlias")).val();
        var recruitmentTarget= $(form.find(".projectrecruitmentTarget")).val();
        var CohortIDs= $(form.find(".projectCohortIDs")).val();

        e.preventDefault();
        var successClosure = function(i, form) {
          return function() {
            $(form.find(".saveStatus")).text("Successfully saved").css({ 'color': 'black'}).fadeIn(500).delay(1000).fadeOut(500);
            if (ProjectID === 'new') {
              setTimeout(function(){
                location.reload();
              }, 1000);
            } else {
              var projectDiv = document.getElementById(`#project${ProjectID}`);
              var oldName = projectDiv.innerText;
              projectDiv.innerText = Name;
              var projectHeader = document.getElementById(`project${ProjectID}`);
              projectHeader.children[0].innerText = Name + projectHeader.children[0].innerText.substring(
                oldName.length
              );
            }
          }
        }

        var errorClosure = function(i, form) {
          if (!Name) {
            return function () {
              $(form.find(".saveStatus")).text("Failed to save, must enter a Project Name!").css({'color': 'red'}).fadeIn(500).delay(1000).fadeOut(500);
            }
          } else if (!Alias) {
            return function () {
              $(form.find(".saveStatus")).text("Failed to save, must enter an Alias!").css({'color': 'red'}).fadeIn(500).delay(1000).fadeOut(500);
            }
          } else if (isNaN(recruitmentTarget)) {
            return function () {
              $(form.find(".saveStatus")).text("Failed to save, recruitment target must be an integer!").css({'color': 'red'}).fadeIn(500).delay(1000).fadeOut(500);
            }
          } else if (Alias.length > 4){
            return function () {
              $(form.find(".saveStatus")).text("Failed to save, Alias should be at most 4 characters long!").css({'color': 'red'}).fadeIn(500).delay(1000).fadeOut(500);
            }
          } else {
            return function () {
              $(form.find(".saveStatus")).text("Failed to save, same name already exist!").css({'color': 'red'}).fadeIn(500).delay(1000).fadeOut(500);
            }
          }
        }

        jQuery.ajax(
                {
                    "type" : "post",
                    "url" : loris.BaseURL + "/configuration/ajax/updateProject.php",
                    "data" : {
                        "ProjectID" : ProjectID,
                        "Name" : Name,
                        "Alias" : Alias,
                        "recruitmentTarget" : recruitmentTarget,
                        "CohortIDs" : CohortIDs
                    },
                    "success" : successClosure(ProjectID, form),
                    "error" : errorClosure(ProjectID, form)
                }

          );
    });
});
