<?php
/*
 * This file contains the NDB_BVL_Instrument_Mock_Scanner_Training_Version_2
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
 * Creates the form elements for the Mock_Scanner_Training_Version_2 instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

const YES_NO = array(null => "", "Yes" => "Yes", "No" => "No");


class NDB_BVL_Instrument_Mock_Scanner_Training_Version_2 extends NDB_BVL_Instrument
{

    use LegacyInstrumentTrait;

    var $ValidityEnabled = false;

    var $ValidityRequired = false;

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     *
     * @return void
     */

    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {

        $this->formType = 'XIN';
        $this->form = new LorisForm('Mock_Scanner_Training_Version_2');
        $this->page = $page;
        $this->testName = 'Mock_Scanner_Training_Version_2';
        $this->table = $this->testName;

        $this->commentID = $commentID;

        // The array of dates/timestamps to convert to database dates/timestamps
        // All LorisForm date elements must be listed here
        $this->dateTimeFields = array(
            "Date_taken",
            "mock_time",
            "session_date_1_date",
            "session_date_2_date",
            "session_date_3_date",
            "session_date_4_date",
            "session_date_5_date",
            "session_date_6_date",
            "total_session_duration_1",
            "total_session_duration_2",
            "total_session_duration_3",
            "total_session_duration_4",
            "total_session_duration_5",
            "total_session_duration_6",
            "break_duration_1",
            "break_duration_2",
            "break_duration_3",
            "break_duration_4",
            "break_duration_5",
            "break_duration_6"
        );

        $this->_selectMultipleElements = array(
            "bx_specialist_ppe_1",
            "bx_specialist_ppe_2",
            "bx_specialist_ppe_3",
            "bx_specialist_ppe_4",
            "bx_specialist_ppe_5",
            "bx_specialist_ppe_6"
        );

        // setup the form
        $this->_setupForm();

    }

    /**
     * Method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        //determine page to display
        if (preg_match(
            "/Mock_Scanner_Training_Version_2(_page[1-6]+)/",
            $this->page,
            $matches)
        ) {
            $this->pageNum = $matches[1];
            $this->_displayPage($matches[1]);
        } else {
            $this->pageNum = 0;
            $this->_main();
        }
        $this->form->addFormRule(array(&$this, 'mock_scanner_rules'));
    }


    function _main()
    {
        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $this->addHeader('Mock Scanner Training: IBIS School Age Project');
        $this->addRequiredSelect(
            'total_mock_sessions',
            'Total # of mock sessions:',
            array('' => NULL, 1 => 1, 2 => 2, 3 => 3, 4 => 4, 5 => 5, 6 => 6)
        );
        $totalMockSessions = $this->form->getValue('total_mock_sessions');
        $msg = '';
        if (!empty($totalMockSessions)) {
            if ($totalMockSessions == 1) {
                $msg = "Remember to only fill page 1 and leave the other pages empty.";
            } elseif ($totalMockSessions == 2) {
                $msg = "Remember to only fill page 1 and 2 and leave the other pages empty.";
            } elseif ($totalMockSessions != 6) {
                $msg = "Remember to only fill pages 1 through $totalMockSessions and leave the other pages empty.";
            } else {
                $msg = "Remember to fill all the pages, i.e. 1 through 6.";
            }
        }

        $this->form->addElement(
            'static',
            null,
            empty($msg) ? '' : "<font color='red'>*** $msg ***</font>"
        );

        $this->addHourMinElement('mock_time', 'Approximate total mock time: (hours:minutes)');
    }

    /**
     * Display a specific page of the instrument.
     *
     * @param string "_page$i" page number (1..6)
     */
    function _displayPage(string $pagei)
    {
        $i = (int)substr($pagei, -1);
        $this->addHeader("Session #: $i");
        $this->addDateElement("session_date_$i", 'Date');
        $this->addRequiredSelect(
            "total_session_staffs_$i",
            '# IBIS Staff present:',
            array("" => NULL, 1 => 1, 2 => 2, 3 => 3)
        );
        $this->addHourMinElement("total_session_duration_$i", 'Session Duration (hours:minutes)');
        $this->addTextElement("session_specialist_$i", 'Bx Specialist:');
        $this->addRequiredSelect(
            "medication_$i",
            'Subject medication taken today?',
            YES_NO
        );
        $this->addTextAreaElement("medication_yes_$i", "{$this->indent}<i>Specify:</i>");
        $this->addRequiredSelect(
            "scan_attempt_$i",
            'Has a scan been attempted?',
            YES_NO
        );
        $this->addSelect(
            "scan_acquired_$i",
            'Any acquired?',
            array('' => NULL, 'Partial' => 'Partial', 'None' => 'None', 'NA' => 'NA')
        );
        $this->addRequiredSelect(
            "training_home_$i",
            'Did the subject do training at home?',
            YES_NO
        );

        //------------------------------//
        //   At home training tools     //
        //------------------------------//
        $this->addSubHeader('At Home Training Tools');
        $this->addYesNoSelect("tool_training_protocol_$i", 'Parent training Protocol');
        $this->addYesNoSelect("tool_story_board_$i", 'Visual story board');
        $this->addYesNoSelect("tool_social_story_$i", 'Social story');
        $this->addYesNoSelect("tool_site_video_$i", 'COVID MRI video');
        $this->addYesNoSelect("tool_generic_video_$i", 'Generic MRI video');
        $this->addYesNoSelect("tool_body_awareness_video_$i", 'Body awareness video');

        //-----------------------------------------//
        //   Reinforcers used during visit         //
        // Answers to these questions are optional //
        //-----------------------------------------//
        $this->addSubHeader('Reinforcers used During Visit');
        $this->addYesNoSelect("reinforcer_preferred_treat_$i", 'Preferred edible treat');
        $this->addYesNoSelect("reinforcer_generic_treat_$i", 'Generic edible treat');
        $this->addYesNoSelect("reinforcer_prize_$i", 'Tangible prize');
        $this->addYesNoSelect("reinforcer_social_reinforcer_$i", 'Social reinforcer');
        $this->addYesNoSelect("reinforcer_delayed_reinforcer_$i", 'Delayed reinforcer');
        $this->addYesNoSelect("reinforcer_verbal_praise_$i", 'Verbal praise');
        $this->addYesNoSelect("reinforcer_sb_$i", 'Sensory bin');
        $this->addYesNoSelect("reinforcer_spin_office_chair_$i", 'Spin in office chair');

        //-------------------------------------//
        //   Bx strategies used during visits  //
        //-------------------------------------//
        $this->addSubHeader('Bx Strategies used During Visits');
        $this->addYesNoSelect("bx_strategies_{$i}_wb", 'Weighted Blanket');
        $this->addYesNoSelect("bx_strategies_{$i}_motion_sensor", 'Motion Sensor/Pause');
        $this->addYesNoSelect("bx_strategies_{$i}_pref_video", 'Preferred Video/movie?');
        $this->addYesNoSelect("bx_strategies_{$i}_verb_reminders", 'Verbal Reminders');
        $this->addYesNoSelect("bx_strategies_{$i}_mod_sibling", 'Model on Parent, Sibling, etc.');
        $this->addYesNoSelect("bx_strategies_{$i}_increase_sound", 'Increase Scanner Sounds Slowly');
        $this->addYesNoSelect("bx_strategies_{$i}_listen_music", 'Listen to Music?');
        $this->addYesNoSelect("bx_strategies_{$i}_body_awareness_video", 'Body Awareness Photo/Video');
        $this->addYesNoSelect("bx_strategies_{$i}_competition", 'Competition');
        $this->addYesNoSelect("bx_strategies_{$i}_face_camera", 'Face Camera in Bore');
        $this->addYesNoSelect("bx_strategies_{$i}_fsv", 'First/Then Statements/Visuals');
        $this->addYesNoSelect("bx_strategies_{$i}_generic_power_card", 'Generic Power Card');
        $this->addYesNoSelect("bx_strategies_{$i}_token_board", 'Generic Token Board');
        $this->addYesNoSelect("bx_strategies_{$i}_power_cards_pref", 'Power Card with preferred character');
        $this->addYesNoSelect("bx_strategies_{$i}_shaping", 'Shaping');
        $this->addYesNoSelect("bx_strategies_{$i}_social_story", 'Social story');
        $this->addYesNoSelect("bx_strategies_{$i}_dance_game", 'Stop/go dance game');
        $this->addYesNoSelect("bx_strategies_{$i}_token_board_pref", 'Token board with preferred character');
        $this->addYesNoSelect("bx_strategies_{$i}_vc", 'Verbal countdown');
        $this->addYesNoSelect("bx_strategies_{$i}_vsb", 'Visual story board');
        $this->addYesNoSelect("bx_strategies_{$i}_vt", 'Visual timer');
        $this->addYesNoSelect("bx_strategies_{$i}_simon_says", 'Simon says');

        $this->addSubHeader('Facade');
        $this->addRequiredSelect(
            "facade_type_$i",
            'Was a facade used on the scanner?',
            array('' => NULL, 'space' => 'Space', 'none' => 'None', 'other' => 'Other')
        );
        $this->addTextAreaElement("other_facade_$i", "{$this->indent}<i>Other:</i>");

        $this->addYesNoSelect("zoom_call_{$i}", 'Zoom call prior to mock scan?');
        $this->addYesNoSelect("parent_in_room_{$i}", 'Parent in the room?');
        $this->addRequiredSelect("bx_specialist_ppe_{$i}", 'Bx Specialist PPE', array(null => '', 'mask' => 'Mask', 'face_shield' => 'Face shield', 'capr' => 'CAPR', 'gown' => 'gown', 'scrubs' => 'scrubs'), ["multiple"]);
        $this->addYesNoSelect("subject_wearing_mask_{$i}", 'Subject wearing mask during scan?');
        $this->addYesNoSelect("subject_mask_breaks_{$i}", 'Subject given mask break(s)?');
        $this->addNumericElement("how_many_breaks_{$i}", 'How many?');
        $this->addHourMinElement("break_duration_{$i}", 'Total duration:');


        $this->form->addElement('static', null, "<br>");

        $this->addTextAreaElement("session_comments_$i", "Comments:");
    }

    /**
     * Adds a drop down list with possible answers 'Yes' and 'No'.
     *
     * @param string $field Name of the form field.
     * @param string $text Text for this select field.
     */
    function addYesNoSelect(string $field, string $text)
    {
        $this->addSelect($field, $text, YES_NO);
    }

    /**
     * Adds a mandatory select field.
     *
     * @param string $field Name of the form field.
     * @param string $text Text for this field.
     * @param array $options Possible choices for the select field.
     * @param array|null $attr Optional attributes
     * @throws LorisException
     */
    function addRequiredSelect(string $field, string $text, array $options, array $attr = null)
    {
        if ($attr == null)
            $this->addSelect($field, $text, $options);
        else $this->addSelect($field, $text, $options, $attr);
        $this->form->addRule($field, 'Required.', 'required');
    }

    /**
     * Adds a sub-header to the form.
     *
     * @param string $subHeader Sub-header text.
     */
    function addSubHeader(string $subHeader)
    {
        $this->form->addElement('static', null, "<h3>$subHeader</h3>");
    }

    /**
     * Validates the data on one of the pages of the instrument.
     *
     * @param array values Data entered on the page.
     *
     * @return array the validation errors found.
     */
    function mock_scanner_rules(?array $values)
    {
        $i = $this->pageNum;
        $p = (int)substr($i, -1);

        $errors = array();

        //==================================//
        //                                  //
        // Main (top) page data validation  //
        //                                  //
        //==================================//

        if ($p == 0) {
            if (array_key_exists('total_mock_sessions', $values)
                && empty($values['total_mock_sessions'])
            ) {
                $errors['total_mock_sessions'] = "Required";
            }

            if (array_key_exists('mock_time', $values)) {
                if (empty($values['mock_time']) && empty($values['mock_time_status'])) {
                    $errors['mock_time_group'] = "Required";
                }
            }

            return $errors;
        }

        //====================================//
        //                                    //
        // Data validation for page $p (1..6) //
        //                                    //
        //====================================//

        if (empty($values["session_date_{$p}_date"]) && empty($values["session_date_{$p}_date_status"])) {
            $errors["session_date_{$p}_date_group"] = "Required";
        }

        //---------------------------------------------//
        // Validation of the session duration          //
        //---------------------------------------------//
        if (array_key_exists("total_session_duration_$p", $values)) {
            if (empty($values["total_session_duration_$p"])
                && empty($values["total_session_duration_{$p}_status"])
            ) {
                $errors["total_session_duration_{$p}_group"] = "Required";
            }
        }

        //------------------------------------//
        // Validation of the medication       //
        //------------------------------------//
        if ($values["medication_$p"] == 'Yes') {
            if (empty($values["medication_yes_$p"]) && empty($values["medication_yes_{$p}_status"])) {
                $errors["medication_yes_{$p}_group"] =
                    "You must answer this question since you answered 'Yes' above";
            }
        } else {
            if (!empty($values["medication_yes_$p"]) || !empty($values["medication_yes_{$p}_status"])) {
                $errors["medication_yes_{$p}_group"] =
                    "You must leave this line empty since you did not answer 'Yes' above";
            }
        }

        //---------------------------------------------//
        // Validation of the scan attempt/acquired     //
        //---------------------------------------------//
        if ($values["scan_attempt_$p"] == 'Yes') {
            if (empty($values["scan_acquired_$p"])) {
                $errors["scan_acquired_$p"] =
                    "You must answer this question since you answered 'Yes' to the previous question";
            }
        } else {
            if (!empty($values["scan_acquired_$p"])) {
                $errors["scan_acquired_$p"] =
                    "You must leave this field empty since you did not answer 'Yes' to the previous question";
            }
        }

        //--------------------------------------------//
        // Validation of the training at home section //
        //--------------------------------------------//
        $questions = array(
            'tool_training_protocol', 'tool_story_board', 'tool_social_story',
            'tool_site_video', 'tool_generic_video', 'tool_body_awareness_video'
        );
        if ($values["training_home_$p"] == 'Yes') {
            $hasAYes = false;
            foreach ($questions as $q) {
                if (!empty($values["{$q}_$p"]) && $values["{$q}_$p"] == 'Yes') {
                    $hasAYes = true;
                    break;
                }
            }

            if (!$hasAYes && empty($values["tool_other_$p"])) {
                $errors["training_home_$p"] =
                    'You must specify at least one training tool used at home (below)';
            }
        } else {
            foreach ($questions as $q) {
                if (!empty($values["{$q}_$p"])) {
                    $errors["{$q}_$p"] =
                        'You must leave this field empty since you indicated that no training at home was done';
                }
            }

            if (!empty($values["tool_other_$p"])) {
                $errors["tool_other_$p"] =
                    'You must leave this field empty since you indicated that no training at home was done';
            }
        }

        //-------------------------------------//
        // Validation of the facade section    //
        //-------------------------------------//
        if (!empty($values["facade_type_$p"]) && $values["facade_type_$p"] != 'other') {
            if (!empty($values["other_facade_$p"]) || !empty($values["other_facade_{$p}_status"])) {
                $errors["other_facade_{$p}_group"] =
                    "You must leave this line empty since you did not answer 'Other' above";
            }
        } elseif (empty($values["other_facade_$p"]) && empty($values["other_facade_{$p}_status"])) {
            $errors["other_facade_{$p}_group"] =
                "Please specify what type of facade what used";
        }

        //-------------------------------------//
        // Validation of the mask breaks       //
        //-------------------------------------//
        if (!empty($values["subject_mask_breaks_$p"]) && $values["subject_mask_breaks_$p"] == 'no') {
            if (!empty($values["how_many_breaks_$p"]) || !empty($values["how_many_breaks_{$p}_status"])) {
                $errors["how_many_breaks_{$p}_group"] =
                    "You must leave this line empty since you did not answer 'Yes' above";
            }
            if (!empty($values["break_duration_$p"]) || !empty($values["break_duration_{$p}_status"])) {
                $errors["break_duration_{$p}_group"] =
                    "You must leave this line empty since you did not answer 'Yes' above";
            }
        } elseif (!empty($values["subject_mask_breaks_$p"]) && $values["subject_mask_breaks_$p"] == 'Yes') {
            if (empty($values["how_many_breaks_$p"]) || empty($values["how_many_breaks_{$p}_status"])) {
                $errors["how_many_breaks_{$p}_group"] =
                    "You must fill this line since you answered 'Yes' above";
            }
            if (empty($values["break_duration_$p"]) || empty($values["break_duration_{$p}_status"])) {
                $errors["break_duration_{$p}_group"] =
                    "You must fill this line since you answered 'Yes' above";
            }
        }

        return $errors;
    }
}

?>

