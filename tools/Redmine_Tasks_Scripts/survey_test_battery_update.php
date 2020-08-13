<?php
/**
 * Configure survey_test_battery based on Redmine 17825
 *
 * @category Main
 * @package  Survey test battery Update
 * @author   Sruthy Mathew
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @version  GIT: <git_id>
 * @link     https://www.github.com/aces/IBIS/
 */
set_include_path(get_include_path().":../../libraries:../../../php/libraries:");
require_once __DIR__ . "/../../../vendor/autoload.php";
require_once "Database.class.inc";
require_once "Utility.class.inc";
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../../config.xml');

$VSA_array=array("ABCL Informant (Adult Informant Behavior Checklist – Ages 18 to 59) - Dad on Mom - Survey",
    "ABCL Informant (Adult Informant Behavior Checklist - Ages 18 to 59) - Mom on Dad - Survey",
    "ABCL Self (Adult Self Behavior Checklist - Ages 18 to 59) - Dad - Survey",
    "ABCL Self (Adult Self Behavior Checklist - Ages 18 to 59) - Mom - Survey",
    "ABC2 (Aberrant Behavior Checklist) - Survey",
    "BRIEF2 Parent (Behavior Rating Inventory of Executive Functioning) - Survey",
    "BRIEF2 Teacher (Behavior Rating Inventory of Executive Functioning) - Survey",
    "CBCL (Child Behavior Checklist) 6 to 18 years - Survey",
    "CCC2 – Children’s Communication Checklist 2 - Survey",
    "Charge GI Form (Gastro Intestinal) - Survey",
    "CSHQ (Children's Sleep Habits Questionnaire) - Survey",
"CONNERS-3 Parent Short - Survey",
"CONNERS-3 Teacher Short - Survey",
"IBIS Perinatal Data Form - Survey",
"MASC2 - Parent (Multidimensional Anxiety Scale for Children - Parent) - Survey",
"MASC2 - Self Report (Multidimensional Anxiety Scale for Children - Self-Report) - Survey",
"PSPQ Self (Personality Styles & Preferences) - Dad - Survey",
"PSPQ Self (Personality Styles & Preferences) - Mom - Survey",
"PSPQ Informant (Personality Styles & Preferences) - Dad on Mom - Survey",
"PSPQ Informant (Personality Styles & Preferences) - Mom on Dad - Survey",
"QRS - Proband (Questionnaire on Resources and Stress - Proband) - Survey",
"QRS - Subject (Questionnaire on Resources and Stress - Subject) - Survey",
"RBS-R - Proband (Repetitive Behavior Scale Revised - Proband) - Survey",
"RBS-R - Subject (Repetitive Behavior Scale Revised - Subject) - Survey",
"SCQ Proband (Social Communication Questionnaire) - Survey",
"Seizure Questionnaire - Survey",
"SEQ3 (Sensory Experiences Questionnaire - Version 3.0) - Survey",
"SRS-2 Self (Social Responsiveness Scale – Self) – Dad - Survey",
"SRS-2 Self (Social Responsiveness Scale – Self) – Mom - Survey",
"SRS-2 Informant - Dad on Mom (Social Responsiveness Scale – Informant) - Dad on Mom - Survey",
"SRS-2 Informant - Mom on Dad (Social Responsiveness Scale – Informant) - Mom on Dad - Survey",
"SRS-2 SA - Proband (Social Responsiveness Scale – School Age - Proband) - Dad OR Mom - Survey",
"SRS-2 SA - Subject (Social Responsiveness Scale – School Age - Subject) - Dad OR Mom - Survey",
"SRS-2 SA - Teacher (Social Responsiveness Scale – School Age - Teacher) - Teacher - Survey",
"SSIS Parent (Social Skills Improvement System) - Survey",
"SSIS Teacher (Social Skills Improvement System) - Survey",
"TANNER Staging Questionnaire (Boys) - Survey",
"TANNER Staging Questionnaire (Girls) - Survey",
"TRF (Teacher's Report Form) Ages 6 to 18 - Survey",
"Peer Contact Questionnaire – Survey",
"AP (Air Pollution) - Survey",
"SSCQ (Sibling Social Contact Questionnaire) - Survey"
);
$V06_array = array('ACE Family Medical History - Survey',
'ACE Subject Medical History - Survey',
'APSI (Autism Parent Screen for Infants) - Survey',
'BISQ (Brief Infant Sleep Questionnaire) - Survey',
'IBQ-R (Infant Behavior Questionnaire - Revised) - Survey',
'PSPQ Self (Personality Styles & Preferences) - Dad - Survey',
'PSPQ Self (Personality Styles & Preferences) - Mom - Survey',
'PSPQ Informant (Personality Styles & Preferences) - Dad on Mom - Survey',
'PSPQ Informant (Personality Styles & Preferences) - Mom on Dad - Survey',
'RBSC - EC (Repetitive Behavior Scale for Early Childhood - Infant Items) - Survey',
'RBSC - EC (Repetitive Behavior Scale for Early Childhood - Supplement) - Survey',
'RBS-R - Proband (Repetitive Behavior Scale Revised - Proband) - Survey',
'RBS-R - Subject (Repetitive Behavior Scale Revised - Subject) - Survey',
'SCQ Proband (Social Communication Questionnaire) - Survey',
'SMQ - Infant (Social Motivation Questionnaire - Infant) - Survey',
'SRS-2 Self (Social Responsiveness Scale – Self) – Dad - Survey',
'SRS-2 Self (Social Responsiveness Scale – Self) – Mom - Survey',
'SRS-2 Informant - Dad on Mom (Social Responsiveness Scale – Informant) - Dad on Mom - Survey',
'SRS-2 Informant - Mom on Dad (Social Responsiveness Scale – Informant) - Mom on Dad - Survey',
'SRS-2 Pre-School (Social Responsiveness Scale - Pre-School) - Survey',
'Peer Contact Questionnaire – Survey',
'Medical and Psychiatric History - Survey',
'SSCQ (Sibling Social Contact Questionnaire) - Survey'
);

