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
    use LegacyInstrumentTrait;

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
     * @param string $page if a multipage form, the page to show
     *
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = "XIN";
        $this->form = new LorisForm('BOT2_Short_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "BOT2_Short";           // test_names.Test_name
        $this->table = 'BOT2_Short';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->_selectMultipleElements = array();

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
        $query = "SELECT * FROM $this->table WHERE CommentID='" . $this->getCommentID() . "'";
        $db->pselectRow($query, array());

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
                null => "",
                "right" => "Right",
                "left" => "Left",
            )
        );

        $this->addSelect(
            "preferred_throwing_hand_arm",
            "Preferred Throwing Hand/Arm:",
            array(
                null => "",
                "right" => "Right",
                "left" => "Left",
            )
        );

        $this->addSelect(
            "preferred_foot_leg",
            "Preferred Foot/Leg:",
            array(
                null => "",
                "right" => "Right",
                "left" => "Left",
            )
        );

        $this->addBasicText("examinee_school", "School/Clinic:");

        $this->form->addElement('header', 'score', "Score Summary<h4><i>(Calculated on Completing Next Page)</i></h4>");

        //scoring column headers

        $group[] = $this->form->createElement('static', "total_point_score", null, null);
        $group[] = $this->form->createElement('static', "std_score", null, null);
        $group[] = $this->form->createElement('static', "CI_band", null, null);
        $group[] = $this->form->createElement('static', "CI_interval", null, null);
        $group[] = $this->form->createElement('static', "percentile_rank", null, null);
        $group[] = $this->form->createElement('static', "desc_category", null, null);
        $this->form->addGroup($group, 'score_header_group', "<strong>Scale</strong>", $this->_GUIDelimiter, FALSE);
        unset($group);


        //score fields
        $domains = array("bot2_short" => "Push-Up Knee Full");


        $columnHeaders = array("total_point_score" => "Total Point Score", "std_score" => "Standard Score",
            "CI_band" => "Band(CI:95%)", "CI_interval" => "Interval(CI:95%)", "percentile_rank" => "%ile Rank",
            "desc_category" => "Descriptive Category"
        );

        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "   ";
        }
        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        foreach ($domains as $field => $label) {
            foreach ($columnHeaders as $scoreField => $scoreLabel) {

                $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
            }
            $this->form->addGroup($group, "{$label}_score_group", $label, $this->_GUIDelimiter, FALSE);
            unset($group);


        }

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
            "subtest_{$subtest_number}_headers",
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
        $this->addHeader("<h5>(Point Score automatically calculated based on Raw Score)</h5>");
        //Section 1
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
            0 => 0,
            1 => 1,
            2 => 2,
            3 => 3,
            4 => 4,
            5 => 5,
            6 => 6,
            7 => 7,
        );
        // Section 1: Adding Group and group validations
        $e = 0;
        foreach ($subtest_1_questions as $key => $category) {
            $e++;
            $group[] = $this->createLabel($category);
            $group[] = $this->createText($key . "_raw_score", "");
            $group[] = $this->form->createElement('static', $key . "_point_score", null, null);
            $this->form->addGroup(
                $group,
                "section1_row{$e}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                $key . "_raw_score",
                array($key . "_raw_score{@}=={@}"), // rule
                "Raw Score is Required.", // message
                "section1_row{$e}" // group [if field is a part of a group]
            );
            /*  $this->XINRegisterRule(
                  $key . "_point_score",
                  array($key . "_point_score{@}=={@}"), // rule
                  "Point Score is Required.", // message
                  "section1_row{$e}" // group [if field is a part of a group]
              );*/
        }
        // Section 1 Finish
        // Section 2 Start
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
            0 => 0,
            1 => 1,
        );
        // Section 2: Adding Group and group validations
        $f = 0;
        foreach ($subtest_2_questions as $key => $category) {
            $f++;
            $group[] =& $this->createLabel($category);
            $group[] =& $this->createSelect($key . "_basic_shape", "", $subtest_2_options);
            $group[] =& $this->createSelect($key . "_closure", "", $subtest_2_options);
            $group[] =& $this->createSelect($key . "_edges", "", $subtest_2_options);
            $group[] =& $this->createSelect($key . "_orientation", "", $subtest_2_options);
            $group[] =& $this->form->createElement("static", null, null, "");
            $group[] =& $this->createSelect($key . "_overall_size", "", $subtest_2_options);
            $group[] =& $this->createText($key . "_raw_score", "");
            // $group[] =& $this->createText($key . "_point_score", "");
            $group[] = &$this->form->createElement('static', $key . "_point_score", null, null);

            $this->form->addGroup(
                $group,
                "section2_row{$f}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                $key . "_basic_shape",
                array($key . "_basic_shape{@}=={@}"), // rule
                "Basic shape is required.", // message
                "section2_row{$f}" // group [if field is a part of a group]
            );
            $this->XINRegisterRule(
                $key . "_closure",
                array($key . "_closure{@}=={@}"), // rule
                "Closure is required.", // message
                "section2_row{$f}" // group [if field is a part of a group]
            );
            $this->XINRegisterRule(
                $key . "_edges",
                array($key . "_edges{@}=={@}"), // rule
                "Edges is required.", // message
                "section2_row{$f}" // group [if field is a part of a group]
            );
            $this->XINRegisterRule(
                $key . "_orientation",
                array($key . "_orientation{@}=={@}"), // rule
                "Orientation is required.", // message
                "section2_row{$f}" // group [if field is a part of a group]
            );
            $this->XINRegisterRule(
                $key . "_overall_size",
                array($key . "_overall_size{@}=={@}"), // rule
                "Overall Size is required.", // message
                "section2_row{$f}" // group [if field is a part of a group]
            );
            $this->XINRegisterRule(
                $key . "_raw_score",
                array($key . "_raw_score{@}=={@}"), // rule
                "Raw Score is required.", // message
                "section2_row{$f}" // group [if field is a part of a group]
            );
            /* $this->XINRegisterRule(
                 $key . "_point_score",
                 array($key . "_point_score{@}=={@}"), // rule
                 "Point Score is required.", // message
                 "section2_row{$f}" // group [if field is a part of a group]
             );*/
        }
        //Section2 Finish
        //Section 3 Start

        $this->addLabel("<h3>Subtest 3: Manual Dexterity</h3>");

        $this->displayHeaders("For item 2, always conduct the second trial.", 3);

        $subtest_3_questions = array("subtest_3_2" => "2. Transferring Pennies");

        $subtest_3_and_8_options = array(
            null => "",
            0 => 0,
            1 => 1,
            2 => 2,
            3 => 3,
            4 => 4,
            5 => 5,
            6 => 6,
            7 => 7,
            8 => 8,
            9 => 9,
        );
        $g = 0;
        foreach ($subtest_3_questions as $key => $category) {
            $g++;
            $group[] =& $this->createLabel($category);
            $group[] =& $this->createText($key . "_trial1", "Pennies:");
            $group[] =& $this->createText($key . "_trial2", "Pennies:");
            //$group[] =& $this->createSelect($key . "_point_score", "", $subtest_3_and_8_options);
            $group[] = &$this->form->createElement('static', $key . "_point_score", null, null);

            $this->form->addGroup(
                $group,
                "section3_row{$g}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                $key . "_trial1",
                array($key . "_trial1{@}=={@}"), // rule
                "Trial1 is required.", // message
                "section3_row{$g}" // group [if field is a part of a group]
            );
            $this->XINRegisterRule(
                $key . "_trial2",
                array($key . "_trial2{@}=={@}"), // rule
                "Trial2 is required.", // message
                "section3_row{$g}" // group [if field is a part of a group]
            );
            /* $this->XINRegisterRule(
                 $key . "_point_score",
                 array($key . "_point_score{@}=={@}"), // rule
                 "Point Score is required.", // message
                 "section3_row{$g}" // group [if field is a part of a group]
             );*/
        }
        //Section 3 Finish

        //Section 4 Start

        $this->addLabel("<h3>Subtest 4: Bilateral Coordination</h3>");

        $this->displayHeaders("Conduct the second trial only if the examinee does not earn the maximum score on the first trial.", 4);

        $subtest_4_questions = array(
            "subtest_4_3" => "3. Jumping in Place - Same Sides Synchronized",
            "subtest_4_6" => "6. Tapping Feet and Fingers - Same Sides Synchronized",
        );

        $subtest_4_3_options = array(
            null => "",
            0 => 0,
            1 => 1,
            2 => 2,
            3 => 3,
        );

        $subtest_4_6_options = array(
            null => "",
            0 => 0,
            1 => 1,
            2 => 2,
            3 => 3,
            4 => 4,
        );
        $h = 0;
        foreach ($subtest_4_questions as $key => $category) {
            $h++;
            $group[] =& $this->createLabel($category);

            $key_trial1 = $key . "_trial1";

            if ($key == "subtest_4_3") {
                $group[] =& $this->createText($key . "_trial1", "jumps:");
                $group[] =& $this->createText($key . "_trial2", "jumps:");
                //  $group[] =& $this->createSelect($key . "_point_score", "", $subtest_4_3_options);
                $group[] = $this->form->createElement('static', $key . "_point_score", null, null);

            } else {
                $group[] =& $this->createText($key . "_trial1", "taps:");
                $group[] =& $this->createText($key . "_trial2", "taps:");
                // $group[] =& $this->createSelect($key . "_point_score", "", $subtest_4_6_options);
                $group[] = &$this->form->createElement('static', $key . "_point_score", null, null);

            }
            $this->form->addGroup(
                $group,
                "section4_row{$h}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                $key . "_trial1",
                array($key . "_trial1{@}=={@}"), // rule
                "Trial1 is required.", // message
                "section4_row{$h}" // group [if field is a part of a group]
            );
            $this->XINRegisterRule(
                $key . "_trial2",
                array($key . "_trial2{@}=={@}"), // rule
                "Trial 2 is required.", // message
                "section4_row{$h}" // group [if field is a part of a group]
            );
            if ($key == "subtest_4_3") {
                $this->XINRegisterRule(
                    $key . "_trial2",
                    array("{$key_trial1}{@}!={@}5"),
                    "Required if the maximum score is not earned on the first trial", // message
                    "section4_row{$h}" // group [if field is a part of a group]
                );
            } else {
                $this->XINRegisterRule(
                    $key . "_trial2",
                    array("{$key_trial1}{@}!={@}10"),
                    "Required if the maximum score is not earned on the first trial",
                    "section4_row{$h}" // group [if field is a part of a group]
                );
            }
        }
        //Section 4 Start

        //Section 5 Start

        $this->addLabel("<h3>Subtest 5: Balance</h3>");

        $this->displayHeaders("Conduct the second trial only if the examinee does not earn the maximum score on the first trial.", 5);

        $subtest_5_questions = array(
            "subtest_5_2" => "2. Walking Forward on a Line",
            "subtest_5_7" => "7. Standing on One Leg on a Balance Beam - Eyes Open",
        );

        $subtest_5_options = array(
            null => "",
            0 => 0,
            1 => 1,
            2 => 2,
            3 => 3,
            4 => 4,
        );
        $i = 0;
        foreach ($subtest_5_questions as $key => $category) {
            $i++;
            $group[] =& $this->createLabel($category);

            $key_trial1 = $key . "_trial1";

            if ($key == "subtest_5_2") {
                $group[] =& $this->createText($key . "_trial1", "steps:");
                $group[] =& $this->createText($key . "_trial2", "steps:");

            } else {
                $group[] =& $this->createText($key . "_trial1", "seconds:");
                $group[] =& $this->createText($key . "_trial2", "seconds:");

            }

            //$group[] =& $this->createSelect($key . "_point_score", "", $subtest_5_options);
            $group[] = &$this->form->createElement('static', $key . "_point_score", null, null);

            $this->form->addGroup(
                $group,
                "section5_row{$i}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            if ($key == "subtest_5_2") {
                $this->XINRegisterRule(
                    $key . "_trial2",
                    array("{$key_trial1}{@}!={@}6"),
                    "Required if the maximum score is not earned on the first trial",
                    "section5_row{$i}" // group [if field is a part of a group]
                );
            } else {
                $this->XINRegisterRule(
                    $key . "_trial2",
                    array("{$key_trial1}{@}!={@}10"),
                    "Required if the maximum score is not earned on the first trial",
                    "section5_row{$i}" // group [if field is a part of a group]
                );
            }
            $this->XINRegisterRule(
                $key . "_trial1",
                array($key . "_trial1{@}=={@}"), // rule
                "Trial1 is required.", // message
                "section5_row{$i}" // group [if field is a part of a group]
            );
            $this->XINRegisterRule(
                $key . "_trial2",
                array($key . "_trial2{@}=={@}"), // rule
                "Trial 2 is required.", // message
                "section5_row{$i}" // group [if field is a part of a group]
            );
            /* $this->XINRegisterRule(
                 $key . "_point_score",
                 array($key . "_point_score{@}=={@}"), // rule
                 "Point Score is required.", // message
                 "section5_row{$i}" // group [if field is a part of a group]
             );*/
        }
        //Section 5 Finish

        //Section 6 Start

        $this->addLabel("<h3>Subtest 6: Running Speed and Agility</h3>");

        $this->displayHeaders("Conduct the second trial only if the examinee stumbles or falls on the first trial.", 6);

        $subtest_6_questions = array("subtest_6_3" => "3. One-Legged Stationary Hop");

        $subtest_6_options = array(
            null => "",
            0 => 0,
            1 => 1,
            2 => 2,
            3 => 3,
            4 => 4,
            5 => 5,
            6 => 6,
            7 => 7,
            8 => 8,
            9 => 9,
            10 => 10,

        );
        $j = 0;

        foreach ($subtest_6_questions as $key => $category) {
            $j++;
            $group[] =& $this->createLabel($category);
            $group[] =& $this->createText($key . "_trial1", "hops:");
            $group[] =& $this->createText($key . "_trial2", "hops:");

            //$group[] =& $this->createSelect($key . "_point_score", "", $subtest_6_options);
            $group[] =& $this->form->createElement('static', $key . "_point_score", null, null);

            $this->form->addGroup(
                $group,
                "section6_row{$j}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                $key . "_trial2",
                array($key . "_trial2{@}=={@}NEVER_REQUIRED"), // rule
                "Trial 2 is required.", // message
                "section6_row{$j}" // group [if field is a part of a group]
            );
            $this->XINRegisterRule(
                $key . "_trial1",
                array($key . "_trial1{@}=={@}"), // rule
                "Trial 1 is required.", // message
                "section6_row{$j}" // group [if field is a part of a group]
            );
            /* $this->XINRegisterRule(
                 $key . "_point_score",
                 array($key . "_point_score{@}=={@}"), // rule
                 "Point Score is required.", // message
                 "section6_row{$j}" // group [if field is a part of a group]
             );*/
        }
        //Section 6 Finish

        //section 7 Start

        $this->addLabel("<h3>Subtest 7: Upper-Limb Coordination</h3>");

        $subtest_7_1_options = array(
            null => "",
            0 => 0,
            1 => 1,
            2 => 2,
            3 => 3,
            4 => 4,
            5 => 5,
        );

        $subtest_7_6_options = array(
            null => "",
            0 => 0,
            1 => 1,
            2 => 2,
            3 => 3,
            4 => 4,
            5 => 5,
            6 => 6,
            7 => 7,
        );

        $this->displayHeaders("For item 6, conduct the second trial only if the examinee does not earn the maximum score on the first trial.", 7);

        $subtest_7_questions = array(
            "subtest_7_1" => "1. Dropping and Catching a Ball - Both Hands",
            "subtest_7_6" => "6. Dribbling a Ball - Alternating Hands",
        );
        $k = 0;
        foreach ($subtest_7_questions as $key => $category) {
            $k++;
            $group[] =& $this->createLabel($category);

            if ($key == "subtest_7_1") {
                $group[] =& $this->createText($key . "_trial1", "catches:");
                $group[] =& $this->form->createElement("static", null, null, "");
                //$group[] =& $this->createSelect($key . "_point_score", "", $subtest_7_1_options);
                $group[] = &$this->form->createElement('static', $key . "_point_score", null, null);
            } else {
                $key_trial1 = $key . "_trial1";

                $group[] =& $this->createText($key . "_trial1", "dribbles:");
                $group[] =& $this->createText($key . "_trial2", "dribbles:");
                //$group[] =& $this->createSelect($key . "_point_score", "", $subtest_7_6_options);
                $group[] = $this->form->createElement('static', $key . "_point_score", null, null);

                $this->XINRegisterRule(
                    $key . "_trial2",
                    array("{$key_trial1}{@}!={@}10"),
                    "Required if the maximum score is not earned on the first trial",
                    $key . "_rule"
                );
            }

            $this->form->addGroup(
                $group,
                "section7_row{$k}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            if ($key == "subtest_7_1") {
                $this->XINRegisterRule(
                    $key . "_trial2",
                    array($key . "_trial2{@}=={@}NEVER_REQUIRED"), // rule
                    "Trial 2 is required.", // message
                    "section7_row{$k}" // group [if field is a part of a group]
                );
            } else {
                $this->XINRegisterRule(
                    $key . "_trial2",
                    array("{$key_trial1}{@}!={@}10"),
                    "Trial 2 Required if the maximum score(10) is not earned on the first trial",
                    "section7_row{$k}"
                );

            }
            $this->XINRegisterRule(
                $key . "_trial1",
                array($key . "_trial1{@}=={@}"), // rule
                "Trial 1 is required.", // message
                "section7_row{$k}" // group [if field is a part of a group]
            );
            /*  $this->XINRegisterRule(
                  $key . "_point_score",
                  array($key . "_point_score{@}=={@}"), // rule
                  "Point Score is required.", // message
                  "section7_row{$k}" // group [if field is a part of a group]
              );*/
        }

        //Section 7 Finish

        //Section 8 Start

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
        $l = 0;
        foreach ($subtest_8_questions as $key => $category) {
            $l++;
            $group[] =& $this->createLabel($category);

            if ($key == "subtest_8_2") {
                $group[] =& $this->form->createSelect($key . "_type", $category, array("knee" => "2a. Knee Push-ups", "full" => "2b. Full Push-ups"));
                $group[] =& $this->createText($key . "_trial1", "push-ups:");
            } else {
                $group[] =& $this->form->createElement("static", null, null, "");
                $group[] =& $this->createText($key . "_trial1", "sit-ups:");
            }

            //$group[] =& $this->createSelect($key . "_point_score", "", $subtest_3_and_8_options);
            $group[] = $this->form->createElement('static', $key . "_point_score", null, null);

            $this->form->addGroup(
                $group,
                "section8_row{$l}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                $key . "_trial1",
                array($key . "_trial1{@}=={@}"), // rule
                "Raw Score is required.", // message
                "section8_row{$l}" // group [if field is a part of a group]
            );
            /* $this->XINRegisterRule(
                 $key . "_point_score",
                 array($key . "_point_score{@}=={@}"), // rule
                 "Point Score is required.", // message
                 "section8_row{$l}" // group [if field is a part of a group]
             );*/
        }
        //Section 8 Finish

        $this->form->addElement("static", null, "<br/>");

        $this->addBasicText("notes_observations", "<h4>Notes & Observations</h4>");

        $this->XINRegisterRule(
            "notes_observations",
            array("notes_observations{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $this->form->addFormRule(array(&$this, 'bot2_short_special_rules'));
    }

    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }


        $db = Database::singleton();

        $record = $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid", array("cid" => $this->getCommentID()));
        $timepoint =& TimePoint::singleton($this->getSessionID());
        $dob = $timepoint->getEffectiveDateOfBirth();
        $interval = date_diff(date_create($dob), date_create($record["Date_taken"]));
        $age = $interval->format("%Y.%M");
        $age_years = $interval->format("%Y");
        $subtest_name = array(
            "subtest_1_3",
            "subtest_1_6",
            "subtest_2_2",
            "subtest_2_7",
            "subtest_3_2",
            "subtest_4_3",
            "subtest_4_6",
            "subtest_5_2",
            "subtest_5_7",
            "subtest_6_3",
            "subtest_7_1",
            "subtest_7_6",
            "subtest_8_2",
            "subtest_8_3",
        );
        foreach ($subtest_name as $value) {
            $scores["$value" . '_point_score'] = $this->getPointScore($value);
        }



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



        $db->update($this->table, $scores, array("CommentID" => $this->getCommentID()));
        foreach ($subtest_point_score as $value) {
            $scores["total_point_score"] += $scores["{$value}"];
            $scores["bot2_short_total_point_score"] += $scores["{$value}"];
        }
        $total_point_score = $scores["bot2_short_total_point_score"];
        if ($scores["total_point_score"] > 0 || $scores["total_point_score"] !=NULL) {
            $query_gender = "SELECT Sex FROM candidate as c, session as s, flag as f, $this->table as t WHERE t.CommentID = '$this->commentID' 
AND f.CommentID=t.CommentID AND s.ID=f.SessionID AND s.CandID=c.CandID";
            $record_gender = $db->pselectRow($query_gender, array());
            $sex = $record_gender['Sex'];
            $query_scores = "SELECT * FROM BOT2_Short_lookup WHERE
                sex='$sex'  AND (age ='$age'  OR  '$age' BETWEEN SUBSTRING_INDEX 
                (`age`,'-', 1) AND SUBSTRING_INDEX(`age`,'-', -1) )AND
                (total_point_score ='$total_point_score'  OR  '$total_point_score' BETWEEN SUBSTRING_INDEX 
                (`total_point_score`,'-', 1) AND SUBSTRING_INDEX(`total_point_score`,'-', -1) )";
            $record_1 = $db->pselectRow($query_scores, array());

            $scores['bot2_short_std_score'] = $record_1['std_score'];
            $scores['bot2_short_percentile_rank'] = $record_1['percentile_rank'];
            $std_score = $scores['bot2_short_std_score'];
            if ($std_score >= 70) {
                $scores['bot2_short_desc_category'] = "Well-Above Average";
            } else if (in_array($std_score, range(60, 69))) {
                $scores['bot2_short_desc_category'] = "Above Average";
            } else if (in_array($std_score, range(41, 59))) {
                $scores['bot2_short_desc_category'] = "Average";
            } else if (in_array($std_score, range(31, 40))) {
                $scores['bot2_short_desc_category'] = "Below Average";
            } else if ($std_score <= 30) {
                $scores['bot2_short_desc_category'] = "Well-Below Average";
            } else {
                $scores['bot2_short_desc_category'] = "--";
            }

            $band_ci = $this->getBandCI($age_years);
            $scores['bot2_short_CI_band'] = "+/- " . $band_ci;
            $scores['bot2_short_CI_interval'] = ($std_score - $band_ci) . "-" . ($std_score + $band_ci);
            $db->update($this->table, $scores, array("CommentID" => $this->getCommentID()));
        }


    }

    function bot2_short_special_rules($values)
    {
        $errors = [];

        $check_greater_than_0 = [
            ["subtest_1_3_raw_score", "section1_row1"],
            ["subtest_6_3_trial1", "section6_row1"],
            ["subtest_8_2_trial1", "section8_row1"],
            ["subtest_8_3_trial1", "section8_row2"],
        ];

        for ($i = 0; $i < count($check_greater_than_0); $i++) {
            $field = $check_greater_than_0[$i][0];
            $group = $check_greater_than_0[$i][1];
            $this->validate_positive_numeric($values, $field, $errors, $group);
        }

        $check_between_0_and_number = [
            ["subtest_1_6_raw_score", "section1_row2", 12],
            ["subtest_3_2_trial1", "section3_row1", 20],
            ["subtest_3_2_trial2", "section3_row1", 20],
            ["subtest_4_3_trial1", "section4_row1", 5],
            ["subtest_4_6_trial1", "section4_row2", 10],
            ["subtest_5_2_trial1", "section5_row1", 6],
            ["subtest_5_7_trial1", "section5_row2", 10],
            ["subtest_7_1_trial1", "section7_row1", 5],
            ["subtest_7_6_trial1", "section7_row2", 10],
        ];


        for ($i = 0; $i < count($check_between_0_and_number); $i++) {
            $field = $check_between_0_and_number[$i][0];
            $max = $check_between_0_and_number[$i][2];
            $group = $check_between_0_and_number[$i][1];
            $this->validate_numeric_strict_group($values, $field, $errors, 0, $max, $group);
        }

        if ($values["subtest_6_3_trial2"] != "") {
            $group = "section6_row1";
            $this->validate_positive_numeric($values, "subtest_6_3_trial2", $errors, $group);
        }

        // if subtest2 basic shape == 0, the subsequent must be 0
        $subtest_2_questions = [
            ["subtest_2_2", "section2_row1"],
            ["subtest_2_7", "section2_row2"],
        ];

        for ($i = 0; $i < count($subtest_2_questions); $i++) {
            $key = $subtest_2_questions[$i][0];
            $group = $subtest_2_questions[$i][1];
            if ($values[$key . "_basic_shape"] == 0) {
                if ($values[$key . "_closure"] != 0
                    || $values[$key . "_edges"] != 0
                    || $values[$key . "_orientation"] != 0
                    || $values[$key . "_overall_size"] != 0
                    || $values[$key . "_raw_score"] != 0
                    || $values[$key . "_point_score"] != 0
                ) {
                    $errors[$group] = "If Basic Shape facet is 0, all remaining facets and score must be 0";
                }
            }
        }

        $between_0_and_number_optional = [
            ["subtest_4_3", "section4_row1", "5"],
            ["subtest_4_6", "section4_row2", "10"],
            ["subtest_5_2", "section5_row1", "6"],
            ["subtest_5_7", "section5_row2", "10"],
            ["subtest_7_6", "section7_row2", "10"],
        ];

        for ($i = 0; $i < count($between_0_and_number_optional); $i++) {
            $field = $between_0_and_number_optional[$i][0];
            $group = $between_0_and_number_optional[$i][1];
            $max = $between_0_and_number_optional[$i][2];
            if ($values[$field . "_trial2"] != "") {
                if ($values[$field . "_trial1"] == $max) {
                    $errors[$group] = "Trial 2 should be left empty as Trail1 has the maximum value.";
                } else {
                    $this->validate_numeric_strict_group($values, $field . "_trial2", $errors, 0, $max, $group);
                }
            }
        }

        return $errors;
    }

    function getBandCI($age_years)
    {
        $seven_band = array(5, 7, 9, 12, 15, 16, 17, 18, 19, 20, 21);
        if ($age_years == 4 || $age_years == 8) {
            $band_ci = 9;
        } else if (in_array($age_years, $seven_band)) {
            $band_ci = 7;
        } else if ($age_years == 13 || $age_years == 14) {
            $band_ci = 5;
        } else if ($age_years == 10 || $age_years == 11) {
            $band_ci = 6;
        } else if ($age_years == 6) {
            $band_ci = 8;
        } else {
            $band_ci = "NA";
        }
        return $band_ci;

    }

    function getPointScore($subtest_name)
    {

        $two_trial_array = array('subtest_3_2', 'subtest_4_3',
            'subtest_4_6', 'subtest_5_2', 'subtest_5_7', 'subtest_6_3',
            'subtest_7_6',);
        $no_trial_array = array('subtest_1_3', 'subtest_1_6','subtest_2_2','subtest_2_7');
        $db = Database::singleton();
        $query = "SELECT *
FROM candidate as c, session as s, flag as f, $this->table as t WHERE t.CommentID = '$this->commentID' 
AND f.CommentID=t.CommentID AND s.ID=f.SessionID AND s.CandID=c.CandID";
        $raw_score_find = $db->pselectRow($query, array());
        //print_r($raw_score_find);
        if (in_array($subtest_name, $two_trial_array)) {
            $raw_score = max($raw_score_find["{$subtest_name}_trial1"],
                $raw_score_find["{$subtest_name}_trial2"]);
        }
           else if (in_array($subtest_name, $no_trial_array)) {
               $raw_score = $raw_score_find["{$subtest_name}_raw_score"];
        } else {
            $raw_score = $raw_score_find["{$subtest_name}_trial1"];
        }
        if($raw_score!=NULL) {
            $search_key = $raw_score;
        }
        else{
            $point_score=NULL;
            return $point_score;
        }
        if($subtest_name=='subtest_1_3')
        {
            $check_array=array('>=21' => 0, '15-20' => 1, '10-14' => 2, '6-9' => 3, '4-5' => 4, '2-3' => 5, '1' => 6, '0' => 7);
        }
        if($subtest_name=='subtest_1_6')
        {
            $check_array=array('0' => 6, '1-2' => 1, '3-4' => 2, '5-6' => 3, '7-8' => 4, '9-10' => 5, '11' => 6, '12' => 7);
        }
        if($subtest_name=='subtest_3_2')
        {
           $check_array=array('0-2' => 0, '3-4' => 1, '5-6' => 2, '7-8' => 3, '9-10' => 4, '11-12' => 5, '13-14' => 6,
               '15-16' => 7, '17-18' => 8, '19-20' => 9);
        }
        if($subtest_name=='subtest_4_3')
        {
            $check_array=array('0' => 0, '1' => 1, '2-4' => 2, '5' => 3);
        }
        if($subtest_name=='subtest_4_6')
        {
            $check_array=array('0' => 0, '1' => 1, '2-4' => 2, '5-9' => 3,'10'=>4);
        }
        if($subtest_name=='subtest_5_2')
        {
            $check_array=array('0' => 0, '1-2' => 1, '3-4' => 2, '5' => 3, '6' => 4);
        }
        if($subtest_name=='subtest_5_7')
        {
            $check_array=array('0.0-0.9' => 0, '1.0-2.9' => 1, '3.0-5.9' => 2, '6.0-9.9' => 3, '10' => 4);
        }
        if($subtest_name=='subtest_6_3')
        {
            $check_array=array('0' => 0, '1-2' => 1, '3-5' => 2, '6-9' => 3, '10-14' => 4, '15-19' => 5, '20-24' => 6, '25-29' => 7,
                '30-39' => 8, '40-49' => 9, '>=50' => 10);
        }
        if($subtest_name=='subtest_7_1')
        {
            $check_array=array('0' => 0, '1' => 1, '2' => 2, '3' => 3, '4' => 4, '5' => 5);
        }
        if($subtest_name=='subtest_7_6')
        {
            $check_array=array('0' => 0, '1' => 1, '2' => 2, '3' => 3, '4-5' => 4, '6-7' => 5,
                '8-9' => 6, '10' => 7);
        }
        if($subtest_name=='subtest_8_2')
        {
           $check_array= array('0' => 0, '1-2' => 1, '3-5' => 2, '6-10' => 3, '11-15' => 4, '16-20' => 5, '21-25' => 6,
                '26-30' => 7, '31-35' => 8, '>=36' => 9);
        }
        if($subtest_name=='subtest_8_3')
        {
            $check_array=array('0' => 0, '1-2' => 1, '3-5' => 2, '6-10' => 3, '11-15' => 4, '16-20' => 5, '21-25' => 6,
            '26-30' => 7, '31-35' => 8, '>=36' => 9);
        }
        if($subtest_name=='subtest_2_2' || $subtest_name=='subtest_2_7')
        {
           $point_score=$raw_score;
        }
        else {
            foreach ($check_array as $key => $value) {
                if (stristr($key, '-') !== FALSE) {
                    $range = array_map('intval', explode('-', $key));
                    if ($search_key >= $range[0] && $search_key <= $range[1]) {
                        $point_score = $value;
                        break;
                    }

                } elseif (strpos($key, '>=') !== false) {
                    $f=explode('>=', $key);
                    if ($raw_score >= $f[1]) {
                        $point_score = $value;
                        break;
                    }
                } elseif ($key == $raw_score) {
                    $point_score = $value;
                    break;
                } else {
                    $point_score = NULL;
                }

            }
        }
        return $point_score;
    }
}
?>
