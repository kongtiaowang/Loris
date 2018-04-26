<?php
/**
 * Map wrong information entered in comments to the right column Interviewed By for PSS
 * Once completed, we will remove the separate not answered status field for past and future PSS
 *
 * @category Main
 * @package  map scattered interviewed_by information to the right column for PSS
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
$filename="PSS_Interviewed_By_DataTransfer.csv";
$confirm=false;
if (!empty($argv[1]) && $argv[1] == 'confirm') {
    $confirm = true;
}

            $in_values_string = "";
            if (($handle = fopen('../csv_files/' . $filename, 'r')) !== FALSE) {
                fgetcsv($handle);
                $total= 0;
                $map_count=0;
                while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
                    $total++;
                    $getcommentID = $db->pselectRow("select pss.commentID from candidate c
                                          JOIN session s ON(c.candID=s.candID)
                                          JOIN flag f ON(f.sessionID=s.ID)
                                          JOIN parental_stress_scale pss ON(pss.commentID=f.commentID)
                                          where c.PSCID=:pcid and s.visit_label=:vl and f.commentID not like '%DDE%'",
                        array('pcid' => $data[0], 'vl' => $data[1]));
                    if(empty($getcommentID))
                    {
                        print "\n".$data[0] . "--->" . $data[1] . "--->" . $data[5] . "--->No relevant commentID detected on script running database)\n";
                    }
                    else {
                        $c++;
                        print "\n" . $data[0] . "--->" . $data[1] . "--->" . $data[5] . "--->" . $getcommentID['commentID'] . "\n";
                        if($confirm)
                        {
                            $db->update('parental_stress_scale',
                                array(
                                    'interviewed_by'      => $data[5]
                                ),
                                array(
                                    'commentID'          =>$getcommentID['commentID']
                                )
                            );
                            print "\nUpdated...";
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

?>