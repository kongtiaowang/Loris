<?php
require_once __DIR__ . "/../../vendor/autoload.php";
require_once 'generic_includes.php';
require_once 'CouchDB.class.inc';
require_once 'Database.class.inc';
require_once 'Utility.class.inc';

/**
 * DQT import script to import Language Common Variables across instruments.
 */
class CouchDBDerivedLanguageImporter
{
    var $SQLDB; // reference to the database handler, store here instead
    // of using Database::singleton in case it's a mock.
    var $CouchDB; // reference to the CouchDB database handler

    function __construct()
    {
        $factory       = \NDB_Factory::singleton();
        $config        = \NDB_Config::singleton();
        $couchConfig   = $config->getSetting('CouchDB');
        $this->SQLDB   = $factory->Database();
        $this->CouchDB = $factory->couchDB(
            $couchConfig['dbClean'],
            $couchConfig['hostname'],
            intval($couchConfig['port']),
            $couchConfig['admin'],
            $couchConfig['adminpass']
        );
    }

    /**
     * Update the data dictionary for the Derived Language Common Variable DQT instrument.
     */
    function UpdateDataDict() {
        $dictionary = array(
            'receptive_language_age_equivalent' => array (
                'Description' => 'Mullen: Receptive Language - Age Equivalent',
                'Type'        => 'varchar(255)'
            ),
            'receptive_language_t' => array(
                'Description' => 'Mullen: Receptive Language - T Score',
                'Type'        => 'varchar(255)'
            ),
            'expressive_language_age_equivalent' => array(
                'Description' => 'Mullen: Expressive Language - Age Equivalent',
                'Type'        => 'varchar(255)'
            ),
            'expressive_language_t' => array(
                'Description' => 'Mullen: Expressive Language - T Score',
                'Type'        => 'varchar(255)'
            ),
            'total_gestures_number' => array(
                'Description' => 'MacArthur-Bates CDI-LF: Number of total gestures',
                'Type'        => 'varchar(255)'
            ),
            'early_gestures_number' => array(
                'Description' => 'MacArthur-Bates CDI-LF: Number of early gestures',
                'Type'        => 'varchar(255)'
            ),
            'later_gestures_number' => array(
                'Description' => 'MacArthur-Bates CDI-LF: Number of later gestures',
                'Type'        => 'varchar(255)'
            ),
            'phrases_understood_number' => array(
                'Description' => 'MacArthur-Bates CDI-LF: Number of phrases understood',
                'Type'        => 'varchar(255)'
            ),
            'words_produced_number' => array(
                'Description' => 'MacArthur-Bates CDI-LF: Number of words produced',
                'Type'        => 'varchar(255)'
            ),
            'words_understood_number' => array(
                'Description' => 'MacArthur-Bates CDI-LF: Number of words understood',
                'Type'        => 'varchar(255)'
            ),
            'COM_STD_SCORE' => array(
                'Description' => 'Vineland - Subject: Communication (Domain): Standard Score',
                'Type'        => 'varchar(255)'
            ),
            'Verbal_Developmental_Quotient' => array(
                'Description' => 'Mullen: Verbal Developmental Quotient',
                'Type'        => 'varchar(255)'
            )
        );

        $this->CouchDB->replaceDoc('DataDictionary:Language_Common_Variables',
            array('Meta' => array('DataDict' => true),
                'DataDictionary' => array('Language_Common_Variables' => $dictionary)
            )
        );
    }

