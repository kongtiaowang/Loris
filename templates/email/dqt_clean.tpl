Subject: [IBIS DQT] Missing Data Dictionary - {$today_date}

<b>The below list of doc ids were deleted from the Clean DQT:</b>

<ul>
    {foreach from=$deleted item=val key=k}
        <li>{$val}</li>
    {/foreach}
</ul>

<b>The below list of doc ids were not handled by the script:</b>

<ul>
    {foreach from=$unknown item=val key=k}
        <li>{$val}</li>
    {/foreach}
</ul>

Thank you,
<br>
IBIS Team
