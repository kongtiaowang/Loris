{if $isDataEntryPerson || $isImagingPerson}
    <!-- <div class="col-xs-1"> -->
        <h3>{dgettext("timepoint_list", "Actions:")}&nbsp&nbsp</h3>
    <!-- </div> -->
    <!-- <div class="col-xs-4"> -->
    {if $isImagingPerson}
        <a class="btn btn-default" role="button" href="{$baseurl}/imaging_browser/?DCCID={$candID}">{dgettext("timepoint_list", "View Imaging datasets")}</a>
    {/if}
    <!-- </div> -->
{/if}

