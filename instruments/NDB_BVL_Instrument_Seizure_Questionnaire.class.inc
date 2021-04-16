<?php
/*
 * This file contains the NDB_BVL_Instrument_Seizure_Questionnaire
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the Seizure_Questionnaire instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_Seizure_Questionnaire extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page      if a multipage form, the page to show
     *
     * @return void
     * @access public
     */
    function setup(?string $commentID = null, ?string $page = null): void
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('Seizure_Questionnaire_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = 'Seizure_Questionnaire';           // test_names.Test_name
        $this->table    = 'Seizure_Questionnaire';           // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array('CommentID');

        $config            = NDB_Config::singleton();
        $this->dateOptions = array(
                              'language'         => 'en',
                              'format'           => 'YMd',
                              'minYear'          => $config->getSetting('startYear'),
                              'maxYear'          => $config->getSetting('endYear'),
                              'addEmptyOption'   => true,
                              'emptyOptionValue' => null,
                             );

        // setup the form
        $this->_setupForm();
    }

    /*
    * Method to build the LorisForm object into a paged form
    *
    * @return void
    * @access private
    */
    function _setupForm()
    {
        //determine page to display
        if (preg_match(
            "/Seizure_Questionnaire(_page[0-9]+)/",
            $this->page,
            $matches
        )
        ) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    function _main()
    {
        // display test name
        $this->addHeader("Seizure Questionnaire");

        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

        $opts = array(
                 null          => "",
                 "mother"      => "Mother",
                 "father"      => "Father",
                 "step_mother" => "Step Mother",
                 "step_father" => "Step Father",
                 "other"       => "Other",
                );
        $this->addSelect("relationship_to_child", "What is your relationship to the child?", $opts);
        $this->addBasicText("relationship_to_child_other", $this->indent."If Other, please describe:");
        $this->XINRegisterRule(
            "relationship_to_child_other",
            array("relationship_to_child{@}=={@}other"),
            "Required",
            "relationship_to_child_other"
        );

        // SCORING TABLE

        $this->form->addElement('header', null, "Score Summary");

        $group[] = $this->form->createElement('static', "score", null, null);

        $this->form->addGroup($group, 'score_header_group', "<strong>Scale</strong>", $this->_GUIDelimiter, false);
        unset($group);

        $scales = array(
                   "seizure_screening_total"        => "Seizure Screening Total",
                   "subscale1_seizure_frequency"    => "Subscale1 Seizure Frequency",
                   "subscale2_time_period"          => "Subscale2 Time Period",
                   "subscale3_num_of_seizure_types" => "Subscale3 Number of Seizure Types",
                   "subscale4_epilepticus"          => "Subscale4 Epilepticus",
                   "total_severity"                 => "Total Severity Score",
                  );

        $columnHeaders = array("score" => "Score");

        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "     ";
        }

        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        foreach ($scales as $field => $label) {
            foreach ($columnHeaders as $scoreField => $scoreLabel) {
                $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
            }
            $this->form->addGroup($group, "{$field}_score_group", $label, $this->_GUIDelimiter, false);
            unset($group);
        }
    }

    function _page1()
    {
        $page1options =
            array(
             null        => "",
             "yes"       => "Yes",
             "no"        => "No",
             "possible"  => "Possible",
             "dont_know" => "Don't know",
            );

        $q3labels = array(
                     "p1_3a" => "(a) A seizure, convulsion, fit or spell under any circumstances?",
                     "p1_3b" => "(b) Uncontrolled movements of part (or all) of their body such as: twiching,
                jerking, shaking, or going limp?",
                     "p1_3c" => "(c) An unexplained change in their mental state or level of awareness;
                or an episode of \"spacing\" out that he/she could not control? (non-responsive)",
                     "p1_3d" => "(d) When he/she was a small child, would he/she daydream or stare into
                 space more than other children?",
                     "p1_3e" => "(e) Has anyone ever noticed unusual body movements, or has your child
                 expressed unusual feelings when she/he was exposed to strobe lights, video games,
                 flickering lights, or sun glare?",
                     "p1_3f" => "(f) Shortly after waking up (either in the morning or after a nap) has anyone
                ever noticed uncontrollable jerking or clumsiness in your child, such as dropping things
                or things suddenly \"flying\" from his/her hands",
                     "p1_3g" => "(g) Has he/she ever had any other type of repeated unusual spells? (Strange behaviors,
                 anything out of the ordinary",
                     "p1_3h" => "(h) Has your child ever seen or been referred to a neurologist?",
                    );

        $this->addSelect(
            "p1_1",
            "1. Has your child ever had a seizure or convulsion caused by a high fever? (uncontrollable
            shaking of limbs)",
            $page1options
        );
        $this->addSelect(
            "p1_2",
            "2. Other than the seizure caused by a high fever, has your child ever had (or has a physician
            ever said your child had) a seizure disorder or epilepsy?",
            $page1options
        );

        $this->addHeader(
            "<BR>If YES (selected for question 2), please skip ahead to the next page.
                              <BR>If NO, POSSIBLE, or DON'T KNOW (selected for question 2), please complete the <u>rest of this page</u> AND the <u>next page</u></h4>"
        );
        $this->addHeader(
            "<h4>3. Other than the seizure caused by a high fever, has your child ever had
                        (or has a physician ever said your child had) any of the following..."
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
            "Options"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Notes:"
        );
        $this->addGroup(
            $group,
            "q3_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        foreach ($q3labels as $name => $label) {
            $group[] =& $this->createLabel(
                $label
            );
            $group[] =& $this->createSelect(
                $name,
                "",
                $page1options
            );
            $this->XINRegisterRule(
                $name,
                array("p1_2{@}=={@}no|possible|dont_know"),
                "Q3 must be answered if NO, POSSIBLE, or DON'T KNOW is selected for Q2",
                $name . "_group"
            );
            $group[] =& $this->createText(
                $name . "_notes",
                "Notes:"
            );
            $this->XINRegisterRule(
                $name . "_notes",
                array("{$name} . _notes{@}=={@}NEVER_REQUIRED"),
                "Not required.",
                $name . "_group"
            );
            $this->addGroup(
                $group,
                $name . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
    }

    function _page2()
    {
        $this->addHeader(
            "<h4>Of the following types of seizures, please mark which types your
        child has *<u>ever</u>* experienced (and how often & for how long)"
        );

        $page2Questions =
            array(
             "p2_1" => "1. Stiffening of the whole body or part of the body (tonic seizure)",
             "p2_2" => "2. Shaking of only part of the body (partial or focal motor seizure)",
             "p3_3" => "3. Infantile spasm: seizure seen in infancy or early childhood.",
             "p3_4" => "4. Whole body shaking (grand mal, generalized or secondary tonic-clonic seizure",
             "p3_5" => "5. Drop spell: head or body goes limp while child is still conscious (atonic seizure)",
             "p3_6" => "6. Staring spell: unresponsive, staring off with a vacant expression for brief periods of time (petit mal, absence or complex partial seizure)",
             "p3_7" => "7. Very quick jerks or shaking (myoclonic seizure)",
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
            "How often does/did this occur?"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Over how long of a time period did these seizures occur?"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Did any episode last over 30 min?"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Number of minutes in duration"
        );
        $this->addGroup(
            $group,
            "page2_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        foreach ($page2Questions as $name => $label) {
            $group[]    =& $this->createLabel($label);
            $group[]    =& $this->createSelect(
                $name . "_frequency",
                "",
                array(
                 null                      => "",
                 "never_occurred"          => "Never occurred",
                 "less_than_once_per_year" => "Less than once a year",
                 "more_than_once_a_year"   => "More than once a year (but not monthly)",
                 "1_or_more_each_month"    => "1 or more each month (but not weekly)",
                 "1_or_more_each_week"     => "1 or more each week (but not daily)",
                 "daily"                   => "Daily",
                )
            );
            $group[]    =& $this->createSelect(
                $name . "_period",
                "",
                array(
                 null                   => "",
                 "never_occurred"       => "Never occurred",
                 "less_than_a_month"    => "These seizures occurred for less than a month",
                 "one_to_six_months"    => "These seizures occurred for 1-6 months",
                 "more_than_six_months" => "These seizures occurred for more than 6 months",
                )
            );
            $group[]    =& $this->createSelect(
                $name . "_last_over_30min",
                "",
                array(
                 null  => "",
                 "no"  => "No",
                 "yes" => "Yes",
                )
            );
            $group[]    =& $this->createTextArea(
                $name . "_duration",
                ""
            );
            $ruleValues = array(
                           'less_than_once_per_year',
                           'more_than_once_a_year',
                           '1_or_more_each_month',
                           '1_or_more_each_week',
                           'daily',
                          );
            $this->XINRegisterRule(
                $name . "_period",
                array("{$name}_frequency{@}=={@}".implode('|', $ruleValues)),
                "Required, unless NEVER OCCURRED is selected.",
                $name . "_group"
            );
            $this->XINRegisterRule(
                $name . "_last_over_30min",
                array("{$name}_frequency{@}=={@}".implode('|', $ruleValues)),
                "Required, unless NEVER OCCURRED is selected.",
                $name . "_group"
            );
            $this->XINRegisterRule(
                $name . "_duration",
                array("{$name}_last_over_30min{@}=={@}yes"),
                "Required if YES selected for episode lasting over 30 min.",
                $name . "_group"
            );
            $this->addGroup(
                $group,
                $name . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
        $this->form->addFormRule(array(&$this, "validateNumerics"));
    }

    function _page3()
    {
        $this->addHeader(
            "MEDICATIONS: Please list any related medications/anticonvulsants
            your child has *ever* been treated with: (examples are below)"
        );

        $this->addHeader(
            "<h5><BR><u><b>Some Examples of Medications Prescribed for Seizures</b></u><BR>(*Note: this list is not exhaustive.)<BR>$this->indent - Barbiturates: Phenoarb<BR>$this->indent - Benzodiazepines: Valium, Klonopin
                              <BR>$this->indent - Carbamezine: Tegretol<BR>
                              $this->indent - Gabapentin: Neurontin<BR>
                              $this->indent - Lamotrigine: Lamictal<BR>
                              $this->indent - Phenytoin: Dilantin<BR>
                              $this->indent - Pregabalin: Lyrica<BR>
                              $this->indent - Tiagabine: Gabitril<BR>
                              $this->indent - Topiramate: Topamax<BR>
                              $this->indent - Valproic Acid: Depakote<BR>
                              $this->indent - Zonisamide: Zonegran</h5>"
        );

        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Medication"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Efficacy"
        );
        $this->addGroup(
            $group,
            "page3_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        for ($i=1; $i <= 4; $i++) {
            $group[] =& $this->createText(
                "medication_{$i}",
                ""
            );
            $group[] =& $this->createSelect(
                "medication_" . $i . "_efficacy",
                "How effective was this medication?",
                array(
                 null                          => "",
                 "stopped_seizures_completely" => "Medication stopped seizures completely",
                 "partial_reduction"           => "Medication partially reduced frequency or length of seizures",
                 "no_improvement"              => "No improvement in seizures",
                 "adverse_reaction"            => "Medication was stopped due to adverse reaction",
                )
            );
            $this->XINRegisterRule(
                "medication_{$i}",
                array("medication_{$i}{@}=={@}NEVER_REQUIRED"),
                "Not required.",
                "medication_" . $i . "_group"
            );
            $this->XINRegisterRule(
                "medication_" . $i . "_efficacy",
                array("medication_{$i}{@}!={@}"),
                "Efficacy of medication is required.",
                "medication_" . $i . "_group"
            );
            $this->addGroup(
                $group,
                "medication_" . $i . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
    }

    /**
     * Validates grouped numeric inputs
     *
     * @return array Array of errors
     */
    function validateNumerics($values)
    {
        $errors    = array();
        $questions = array(
                      "p2_1_duration",
                      "p2_2_duration",
                      "p2_3_duration",
                      "p2_4_duration",
                      "p2_5_duration",
                      "p2_6_duration",
                      "p2_7_duration",
                     );
        foreach ($questions as $question) {
            if ((!is_numeric($values[$question])) && !empty($values[$question])) {
                $errors[$question] = "Please enter a numeric value.";
            }
        }
        return $errors;
    }

    /**
     * Used to sum Seizure Screening Total Score
     *
     * Given the user's input for a screening question, returns the appropriate score
     *
     * Yes = 2
     * Possible = 1
     * Don't know = 0
     * No = 0
     *
     * @param  string $response user input for a question
     * @return integer
     */
    function getScreeningScore($response)
    {
        if ($response == "yes") {
            return 2;
        } elseif ($response == "possible") {
            return 1;
        } else {
            return 0;
        }
    }

    /**
     * Used to get Subscale1: Frequency of Seizures Score
     *
     * Given the user's input for a _frequency question, returns the appropriate score
     *
     * Never occurred = 0
     * Less than once a year = 1
     * More than once a year = 2
     * 1 or more each month = 3
     * 1 or more each week = 4
     * Daily = 5
     *
     * @param  string $response user input for a question
     * @return integer
     */
    function getFrequencyScore($response)
    {
        if ($response == "never_occurred") {
            return 0;
        } elseif ($response == "less_than_once_per_year") {
            return 1;
        } elseif ($response == "more_than_once_a_year") {
            return 2;
        } elseif ($response == "1_or_more_each_month") {
            return 3;
        } elseif ($response == "1_or_more_each_week") {
            return 4;
        } elseif ($response == "daily") {
            return 5;
        }
    }

    /**
     * Used to get Subscale2: Time Period Score
     *
     * Given the user's input for a _period question, returns the appropriate score
     *
     * Never occurred = 0
     * Less than a month = 1
     * One to six months = 2
     * More than six months = 3
     *
     * @param  string $response user input for a question
     * @return integer
     */
    function getPeriodScore($response)
    {
        if ($response == "never_occurred") {
            return 0;
        } elseif ($response == "less_than_a_month") {
            return 1;
        } elseif ($response == "one_to_six_months") {
            return 2;
        } elseif ($response == "more_than_six_months") {
            return 3;
        }
    }

    /**
     * Used to get Subscale4: Epilepticus Score
     *
     * Given the user's input for a _duration question, returns the appropriate score
     *
     * No response, 0, or <30 = 0
     * 30-60 minutes = 2
     * >60 minutes = 3
     *
     * @param  string $response user input for a question
     * @return integer
     */
    function getDurationScore($response)
    {
        if ($response > 60) {
            return 3;
        } elseif ($response < 60 && $response >= 30) {
            return 2;
        } else {
            return 0;
        }
    }

    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        $db     = Database::singleton();
        $record = $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid", array("cid" => $this->getCommentID()));

        $scores = array(
                   "seizure_screening_total_score"        => 0,
                   "subscale1_seizure_frequency_score"    => 0,
                   "subscale2_time_period_score"          => 0,
                   "subscale3_num_of_seizure_types_score" => 0,
                   "subscale4_epilepticus_score"          => 0,
                   "total_severity_score"                 => 0,
                  );

        /***************************
         * SEIZURE SCREENING TOTAL *
         ***************************/
        // Sum of all points for screening questions:

        $seizure_screening_total_questions = array(
                                              "p1_3a",
                                              "p1_3b",
                                              "p1_3c",
                                              "p1_3d",
                                              "p1_3e",
                                              "p1_3f",
                                              "p1_3g",
                                              "p1_3h",
                                             );

        $seizure_screening_total = 0;

        foreach ($seizure_screening_total_questions as $field) {
            $seizure_screening_total += $this->getScreeningScore($record[$field]);
        }

        $scores["seizure_screening_total_score"] = $seizure_screening_total;

        /*************************************
         * SUBSCALE 1: FREQUENCY OF SEIZURES *
         *************************************/
        // Highest score out of these 7 variables
        // (NOT SUM, just highest reported frequency for the 7 types)

        $seizure_frequency_questions = array(
                                        "p2_1_frequency",
                                        "p2_2_frequency",
                                        "p3_3_frequency",
                                        "p3_4_frequency",
                                        "p3_5_frequency",
                                        "p3_6_frequency",
                                        "p3_7_frequency",
                                       );

        $seizure_frequency_highest_score = 0;

        foreach ($seizure_frequency_questions as $field) {
            if ($seizure_frequency_highest_score < $this->getFrequencyScore($record[$field])) {
                $seizure_frequency_highest_score = $this->getFrequencyScore($record[$field]);
            }
        }

        $scores["subscale1_seizure_frequency_score"] = $seizure_frequency_highest_score;

        /***************************
         * SUBSCALE 2: TIME PERIOD *
         ***************************/
        // Highest score out of these 7 variables (NOT SUM)

        $seizure_period_questions = array(
                                     "p2_1_period",
                                     "p2_2_period",
                                     "p3_3_period",
                                     "p3_4_period",
                                     "p3_5_period",
                                     "p3_6_period",
                                     "p3_7_period",
                                    );

        $seizure_period_highest_score = 0;

        foreach ($seizure_period_questions as $field) {
            if ($seizure_period_highest_score < $this->getFrequencyScore($record[$field])) {
                $seizure_period_highest_score = $this->getFrequencyScore($record[$field]);
            }
        }

        $scores["subscale2_time_period_score"] = $seizure_period_highest_score;

        /***************************************
         * SUBSCALE 3: NUMBER OF SEIZURE TYPES *
         ***************************************/
        // Out of the 7 seizure types listed,
        // How many of them (listed below) were rated anything anything above 0/never occurred?
        // Give 1 point per each seizure type

        $num_seizure_types = 0;

        foreach ($seizure_frequency_questions as $field) {
            if ($record[$field] != "never_occurred") {
                $num_seizure_types ++;
            }
        }

        $scores["subscale3_num_of_seizure_types_score"] = $num_seizure_types;

        /***************************
         * SUBSCALE 4: EPILEPTICUS *
         ***************************/
        // Highest score out of these 7 variables (NOT SUM)
        // Caveat: Fields are varchars, therefore input is not guaranteed to be a number

        $seizure_duration_questions = array(
                                       "p2_1_duration",
                                       "p2_2_duration",
                                       "p3_3_duration",
                                       "p3_4_duration",
                                       "p3_5_duration",
                                       "p3_6_duration",
                                       "p3_7_duration",
                                      );

        $duration_highest_score = 0;

        foreach ($seizure_duration_questions as $field) {
            if ($duration_highest_score < $this->getDurationScore($record[$field])) {
                $duration_highest_score = $this->getDurationScore($record[$field]);
            }
        }

        $scores["subscale4_epilepticus_score"] = $duration_highest_score;

        /************************
         * TOTAL SEVERITY SCORE *
         ************************/
        // Sum of all 4 subscale scores

        $scores["total_severity_score"] = $scores["subscale1_seizure_frequency_score"] +
                                          $scores["subscale2_time_period_score"] +
                                          $scores["subscale3_num_of_seizure_types_score"] +
                                          $scores["subscale4_epilepticus_score"];

        $db->update($this->table, $scores, array("CommentID" => $this->getCommentID()));
    }
}
