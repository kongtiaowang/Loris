<!-- table with candidate profile info -->
  <!-- Popup form -->
    <div class="modal fade" id="editModal" tabindex="-1" role="dialog" aria-labelledby="editModalLabel" aria-hidden="true">
        <div class="modal-dialog" role="document">
            <div class="modal-content">
                <div class="modal-header">
                    <h5 class="modal-title" id="editModalLabel">Edit</h5>
                    <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                        <span aria-hidden="true">&times;</span>
                    </button>
                </div>
                <div class="modal-body">
                    <form>
                        <div class="form-group">
                            <label for="subProjectName">Sub-project Name:</label>
                              <select class="form-control" id="subProjectName" name="subProjectName">

                              </select>
                        </div>
                        <div class="form-group">
                            <label for="startDate">Start Date:</label>
                            <input type="date" class="form-control" id="startDate" name="startDate">
                        </div>
                        <input type="hidden" id="sessionID" name="sessionID" value="">

                    </form>
                </div>
                <div class="modal-footer">
                    <button type="button" class="btn btn-secondary" data-dismiss="modal">Cancel</button>
                    <button type="button" class="btn btn-primary" onclick="saveChanges()">Save</button>
                </div>
            </div>
        </div>
    </div>
</div>
<table cellpadding="2" class="table table-info table-bordered dynamictable" style="max-width:auto">
  <!-- column headings -->
  <thead>
  <tr class="info">
    <th>
    {assign var="DoB" value=$cand->getDisplayDoB()}
    {$DoB['label']} 
    </th>
    {if $candidate.EDC!=""}
      <th>
        EDC
      </th>
    {/if}
    <th>
      Biological Sex
    </th>
    <th>
      Project
    </th>
    {foreach from=$candidate.DisplayParameters item=value key=name}
      <th>
        {$name}
      </th>
    {/foreach}
  </tr>
  </thead>
  <!-- candidate data -->
  <tbody>
  <tr>
    <td>
      {$DoB['value']} 
    </td>
    {if $candidate.EDC!=""}
      <td>
        {$candidate.EDC}
      </td>
    {/if}
    <td>
      {$candidate.Sex}
    </td>
      <td>
        {$candidate.ProjectTitle}
      </td>
    {foreach from=$candidate.DisplayParameters item=value key=name}
      <td>
        {$value}
      </td>
    {/foreach}
  </tr>
  </tbody>
</table>

<div class="col-xs-12 row">
    {$actions}
</div>
<br>
<br>
<br>
<br>
<br>
<br>

<!-- table title -->
<strong>List of Visits (Time Points)</strong>
<!-- list of timepoints table -->
<table style="margin-top:0" class="table table-hover table-primary table-bordered dynamictable" cellpadding="2">
    <!-- table column headings -->
    <thead>
        <tr class="info">
            <th>Visit Label<BR>(Click to Open)</th>
            <th>Cohort</th>
            <th>Site</th>
            <th>Project</th>
            <th>Stage</th>
            <th>Stage Status</th>
            <th>Date of Stage</th>
            <th>Sent To DCC</th>
            <th>Imaging Scan Done</th>
            <th>Feedback</th>
            <th>BVL QC</th>
            <th>BVL Exclusion</th>
            <th>Registered By</th>
            <th>Edit/Archive</th>
        </tr>
    </thead>
    <tbody>
    {section name=timepoint loop=$timePoints}
        <tr>
            <td><a href="{$baseurl|default}/instrument_list/?candID={$candID}&sessionID={$timePoints[timepoint].SessionID}">{$timePoints[timepoint].Visit_label}</a></td>

            <td>{$timePoints[timepoint].CohortTitle}</td>

            <td>{$timePoints[timepoint].SiteAlias}</td>
            <td>{$timePoints[timepoint].ProjectName}</td>

            {if $timePoints[timepoint].staticStage|default != "" || $timePoints[timepoint].Current_stage == "Not Started"}
            <td colspan="3">{$timePoints[timepoint].Current_stage}</td>
            {else}
            <td>{$timePoints[timepoint].Current_stage}</td>
            <td>{$timePoints[timepoint].currentStatus}</td>
            <td>{$timePoints[timepoint].currentDate}</td>
            {/if}

            <td>
            {if $timePoints[timepoint].Submitted == "Y"}
        	    <img src="{$baseurl|default}/images/check_blue.gif" border="0" />
            {else}
        	    -
            {/if}
            </td>
            <td>
            {if $timePoints[timepoint].Scan_done != ""}
                    {if $timePoints[timepoint].Scan_done == 'Y'}
                        {assign var="scan_done" value="Yes"}
                        <a href="{$baseurl|default}/imaging_browser/viewSession/?sessionID={$timePoints[timepoint].SessionID}" class="timepoint_list">
                        {$scan_done}</a>
                    {else}
                        {assign var="scan_done" value="No"}
                        {$scan_done}
                    {/if}
            {else}
                <img alt="Data Missing" src="{$baseurl|default}/images/help2.gif" border=0>
            {/if}
            </td>

            <td bgColor="{$timePoints[timepoint].feedbackColor}">
            {if $timePoints[timepoint].feedbackCount}
                {$timePoints[timepoint].feedbackStatus}
            {else}
                -
            {/if}
            </td>

            <td>
            {if $timePoints[timepoint].BVLQCStatus}
                {$timePoints[timepoint].BVLQCType}
            {else}
                <img src="{$baseurl|default}/images/delete.gif" border="0" />
            {/if}
            </td>

            <td>
            {if $timePoints[timepoint].BVLQCExclusion}
                {if $timePoints[timepoint].BVLQCExclusion == 'Not Excluded'}
                Pass
                {else}
                Fail
                {/if}
            {else}
                <img src="{$baseurl|default}/images/delete.gif" border="0" />
            {/if}
            </td>

            <td>
                {$timePoints[timepoint].Real_name}
            </td>
             <td style="white-space: nowrap;">
   <!-- Edit button -->
    <button type="button" class="btn btn-primary" data-toggle="modal" data-target="#editModal" onclick="openEditModal('{$timePoints[timepoint].SessionID}', '{$timePoints[timepoint].currentDate}', '{$timePoints[timepoint].test}','{$timePoints[timepoint].CohortTitle}')">
        Edit
    </button>
        <button type="button" class="btn btn-danger" onclick="deleteItem({$timePoints[timepoint].SessionID})">
        Archive
    </button>
             </td>
        </tr>
    {sectionelse}
        <tr><td colspan="10">You do not have access to any timepoints registered for this candidate.</td></tr>
    {/section}
    </tbody>
