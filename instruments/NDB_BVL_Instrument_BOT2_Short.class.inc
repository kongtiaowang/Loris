<?php
/**
 * This file contains the NDB_BVL_Instrument_BOT2_Short class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Main
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the BOT2 Short instrument
 *
 * @category Instrument
 * @package  Main
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_BOT2_Short extends NDB_BVL_Instrument
{
    use instrument_validator;
    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names(Test_name, Full_name, Sub_Group) VALUES('BOT2_Short', "BOT2 SHORT FORM", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('BOT2_Short','BOT2_Short_page1', "Short Form", 1);
     * INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('BOT2_Short', '0', '0', 'Y', 'Visit', 1, 'V06', NULL);
     */

    /**
     * Sets up basic data, such as the HTML_Quickform object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page      if a multipage form, the page to show
     *
     * @return void
     * @access public
     */
    function setup($commentID, $page)
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('BOT2_Short_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "BOT2_Short";           // test_names.Test_name
        $this->table    = 'BOT2_Short';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    "Examiner",
                                    "subtest_1_3_raw_score",
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
        $db =& Database::singleton();
        // Get the item scores
        $query  = "SELECT * FROM $this->table WHERE CommentID='".$this->getCommentID()."'";
        $record =array();
        $db->selectRow($query, $record);

        if (preg_match("/BOT2_Short(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        // Defines the call back function for HTML Quickform to use when validating the form.
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
        // Display test name
        $this->addHeader("BOT 2 SHORT FORM: Bruininks-Oseretsky Test of Motor Proficiency, <i>Second Edition</i>");

        // Automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $this->addSelect(
            "preferred_drawing_hand",
            "Preferred Drawing Hand:",
            array(
             null    => "",
             "right" => "Right",
             "left"  => "Left",
            )
        );

        $this->addSelect(
            "preferred_throwing_hand_arm",
            "Preferred Throwing Hand/Arm:",
            array(
             null    => "",
             "right" => "Right",
             "left"  => "Left",
            )
        );

        $this->addSelect(
            "preferred_foot_leg",
            "Preferred Foot/Leg:",
            array(
             null    => "",
             "right" => "Right",
             "left"  => "Left",
            )
        );

        $this->addBasicText("examinee_school", "School/Clinic:");
    }

    function displayHeaders($message, $subtest_number)
    {
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

    /**
    * Generates the first page of the form.
     *
    * @return void
    */
    function _page1()
    {
        $this->addHeader("BOT 2 SHORT FORM: Bruininks-Oseretsky Test of Motor Proficiency, <i>Second Edition</i>");

        $this->addHeader("<h3>Subtest 1: Fine Motor Precision</h3>");

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

        $subtest_1_questions = array(
                                "subtest_1_3" => "3. Drawing Lines through Paths - Crooked",
                                "subtest_1_6" => "6. Folding Paper",
                               );

        $subtest_1_options = array(
                              null => "",
                              0    => 0,
                              1    => 1,
                              2    => 2,
                              3    => 3,
                              4    => 4,
                              5    => 5,
                              6    => 6,
                              7    => 7,
                             );

        foreach ($subtest_1_questions as $key => $category) {
            $group[] =& $this->createLabel($category);
            $group[] =& $this->createText($key . "_raw_score", "");
            $group[] =& $this->createSelect($key . "_point_score", "", $subtest_1_options);

            $this->form->addGroup(
                $group,
                $key . "_answers",
                null,
                $this->_GUIDelimiter,
                false
            );

            unset($group);
        }

        $this->addLabel("<h3>Subtest 2: Fine Motor Integration</h3>");

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

        $subtest_2_questions = array(
                                "subtest_2_2" => "2. Copying a Square",
                                "subtest_2_7" => "7. Copying a Star",
                               );

        $subtest_2_options = array(
                              null => "",
                              0    => 0,
                              1    => 1,
                             );

        foreach ($subtest_2_questions as $key => $category) {
            $group[] =& $this->createLabel($category);
            $group[] =& $this->createSelect($key . "_basic_shape", "", $subtest_2_options);
            $group[] =& $this->createSelect($key . "_closure", "", $subtest_2_options);
            $group[] =& $this->createSelect($key . "_edges", "", $subtest_2_options);
            $group[] =& $this->createSelect($key . "_orientation", "", $subtest_2_options);
            $group[] =& $this->form->createElement("static", null, null, "");
            $group[] =& $this->createSelect($key . "_overall_size", "", $subtest_2_options);
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

        $this->addLabel("<h3>Subtest 3: Manual Dexterity</h3>");

        $this->displayHeaders("For item 2, always conduct the second trial.", 3);

        $subtest_3_questions = array("subtest_3_2" => "2. Transferring Pennies");

        $subtest_3_and_8_options = array(
                                    null => "",
                                    0    => 0,
                                    1    => 1,
                                    2    => 2,
                                    3    => 3,
                                    4    => 4,
                                    5    => 5,
                                    6    => 6,
                                    7    => 7,
                                    8    => 8,
                                    9    => 9,
                                   );

        foreach ($subtest_3_questions as $key=>$category) {
            $group[] =& $this->createLabel($category);
            $group[] =& $this->createText($key . "_trial1", "Pennies:");
            $group[] =& $this->createText($key . "_trial2", "Pennies:");
            $group[] =& $this->createSelect($key . "_point_score", "", $subtest_3_and_8_options);

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

        $this->displayHeaders("Conduct the second trial only if the examinee does not earn the maximum score on the first trial.", 4);

        $subtest_4_questions = array(
                                "subtest_4_3" => "3. Jumping in Place - Same Sides Synchronized",
                                "subtest_4_6" => "6. Tapping Feet and Fingers - Same Sides Synchronized",
                               );

        $subtest_4_3_options = array(
                                null => "",
                                0    => 0,
                                1    => 1,
                                2    => 2,
                                3    => 3,
                               );

        $subtest_4_6_options = array(
                                null => "",
                                0    => 0,
                                1    => 1,
                                2    => 2,
                                3    => 3,
                                4    => 4,
                               );

        foreach ($subtest_4_questions as $key => $category) {
            $group[] =& $this->createLabel($category);

            $key_trial1 = $key . "_trial1";

            if ($key == "subtest_4_3") {
                $group[] =& $this->createText($key . "_trial1", "jumps:");
                $group[] =& $this->createText($key . "_trial2", "jumps:");
                $group[] =& $this->createSelect($key . "_point_score", "", $subtest_4_3_options);

                $this->XINRegisterRule(
                    $key . "_trial2",
                    array("{$key_trial1}{@}!={@}5"),
                    "Required if the maximum score is not earned on the first trial",
                    $key . "_rule"
                );
            } else {
                $group[] =& $this->createText($key . "_trial1", "taps:");
                $group[] =& $this->createText($key . "_trial2", "taps:");
                $group[] =& $this->createSelect($key . "_point_score", "", $subtest_4_6_options);

                $this->XINRegisterRule(
                    $key . "_trial2",
                    array("{$key_trial1}{@}!={@}10"),
                    "Required if the maximum score is not earned on the first trial",
                    $key . "_rule"
                );
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

        $this->addLabel("<h3>Subtest 5: Balance</h3>");

        $this->displayHeaders("Conduct the second trial only if the examinee does not earn the maximum score on the first trial.", 5);

        $subtest_5_questions = array(
                                "subtest_5_2" => "2. Walking Forward on a Line",
                                "subtest_5_7" => "7. Standing on One Leg on a Balance Beam - Eyes Open",
                               );

        $subtest_5_options = array(
                              null => "",
                              0    => 0,
                              1    => 1,
                              2    => 2,
                              3    => 3,
                              4    => 4,
                             );

        foreach ($subtest_5_questions as $key => $category) {
            $group[] =& $this->createLabel($category);

            $key_trial1 = $key . "_trial1";

            if ($key == "subtest_5_2") {
                $group[] =& $this->createText($key . "_trial1", "steps:");
                $group[] =& $this->createText($key . "_trial2", "steps:");

                $this->XINRegisterRule(
                    $key . "_trial2",
                    array("{$key_trial1}{@}!={@}6"),
                    "Required if the maximum score is not earned on the first trial",
                    $key . "_rule"
                );
            } else {
                $group[] =& $this->createText($key . "_trial1", "seconds:");
                $group[] =& $this->createText($key . "_trial2", "seconds:");

                $this->XINRegisterRule(
                    $key . "_trial2",
                    array("{$key_trial1}{@}!={@}10"),
                    "Required if the maximum score is not earned on the first trial",
                    $key . "_rule"
                );
            }

            $group[] =& $this->createSelect($key . "_point_score", "", $subtest_5_options);

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

        $this->displayHeaders("Conduct the second trial only if the examinee stumbles or falls on the first trial.", 6);

        $subtest_6_questions = array("subtest_6_3" => "3. One-Legged Stationary Hop");

        $subtest_6_options = array(
                              null => "",
                              0    => 0,
                              1    => 1,
                              2    => 2,
                              3    => 3,
                              4    => 4,
                              5    => 5,
                              6    => 6,
                              7    => 7,
                              8    => 8,
                              9    => 9,
                              10   => 10,
                             );

        foreach ($subtest_6_questions as $key => $category) {
            $group[] =& $this->createLabel($category);
            $group[] =& $this->createText($key . "_trial1", "hops:");
            $group[] =& $this->createText($key . "_trial2", "hops:");

            $key_trial2 = $key . "_trial2";

            $this->XINRegisterRule(
                $key . "_trial2",
                array("{$key_trial2}{@}=={@}NEVER_REQUIRED"),
                "Never required."
            );

            $group[] =& $this->createSelect($key . "_point_score", "", $subtest_6_options);

            $this->form->addGroup(
                $group,
                $key . "_answers",
                null,
                $this->_GUIDelimiter,
                false
            );

            unset($group);
        }

        $this->addLabel("<h3>Subtest 7: Upper-Limb Coordination</h3>");

        $subtest_7_1_options = array(
                                null => "",
                                0    => 0,
                                1    => 1,
                                2    => 2,
                                3    => 3,
                                4    => 4,
                                5    => 5,
                               );

        $subtest_7_6_options = array(
                                null => "",
                                0    => 0,
                                1    => 1,
                                2    => 2,
                                3    => 3,
                                4    => 4,
                                5    => 5,
                                6    => 6,
                                7    => 7,
                               );

        $this->displayHeaders("For item 6, conduct the second trial only if the examinee does not earn the maximum score on the first trial.", 7);

        $subtest_7_questions = array(
                                "subtest_7_1" => "1. Dropping and Catching a Ball - Both Hands",
                                "subtest_7_6" => "6. Dribbling a Ball - Alternating Hands",
                               );

        foreach ($subtest_7_questions as $key => $category) {
            $group[] =& $this->createLabel($category);

            if ($key == "subtest_7_1") {
                $group[] =& $this->createText($key . "_trial1", "catches:");
                $group[] =& $this->form->createElement("static", null, null, "");
                $group[] =& $this->createSelect($key . "_point_score", "", $subtest_7_1_options);
            } else {
                $key_trial1 = $key . "_trial1";

                $group[] =& $this->createText($key . "_trial1", "dribbles:");
                $group[] =& $this->createText($key . "_trial2", "dribbles:");
                $group[] =& $this->createSelect($key . "_point_score", "", $subtest_7_6_options);

                $this->XINRegisterRule(
                    $key . "_trial2",
                    array("{$key_trial1}{@}!={@}10"),
                    "Required if the maximum score is not earned on the first trial",
                    $key . "_rule"
                );
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

        $this->addLabel("<h3>Subtest 8: Strength</h3>");

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
            "subtest_8_headers",
            null,
            $this->_GUIDelimiter,
            false
        );

        unset($group);

        $subtest_8_questions = array(
                                "subtest_8_2" => "2. Select one",
                                "subtest_8_3" => "3. Sit-ups",
                               );

        foreach ($subtest_8_questions as $key => $category) {
            $group[] =& $this->createLabel($category);

            if ($key == "subtest_8_2") {
                $group[] =& $this->form->createSelect($key . "_type", $category, array("knee" => "2a. Knee Push-ups", "full" => "2b. Full Push-ups"));
                $group[] =& $this->createText($key . "_trial1", "push-ups:");
            } else {
                $group[] =& $this->form->createElement("static", null, null, "");
                $group[] =& $this->createText($key . "_trial1", "sit-ups:");
            }

            $group[] =& $this->createSelect($key . "_point_score", "", $subtest_3_and_8_options);

            $this->form->addGroup(
                $group,
                $key . "_answers",
                null,
                $this->_GUIDelimiter,
                false
            );

            unset($group);
        }

        $this->form->addElement("static", null, "<br/>");

        $this->addBasicText("notes_observations", "<h4>Notes & Observations</h4>");

        $this->XINRegisterRule(
            "notes_observations",
            array("notes_observations{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $this->form->addFormRule(array(&$this, 'bot2_short_special_rules'));
    }

    function score()
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        $db = Database::singleton();

        $record = $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid", array("cid" => $this->getCommentID() ));

        $subtest_point_score = array(
                                "subtest_1_3_point_score",
                                "subtest_1_6_point_score",
                                "subtest_2_2_point_score",
                                "subtest_2_7_point_score",
                                "subtest_3_2_point_score",
                                "subtest_4_3_point_score",
                                "subtest_4_6_point_score",
                                "subtest_5_2_point_score",
                                "subtest_5_7_point_score",
                                "subtest_6_3_point_score",
                                "subtest_7_1_point_score",
                                "subtest_7_6_point_score",
                                "subtest_8_2_point_score",
                                "subtest_8_3_point_score",
                               );

        $total = array("total_point_score" => 0);

        foreach ($subtest_point_score as $value) {
            $total["total_point_score"] += $record[$value];
        }

        $db->update($this->table, $total, array("CommentID" => $this->getCommentID()));
    }

    function bot2_short_special_rules($values)
    {
        $errors = [];

        $check_greater_than_0 = array(
                                 "subtest_1_3_raw_score",
                                 "subtest_6_3_trial1",
                                 "subtest_8_2_trial1",
                                 "subtest_8_3_trial1",
                                );

        foreach ($check_greater_than_0 as $question) {
            $this->validate_positive_numeric($values, $question, $errors);
        }

        $check_between_0_and_number = array(
                                       "subtest_1_6_raw_score" => 12,
                                       "subtest_3_2_trial1"    => 20,
                                       "subtest_3_2_trial2"    => 20,
                                       "subtest_4_3_trial1"    => 5,
                                       //"subtest_4_3_trial2"    => 5, //optional
                                       "subtest_4_6_trial1"    => 10,
                                       //"subtest_4_6_trial2"    => 10, //optional
                                       "subtest_5_2_trial1"    => 6,
                                       //"subtest_5_2_trial2"    => 6, //optional
                                       "subtest_5_7_trial1"    => 10,
                                       //"subtest_5_7_trial2"    => 10, //optional
                                       "subtest_7_1_trial1"    => 5,
                                       "subtest_7_6_trial1"    => 10,
                                       //"subtest_7_6_trial2"    => 10, //optional
                                      );

        foreach ($check_between_0_and_number as $key => $max) {
            $this->validate_numeric_strict($values, $key, $errors, 0, $max);
        }

        if ($values["subtest_6_3_trial2"] != "") {
            $this->validate_positive_numeric($values, "subtest_6_3_trial2", $errors);
        }

        // if subtest2 basic shape == 0, the subsequent must be 0
        $subtest_2_questions = array(
                                "subtest_2_2",
                                "subtest_2_7",
                               );

        foreach ($subtest_2_questions as $key) {
            if ($values[$key . "_basic_shape"] == 0) {
                if ($values[$key . "_closure"] != 0
                    || $values[$key . "_edges"] != 0
                    || $values[$key . "_orientation"] != 0
                    || $values[$key . "_overall_size"] != 0
                    || $values[$key . "_raw_score"] != 0
                    || $values[$key . "_point_score"] != 0
                ) {
                    $errors[$key] = "If Basic Shape facet is 0, all remaining facets and score must be 0";
                }
            }
        }

        $between_0_and_number_optional = array(
                                          "subtest_4_3" => "5", //optional
                                          "subtest_4_6" => "10", //optional
                                          "subtest_5_2" => "6", //optional
                                          "subtest_5_7" => "10", //optional
                                          "subtest_7_6" => "10", //optional
                                         );

        foreach ($between_0_and_number_optional as $key => $max) {
            if ($values[$key . "_trial2"] != "") {
                if ($values[$key . "_trial1"] == $max) {
                    $this->validate_empty_subquestions($values, [$key . "_trial2"], $errors);
                } else {
                    $this->validate_numeric_strict($values, $key . "_trial2", $errors, 0, $max);
                }
            }
        }

        return $errors;
    }
}
?>
