Subject: [IBIS DQT] Missing Data Dictionary - {$today_date}

<b>The below list of instruments are missing their full data dictionary in the DQT:</b>

<ul>
    {foreach from=$instruments item=val key=k}
        <li>{$val}</li>
    {/foreach}
</ul>

To update the Data Dictionary run the <i>data_dictionary_builder.php</i> to update the parameter
type table. The DQT data dictionary will update during the scheduled cronjob.

Thank you,
<br>
IBIS Team
