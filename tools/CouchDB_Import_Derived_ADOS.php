<?php
/**
 * This script creates a "fake" (derived) ADOS instrument in the CouchDB
 * data querying tool. This derived instrument contains the scores and metadata
 * for the ADOS that was administered to the candidate, and only that ADOS.
 *
 * PHP Version 5
 *
 *  @category Loris
 *  @package  DQT
 *  @author   Dave MacFarlane <david.macfarlane2@mcgill.ca>
 *  @license  Loris license
 *  @link     https://github.com/aces/Loris-Trunk
 */
require_once 'generic_includes.php';
require_once 'CouchDB.class.inc';
require_once 'Database.class.inc';
require_once 'Utility.class.inc';
require_once 'NDB_Factory.class.inc';
/**
 * Class which implements script to derived fake ADOS instrument and update
 * all CouchDB documents that are appropriate.
 *
 *  @category Loris
 *  @package  DQT
 *  @author   Dave MacFarlane <david.macfarlane2@mcgill.ca>
 *  @license  Loris license
 *  @link     https://github.com/aces/Loris-Trunk
 */
class CouchDBADOSImporter
{
    var $SQLDB; // reference to the database handler, store here instead
    // of using Database::singleton in case it's a mock.
    var $CouchDB; // reference to the CouchDB database handler

    /**
     * Construct the object used for importing data. This initiates
     * a pointer to both the CouchDB and MySQL DB handler, which is
     * used instead of the ::singleton() methods so that the test
     * suite can mock them out for testing.
     * 
     * This is a constructor called automagically by PHP, it should not be called 
     * manually. 
     *
     * @return null
     */
    function __construct()
    {
        $factory = NDB_Factory::singleton();
        $this->SQLDB = $factory->database();
        $this->CouchDB = $factory->CouchDB();
    }

