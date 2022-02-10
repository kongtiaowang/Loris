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
        'b18_weighted', 'd1_weighted', 'd2_weighted', 'd5_weighted', 'severity_score_lookup'
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
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)
        // set the object properties
        $this->testName = "ADOS2_Toddler_Module";           // test_names.Test_name
        $this->table    = 'ADOS2_Toddler_Module';              // name of database table corresponding to instrument
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
        $this->form->addElement('static', "social_affect_total", "Social Affect Total:");
        $this->form->addElement('static', "restricted_repetitive_behavior_total", "Restricted and Repetitive Behavior Total:");
        $this->form->addElement('static', "social_affect_restricted_repetitive_behavior_total", "Social Affect and Restricted and Repetitive Behavior Total:");
        $this->form->addElement('static', "ADOS_SA_CSS", "ADOS_SA_CSS:");
        $this->form->addElement('static', "ADOS_RRB_CSS", "ADOS_RRB_CSS:");
        $this->form->addElement('static', "ADOS_classification", "ADOS Classification:");
        $this->form->addElement('header', null, 'Severity Scores:');
        $this->form->addElement('static', 'severity_score_lookup', 'Severity Score:');
        /*
            $group[]= &$this->form->createElement("static", "ADOS_classification", null);
             $this->form->addGroup($group, null, "ADOS Classification:", $this->_GUIDelimiter, false);
            unset($group);

            $this->form->addElement("static",null,null);
            $this->form->addElement("static",null,null);
            */
    }

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

        //Convert the entered scores to countable scores:
        //"Convert scores of 3 on the protocol to 2, and treat all other scores other than 0-3 as 0."
        $scores = array(); //holds converted scores
        foreach($record as $field=>$value) {
            if($value == 0) {
                $scores[$field] = 0;
            } elseif ($value == 1 && $field != 'b1') {
                $scores[$field] = 1;
            } elseif ($value == 2) {
                $scores[$field] = 2;
            } elseif ($value == 3 && $field != 'b1') {
                $scores[$field] = 2;
            } elseif ($value >= 4) {
                $scores[$field] = 0;
            } elseif ($value == "not_answered") {
                $scores[$field] = 0;
            } elseif ($field == 'b1' && ($value == 1 || $value == 3)) {
                $scores[$field] = 2;
            }
        }

        $module = '';

        // NO WORDS scoring
        if($record["a1"] == 3 || $record["a1"] == 4) {
            $module = '1-NoWords';

            $scoreCols["social_affect_total"] = $scores["a2"] + $scores["a8"] + $scores["b1"] + $scores["b4"] +
                $scores["b5"] + $scores["b6"] + $scores["b12"] + $scores["b13"] + $scores["b14"] + $scores["b15"];
            $scoreCols["restricted_repetitive_behavior_total"] = $scores["a3"] + $scores["d1"] + $scores["d2"] + $scores["d5"];
            $scoreCols["social_affect_restricted_repetitive_behavior_total"] = $scoreCols["social_affect_total"] + $scoreCols["restricted_repetitive_behavior_total"];

            if($scoreCols["social_affect_restricted_repetitive_behavior_total"] >= 10 && $scoreCols["social_affect_restricted_repetitive_behavior_total"] <= 13) {
                $scoreCols["ADOS_classification"] = "Mild-to-Moderate Concern";
            } elseif ($scoreCols["social_affect_restricted_repetitive_behavior_total"] >= 14) {
                $scoreCols["ADOS_classification"] = "Moderate-to-Severe Concern";
            } else {
                   $scoreCols["ADOS_classification"] = "Little-to-No Concern";
            }

            // Weightings from Risi, Pickles and Lord 2007 Table 2
            // Put in the same order as the paper, which happens to be different than
            // how Loris orders it, which is why this looks a little weird
            // Social Affect
            $scoreCols['b1_weighted'] = $scores['b1'] * 0.64; // Unusual Eye Contact
            $scoreCols['b4_weighted'] = $scores['b4'] * 0.76; // Gaze and Other
            //            $scoreCols['b3_weighted'] = $scores['b3'] * 0.85; // Facial Expressions
            $scoreCols['a2_weighted']  = $scores['a2'] * 0.69; // Frequency of vocalization
            $scoreCols['b5_weighted']  = $scores['b5'] * 0.71; // Shared Enjoyment
            $scoreCols['b12_weighted'] = $scores['b12'] * 0.74; // Quality of Social Overtures
            //            $scoreCols['b11_weighted'] = $scores['b11'] * 0.60;// Response to Joint Attention
            $scoreCols['a8_weighted'] = $scores['a8'] * 0.73; // Gestures
            $scoreCols['b9_weighted'] = $scores['b9'] * 0.69; // Showing
            //            $scoreCols['b10_weighted'] = $scores['b10'] * 0.77;// Initiation of Joint Attention
            // Restricted Repetitive Behaviours
            $scoreCols['a3_weighted'] = $scores['a3'] * 0.44; // Intonation
            $scoreCols['d1_weighted'] = $scores['d1'] * 0.78; // Unusual Sensory Interest
            //            $scoreCols['d4_weighted'] = $scores['d4'] * 0.44; // Repetitive Interests
            $scoreCols['d2_weighted'] = $scores['d2'] * 0.66; // Hand Mannerisms
        }

        //SOME WORDS Scoring
        if($record["a1"] == 0 || $record["a1"] == 1 || $record["a1"] == 2) {
            $module = '1-Words';

            $scoreCols["social_affect_total"] = $scores["a2"] + $scores["a7"] + $scores["a8"] + $scores["b1"] +
                $scores["b4"] + $scores["b5"] + $scores["b6"] + $scores["b7"] + $scores["b8"] + $scores["b9"] +
                $scores["b12"] + $scores["b13"] + $scores["b14"] + $scores["b15"] + $scores["b16b"] + $scores["b18"];
            $scoreCols["restricted_repetitive_behavior_total"] = $scores["a3"] + $scores["d1"] + $scores["d2"] + $scores["d5"];
            $scoreCols["social_affect_restricted_repetitive_behavior_total"] = $scoreCols["social_affect_total"] + $scoreCols["restricted_repetitive_behavior_total"];
            if($scoreCols["social_affect_restricted_repetitive_behavior_total"] >= 8 && $scoreCols["social_affect_restricted_repetitive_behavior_total"] <= 11) {
                $scoreCols["ADOS_classification"] = "Mild-to-Moderate Concern";
            } elseif ($scoreCols["social_affect_restricted_repetitive_behavior_total"] >= 12) {
                $scoreCols["ADOS_classification"] = "Moderate-to-Severe Concern";
            } else {
                $scoreCols["ADOS_classification"] = "Little-to-No Concern";
            }
        }

        //Determine Severity score from ados_lookup table
        //Requires age in months:
        $Answers    = $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid", array("cid" =>$this->getCommentID() ));
        $age_months = 0;
        if($this->getSessionID() != null) { //quickform_parser doesn't use any specific session
            $timepoint =& TimePoint::singleton($this->getSessionID());
            $dob       = $timepoint->getEffectiveDateOfBirth();
        }

        if(!empty($dob) && !empty($Answers['Date_taken'])) {
            $age = Utility::calculateAge($dob, $Answers["Date_taken"]);
            if(is_array($age)) {
                $age_months = $age['year'] * 12 + $age['mon'];
            }
        }
        //Severity score lookup:  column limits for age (min, max), raw score (min, max)
        // ados_lookup table columns : sevscore module minagemos maxagemos minraw maxraw
        if ($module != '' && $age_months != 0) {
            $query_severity_lookup = "SELECT sevscore FROM ados_lookup WHERE module = :modname AND minagemos <= :agemonths AND maxagemos >= :agemonths AND minraw <= :rawscore AND maxraw >= :rawscore";
            $record_lookup         = array();
            $sevscore = $db->pselectOne(
                $query_severity_lookup,
                array(
                    'modname'   => $module,
                    'agemonths' => $age_months,
                    'rawscore'  => $scoreCols['social_affect_restricted_repetitive_behavior_total']
                )
            );
            if(empty($sevscore)) {
                $scoreCols['severity_score_lookup'] = "N/A";
            } else {
                $scoreCols['severity_score_lookup'] =$sevscore;
            }

            //($record_lookup['sevscore']);
        }

        // CSS Calculations

        // if the candidate is 23 months old, round to 24 months
        if ($age_months >= 23 && $age_months < 24) {
            $age_months = 24;
        }

        for ($i = 2; $i <= 14; $i++) {
            $low  = $i*12;
            $high = ($i+1)*12;
            if ($age_months >= $low && $age_months < $high) {
                $ados_age = $i;
            }
        }
        $scoreCols["ADOS_SA_CSS"]  = $this->ADOS_SA_CSS($this->table, $record['a1'], $scoreCols['social_affect_total'], $ados_age);
        $scoreCols["ADOS_RRB_CSS"] = $this->ADOS_RRB_CSS($this->table, $record['a1'], $scoreCols['restricted_repetitive_behavior_total'], $ados_age);

        // save scores to database
         $result = $db->update($this->table, $scoreCols, array("CommentID"=>$this->getCommentID()));
    }   // end score function
}


