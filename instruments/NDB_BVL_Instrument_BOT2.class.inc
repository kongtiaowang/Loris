<?php
/**
 * This file contains the NDB_BVL_Instrument_BOT2 class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Main
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the BOT2 instrument
 *
 * @category Instrument
 * @package  Main
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_BOT2 extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names(Test_name, Full_name,Sub_group,isDirectEntry) VALUES ('<TEST_NAME>','<INSTRUMENT_TITLE>',1, false);
     * INSERT INTO instrument_subtests(Test_name, Subtest_name, Description, Order_number) VALUES('<TEST_NAME>', '<TEST_NAME>_page1', 'Page1', 1);
     */

    /**
     * Sets up basic data, such as the HTML_Quickform object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     *
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = "XIN";
        $this->form = new LorisForm('BOT2_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "BOT2";           // test_names.Test_name
        $this->table = 'BOT2';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
            'Examiner',
        );

        // setup the form
        $this->_setupForm();

    }

    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

    /**
     * Method to build the HTML_Quickform object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        if (preg_match("/BOT2(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    /**
     * Generates the main page of the form.
     *
     * @return void
     * @access private
     */
    function _main() {
        // display test name
        $this->addHeader("BOT 2: Bruininks-Oseretsky Test of Motor Proficiency, <i>Second Edition</i>");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
        $this->addSelect(
            "preferred_drawing_hand",
            "Preferred Drawing Hand:",
            array(null => "", "right" => "Right", "left" => "Left"));
        $this->addSelect(
            "preferred_throwing_hand_arm",
            "Preferred Throwing Hand/Arm:",
            array(null => "", "right" => "Right", "left" => "Left"));
        $this->addSelect(
            "preferred_foot_leg",
            "Preferred Foot/Leg:",
            array(null => "", "right" => "Right", "left" => "Left"));
        $this->addBasicText("examinee_school", "School/Clinic:");
    }

    function displayHeaders($message, $subtest_number) {
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<i>$message</i>"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Raw Score: Trial 1"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Raw Score: Trial 2"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Point Score"
        );
        $this->form->addGroup(
            $group,
            "subtest_ . $subtest_number . _headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
    }

    function _page1() {
        // page1

        $this->addHeader("<h3>Subtest I: Fine Motor Precision</h3>");
        // add headers
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            ""
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Raw Score"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Point Score"
        );
        $this->form->addGroup(
            $group,
            "subtest_1_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        $fine_motor_prediction_categories =
            array(
                "subtest_1_1" => "1. Filling in Shapes - Circles",
                "subtest_1_2" => "2. Filling in Shapes - Star",
                "subtest_1_3" => "3. Drawing Lines through Paths - Crooked",
                "subtest_1_4" => "4. Drawing Lines through Paths - Curved",
                "subtest_1_5" => "5. Connecting Dots",
                "subtest_1_6" => "6. Folding Paper",
                "subtest_1_7" => "7. Cutting Out a Circle");

        foreach($fine_motor_prediction_categories as $key => $category) {
            $group[] =& $this->createLabel($category);
            $group[] =& $this->createText($key . "_raw_score", "");
            $group[] =& $this->createText($key . "_point_score", "");
            $this->form->addGroup(
                $group,
                $key . "_answers",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }


        // Subtest 2

        $this->addLabel("<h3>Subtest II: Fine Motor Precision</h3>");
        // add headers
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<i>For each item, if the Basic Shape facet is scored 0, 
             then all remaining facets and the total score for that item must
             also be scored 0."
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Basic Shape"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Closure"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Edges"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Orientation"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Overlap"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Overall Size"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Raw Score"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Point Score"
        );
        $this->form->addGroup(
            $group,
            "subtest_2_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        $subtest_2_questions =
            array(
                "subtest_2_1" => "1. Copying a Circle",
                "subtest_2_2" => "2. Copying a Square",
                "subtest_2_3" => "3. Copying Overlapping Circles",
                "subtest_2_4" => "4. Copying a Wavy Line",
                "subtest_2_5" => "5. Copying a Triangle",
                "subtest_2_6" => "6. Copying a Diamond",
                "subtest_2_7" => "7. Copying a Star",
                "subtest_2_8" => "8. Copying Overlapping Pencils"
            );

        $subtest_2_options =
            array(
                null => "",
                0 => 0,
                1 => 1
            );

        foreach ($subtest_2_questions as $key=>$category) {
            if ($key == "subtest_2_1") {
                $group[] =& $this->createLabel($category);
                $group[] =& $this->createSelect($key . "_basic_shape", "", $subtest_2_options, array('size' => 4, 'maxlength' => 4));
                $group[] =& $this->createSelect($key . "_closure", "", $subtest_2_options, array('size' => 4, 'maxlength' => 4));
                $group[] =& $this->createSelect($key . "_edges", "", $subtest_2_options, array('size' => 4, 'maxlength' => 4));
                $group[] =& $this->form->createElement("static", null, null, "", array('size' => 4, 'maxlength' => 4));
                $group[] =& $this->form->createElement("static", null, null, "", array('size' => 4, 'maxlength' => 4));
                $group[] =& $this->createSelect($key . "_overall_size", "", $subtest_2_options, array('size' => 4, 'maxlength' => 4));
                $group[] =& $this->createText($key . "_raw_score", "", array('size' => 4, 'maxlength' => 4));
                $group[] =& $this->createText($key . "_point_score", "", array('size' => 4, 'maxlength' => 4));
            } elseif ($key == "subtest_2_2" || $key == "subtest_2_5" ||
                $key == "subtest_2_6" || $key == "subtest_2_7") {
                $group[] =& $this->createLabel($category);
                $group[] =& $this->createSelect($key . "_basic_shape", "", $subtest_2_options);
                $group[] =& $this->createSelect($key . "_closure", "", $subtest_2_options);
                $group[] =& $this->createSelect($key . "_edges", "", $subtest_2_options);
                $group[] =& $this->createSelect($key . "_orientation", "", $subtest_2_options);
                $group[] =& $this->form->createElement("static", null, null, "");
                $group[] =& $this->createSelect($key . "_overall_size", "", $subtest_2_options);
                $group[] =& $this->createText($key . "_raw_score", "");
                $group[] =& $this->createText($key . "_point_score", "");
            } elseif ($key == "subtest_2_4") {
                $group[] =& $this->createLabel($category);
                $group[] =& $this->createSelect($key . "_basic_shape", "", $subtest_2_options);
                $group[] =& $this->form->createElement("static", null, null, "");
                $group[] =& $this->createSelect($key . "_edges", "", $subtest_2_options);
                $group[] =& $this->createSelect($key . "_orientation", "", $subtest_2_options);
                $group[] =& $this->form->createElement("static", null, null, "");
                $group[] =& $this->createSelect($key . "_overall_size", "", $subtest_2_options);
                $group[] =& $this->createText($key . "_raw_score", "");
                $group[] =& $this->createText($key . "_point_score", "");
            } else {
                $group[] =& $this->createLabel($category);
                $group[] =& $this->createSelect($key . "_basic_shape", "", $subtest_2_options);
                $group[] =& $this->createSelect($key . "_closure", "", $subtest_2_options);
                $group[] =& $this->createSelect($key . "_edges", "", $subtest_2_options);
                $group[] =& $this->createSelect($key . "_orientation", "", $subtest_2_options);
                $group[] =& $this->createSelect($key . "_overlap", "", $subtest_2_options);
                $group[] =& $this->createSelect($key . "_overall_size", "", $subtest_2_options);
                $group[] =& $this->createText($key . "_raw_score", "");
                $group[] =& $this->createText($key . "_point_score", "");
            }
            $this->form->addGroup(
                $group,
                $key . "_answers",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }


    }

    function _page2() {
        $this->addLabel("<h3>Subtest 3: Manual Dexterity</h3>");
        $this->displayHeaders("For items 2 through 5, always conduct the second trial.",3);
        $subtest_3_questions =
            array(
                "subtest_3_1" => "1. Making Dots in Circle",
                "subtest_3_2" => "2. Transferring Pennies",
                "subtest_3_3" => "3. Placing Pegs into Pegboard",
                "subtest_3_4" => "4. Sorting Cards",
                "subtest_3_5" => "5. Stringing Blocks"
            );

        foreach ($subtest_3_questions as $key=>$category) {
            $group[] =& $this->createLabel($category);
            if ($key == "subtest_3_1") {
                $group[] =& $this->createText($key . "_trial1", "Circles:");
                $group[] =& $this->form->createElement("static", null, null, "");
                $group[] =& $this->createText($key . "_point_score");
            } elseif ($key == "subtest_3_2") {
                $group[] =& $this->createText($key . "_trial1", "Pennies:");
                $group[] =& $this->createText($key . "_trial2", "Pennies:");
                $group[] =& $this->createText($key . "_point_score", "");
            } elseif ($key == "subtest_3_3") {
                $group[] =& $this->createText($key . "_trial1", "Pegs:");
                $group[] =& $this->createText($key . "_trial2", "Pegs:");
                $group[] =& $this->createText($key . "_point_score", "");
            } elseif ($key == "subtest_3_4") {
                $group[] =& $this->createText($key . "_trial1", "Cards:");
                $group[] =& $this->createText($key . "_trial2", "Cards:");
                $group[] =& $this->createText($key . "_point_score", "");
            } else {
                $group[] =& $this->createText($key . "_trial1", "Blocks:");
                $group[] =& $this->createText($key . "_trial2", "Blocks:");
                $group[] =& $this->createText($key . "_point_score", "");
            }
            $this->form->addGroup(
                $group,
                $key . "_answers",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }


        $this->addLabel("<h3>Subtest 4: Bilateral Coordination</h3>");
        $this->displayHeaders("Conduct the second trial only if the examinee does not earn the maximum score on the first trial.",4);

        $subtest_4_questions =
            array(
                "subtest_4_1" => "1. Touching Nose with Index Fingers - Eyes Closed",
                "subtest_4_2" => "2. Jumping Jacks",
                "subtest_4_3" => "3. Jumping in Place - Same Sides Synchronized",
                "subtest_4_4" => "4. Jumping in Place - Opposite Sides Synchronized",
                "subtest_4_5" => "5. Pivoting Thumbs and Index Fingers",
                "subtest_4_6" => "6. Tapping Feet and Fingers - Same Sides Synchronized",
                "subtest_4_7" => "7. Tapping Feet and Fingers - Opposite Sides Synchronized"
            );

       /* function subtest_4_depencies($key, $max_value) {
            $key_trial1 = $key . "_trial1";
            $this->XINRegisterRule(
                $key . "_trial1",
                array("{$key_trial1}{@}!={@}{$max_value}"),
                "Required if the maximum score is not earned on the first trial",
                $key . "_rule");
        } */

        foreach ($subtest_4_questions as $key=>$category) {
            $group[] =& $this->createLabel($category);
            $key_trial1 = $key . "_trial1";
            if ($key == "subtest_4_1") {
                $group[] =& $this->createText($key . "_trial1", "touches:");
                $group[] =& $this->createText($key . "_trial2", "touches:");
                $group[] =& $this->createText($key . "_point_score");
                $this->XINRegisterRule(
                    $key . "_trial2",
                    array("{$key_trial1}{@}!={@}4"),
                    "Required if the maximum score is not earned on the first trial",
                    $key . "_rule");
            } elseif ($key == "subtest_4_2") {
                $group[] =& $this->createText($key . "_trial1", "jumping jacks:");
                $group[] =& $this->createText($key . "_trial2", "jumping jacks:");
                $group[] =& $this->createText($key . "_point_score", "");
                $this->XINRegisterRule(
                    $key . "_trial2",
                    array("{$key_trial1}{@}!={@}5"),
                    "Required if the maximum score is not earned on the first trial",
                    $key . "_rule");
            } elseif ($key == "subtest_4_3" || $key == "subtest_4_4") {
                $group[] =& $this->createText($key . "_trial1", "jumps:");
                $group[] =& $this->createText($key . "_trial2", "jumps:");
                $group[] =& $this->createText($key . "_point_score", "");
                $this->XINRegisterRule(
                    $key . "_trial2",
                    array("{$key_trial1}{@}!={@}5"),
                    "Required if the maximum score is not earned on the first trial",
                    $key . "_rule");
            } elseif ($key == "subtest_4_5") {
                $group[] =& $this->createText($key . "_trial1", "pivots:");
                $group[] =& $this->createText($key . "_trial2", "pivots:");
                $group[] =& $this->createText($key . "_point_score", "");
                $this->XINRegisterRule(
                    $key . "_trial2",
                    array("{$key_trial1}{@}!={@}5"),
                    "Required if the maximum score is not earned on the first trial",
                    $key . "_rule");
            } else {
                $group[] =& $this->createText($key . "_trial1", "taps:");
                $group[] =& $this->createText($key . "_trial2", "taps:");
                $group[] =& $this->createText($key . "_point_score", "");
                $this->XINRegisterRule(
                    $key . "_trial2",
                    array("{$key_trial1}{@}!={@}10"),
                    "Required if the maximum score is not earned on the first trial",
                    $key . "_rule");
            }
            $this->form->addGroup(
                $group,
                $key . "_answers",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
    }

    function _page3() {
        $this->addLabel("<h3>Subtest 5: Balance</h3>");
        $this->displayHeaders("Conduct the second trial only if the examinee does not earn the maximum score on the first trial.",5);
        $subtest_5_questions =
            array(
                "subtest_5_1" => "1. Standing with Feet Apart On a Line - Eyes Open",
                "subtest_5_2" => "2. Walking Forward on a Line",
                "subtest_5_3" => "3. Standing on One Leg on a Line - Eyes Open",
                "subtest_5_4" => "4. Standing with Feet Apart on a Line",
                "subtest_5_5" => "5. Walking Forward Heel-to-Toe on a Line",
                "subtest_5_6" => "6. Standing on One Leg on a Line - Eyes Closed",
                "subtest_5_7" => "7. Standing on One Leg on a Balance Beam - Eyes Open",
                "subtest_5_8" => "8. Standing Heel-to-Toe on a Balance Beam",
                "subtest_5_9" => "9. Standing on One Leg on a Balance Beam - Eyes Closed"
            );

        foreach ($subtest_5_questions as $key=>$category) {
            $group[] =& $this->createLabel($category);
            if ($key == "subtest_5_2" || $key == "subtest_5_5") {
                $group[] =& $this->createText($key . "_trial1", "steps:");
                $group[] =& $this->createText($key . "_trial2", "steps:");
            } else {
                $group[] =& $this->createText($key . "_trial1", "seconds:");
                $group[] =& $this->createText($key . "_trial2", "seconds:");
            }
            $group[] =& $this->createText($key . "_point_score", "");
            $this->form->addGroup(
                $group,
                $key . "_answers",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->addLabel("<h3>Subtest 6: Running Speed and Agility</h3>");
        $this->displayHeaders("Conduct the second trial only if the examinee stumbles or falls on the first trial.",6);
        $subtest_6_questions =
            array(
                "subtest_6_1" => "1. Shuttle Run",
                "subtest_6_2" => "2. Stepping Sideways over a Balance Beam",
                "subtest_6_3" => "3. One-Legged Stationary Hop",
                "subtest_6_4" => "4. One-Legged Side Hop",
                "subtest_6_5" => "5. Two-Legged Side Hop"
            );
        foreach ($subtest_6_questions as $key=>$category) {
            $group[] =& $this->createLabel($category);
            if ($key == "subtest_6_1") {
                $group[] =& $this->createText($key . "_trial1", "seconds:");
                $group[] =& $this->createText($key . "_trial2", "seconds:");
            } elseif ($key == "subtest_6_2") {
                $group[] =& $this->createText($key . "_trial1", "steps:");
                $group[] =& $this->createText($key . "_trial2", "steps:");
            } else {
                $group[] =& $this->createText($key . "_trial1", "hops:");
                $group[] =& $this->createText($key . "_trial2", "hops:");
            }
            $group[] =& $this->createText($key . "_point_score", "");
            $this->form->addGroup(
                $group,
                $key . "_answers",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
    }

    function _page4() {
        $this->addLabel("<h3>Subtest 7: Upper-Limb Coordination</h3>");
        $this->displayHeaders("For Items 5 and 6, conduct the second trial only if the examinee does not earn the maximum score on the first trial.",7);
        $subtest_7_questions =
            array(
                "subtest_7_1" => "1. Dropping and Catching a Ball - Both Hands",
                "subtest_7_2" => "2. Catching a Tossed Ball - B",
                "subtest_7_3" => "3. Dropping and Catching a Ball - One Hand",
                "subtest_7_4" => "4. Catching a Tossed Ball - One Hand",
                "subtest_7_5" => "5. Dribbling a Ball - One Hand",
                "subtest_7_6" => "6. Dribbling a Ball - Alternating Hands",
                "subtest_7_7" => "7. Throwing a Ball at a Target"
            );
        foreach($subtest_7_questions as $key=>$category) {
            $group[] =& $this->createLabel($category);
            if ($key == "subtest_7_5" || $key == "subtest_7_6") {
                $group[] =& $this->createText($key . "_trial1", "dribbles:");
                $group[] =& $this->createText($key . "_trial2", "dribbles:");
            } elseif ($key == "subtest_7_7") {
                $group[] =& $this->createText($key . "_trial1", "throws:");
                $group[] =& $this->form->createElement("static", null, null, "");
            } else {
                $group[] =& $this->createText($key . "_trial1", "catches:");
                $group[] =& $this->form->createElement("static", null, null, "");
            }
            $group[] =& $this->createText($key . "_point_score", "");
            $this->form->addGroup(
                $group,
                $key . "_answers",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->addLabel("<h3>Subtest 8: Strength</h3>");
        $this->displayHeaders("For item 1, conduct the second trial only if the examinee stumbles or falls on the first trial.",8);
        $subtest_8_questions =
            array(
                "subtest_8_1" => "1. Standing Long Jump",
                "subtest_8_2" => "2. Select one.",
                "subtest_8_3" => "3. Sit-ups",
                "subtest_8_4" => "4. Wall Sit",
                "subtest_8_5" => "5. V-up"
            );

        foreach ($subtest_8_questions as $key=>$category) {
            if ($key == "subtest_8_1") {
                $group[] =& $this->createLabel($category);
                $group[] =& $this->createText($key . "_trial1", "inches:");
                $group[] =& $this->createText($key . "_trial2", "inches:");
            } elseif ($key == "subtest_8_2") {
                $group[] =& $this->form->createSelect($key . "type", $category, array("knee" => "2a. Knee Push-ups", "full" => "2b. Full Push-ups"));
                $group[] =& $this->createText($key . "_trial1", "push-ups:");
                $group[] =& $this->form->createElement("static", null, null, "");
            } elseif ($key == "subtest_8_3") {
                $group[] =& $this->createLabel($category);
                $group[] =& $this->createText($key . "_trial1", "sit-ups:");
                $group[] =& $this->form->createElement("static", null, null, "");
            } else {
                $group[] =& $this->createLabel($category);
                $group[] =& $this->createText($key . "_trial1", "seconds:");
                $group[] =& $this->form->createElement("static", null, null, "");
            }
            $group[] =& $this->createText($key . "_point_score", "");
            $this->form->addGroup(
                $group,
                $key . "_answers",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
    }

    function _score() {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        //null scores
        $this->_nullScores($this->scoreLabels);

        //get the saved scores
        $db = Database::singleton();


        $record= $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid",array("cid" =>$this->getCommentID() ) );

        // Get gender
        $record_gender= $db->pselectRow("SELECT Sex FROM candidate as c, session as s, flag as f, $this->table as
 t WHERE t.CommentID = CommentID=:cid AND f.CommentID=t.CommentID AND s.ID=f.SessionID AND s.CandID=c.CandID",array("cid" =>$this->getCommentID()));
        $gender = strtolower($record_gender['Gender']);

        // Get the subject age in months for scoring
        $timepoint = TimePoint::singleton($this->getSessionID());
        $dob = $timepoint->getEffectiveDateOfBirth();

        $age = Utility::calculateAge($dob, $record["Date_taken"]);
        $age_months = $age['year'] * 12 + $age['mon'];

        $scores = array();
        $scores['subtest_1_total_point_score'] = 0;
        for ($i=1; $i <= 7; $i++) {
            $scores['subtest_1_total_point_score'] += $record['subtest_1_' . $i . '_point_score'];
        }
        $scores['subtest_2'] = 0;
        for ($i=1; $i <= 8; $i++) {
            $scores['subtest_2_total_point_score'] += $record['subtest_2_' . $i . '_point_score'];
        }
        $scores['subtest_3'] = 0;
        for ($i=1; $i <= 5; $i++) {
            $scores['subtest_2_total_point_score'] += $record['subtest_3_' . $i . '_point_score'];
        }
        $scores['subtest_4'] = 0;
        for ($i=1; $i <= 7; $i++) {
            $scores['subtest_2_total_point_score'] += $record['subtest_4_' . $i . '_point_score'];
        }
        $scores['subtest_5'] = 0;
        for ($i=1; $i <= 9; $i++) {
            $scores['subtest_5_total_point_score'] += $record['subtest_5_' . $i . '_point_score'];
        }
        $scores['subtest_6'] = 0;
        for ($i=1; $i <= 5; $i++) {
            $scores['subtest_6_total_point_score'] += $record['subtest_6_' . $i . '_point_score'];
        }
        $scores['subtest_7'] = 0;
        for ($i=1; $i <= 7; $i++) {
            $scores['subtest_7_total_point_score'] += $record['subtest_7_' . $i . '_point_score'];
        }
        $scores['subtest_8'] = 0;
        for ($i=1; $i <= 5; $i++) {
            $scores['subtest_8_total_point_score'] += $record['subtest_8_' . $i . '_point_score'];
        }
    }

}
