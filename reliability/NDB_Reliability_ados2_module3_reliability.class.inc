<?php
set_include_path(get_include_path() . ":../libraries:../../php/libraries:");
require_once "NDB_Reliability.class.inc";
//require_once "NDB_BVL_Instrument.class.inc";
/**
 * The forms for the tracking log menu
 * @package main
 * @package LORIS
 * @author Rathi Gnanasekaran sekaranrathi@gmail.com
 *
 */
class NDB_Reliability_ados2_module3_reliability extends NDB_Reliability
{
    var $option01237 = array(""=>NULL, 0=>0, 1=>1, 2=>2, 3=>3, 7=>7, "not_answered"=>"Not Answered");
    var $option0127 = array(""=>NULL, 0=>0, 1=>1, 2=>2, 7=>7, "not_answered"=>"Not Answered");
    var $option01278 = array(""=>NULL, 0=>0, 1=>1, 2=>2, 7=>7, 8=>8, "not_answered"=>"Not Answered");
    var $option0123 = array(""=>NULL, 0=>0, 1=>1, 2=>2, 3=>3, "not_answered"=>"Not Answered");
    var $option01238 = array(""=>NULL, 0=>0, 1=>1, 2=>2, 3=>3, 8=>8, "not_answered"=>"Not Answered");
    var $option02 = array(""=>NULL, 0=>0, 2=>2, "not_answered"=>"Not Answered");
    var $option012 = array(""=>NULL, 0=>0, 1=>1, 2=>2, "not_answered"=>"Not Answered");
    var $option0128 = array(""=>NULL, 0=>0, 1=>1, 2=>2, 8=>8, "not_answered"=>"Not Answered");
    function _getAgeInMonths($instrument_record, $reliability_record)
    {
        $CommentID = $this->identifier;
        $CandID = substr($CommentID, 0, 6);
        $candidate =& Candidate::singleton($CandID);
        $age = Utility::calculateAge($candidate->getCandidateDoB(), $instrument_record['Date_taken']);
        return $age['year'] * 12 + $age['mon'];
    }

    function _getDefaults()
    {
        $DB =& Database::singleton();
        $result = $DB->pselect("SELECT * FROM {$this->name}", array());

        //print_r($this->identifier);
        if (!empty($this->identifier)) {
            // set the ados2_module2_reliability values
            $row = $DB->pselectRow("SELECT * FROM {$this->name} WHERE CommentID=:cid AND reliability_center_id=:rcid", array("cid" => $this->identifier, "rcid" => $this->reliability_center_id));

            // Set the defaults
            // print_r($row['CommentID']);

            $sites = array(1 => 'DCC', 2 => 'SEA', 3 => 'PHI', 4 => 'STL', 5 => 'UNC');

            $initial_table = preg_replace('/_reliability/', '', $this->name);

            foreach ($row as $key => $value) {
                $defaults[$key] = $value;
            }
        } else {
            echo("Identifier empty! No ID has been chosen. Please contact Samir at the DCC.<br>");
        }

        return $defaults;
    }


    function score()
    {
        //holds raw question values
        $score_record = array();
        //holds calculated
        $db =& Database::singleton();

        // null scores
        //$this->_nullScores();
        $initial_table = preg_replace('/_reliability/', '', $this->name);

        //Get values from both tables of adi_r (reliability and original)
        $query = "SELECT * FROM {$this->name} WHERE CommentID=:cid AND reliability_center_id=:rcid";
        $query1 = "SELECT * FROM {$initial_table} WHERE CommentID=:cid";

        $score_record = $db->pselectRow($query, array("cid" => $this->identifier, "rcid" => $this->reliability_center_id));
        $score_record1 = $db->pselectRow($query1, array("cid" => $this->identifier));
        $session = $db->pselectOne("SELECT s.ID from session s JOIN flag f ON s.ID=f.SessionID WHERE f.CommentID=:cid", array('cid' => $this->identifier));
        // Get the subject age in months for scoring
        $timepoint =& TimePoint::singleton($session);
        $dob = $timepoint->getEffectiveDateOfBirth();
        $age = Utility::calculateAge($dob, $score_record1["Date_taken"]);
        $age_years = $age['year'] + ($age['mon'] / 12);
        $instrument_record = $this->_convertScore($score_record1);
        $reliability_record = $this->_convertScore($score_record);

        $mismatches = 0;
        $denominator = 0;
        $algorithm_mismatches = 0;
        $algorithm_denominator = 0;
        $algorithm_questions = array('a4', 'a6', 'a7', 'b1', 'b2', 'b3', 'b5', 'b6', 'b8', 'b11', 'b12', 'd1', 'd2', 'd4');
        if ($age_years >= 5) {
            $algorithm_questions = array('a5', 'a6', 'a7', 'a8', 'b1', 'b2', 'b3', 'b5', 'b6', 'b8', 'b11', 'b12', 'd1', 'd2', 'd4');
        }
        $excluded = array('CommentID', 'UserID', 'Examiner', 'Testdate', 'Data_entry_completion_status', 'Date_taken', 'Candidate_Age', 'Window_Difference', 'other_comments');
        foreach ($instrument_record as $key => $value) {
            if (!in_array($key, $excluded)) {
                $algorithm_question = in_array($key, $algorithm_questions);
                $rel_value = $reliability_record[$key];

                $denominator++;
                if ($algorithm_question) {
                    $algorithm_denominator++;
                }

                if ($value != $rel_value) {
                    //echo("MISMATCH<BR>");
                    $mismatches++;
                    if ($algorithm_question) {
                        $algorithm_mismatches++;
                    }
                }
            }
        }

//        print "Denominator : $denominator , MISMATCHES : $mismatches, ALG_DENOM : $algorithm_denominator, ALG_MISMATCH : $algorithm_mismatches";
        // Score the reliability
        $reliability['Reliability_score_all_items'] = (($denominator - $mismatches) / $denominator * 100);
        $reliability['Reliability_score_scored_items'] = (($algorithm_denominator - $algorithm_mismatches) / $algorithm_denominator * 100);


        // Do the update here for the relibaility scores - saving the scores
        $result = $db->update("{$this->name}", $reliability, array("CommentID" => $this->identifier, 'reliability_center_id' => $this->reliability_center_id));
        $result = $db->update("reliability", array("Reliability_score" => round(min($reliability['Reliability_score_all_items'], $reliability['Reliability_score_scored_items']), 3)), array("CommentID" => $this->identifier, "Instrument" => preg_replace("/_reliability$/", "", $this->name), 'reliability_center_id' => $this->reliability_center_id));
        // Update the main relibaility table with the overall reliability score
        $result1 = $db->update("reliability", array('reliability_score' => $reliability['Reliability_score_all_items']), array("CommentID" => $this->identifier));
    } // end function score

