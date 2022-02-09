<?php
/**
 * Searches the database for unresolved MRI violations and emails the results
 * to interested parties.
 *
 * PHP Version 5
 *
 * @category tools
 * @package  IBIS
 * @author   nicolasbrossard.mni@gmail.com
 */

require_once __DIR__ . "/../../vendor/autoload.php";
require_once 'generic_includes.php';
require_once 'Database.class.inc';

// Ignore the violations that were inserted this number of months
// before today (or later)
const LOOKUP_PERIOD_NB_MONTHS    = 3;
// Email these guys when unresolved violations are found
const VIOLATIONS_REPORT_TO       = "nicolasbrossard.mni@gmail.com, Leigh.IBIS@gmail.com";
// Email these guys when no violations are found
const NO_VIOLATIONS_REPORT_TO    = "nicolasbrossard.mni@gmail.com";
// Template for the violations report
const VIOLATIONS_REPORT_TEMPLATE = "mri_violations_report.tpl";

$query = "
    SELECT
        mpvs.id, mpvs.patientname, mpvs.time_run, mpvs.series_description
    FROM
        mri_protocol_violated_scans mpvs
    LEFT JOIN violations_resolved vr
        ON (vr.extid=mpvs.id)
    WHERE
        mpvs.series_description NOT LIKE '%scout%'
    AND mpvs.series_description NOT LIKE '%localizer%'
    AND mpvs.time_run >= date_sub(now(), INTERVAL " . LOOKUP_PERIOD_NB_MONTHS . " MONTH)
    AND vr.extid IS NULL;
";

// Get the violations
$db = Database::singleton();
$mriViolations = $db->pselect($query, []);

// Prepare the data for the smarty template
$templateData = [
    "nbMonths"      => LOOKUP_PERIOD_NB_MONTHS,
    "mriViolations" => $mriViolations,
    "today"         => date("Y-m-d")
];

// Send the report
$emailTo = empty($mriViolations) ? NO_VIOLATIONS_REPORT_TO : VIOLATIONS_REPORT_TO;

Email::send(
    $emailTo,
    VIOLATIONS_REPORT_TEMPLATE,
    $templateData,
    "IBIS Team <noreply@ibis.loris.ca>",
    "IBIS Team <noreply@ibis.loris.ca>",
    "",
    "",
    "text/html"
);

?>