    /**
     * Update (or create) the CouchDB document for the data dictionary for
     * this derived variable.
     *
     * @return null
     */
    function updateDataDict()
    {
print "updateDataDict"; 

        $this->CouchDB->replaceDoc(
            "DataDictionary:ADOS_Derived",
            array(
                'Meta' => array(
                    'DataDict' => true
                ),
                'DataDictionary' => array(
                    'ADOS_Derived' => array(
                        'Administration' => array(
                            'Type' => "enum('None', 'Partial', 'All')",
                            'Description' => 'Administration for hello'
                        ),
                        'Data_entry' => array(
                            'Type' => "enum('In Progress', 'Complete')",
                            'Description' => 'Data entry status for hello'
                        ),
                        'Validity' => array(
                            'Type' => "enum('Questionable', 'Invalid', 'Valid')",
                            'Description' => 'Validity of data for hello'
                        ),
                        'Conflicts_Exist' => array(
                            'Type'        => "enum('Yes', 'No')",
                            'Description' => 'Conflicts exist for instrument data entry'
                        ),
                        'DDE_Complete' => array(
                            'Type'        => "enum('Yes', 'No')",
                            'Description' => 
                            'Double Data Entry was completed for instrument'
                        ),
                        'Candidate_Age' => array(
                            'Type' => 'varchar(255)',
                            'Description' => 'Age of Candidate'),
                        'ADOS_Version' => array(
                            'Type' => 
                            "enum('ados1_module1','ados1_module2','ados1_module3'"
                            . ",'ados2_module1','ados2_module2','ados2_module3')",
                            'Description' => 'Version of ADOS Administered'
                        ),
                        'social_affect_total' => array(
                            'Type' => "varchar(255)",
                            'Description' => 'Social Affect Total score'
                        ),
                        'restricted_repetitive_behavior_total' => array(
                            'Type' => "varchar(255)",
                            'Description' => 
                            'Restricted Repetitive Behaviour Total score'
                        ),
                        'social_affect_restricted_repetitive_behavior_total' => array(
                            'Type' => "varchar(255)",
                            'Description' => 
                            'Social Affect Restricted Repetitive Behaviour'
                            . ' Total score'
                        ),
                        'ADOS_classification' => array(
                            'Type' => "varchar(255)",
                            'Description' => 'ADOS Diagnosis'
                        ),
                        'social_affect_gotham_weighted' => array(
                            'Type' => "varchar(255)",
                            'Description' => 'Weighted Social Affect score'
                        ),
                        'restricted_repetitive_gotham_weighted' => array(
                            'Type' => "varchar(255)",
                            'Description' => 'Weighted Restricted Repetitive score'
                        ),
                        'gotham_weighted_score' => array(
                            'Type' => "varchar(255)",
                            'Description' => 'Weighted ADOS Score'
                        ),
                        'severity_score_lookup' => array(
                            'Type' => "varchar(255)",
                            'Description' => 'ADOS severity lookup'
                        ),
                        'ADOS_SA_CSS' => array(
                            'Type' => "varchar(255)",
                            'Description' => 'ADOS_SA_CSS'
                        ),
                        'ADOS_RRB_CSS' => array(
                            'Type' => "varchar(255)",
                            'Description' => 'ADOS_RRB_CSS'
                        )
                    )
                )
            )
        );
    }

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
        $rows = $this->SQLDB->pselect(
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

    /**
     * Update an individual session's document. This will find the
     * appropriate ADOS module that was administered, and create the
     * document containing scores from that module.
     *
     * @param int $SessionID The session to be updated
     *
     * @return null
     */
    function updateCandidate($SessionID)
    {
        $ADOSModule = $this->getADOSModule($SessionID);

	if (is_null($ADOSModule)) {
            return;
        }

print "ADOSModule: $ADOSModule\n";
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
            'i.severity_score_lookup',
            'i.a1'
        );

        $selectq =  "SELECT " . join(",", $Fields) .
            " FROM flag f LEFT JOIN ". $ADOSModule ." i USING (CommentID)" .
            " LEFT JOIN session s ON (s.ID=f.SessionID)" .
            " LEFT JOIN candidate c USING (CandID) " .
            "WHERE f.Test_name=:AM AND f.SessionID=:SID AND s.Active='Y'" .
            " AND c.Active='Y' AND f.CommentID NOT LIKE 'DDE%'";

//        print "selectq: " . $selectq . "\n";
        $row = $this->SQLDB->pselectRow($selectq,
            array(
                "AM"  => $ADOSModule,
                'SID' => $SessionID
            )
        );
        if ($row === array()) {
            return;
        }
        $PSCID=$row['PSCID'];
        $Visit_label  = $row['Visit_label'];
        $ADOS_SA_CSS  = $this->ADOS_SA_CSS( $ADOSModule, $row['a1'], $row['social_affect_total']);
        $ADOS_RRB_CSS = $this->ADOS_RRB_CSS($ADOSModule, $row['a1'], $row['restricted_repetitive_behavior_total']);

        print $this->CouchDB->replaceDoc(
            "ADOS_Derived:$PSCID" . "_" . $Visit_label,
            array(
                'Meta' => array(
                    'DocType'    => 'ADOS_Derived',
                    'identifier' => array(
                        $PSCID,$Visit_label
                    )
                ),
                'data' => array(
                    'Administration' => $row['Administration'],
                    'Data_entry'     => $row['Data_entry'],
                    'Validity'       => $row['Validity'],
                    'Candidate_Age'  => $row['Candidate_Age'],
                    'ADOS_Version'   => $ADOSModule,
                    'social_affect_total'
                       => $row['social_affect_total'],
                    'restricted_repetitive_behavior_total'
                       => $row['restricted_repetitive_behavior_total'],
                    'social_affect_restricted_repetitive_behavior_total'
                       => $row['social_affect_restricted_repetitive_behavior_total'],
                    'ADOS_classification'
                       => $row['ADOS_classification'],
                    'social_affect_gotham_weighted'
                       => $row['social_affect_gotham_weighted'],
                    'restricted_repetitive_gotham_weighted'
                       => $row['restricted_repetitive_gotham_weighted'],
                    'gotham_weighted_score'
                       => $row['gotham_weighted_score'],
                    'severity_score_lookup'
                       => $row['severity_score_lookup'],
                    'ADOS_SA_CSS'
                       => $ADOS_SA_CSS,
                    'ADOS_RRB_CSS'
                       => $ADOS_RRB_CSS
                )
            )
        );
    }

