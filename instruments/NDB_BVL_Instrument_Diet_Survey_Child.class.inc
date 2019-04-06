<?php
/**
 * Creates the form elements for the Child's Diet Survey
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
 * Creates the form elements for the Child's Diet Survey
 *
 * @category Instrument
 * @package  Main
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_Diet_Survey_Child extends NDB_BVL_Instrument
{
    use instrument_validator;
    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names(Test_name, Full_name, Sub_Group) VALUES('Diet_Survey_Child', "Diet Survey Child 101112 Clean", 1);
     * INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Diet_Survey_Child', '0', '0', 'Y', 'Visit', 1, 'V06', NULL);
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
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)
        // set the object properties
        $this->testName = "Diet_Survey_Child";           // test_names.Test_name
        $this->table    = 'Diet_Survey_Child';              // name of database table corresponding to instrument
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
                                    'q1_feed_child_bottle_once_per_week',
                                    'q6_did_you_feed_formula_contained_DHA_ARA',
                                    'q7_did_you_feed_formula_contained_iron',
                                    'q12_pump_or_store_breast_milk',
                                   // '63_would_rather_be_with_older_people',
                                   // '93_walks_too_much',
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
        if (preg_match("/Diet_Survey_Child(_page[0-9]+)/", $this->page, $matches)) {
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
    function _main()
    {
        // display test name
        $this->addHeader("Diet Survey Child 101112 Clean");

        $this->form->addElement('static', null, "<br />");

        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
    }

    /**
    * Generates the first page of the form.
    *
    * @return void
    */
    function _page1()
    {
        $this->addHeader("Diet Survey Child 101112 Clean");

        $this->form->addElement('static', null, "<br />");

        $yes_no_options = array(
                           null  => "",
                           "yes" => "Yes",
                           "no"  => "No",
                           "dk"  => "DK",
                           "rf"  => "RF",
                          );

        // if yes, continue
        // otherwise, skip to 12
        $this->addSelect("q1_feed_child_bottle_once_per_week", "1. Did you ever feed your child with a bottle (including breast milk, formula, or other liquids) at least once per week for a month or more?", $yes_no_options);

        $this->addLabel($this->indent."If Yes, then continue. Otherwise, go to question 12");

        $this->form->addElement('static', null, "<br />");

        // Types of bottles, needs group
        $this->addLabel("2. Which of the following types of bottles were used at least once per week for a month or more when giving your child breast milk, formula or other liquids?");

        $q2_subquestions = array(
                            "q2a_clear_hard_plastic_no_inserts_liners"   => "a. Clear hard plastic (no inserts/liners)",
                            "q2b_clear_hard_plastic_with_inserts_liners" => "b. Clear hard plastic (with inserts/liners)",
                            "q2c_opaque_plastic"                         => "c. Opaque plastic (not clear)",
                            "q2d_glass"                                  => "d. Glass",
                            "q2e_bpa_free_bottle"                        => "e. BPA-free bottle (such as Born Free (R))",
                           );

        $this->form->addElement('static', null, "<br />");

        $this->_displayHeaders("q2_subquestions");

        foreach ($q2_subquestions as $question => $label) {
            $group[] = $this->createLabel($label);

            $group[] = $this->createSelect(
                $question . "_yes_no",
                "",
                $yes_no_options
            );

            $group[] = $this->createText(
                $question . "_specify_brands",
                ""
            );

            $this->XINRegisterRule(
                $question . "_specify_brands",
                array($question . "_yes_no{@}=={@}yes"),
                "Required.",
                $question . "_group"
            );

            $this->form->addGroup(
                $group,
                $question . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->form->addElement('static', null, "<br />");

        $q3_options = array(
                       null                         => "",
                       "mostly_microwave"           => "Mostly microwave",
                       "mostyle_stovetop_hot_water" => "Mostyle stovetop/hot water",
                       "50_50_microwave_stovetop"   => "50/50 (microwave/stovetop)",
                       "did_not_warm_bottles"       => "Did not warm bottles",
                       "used_warm_tap_water"        => "Used warm tap water to make formula",
                       "dk"                         => "DK",
                       "rf"                         => "RF",
                       "other"                      => "Other: Specify",
                      );

        $this->addSelect("q3_how_usually_heat_bottles", "3. How did you usually heat the bottles?", $q3_options);

        //$this->if_yes_skip($q1_feed_child_bottle_once_per_week, $q3_how_usually_heat_bottles, "12");

        $this->XINRegisterRule(
            "q3_how_usually_heat_bottles",
            array("q1_feed_child_bottle_once_per_week{@}=={@}yes"),
            "Required."
        );

        $this->addBasicText("q3_if_other", $this->indent."If other, please specify:");

        $this->XINRegisterRule(
            "q3_if_other",
            array("q3_how_usually_heat_bottles{@}=={@}other"),
            "Required."
        );

        $this->form->addElement('static', null, "<br />");

        // If yes, continue
        // Otherwise, go to q11
        $this->addSelect("q4_did_you_feed_infant_formula", "4. Did you feed your baby any infant formula?", $yes_no_options);

        $this->addLabel("$this->indentIf Yes, then continue. Otherwise, go to question 11");


        $this->XINRegisterRule(
            "q4_did_you_feed_infant_formula",
            array("q1_feed_child_bottle_once_per_week{@}=={@}yes"),
            "Required."
        );

        $this->form->addElement('static', null, "<br />");
        // q4a, q4b

        // "4a. At what age did you start feeding your child formula?"
        // "4b. For how long did you feed your child formula?"

        $this->form->addFormRule(array(&$this, 'diet_survey_special_rules_page_1'));
    }

    /**
    * Generates the second page of the form.
    *
    * @return void
    */
    function _page2()
    {
        $this->addHeader("Diet Survey Child 101112 Clean");

        $this->form->addElement('static', null, "<br />");

        $yes_no_options = array(
                           null  => "",
                           "yes" => "Yes",
                           "no"  => "No",
                           "dk"  => "DK",
                           "rf"  => "RF",
                          );

        // q5 needs group

        $this->addLabel("5. What type of formula did you usually use (for at least one month)? Check the box with the type of formula you used, or check ‘<b>did not use</b>’ if you did not use that type of formula at all. By <i>type</i>, we mean powder, ready-to-use liquid, and/or concentrate. Specify the brands used most often in the spaces provided.");

        $this->form->addElement('static', null, "<br />");

        $this->addSelect("q6_did_you_feed_formula_contained_DHA_ARA", "6. Did you ever feed your child formula that contained DHA/ARA?", $yes_no_options);

        // if yes, fill out chart
        $this->addLabel($this->indent."If yes, for each time period, specify if you fed your child formula that contained DHA/ARA most of the time, sometimes, not at all, or don’t know by checking the appropriate box in the table below.");
        // $this->form->addFormRule(array(&$this, 'abcl_special_rules'));


        $q6_options = array(
                       null         => "",
                       "mostly"     => "Mostly",
                       "sometimes"  => "Sometimes",
                       "not_at_all" => "Not At All",
                       "dont_know"  => "Don't Know",
                      );

        //$this->form->addElement('static', null, "<br />");
        $group[] = &$this->form->createElement("static", null, null, "Month 1");
        $group[] = &$this->form->createElement("static", null, null, "Month 2");
        $group[] = &$this->form->createElement("static", null, null, "Month 3");
        $group[] = &$this->form->createElement("static", null, null, "Months 4-6");
        $group[] = &$this->form->createElement("static", null, null, "Months 7-11");
        $group[] = &$this->form->createElement("static", null, null, "12 Months+");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        $group[]=&$this->form->createElement("select", "q6_month_1", null, $q6_options);
        $group[]=&$this->form->createElement("select", "q6_month_2", null, $q6_options);
        $group[]=&$this->form->createElement("select", "q6_month_3", null, $q6_options);
        $group[]=&$this->form->createElement("select", "q6_month_4_to_6", null, $q6_options);
        $group[]=&$this->form->createElement("select", "q6_month_7_to_11", null, $q6_options);
        $group[]=&$this->form->createElement("select", "q6_month_12", null, $q6_options);

        $this->XINRegisterRule(
            "q6_month_1",
            array("q6_did_you_feed_formula_contained_DHA_ARA{@}=={@}yes"),
            "All fields are required if the above question was answered Yes.",
            "q6_if_yes_group"
        );
        $this->XINRegisterRule(
            "q6_month_2",
            array("q6_did_you_feed_formula_contained_DHA_ARA{@}=={@}yes"),
            "All fields are required if the above question was answered Yes.",
            "q6_if_yes_group"
        );
        $this->XINRegisterRule(
            "q6_month_3",
            array("q6_did_you_feed_formula_contained_DHA_ARA{@}=={@}yes"),
            "All fields are required if the above question was answered Yes.",
            "q6_if_yes_group"
        );
        $this->XINRegisterRule(
            "q6_month_4_to_6",
            array("q6_did_you_feed_formula_contained_DHA_ARA{@}=={@}yes"),
            "All fields are required if the above question was answered Yes.",
            "q6_if_yes_group"
        );
        $this->XINRegisterRule(
            "q6_month_7_to_11",
            array("q6_did_you_feed_formula_contained_DHA_ARA{@}=={@}yes"),
            "All fields are required if the above question was answered Yes.",
            "q6_if_yes_group"
        );
        $this->XINRegisterRule(
            "q6_month_12",
            array("q6_did_you_feed_formula_contained_DHA_ARA{@}=={@}yes"),
            "All fields are required if the above question was answered Yes.",
            "q6_if_yes_group"
        ); 

        $this->form->addGroup($group, "q6_if_yes_group", "", $this->_GUIDelimiter, false);
        unset($group);
    }

    /**
    * Generates the third page of the form.
    *
    * @return void
    */
    function _page3()
    {
        $this->addHeader("Diet Survey Child 101112 Clean");

        $this->form->addElement('static', null, "<br />");

        $yes_no_options = array(
                           null  => "",
                           "yes" => "Yes",
                           "no"  => "No",
                           "dk"  => "DK",
                           "rf"  => "RF",
                          );

        $this->addSelect("q7_did_you_feed_formula_contained_iron", "7. Did you ever feed your child formula that contained iron?", $yes_no_options);

        // if yes, fill out chart
        $this->addLabel($this->indent."If yes, for each time period, specify if you fed your child formula that contained iron most of the time, sometimes, not at all, or don’t know by checking the appropriate box in the table below.");

        $q7_and_8_options = array(
               null         => "",
               "mostly"     => "Mostly",
               "sometimes"  => "Sometimes",
               "not_at_all" => "Not At All",
               "dont_know"  => "Don't Know",
              );

        //$this->form->addElement('static', null, "<br />");
        $group[] = &$this->form->createElement("static", null, null, "Month 1");
        $group[] = &$this->form->createElement("static", null, null, "Month 2");
        $group[] = &$this->form->createElement("static", null, null, "Month 3");
        $group[] = &$this->form->createElement("static", null, null, "Months 4-6");
        $group[] = &$this->form->createElement("static", null, null, "Months 7-11");
        $group[] = &$this->form->createElement("static", null, null, "12 Months+");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        $group[]=&$this->form->createElement("select", "q7_month_1", null, $q7_and_8_options);
        $group[]=&$this->form->createElement("select", "q7_month_2", null, $q7_and_8_options);
        $group[]=&$this->form->createElement("select", "q7_month_3", null, $q7_and_8_options);
        $group[]=&$this->form->createElement("select", "q7_month_4_to_6", null, $q7_and_8_options);
        $group[]=&$this->form->createElement("select", "q7_month_7_to_11", null, $q7_and_8_options);
        $group[]=&$this->form->createElement("select", "q7_month_12", null, $q7_and_8_options);

        $this->XINRegisterRule(
            "q7_month_1",
            array("q7_did_you_feed_formula_contained_iron{@}=={@}yes"),
            "All fields are required if the above question was answered Yes.",
            "q7_if_yes_group"
        );
        $this->XINRegisterRule(
            "q7_month_2",
            array("q7_did_you_feed_formula_contained_iron{@}=={@}yes"),
            "All fields are required if the above question was answered Yes.",
            "q7_if_yes_group"
        );
        $this->XINRegisterRule(
            "q7_month_3",
            array("q7_did_you_feed_formula_contained_iron{@}=={@}yes"),
            "All fields are required if the above question was answered Yes.",
            "q7_if_yes_group"
        );
        $this->XINRegisterRule(
            "q7_month_4_to_6",
            array("q7_did_you_feed_formula_contained_iron{@}=={@}yes"),
            "All fields are required if the above question was answered Yes.",
            "q7_if_yes_group"
        );
        $this->XINRegisterRule(
            "q7_month_7_to_11",
            array("q7_did_you_feed_formula_contained_iron{@}=={@}yes"),
            "All fields are required if the above question was answered Yes.",
            "q7_if_yes_group"
        );
        $this->XINRegisterRule(
            "q7_month_12",
            array("q7_did_you_feed_formula_contained_iron{@}=={@}yes"),
            "All fields are required if the above question was answered Yes.",
            "q7_if_yes_group"
        ); 

        $this->form->addGroup($group, "q7_if_yes_group", "", $this->_GUIDelimiter, false);
        unset($group);

        $this->form->addElement('static', null, "<br />");

        $this->addSelect("q8_did_you_feed_any_other_type_special_formula", "8. Did you ever feed your child any other type of special formula?", $yes_no_options);

        $this->addBasicText("q8_if_yes", "$this->indent If yes, specify the type of formula:");

        $this->XINRegisterRule(
            "q8_if_yes",
            array("q8_did_you_feed_any_other_type_special_formula{@}=={@}yes"),
            "Required."
        );

        $this->addLabel($this->indent."If yes, for each time period, specify if you fed your child special formula most of the time, sometimes, not at all, or don’t know by checking the appropriate box in the table below.");


        //$this->form->addElement('static', null, "<br />");
        $group[] = &$this->form->createElement("static", null, null, "Month 1");
        $group[] = &$this->form->createElement("static", null, null, "Month 2");
        $group[] = &$this->form->createElement("static", null, null, "Month 3");
        $group[] = &$this->form->createElement("static", null, null, "Months 4-6");
        $group[] = &$this->form->createElement("static", null, null, "Months 7-11");
        $group[] = &$this->form->createElement("static", null, null, "12 Months+");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        $group[]=&$this->form->createElement("select", "q8_month_1", null, $q7_and_8_options);
        $group[]=&$this->form->createElement("select", "q8_month_2", null, $q7_and_8_options);
        $group[]=&$this->form->createElement("select", "q8_month_3", null, $q7_and_8_options);
        $group[]=&$this->form->createElement("select", "q8_month_4_to_6", null, $q7_and_8_options);
        $group[]=&$this->form->createElement("select", "q8_month_7_to_11", null, $q7_and_8_options);
        $group[]=&$this->form->createElement("select", "q8_month_12", null, $q7_and_8_options);

        $this->XINRegisterRule(
            "q8_month_1",
            array("q8_did_you_feed_any_other_type_special_formula{@}=={@}yes"),
            "All fields are required if the above question was answered Yes.",
            "q8_if_yes_group"
        );
        $this->XINRegisterRule(
            "q8_month_2",
            array("q8_did_you_feed_any_other_type_special_formula{@}=={@}yes"),
            "All fields are required if the above question was answered Yes.",
            "q8_if_yes_group"
        );
        $this->XINRegisterRule(
            "q8_month_3",
            array("q8_did_you_feed_any_other_type_special_formula{@}=={@}yes"),
            "All fields are required if the above question was answered Yes.",
            "q8_if_yes_group"
        );
        $this->XINRegisterRule(
            "q8_month_4_to_6",
            array("q8_did_you_feed_any_other_type_special_formula{@}=={@}yes"),
            "All fields are required if the above question was answered Yes.",
            "q8_if_yes_group"
        );
        $this->XINRegisterRule(
            "q8_month_7_to_11",
            array("q8_did_you_feed_any_other_type_special_formula{@}=={@}yes"),
            "All fields are required if the above question was answered Yes.",
            "q8_if_yes_group"
        );
        $this->XINRegisterRule(
            "q8_month_12",
            array("q8_did_you_feed_any_other_type_special_formula{@}=={@}yes"),
            "All fields are required if the above question was answered Yes.",
            "q8_if_yes_group"
        ); 

        $this->form->addGroup($group, "q8_if_yes_group", "", $this->_GUIDelimiter, false);
        unset($group);




        $this->form->addElement('static', null, "<br />");

        // if yes, fill out chart

        // if yes, continue to question 12
        $this->addSelect("q9_period_fed_child_formula_regularly_breastfed", "9. Was there a period during the time you fed your child formula that you also regularly breastfed?", $yes_no_options);

        $this->addLabel($this->indent."If Yes, then continue.  Otherwise, go to question 12.");

        $this->form->addElement('static', null, "<br />");

        $q10_options = array(
                        null                        => "",
                        "mostly_breast_milk"        => "Mostly breast milk",
                        "mostly_formula"            => "Mostly formula",
                        "50_50_breast_milk_formula" => "50/50 breast milk and formula",
                        "dk"                        => "DK",
                        "rf"                        => "RF",
                       );

        $this->addSelect("q10_during_time_fed_both_formula_and_breast_milk", "10. During the time you fed both formula and breast milk, did you feed:", $q10_options);

        // $this->form->addFormRule(array(&$this, 'abcl_special_rules'));
    }


    /**
    * Generates the fourth page of the form.
    *
    * @return void
    */
    function _page4()
    {
        $this->addHeader("Diet Survey Child 101112 Clean");

        $this->form->addElement('static', null, "<br />");

        $yes_no_options = array(
                           null  => "",
                           "yes" => "Yes",
                           "no"  => "No",
                           "dk"  => "DK",
                           "rf"  => "RF",
                          );

        $this->addLabel("11. What percent of breast milk did you feed from a bottle? Check the box with the closest percentage. Check 0% if breast milk was not fed from a bottle at all during that time period.");

        $q11_subquestions = array(
                            "q11a_during_first_3_months"   => "a. During the first 3 months",
                            "q11b_during_second_3_months" => "b. During the second 3 months",
                           );

        $q11_options = array(
            null => "",
            "0_percent" => "0%",
            "1_to_24_percent" => "1-24%",
            "25_to_49_percent" => "25-49%",
            "50_to_74_percent" => "50-74%",
            "75_to_100_percent" => "75-100%",
            "dk" => "DK",
            "rf" => "RF",
        );

        foreach ($q11_subquestions as $question => $label) {
            $this->addSelect($question, $label, $q11_options);
        }



        $this->form->addElement('static', null, "<br />");

        // if yes, continue
        // else go to q16
        $this->addSelect("q12_pump_or_store_breast_milk", "12. Did you pump and store your own breast milk, if you breast fed?", $yes_no_options);

        $this->addLabel($this->indent."If Yes, then continue.  Otherwise, go to question 16.");

        $this->form->addElement('static', null, "<br />");

        // "13. What is the average time you stored your breast milk before feeding it to your child?"

        $this->addLabel("14. How often was your child fed your stored milk? For <i>frequency</i>, enter the average number of times your child was fed your stored milk per day, per week, or per month.");

        $this->form->addElement('static', null, "<br />");

        $q15_options = array(
                        null                   => "",
                        "specify_types_brands" => "Specify types/brands",
                        "dk"                   => "DK",
                        "rf"                   => "RF",
                       );

        $this->addSelect("q15_type_container_use_to_store_breast_milk", "15. What type of container did you use to store your breast milk?", $q15_options);

        $this->addBasicText("q15_if_specify", "$this->indent Specify types/brands:");

        $this->XINRegisterRule(
            "q15_if_specify",
            array("q15_type_container_use_to_store_breast_milk{@}=={@}specify_types_brands"),
            "Required."
        );

        //"16. At what age did you first introduce solid foods?"

        $q17_options = array(
                        null                   => "",
                        "before_10_months"     => "Before 10 months",
                        "between_10_12_months" => "Between 10-12 months",
                        "after_12_months"      => "After 12 months",
                        "dk"                   => "DK",
                        "rf"                   => "RF",
                       );

        $this->addSelect("q17_what age_child_diet_primarily_consist_of_table_food", "17. At what age did your child’s diet <b>primarily</b> consist of table food?  By <i>table food</i>, we mean food that is <b>not</b> made especially for babies and is also <b>not</b> transitional food (like stage-3 baby foods).", $q17_options);

        // $this->form->addFormRule(array(&$this, 'abcl_special_rules'));
    }


    /**
    * Generates the fifth page of the form.
    *
    * @return void
    */    
    /*
    function _page5()
    {
        $this->addHeader("Diet Survey Child 101112 Clean");

        $this->addLabel("18. ");

        // $this->form->addFormRule(array(&$this, 'abcl_special_rules'));
    }*/

    /**
    * Generates the sixth page of the form.
    *
    * @return void
    */
    /*function _page6()
    {
        $this->addHeader("Diet Survey Child 101112 Clean");

        $this->addLabel("19. ");
    }*/

    /**
    * Generates the seventh page of the form.
    *
    * @return void
    */
    /*function _page7()
    {
        $this->addHeader("Diet Survey Child 101112 Clean");

                $yes_no_options = array(
                   null  => "",
                   "yes" => "Yes",
                   "no"  => "No",
                   "dk"  => "DK",
                   "rf"  => "RF",
                  );

        $this->addLabel("20. ");

        $this->addLabel("21. What percentage of your child’s consumption of the food items below was organic (from a jar, a package, or homemade)?  Check the box with the closest percentage, or check ‘did  not eat’ if child did not eat this food item
        at all.");

        $q21_subquestions = array(
                            "q21a_during_first_3_months"   => "a. Vegetables",
                            "q21b_during_second_3_months" => "b. Fruit",
                            "q21c_during_first_3_months"   => "c. Meat/Poultry",
                            "q21d_during_second_3_months" => "d. Baby Cereal",
                           );

        $q21_options = array(
            null => "",
            "0_percent" => "0%",
            "1_to_24_percent" => "1-24%",
            "25_to_49_percent" => "25-49%",
            "50_to_74_percent" => "50-74%",
            "75_to_100_percent" => "75-100%",
            "did_not_eat" => "Did not eat",
            "dk" => "DK",
            "rf" => "RF",
        );

        foreach ($q21_subquestions as $question => $label) {
            $this->addSelect($question, $label, $q21_options);
        }

        $this->addSelect("q22_birth_to_present_child_receive_vitamins_supplements", "22. From birth to the present, did your child receive any vitamins or supplements", $yes_no_options);

        $this->addLabel("23. Which vitamins and supplements did your child receive from birth to the present? Under the column “How much and how often?” enter the number of pills, tablets or gel caps your child received per day, per week, or per month. If in liquid or powder form, enter the number of servings. Under the column “For how long?” enter the length of time your child took the vitamins or supplements during each year of her/his life. Specify the brands or supplement types in the spaces provided.");


        $this->addLabel("24. Was your child on any of the following food restrictions or special diets from birth to the present, where restriction means total as opposed to limited restriction. If your child was not on the diet or restriction listed, check <b>N/A</b>. For each diet or restriction your child was on, enter the years of the child’s life that the food was restricted or the child was on the special diet, who restricted the food or prescribed the special diet, and the reason. (<i>check all that apply</i>)");

        $q25_options = array(
                            null => "",
                            "very_picky_eater" => "Very picky eater",
                            "somewhat_picky_eater" => "Somewhat picky eater",
                            "not_picky_eater" => "Not a picky eater",
                            "dk" => "DK",
                            "rf" => "RF",
                            );

        $this->addSelect("q25_do_you_consider_your_child_a", "25. Do you consider your child a...", $q25_options);

        $q26_options = array(
                            null => "",
                            "has_strong_preferences_certain_textures" => "Has strong preferences for certain food textures; specify:",
                            "has_strong_dislikes_certain_textures" => "Has strong dislikes of certain food textures; specify: ",
                            "does_not_have_strong_preferences_dislikes_certain_textures" => "Does not have strong preferences or dislikes for certain food textures",
                            "has_strong_preferences_certain_foods" => "Has strong preferences for certain foods: specify:",
                            "has_strong_dislikes_certain_foods" => "Has strong dislikes for certain foods: specify: ",
                            "does_not_have_strong_preferences_dislikes_certain_foods" => "Does not have strong preferences or dislikes for certain foods",
                            "dk" => "DK",
                            "rf" => "RF",
                            );

        $this->addSelect("q26_considering_different_foods_would_say_child", "26. When considering different foods, would you say your child...", $q26_options);

        $this->addBasicText("q26_if_specify", "$this->indent Specify:");

        $this->XINRegisterRule(
            "q26_if_specify",
            array(
                "q26_considering_different_foods_would_say_child{@}=={@}has_strong_preferences_certain_textures|has_strong_dislikes_certain_textures|has_strong_preferences_certain_foods|has_strong_dislikes_certain_foods"),
            "Required."
        );

        $this->addLabel("<b>End of Diet Questionnaire</b>");
    }*/

    /**
     * Displays headers for column section
     */
    function _displayHeaders($category)
    {
            $group[] = $this->form->createElement(
                "static",
                null,
                null,
                "Bottles"
            );
            $group[] = $this->form->createElement(
                "static",
                null,
                null,
                "<b>Yes/No/DK/RF</b>"
            );
            $group[] = $this->form->createElement(
                "static",
                null,
                null,
                "<b>If yes, specify the brand[s] of bottle</b>"
            );
            $this->form->addGroup(
                $group,
                $category . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
    }

    // $skip_to = the number of the question that needs to be skipped to 
    function if_yes_continue($if_yes, $current_q, $skip_to) {
        $this->XINRegisterRule(
            $current_q,
            array("{$if_yes}{@}!={@}yes"),
            "Please go to question " . $skip_to
        );
    }

    
    function diet_survey_special_rules_page_1($values)
    {
        $errors = [];

        $questions = array(
            "q2a_clear_hard_plastic_no_inserts_liners_yes_no", 
            "q2a_clear_hard_plastic_no_inserts_liners_specify_brands",
            "q2b_clear_hard_plastic_with_inserts_liners_yes_no",
            "q2b_clear_hard_plastic_with_inserts_liners_specify_brands",
            "q2c_opaque_plastic_yes_no",
            "q2c_opaque_plastic_specify_brands",
            "q2d_glass_yes_no",
            "q2d_glass_specify_brands",
            "q2e_bpa_free_bottle_yes_no",
            "q2e_bpa_free_bottle_specify_brands",
            "q3_how_usually_heat_bottles",
            "q3_if_other",
            "q4_did_you_feed_infant_formula",
        );

        // If !yes, skip to question 12
        if ($values["q1_feed_child_bottle_once_per_week"] != "yes") {
            $this->validate_empty_subquestions($values, $questions, $errors);
        }

        return $errors;
     }
}
?>
