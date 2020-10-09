<?php
/**
 * This file contains the NDB_BVL_Instrument_asd_peds
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  asd_peds
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/
 */

/**
 * Creates the form elements for the TELE-ASD-PEDS instrument
 *
 * @category Instrument
 * @package  asd_peds
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/
 */
class NDB_BVL_Instrument_asd_peds extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;

    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    var $scoreLabels = array(
                        'dichotomous_total_score',
                        'likert_total_score',
                       );

    private $_likert_score_options = array(
                                      'null' => '',
                                      '1'    => '1 = Symptom not present',
                                      '2'    => '2 = Symptom present but at subclinical levels',
                                      '3'    => '3 = Symptom obviously consistent with AS',
                                     );

    private $_dichotomous_score_options = array(
                                           'null' => '',
                                           '1'    => '1 = Symptom not present',
                                           '3'    => '3 = Symptom obviously consistent with AS',
                                          );

    private $_item_grp = [
                          'q1_speech'         => 'Socially directed speech and sounds',
                          'q2_eye_contact'    => 'Frequent and flexible eye contact',
                          'q3_vocalizations'  => 'Unusual vocalizations',
                          'q4_play'           => 'Unusual or repetitive play',
                          'q5_body_movements' => 'Unusual or repetitive body movements',
                          'q6_gestures'       => 'Combines gestures, eye contact, and speech/vocalization',
                          'q7_sensory'        => 'Unusual sensory exploration or reaction',
                         ];

    private $_likert_grp1 = [
                             'q1_speech'         => 'Child often uses words or other vocalizations for a variety of social purposes (e.g. requesting, protesting, directing attention, sharing enjoyment).',
                             'q2_eye_contact'    => 'Child frequently makes eye contact with others and across a variety of activities',
                             'q3_vocalizations'  => 'No unusual qualities of speech/language observed. Most of child’s speech is appropriate for the child’s age and developmental level.',
                             'q4_play'           => 'Child plays with toys in appropriate ways (uses toys as expected).',
                             'q5_body_movements' => 'No unusual or repetitive body movements seen.',
                             'q6_gestures'       => 'Child frequently points and uses other gestures to communicate. Child’s gestures are usually combined with vocalizations and eye contact.',
                             'q7_sensory'        => 'No unusual sensory behavior observed.',
                            ];

    private $_likert_grp2 = [
                             'q1_speech'         => 'Inconsistent socially directed speech.',
                             'q2_eye_contact'    => 'Child’s eye contact seems inconsistent. Gaze seems less flexible and harder to catch than expected.',
                             'q3_vocalizations'  => 'Speech is not clearly unusual, but there are some differences (e.g., volume, slight repetitive quality of speech/language, unclear echoing, some occasional sounds that are unusual).',
                             'q4_play'           => 'Child’s play is not clearly unusual, but child is strongly focused on some toys, routines, or activities. May sometimes be hard to shift child’s attention to something new.',
                             'q5_body_movements' => 'Unclear unusual/repetitive body movements. Some repetitive jumping or very brief posturing of fingers, hands, or arms that is not clearly atypical.',
                             'q6_gestures'       => 'Child may sometimes point or use other gestures, but less than expected. Child does not always look at you or make a sound when gesturing.',
                             'q7_sensory'        => 'Unclear sensory exploration or reaction. May have a brief response to a sound, smell, or how something feels or moves.',
                            ];

    private $_likert_grp3 = [
                             'q1_speech'         => 'Most of the child’s sounds are self-directed. May make atypical non-word noises (e.g., “digga digga”).',
                             'q2_eye_contact'    => 'Child infrequently makes eye contact. Might only make eye contact during one activity (e.g., asking for help).',
                             'q3_vocalizations'  => 'Child produces unusual jargon, sounds, or speech/language (e.g., undirected jargoning, speech of peculiar intonation, unusual sounds, repetitive vocalizations, echoing or repetitive speech/language.',
                             'q4_play'           => 'Child shows clearly repetitive or unusual play, such as repeatedly pushing buttons, watching how objects move, lining things up, or scrambling/dropping toys.',
                             'q5_body_movements' => 'Child clearly shows unusual or repetitive (e.g., hand-flapping, posturing or tensing upper body, toe-walking, facial grimacing, hand/finger mannerisms) repetitive running/walking/spinning/jumping.',
                             'q6_gestures'       => 'Child does not usually gesture to communicate. May sometimes reach or point, but does not usually combine these with eye gaze or sounds. May move your hand or push on your body to get help.',
                             'q7_sensory'        => 'Child shows sensory differences. May closely inspect objects, overreact to sounds, show intense interest or dislike to textures (e.g., touching, licking, biting, refusing to touch specific toys), or clear self-injurious behavior.',
                            ];

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('asd_peds', "TELE-ASD-PEDS Rating Form", 1, 0);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('asd_peds','asd_peds_page1', "Page 1", 1);
     * INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('asd_peds', '0', '0', 'Y', 'Visit', '18', 'V24', NULL);
     * INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('asd_peds', '0', '0', 'Y', 'Visit', '18', 'V24-CVD', NULL);
     * INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('asd_peds', '0', '0', 'Y', 'Visit', '19', 'V24', NULL);
     * INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('asd_peds', '0', '0', 'Y', 'Visit', '19', 'V24-CVD', NULL);
     */

    /**
     * Sets up basic data such as the HTML_Quickform object, database references
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page      if a multipage form, the page to show
     *
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('asd_peds_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        // Corresponds to the Test_name column in test_names table
        $this->testName = "asd_peds";
        // name of database table corresponding to instrument
        $this->table = 'asd_peds';
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array("q1_speech_likert");

        // setup the form
        $this->_setupForm();
    }

    /**
     * Builds the HTML_Quickform object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        if (preg_match("/asd_peds(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        // Defines the call back function for HTML Quickform to use in validation
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    /**
     * Generates the main page of the form.
     *
     * @return void
     * @access private
     */
    function _main()
    {
        // display test name
        $this->addHeader("TELE-ASD-PEDS Rating Form");

        $config =& NDB_Config::singleton();

        $dateOptions = array(
                        'language'         => 'en',
                        'format'           => 'YMd',
                        'minYear'          => $config->getSetting('startYear'),
                        'maxYear'          => $config->getSetting('endYear'),
                        'addEmptyOption'   => true,
                        'emptyOptionValue' => null,
                       );
        $this->addBasicDate('Date_taken', 'Date Taken', $dateOptions);

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $this->form->addElement('static', null, null);

        // If the instrument is not paged,
        // remove the switch from the _setupForm method
        // and add all the form Elements in this function

        $this->form->addElement('static', 'lorisSubHeader', '<b>Dichotomous score:</b> Is the symptom present or not (1 vs. 3)<br><b>Likert score:</b> 1 = symptom not present; 2 = symptom present but at subclinical levels; 3 = symptom obviously consistent with AS');

        $this->form->addElement('static', null, null);

        $group[] = $this->form->createElement('static', "total_score", null, null);
        $this->form->addGroup($group, 'score_header_group', "<strong>Score Type</strong>", $this->_GUIDelimiter, false);

        unset($group);

        $columnHeaders = array("total_score" => "Total Score");

        $scoreTypes = array(
                       "dichotomous" => "Dichotomous Score (1/3)",
                       "likert"      => "Likert Score (1/2/3)",
                      );

        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        foreach ($scoreTypes as $scoreField => $scoreLabel) {
            foreach ($columnHeaders as $columnField => $columnHeader) {
                $group[] = $this->form->createElement('static', "{$scoreField}_{$columnField}", null, null);
            }
            $this->form->addGroup($group, "{$scoreField}_score_group", $scoreLabel, $this->_GUIDelimiter, false);
            unset($group);
        }
    }

    /**
     * Generates the first page of the form.
     *
     * @return void
     */
    function _page1()
    {
        // display test name
        $this->addHeader("TELE-ASD-PEDS Rating Form");

        $this->addBasicText("child_age", "Child age (months)");

        $this->addSelect(
            "child_gender",
            "Gender",
            array(
             null     => "",
             "male"   => "M",
             "female" => "F",
            )
        );

        $this->form->addElement('static', null, null);

        $i = 1;

        foreach ($this->_item_grp as $key => $val) {
            $this->form->addElement(
                'static',
                null,
                $i . ". " . $val
            );

            $this->form->addElement(
                'static',
                null,
                '<h6><i>' .
                    $this->getLikertOptions($key) .
                '</i></h6>'
            );

            $this->addSelect($key . "_likert", $this->indent . "Likert", $this->_likert_score_options);

            $this->addSelect($key . "_dichotomous", $this->indent . "Dichotomous", $this->_dichotomous_score_options);

            $i++;

            $this->form->addElement('static', null, null);
        }

        $this->addSelect(
            "asd_if_forced_to_choose",
            "ASD if forced to choose?",
            array(
             null        => '',
             '1_absent'  => 'Absent',
             '2_unsure'  => 'Unsure',
             '3_present' => 'Present',
            )
        );

        $this->addSelect(
            "recommend_in_person_evaluation",
            "Did you recommend in person evaluation for diagnostic clarification?",
            array(
             null  => '',
             'yes' => 'Yes',
             'no'  => 'No',
            )
        );

        $this->addBasicText("diagnosis_issued", "Diagnosis issued:");

        $this->addSelect(
            "how_certain_diagnostic_impression",
            "How certain are you of your diagnostic impression?",
            array(
             null                     => '',
             '1_completely_uncertain' => '1 = Completely uncertain',
             '2_somewhat_uncertain'   => '2 = Somewhat uncertain',
             '3_somewhat_certain'     => '3 = Somewhat certain',
             '4_completely_certain'   => '4 = Completely certain',
            )
        );

        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    function getLikertOptions($key)
    {
        return $this->indent . '1 = ' . $this->_likert_grp1[$key] . '<br>' . $this->indent . '2 = ' . $this->_likert_grp2[$key] . '<br>' . $this->indent . '3 = ' . $this->_likert_grp3[$key];
    }

    function getDichotomousOptions($key)
    {
        return $this->indent . '1 = ' . $this->_likert_grp1[$key] . '<br>' . $this->indent . '3 = ' . $this->_likert_grp3[$key];
    }

    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        $scores['score_validity'] = null;

        //null scores
        $this->_nullScores($this->scoreLabels);

        //get the saved scores
        $db     =& Database::singleton();
        $query  = "SELECT * FROM $this->table WHERE CommentID = '$this->commentID'";
        $record = $db->pselectRow($query, array());

        $likert_response_array = array(
                                  $record['q1_speech_likert'],
                                  $record['q2_eye_contact_likert'],
                                  $record['q3_vocalizations_likert'],
                                  $record['q4_play_likert'],
                                  $record['q5_body_movements_likert'],
                                  $record['q6_gestures_likert'],
                                  $record['q7_sensory_likert'],
                                 );

        $dichotomous_response_array = array(
                                       $record['q1_speech_dichotomous'],
                                       $record['q2_eye_contact_dichotomous'],
                                       $record['q3_vocalizations_dichotomous'],
                                       $record['q4_play_dichotomous'],
                                       $record['q5_body_movements_dichotomous'],
                                       $record['q6_gestures_dichotomous'],
                                       $record['q7_sensory_dichotomous'],
                                      );

        $scores = array();

        $scores['likert_total_score']      = $this->calculateTotalLikertScore($likert_response_array);
        $scores['dichotomous_total_score'] = $this->calculateTotalDichotomousScore($dichotomous_response_array);

        $result = $db->update($this->table, $scores, array('CommentID' => $this->getCommentID()));
    }

    function calculateTotalLikertScore($responses)
    {
        $score = 0;

        // $value is the question's answer
        foreach ($responses as $value) {
            switch ($value) {
            case 1:
                $score += 1;
                break;
            case 2:
                $score += 2;
                break;
            case 3:
                $score += 3;
                break;
            default:
                break; // do nothing
            }
        }

        return $score;
    }

    function calculateTotalDichotomousScore($responses)
    {
        $score = 0;

        // $value is the question's answer
        foreach ($responses as $value) {
            switch ($value) {
            case 1:
                $score += 1;
                break;
            case 3:
                $score += 3;
                break;
            default:
                break; // do nothing
            }
        }

        return $score;
    }
    function validate_page1($values)
    {
        $errors = [];

        $this->validate_child_age($values, "child_age", $errors);

        return $errors;
    }
}
?>