    /**
     * Get a list of sessions which must be created/updated and then updates
     * each one.
     *
     * @return null
     */
    function updateCandidateDocs()
    {
        $sessions = $this->SQLDB->pselect(
            "SELECT s.ID FROM session s JOIN candidate c USING (CandID)" .
            " WHERE c.Active='Y' AND s.Active='Y' " .
            "AND s.Visit_label in ('V24', 'V36', 'V37Plus')",
            array()
        );
        foreach ($sessions as $row) {
            $this->updateCandidate($row['ID']);
        }
    }

    /**
     * Initiate the script, called automatically if not run by
     * UnitTesting suite.
     *
     * @return null
     */
    function run()
    {
        $this->updateDataDict();
        $this->updateCandidateDocs();
    }

    function ADOS_SA_CSS($ADOS_Version, $ados_a1, $ADOS_social_affect_total)
    {
        $ADOS_mod = '';

        if ( $ADOS_Version == "ados_module1" or $ADOS_Version == "ados2_module1") {
            if ( $ados_a1 == 0 ) { $ADOS_mod = "Module1somewords"; }
            elseif ( $ados_a1 == 1 ) { $ADOS_mod = "Module1somewords"; }
            elseif ( $ados_a1 == 2 ) { $ADOS_mod = "Module1somewords"; }
            elseif ( $ados_a1 == 3 ) { $ADOS_mod = "Module1nowords"; }
            elseif ( $ados_a1 == 4 and $ADOS_Version == "ados_module1" ) { $ADOS_mod = "Module1nowords"; }
            elseif ( $ados_a1 == 8 and $ADOS_Version == "ados2_module1" ) { $ADOS_mod = "Module1nowords"; }
        }

        if ( $ADOS_Version == "ados_module2" ) { $ADOS_mod = "Module2"; }
        elseif ( $ADOS_Version == "ados2_module2" ) { $ADOS_mod = "Module2"; }
        elseif ( $ADOS_Version == "." ) { $ADOS_mod = "."; }

        $ADOS_SA_CSS = '';

        if ( $ADOS_mod == "Module1nowords" and in_array($ADOS_social_affect_total, range(0, 3)) ) { $ADOS_SA_CSS = 1; }
        elseif ( $ADOS_mod == "Module1nowords" and in_array($ADOS_social_affect_total, range(4, 5)) ) { $ADOS_SA_CSS = 2; }
        elseif ( $ADOS_mod == "Module1nowords" and in_array($ADOS_social_affect_total, range(6, 8)) ) { $ADOS_SA_CSS = 3; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_social_affect_total == 9 ) { $ADOS_SA_CSS = 4; }
        elseif ( $ADOS_mod == "Module1nowords" and in_array($ADOS_social_affect_total, range(10, 13)) ) { $ADOS_SA_CSS = 5; }
        elseif ( $ADOS_mod == "Module1nowords" and in_array($ADOS_social_affect_total, range(14, 16)) ) { $ADOS_SA_CSS = 6; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_social_affect_total == 17 ) { $ADOS_SA_CSS = 7; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_social_affect_total == 18 ) { $ADOS_SA_CSS = 8; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_social_affect_total == 19 ) { $ADOS_SA_CSS = 9; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_social_affect_total == 20 ) { $ADOS_SA_CSS = 10; }

        if ( $ADOS_mod == "Module1somewords" and in_array($ADOS_social_affect_total, range(0, 1)) ) { $ADOS_SA_CSS = 1; }
        elseif ( $ADOS_mod == "Module1somewords" and in_array($ADOS_social_affect_total, range(2, 4)) ) { $ADOS_SA_CSS = 2; }
        elseif ( $ADOS_mod == "Module1somewords" and $ADOS_social_affect_total == 5 ) { $ADOS_SA_CSS = 3; }
        elseif ( $ADOS_mod == "Module1somewords" and in_array($ADOS_social_affect_total, range(6, 7)) ) { $ADOS_SA_CSS = 4; }
        elseif ( $ADOS_mod == "Module1somewords" and $ADOS_social_affect_total == 8 ) { $ADOS_SA_CSS = 5; }
        elseif ( $ADOS_mod == "Module1somewords" and in_array($ADOS_social_affect_total, range(9, 11)) ) { $ADOS_SA_CSS = 6; }
        elseif ( $ADOS_mod == "Module1somewords" and in_array($ADOS_social_affect_total, range(12, 13)) ) { $ADOS_SA_CSS = 7; }
        elseif ( $ADOS_mod == "Module1somewords" and in_array($ADOS_social_affect_total, range(14, 15)) ) { $ADOS_SA_CSS = 8; }
        elseif ( $ADOS_mod == "Module1somewords" and in_array($ADOS_social_affect_total, range(16, 17)) ) { $ADOS_SA_CSS = 9; }
        elseif ( $ADOS_mod == "Module1somewords" and in_array($ADOS_social_affect_total, range(18, 20)) ) { $ADOS_SA_CSS = 10; }

        if ( $ADOS_mod == "Module2" and in_array($ADOS_social_affect_total, range(0, 1)) ) { $ADOS_SA_CSS = 1; }
        elseif ( $ADOS_mod == "Module2" and in_array($ADOS_social_affect_total, range(2, 3)) ) { $ADOS_SA_CSS = 2; }
        elseif ( $ADOS_mod == "Module2" and $ADOS_social_affect_total == 4 ) { $ADOS_SA_CSS = 3; }
        elseif ( $ADOS_mod == "Module2" and $ADOS_social_affect_total == 5 ) { $ADOS_SA_CSS = 4; }
        elseif ( $ADOS_mod == "Module2" and $ADOS_social_affect_total == 6 ) { $ADOS_SA_CSS = 5; }
        elseif ( $ADOS_mod == "Module2" and in_array($ADOS_social_affect_total, range(7, 8)) ) { $ADOS_SA_CSS = 6; }
        elseif ( $ADOS_mod == "Module2" and in_array($ADOS_social_affect_total, range(9, 10)) ) { $ADOS_SA_CSS = 7; }
        elseif ( $ADOS_mod == "Module2" and $ADOS_social_affect_total == 11 ) { $ADOS_SA_CSS = 8; }
        elseif ( $ADOS_mod == "Module2" and in_array($ADOS_social_affect_total, range(12, 14)) ) { $ADOS_SA_CSS = 9; }
        elseif ( $ADOS_mod == "Module2" and in_array($ADOS_social_affect_total, range(15, 20)) ) { $ADOS_SA_CSS = 10; }

        return ($ADOS_SA_CSS);
    }