    function _convertScore($scores)
    {
        foreach ($scores as $field => $value) {
            if ($value == 0) {
                $scores[$field] = 0;
            } elseif ($value == 1) {
                $scores[$field] = 1;
            } elseif ($value == 2) {
                $scores[$field] = 2;
            } elseif ($value == 3) {
                $scores[$field] = 2;
            } elseif ($value >= 4) {
                $scores[$field] = 0;
            } elseif ($value == "not_answered") {
                $scores[$field] = 0;
            }
        }
        return $scores;
    }

    function _nullScores()
    {
        $db =& Database::singleton();

        // set the scores to NULL
        foreach ($this->scores as $val) {
            $scores[$val] = null;
        }

        // update the scores
        $success = $db->update("{$this->name}", $scores, array("CommentID" => $this->identifier, 'reliability_center_id' => $this->reliability_center_id));
        return;
    }

    function ados2_module3_reliability()
    {
        $this->create_form();
    }


    function create_form()
    {
        $this->_addMetadataFields();
        $this->form->addElement("static", "reliability_center", "Site of Reliability Test:");

        //Scoring header
        $this->form->addElement('header', 'instrument_title', "Scoring:");
        $this->form->addElement("static", "Reliability_score_scored_items", "Reliability Score Scored items(%):");
        $this->form->addElement("static", "Reliability_score_all_items", "Reliability All items(%):");
        $factory = \NDB_Factory::singleton();
        $baseurl = $factory->settings()->getBaseURL();
        $initial_table = preg_replace('/_reliability/', '', $this->name);
        $url= "$baseurl/reliability/reliability_breakdown/?instrument=".$initial_table."&CommentID=".$this->identifier;
        $this->form->addElement("link", null, "CommentID:", $url, $this->identifier);

        //display test name
        $this->form->addElement('header', null, "CODING:");
        $this->form->addElement("static", null, "<BR>"); //line space

        $this->form->addElement('header', null, "Section A: Language and Communication");
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'a1', '1. Overall Level of Non-Echoed Language', $this->option0123);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'a2', '2. Speech Abnormalities Associated with Autism (Intonation/Volume/Rhythm/Rate)', $this->option01278);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'a3', '3. Immediate Echolalia', $this->option0123);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'a4', '4. Stereotyped/Idiosyncratic Use of Words or Phrases', $this->option0123);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'a5', '5. Offers Information', $this->option012);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'a6', '6. Asks for Information', $this->option0123);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'a7', '7. Reporting of Events', $this->option0123);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'a8', '8. Conversation', $this->option0123);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'a9', '9. Descriptive, Conventional, Instrumental, or Informational Gestures', $this->option01238);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement("static", null, "<BR>"); //line space
        //Section B: Reciprocal Social Interaction
        $this->form->addElement('header', null, "Section B: Reciprocal Social Interaction");
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'b1', '1. Unusual Eye Contact', $this->option02);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'b2', '2. Facial Expressions Directed to Others', $this->option012);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'b3', '3. Language Production and Linked Nonverbal Communication', $this->option01278);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'b4', '4. Shared Enjoyment in Interaction', $this->option0123);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'b5', '5. Empathy/Comments on Others\' Emotions', $this->option0123);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'b6', '6. Insight', $this->option0123);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'b7', '7. Quality of Social Overtures', $this->option0123);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'b8', '8. Amount of Social Overtures/Maintenance of Attention', $this->option01237);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'b9', '9. Quality of Social Response', $this->option0123);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'b10', '10. Amount of Reciprocal Social Communication', $this->option0123);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'b11', '11. Overall Quality of Rapport', $this->option0123);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('header', null, "Section C: Play");
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'c1', '1. Imagination/Creativity', $this->option0123);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement("static", null, "<BR>"); //line space
        //Section D: Stereotyped Behaviors and Restricted Interests
        $this->form->addElement('header', null, "Section D: Stereotyped Behaviors and Restricted Interests");
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'd1', '1. Unusual Sensory Interest in Play Material/Person', $this->option0123);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->addTextAreaElement('d1_specify', $this->indent . "Please specify:");
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'd2', '2. Hand and Finger and Other Complex Mannerisms', $this->option0123);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->addTextAreaElement('d2_specify', $this->indent . "Please specify:");
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'd3', '3. Self-Injurious Behavior', $this->option012);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'd4', '4. Excessive Interest in or References to Unusual or Highly Specific Topics or Objects or Repetitive Behaviors', $this->option0123);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'd5', "5. Compulsions or Rituals", $this->option012);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->addTextAreaElement('d5_specify', $this->indent . "Please specify:");
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement("static", null, "<BR>"); //line space
        //Section E: Other Abnormal Behaviors
        $this->form->addElement('header', null, "Section E: Other Abnormal Behaviors");
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'e1', '1. Overactivity/Agitation', $this->option01237);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'e2', '2. Tantrums, Aggression, Negative or Disruptive Behavior', $this->option0123);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement('select', 'e3', '3. Anxiety', $this->option012);
        $this->form->addElement("static", null, "<BR>"); //line space
        $this->form->addElement("static", null, "<BR>"); //line space
    } // End function
    function _cleanTo3Digits($string)
    {
        return preg_replace("[^0-9]", "", substr($string, 0, 3));
    }

    function _process($values)
    {

        $DB =& Database::singleton();
        $user =& User::singleton();

        $row = $DB->pselectRow("SELECT * FROM {$this->name} WHERE CommentID=:cid AND reliability_center_id=:rcid", array("cid" => $this->identifier, "rcid" => $this->reliability_center_id));

        $invalid = $values['invalid'];
        $DB->update("reliability", array('invalid' => $invalid), array("CommentID" => $this->identifier, "Instrument" => preg_replace("/_reliability$/", "", $this->name), "reliability_center_id" => $this->reliability_center_id));
        unset($values['invalid']);

        if ($invalid == "yes") {
            $this->form->freeze();
            $this->tpl_data['success'] = true;
            return;
        }

        if (empty($row)) {

            $values['CommentID'] = $this->identifier;
            $values['reliability_center_id'] = $this->reliability_center_id;
            // insert the event
            $success = $DB->insert($this->name, $values);
        } else {
            // update the event
            $success = $DB->update($this->name, $values,
                array('CommentID' => $this->identifier, 'reliability_center_id' => $this->reliability_center_id)
            );
        }

        $scoreResult = $this->score();

        $this->form->freeze();
        $this->tpl_data['success'] = true;
    }

    function _validate($values)
    {
        $DB =& Database::singleton();
        $query = "SELECT count(*) AS counter FROM candidate WHERE CandID='$values[CandID]' and PSCID='$values[PSCID]'";
        $recordsFound = $DB->pselectOne($query, array());
        $errors = array();

        if ($recordsFound < 1) {
            $errors['CandID'] = "Specified DCCID and PSCID do not exist or do not match.";
        }

        return $errors;
    }

    function display()
    {
        if (!$this->form->isFrozen()) {
            // hidden values
            $this->form->addElement('hidden', 'test_name', $this->name);
            $this->form->addElement('hidden', 'subtest', $this->page);
            $this->form->addElement('hidden', 'identifier', $this->identifier);
            $this->form->addElement('hidden', 'reliability_center_id', $this->reliability_center_id);
            $buttons[] = $this->form->createElement(
                'submit',
                'fire_away',
                'Save Data',
                array('class' => 'button')
            );
            //$buttons[] = $this->form->createElement('reset', null, 'Reset');
            $this->addGroup($buttons, null, null, "&nbsp;");
        }

        // get the defaults
        $localDefaults = $this->_getDefaults();
        if (!is_array($localDefaults)) {
            $localDefaults = array();
        }
        // set the quickform object defaults
        $this->form->setDefaults(array_merge($this->defaults, $localDefaults));

        // trim all values
        $this->form->applyFilter('__ALL__', 'trim');

        // display the HTML_Quickform object
        $smarty = new Smarty_neurodb;

        // display the HTML_Quickform object
        return $this->form->toHTML();



    } // end function display
}
?>