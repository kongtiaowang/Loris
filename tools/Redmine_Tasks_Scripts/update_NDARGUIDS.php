<?php
/**
 * Update NDARGUIDS in bulk from the csv file that the site/Leigh/Meaghan gave
 * This script is used when we need to update/add a lot of NDARGUIDs which site coordinators missed to add it from the frontend.
 *
 * @category Main
 * @package  update/add missed NDARGUIDs from csv file to backend
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
$filename="update_NDARGUIDS.csv";
$confirm=false;
if (!empty($argv[1]) && $argv[1] == 'confirm') {
    $confirm = true;
}

            $in_values_string = "";
            if (($handle = fopen('../csv_files/' . $filename, 'r')) !== FALSE) {
                fgetcsv($handle);
                $total= 0;
                $i=0;
                $u=0;
                while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
                    $total++;
                    $ptid=$db->pselectRow("select pt.ParameterTypeID from parameter_type pt
                                          where pt.Name='CandidateGUID'",
                        array());
                    $cid= $db->pselectRow("select c.CandID from candidate c
                                          where c.PSCID=:pcid",
                        array('pcid' => $data[0]));
                    $getInfo =$db->pselectRow("select c.CandID, pt.ParameterTypeID from candidate c
                                          JOIN parameter_candidate pc ON(c.candID=pc.candID)
                                          JOIN parameter_type pt ON (pt.ParameterTypeID=pc.ParameterTypeID)
                                          where c.PSCID=:pid and pt.Name='CandidateGUID'",
                        array('pid' => $data[0]));
                    $updateValues = [
                        'ParameterTypeID' => $ptid['ParameterTypeID'],
                        'CandID'          => $cid['CandID'],
                        'Value'           => $data[1],
                        'InsertTime'      => time(),
                    ];
                    if(empty($getInfo))
                    {
                        $i++;
                        print "\n".$data[0] . "--->" . $cid['CandID'] . "--->" . $data[1]." (PTID:".$ptid['ParameterTypeID'].")--->Needs To Be Inserted\n";
                        if($confirm)
                        {
                            $db->insert('parameter_candidate', $updateValues);
                            print "\nInserted...";
                        }
                    }
                    else {
                        $u++;
                        print "\n".$data[0] . "--->" . $cid['CandID'] . "--->" . $data[1] ." (PTID:".$ptid['ParameterTypeID'].")---->Needs To Be Updated\n";
                        if($confirm)
                        {
                            $db->update(
                                'parameter_candidate',
                                $updateValues,
                                [
                                    'CandID'          => $cid['CandID'],
                                    'ParameterTypeID' => $ptid['ParameterTypeID'],
                                ]
                            );
                            print "\nUpdated...";
                        }
                    }

                }
                fclose($handle);
                if($confirm)
                {
                    print "\n{$i} information inserted out of the total {$total} found in the csv file\n";
                    print "\n{$u} information updated out of the total {$total} found in the csv file\n";
                }
                else{
                    print"\n{$i} NDAR CandidateGUID Entries found ready to insert with the right information out of the total {$total} found in the csv file\n";
                    print"\n{$u} NDAR CandidateGUID Entries found ready to update with the right information out of the total {$total} found in the csv file\n";
                    print "\nIf you feel good to update the data with the above information; please Run this tool again with the argument 'confirm'\n";

                }

            }

?>