    function ADOS_RRB_CSS($ADOS_Version, $ados_a1, $ADOS_RRB_total)
    {
        $ADOS_mod = '';

        if ( $ADOS_Version == "ados_module1" or $ADOS_Version == "ados2_module1") {
            if ( $ados_a1 == 0 ) { $ADOS_mod = "Module1somewords"; }
            elseif ( $ados_a1 == 1 ) { $ADOS_mod = "Module1somewords"; }
            elseif ( $ados_a1 == 2 ) { $ADOS_mod = "Module1somewords"; }
            elseif ( $ados_a1 == 3 ) { $ADOS_mod = "Module1nowords"; }
            elseif ( $ados_a1 == 4 and $ADOS_Version == "ados_module1" ) { $ADOS_mod = "Module1nowords"; }
            elseif ( $ados_a1 == 8 and $ADOS_Version == "ados2_module1" ) { $ADOS_mod = "Module1nowords"; }
        }

        if ( $ADOS_Version == "ados_module2" ) { $ADOS_mod = "Module2"; }
        elseif ( $ADOS_Version == "ados2_module2" ) { $ADOS_mod = "Module2"; }
        elseif ( $ADOS_Version == "." ) { $ADOS_mod = "."; }

        $ADOS_RRB_CSS = '';

        if ( $ADOS_mod == "Module1nowords" and $ADOS_RRB_total == 0 ) { $ADOS_RRB_CSS = 1; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_RRB_total == 1 ) { $ADOS_RRB_CSS = 5; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_RRB_total == 2 ) { $ADOS_RRB_CSS = 6; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_RRB_total == 3 ) { $ADOS_RRB_CSS = 7; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_RRB_total == 4 ) { $ADOS_RRB_CSS = 8; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_RRB_total == 5 ) { $ADOS_RRB_CSS = 9; }
        elseif ( $ADOS_mod == "Module1nowords" and in_array($ADOS_RRB_total, range(6, 8)) ) { $ADOS_RRB_CSS = 10; }

        if ( $ADOS_mod == "Module1somewords" and $ADOS_RRB_total == 0 ) { $ADOS_RRB_CSS = 1; }
        elseif ( $ADOS_mod == "Module1somewords" and $ADOS_RRB_total == 1 ) { $ADOS_RRB_CSS = 5; }
        elseif ( $ADOS_mod == "Module1somewords" and $ADOS_RRB_total == 2 ) { $ADOS_RRB_CSS = 6; }
        elseif ( $ADOS_mod == "Module1somewords" and $ADOS_RRB_total == 3 ) { $ADOS_RRB_CSS = 7; }
        elseif ( $ADOS_mod == "Module1somewords" and $ADOS_RRB_total == 4 ) { $ADOS_RRB_CSS = 8; }
        elseif ( $ADOS_mod == "Module1somewords" and $ADOS_RRB_total == 5 ) { $ADOS_RRB_CSS = 9; }
        elseif ( $ADOS_mod == "Module1somewords" and in_array($ADOS_RRB_total, range(6, 8)) ) { $ADOS_RRB_CSS = 10; }

        if ( $ADOS_mod == "Module2" and $ADOS_RRB_total == 0 ) { $ADOS_RRB_CSS = 1; }
        elseif ( $ADOS_mod == "Module2" and $ADOS_RRB_total == 1 ) { $ADOS_RRB_CSS = 5; }
        elseif ( $ADOS_mod == "Module2" and $ADOS_RRB_total == 2 ) { $ADOS_RRB_CSS = 6; }
        elseif ( $ADOS_mod == "Module2" and $ADOS_RRB_total == 3 ) { $ADOS_RRB_CSS = 7; }
        elseif ( $ADOS_mod == "Module2" and $ADOS_RRB_total == 4 ) { $ADOS_RRB_CSS = 8; }
        elseif ( $ADOS_mod == "Module2" and in_array($ADOS_RRB_total, range(5, 6)) ) { $ADOS_RRB_CSS = 9; }
        elseif ( $ADOS_mod == "Module2" and in_array($ADOS_RRB_total, range(7, 8)) ) { $ADOS_RRB_CSS = 10; }

        return($ADOS_RRB_CSS);
    }

}
// Don't run if we're doing the unit tests, the unit test will call run..
if (!class_exists('UnitTestCase')) {
    $Runner = new CouchDBADOSImporter();
    $Runner->run();
}
?>
