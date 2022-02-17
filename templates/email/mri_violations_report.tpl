Subject: Pending unresolved MRI violations report {$today}

<html>
  <head>
      <style>
         table, th, td {
            border: 1px solid black;
         }
      </style>
  </head>
  <body>
  {if count($mriViolations)} 
    <b>There are still MRI violations found in the past {$nbMonths} months that need to be addressed:</b>
    <br>
    <br>
    <table>
       <tr>
          <th>ID</th>
          <th>Patient Name</th>
          <th>Time Run</th>
          <th>Series Description</th>
       </tr>

       {foreach from=$mriViolations item=mriViolation}
       <tr>
          <td>{$mriViolation.id}</td>
          <td>{$mriViolation.patientname}</td>
          <td>{$mriViolation.time_run}</td>
          <td>{$mriViolation.series_description}</td>
       </tr>
       {/foreach}
    </table>
  {else}
    <b>No unaddressed MRI violations were found in the past {$nbMonths} months. We rock!</b>
  {/if}
    <br>
    <br>
    <br>
    <br>
  Thank you,
  <br>
  IBIS Team
  </body>
</html>
