Subject: [IBIS Study] ELSI Consented Candidate List - {$today_date}

<b>The below list of Candidates has given 'YES' consent to ELSI.</b><br>

<table  border="1">
   <tr><td>No</td><td>PSCID</td><td>Consent Name</td><td>Consent Status</td><td>Date Given</td></tr>
{foreach from=$yes_consent_list item=val key=k}
   {$val}
{/foreach}
</table>
Thank you,
<br>
IBIS Team