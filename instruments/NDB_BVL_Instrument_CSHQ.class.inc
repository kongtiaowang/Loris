<?php
/**
 * This file contains the NDB_BVL_Instrument_CSHQ
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
 * Creates the form elements for the CDI_Words_Sentences instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_CSHQ extends NDB_BVL_Instrument_survey
{
    use LegacyInstrumentTrait;
    use instrument_validator;
    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    var $LONG_CSHQ_QUESTIONS = [
        "falls_asleep_with_movement",
        "falls_asleep_with_object",
        "ready_to_go_to_bed",
        "resists_going_to_bed",
        "sleeps_too_much",
        "reports_pain_during_sleep",
        "complains_about_sleeping_problems",

        "returns_to_sleep_without_help",
        "wakes_up_with_alarm_clock",
        "wakes_up_early",
        "good_appetite_in_morning",
        "naps_during_day",
        "suddenly_falls_asleep",
        "play_alone",
        "eating_meals"
    ];

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
        $this->form     = new LorisForm('CSHQ_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = 'CSHQ';           // test_names.Test_name
        $this->table    = 'CSHQ';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here

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

        $this->scoreCols = [];

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
            "/CSHQ(_page[0-9]+)/",
            $this->page,
            $matches
        )
        ) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
            $this->form->addFormRule(array(&$this, 'XINValidate'));
        }
    }

    /**
     * Overriden _saveValue function that adds this to the standard behaviour:
     *
     * - if the abbreviated version is saved, all the answers to the questions that
     *   belong exclusively to the long CSHQ are set to NULL.
     */
    function _saveValues(array $values): void
    {
        $isDataEntryStaffEditingForm = !is_null($_SESSION['State']->getUsername());
        if ($this->getFieldValue("which_cshq_did_you_administer") == "a_abbreviated"
          && $isDataEntryStaffEditingForm
        ) {
            foreach ($this->LONG_CSHQ_QUESTIONS as $question) {
                if ($question == "play_alone" || $question == "eating_meals") {
                    $values[$question] = null;
                } else {
                    $values["{$question}_frequency"] = null;
                    $values["{$question}_problem"]   = null;
                    if ($question == "reports_pain_during_sleep") {
                        $values["reports_pain_during_sleep_body_pain"] = null;
                    }
                }
            }
        }
        parent::_saveValues($values);
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
        $this->addHeader("Child's Sleep Habit  (Preschool and School Aged)");

        // If the session's user name is not null then it means that this instrument is
        // being accessed through the timepoint list by someone who logged into LORIS
        // (i.e. we are not in real "survey" mode)
        $isDataEntryStaffEditingForm = !is_null($_SESSION['State']->getUsername());

        // Data entry staff get to answer this question
        if ($isDataEntryStaffEditingForm) {
            $cshq_options = array(
                "a_abbreviated" => "a) The abbreviated 33 question version (this is not the version recommended to administer)",
                "b_long_form"   => "b) The long form 52 question version (this is the version that is recommended)",
            );

            $this->addSelect(
                "which_cshq_did_you_administer",
                "<u>For Study Staff Only</u>: Which CSHQ did you administer?",
                $cshq_options
            );
        // Participants who fill the survey cannot answer the question: they can only
        // see what type of questionnaire they are filling
        } else {
            $formAdministered = $this->getFieldValue("which_cshq_did_you_administer") == "b_long_form"
                ? "b) The long form 52 question version (this is the version that is recommended)"
                : "a) The abbreviated 33 question version (this is not the version recommended to administer)";
            $this->addLabel(
                "<u>For Study Staff Only</u>: Which CSHQ did you administer? " . $formAdministered
            );
        }

        // This is a survey: we do not want to force the entry staff to enter an
        // administration date
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
        if (isDataEntryStaffEditingForm) {
            $this->XINRegisterRule("Date_taken", array("Date_taken{@}=={@}NEVER_REQUIRED"), "Not required");
        }
        $score_columns
            = array(
               'bedtime_resistance'         => 'Bedtime Resistance',
               'sleep_onset_delay'          => 'Sleep Onset Delay',
               'sleep_duration'             => 'Sleep Duration',
               'sleep_anxiety'              => 'Sleep Anxiety',
               'night_wakings'              => 'Night Wakings',
               'parasomnias'                => 'Parasomnias',
               'sleep_disordered_breathing' => 'Sleep Disordered Breathing',
               'daytime_sleepiness'         => 'Daytime Sleepiness',
               'total_score'                => 'Total Score',
              );

        while ($i = current($score_columns)) {
            $f       = key($score_columns);
            $group[] = $this->form->createElement('static', "$f", null, null);
            $this->form->addGroup($group, "{$f}_score_group", "$i:", $this->_GUIDelimiter, false);
            unset($group);
            next($score_columns);
        }
        $opts = array(
                 null          => "",
                 "mother"      => "Mother",
                 "father"      => "Father",
                 "step_mother" => "Step Mother",
                 "step_father" => "Step Father",
                 "other"       => "Other",
                );
        $this->addSelect("relationship_to_child", "What is your relationship to the child?", $opts);
        // This is a survey: we do not want to force the data entry staff to enter
        // the relationship to child
        if (isDataEntryStaffEditingForm) {
            $this->XINRegisterRule("relationship_to_child", array("relationship_to_child{@}=={@}NEVER_REQUIRED"), "Not required");
        }

        $this->addBasicText("other_relationship_to_child", $this->indent."If Other, please describe:");
        $this->XINRegisterRule(
            "other_relationship_to_child",
            array("relationship_to_child{@}=={@}other"),
            "Required",
            "other_relationship_to_child"
        );
    }

    function _displayHeaders($category)
    {
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Frequency</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Problem</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            ""
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            ""
        );
        $this->form->addGroup(
            $group,
            $category . "_group",
            $this->_GUIDelimiter,
            false
        );
        unset($group);
    }

    function _displayHeadersSleepBehaviors($category)
    {
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Frequency</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Problem</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            ""
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            ""
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            ""
        );
        $this->form->addGroup(
            $group,
            $category . "_group",
            $this->_GUIDelimiter,
            false
        );
        unset($group);
    }

    function _page1()
    {
        $answer_choices    = array(
                              null => "",
                              3    => "Usually (5-7)",
                              2    => "Sometimes (2-4)",
                              1    => "Rarely (0-1)",
                             );
        $answer_choices_na = array(
                              null => "",
                              3    => "Usually (5-7)",
                              2    => "Sometimes (2-4)",
                              1    => "Rarely (0-1)",
                              'na' => "Not Applicable",
                             );
        $problem_choices   = array(
                              null  => "",
                              1     => "Yes",
                              0     => "No",
                              "n/a" => "N/A",
                             );

        $this->addHeader("Child's Sleep Habit (Preschool and School-Aged)");

        $this->addHeader(
            "<h4>The following statements are about your child’s sleep
            habits and possible difficulties with sleep. Think about the
            past week in your child’s life when answering the questions.
            If last week was unusual for a specific reason (such as your
            child had an ear infection and did not sleep well or
            the TV set was broken), choose the most recent typical week.
            Answer USUALLY if something occurs <b>5 or more times</b> in
            a week; answer SOMETIMES if it occurs <b>2-4 times</b> in a
            week; answer RARELY if something occurs
            <b>never or 1 time</b> during a week. Also, please indicate
            whether or not the sleep habit is a problem by circling “Yes,”
            “No,” or Not applicable (N/A).</h4>"
        );

        // If the session's user name is not null then it means that this instrument is
        // being accessed through the timepoint list by someone who logged into LORIS
        // (i.e. we are not in real "survey" mode)
        $isDataEntryStaffEditingForm = !is_null($_SESSION['State']->getUsername());

        // Whether the long or abbreviated questionnaire is administered
        $isLongQuestionnaire         = $this->getFieldValue("which_cshq_did_you_administer") != "a_abbreviated";

        $bedtime_questions        = array(
                                     "goes_to_bed_at_same_time_item1"      => "Child goes to bed at the same time at night.",
                                     "falls_asleep_in_20_min_item2"        => "Child falls asleep within 20 minutes after going to bed.",
                                     "falls_asleep_in_own_bed_item3"       => "Child falls asleep in own bed.",
                                     "falls_asleep_in_others_bed_item4"    => "Child falls asleep in parent's or sibling's bed",
                                     "falls_asleep_with_movement"          => "Child falls asleep with rocking or rhythmic movements.",
                                     "falls_asleep_with_object"            => "Child needs special object to fall asleep (dolls, special blanket, etc.)",
                                     "needs_parent_in_room_to_sleep_item5" => "Child needs parent in the room to fall asleep.",
                                     "ready_to_go_to_bed"                  => "Child is ready to go to bed at bedtime.",
                                     "resists_going_to_bed"                => "Child resists going to bed at bedtime.",
                                     "struggles_at_bedtime_item6"          => "Child struggles at bedtime (cries, refuses to stay in bed, etc.)",
                                     "afraid_of_sleeping_in_dark_item7"    => "Child is afraid of sleeping in the dark.",
                                     "afraid_of_sleeping_alone_item8"      => "Child is afraid of sleep alone.",
                                    );
        $sleep_behavior_questions = array(
                                     "sleeps_too_little_item9"             => "Child sleeps too little.",
                                     "sleeps_too_much"                     => "Child sleeps too much",
                                     "sleeps_right_amount_item10"          => "Child sleeps the right amount",
                                     "sleeps_same_amount_each_day_item11"  => "Child sleeps about the same amount each day.",
                                     "wets_bed_at_night_item12"            => "Child wets the bed at night.",
                                     "talks_during_sleep_item13"           => "Child talks during sleep.",
                                     "restless_and_moves_alot_item14"      => "Child is restless and moves a lot during sleep.",
                                     "sleepwalks_item15"                   => "Child sleepwalks during the night.",
                                     "moves_to_others_bed_at_night_item16" => "Child moves to someone else's bed during the night (parent, brother, sister, etc.)",
                                     "reports_pain_during_sleep"           => "Child reports pain during sleep.",
                                     "grinds_teeth_during_sleep_item17"    => "Child grinds teeth during sleep (your dentist may have told you this).",
                                     "snores_loudly_item18"                => "Child snores loudly.",
                                     "stops_breathing_item19"              => "Child seems to stop breathing during sleep.",
                                     "snorts_and_gasps_item20"             => "Child snorts and/or gasps during sleep.",
                                     "trouble_sleeping_away_item21"        => "Child has trouble sleeping away from home (visiting relatives, vacation).",
                                     "complains_about_sleeping_problems"   => "Child complains about problems sleeping.",
                                     "awakens_screaming_sweating_item22"   => "Child awakens during night screaming, sweating, and inconsolable.",
                                     "alarmed_by_scary_dream_item23"       => "Child awakens alarmed by a frightening dream.",
                                    );

        $this->addHeader("<h4><b><u>Bedtime</u></b></h4>");
        $this->addHourMinElement('bed_time', 'Write in the child\'s bedtime:');

        $this->_displayHeaders("bedtime");

        $a = 0;

        foreach ($bedtime_questions as $question => $label) {
            $a++;

            // Don't display the question if it is exclusively for the long CSHQ and
            // we are administering the short version
            if (!$isLongQuestionnaire && $this->isQuestionForLongCshq($question)) {
                continue;
            }

            $group[] = $this->createLabel($label);
            $group[] = $this->createSelect(
                $question . "_frequency",
                "",
                $answer_choices
            );
            $group[] = $this->createSelect(
                $question . "_problem",
                "",
                $problem_choices
            );
            $this->form->addGroup(
                $group,
                "section1_row{$a}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                $question . "_frequency",
                array($question . "_frequency{@}=={@}"), // rule
                "Field is required.", // message
                "section1_row{$a}" // group [if field is a part of a group]
            );
            $this->XINRegisterRule(
                $question . "_problem",
                array($question . "_problem{@}=={@}"), // rule
                "Field is required.", // message
                "section1_row{$a}" // group [if field is a part of a group]
            );
        }

        $this->addHeader("<h4><b><u>Sleep Behaviour</u></b></h4>");
        $this->displayHourMinElementCustom(
            'sleep_behavior_duration',
            'Child\'s usual amount of sleep each day:',
            'Usual amount of daily sleep'
        );

        $this->_displayHeadersSleepBehaviors("sleep_behavior");

        $b = 0;

        foreach ($sleep_behavior_questions as $question => $label) {
            $b++;
            // Don't display the question if it is exclusively for the long CSHQ and
            // we are administering the short version
            if (!$isLongQuestionnaire && $this->isQuestionForLongCshq($question)) {
                continue;
            }
            $group[] = $this->createLabel($label);
            if ($question=='sleeps_same_amount_each_day_item11') {
                $group[] = $this->createSelect(
                    $question . "_frequency",
                    "",
                    $answer_choices_na
                );
            } else {
                $group[] = $this->createSelect(
                    $question . "_frequency",
                    "",
                    $answer_choices
                );
            }
            $group[] = $this->createSelect(
                $question . "_problem",
                "",
                $problem_choices
            );
            if ($question == "reports_pain_during_sleep") {
                $group[] = $this->createLabel("If child reports body pain during sleep, where?");
                $group[] = $this->createText(
                    $question . "_body_pain",
                    ""
                );
            } else {
                $group[] = $this->createLabel("");
                $group[] = $this->createLabel("");
            }
            $this->form->addGroup(
                $group,
                "section2_row{$b}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);

            $this->XINRegisterRule(
                $question . "_frequency",
                array($question . "_frequency{@}=={@}"), // rule
                "Field is required.", // message
                "section2_row{$b}" // group [if field is a part of a group]
            );
            $this->XINRegisterRule(
                $question . "_problem",
                array($question . "_problem{@}=={@}"), // rule
                "Field is required.", // message
                "section2_row{$b}" // group [if field is a part of a group]
            );
            if ($question == 'reports_pain_during_sleep') {
                $this->XINRegisterRule(
                    $question . "_body_pain",
                    array("{$question}_problem{@}=={@}1"), // rule
                    "Field is required.", // message
                    "section2_row{$b}" // group [if field is a part of a group]
                );
            }
        }

        $this->form->addFormRule(array(&$this, 'XINValidate'));
        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    /**
     * Determines if a question is asked only in the long version of
     * the CSHQ.
     *
     * @param string $questionID ID of the question.
     *
     * @return bool true if the question is asked only in the long version of
     *              the CSHQ, false otherwise.
     */
    function isQuestionForLongCshq(string $questionID) {
        return in_array($questionID, $this->LONG_CSHQ_QUESTIONS);
    }

    function _page2()
    {
        $isLongQuestionnaire         = $this->getFieldValue("which_cshq_did_you_administer") != "a_abbreviated";

        // If the session's user name is not null then it means that this instrument is
        // being accessed through the timepoint list by someone who logged into LORIS
        // (i.e. we are not in real "survey" mode)
        $isDataEntryStaffEditingForm = !is_null($_SESSION['State']->getUsername());

        $answer_choices  = array(
                            null => "",
                            3    => "Usually (5-7)",
                            2    => "Sometimes (2-4)",
                            1    => "Rarely (0-1)",
                           );
        $problem_choices = array(
                            null  => "",
                            1     => "Yes",
                            0     => "No",
                            "n/a" => "N/A",
                           );

        $sleepy_choices = array(
                           null => "",
                           "1"  => "Not sleepy",
                           "2"  => "Very Sleepy",
                           "3"  => "Falls Asleep",
                          );

        $this->addHeader("Child's Sleep Habit (Preschool and School-Aged)");

        $waking_during_night_questions = array(
                                          "awakes_once_item24"            => "Child awakes once during the night.",
                                          "awakes_more_than_once_item25"  => "Child awakes more than once during the night.",
                                          "returns_to_sleep_without_help" => "Child returns to sleep without help after waking.",
                                          //"length_waking" => "Write the number of minutes a night waking usually lasts:"
                                         );
        $morning_waking_questions     = array(
                                         "wakes_by_himself_item26"             => "Child wakes up by him/herself.",
                                         "wakes_up_with_alarm_clock"           => "Child wakes up with alarm clock.",
                                         "wakes_up_in_neg_mood_item27"         => "Child wakes up in negative mood.",
                                         "others_wake_child_item28"            => "Adults or siblings wake up child.",
                                         "hard_time_getting_out_of_bed_item29" => "Child has difficulty getting out of bed in the morning",
                                         "takes_long_time_to_be_alert_item30"  => "Child takes a long time to become alert in the morning.",
                                         "wakes_up_early"                      => "Child wakes up very early in the morning.",
                                         "good_appetite_in_morning"            => "Child has a good appetite in the morning.",
                                        );
        $daytime_sleepiness_questions = array(
                                         "naps_during_day"       => "Child naps during the day.",
                                         "suddenly_falls_asleep" => "Child suddenly falls asleep in the middle of active behavior.",
                                         "seems_tired_item31"    => "Child seems tired.",
                                        );

        $this->addHeader("<h4><b><u>Waking During the Night</u></b></h4>");
        $this->_displayHeaders("waking_during_night");
        $a =0;
        foreach ($waking_during_night_questions as $question => $label) {
            $a++;

            // Don't display the question if it is exclusively for the long CSHQ and
            // we are administering the short version
            if (!$isLongQuestionnaire && $this->isQuestionForLongCshq($question)) {
                continue;
            }

            $group[] = $this->createLabel($label);
            $group[] = $this->createSelect(
                $question . "_frequency",
                "",
                $answer_choices
            );
            $group[] = $this->createSelect(
                $question . "_problem",
                "",
                $problem_choices
            );
            $this->form->addGroup(
                $group,
                "page2_section1_row{$a}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);

            $this->XINRegisterRule(
                $question . "_frequency",
                array($question . "_frequency{@}=={@}"), // rule
                "Field is required.", // message
                "page2_section1_row{$a}" // group [if field is a part of a group]
            );
            $this->XINRegisterRule(
                $question . "_problem",
                array($question . "_problem{@}=={@}"), // rule
                "Field is required.", // message
                "page2_section1_row{$a}" // group [if field is a part of a group]
            );
        }

        $field = "waking_during_night_duration";$label = "<h5><i>Please enter a numerical value for the number of minutes waking usually last per night or write NA</i></h5>";
        $group[] = $this->createText($field, $label);
        $this->addGroup($group, $field . "_group", $label, null, false);
        unset($group);

        $this->addHeader("<h4><b><u>Morning Waking</u></b></h4>");
        $this->addHourMinElement(
            'morning_waking_time',
            'Write in the time of day child usually wakes in the morning.',
            array(),
            'This field is required',
            true
        );

        $this->_displayHeaders("morning_waking");
        $b =0;
        foreach ($morning_waking_questions as $question => $label) {
            $b++;

            // Don't display the question if it is exclusively for the long CSHQ and
            // we are administering the short version
            if (!$isLongQuestionnaire && $this->isQuestionForLongCshq($question)) {
                continue;
            }

            $group[] = $this->createLabel($label);
            $group[] = $this->createSelect(
                $question . "_frequency",
                "",
                $answer_choices
            );
            $group[] = $this->createSelect(
                $question . "_problem",
                "",
                $problem_choices
            );
            $this->form->addGroup(
                $group,
                "page2_section2_row{$b}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                $question . "_frequency",
                array($question . "_frequency{@}=={@}"), // rule
                "Field is required.", // message
                "page2_section2_row{$b}" // group [if field is a part of a group]
            );
            $this->XINRegisterRule(
                $question . "_problem",
                array($question . "_problem{@}=={@}"), // rule
                "Field is required.", // message
                "page2_section2_row{$b}" // group [if field is a part of a group]
            );
        }

        $this->addHeader("<h4><b><u>Daytime Sleepiness</u></b></h4>");
        $c =0;
        $this->_displayHeaders("daytime_sleepiness");
        foreach ($daytime_sleepiness_questions as $question => $label) {
            $c++;

            // Don't display the question if it is exclusively for the long CSHQ and
            // we are administering the short version
            if (!$isLongQuestionnaire && $this->isQuestionForLongCshq($question)) {
                continue;
            }

            $group[] = $this->createLabel($label);
            $group[] = $this->createSelect(
                $question . "_frequency",
                "",
                $answer_choices
            );
            $group[] = $this->createSelect(
                $question . "_problem",
                "",
                $problem_choices
            );
            $this->form->addGroup(
                $group,
                "page2_section3_row{$c}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                $question . "_frequency",
                array($question . "_frequency{@}=={@}"), // rule
                "Field is required.", // message
                "page2_section3_row{$c}" // group [if field is a part of a group]
            );
            $this->XINRegisterRule(
                $question . "_problem",
                array($question . "_problem{@}=={@}"), // rule
                "Field is required.", // message
                "page2_section3_row{$c}" // group [if field is a part of a group]
            );

        }

        $this->addHeader(
            "<h4>During the past week, your child has appeared very sleepy or fallen asleep" .
            " during the following (check all that apply):</h4>"
        );
        $sleepy_questions = array(
                             "play_alone"           => "Play alone",
                             "watching_tv_item32"   => "Watching TV",
                             "riding_in_car_item33" => "Riding in car",
                             "eating_meals"         => "Eating meals",
                            );

        foreach ($sleepy_questions as $sq => $label) {
            // Don't display the question if it is exclusively for the long CSHQ and
            // we are administering the short version
            if (!$isLongQuestionnaire && $this->isQuestionForLongCshq($sq)) {
                continue;
            }
            $this->addSelect($sq, $label, $sleepy_choices);
        }

        $this->form->addFormRule(array(&$this, 'XINValidate'));
        $this->form->addFormRule(array(&$this, 'validate_page2'));
    }

    function displayHourMinElementCustom($field, $label, $field_label)
    {
        for ($i = 0; $i < 24; $i ++) {
            $hours_options["$i"] = "$i hour(s)";
        }
        for ($i = 0; $i < 60; $i += 5) {
            $min_options["$i"] = "$i minute(s)";
        }
        $min_options['59'] = "59 minute(s)";

        $default_val   = array(null => '');
        $hours_options = array_merge($default_val, $hours_options);
        $min_options   = array_merge($default_val, $min_options);
        $group         = array();
        $group[]       = $this->createSelect($field."_hours", $field_label.' hours', $hours_options);
        $group[]       = $this->createSelect($field."_mins", $field_label.' minutes', $min_options);
        $group[]       = $this->createSelect(
            $field."_status",
            $field_label . ' status',
            array(
             null           => '',
             "dnk"          => "Unknown",
             'not_answered' => 'Prefer not to answer',
            )
        );

        $this->addGroup($group, $field . "_group", $label, null, false);
        unset($group);
        $this->XINRegisterRule(
            $field . "_status",
            array(
             "{$field}_hours{@}=={@}",
             "{$field}_mins{@}=={@}",
            ),
            "Please select one of the option if you don't want to enter the time details."
        );
        $this->XINRegisterRule(
            $field . "_hours",
            array(
             "{$field}_status{@}=={@}",
             "{$field}_mins{@}!={@}",
            ),
            "Hours Required."
        );
        $this->XINRegisterRule(
            $field . "_mins",
            array(
             "{$field}_status{@}=={@}",
             "{$field}_hours{@}!={@}",
            ),
            "Mins Required."
        );

        $this->addLabel('');
    }

    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }
        //null scores
        //$this->_nullScores($this->scoreLabels);

        //get the saved scores
        $db     = Database::singleton();
        $query  = "SELECT * FROM $this->table WHERE CommentID =:cid";
        $record = $db->pselectRow($query, array('cid' => $this->commentID));
        $score  = array();

        // get the list of abbreviated questions
        // and n
        $abbreviated_questions = array();
        foreach ($record as $item => $ans) {
            if (strpos($item, 'item') !== false
                && strpos($item, 'problem') === false
            ) {
                array_push($abbreviated_questions, $item);
            }
        }

        $reverse_items = array(
                          "goes_to_bed_at_same_time_item1_frequency",
                          "falls_asleep_in_20_min_item2_frequency",
                          "falls_asleep_in_own_bed_item3_frequency",
                          "sleeps_right_amount_item10_frequency",
                          "sleeps_same_amount_each_day_item11_frequency",
                          "wakes_by_himself_item26_frequency",
                         );

        // reverse the scoring for (R) questions
        foreach ($abbreviated_questions as $aq) {
            if (in_array($aq, $reverse_items)) {
                if ($record[$aq] == 1) {
                    $record[$aq] = 3;
                } else if ($record[$aq] == 3) {
                    $record[$aq] = 1;
                } else {
                    $record[$aq] = $record[$aq];
                }
            }
        }

        $subscale_questions = array(
                               'bedtime_resistance'         => array(
                                                                "_item1_",
                                                                "_item3_",
                                                                "_item4_",
                                                                "_item5_",
                                                                "_item6_",
                                                                "_item8_",
                                                               ),
                               'sleep_onset_delay'          => array("_item2_"),
                               'sleep_duration'             => array(
                                                                "_item9_",
                                                                "_item10_",
                                                                "_item11_",
                                                               ),
                               'sleep_anxiety'              => array(
                                                                "_item5_",
                                                                "_item7_",
                                                                "_item8_",
                                                                "_item21_",
                                                               ),
                               'night_wakings'              => array(
                                                                "_item16_",
                                                                "_item24_",
                                                                "_item25_",
                                                               ),
                               'parasomnias'                => array(
                                                                "_item12_",
                                                                "_item13_",
                                                                "_item14_",
                                                                "_item15_",
                                                                "_item17_",
                                                                "_item22_",
                                                                "_item23_",
                                                               ),
                               'sleep_disordered_breathing' => array(
                                                                "_item18_",
                                                                "_item19_",
                                                                "_item20_",
                                                               ),
                               'daytime_sleepiness'         => array(
                                                                "_item26_",
                                                                "_item27_",
                                                                "_item28_",
                                                                "_item29_",
                                                                "_item30_",
                                                                "_item31_",
                                                                "_item32",
                                                                "_item33",
                                                               ),
                              );

        $score['bedtime_resistance'] = 0;
        $score['sleep_onset_delay']  = 0;
        $score['sleep_duration']     = 0;
        $score['sleep_anxiety']      = 0;
        $score['night_wakings']      = 0;
        $score['parasomnias']        = 0;
        $score['sleep_disordered_breathing'] = 0;
        $score['daytime_sleepiness']         = 0;

        foreach ($subscale_questions as $subscale => $questions) {
            foreach ($questions as $question) {
                foreach ($abbreviated_questions as $aq) {
                    if (strpos($aq, $question) !== false && strpos($aq, 'problem') === false) {
                        $score[$subscale] += $record[$aq];

                    }
                }
            }
        }

        $score['total_score'] = 0;

        foreach ($abbreviated_questions as  $aq) {
            $score['total_score'] += $record[$aq];
        }

        $result = $db->update($this->table, $score, array("CommentID" => $this->getCommentID()));
    }

    function validate_page1($values)
    {
        return $this->customDateCheck($values, ['sleep_behavior_duration']);
    }

    /**
     * Validates page 2 of the form using instrument_validator.php
     */
    function validate_page2($values)
    {
        $errors = [];

        if (isset($values['waking_during_night_duration'])) {
            if (is_numeric($values['waking_during_night_duration'])) {
                if (intval($values['waking_during_night_duration']) > 720 || intval($values['waking_during_night_duration']) < 0) {
                    $errors['waking_during_night_duration_group'] = "Please enter a numeric value in minutes or NA";
                }
            } else {
                if ($values['waking_during_night_duration'] != 'NA') {
                    $errors['waking_during_night_duration_group'] = "Please enter a numeric value in minutes or NA";
                }
            }

            $err = $this->customDateCheck($values, ['morning_waking_time']);

            if (!empty($err)) {
                $errors = array_merge($errors, $err);
            }
        }

        return $errors;
    }

    private function customDateCheck($values, $items)
    {
        $errors = [];

        foreach ($items as $key) {
            if (!empty($values[$key. '_status'])) {
                if (!empty($values[$key. '_hours']) || !empty($values[$key. '_mins'])) {
                    $errors[$key. '_group'] = 'You have entered hours or minutes, you can not choose ' . ($values[$key. '_status'] == 'not_answered'? 'Prefer not to answer' : 'Unknown') . '.';
                }
            }
        }

        return $errors;
    }
}