    /**
     * Get the candidates' variables across instruments and update the DQT with data.
     */
    function UpdateCandidateDocs()
    {
        // Query for the all candidates PSCID, Visit and tuples of the commentID and test name for
        // all sessions which have an instrument with language variables administered.
        $candidateVisits = $this->SQLDB->pselect("
            SELECT c.PSCID,
                   s.Visit_label,
                   GROUP_CONCAT(f.CommentID, '/', f.Test_name) as instruments
            FROM candidate c
                JOIN session s ON (c.CandID = s.CandID)
                JOIN flag f ON (s.ID = f.SessionID)
                LEFT JOIN participant_status ps ON ( ps.candid = c.candid )
            WHERE f.Test_name IN ('mullen', 'macarthur_words_gestures', 'vineland_subject')
                AND f.Data_entry = 'Complete'
                AND f.Administration = 'All'
                AND f.Validity <> 'Invalid'
                AND f.CommentID NOT LIKE 'DDE_%'
                AND s.Active='Y' AND c.Active='Y'
                AND s.Current_stage NOT IN ('Recycling Bin')
                AND c.RegistrationCenterID NOT IN (1,8,9,10)
                AND c.RegistrationProjectID NOT IN (5,6)
                AND (ps.participant_status NOT IN (2,3,4,15) OR ps.participant_status IS NULL)
            GROUP BY s.ID
        ", array());

        foreach ($candidateVisits as $visit) {
            // Default the common language variables to null.
            $common_variables = array(
                'receptive_language_age_equivalent' => null,
                'receptive_language_t' => null,
                'expressive_language_age_equivalent' => null,
                'expressive_language_t' => null,
                'total_gestures_number' => null,
                'early_gestures_number' => null,
                'later_gestures_number' => null,
                'phrases_understood_number' => null,
                'words_produced_number' => null,
                'words_understood_number' => null,
                'COM_STD_SCORE' => null,
                'Verbal_Developmental_Quotient' => null
            );
            $id = "Language_Common_Variables_" . $visit['PSCID'] . "_" . $visit['Visit_label'];

            // Get the instruments administered at the visit.
            $visit_instruments = explode(",", $visit['instruments']);
            foreach ($visit_instruments as $instrument) {
                $info       = explode("/", $instrument);
                $commentID  = $info[0];
                $instrument = $info[1];
                switch ($instrument) {
                    case 'mullen':
                        $this->getMullen($commentID, $common_variables);
                        break;
                    case 'macarthur_words_gestures':
                        $this->getMacArthur($commentID, $common_variables);
                        break;
                    case 'vineland_subject':
                        $this->getVineland($commentID, $common_variables);
                        break;
                }
            }

            $success = $this->CouchDB->replaceDoc($id, array('Meta' => array(
                'DocType' => 'Language_Common_Variables',
                'identifier' => array($visit['PSCID'], $visit['Visit_label'])
            ),
                'data' => $common_variables
            ));

            print "$id: $success\n";
        }
    }

    /**
     * Get the language variables from the Mullen instrument.
     *
     * @param string $commentID        the commentID of the instrument administer to candidate
     * @param array  $common_variables pointer to the array of common variables
     */
    function getMullen($commentID, &$common_variables) {
        $result = $this->SQLDB->pselectRow("
            SELECT receptive_language_age_equivalent,
                   expressive_language_age_equivalent,
                   expressive_language_t,
                   receptive_language_t,
                   Candidate_Age
            FROM mullen
            WHERE CommentID = :commentID
            AND EXISTS (
                 SELECT 'x'
                 FROM flag f
                 WHERE f.CommentID = CONCAT('DDE_', mullen.CommentID)
            ) AND NOT EXISTS (
                 SELECT 'x'
                 FROM conflicts_unresolved cu
                 WHERE mullen.CommentID=cu.CommentId1 OR mullen.CommentID=cu.CommentId2
            )
        ", array("commentID" => $commentID));

        $common_variables['receptive_language_age_equivalent']  = $result['receptive_language_age_equivalent'];
        $common_variables['receptive_language_t']               = $result['receptive_language_t'];
        $common_variables['expressive_language_age_equivalent'] = $result['expressive_language_age_equivalent'];
        $common_variables['expressive_language_t']              = $result['expressive_language_t'];

        // Mullen has an unofficial score variable which IBIS clinicians would like to query.
        if (!(
            is_null($result['receptive_language_age_equivalent'])
            || is_null($result['expressive_language_age_equivalent'])
            || is_null($result['Candidate_Age'])
        )) {
            $receptive  = (float) $result['receptive_language_age_equivalent'];
            $expressive = (float) $result['expressive_language_age_equivalent'];
            $age        = (float) $result['Candidate_Age'];
            // ((receptive_language_age_equivalent + $expressive_language_age_equivalent) /2) / age of administration in Mullen) *100)
            $common_variables['Verbal_Developmental_Quotient'] = round(50 * ($receptive + $expressive) / $age, 2);
        }
    }

    /**
     * Get the language variables from the MacArthur-Bates CDI-LF instrument.
     *
     * @param string $commentID        the commentID of the instrument administer to candidate
     * @param array  $common_variables pointer to the array of common variables
     */
    function getMacArthur($commentID, &$common_variables) {
        $result = $this->SQLDB->pselectRow("
            SELECT total_gestures_number,
                   early_gestures_number,
                   later_gestures_number,
                   phrases_understood_number,
                   words_produced_number,
                   words_understood_number
            FROM macarthur_words_gestures
            WHERE CommentID = :commentID
            AND EXISTS (
                 SELECT 'x'
                 FROM flag f
                 WHERE f.CommentID = CONCAT('DDE_', macarthur_words_gestures.CommentID)
            ) AND NOT EXISTS (
                 SELECT 'x'
                 FROM conflicts_unresolved cu
                 WHERE macarthur_words_gestures.CommentID=cu.CommentId1 OR macarthur_words_gestures.CommentID=cu.CommentId2
            )
        ", array("commentID" => $commentID));

        $common_variables['total_gestures_number']     = $result['total_gestures_number'];
        $common_variables['early_gestures_number']     = $result['early_gestures_number'];
        $common_variables['later_gestures_number']     = $result['later_gestures_number'];
        $common_variables['phrases_understood_number'] = $result['phrases_understood_number'];
        $common_variables['words_produced_number']     = $result['words_produced_number'];
        $common_variables['words_understood_number']   = $result['words_understood_number'];
    }

    /**
     * Get the language variables from the Vineland instrument.
     *
     * @param string $commentID        the commentID of the instrument administer to candidate
     * @param array  $common_variables pointer to the array of common variables
     */
    function getVineland($commentID, &$common_variables) {
        $result = $this->SQLDB->pselectRow("
            SELECT COM_STD_SCORE
            FROM vineland_subject
            WHERE CommentID = :commentID
        ", array("commentID" => $commentID));

        $common_variables['COM_STD_SCORE'] = $result['COM_STD_SCORE'];
    }

    function run()
    {
        $this->UpdateDataDict();
        $this->UpdateCandidateDocs();
    }
}

// Don't run if we're doing the unit tests; the unit test will call run.
if(!class_exists('UnitTestCase')) {
    $Runner = new CouchDBDerivedLanguageImporter();
    $Runner->run();
}