$V12_array= array('ACE Family Medical History - Survey',
'ACE Subject Medical History - Survey',
'APSI (Autism Parent Screen for Infants) - Survey',
'BISQ (Brief Infant Sleep Questionnaire) - Survey',
'FYI (First Year Inventory) - Survey',
'IBQ-R (Infant Behavior Questionnaire - Revised) - Survey',
'MCDI - Words & Gestures - Survey',
'MCDI - Words, Sentences & Gestures - Survey',
'RBS - EC - G (Repetitive Behavior Scale for Early Childhood - General Version) - Survey',
'RBS-R - Proband (Repetitive Behavior Scale Revised - Proband) - Survey',
'RBS-R - Subject (Repetitive Behavior Scale Revised - Subject) - Survey',
'SCQ Proband (Social Communication Questionnaire) - Survey',
'SEQ3 (Sensory Experiences Questionnaire - Version 3.0) - Survey',
'SMQ - Infant (Social Motivation Questionnaire - Infant) - Survey',
'Peer Contact Questionnaire – Survey',
'Medical and Psychiatric History - Survey',
'SSCQ (Sibling Social Contact Questionnaire) - Survey',
);

$V24_array=array('ACE Family Medical History - Survey',
'ACE Subject Medical History - Survey',
'APSI (Autism Parent Screen for Infants) - Survey',
'BISQ (Brief Infant Sleep Questionnaire) - Survey',
'CBCL (Child Behavior Checklist) 1.5 to 5 years - Survey',
'ECBQ (Early Childhood Behavior Questionnaire) - Survey',
'MCDI - Words & Gestures - Survey',
'MCDI - Words, Sentences & Gestures - Survey',
'PSPQ Self (Personality Styles & Preferences) - Dad - Survey',
'PSPQ Self (Personality Styles & Preferences) - Mom - Survey',
'PSPQ Informant (Personality Styles & Preferences) - Dad on Mom - Survey',
'PSPQ Informant (Personality Styles & Preferences) - Mom on Dad - Survey',
'QRS - Proband (Questionnaire on Resources and Stress - Proband) - Survey',
'QRS - Subject (Questionnaire on Resources and Stress - Subject) - Survey',
'RBS - EC - G (Repetitive Behavior Scale for Early Childhood - General Version) - Survey',
'RBS-R - Proband (Repetitive Behavior Scale Revised - Proband) - Survey',
'RBS-R - Subject (Repetitive Behavior Scale Revised - Subject) - Survey',
'SCQ Proband (Social Communication Questionnaire) - Survey',
'SEQ3 (Sensory Experiences Questionnaire - Version 3.0) - Survey',
'SMQ - Toddler (Social Motivation Questionnaire - Toddler) - Survey',
'Peer Contact Questionnaire – Survey',
'Medical and Psychiatric History - Survey',
'SSCQ (Sibling Social Contact Questionnaire) - Survey',
);
$DB         = \Database::singleton();
$count=0;
foreach ($VSA_array as $instr_value )
{
    $count++;

    $visits=array('VSA','VSA-CVD');
    foreach ($visits as $visit)
    {
     $test_name=getTestName($instr_value);
     $available=isAvailable($test_name,$visit);
        if($available==0 && $test_name!='Not Found')
     {

         $vals = array('Test_name'=>$test_name, 'Visit_label'=>$visit);
         $success = $DB->insert("survey_test_battery",$vals);
     }
    }
}
echo "Total $count VSA/VSA-CVD instruments found\n";
echo "VSA/VSA-CVD test battery configuration complete\n";
$count=0;
foreach ($V06_array as $instr_value)
{
    $count++;
    $visits=array('V06','V6-CVD');
    foreach ($visits as $visit)
    {
        $test_name=getTestName($instr_value);
        $available=isAvailable($test_name,$visit);
        if($available==0 && $test_name!='Not Found')
        {

            $vals = array('Test_name'=>$test_name, 'Visit_label'=>$visit);
            $DB->insert("survey_test_battery",$vals);
        }
    }
}
echo "Total $count V06/V6-CVD instruments found\n";
$count=0;
echo "V06/V6-CVD test battery configuration complete\n";

