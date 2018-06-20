<?php
/**
 * This Scripts Updates the Estimated Completion Time for Survey Instruments
 * Inserts the data if not found; updates the data for already existing
 *
 * @category Main
 * @package  Scripts Updates the Estimated Completion Time for Survey Instruments
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
$filename="instrument_completion_time.csv";
$confirm=false;
if (!empty($argv[1]) && $argv[1] == 'confirm') {
    $confirm = true;
}

            $in_values_string = "";
            if (($handle = fopen('../csv_files/' . $filename, 'r')) !== FALSE) {
                fgetcsv($handle);
                $total= 0;
                $map_count=0;
                $a=0;
                $b=0;
                while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
                    $total++;
                    $data_to_add=array();
                    $data_to_add['TestNameID']=$data[0];
                    $data_to_add['completion_time']=$data[2];
                    $already = $db->pselectOne("SELECT count(*) FROM instrument_completion_time
                                          where TestNameID=:tid",
                        array('tid' => $data[0]));
                    if($already==0)
                    {

                        $a++;
                        if($confirm)
                        {
                            $db->insert("instrument_completion_time", $data_to_add);
                            print "\n[".$data[0] . "][TestNameID]----[" .$data[1] . "][Instrument]----[" . $data[2] ."][Time]\n";
                            print "\nInserted...";
                        }
                        else{
                            print "\n[".$data[0] . "][TestNameID]----[" .$data[1] . "][Instrument]----[" . $data[2] ."][Time]----> TO BE ADDED!. Please confirm to add the changes\n";
                        }
                    }
                    else {
                       $b++;
                        if($confirm)
                        {
                            $db->update('instrument_completion_time',
                                array(
                                    'completion_time'      => $data[2]
                                ),
                                array(
                                    'TestNameID'          =>$data[0]
                                )
                            );
                            print "\n[".$data[0] . "][TestNameID]----[" .$data[1] . "][Instrument]----[" . $data[2] ."][Time]\n";
                            print "\nUpdated...";
                        }
                        else{
                            print "\n[".$data[0] . "][TestNameID]----[" .$data[1] . "][Instrument]----[" . $data[2] ."][Time]----> TO BE UPDATED!. Please confirm to add the changes\n";
                        }
                    }

                }
                fclose($handle);
                if($confirm)
                {
                    print "\n{$a} information ADDED out of the total {$total} found in the csv file\n";
                    print "\n{$b} information UPDATED out of the total {$total} found in the csv file\n";
                }
                else{
                    print "\n{$a} information NEEDS TO BE  ADDED out of the total {$total} found in the csv file\n";
                    print "\n{$b} information NEEDS TO BE UPDATED out of the total {$total} found in the csv file\n";
                    print "\nIf you feel good to ADD/UPDATE the data with the above information; please Run this tool again with the argument 'confirm'\n";

                }

            }

?>