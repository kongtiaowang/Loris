<?php
/**
*
* Need to mount pinch first: gluneau@nihace:~$ ./mount_pinch.sh
*
* PHP Version 5.5.9
*
*  @category Main
*  @package  copy-dti
*  @author   Gregory Luneau <gregory.luneau@mcgill.ca>
*  @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
*  @version  GIT: <git_id>
*  @link     https://www.github.com/aces/IBIS/
**/
set_include_path(get_include_path().":../libraries:../../php/libraries:");

require_once '../../vendor/autoload.php';
require_once "NDB_Client.class.inc";
require_once "Utility.class.inc";
require_once "Candidate.class.inc";

    /**
     * Gets the ADOS module that was Administered at a particular
     * SessionID
     *
     * @param int $SessionID The Session
     *
     * @return string Test_name of ADOS module. null if not found
     */
    function getADOSModule($SessionID)
    {
        global $db;
        $rows = $db->pselect(
            "SELECT Test_name, Administration FROM flag " .
            "WHERE SessionID=:SID AND Test_name LIKE 'ados%'" .
            " AND CommentID NOT LIKE 'DDE%'",
            array('SID' => $SessionID)
        );
        foreach ($rows as $row) {
            if ($row['Administration'] === 'All') {
                return $row['Test_name'];
            }
        }

        return null;
    }

    function getADOSClasification($SessionID)
    {
        global $db;
        $ADOSModule = getADOSModule($SessionID);

        if (is_null($ADOSModule)) {
            return;
        }

//        print "ADOSModule: $ADOSModule\n";

        $Fields = array(
            'f.CommentID',
            'c.PSCID',
            's.Visit_label',
            'f.Administration', 'f.Data_entry', 'f.Validity',
            /* Special cases, do them later */
            //'Conflicts_Exist', 'DDE_Complete',
            'i.Candidate_Age',
            /* Not a field, just the value of getADOSModule,
             * but don't forget to add it in the replaceDoc
             */
            // 'ADOS Version',
            'i.social_affect_total',
            'i.restricted_repetitive_behavior_total',
            'i.social_affect_restricted_repetitive_behavior_total',
            'i.ADOS_classification',
            'i.social_affect_gotham_weighted',
            'i.restricted_repetitive_gotham_weighted',
            'i.gotham_weighted_score',
            'i.severity_score_lookup'
        );

        $selectq =  "SELECT " . join(",", $Fields) .
            " FROM flag f LEFT JOIN ". $ADOSModule ." i USING (CommentID)" .
            " LEFT JOIN session s ON (s.ID=f.SessionID)" .
            " LEFT JOIN candidate c USING (CandID) " .
            "WHERE f.Test_name=:AM AND f.SessionID=:SID AND s.Active='Y'" .
            " AND c.Active='Y' AND f.CommentID NOT LIKE 'DDE%'";

  //      print "selectq: " . $selectq . "\n";
        $row = $db->pselectRow($selectq,
            array(
                "AM"  => $ADOSModule,
                'SID' => $SessionID
            )
        );
//print_r($row);
        if ($row === array()) {
            return;
        }
//print "Returning\n";
        return $row['ADOS_classification'];
        //$PSCID=$row['PSCID'];
        //$Visit_label=$row['Visit_label'];
    }

// Main
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../config.xml');

$db = Database::singleton();

$candidates = $db->pselect("SELECT c.CandID, c.PSCID, s.Visit_label, s.ID
FROM candidate as c
JOIN session as s ON (s.CandID=c.CandID)
-- WHERE c.CandID='812952'
ORDER BY c.PSCID, s.Visit_label", array());

//WHERE ps.study_consent != 'no' AND s.CenterID!=1 AND c.Active='Y'
//AND (COALESCE(ps.study_consent_withdrawal,'0000-00-00')='0000-00-00')
//AND (s.SubprojectID=9 OR s.SubprojectID=10 OR s.SubprojectID=1 OR s.SubprojectID=2 OR s.SubprojectID=3)
//AND (m.T1_Scan_done = 'Complete' OR m.T1_Scan_done = 'Partial')

$cand = array();

foreach($candidates as $row) {
//print $row['CandID'] . "\n" ;
  $ADOSClasification = getADOSClasification($row['ID']);
//print $ADOSClasification . "\n";
  if ($ADOSClasification != '') {
  $cand[$row['CandID']] = $ADOSClasification;
}
}


foreach($cand as $cand=>$ADOSClasification) {

  if ($ADOSClasification != '') {
    print "INSERT INTO ADOS_NOV2016 (CandID,ADOS_classification) " .
          "VALUES ('" . $cand . "','" . $ADOSClasification . "');";

    print "\n";
  }
}