foreach ($V12_array as $instr_value ) {
    $count++;
    $visits = array('V12', 'V12-CVD');
    foreach ($visits as $visit) {
        $test_name = getTestName($instr_value);
        $available = isAvailable($test_name, $visit);
        if($available==0 && $test_name!='Not Found') {

            $vals = array('Test_name' => $test_name, 'Visit_label' => $visit);
            $success = $DB->insert("survey_test_battery", $vals);
        }

    }
}
echo "Total $count V12/V12-CVD instruments found\n";
$count=0;
echo "V12/V12-CVD test battery configuration complete\n";

foreach ($V24_array as $instr_value )
{
    $count++;
    $visits=array('V24','V24-CVD');
    foreach ($visits as $visit)
    {
        $test_name=getTestName($instr_value);
        $available=isAvailable($test_name,$visit);
        if($available==0 && $test_name!='Not Found')
        {

            $vals = array('Test_name'=>$test_name, 'Visit_label'=>$visit);
            $success = $DB->insert("survey_test_battery",$vals);
        }
    }
}
echo "Total $count V24/V24-CVD instruments found\n";
$count=0;
echo "V24/V24-CVD test battery configuration complete\n";

function getTestName($name)
{
    $DB         = \Database::singleton();
    $val= $DB->pselectRow("select test_name from test_names where Full_name=:fn",
        array('fn'     => $name));
    if(!empty($val))
    {
        return ($val['test_name']);
    }

    else
    {
        return ('Not Found');
    }

}

function isAvailable($instr,$visit)
{
    $DB         = \Database::singleton();
    $already_added = $DB->pselectOne("select count(*) from survey_test_battery where Visit_label=:vl and Test_name=:tn",
        array('vl'     => $visit,  'tn'   => $instr));
    return $already_added;
}

?>