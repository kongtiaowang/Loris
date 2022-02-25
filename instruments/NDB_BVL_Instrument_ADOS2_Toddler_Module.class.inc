<?php

/**
 * This file contains the NDB_BVL_Instrument_ADOS2_Toddler_Module
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the ADOS-2 Toddler Module
 * instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

class NDB_BVL_Instrument_ADOS2_Toddler_Module extends NDB_BVL_Instrument_IBIS
{
    var $option01238  = array("" => null, 0 => 0, 1 => 1, 2 => 2, 3 => 3, 8 => 8, "not_answered" => "Not Answered");
    var $option01234  = array("" => null, 0 => 0, 1 => 1, 2 => 2, 3 => 3, 4 => 4, "not_answered" => "Not Answered");
    var $option0128   = array("" => null, 0 => 0, 1 => 1, 2 => 2, 8 => 8, "not_answered" => "Not Answered");
    var $option0123   = array("" => null, 0 => 0, 1 => 1, 2 => 2, 3 => 3, "not_answered" => "Not Answered");
    var $option02     = array("" => null, 0 => 0, 2 => 2, "not_answered" => "Not Answered");
    var $option012    = array("" => null, 0 => 0, 1 => 1, 2 => 2, "not_answered" => "Not Answered");
    var $option0127   = array("" => null, 0 => 0, 1 => 1, 2 => 2, 7 => 7, "not_answered" => "Not Answered");
    var $option01237  = array("" => null, 0 => 0, 1 => 1, 2 => 2, 3 => 3, 7 => 7, "not_answered" => "Not Answered");
    var $option012378 = array("" => null, 0 => 0, 1 => 1, 2 => 2, 3 => 3, 7 => 7, 8 => 8, "not_answered" => "Not Answered");
    var $scoreCols    = array("social_affect_total", "restricted_repetitive_behavior_total",
        "social_affect_restricted_repetitive_behavior_total", "ADOS_classification", 'a2_weighted', 'a3_weighted',
        'a7_weighted', 'a8_weighted', 'b1_weighted', 'b4_weighted', 'b5_weighted', 'b6_weighted', 'b7_weighted',
        'b8_weighted', 'b9_weighted', 'b12_weighted', 'b13_weighted', 'b14_weighted', 'b15_weighted', 'b16b_weighted',
        'b18_weighted', 'd1_weighted', 'd2_weighted', 'd5_weighted', 'severity_score_lookup', 'toddler_module'
    );
    /**
     * Array of column names to be ignored by the double data entry conflict detector.
     */
    /**
     * sets up basic data, such as the LorisForm object, and so on.
     *
     * @param  string $commentID the CommentID identifying the data to load
     * @param  string $page      if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = null, ?string $page = null): void
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('ADOS2_Toddler_Module');
        $this->page     = $page; // page label (number or
        // string - used by
        // user-defined child classes)
        // set the object properties
        $this->testName = "ADOS2_Toddler_Module"; // test_names.Test_name
        $this->table    = 'ADOS2_Toddler_Module'; // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;
        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array("Date_taken");
        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->selectMultipleElements = array();
        // required fields for data entry completion status
        $this->_requiredElements = array('Examiner', 'a1', 'c1');
        $this->_doubleDataEntryDiffIgnoreColumns = array(
            'CommentID', 'UserID', 'Testdate', 'Window_Difference', 'Candidate_Age', 'Data_entry_completion_status',
            'social_affect_total', 'restricted_repetitive_behavior_total', 'social_affect_restricted_repetitive_behavior_total',
            'ADOS_classification', 'd1_specify', 'd2_specify', 'd3_specify', 'd4_specify', 'd5_specify', 'a2_weighted',
            'a3_weighted', 'a7_weighted', 'a8_weighted', 'b1_weighted', 'b4_weighted', 'b5_weighted', 'b6_weighted',
            'b7_weighted', 'b8_weighted', 'b9_weighted', 'b12_weighted', 'b13_weighted', 'b14_weighted', 'b15_weighted',
            'b16b_weighted', 'b18_weighted', 'd1_weighted', 'd2_weighted', 'd5_weighted', 'severity_score_lookup'
        );
        // setup the form
        $this->_setupForm();
    }

    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

    /**
     * method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        if (preg_match("/ADOS2_Toddler_Module(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    /**
     * generates the main page of the form.
     *
     * @return void
     * @access private
     */
    function _main()
    {
        $this->form->addElement('header', 'instrument_title', "ADOS-2 Toddler Module");
        $this->_addMetadataFields();
        $this->form->addElement("header", null, "SUMMARY SCORES:");
        $this->form->addElement('static', 'toddler_module', 'Toddler Module:');
        $this->form->addElement('static', "social_affect_total", "Social Affect Total:");
        $this->form->addElement('static', "restricted_repetitive_behavior_total", "Restricted and Repetitive Behavior Total:");
        $this->form->addElement('static', "social_affect_restricted_repetitive_behavior_total", "Social Affect and Restricted and Repetitive Behavior Total:");
        $this->form->addElement('static', "ADOS_SA_CSS", "ADOS_SA_CSS:");
        $this->form->addElement('static', "ADOS_RRB_CSS", "ADOS_RRB_CSS:");
        $this->form->addElement('static', "ADOS_classification", "ADOS Classification:");
        $this->form->addElement('header', null, 'Severity Scores:');
        $this->form->addElement('static', 'severity_score_lookup', 'Severity Score:');
    }

    /**
     * Page 1
     */
    function _page1()
    {
        //CODING
        //Section A: Language and Communication
        $this->form->addElement('header', null, "CODING:");

        $this->form->addElement('header', null, "Section A: Language and Communication");
        $this->form->addElement('select', 'a1', '1. Overall Level of Non-Echoed Spoken Language', $this->option01234);
        $this->form->addElement('select', 'a1a', '1a. Frequency of Babbling', $this->option01238);
        $this->form->addElement('select', 'a2', '2. Frequency of Spontaneous Vocalization Directed to Others', $this->option0123);
        $this->form->addElement('select', 'a3', '3. Intonation of Vocalizations or Verbalization', $this->option01238);
        $this->form->addElement('select', 'a4', '4. Immediate Echolalia', $this->option01238);
        $this->form->addElement('select', 'a5', '5. Stereotyped/Idiosyncratic Use of Words or Phrases', $this->option01238);
        $this->form->addElement('select', 'a6', '6. Use of Another\'s Body', $this->option01238);
        $this->form->addElement('select', 'a7', '7. Pointing', $this->option0123);
        $this->form->addElement('select', 'a8', '8. Gestures', $this->option01238);
        $this->form->addElement('select', 'a9', '9. Frequency of Undirected Vocalization', $this->option01238);

        //Section B: Reciprocal Social Interaction
        $this->form->addElement('header', null, "Section B: Reciprocal Social Interaction");
        $this->form->addElement('select', 'b1', '1. Unusual Eye Contact', $this->option0123);
        $this->form->addElement('select', 'b2', '2. Teasing Toy Play', $this->option01238);
        $this->form->addElement('select', 'b3', '3. Unable Toy Play', $this->option01238);
        $this->form->addElement('select', 'b4', '4. Facial Expressions Directed to Others', $this->option0123);
        $this->form->addElement('select', 'b5', '5. Integration of Gaze and Other Behaviors During Social Overtures', $this->option0123);
        $this->form->addElement('select', 'b6', '6. Shared Enjoyment in Interaction', $this->option0123);
        $this->form->addElement('select', 'b7', '7. Response to Name', $this->option0123);
        $this->form->addElement('select', 'b8', '8. Ignore', $this->option0123);
        $this->form->addElement('select', 'b9', '9. Requesting', $this->option0123);
        $this->form->addElement('select', 'b10', '10. Amount of Requesting', $this->option0123);
        $this->form->addElement('select', 'b11', '11. Giving', $this->option0123);
        $this->form->addElement('select', 'b12', '12. Showing', $this->option0123);
        $this->form->addElement('select', 'b13', '13. Spontaneous Initiation of Joint Attention', $this->option0123);
        $this->form->addElement('select', 'b14', '14. Response to Joint Attention', $this->option0123);
        $this->form->addElement('select', 'b15', '15. Quality of Social Overtures', $this->option0123);
        $this->form->addElement('select', 'b16a', '16a. Amount of Social Overtures/Maintenance of Attention: EXAMINER', $this->option01237);
        $this->form->addElement('select', 'b16b', '16b. Amount of Social Overtures/Maintenance of Attention: PARENT/CAREGIVER', $this->option012378);
        $this->form->addElement('select', 'b17', '17. Level of Engagement', $this->option0123);
        $this->form->addElement('select', 'b18', '18. Overall Quality of Rapport', $this->option0123);
    }

    /**
     * Page 2
     */
    function _page2()
    {
        //Section C: Play
        $this->form->addElement('header', null, "Section C: Play");
        $this->form->addElement('select', 'c1', '1. Functional Play with Objects', $this->option0123);
        $this->form->addElement('select', 'c2', '2. Imagination/Creativity', $this->option0123);
        $this->form->addElement('select', 'c3', '3. Functional and Symbolic Imitation', $this->option0123);

        //Section D: Stereotyped Behaviors and Restricted Interests
        $this->form->addElement('header', null, "Section D: Stereotyped Behaviors and Restricted Interests");
        $this->form->addElement('select', 'd1', '1. Unusual Sensory Interest in Play Material/Person', $this->option0123);
         $this->addTextAreaElement('d1_specify', $this->indent . "Please specify:");
        $this->form->addElement('select', 'd2', '2. Hand and Finger and Other Complex Mannerisms', $this->option0123);
        $this->addTextAreaElement('d2_specify', $this->indent . "Please specify:");
        $this->form->addElement('select', 'd3', '3. Other Complex Mannerisms', $this->option0123);
        $this->addTextAreaElement('d3_specify', $this->indent . "Please specify:");
        $this->form->addElement('select', 'd4', '4. Self-Injurious Behavior', $this->option0123);
        $this->addTextAreaElement('d4_specify', $this->indent . "Please specify:");
        $this->form->addElement('select', 'd5', '5. Unusually Repetitive Interests or Stereotyped Behaviors', $this->option0123);
        $this->addTextAreaElement('d5_specify', $this->indent . "Please specify:");

        //Section E: Other Behaviors
        $this->form->addElement('header', null, "Section E: Other Abnormal Behaviors");
        $this->form->addElement('select', 'e1', '1. Overactivity', $this->option01237);
        $this->form->addElement('select', 'e2', '2. Fussiness/Irritability', $this->option0123);
        $this->form->addElement('select', 'e3', '3. Aggression and Disruptive Behavior', $this->option0123);
        $this->form->addElement('select', 'e4', '4. Anxiety', $this->option0123);
    } // End Form

    /**
     * Scoring
     */
    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        // null scores
        $this->_nullScores($this->scoreCols);

        //get the saved scores
        $db =& Database::singleton();

        $record = $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid", array("cid" =>$this->getCommentID() ));

        $scoreCols = array();

        $age_months = -1;

        if ($this->getSessionID() != null) { // quickform_parser doesn't use any specific session
            $timepoint =& TimePoint::singleton($this->getSessionID());
            $dob       = $timepoint->getEffectiveDateOfBirth();
        }

        if (!empty($dob) && !empty($record['Date_taken'])) {
            $age = Utility::calculateAge($dob, $record["Date_taken"]);
            if (is_array($age)) {
                $age_months = $age['year'] * 12 + $age['mon'];
            }
        }

        /** TODDLER MODULE ALGORITHMS **/

        /** ALL YOUNGER / OLDER WITH FEW TO NO WORDS **/
        // Chronological age is between 12 and 20 months
        // OR
        // Chronological age is between 21 and 30 months
        // AND
        // Assigned rating of 3 or 4 on Item A1

        /** OLDER WITH SOME WORDS **/
        // Chronological age is between 21 and 30 months
        // AND
        // Assigned rating of 0, 1, or 2 on Item A1

        $module = "";

        if ($age_months >= 12 && $age_months <= 20) {
            $module = "1-NoWords";
            $scoreCols["toddler_module"] = "All Younger/Older with Few to No Words";
        } else if ($age_months >= 21 && $age_months <= 30) {
            if ($record["a1"] == 3 || $record["a1"] == 4) {
                $module = "1-NoWords";
                $scoreCols["toddler_module"] = "All Younger/Older with Few to No Words";
            }
            if ($record["a1"] == 0 || $record["a1"] == 1 || $record["a1"] == 2) {
                $module = "1-Words";
                $scoreCols["toddler_module"] = "Older with Some Words";
            }
        } else {
            $scoreCols["toddler_module"] = "Age Out of Range";
        }

        $converted_scores = array(
            "a2" => "",
            "a3" => "",
            "a7" => "",
            "a8" => "",
            "b1" => "",
            "b4" => "",
            "b5" => "",
            "b6" => "",
            "b7" => "",
            "b8" => "",
            "b9" => "",
            "b12" => "",
            "b13" => "",
            "b14" => "",
            "b15" => "",
            "b16b" => "",
            "b18" => "",
            "d1" => "",
            "d2" => "",
            "d5" => "",
        );

        /** CONVERTING ITEM CODES TO ALGORITHM SCORES **/
        // Convert assigned ratings as follows:
        // 0 --> 0
        // 1 --> 1
        // 2 --> 2
        // 3 --> 2
        // 4 and up --> 0
        // N/A --> 0

        // Exception: Item B1
        // Convert assigned rating as follows:
        // 0 --> 0
        // 1 --> 2
        // 2 --> 2
        // 3 --> 2
        foreach ($converted_scores as $field => $value) {
            if ($field == "b1") {
                if ($record["b1"] == 0) {
                    $converted_scores["b1"] = 0;
                } else {
                    $converted_scores["b1"] = 2;
                }
            } else {
                if ($record[$field] == 0 || $record[$field] >= 4 || $record[$field] == "not_answered") {
                    $converted_scores[$field] = 0;
                } else if ($record[$field] == 1) {
                    $converted_scores[$field] = 1;
                } else if ($record[$field] == 2 || $record[$field] == 3) {
                    $converted_scores[$field] = 2;
                }
            }
        }

        /** ALL YOUNGER / OLDER WITH FEW TO NO WORDS **/
        if ($module == "1-NoWords") {
            // SA Total
            $scoreCols["social_affect_total"] =
                $converted_scores["a2"] +
                $converted_scores["a8"] +
                $converted_scores["b1"] +
                $converted_scores["b4"] +
                $converted_scores["b5"] +
                $converted_scores["b6"] +
                $converted_scores["b12"] +
                $converted_scores["b13"] +
                $converted_scores["b14"] +
                $converted_scores["b15"];

            // RRB Total
            $scoreCols["restricted_repetitive_behavior_total"] =
                $converted_scores["a3"] +
                $converted_scores["d1"] +
                $converted_scores["d2"] +
                $converted_scores["d5"];

            $total_score =
                $scoreCols["social_affect_total"] +
                $scoreCols["restricted_repetitive_behavior_total"];

            // ADOS-2 Range of Concern
            if ($total_score >= 14) {
                $scoreCols["ADOS_classification"] = "Moderate-to-Severe Concern";
            } else if ($total_score >= 10 && $total_score <= 13) {
                $scoreCols["ADOS_classification"] = "Mild-to-Moderate Concern";
            } else {
                $scoreCols["ADOS_classification"] = "Little-to-No Concern";
            }

            // Overall Total (SA + RRB)
            $scoreCols["social_affect_restricted_repetitive_behavior_total"] = $total_score;

            /*
            // Weighted Scores 
            // Social Affect
            $scoreCols['b1_weighted']  = $record['b1'] * 0.64;  // Unusual Eye Contact
            $scoreCols['b5_weighted']  = $record['b5'] * 0.76;  // Gaze and Other Behaviors
            $scoreCols['b4_weighted']  = $record['b4'] * 0.85;  // Facial Expressions
            $scoreCols['a2_weighted']  = $record['a2'] * 0.69;  // Frequency of Vocalization
            $scoreCols['b6_weighted']  = $record['b6'] * 0.71;  // Shared Enjoyment
            $scoreCols['b15_weighted'] = $record['b15'] * 0.74; // Quality of Social Overtures
            $scoreCols['b14_weighted'] = $record['b14'] * 0.60; // Response to Joint Attention
            $scoreCols['a8_weighted']  = $record['a8'] * 0.73;  // Gestures
            $scoreCols['b12_weighted'] = $record['b12'] * 0.69; // Showing
            $scoreCols['b13_weighted'] = $record['b13'] * 0.77; // Initiation of Joint Attention
            
            // Restricted Repetitive Behaviours
            $scoreCols['a3_weighted'] = $record['a3'] * 0.44; // Intonation
            $scoreCols['d1_weighted'] = $record['d1'] * 0.78; // Unusual Sensory Interest
            $scoreCols['d5_weighted'] = $record['d5'] * 0.44; // Repetitive Interests
            $scoreCols['d2_weighted'] = $record['d2'] * 0.66; // Hand Mannerisms
            */
        }

        /** OLDER WITH SOME WORDS **/
        if ($module == "1-Words") {
            // SA Total
            $scoreCols["social_affect_total"] =
                $converted_scores["a7"] +
                $converted_scores["b1"] +
                $converted_scores["b4"] +
                $converted_scores["b5"] +
                $converted_scores["b7"] +
                $converted_scores["b8"] +
                $converted_scores["b9"] +
                $converted_scores["b13"] +
                $converted_scores["b15"] +
                $converted_scores["b16b"] +
                $converted_scores["b18"];

            // RRB Total
            $scoreCols["restricted_repetitive_behavior_total"] =
                $converted_scores["d1"] +
                $converted_scores["d2"] +
                $converted_scores["d5"];

            $total_score =
                $scoreCols["social_affect_total"] +
                $scoreCols["restricted_repetitive_behavior_total"];

            // ADOS-2 Range of Concern
            if ($total_score >= 12) {
                $scoreCols["ADOS_classification"] = "Moderate-to-Severe Concern";
            } else if ($total_score >= 8 && $total_score <= 11) {
                $scoreCols["ADOS_classification"] = "Mild-to-Moderate Concern";
            } else {
                $scoreCols["ADOS_classification"] = "Little-to-No Concern";
            }

            // Overall Total (SA + RRB)
            $scoreCols["social_affect_restricted_repetitive_behavior_total"] = $total_score;

            /*
            // Weighted Scores 
            // Social Affect
            $scoreCols['b1_weighted']  = $record['b1'] * 0.53;  // Unusual Eye Contact
            $scoreCols['b5_weighted']  = $record['b5'] * 0.47;  // Gaze and Other Behaviors
            $scoreCols['b4_weighted']  = $record['b4'] * 0.68;  // Facial Expressions
            $scoreCols['a2_weighted']  = $record['a2'] * 0.84;  // Frequency of Vocalization
            $scoreCols['b6_weighted']  = $record['b6'] * 0.62;  // Shared Enjoyment
            $scoreCols['b15_weighted'] = $record['b15'] * 0.65; // Quality of Social Overtures
            $scoreCols['b14_weighted'] = $record['b14'] * 0.82; // Response to Joint Attention
            $scoreCols['a8_weighted']  = $record['a8'] * 0.72;  // Gestures
            $scoreCols['b12_weighted'] = $record['b12'] * 0.79; // Showing
            $scoreCols['b13_weighted'] = $record['b13'] * 0.73; // Initiation of Joint Attention
            
            // Restricted Repetitive Behaviours
            $scoreCols['a3_weighted'] = $record['a5'] * 0.7;  // Stereotyped Language
            $scoreCols['d1_weighted'] = $record['d1'] * 0.7;  // Unusual Sensory Interest
            $scoreCols['d5_weighted'] = $record['d5'] * 0.69; // Repetitive Interests
            $scoreCols['d2_weighted'] = $record['d2'] * 0.63; // Hand Mannerisms
            */
        }

        /** SEVERITY SCORE LOOKUP **/
        // Column limits for age (min, max), raw score (min, max)
        // ados_lookup table columns :
        // sevscore module minagemos maxagemos minraw maxraw

        $scoreCols['severity_score_lookup'] = "N/A";

        if ($module != "") {
            $query_severity_lookup = "
                SELECT
                    sevscore
                FROM
                    ados_lookup
                WHERE
                    module    = :modname AND
                    minagemos <= :agemonths AND
                    maxagemos >= :agemonths AND
                    minraw    <= :rawscore AND
                    maxraw    >= :rawscore"
            ;

            $sevscore = $db->pselectOne(
                $query_severity_lookup,
                array(
                    'modname'   => $module,
                    'agemonths' => $age_months,
                    'rawscore'  => $scoreCols['social_affect_restricted_repetitive_behavior_total']
                )
            );

            if (!empty($sevscore)) {
                $scoreCols['severity_score_lookup'] = $sevscore;
            }
        }

        /** CSS Calculations **/

        // If the candidate is 23 months old, round to 24 months
        if ($age_months >= 23 && $age_months < 24) {
            $age_months = 24;
        }

        $ados_age = -1;

        for ($i = 2; $i <= 14; $i++) {
            $low  = $i * 12;
            $high = ($i + 1) * 12;
            if ($age_months >= $low && $age_months < $high) {
                $ados_age = $i;
            }
        }

        $scoreCols["ADOS_SA_CSS"]  = $this->ADOS_SA_CSS($this->table, $record['a1'], $scoreCols['social_affect_total'], $ados_age);
        $scoreCols["ADOS_RRB_CSS"] = $this->ADOS_RRB_CSS($this->table, $record['a1'], $scoreCols['restricted_repetitive_behavior_total'], $ados_age);

        // Save scores to database
         $result = $db->update($this->table, $scoreCols, array("CommentID"=>$this->getCommentID()));
    }
}
