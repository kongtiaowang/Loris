<script
  type="text/javascript"
  src="{$baseurl}/statistics_ibis/js/form_stats_automated.js"
></script>
<div id="automated">
  <h2 class="statsH2">
    Automated Statistics{if $CurrentSite} for {$CurrentSite.Name}{/if}
  </h2>
  <div class="col-sm-3 col-xs-12 form-group">
    <button
      onClick="getDirectDataReportEP()"
      class="btn btn-primary btn-small col-xs-12"
    >
      Direct Assessments - EP
    </button>
  </div>
  <div class="col-sm-3 col-xs-12 form-group">
    <button
      onClick="getDirectDataReportSA()"
      id="DirectSA"
      class="btn btn-primary btn-small col-xs-12"
    >
      Direct Assessments - SA
    </button>
  </div>
  <div class="col-sm-3 col-xs-12 form-group">
    <button
      onClick="getDirectDataReportDSInfant()"
      class="btn btn-primary btn-small col-xs-12"
    >
      Direct Assessments - DS-Infant
    </button>
  </div>
  <br /><br /><br />
</div>
<div class="alert alert-warning" role="alert" id="alert" style="display: none">
  Loading...
</div>