</table>
<script>
    function saveChanges() {

        var sessionID = document.getElementById('sessionID');
        console.log(sessionID.value);
        var modalDate = document.getElementById('startDate');
        var newdate = modalDate.value;
        console.log(newdate);



        if (confirm('Are you sure you want to edit this profile?')) {
            fetch(window.location.href, {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'
                    // Add any other headers as needed
                },
                // You can include a request body if required
                 body: JSON.stringify({ sessionID: sessionID.value,date: newdate})
            })
            .then(response => {
                if (!response.ok) {
                    throw new Error('Network response was not ok');
                }
                return response.json();
            })
            .then(data => {
                // Handle the response data as needed
                console.log(data);
                window.location.reload();
                // Optionally, you can redirect or update the UI after successful deletion
            })
            .catch(error => {
                console.error('There was a problem with your fetch operation:', error);
                // Handle errors or show a message to the user
            });
        }



        $('#editModal').modal('hide');
    }    


    function deleteItem($sessionID) {
        if (confirm('Are you sure you want to delete this time point?')) {
            fetch(window.location.href, {
                method: 'DELETE',
                headers: {
                    'Content-Type': 'application/json'
                    // Add any other headers as needed
                },
                // You can include a request body if required
                 body: JSON.stringify({ sessionID: $sessionID})
            })
            .then(response => {
                if (!response.ok) {
                    throw new Error('Network response was not ok');
                }
                return response.json();
            })
            .then(data => {
                // Handle the response data as needed
                console.log(data);
                window.location.reload();
                // Optionally, you can redirect or update the UI after successful deletion
            })
            .catch(error => {
                console.error('There was a problem with your fetch operation:', error);
                // Handle errors or show a message to the user
            });
        }
    }

    function openEditModal(param1, param2,param3,param4) {

        // Display the passed parameters in the modal
        var modalDate = document.getElementById('startDate');
        console.log(param2);
        modalDate.value = param2;
        var sessionID = document.getElementById('sessionID');
        console.log(param1);
        sessionID.value = param1;
        console.log(param3);

var str = "Fresdfjkdh@Fresh@s-c";

// Split the string by "@" delimiter
var parts = str.split('@');

// Get the select element
var select = document.getElementById('subProjectName');

// Loop through the parts array and create an option for each part
parts.forEach(function(part) {
    var option = document.createElement('option');
    option.value = part; // Set the value of the option
    option.text = part;  // Set the text displayed in the option
    select.appendChild(option); // Append the option to the select element
        // Set the default value based on param4
        if (part === param4) {
            option.selected = true;
        }
});





    }

</script>
