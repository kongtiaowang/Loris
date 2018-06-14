<!--<script type="text/javascript" src="https://msruthy-dev.loris.ca/parent_portal/js/hello.js"></script> -->
<div class="container">
    <div align="center">
        <h2>{$page_title} </h2>
    </div>
    <br>
        <table class="table table-striped table-bordered">
        <tbody><tr class="reviewPage">
            <td><div><b>No</b></div></td>
            <td><div><b>Survey</b></div></td>
            <td><div><b>Status</b></div></td>
            <td><div><b>Survey Link</b></div></td>
            <td><div><b>Estimated Time To Complete (Minutes)</b></div></td>
        </tr>
        {assign var=number value=1}
        {section name=data loop=$survey_data}
        <tr class="reviewPage">
            <td><div><p>{$number++}</p></div></td>
            <td><div><p>{$survey_data[data].Full_name}</p></div></td>
            {if $survey_data[data].Status == 'Complete'}
                <td bgcolor="#8fbc8f"><div><p>{$survey_data[data].Status}</p></div></td>
            {elseif $survey_data[data].Status == 'In Progress' }
                <td bgcolor="#f2f830 "><div><p>{$survey_data[data].Status}</p></div></td>
            {else}
            <td bgcolor="#eca697 "><div><p>Not Started</p></div></td>
            {/if}
            <td><div><p><a href="{$url}{$survey_data[data].OneTimePassword}" target="_blank">Open Survey</a></p></div></td>
            {if $survey_data[data].completion_time === '' || $survey_data[data].completion_time === NULL}
            <td><div><p>--</p></div></td>
                {else}
                <td><div><p>{$survey_data[data].completion_time}</p></div></td>
            {/if}
        </tr>
        {/section}
        </tbody>
        </table>
    </div>
</div>
