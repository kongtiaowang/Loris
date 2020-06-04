<?php
/**
 * Update Common Loris fields(Dat_taken, examiner,data_entry etc for the globally parsed instruments like Shipley, NIH)
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
$filename="parser_global_common_fields_update_{$argv[1]}.csv";
$testname=$argv[1];
$confirm=false;
$c=0;
if (!empty($argv[2]) && $argv[2] == 'confirm') {
    $confirm = true;
}

            $in_values_string = "";
            if (($handle = fopen('../csv_files/' . $filename, 'r')) !== FALSE) {
                fgetcsv($handle);
                $total= 0;
                $map_count=0;
                while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
                    $total++;
                    $getcommentID = $db->pselectRow("select instr.commentID,c.DoB from candidate c
                                          JOIN session s ON(c.candID=s.candID)
                                          JOIN flag f ON(f.sessionID=s.ID)
                                          JOIN  $testname instr ON(instr.commentID=f.commentID)
                                          where c.PSCID=:pcid and s.visit_label=:vl and f.commentID 
                                          not like '%DDE%'",
                        array('pcid' => $data[0], 'vl' => $data[2]));
                    if(empty($getcommentID))
                    {
                        print "\n".$data[0] . "--->" . $data[2] . "--->No relevant commentID detected on script running database)\n";
                    }
                    else {
                        $age = Utility::calculateAge($getcommentID['DoB'], $data[3]);
                        $agemonths = calculateAgeMonths($age);
                        print"\n";
                        $c++;
                        $examiner=getExaminerID($data[4]);
                        print "\n PSCID({$data[0]})----Visit({$data[2]})----CommentID{$getcommentID['commentID']}\n";
                        print "Examiner($examiner -$data[4])---CandidateAge($agemonths)----Date_taken($data[3])\n";
                        if($confirm)
                        {

                            $db->update($testname,
                                array(
                                    'examiner'    => getExaminerID($data[4]),
                                    'Candidate_age'=>$agemonths,
                                    'Date_taken'  =>$data[3],
                                    'Data_entry_completion_status' =>'Complete'

                                ),
                                array(
                                    'commentID'          =>$getcommentID['commentID']
                                )
                            );
                            $db->update('flag',
                                array(
                                    'Data_entry'      => 'Complete',
                                    'Administration'    =>'All'

                                ),
                                array(
                                    'commentID'          =>$getcommentID['commentID']
                                )
                            );

                            print "\n {$getcommentID['commentID']}...Updated...";
                        }
                    }

                }
                fclose($handle);
                if($confirm)
                {
                    print "\n{$c} information updated out of the total {$total} found in the csv file\n";
                }
                else{
                    print"\n{$c} Entries found ready to map with the right information out of the total {$total} found in the csv file\n";
                    print "\nIf you feel good to update the data with the above information; please Run this tool again with the argument 'confirm'\n";

                }

            }
function getExaminerID($fullName)
{
    $DB         = \Database::singleton();
    $examinerID = $DB->pselectOne(
        "SELECT examinerID
             FROM examiners
             WHERE full_name=:fullName",
        array('fullName' => $fullName)
    );

    //returned as a string
    return $examinerID;
}

function calculateAgeMonths($age)
{
    $months = $age['year']*12 + $age['mon'] + ($age['day']/30);
    // 1 Decimal.
    $months = (round($months*10) / 10.0);
    return $months;
}

?>