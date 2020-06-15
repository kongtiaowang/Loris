<?php
/**
 * Merge all caveat info into participant_status_comments
 *
 * @category Main
 * @package  update common Loris fields across candidates
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
$db        =& Database::singleton();
$confirm=false;
$c=0;
if (!empty($argv[1]) && $argv[1] == 'confirm') {
    $confirm = true;
}
$c=0;
$total=0;
$candidates=$db->pselect("select CandID from candidate where Active='Y'",array());


foreach ($candidates as $candidate) {

    $update_values = $db->pselectRow("select c.PSCID,
c.CandID,co.Description as caveat_reason,
c.flagged_other as caveat_other_comment,
ps.reason_specify as ps_comment from participant_status ps 
 join candidate c ON (c.CandID=ps.CandID)
LEFT join caveat_options co ON (c.flagged_reason=co.ID) where c.CandID=:cid",
        array('cid' => $candidate['CandID']));
    if (!empty($update_values)) {
        $total++;
$candidate_comment=getCandidateComment($candidate['CandID']);

                        $final_concatenated_string="";
                        if($update_values['caveat_reason']!='' OR $update_values['caveat_reason']!=NULL)
                        {
                            $final_concatenated_string.=$update_values['caveat_reason'].";";
                        }
                        if($update_values['caveat_other_comment']!='' OR $update_values['caveat_other_comment']!=NULL)
                        {
                            $final_concatenated_string.=$update_values['caveat_other_comment'].";";
                        }
                        if($candidate_comment!='' OR $candidate_comment!=NULL)
                        {
                            $final_concatenated_string.=$candidate_comment.";";
                        }
                        if($update_values['ps_comment']!='' OR $update_values['ps_comment']!=NULL)
                        {
                            $final_concatenated_string.=$update_values['ps_comment']."";
                        }
                        if($final_concatenated_string!=='')
                        {
                            $c++;
                            print $c . ")" . $update_values['PSCID'] . "\n";
                       /*     print"
                        *Caveat Reason({$update_values['caveat_reason']})\n
                        *Caveat Other Comment({$update_values['caveat_other_comment']})\n
                        *Candidate Comment({$candidate_comment})\n
                        *Participant_comment(({$update_values['ps_comment']})\n";*/

                            print "FINAL CONCATENATED COMMENT= {$final_concatenated_string}";

                        }


        print"\n";
        if ($confirm) {

            print "Updated\n";

            $db->update('participant_status',
                array(
                    'reason_specify'    => $final_concatenated_string,

                ),
                array(
                    'CandID'          =>$candidate['CandID']
                )
            );
            print"\n";
        }


    }
}

                if($confirm)
                {
                    print "\n{$c} information updated out of {$total} records";
                }
                else{
                    print"\n{$c} Entries found ready to update out of {$total} records\n";
                    print "\nIf you feel good to update the data with the above information; please Run this tool again with the argument 'confirm'\n";

                }


function getCandidateComment($candid)
{
    $db =& Database::singleton();
    $candidate_comment = $db->pselectRow("SELECT pc.Value as candidate_comment FROM parameter_type pt
JOIN parameter_type_category_rel ptcr USING (ParameterTypeID)
JOIN parameter_type_category ptc USING (ParameterTypeCategoryID)
JOIN parameter_candidate pc USING(ParameterTypeID)
join candidate c oN (c.CandID=pc.CandID)
WHERE ptc.Name='Candidate Parameters' and pt.Name ='candidate_comment' and c.CandID=:cid",
        array('cid' => $candid));
if(!empty($candidate_comment))
{
    return $candidate_comment['candidate_comment'];
}
    else{
        return '';
    }
}

?>



