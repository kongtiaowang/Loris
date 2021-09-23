<?php
/**
 *This file contains the NDB_BVL_Instrument_CBCL_6_To_18_survey_sibling class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Moshood Kolawole <moshood.abiola@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the NDB_BVL_Instrument_CBCL_6_To_18 instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Moshood Kolawole <moshood.abiola@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_CBCL_6_To_18_survey_sibling extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    use instrument_validator;
    var $ValidityRequired = false;
    var $scoreLabels = array('anxious_score',
        'anxious_T_score',
        'anxious_percentile',
        'depressed_score',
        'depressed_T_score',
        'depressed_percentile',
        'som_comp_score',
        'som_comp_T_score',
        'som_comp_percentile',
        'social_prob_score',
        'social_prob_T_score',
        'social_prob_percentile',
        'thought_prob_score',
        'thought_prob_T_score',
        'thought_prob_percentile',
        'rule_break_behav_score',
        'rule_break_behav_T_score',
        'rule_break_behav_percentile',
        'aggr_behav_score',
        'aggr_behav_T_score',
        'aggr_behav_percentile',
        'attention_prob_score',
        'attention_prob_T_score',
        'attention_prob_percentile',
        'internalizing_score',
        'internalizing_T_score',
        'internalizing_percentile',
        'externalizing_score',
        'externalizing_T_score',
        'externalizing_percentile',
        'total_problems_score',
        'total_problems_T_score',
        'total_problems_percentile',
        'depressive_prob_score',
        'depressive_prob_T_score',
        'depressive_prob_percentile',
        'anx_prob_score',
        'anx_prob_T_score',
        'anx_prob_percentile',
        'som_prob_score',
        'som_prob_T_score',
        'som_prob_percentile',
        'attention_hyper_prob_score',
        'attention_hyper_prob_T_score',
        'attention_hyper_prob_percentile',
        'oppo_def_prob_score',
        'oppo_def_prob_T_score',
        'oppo_def_prob_percentile',
        'conduct_prob_score',
        'conduct_prob_T_score',
        'conduct_prob_percentile',
        'sluggish_cogn_tempo_score',
        'sluggish_cogn_tempo_T_score',
        'sluggish_cogn_tempo_percentile',
        'obsessive_comp_prob_score',
        'obsessive_comp_prob_T_score',
        'obsessive_comp_prob_percentile',
        'stress_prob_score',
        'stress_prob_T_score',
        'stress_prob_percentile',
    );
    /**
    * Sets up basic data, such as the HTML_Quickform object, and so on.
    *
    * @param string $commentID the CommentID identifying the data to load
    * @param string $page      if a multipage form, the page to show
    *
    * @return void
    * @access public
    */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType ="XIN";
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "CBCL_6_To_18_survey_sibling";           // test_names.Test_name
        $this->table    = 'CBCL_6_To_18_survey_sibling';           // name of database table corresponding to instrument
        // data keyed by commentID
	$this->commentID = $commentID;
	 $config            =& NDB_Config::singleton();
        $this->dateOptions = array(
                              'language'         => 'en',
                              'format'           => 'YMd',
                              'minYear'          => $config->getSetting('startYear'),
                              'maxYear'          => $config->getSetting('endYear'),
                              'addEmptyOption'   => true,
                              'emptyOptionValue' => null,
                             );

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields =array("child_birthdate");

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
        if (preg_match("/CBCL_6_To_18_survey_sibling(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("CBCL (Child Behavior Checklist) 6 to 18 years - FOH Sibling - Survey");

        $this->form->addElement('static', null, "<i><h3>*Please fill out this survey on your enrolled child's SIBLING who is part of the study.</i></h3>");


        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
        $opts = array(
            null              => "",
            "mother"             => "Mother",
            "father"             => "Father",
            "step_mother"        => "Step Mother",
            "step_father"        => "Step Father",
            "other"             => "Other",
        );
        $this->addSelect("relationship_to_child", "What is your relationship to the child?", $opts);
        $this->addBasicText("other_relationship_to_child", $this->indent."If Other, please describe:");
        $this->XINRegisterRule(
            "other_relationship_to_child",
            array("relationship_to_child{@}=={@}other"),
            "Required",
            "other_relationship_to_child"
        );



        for($i=1;$i<=4;$i++)
        {
            if($i==1) {
                $this->form->addElement('header', null, "Syndrome Scales (Scores)  ");
                $domains=array("anxious" => "Anxious/Depressed","depressed" => "Withdrawn/Depressed","som_comp" => "Somatic Complaints",
                    "social_prob" => "Social Problems", "thought_prob" => "Thought Problems", "attention_prob" => "Attention Problems",
                    "rule_break_behav" => "Rule Breaking Behaviour",
                    "aggr_behav" => "Aggressive Behaviour",
                );
            }
            if($i==2) {
                $this->form->addElement('header', null, "Internalizing, Externalizing, Total Problems, Other Problems (Scores)  ");
                $domains=array("internalizing" => "Internalizing","externalizing" => "Externalizing","total_problems" => "Total Problems",
                );
            }
            if($i==3)
            {
                $this->form->addElement('header', null, "DSM-5-Oriented Scales (Scores)  ");
                $domains = array("depressive_prob" => "Depressive Problems","anx_prob" => "Anxiety Problems","som_prob" => "Somatic Problems",
                    "attention_hyper_prob" => "Attention Deficit/ Hyperactivity Problems", "oppo_def_prob" => "Oppositional Defiant Problems",
                    "conduct_prob" => "Conduct Problem"
                );
            }
            if($i==4)
            {
                $this->form->addElement('header', null, "2007 Scales (Scores)");
                $domains = array("sluggish_cogn_tempo" => "Sluggish Cognitive Tempo","obsessive_comp_prob" => " Obsessive-Compulsive Problems",
                    "stress_prob" => " Stress Problems",

                );
            }
            //scoring column headers
            $group[] = $this->form->createElement('static', "score", null, null);
            $group[] = $this->form->createElement('static', "T_score", null, null);
            $group[] = $this->form->createElement('static', "percentile", null, null);
            $this->form->addGroup($group, 'score_header_group_'.$i, "<strong>Domain</strong>", $this->_GUIDelimiter, FALSE);
            unset($group);


            //score fields

            $columnHeaders = array("score" => "Score", "T_score" => "T Score","percentile" =>"Percentile");

            foreach ($columnHeaders as $field => $label) {
                $columnHeaders[$field] .= "     ";
            }
            $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

            foreach ($domains as $field => $label) {
                foreach ($columnHeaders as $scoreField => $scoreLabel) {

                    $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
                }
                $this->form->addGroup($group, "{$label}_score_group_{$i}", $label, $this->_GUIDelimiter, FALSE);
                unset($group);


            }


            //scoring column headers
            $group[] = $this->form->createElement('static', "score", null, null);
            $group[] = $this->form->createElement('static', "T_score", null, null);
            $group[] = $this->form->createElement('static', "percentile", null, null);
            $this->form->addGroup($group, 'score_header_group_'.$i, "<strong>Domain</strong>", $this->_GUIDelimiter, FALSE);
            unset($group);
        }

    }

    /**
    * Generates the first page of the form.
    *
    *@return void
    */
    function _page1()
    {
        // display test name
        $this->addHeader("CBCL (Child Behavior Checklist) 6 to 18 years - FOH Sibling - Survey");

        $this->form->addElement('static', null, "<i><h3>*Please fill out this survey on your enrolled child's SIBLING who is part of the study.</i></h3>");

        $child_gender_options = array(
                                 null   => "",
                                 "boy"  => "Boy",
                                 "girl" => "Girl",
                                );

        $this->addSelect("child_gender", "CHILD'S SEX", $child_gender_options);

        $this->addBasicText("child_age", "CHILD'S AGE <br><h5><i>(Please enter a numeric value between 0-100.)</i></h5>");

        $this->addBasicText("child_ethnic_group_race", "CHILD'S ETHNIC GROUP OR RACE");

        $this->addBasicDate('child_birthdate', "Child's Birthdate (if known)");

        $this->XINRegisterRule(
            "child_birthdate",
            array("child_birthdate{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $this->addBasicText("grade_in_school", "GRADE IN SCHOOL (if attending) <br><h5><i>(If child is not attending school, enter NA)</i></h5>");

        $this->addLabel("Please fill out this form to reflect <i>your</i> view of the child's behavior even if other people might not agree. Feel free to add additional comments beside each item and in the space provided 2. <b><i>Be sure to answer all items.</i></b>");

        $this->addLabel("<h3>PARENTS'USUAL TYPE OF WORK, even if not working now <i>(Please be specific -- for example, auto mechanic, high school teacher, homemaker, laborer, lathe operator, shoe salesman, army sergeant.)</i></h3>");

        $this->addBasicText("parent1_type_of_work", "PARENT 1 (or FATHER) TYPE OF WORK");

        $this->XINRegisterRule(
            "parent1_type_of_work",
            array("parent2_type_of_work{@}=={@}"),
            "Required."
        );

        $this->addBasicText("parent2_type_of_work", "PARENT 2 (or MOTHER) TYPE OF WORK");

        $this->XINRegisterRule(
            "parent2_type_of_work",
            array("parent1_type_of_work{@}=={@}"),
            "Required."
        );

        $parent_gender_options = array(
                                  null     => "",
                                  "male"   => "Male",
                                  "female" => "Female",
                                  "other"  => "Other",
                                 );

        $this->addSelect("parent_gender", "Your sex:", $parent_gender_options);

        $relation_options = array(
                             null                => "",
                             "biological_parent" => "Biological Parent",
                             "adoptive_parent"   => "Adoptive Parent",
                             "step_parent"       => "Step Parent",
                             "foster_parent"     => "Foster Parent",
                             "grandparent"       => "Grandparent",
                             "other"             => "Other (specify):",
                            );

        $this->addSelect("relation_to_child", "Your relation to child:", $relation_options);

        $this->addBasicText("if_other_relation", "$this->indent If other, please specify:");

        $this->XINRegisterRule(
            "if_other_relation",
            array("relation_to_child{@}=={@}other"),
            "Required."
        );

        $how_much_options = array(
                             null                => "",
                             "less_than_average" => "Less Than Average",
                             "average"           => "Average",
                             "more_than_average" => "More Than Average",
                             "dont_know"         => "Don't Know",
                            );

        $how_active_options = array(
                               null          => "",
                               "less_active" => "Less Active",
                               "average"     => "Average",
                               "more_active" => "More Active",
                               "dont_know"   => "Don't Know",
                              );

        $how_well_options = array(
                             null            => "",
                             "below_average" => "Below Average",
                             "average"       => "Average",
                             "above_average" => "Above Average",
                             "dont_know"     => "Don't Know",
                            );

        $none_option = array(
                        null   => "",
                        "none" => "None",
                       );

        $this->addSelect("list_sports", "<h3><b>I. Please list the sports your child most likes to take part in.</b> For example: swimming, baseball, skating, skate boarding, bike riding, fishing, etc.</h3>", $none_option);

        $this->XINRegisterRule(
            "list_sports",
            array("list_sports{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Sports</h4>"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Compared to others of the same age, about how much time does he/she spend in each?</h4>"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Compared to others of the same age, how well does he/she do each one?</h4>"
        );
        $this->addGroup(
            $group,
            "sports_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        for ($i=1; $i <= 3; $i++) {
            $this->addLabel($i . ".");

            $group[] =& $this->createText(
                "sports_{$i}",
                ""
            );
            $group[] =& $this->createSelect(
                "sports_" . $i . "_rating",
                "Sports",
                $how_much_options
            );
            $group[] =& $this->createSelect(
                "sports_" . $i . "_rating1",
                "Sports",
                $how_well_options
            );

            if ($i == 1) {
                $this->XINRegisterRule(
                    "sports_{$i}",
                    array("list_sports{@}!={@}none"),
                    "Required.",
                    "sports_" . $i . "_group"
                );
                $this->XINRegisterRule(
                    "sports_" . $i . "_rating",
                    array("sports_{$i}{@}!={@}"),
                    "Required",
                    "sports_" . $i . "_group"
                );
                $this->XINRegisterRule(
                    "sports_" . $i . "_rating1",
                    array("sports_{$i}{@}!={@}"),
                    "Required",
                    "sports_" . $i . "_group"
                );
            } else {
                $this->XINRegisterRule(
                    "sports_" . $i . "_rating",
                    array("sports_{$i}{@}!={@}"),
                    "Required",
                    "sports_" . $i . "_group"
                );
                $this->XINRegisterRule(
                    "sports_" . $i . "_rating1",
                    array("sports_{$i}{@}!={@}"),
                    "Required",
                    "sports_" . $i . "_group"
                );
                $this->XINRegisterRule(
                    "sports_{$i}",
                    array("sports_{$i}_rating{@}!={@}"),
                    "Required.",
                    "sports_" . $i . "_group"
                );
                $this->XINRegisterRule(
                    "sports_{$i}",
                    array("sports_{$i}_rating1{@}!={@}"),
                    "Required.",
                    "sports_" . $i . "_group"
                );
            }

            $this->addGroup(
                $group,
                "sports_" . $i . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->addSelect("list_hobbies_activities_games", "<h3><b>II. Please list your child's favorite hobbies, activities, and games, other than sports.</b> For example: video games, dolls, reading, piano, crafts, cars, computers, singing, etc (Do <b><i>not</i></b> include listening to radio, TV, or other media.)</h3>", $none_option);

        $this->XINRegisterRule(
            "list_hobbies_activities_games",
            array("list_hobbies_activities_games{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Hobbies, Activities, Games</h4>"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Compared to others of the same age, about how much time does he/she spend in each?</h4>"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Compared to others of the same age, how well does he/she do each one?</h4>"
        );
        $this->addGroup(
            $group,
            "hobbies_activities_games_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        for ($i=1; $i <= 3; $i++) {
            $this->addLabel($i . ".");

            $group[] =& $this->createText(
                "hobbies_activities_games_{$i}",
                ""
            );
            $group[] =& $this->createSelect(
                "hobbies_activities_games_" . $i . "_rating",
                "Hobbies, Activities, Games",
                $how_much_options
            );
            $group[] =& $this->createSelect(
                "hobbies_activities_games_" . $i . "_rating1",
                "Hobbies, Activities, Games",
                $how_well_options
            );

            if ($i == 1) {
                $this->XINRegisterRule(
                    "hobbies_activities_games_{$i}",
                    array("list_hobbies_activities_games{@}!={@}none"),
                    "Required.",
                    "hobbies_activities_games_" . $i . "_group"
                );

                $this->XINRegisterRule(
                    "hobbies_activities_games_" . $i . "_rating",
                    array("hobbies_activities_games_{$i}{@}!={@}"),
                    "Required",
                    "hobbies_activities_games_" . $i . "_group"
                );

                $this->XINRegisterRule(
                    "hobbies_activities_games_" . $i . "_rating1",
                    array("hobbies_activities_games_{$i}{@}!={@}"),
                    "Required",
                    "hobbies_activities_games_" . $i . "_group"
                );
            } else {
                $this->XINRegisterRule(
                    "hobbies_activities_games_" . $i . "_rating",
                    array("hobbies_activities_games_{$i}{@}!={@}"),
                    "Required",
                    "hobbies_activities_games_" . $i . "_group"
                );

                $this->XINRegisterRule(
                    "hobbies_activities_games_" . $i . "_rating1",
                    array("hobbies_activities_games_{$i}{@}!={@}"),
                    "Required",
                    "hobbies_activities_games_" . $i . "_group"
                );

                $this->XINRegisterRule(
                    "hobbies_activities_games_{$i}",
                    array("hobbies_activities_games_{$i}_rating{@}!={@}"),
                    "Required.",
                    "hobbies_activities_games_" . $i . "_group"
                );

                $this->XINRegisterRule(
                    "hobbies_activities_games_{$i}",
                    array("hobbies_activities_games_{$i}_rating1{@}!={@}"),
                    "Required.",
                    "hobbies_activities_games_" . $i . "_group"
                );
            }
            $this->addGroup(
                $group,
                "hobbies_activities_games_" . $i . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->addSelect("list_organizations_clubs_teams", "<h3><b>III. Please list any organizations, clubs, teams, or groups your child belongs to.</b></h3>", $none_option);

        $this->XINRegisterRule(
            "list_organizations_clubs_teams",
            array("list_organizations_clubs_teams{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Organizations, Clubs, Teams, Groups</h4>"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Compared to others of the same age, how active is he/she in each?</h4>"
        );
        $this->addGroup(
            $group,
            "organizations_clubs_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        for ($i=1; $i <= 3; $i++) {
            $this->addLabel($i . ".");

            $group[] =& $this->createText(
                "organizations_clubs_teams_{$i}",
                ""
            );
            $group[] =& $this->createSelect(
                "organizations_clubs_teams_" . $i . "_rating",
                "Organizations, clubs, teams, groups",
                $how_active_options
            );

            if ($i == 1) {
                $this->XINRegisterRule(
                    "organizations_clubs_teams_{$i}",
                    array("list_organizations_clubs_teams{@}!={@}none"),
                    "Required.",
                    "organizations_clubs_teams_" . $i . "_group"
                );
                $this->XINRegisterRule(
                    "organizations_clubs_teams_" . $i . "_rating",
                    array("organizations_clubs_teams_{$i}{@}!={@}"),
                    "Required",
                    "organizations_clubs_teams_" . $i . "_group"
                );
            } else {
                $this->XINRegisterRule(
                    "organizations_clubs_teams_" . $i . "_rating",
                    array("organizations_clubs_teams_{$i}{@}!={@}"),
                    "Required",
                    "organizations_clubs_teams_" . $i . "_group"
                );
                $this->XINRegisterRule(
                    "organizations_clubs_teams_{$i}",
                    array("organizations_clubs_teams_{$i}_rating{@}!={@}"),
                    "Required.",
                    "organizations_clubs_teams_" . $i . "_group"
                );
            }

            $this->addGroup(
                $group,
                "organizations_clubs_teams_" . $i . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->addSelect("list_any_jobs_chores", "<h3><b>IV. Please list any jobs or chores your child has.</b> For example: doing dishes, babysitting, making bed, working in store, etc. (Include both paid and unpaid jobs and chores.)</h3>", $none_option);

        $this->XINRegisterRule(
            "list_any_jobs_chores",
            array("list_any_jobs_chores{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Jobs or Chores</h4>"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Compared to others of the same age, how well does he/she carry them out?</h4>"
        );
        $this->addGroup(
            $group,
            "jobs_chores_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        for ($i=1; $i <= 3; $i++) {
            $this->addLabel($i . ".");

            $group[] =& $this->createText(
                "jobs_or_chores_{$i}",
                ""
            );
            $group[] =& $this->createSelect(
                "jobs_or_chores_" . $i . "_rating",
                "Jobs or Chores",
                $how_well_options
            );

            if ($i == 1) {
                $this->XINRegisterRule(
                    "jobs_or_chores_{$i}",
                    array("list_any_jobs_chores{@}!={@}none"),
                    "Required.",
                    "jobs_or_chores_" . $i . "_group"
                );
                $this->XINRegisterRule(
                    "jobs_or_chores_" . $i . "_rating",
                    array("jobs_or_chores_{$i}{@}!={@}"),
                    "Required",
                    "jobs_or_chores_" . $i . "_group"
                );
            } else {
                $this->XINRegisterRule(
                    "jobs_or_chores_" . $i . "_rating",
                    array("jobs_or_chores_{$i}{@}!={@}"),
                    "Required",
                    "jobs_or_chores_" . $i . "_group"
                );
                $this->XINRegisterRule(
                    "jobs_or_chores_{$i}",
                    array("jobs_or_chores_{$i}_rating{@}!={@}"),
                    "Required.",
                    "jobs_or_chores_" . $i . "_group"
                );
            }

            $this->addGroup(
                $group,
                "jobs_or_chores_" . $i . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->addLabel("Be sure you answered all items.");

        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    /**
    * Generates the second page of the form.
    *
    *@return void
    */
    function _page2()
    {
        // display test name
        $this->addHeader("CBCL (Child Behavior Checklist) 6 to 18 years - FOH Sibling - Survey");

        $this->form->addElement('static', null, "<i><h3>*Please fill out this survey on your enrolled child's SIBLING who is part of the study.</i></h3>");

        $this->addLabel("Be sure to answer all items.");

        $V_1_options = array(
                        null        => "",
                        "none"      => "None",
                        "1"         => "1",
                        "2_or_3"    => "2 or 3",
                        "4_or_more" => "4 or more",
                       );

        $V_2_options = array(
                        null          => "",
                        "less_than_1" => "Less than 1",
                        "1_or_2"      => "1 or 2",
                        "3_or_more"   => "3 or more",
                       );

        $this->addSelect("V_1_how_many_close_friends", "<h3>V. 1. About how many close friends does your child have? (Do <i>not</i> include brothers & sisters)</h3>", $V_1_options);

        $this->addSelect("V_2_how_many_things_with_friends_outside_school", "<h3>V. 2. About how many times a week does your child do things with any friends outside of regular school hours? (Do <i>not</i> include brothers & sisters)</h3>", $V_2_options);

        $VI_options = array(
                       null              => "",
                       "worse"           => "Worse",
                       "average"         => "Average",
                       "better"          => "Better",
                       "has_no_siblings" => "Has no brothers or sisters",
                      );

        $VI_questions = array(
                         "VIa_get_along_with_siblings"   => "a. Get along with his/her brothers & sisters?",
                         "VIb_get_along_with_other_kids" => "b. Get along with other kids?",
                         "VIc_behave_with_parents"       => "c. Behave with his/her parents?",
                         "VId_play_work_alone"           => "d. Play and work alone?",
                        );

        $this->addLabel("<h3>VI. Compared to others of his/her age, how well does your child:</h3>");

        foreach ($VI_questions as $key => $VI_questions) {
            // last option is removed after first question
            if ($key == "VIb_get_along_with_other_kids") {
                unset($VI_options['has_no_siblings']);
            }

            $this->addSelect($key, $VI_questions, $VI_options);
        }

        $attend_school_option = array(
                                 null                     => "",
                                 "does_not_attend_school" => "Does not attend school",
                                );

        $this->addSelect("attend_school", "<h3>VII. 1. Performance in academic subjects.</h3>", $attend_school_option);

        $this->XINRegisterRule(
            "attend_school",
            array("attend_school{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $this->addBasicText("does_not_attend_because", "$this->indent Does not attend school because:");

        $this->XINRegisterRule(
            "does_not_attend_because",
            array("attend_school{@}=={@}does_not_attend_school"),
            "Required."
        );

        $this->addLabel("Answer for each subject that child takes.");

        $yes_no_options = array(
                           null  => "",
                           "no"  => "No",
                           "yes" => "Yes",
                          );

        $performance_options = array(
                                null            => "",
                                "failing"       => "Failing",
                                "below_average" => "Below Average",
                                "average"       => "Average",
                                "above_average" => "Above Average",
                               );

        $academic_subjects =array(
                             "a_reading_english_language" => "a. Reading, English, Language Arts",
                             "b_history_social_studies"   => "b. History or Social Studies",
                             "c_arithmetic_math"          => "c. Arithmetic or Math",
                             "d_science"                  => "d. Science",
                            );

        foreach ($academic_subjects as $key => $academic_subject) {

            $this->addSelect($key, $academic_subject, $performance_options);

            $this->XINRegisterRule(
                "$key",
                array("$key{@}=={@}NEVER_REQUIRED")
            );
        }

        $this->addLabel("Other academic subjects- for example: computer courses, foreign language, business. Do <b><i>not</i></b> include gym, shop, driver's ed., or other nonacademic subjects.");

        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            " "
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            " "
        );
        $this->addGroup(
            $group,
            "page2_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        for ($i=1; $i <= 3; $i++) {

            if ($i == 1) {
                $label = "e";
            } else if ($i == 2) {
                $label = "f";
            } else {
                $label = "g";
            }

            $this->addLabel($label . ".");

            $group[] =& $this->createText(
                "performance_in_subjects_{$i}",
                ""
            );
            $group[] =& $this->createSelect(
                "performance_in_subjects_" . $i . "_rating",
                " ",
                $performance_options
            );

            $this->XINRegisterRule(
                "performance_in_subjects_" . $i . "_rating",
                array("performance_in_subjects_{$i}{@}!={@}"),
                "Required",
                "performance_in_subjects_" . $i . "_group"
            );
            $this->XINRegisterRule(
                "performance_in_subjects_{$i}",
                array("performance_in_subjects_{$i}_rating{@}!={@}"),
                "Required.",
                "performance_in_subjects_" . $i . "_group"
            );
            $this->addGroup(
                $group,
                "performance_in_subjects_" . $i . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->addSelect("q2_special_education_class_school", "<h3>2. Does your child receive special education or remedial services or attend a special class or special school?</h3>", $yes_no_options);

        $this->addBasicText("q2_yes", "$this->indent Yes -- kind of services, class, or school:");

        $this->XINRegisterRule(
            "q2_yes",
            array("q2_special_education_class_school{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("q3_repeated_any_grades", "<h3>3. Has your child repeated any grades?</h3>", $yes_no_options);

        $this->addBasicText("q3_yes", "$this->indent Yes -- grades and reasons:");

        $this->XINRegisterRule(
            "q3_yes",
            array("q3_repeated_any_grades{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("q4_problems_in_school", "<h3>4. Has your child had any academic or other problems in school?</h3>", $yes_no_options);

        $this->addBasicText("q4_yes", "$this->indent Yes -- please describe:");

        $this->XINRegisterRule(
            "q4_yes",
            array("q4_problems_in_school{@}=={@}yes"),
            "Required."
        );

        $this->addBasicText("when_did_problems_start", "When did these problems start?");

        $this->XINRegisterRule(
            "when_did_problems_start",
            array("q4_problems_in_school{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("have_problems_ended", "Have these problems ended?", $yes_no_options);

        $this->XINRegisterRule(
            "have_problems_ended",
            array("q4_problems_in_school{@}=={@}yes"),
            "Required."
        );

        $this->addBasicText("q4_ended_yes", "$this->indent Yes -- when?");

        $this->XINRegisterRule(
            "q4_ended_yes",
            array("have_problems_ended{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("does_child_have_illness_disability", "<h3>Does your child have any illness or disability (either physical or mental)?</h3>", $yes_no_options);

        $this->addBasicText("child_illness_disability_describe", "$this->indent Describe:");

        $this->XINRegisterRule(
            "child_illness_disability_describe",
            array("does_child_have_illness_disability{@}=={@}yes"),
            "Required."
        );

        $this->addBasicText("concerns_about_child", "<h3>What concerns you most about your child?</h3>");

        $this->addBasicText("best_things_about_child", "<h3>Please describe the best things about your child.</h3>");

        $this->addLabel("Be sure you answered all items.");

        $this->form->addFormRule(array(&$this, 'validate_page2'));
    }
    /**
    * Generates the third page of the form.
    *
    *@return void
    */
    function _page3()
    {
        // display test name
        $this->addHeader("CBCL (Child Behavior Checklist) 6 to 18 years - FOH Sibling - Survey");

        $this->form->addElement('static', null, "<i><h3>*Please fill out this survey on your enrolled child's SIBLING who is part of the study.</i></h3>");

        $this->addLabel("<h3>Below is a list of items that describe children and youths <b><i>now or within the past 2 months</i></b>. Please answer all items as well as you can, even if some do not seem to apply to your child.</h3>");

        $options = array(
                    null => "",
                    "0"  => "0 - Not True (as far as you know)",
                    "1"  => "1 - Somewhat or Sometimes True",
                    "2"  => "2 - Very True or Often True",
                   );

        $questions = array(
                      "q1_acts_too_young"                          => "1. Acts too young for his/her age",
                      "q2_drinks_alcohol_without_approval"         => "2. Drinks alcohol without parents'approval (describe):",
                      "q3_argues_a_lot"                            => "3. Argues a lot",
                      "q4_fails_to_finish_things_starts"           => "4. Fails to finish things he/she starts",
                      "q5_very_little_they_enjoy"                  => "5. There is very little that he/she enjoys",
                      "q6_bowel_movements_outside_toilet"          => "6. Bowel movements outside toilet",
                      "q7_bragging_boasting"                       => "7. Bragging, boasting",
                      "q8_cant_concentrate_for_long"               => "8. Can't concentrate, can't pay attention for long",
                      "q9_cant_get_mind_off_certain_thoughts"      => "9. Can't get his/her mind off certain thoughts; obsessions (describe):",
                      "q10_cant_sit_still_restless"                => "10. Can't sit still, restless, or hyperactive",
                      "q11_clings_to_adults_dependent"             => "11. Clings to adults or too dependent",
                      "q12_complains_of_loneliness"                => "12. Complains of loneliness",
                      "q13_confused_in_a_fog"                      => "13. Confused or seems to be in a fog",
                      "q14_cries_a_lot"                            => "14. Cries a lot",
                      "q15_cruel_to_animals"                       => "15. Cruel to animals",
                      "q16_cruelty_bullying_meanness"              => "16. Cruelty, bullying, or meanness to others",
                      "q17_daydreams_gets_lost_in_thoughts"        => "17. Daydreams or gets lost in his/her thoughts",
                      "q18_harms_self_attempts_suicide"            => "18. Deliberately harms self or attempts suicide",
                      "q19_demands_a_lot_of_attention"             => "19. Demands a lot of attention",
                      "q20_destroys_own_things"                    => "20. Destroys his/her own things",
                      "q21_destroys_things_belonging_to_others"    => "21. Destroys things belonging to his/her family or others",
                      "q22_disobedient_at_home"                    => "22. Disobedient at home",
                      "q23_disobedient_at_school"                  => "23. Disobedient at school",
                      "q24_doesnt_eat_well"                        => "24. Doesn't eat well",
                      "q25_doesnt_get_along_with_other_kids"       => "25. Doesn't get along with other kids",
                      "q26_doesnt_feel_guilty_misbehaving"         => "26. Doesn't seem to feel guilty after misbehaving",
                      "q27_easily_jealous"                         => "27. Easily jealous",
                      "q28_breaks_rules_home_school_elsewhere"     => "28. Breaks rules at home, school, or elsewhere",
                      "q29_fears_animals_situations_places"        => "29. Fears certain animals, situations, or places, other than school (describe):",
                      "q30_fears_going_to_school"                  => "30. Fears going to school",
                      "q31_fears_might_think_do_something_bad"     => "31. Fears he/she might think or do something bad",
                      "q32_feels_has_to_be_perfect"                => "32. Feels he/she has to be perfect",
                      "q33_feels_complains_no_one_loves_them"      => "33. Feels or complains that no one loves him/her",
                      "q34_feels_others_out_to_get_them"           => "34. Feels others are out to get him/her",
                      "q35_feels_worthless_inferior"               => "35. Feels worthless or inferior",
                      "q36_gets_hurt_a_lot_accident_prone"         => "36. Gets hurt a lot, accident-prone",
                      "q37_gets_in_many_fights"                    => "37. Gets in many fights",
                      "q38_gets_teased_a_lot"                      => "38. Gets teased a lot",
                      "q39_hangs_around_others_who_get_in_trouble" => "39. Hangs around with others who get in trouble",
                      "q40_hears_sounds_voices_arent_there"        => "40. Hears sounds or voices that aren't there (describe):",
                      "q41_impulsive_acts_without_thinking"        => "41. Impulsive or acts without thinking",
                      "q42_would_rather_be_alone"                  => "42. Would rather be alone than with others",
                      "q43_lying_or_cheating"                      => "43. Lying or cheating",
                      "q44_bites_fingernails"                      => "44. Bites fingernails",
                      "q45_nervous_highstrung_tense"               => "45. Nervous, highstrung, or tense",
                      "q46_nervous_movements_twitching"            => "46. Nervous movements or twitching (describe):",
                      "q47_nightmares"                             => "47. Nightmares",
                      "q48_not_liked_by_other_kids"                => "48. Not liked by other kids",
                      "q49_constipated"                            => "49. Constipated, doesn't move bowels",
                      "q50_too_fearful_or_anxious"                 => "50. Too fearful or anxious",
                      "q51_feels_dizzy_lightheaded"                => "51. Feels dizzy or lightheaded",
                      "q52_feels_too_guilty"                       => "52. Feels too guilty",
                      "q53_overeating"                             => "53. Overeating",
                      "q54_overtired_without_good_reason"          => "54. Overtired without good reason",
                      "q55_overweight"                             => "55. Overweight",
                      "q56a_aches_or_pains"                        => "a. Aches or pains (<i>not</i> stomach or headaches)",
                      "q56b_headaches"                             => "b. Headaches",
                      "q56c_nausea_feels_sick"                     => "c. Nausea, feels sick",
                      "q56d_problems_with_eyes"                    => "d. Problems with eyes (<i>not</i> if corrected by glasses)(describe):",
                      "q56e_rashes_or_skin_problems"               => "e. Rashes or other skin problems",
                      "q56f_stomachaches"                          => "f. Stomachaches",
                      "q56g_vomiting_throwing_up"                  => "g. Vomiting, throwing up",
                      "q56h_other"                                 => "h. Other (describe):",
                     );

        foreach ($questions as $key => $question) {
            // add label for q56
            if ($key == "q56a_aches_or_pains") {

                $this->addLabel("56. Physical problems <b><i>without known medical cause:</i></b>");

            }

            $this->addSelect($key, $question, $options);

            // if the question contains (describe), include text element
            if (strpos($question, "(describe)") !== false) {

                $str = substr($key, 0, strpos($key, "_")+1)."describe";

                $this->addBasicText($str, "$this->indent Describe: <br><h5><i>$this->indent$this->indent(Required if selected \"Somewhat or Sometimes True\" or \"Very True or Often True\".)</i></h5>");

                $this->XINRegisterRule(
                    $str,
                    array("{$key}{@}=={@}1|2"),
                    "Required."
                );
            }
        }

        $this->form->addFormRule(array(&$this, 'validate_page3'));
    }
    /**
    * Generates the fourth page of the form.
    *
    *@return void
    */
    function _page4()
    {
       // display test name
       $this->addHeader("CBCL (Child Behavior Checklist) 6 to 18 years - FOH Sibling - Survey");

       $this->form->addElement('static', null, "<i><h3>*Please fill out this survey on your enrolled child's SIBLING who is part of the study.</i></h3>");

           $this->addLabel("<h3>Below is a list of items that describe children and youths <b><i>now or within the past 2 months</i></b>. Please answer all items as well as you can, even if some do not seem to apply to your child.</h3>");

        $options = array(
                    null => "",
                    "0"  => "0 - Not True (as far as you know)",
                    "1"  => "1 - Somewhat or Sometimes True",
                    "2"  => "2 - Very True or Often True",
                   );

        $questions = array(
                      "q57_physically_attacks_people"                  => "57. Physically attacks people",
                      "q58_picks_nose_skin_other_parts_of_body"        => "58. Picks nose, skin, or other parts of body (describe):",
                      "q59_plays_with_own_sex_parts_public"            => "59. Plays with own sex parts in public",
                      "q60_plays_with_own_sex_parts_too_much"          => "60. Plays with own sex parts too much",
                      "q61_poor_school_work"                           => "61. Poor school work",
                      "q62_poorly_coordinated_clumsy"                  => "62. Poorly coordinated or clumsy",
                      "q63_prefers_being_with_older_kids"              => "63. Prefers being with older kids",
                      "q64_prefers_being_with_younger_kids"            => "64. Prefers being with younger kids",
                      "q65_refuses_to_talk"                            => "65. Refuses to talk",
                      "q66_repeats_certain_acts_compulsions"           => "66. Repeats certain acts over and over; compulsions (describe):",
                      "q67_runs_away_from_home"                        => "67. Runs away from home",
                      "q68_screams_a_lot"                              => "68. Screams a lot",
                      "q69_secretive"                                  => "69. Secretive, keeps things to self",
                      "q70_sees_things_that_arent_there"               => "70. Sees things that aren't there (describe):",
                      "q71_self_conscious_easily_embarrassed"          => "71. Self-conscious or easily embarrassed",
                      "q72_sets_fires"                                 => "72. Sets fires",
                      "q73_sexual_problems"                            => "73. Sexual problems (describe):",
                      "q74_showing_off_clowning"                       => "74. Showing off or clowning",
                      "q75_too_shy_or_timid"                           => "75. Too shy or timid",
                      "q76_sleeps_less_than_most_kids"                 => "76. Sleeps less than most kids",
                      "q77_sleeps_more_than_most_kids_day_or_night"    => "77. Sleeps more than most kids during the day and/or night (describe):",
                      "q78_inattentive_easily_distracted"              => "78. Inattentive or easily distracted",
                      "q79_speech_problem"                             => "79. Speech problem (describe):",
                      "q80_stares_blankly"                             => "80. Stares blankly",
                      "q81_steals_at_home"                             => "81. Steals at home",
                      "q82_steals_outside_home"                        => "82. Steals outside the home",
                      "q83_stores_up_many_things_doesnt_need"          => "83. Stores up too many things he/she doesn't need (describe):",
                      "q84_strange_behaviour"                          => "84. Strange behavior (describe):",
                      "q85_strange_ideas"                              => "85. Strange ideas (describe):",
                      "q86_stubborn_sullen_irritable"                  => "86. Stubborn, sullen, or irritable",
                      "q87_sudden_changes_in_mood_feelings"            => "87. Sudden changes in mood or feelings",
                      "q88_sulks_a_lot"                                => "88. Sulks a lot",
                      "q89_suspicious"                                 => "89. Suspicious",
                      "q90_swearing_or_obscene_language"               => "90. Swearing or obscene language",
                      "q91_talks_about_killing_self"                   => "91. Talks about killing self",
                      "q92_talks_or_walks_in_sleep"                    => "92. Talks or walks in sleep (describe):",
                      "q93_talks_too_much"                             => "93. Talks too much",
                      "q94_teases_a_lot"                               => "94. Teases a lot",
                      "q95_temper_tantrums_hot_temper"                 => "95. Temper tantrums or hot temper",
                      "q96_thinks_about_sex_too_much"                  => "96. Thinks about sex too much",
                      "q97_threatens_people"                           => "97. Threatens people",
                      "q98_thumb_sucking"                              => "98. Thumb-sucking",
                      "q99_smokes_chews_sniffs_tobacco"                => "99. Smokes, chews, or sniffs tobacco",
                      "q100_trouble_sleeping"                          => "100. Trouble sleeping (describe):",
                      "q101_truancy_skips_school"                      => "101. Truancy, skips school",
                      "q102_underactive_slow_moving_lacks_energy"      => "102. Underactive, slow moving, or lacks energy",
                      "q103_unhappy_sad_depressed"                     => "103. Unhappy, sad, or depressed",
                      "q104_unusually_loud"                            => "104. Unusually loud",
                      "q105_uses_drugs_nonmedical_purposes"            => "105. Uses drugs for nonmedical purposes (<i>don't</i> include alcohol or tobacco)(describe):",
                      "q106_vandalism"                                 => "106. Vandalism",
                      "q107_wets_self_during_day"                      => "107. Wets self during the day",
                      "q108_wets_the_bed"                              => "108. Wets the bed",
                      "q109_whining"                                   => "109. Whining",
                      "q110_wishes_to_be_opposite_sex"                 => "110. Wishes to be the opposite sex",
                      "q111_withdrawn_doesnt_get_involved_with_others" => "111. Withdrawn, doesn't get involved with others",
                      "q112_worries"                                   => "112. Worries",
                     );

        foreach ($questions as $key => $question) {

            $this->addSelect($key, $question, $options);

            // if the question contains (describe), include text element
            if (strpos($question, "(describe)") !== false) {

                $str = substr($key, 0, strpos($key, "_")+1)."describe";

                $this->addBasicText($str, "$this->indent Describe: <br><h5><i>$this->indent$this->indent(Required if selected \"Somewhat or Sometimes True\" or \"Very True or Often True\".)</i></h5>");

                $this->XINRegisterRule(
                    $str,
                    array("{$key}{@}=={@}1|2"),
                    "Required."
                );
            }
        }

        $this->addLabel("113. Please write any problems your child has that were not listed above:");

        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Problem</h4>"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Problem rating</h4>"
        );
        $this->addGroup(
            $group,
            "page4_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        for ($i=1; $i <= 3; $i++) {
            $this->addLabel($i . ".");

            $group[] =& $this->createText(
                "additional_problem_{$i}",
                ""
            );
            $group[] =& $this->createSelect(
                "additional_problem_" . $i . "_rating",
                "Additional Problems",
                $options
            );

            $this->XINRegisterRule(
                "additional_problem_" . $i . "_rating",
                array("additional_problem_{$i}{@}!={@}"),
                "Required",
                "additional_problem_" . $i . "_group"
            );
            $this->XINRegisterRule(
                "additional_problem_{$i}",
                array("additional_problem_{$i}_rating{@}=={@}0|1|2"),
                "Required.",
                "additional_problem_" . $i . "_group"
            );
            $this->addGroup(
                $group,
                "additional_problem_" . $i . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->form->addFormRule(array(&$this, 'validate_page4'));
    }

    function validate_page1($values)
    {
        $errors = [];

        $this->validate_child_age($values, "child_age", $errors);

        $this->validate_grade_NA($values, "grade_in_school", $errors);

        if ($values["relation_to_child"] != "other") {
            $this->validate_empty_subquestions($values, ["if_other_relation"], $errors);
        }

        if ($values["list_sports"] == "none") {
            $this->validate_empty_subquestions($values, ["sports_1", "sports_2", "sports_3", "sports_1_rating", "sports_2_rating", "sports_3_rating", "sports_1_rating1", "sports_2_rating1", "sports_3_rating1"], $errors);
        }

        if ($values["list_hobbies_activities_games"] == "none") {
            $this->validate_empty_subquestions($values, ["hobbies_activities_games_1", "hobbies_activities_games_2", "hobbies_activities_games_3", "hobbies_activities_games_1_rating", "hobbies_activities_games_2_rating", "hobbies_activities_games_3_rating", "hobbies_activities_games_1_rating1", "hobbies_activities_games_2_rating1", "hobbies_activities_games_3_rating1"], $errors);
        }

        if ($values["list_organizations_clubs_teams"] == "none") {
            $this->validate_empty_subquestions($values, ["organizations_clubs_teams_1", "organizations_clubs_teams_2", "organizations_clubs_teams_3", "organizations_clubs_teams_1_rating", "organizations_clubs_teams_2_rating", "organizations_clubs_teams_4_rating"], $errors);
        }

        if ($values["list_any_jobs_chores"] == "none") {
            $this->validate_empty_subquestions($values, ["jobs_or_chores_1", "jobs_or_chores_2", "jobs_or_chores_3", "jobs_or_chores_1_rating", "jobs_or_chores_2_rating", "jobs_or_chores_3_rating"], $errors);
        }

        return $errors;
    }

    function validate_page2($values)
    {
        $errors = [];

        if ($values["attend_school"] != "does_not_attend_school") {
            $this->validate_empty_subquestions($values, ["does_not_attend_because"], $errors);
        }

        if ($values["attend_school"] == "does_not_attend_school") {
            $this->validate_empty_subquestions($values, ["a_reading_english_language", "b_history_social_studies", "c_arithmetic_math", "d_science", "performance_in_subjects_1", "performance_in_subjects_2", "performance_in_subjects_3", "performance_in_subjects_1_rating", "performance_in_subjects_2_rating", "performance_in_subjects_3_rating"], $errors);
        }

        if ($values["q2_special_education_class_school"] != "yes") {
            $this->validate_empty_subquestions($values, ["q2_yes"], $errors);
        }

        if ($values["q3_repeated_any_grades"] != "yes") {
            $this->validate_empty_subquestions($values, ["q3_yes"], $errors);
        }

        if ($values["q4_problems_in_school"] != "yes") {
            $this->validate_empty_subquestions($values, ["q4_yes", "when_did_problems_start", "have_problems_ended"], $errors);
        }

        if ($values["have_problems_ended"] != "yes") {
            $this->validate_empty_subquestions($values, ["q4_ended_yes"], $errors);
        }

        if ($values["does_child_have_illness_disability"] != "yes") {
            $this->validate_empty_subquestions($values, ["child_illness_disability_describe"], $errors);
        }

        return $errors;
    }

    function validate_page3($values)
    {
        $errors = [];

        $questions = array(
                      "q2_drinks_alcohol_without_approval"    => "q2_describe",
                      "q9_cant_get_mind_off_certain_thoughts" => "q9_describe",
                      "q29_fears_animals_situations_places"   => "q29_describe",
                      "q40_hears_sounds_voices_arent_there"   => "q40_describe",
                      "q46_nervous_movements_twitching"       => "q46_describe",
                      "q56d_problems_with_eyes"               => "q56d_describe",
                      "q56h_other"                            => "q56h_describe",
                     );

        foreach ($questions as $key => $describe) {
            if ($values[$key] == "0") {
                $this->validate_empty_subquestions($values, [$describe], $errors);
            }
        }

        return $errors;
    }

    function validate_page4($values)
    {
        $errors = [];

        $questions = array(
                      "q58_picks_nose_skin_other_parts_of_body" => "q58_describe",
                      "q66_repeats_certain_acts_compulsions"    => "q66_describe",
                      "q70_sees_things_that_arent_there"        => "q70_describe",
                      "q73_sexual_problems"                     => "q73_describe",
                      "q79_speech_problem"                      => "q79_describe",
                      "q83_stores_up_many_things_doesnt_need"   => "q83_describe",
                      "q84_strange_behaviour"                   => "q84_describe",
                      "q85_strange_ideas"                       => "q85_describe",
                      "q92_talks_or_walks_in_sleep"             => "q92_describe",
                      "q100_trouble_sleeping"                   => "q100_describe",
                      "q105_uses_drugs_nonmedical_purposes"     => "q105_describe",
                     );

        foreach ($questions as $key => $describe) {
            if ($values[$key] == "0") {
                $this->validate_empty_subquestions($values, [$describe], $errors);
            }
        }

        return $errors;
    }
function score(): void
{


    if($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }
        $scores['score_validity'] =NULL;

        //null scores
        $this->_nullScores($this->scoreLabels);

    //get the saved scores
    $db =& Database::singleton();
    $query = "SELECT * FROM $this->table WHERE CommentID = '$this->commentID'";
    $record = $db->pselectRow($query, array());


    // Syndrome Raw Score calculation Start
    $anxious_array = array(
        $record['q14_cries_a_lot'],
        $record['q29_fears_animals_situations_places'],
        $record['q30_fears_going_to_school'],
        $record['q31_fears_might_think_do_something_bad'],
        $record['q32_feels_has_to_be_perfect'],
        $record['q33_feels_complains_no_one_loves_them'],
        $record['q35_feels_worthless_inferior'],
        $record['q45_nervous_highstrung_tense'],
        $record['q50_too_fearful_or_anxious'],
        $record['q52_feels_too_guilty'],
        $record['q71_self_conscious_easily_embarrassed'],
        $record['q91_talks_about_killing_self'],
        $record['q112_worries'],

    );
    $depressed_array = array(
        $record['q5_very_little_they_enjoy'],
        $record['q42_would_rather_be_alone'],
        $record['q65_refuses_to_talk'],
        $record['q69_secretive'],
        $record['q75_too_shy_or_timid'],
        $record['q102_underactive_slow_moving_lacks_energy'],
        $record['q103_unhappy_sad_depressed'],
        $record['q111_withdrawn_doesnt_get_involved_with_others'],

    );
    $som_comp_array = array(
        $record['q47_nightmares'],
        $record['q49_constipated'],
        $record['q51_feels_dizzy_lightheaded'],
        $record['q54_overtired_without_good_reason'],
        $record['q56a_aches_or_pains'],
        $record['q56b_headaches'],
        $record['q56c_nausea_feels_sick'],
        $record['q56d_problems_with_eyes'],
        $record['q56e_rashes_or_skin_problems'],
        $record['q56f_stomachaches'],
        $record['q56g_vomiting_throwing_up'],

    );
    $social_prob_array = array(
        $record['q11_clings_to_adults_dependent'],
        $record['q12_complains_of_loneliness'],
        $record['q25_doesnt_get_along_with_other_kids'],
        $record['q27_easily_jealous'],
        $record['q34_feels_others_out_to_get_them'],
        $record['q36_gets_hurt_a_lot_accident_prone'],
        $record['q38_gets_teased_a_lot'],
        $record['q48_not_liked_by_other_kids'],
        $record['q62_poorly_coordinated_clumsy'],
        $record['q64_prefers_being_with_younger_kids'],
        $record['q79_speech_problem'],


    );
    $thought_prob_array = array(
        $record['q9_cant_get_mind_off_certain_thoughts'],
        $record['q18_harms_self_attempts_suicide'],
        $record['q40_hears_sounds_voices_arent_there'],
        $record['q46_nervous_movements_twitching'],
        $record['q58_picks_nose_skin_other_parts_of_body'],
        $record['q59_plays_with_own_sex_parts_public'],
        $record['q60_plays_with_own_sex_parts_too_much'],
        $record['q66_repeats_certain_acts_compulsions'],
        $record['q70_sees_things_that_arent_there'],
        $record['q76_sleeps_less_than_most_kids'],
        $record['q83_stores_up_many_things_doesnt_need'],
        $record['q84_strange_behaviour'],
        $record['q85_strange_ideas'],
        $record['q92_talks_or_walks_in_sleep'],
        $record['q100_trouble_sleeping'],

    );
    $attention_prob_array = array(
        $record['q1_acts_too_young'],
        $record['q4_fails_to_finish_things_starts'],
        $record['q8_cant_concentrate_for_long'],
        $record['q10_cant_sit_still_restless'],
        $record['q13_confused_in_a_fog'],
        $record['q17_daydreams_gets_lost_in_thoughts'],
        $record['q41_impulsive_acts_without_thinking'],
        $record['q61_poor_school_work'],
        $record['q78_inattentive_easily_distracted'],
        $record['q80_stares_blankly'],

    );
    $rule_break_behav_array = array(
        $record['q2_drinks_alcohol_without_approval'],
        $record['q26_doesnt_feel_guilty_misbehaving'],
        $record['q28_breaks_rules_home_school_elsewhere'],
        $record['q39_hangs_around_others_who_get_in_trouble'],
        $record['q43_lying_or_cheating'],
        $record['q63_prefers_being_with_older_kids'],
        $record['q67_runs_away_from_home'],
        $record['q72_sets_fires'],
        $record['q73_sexual_problems'],
        $record['q81_steals_at_home'],
        $record['q82_steals_outside_home'],
        $record['q90_swearing_or_obscene_language'],
        $record['q96_thinks_about_sex_too_much'],
        $record['q99_smokes_chews_sniffs_tobacco'],
        $record['q101_truancy_skips_school'],
        $record['q105_uses_drugs_nonmedical_purposes'],
        $record['q106_vandalism'],

    );
    $aggr_behav_array = array(
        $record['q3_argues_a_lot'],
        $record['q16_cruelty_bullying_meanness'],
        $record['q19_demands_a_lot_of_attention'],
        $record['q20_destroys_own_things'],
        $record['q21_destroys_things_belonging_to_others'],
        $record['q22_disobedient_at_home'],
        $record['q23_disobedient_at_school'],
        $record['q37_gets_in_many_fights'],
        $record['q57_physically_attacks_people'],
        $record['q68_screams_a_lot'],
        $record['q86_stubborn_sullen_irritable'],
        $record['q87_sudden_changes_in_mood_feelings'],
        $record['q88_sulks_a_lot'],
        $record['q89_suspicious'],
        $record['q94_teases_a_lot'],
        $record['q95_temper_tantrums_hot_temper'],
        $record['q97_threatens_people'],
        $record['q104_unusually_loud'],
    );

    $other_prob_array= array(
        $record['q6_bowel_movements_outside_toilet'],
$record['q7_bragging_boasting'],
$record['q15_cruel_to_animals'],
$record['q24_doesnt_eat_well'],
$record['q44_bites_fingernails'],
$record['q53_overeating'],
$record['q55_overweight'],
$record['q56h_other'],
$record['q74_showing_off_clowning'],
$record['q77_sleeps_more_than_most_kids_day_or_night'],
$record['q93_talks_too_much'],
$record['q98_thumb_sucking'],
$record['q107_wets_self_during_day'],
$record['q108_wets_the_bed'],
$record['q109_whining'],
$record['q110_wishes_to_be_opposite_sex'],
$record['additional_problem_1'],
$record['additional_problem_2'],
$record['additional_problem_3'],
    );

    $scores['anxious_score'] = $this->findRawScore($anxious_array);
    $scores['depressed_score'] = $this->findRawScore($depressed_array);
    $scores['som_comp_score'] = $this->findRawScore($som_comp_array);
    $scores['social_prob_score'] = $this->findRawScore($social_prob_array);
    $scores['thought_prob_score'] = $this->findRawScore($thought_prob_array);
    $scores['attention_prob_score'] = $this->findRawScore($attention_prob_array);
    $scores['rule_break_behav_score'] = $this->findRawScore($rule_break_behav_array);
    $scores['aggr_behav_score'] =  $this->findRawScore($aggr_behav_array);
    $scores['other_prob_score'] =  $this->findRawScore($other_prob_array);
   // Syndrome Raw Score calculation Finished
    //Internalization
    $scores['internalizing_score'] = $this->findRawScore($anxious_array) +  $this->findRawScore($depressed_array) + $this->findRawScore($som_comp_array);
    $scores['externalizing_score'] = $this->findRawScore($rule_break_behav_array)  +  $this->findRawScore($aggr_behav_array);
    // Sum of ext +int +other_prob +social + thought + attention
    $scores['total_problems_score'] =$this->findRawScore($social_prob_array) + $this->findRawScore($thought_prob_array) +  $this->findRawScore($attention_prob_array) + $this->findRawScore($other_prob_array) + $scores['internalizing_score'] + $scores['externalizing_score'];
   //Internalization, Ext, to scoring finish
    //DSM oriented scoring start
    $depressive_prob_array=array(
        $record['q5_very_little_they_enjoy'],
        $record['q14_cries_a_lot'],
        $record['q18_harms_self_attempts_suicide'],
        $record['q24_doesnt_eat_well'],
        $record['q35_feels_worthless_inferior'],
        $record['q52_feels_too_guilty'],
        $record['q54_overtired_without_good_reason'],
        $record['q76_sleeps_less_than_most_kids'],
        $record['q77_sleeps_more_than_most_kids_day_or_night'],
        $record['q91_talks_about_killing_self'],
        $record['q100_trouble_sleeping'],
        $record['q102_underactive_slow_moving_lacks_energy'],
        $record['q103_unhappy_sad_depressed'],
    );
    $scores['depressive_prob_score'] = $this->findRawScore($depressive_prob_array);

    $anx_prob_array=array(
        $record['q11_clings_to_adults_dependent'],
        $record['q29_fears_animals_situations_places'],
        $record['q30_fears_going_to_school'],
        $record['q31_fears_might_think_do_something_bad'],
        $record['q45_nervous_highstrung_tense'],
        $record['q47_nightmares'],
        $record['q50_too_fearful_or_anxious'],
        $record['q71_self_conscious_easily_embarrassed'],
        $record['q112_worries'],

    );
    $scores['anx_prob_score'] = $this->findRawScore($anx_prob_array);

    $som_prob_array=array(
        $record['q56a_aches_or_pains'],
        $record['q56b_headaches'],
        $record['q56c_nausea_feels_sick'],
        $record['q56d_problems_with_eyes'],
        $record['q56e_rashes_or_skin_problems'],
        $record['q56f_stomachaches'],
        $record['q56g_vomiting_throwing_up'],

    );
    $scores['som_prob_score'] = $this->findRawScore($som_prob_array);

    $attention_hyper_prob_array=array(
        $record['q4_fails_to_finish_things_starts'],
        $record['q8_cant_concentrate_for_long'],
        $record['q10_cant_sit_still_restless'],
        $record['q41_impulsive_acts_without_thinking'],
        $record['q78_inattentive_easily_distracted'],
        $record['q93_talks_too_much'],
        $record['q104_unusually_loud'],

    );
    $scores['attention_hyper_prob_score']=$this->findRawScore($attention_hyper_prob_array);

    $oppo_def_prob_array=array(
        $record['q3_argues_a_lot'],
        $record['q22_disobedient_at_home'],
        $record['q23_disobedient_at_school'],
        $record['q86_stubborn_sullen_irritable'],
        $record['q95_temper_tantrums_hot_temper'],
    );
    $scores['oppo_def_prob_score']=$this->findRawScore($oppo_def_prob_array);

    $conduct_prob_array=array(
        $record['q15_cruel_to_animals'],
        $record['q16_cruelty_bullying_meanness'],
        $record['q21_destroys_things_belonging_to_others'],
        $record['q26_doesnt_feel_guilty_misbehaving'],
        $record['q28_breaks_rules_home_school_elsewhere'],
        $record['q37_gets_in_many_fights'],
        $record['q39_hangs_around_others_who_get_in_trouble'],
        $record['q43_lying_or_cheating'],
        $record['q57_physically_attacks_people'],
        $record['q67_runs_away_from_home'],
        $record['q72_sets_fires'],
        $record['q81_steals_at_home'],
        $record['q82_steals_outside_home'],
        $record['q90_swearing_or_obscene_language'],
        $record['q97_threatens_people'],
        $record['q101_truancy_skips_school'],
        $record['q106_vandalism'],

    );
    $scores['conduct_prob_score']=$this->findRawScore($conduct_prob_array);
   // DSM oriented scoring finish

    //2007 scales scoring start

    $sluggish_cogn_tempo_array=array(
        $record['q13_confused_in_a_fog'],
        $record['q17_daydreams_gets_lost_in_thoughts'],
        $record['q80_stares_blankly'],
        $record['q102_underactive_slow_moving_lacks_energy'],

    );
    $scores['sluggish_cogn_tempo_score'] =$this->findRawScore($sluggish_cogn_tempo_array);

    $obsessive_comp_prob_array=array(
        $record['q9_cant_get_mind_off_certain_thoughts'],
        $record['q31_fears_might_think_do_something_bad'],
        $record['q32_feels_has_to_be_perfect'],
        $record['q52_feels_too_guilty'],
        $record['q66_repeats_certain_acts_compulsions'],
        $record['q84_strange_behaviour'],
        $record['q85_strange_ideas'],
        $record['q112_worries'],

    );
    $scores['obsessive_comp_prob_score'] =$this->findRawScore($obsessive_comp_prob_array);

    $stress_prob_array=array(
        $record['q3_argues_a_lot'],
        $record['q8_cant_concentrate_for_long'],
        $record['q9_cant_get_mind_off_certain_thoughts'],
        $record['q11_clings_to_adults_dependent'],
        $record['q31_fears_might_think_do_something_bad'],
        $record['q34_feels_others_out_to_get_them'],
        $record['q45_nervous_highstrung_tense'],
        $record['q47_nightmares'],
        $record['q50_too_fearful_or_anxious'],
        $record['q52_feels_too_guilty'],
        $record['q69_secretive'],
        $record['q87_sudden_changes_in_mood_feelings'],
        $record['q103_unhappy_sad_depressed'],
        $record['q111_withdrawn_doesnt_get_involved_with_others'],


    );
    $scores['stress_prob_score'] =$this->findRawScore($stress_prob_array);
   // 2007 scoring finish

    $timepoint =& TimePoint::singleton($this->getSessionID());
    $dob = $timepoint->getEffectiveDateOfBirth();

    $age = Utility::calculateAge($dob, $record["Date_taken"]);

    $age_months = $age['year'] * 12 + $age['mon'] + ($age['day'] / 30);
    $age_years = $age_months / 12;
    $age_years = floor($age_years);
    if (in_array($age_years, range(6, 11))) {
        $age_range = "6 to 11";
    } else if (in_array($age_years, range(12, 18))) {
        $age_range = "12 to 18";
    } else if ($age_years < 6 && $age_years >18) {
        $scores['score_validity'] = "Age not valid for scoring";
    }

    if ($scores['score_validity'] != NULL) {
        echo "T score and classification are applicable only for ages  6 to 18 years";
        echo "\n";
    }


    $query_gender = "SELECT Sex FROM candidate as c, session as s, flag as f, $this->table as t WHERE t.CommentID = '$this->commentID'
AND f.CommentID=t.CommentID AND s.ID=f.SessionID AND s.CandID=c.CandID";
    $record_gender = $db->pselectRow($query_gender, array());
    if ($record_gender['Sex'] == 'Male') {
        $gender = 'M';
    }
    if ($record_gender['Sex'] == 'Female') {
        $gender = 'F';
    }
    $scales=array(
        'anxious',
        'depressed',
        'som_comp',
        'social_prob',
        'thought_prob',
        'rule_break_behav',
        'aggr_behav',
        'attention_prob',
        'internalizing',
        'externalizing',
        'total_problems',
        'depressive_prob',
        'anx_prob',
        'som_prob',
        'attention_hyper_prob',
        'oppo_def_prob',
        'conduct_prob',
        'sluggish_cogn_tempo',
        'obsessive_comp_prob',
        'stress_prob'
    );


    foreach ($scales as $field) {
        $fied_raw_score=$scores[$field.'_score'];

        $query_scores1 = "SELECT * FROM CBCL_6_To_18_lookup WHERE
                age_years='$age_range' AND sex='$gender'  AND scale_raw_score= '$fied_raw_score' AND scale='$field'";
        $record_1 = $db->pselectRow($query_scores1, array());
        if (array_key_exists('scale_T_score', $record_1)) {
            if ($record_1['scale_T_score'] == "" || ($record_1['scale_T_score'] == NULL)) {
                $scores[$field . '_T_score'] = "NA";
            } else {
                $scores[$field . '_T_score'] = ($record_1['scale_T_score']);
            }
        } else {
            $scores[$field . '_T_score'] = "NA";
        }

        if (array_key_exists('scale_percentile', $record_1)) {
            if ($record_1['scale_percentile'] == "" || ($record_1['scale_percentile'] == NULL)) {
                $scores[$field . '_percentile'] = "NA";
            } else {
                $scores[$field . '_percentile'] = ($record_1['scale_percentile']);
            }
        } else {
            $scores[$field . '_percentile'] = "NA";
        }


    }

    $result = $db->update($this->table, $scores, array('CommentID'=>$this->getCommentID()));


}
    function findRawScore($scale_array)
    {
        $raw_score=0;
        foreach ($scale_array as $val)
        {
            if($val=='0')
            {
                $raw_score=$raw_score+0;
            }
            if($val=='1')
            {
                $raw_score=$raw_score+1;
            }
            if($val=='2')
            {
                $raw_score=$raw_score+2;
            }
            if($val=='3')
            {
                $raw_score=$raw_score+3;
            }
        }
        return $raw_score;
    }
}
?>
