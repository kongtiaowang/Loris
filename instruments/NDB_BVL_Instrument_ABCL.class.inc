<?php
/**
 * Creates the form elements for the ABCL instrument
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
 * Creates the form elements for the ABCL instrument
 *
 * @category Instrument
 * @package  Main
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_ABCL extends NDB_BVL_Instrument
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
    * @param string $page      if a multipage form, the page to show
    *
    * @return void
    * @access public
    */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)
        // set the object properties
        $this->testName = "ABCL";           // test_names.Test_name
        $this->table    = 'ABCL';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;
        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array(
                                 "Date_taken",
                                 "date_today",
                                 "adult_birthdate",
                                );

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    'first_name',
                                    'user_handicap',
                                    '1_is_too_forgetful',
                                    '37_gets_in_many_fights',
                                    '63_would_rather_be_with_older_people',
                                    '93_walks_too_much',
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
        if (preg_match("/ABCL(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("ABCL (Adult Behavior Checklist For Ages 18-59)");

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
    }

    /**
    * Generates the first page of the form.
    *
    * @return void
    */
    function _page1()
    {
        $this->addHeader("ABCL (Adult Behavior Checklist For Ages 18-59)");

        //Adult's Gender
        $gender_options = array(
                           null     => "",
                           "male"   => "Male",
                           "female" => "Female",
                           "other"  => "Other"
                          );

        $this->addSelect("adults_gender", "ADULT'S SEX", $gender_options);

        //Adult's Age
        $this->addBasicText("adult_age", "ADULT'S AGE <br><h5><i>(Please enter a numeric value between 0-100 or if you really don't wish to answer; enter NA)</i></h5>");
        //Ethnic Group or Race
        $this->addBasicText("ethnic_group_or_race", "ETHNIC GROUP OR RACE");

        //Adult's Birthdate (month, date, year)
        $this->addBasicDate('adult_birthdate', 'ADULT\'S BIRTHDATE');

        //Highest Education
        $opts = array(
                 null    => "",
                 "1"     => "1. No high school diploma and no GED",
                 "2"     => "2. General Equivalency Diploma (GED)",
                 "3"     => "3. High school graduate",
                 "4"     => "4. Some college but no college degree",
                 "5"     => "5. Associate’s Degree",
                 "6"     => "6. Bachelor’s or RN Degree",
                 "7"     => "7. Some graduate school but no graduate degree",
                 "8"     => "8. Master’s Degree",
                 "9"     => "9. Doctoral or Law degree",
                 "other" => "Other education (specify)",
                );

        $this->addSelect("user_education", "PLEASE CHECK ADULT'S HIGHEST EDUCATION", $opts);

        $this->addBasicText("if_other_education", "$this->indent If other, please specify:");

        $this->XINRegisterRule(
            "if_other_education",
            array("user_education{@}=={@}other"),
            "Required."
        );

        $this->addLabel("ADULT'S USUAL TYPE OF WORK, even if not working now. Please be specific- for example, auto mechanic; high school teacher; homemaker; laborer; lathe operator; shoe salesman; army sergeant; student (indicate what he/she is studying & what degree is expected).");

        $this->addBasicText("work_adult", "Adult's work");

        $this->addBasicText("work_spouse", "Spouse or partner's work");

        //Your relationship to Adult
        $relationship_options = array(
                                 null      => "",
                                 "spouse"  => "Spouse",
                                 "partner" => "Partner",
                                 "other"   => "Other (specify)",
                                );

        $this->addSelect("relationship_to_adult", "Your relationship to adult:", $relationship_options);

        $this->addBasicText("if_other_relationship", "$this->indent If other, please specify:");

        $this->XINRegisterRule(
            "if_other_relationship",
            array("relationship_to_adult{@}=={@}other"),
            "Required."
        );

        $this->form->addElement("static", null, "<br/>");

        $this->addLabel("Please fill out this form to reflect <i>your</i> views, even if other people might not agree. You need not spend a lot of time on any item. Feel free to give additional comments (optional). <i>Be sure to answer all items</i>");

        //I. FRIENDS
        $this->addHeader("I. FRIENDS");

        $friends_options_1 = array(
                              null   => "",
                              "none" => "None",
                              "1"    => "1",
                              "2"    => "2 or 3",
                              "3"    => "4 or more",
                             );

        $friends_options_2 = array(
                              null => "",
                              "0"  => "Less than 1",
                              "1"  => "1 or 2",
                              "2"  => "3 or 4",
                              "3"  => "5 or more",
                             );

        $friends_options_3 = array(
                              null            => "",
                              "not_well"      => "Not well",
                              "average"       => "Average",
                              "above_average" => "Above average",
                              "far_above"     => "Far above average",
                             );

        $this->addSelect("a_how_many_close_friends", "A. About how many close friends does he/she have? (Do not include family members.)", $friends_options_1);

        $this->addSelect("b_contact_with_close_friends", "B. About how many times a month does he/she have contact with any close friends? (Include in-person contacts, phone, letters, e-mail.)", $friends_options_2);

        $this->addSelect("c_how_well_do_they_get_along_with_friends", "C. How well does he/she get along with close friends?", $friends_options_3);

        $this->addSelect("d_how_many_times_do_family_or_friends_visit", "D. About how many times a month do any friends or family visit him/her?", $friends_options_2);

        $this->addBasicText("I_friends_comments", "Additional Comments (optional):");

        $this->XINRegisterRule(
            "I_friends_comments",
            array("I_friends_comments{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        //II. SPOUSE OR PARTNER
        $this->addHeader("II. SPOUSE OR PARTNER");

        //marital status
        $marital_status_opts = array(
                                null        => "",
                                "never"     => "Never been married",
                                "living"    => "Married, living with spouse",
                                "widowed"   => "Widowed",
                                "separated" => "Married but separated from spouse",
                                "divorced"  => "Divorced",
                                "other"     => "Other- please describe",
                               );

        $this->addSelect("marital_status_user", "What is his/her marital status?", $marital_status_opts);

        $this->addBasicText("if_other_marital", "$this->indent If other, please describe: ");

        $this->XINRegisterRule(
            "if_other_marital",
            array("marital_status_user{@}=={@}other"),
            "Required."
        );

        //Did they live with partner?
        $yes_no_opts = array(
                        null  => "",
                        "no"  => "No",
                        "yes" => "Yes",
                       );

        //if yes, answer following questions
        //if no, skip following questions
        $this->addSelect(
            "live_with_partner",
            "At any time in the past 6 months, did he/she live with a spouse or partner? 
        <br><h4><i>*(If 'No' selected, then subset of questions below (A-H) should be left blank OR if 'Yes', choose options beside items A-H)</i></h4>",
            $yes_no_opts
        );

        $options = array(
                    null => "",
                    "2"  => "2-Very True or Often True",
                    "1"  => "1-Somewhat or Sometimes True",
                    "0"  => "0-Not True (as far as you know)",
                   );

        $this->addSelect("a_gets_along_well_with_partner", "A. Gets along well with spouse or partner", $options);

        $this->XINRegisterRule(
            "a_gets_along_well_with_partner",
            array("live_with_partner{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("b_trouble_sharing_responsibilities", "B. Has trouble sharing responsibilities with spouse or partner", $options);

        $this->XINRegisterRule(
            "b_trouble_sharing_responsibilities",
            array("live_with_partner{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("c_seems_satisfied_with_spouse_or_partner", "C. Seems satisfied with spouse or partner", $options);

        $this->XINRegisterRule(
            "c_seems_satisfied_with_spouse_or_partner",
            array("live_with_partner{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("d_enjoys_similar_activities_as_partner", "D. Enjoys similar activities as spouse or partner", $options);

        $this->XINRegisterRule(
            "d_enjoys_similar_activities_as_partner",
            array("live_with_partner{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("e_disagrees_with_partner_about_living_arrangements", "E. Disagrees with spouse or partner about living arrangements, such as where to live", $options);

        $this->XINRegisterRule(
            "e_disagrees_with_partner_about_living_arrangements",
            array("live_with_partner{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("f_has_trouble_with_family_of_partner", "F. Has trouble with spouse or partner's family", $options);

        $this->XINRegisterRule(
            "f_has_trouble_with_family_of_partner",
            array("live_with_partner{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("g_likes_friends_of_partner", "G. Likes spouse or partner's friends", $options);

        $this->XINRegisterRule(
            "g_likes_friends_of_partner",
            array("live_with_partner{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("h_annoyed_by_behavior_of_spouse", "H. Is annoyed by spouse or partner's behavior", $options);

        $this->XINRegisterRule(
            "h_annoyed_by_behavior_of_spouse",
            array("live_with_partner{@}=={@}yes"),
            "Required."
        );

        $this->addBasicTextArea("II_spouse_partner_comments", "Additional Comments (optional):");

        $this->XINRegisterRule(
            "II_spouse_partner_comments",
            array("II_spouse_partner_comments{@}=={@}NEVER_REQUIRED")
        );

        $this->form->addFormRule(array(&$this, 'abcl_special_rules'));
    }

    /**
    * Generates the second page of the form.
    *
    * @return void
    */
    function _page2()
    {

        $this->addHeader("ABCL (Adult Behavior Checklist For Ages 18-59)");

        //III. Does he/she have any illness, disability, or handicap?
        $opts = array(
                 null  => "",
                 "no"  => "No",
                 "yes" => "Yes-please describe",
                );

        $this->addSelect("user_handicap", "<h4>III. Does he/she have any illness, disability, or handicap?</h4>", $opts);

        $this->addBasicText("user_handicap_yes", "$this->indent If yes, please describe:");

        $this->XINRegisterRule(
            "user_handicap_yes",
            array("user_handicap{@}=={@}yes"),
            "Required."
        );

        //IV. Please describe any concerns you have about him/her:
        $concerns_options = array(
                             null  => "",
                             "no"  => "No concerns",
                             "yes" => "Yes-please describe",
                            );

        $this->addSelect("user_concerns", "<h4>IV. Please describe any concerns you have about him/her:</h4>", $concerns_options);

        $this->addBasicText("user_concerns_yes", "$this->indent If yes, please describe:");

        $this->XINRegisterRule(
            "user_concerns_yes",
            array("user_concerns{@}=={@}yes"),
            "Required."
        );

        //V. Please describe the best things about him/her:
        $this->addBasicText("describe_best_things_about_them", "<h4>V. Please describe the best things about him/her:</h4>");

        $this->addBasicText("III_IV_V_comments", "Additional Comments (optional):");

        $this->XINRegisterRule(
            "III_IV_V_comments",
            array("III_IV_V_comments{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addFormRule(array(&$this, 'abcl_special_rules'));
    }

    /**
    * Generates the third page of the form.
    *
    * @return void
    */
    function _page3()
    {
        $this->addHeader("ABCL (Adult Behavior Checklist For Ages 18-59)");

        $this->addLabel("<h3>VI. Below is a list of items that describe people. As you read each item, please decide whether it has been true of the adult <i>over the past 6 months</i>. Then choose <i>0, 1,</i> or <i>2</i> to describe the adult. Please answer all items as well as you can, even if some do not seem to apply to the adult.</h3>");

        $options = array(
                    null => "",
                    "2"  => "2-Very True or Often True",
                    "1"  => "1-Somewhat or Sometimes True",
                    "0"  => "0-Not True (as far as you know)",
                   );

        $this->addSelect("1_is_too_forgetful", "1. Is too forgetful", $options);

        $this->addSelect("2_makes_good_use_of_opportunities", "2. Makes good use of his/her opportunities", $options);

        $this->addSelect("3_argues_a_lot", "3. Argues a lot", $options);

        $this->addSelect("4_works_up_to_ability", "4. Works up to ability", $options);

        $this->addSelect("5_blames_others_for_own_problems", "5. Blames others for own problems", $options);

        $this->addSelect("6_uses_drugs_for_nonmedical_purposes", "6.(i) Uses drugs (other than alcohol or nicotine) for nonmedical purposes", $options);

        $this->addBasicText("6_continued", "6.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "6_continued",
            array("6_uses_drugs_for_nonmedical_purposes{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("7_bragging_boasting", "7. Bragging, boasting", $options);

        $this->addSelect("8_cant_concentrate_or_pay_attention", "8. Can't concentrate, can't pay attention for long", $options);

        $this->addSelect("9_cant_get_mind_off_certain_thoughts", "9.(i) Can't get mind off certain thoughts; obsessions", $options);

        $this->addBasicText("9_continued", "9.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "9_continued",
            array("9_cant_get_mind_off_certain_thoughts{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("10_cant_sit_still", "10. Can't sit still, restless, or hyperactive", $options);

        $this->addSelect("11_too_dependent_on_others", "11. Too dependent on others", $options);

        $this->addSelect("12_complains_of_loneliness", "12. Complains of loneliness", $options);

        $this->addSelect("13_confused_or_in_a_fog", "13. Confused or seems to be in a fog", $options);

        $this->addSelect("14_cries_a_lot", "14. Cries a lot", $options);

        $this->addSelect("15_pretty_honest", "15. Is pretty honest", $options);

        $this->addSelect("16_cruelty_bullying_meanness", "16. Cruelty, bullying, or meanness to others", $options);

        $this->addSelect("17_daydreams_or_gets_lost_in_thoughts", "17. Daydreams or gets lost in his/her thoughts", $options);

        $this->addSelect("18_deliberately_harms_self", "18. Deliberately harms self or attempts suicide", $options);

        $this->addSelect("19_demands_attention", "19. Demands a lot of attention", $options);

        $this->addSelect("20_damages_own_things", "20. Damages or destroys his/her own things", $options);

        $this->addSelect("21_damages_things_belonging_to_others", "21. Damages or destroys things belonging to others", $options);

        $this->addSelect("22_worries_about_their_future", "22. Worries about his/her future", $options);

        $this->addSelect("23_breaks_rules", "23. Breaks rules at work or elsewhere", $options);

        $this->addSelect("24_does_not_eat_well", "24. Doesn't eat well", $options);

        $this->addSelect("25_does_not_get_along_with_others", "25. Doesn't get along with other people", $options);

        $this->addSelect("26_does_not_feel_guilty_after_misbehaving", "26. Doesn't seem to feel guilty after misbehaving", $options);

        $this->addSelect("27_easily_jealous", "27. Easily jealous", $options);

        $this->addSelect("28_gets_along_badly_with_family", "28. Gets along badly with family", $options);

        $this->addSelect("29_fears_certain_animals_situations_places", "29.(i) Fears certain animals, situations, or places", $options);

        $this->addBasicText("29_continued", "29.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "29_continued",
            array("29_fears_certain_animals_situations_places{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("30_poor_relations_with_opposite_sex", "30. Poor relations with opposite sex", $options);

        $this->addSelect("31_fears_they_might_think_or_do_something_bad", "31. Fears he/she might think or do something bad", $options);

        $this->addSelect("32_feels_they_have_to_be_perfect", "32. Feels he/she has to be perfect", $options);

        $this->addSelect("33_feels_or_complains_that_no_one_loves_them", "33. Feels or complains that no one loves him/her", $options);

        $this->addSelect("34_feels_others_are_out_to_get_them", "34. Feels others are out to get him/her", $options);

        $this->addSelect("35_feels_worthless_or_inferior", "35. Feels worthless or inferior", $options);

        $this->addSelect("36_gets_hurt_a_lot", "36. Gets hurt a lot, accident-prone", $options);

        $this->form->addFormRule(array(&$this, 'abcl_special_rules'));
    }


    /**
    * Generates the fourth page of the form.
    *
    * @return void
    */
    function _page4()
    {
        $this->addHeader("ABCL (Adult Behavior Checklist For Ages 18-59)");

        $options = array(
                    null => "",
                    "2"  => "2-Very True or Often True",
                    "1"  => "1-Somewhat or Sometimes True",
                    "0"  => "0-Not True (as far as you know)",
                   );

        $this->addSelect("37_gets_in_many_fights", "37. Gets in many fights", $options);

        $this->addSelect("38_poor_relations_with_neighbors", "38. His/her relations with neighbors are poor", $options);

        $this->addSelect("39_hangs_around_people_who_get_in_trouble", "39. Hangs around people who get in trouble", $options);

        $this->addSelect("40_hears_sounds_or_voices", "40.(i) Hears sounds or voices that aren't there", $options);

        $this->addBasicText("40_continued", "40.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "40_continued",
            array("40_hears_sounds_or_voices{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("41_acts_without_thinking", "41. Impulsive or acts without thinking", $options);

        $this->addSelect("42_would_rather_be_alone", "42. Would rather be alone than with others", $options);

        $this->addSelect("43_lying_or_cheating", "43. Lying or cheating", $options);

        $this->addSelect("44_feels_overwhelmed_by_responsibilities", "44. Feels overwhelmed by responsibilities", $options);

        $this->addSelect("45_nervous_highstrung_tense", "45. Nervous, highstrung, or tense", $options);

        $this->addSelect("46_nervous_movements", "46.(i) Nervous movements or twitching", $options);

        $this->addBasicText("46_continued", "46.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "46_continued",
            array("46_nervous_movements{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("47_lacks_self_confidence", "47. Lacks self-confidence", $options);

        $this->addSelect("48_not_liked_by_others", "48. Not liked by others", $options);

        $this->addSelect("49_can_do_certain_things_better_than_others", "49. Can do certain things better than other people", $options);

        $this->addSelect("50_too_fearful_or_anxious", "50. Too fearful or anxious", $options);

        $this->addSelect("51_feels_dizzy_or_lightheaded", "51. Feels dizzy or lightheaded", $options);

        $this->addSelect("52_feels_too_guilty", "52. Feels too guilty", $options);

        $this->addSelect("53_trouble_planning_for_future", "53. Has trouble planning for the future", $options);

        $this->addSelect("54_trouble_planning_for_future", "54. Feels tired without good reasons", $options);

        $this->addSelect("55_moods_swing_between_elation_and_depression", "55. Moods swing between elation and depression", $options);

        $this->addLabel("56.Physical problems <i>without known medical cause:</i>");

        $this->addSelect("a_aches_or_pains", "a. Aches or pains (<i>not</i> stomach or headaches)", $options);

        $this->addSelect("b_headaches", "b. Headaches", $options);

        $this->addSelect("c_nausea", "c. Nausea, feels sick", $options);

        $this->addSelect("d_problems_witih_eyes", "d.(i) Problems with eyes (<i>not</i> if corrected by glasses)", $options);

        $this->addBasicText("d_continued", "d.(ii) Description: <h5><i>(Required if selected 'True' for Problems with eyes)</i></h5>");

        $this->XINRegisterRule(
            "d_continued",
            array("d_problems_witih_eyes{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("e_skin_problems", "e. Rashes or other skin problems", $options);

        $this->addSelect("f_stomachaches", "f. Stomachaches", $options);

        $this->addSelect("g_vomiting", "g. Vomiting, throwing up", $options);

        $this->addSelect("57_physically_attacks_people", "57. Physically attacks people", $options);

        $this->addSelect("58_picks_skin_or_other_parts_of_body", "58.(i) Picks skin or other parts of his/her body", $options);

        $this->addBasicText("58_continued", "58.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "58_continued",
            array("58_picks_skin_or_other_parts_of_body{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("59_fails_to_finish_things_they_should_do", "59. Fails to finish things he/she should do", $options);

        $this->addSelect("60_enjoys_very_little", "60. There is very little that he/she enjoys", $options);

        $this->addSelect("61_poor_work_performance", "61. Poor work performance", $options);

        $this->addSelect("62_poorly_coordinated", "62. Poorly coordinated or clumsy", $options);

        $this->form->addFormRule(array(&$this, 'abcl_special_rules'));
    }

    /**
    * Generates the fifth page of the form.
    *
    * @return void
    */
    function _page5()
    {
        $this->addHeader("ABCL (Adult Behavior Checklist For Ages 18-59)");

        $options = array(
                    null => "",
                    "2"  => "2-Very True or Often True",
                    "1"  => "1-Somewhat or Sometimes True",
                    "0"  => "0-Not True (as far as you know)",
                   );

        $this->addSelect("63_would_rather_be_with_older_people", "63. Would rather be with older people than with people of own age", $options);

        $this->addSelect("64_has_trouble_setting_priorities", "64. Has trouble setting priorities", $options);

        $this->addSelect("65_refuses_to_talk", "65. Refuses to talk", $options);

        $this->addSelect("66_repeats_certain_acts", "66.(i) Repeats certain acts over and over; compulsions", $options);

        $this->addBasicText("66_continued", "66.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "66_continued",
            array("66_repeats_certain_acts{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("67_has_trouble_making_or_keeping_friends", "67. Has trouble making or keeping friends", $options);

        $this->addSelect("68_screams_or_yells_a_lot", "68. Screams or yells a lot", $options);

        $this->addSelect("69_keeps_things_to_self", "69. Secretive, keeps things to self", $options);

        $this->addSelect("70_sees_things_that_are_not_there", "70.(i) Sees things that aren't there (describe)", $options);

        $this->addBasicText("70_continued", "70.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "70_continued",
            array("70_sees_things_that_are_not_there{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("71_self_conscious_or_easily_embarrassed", "71. Self-conscious or easily embarrassed", $options);

        $this->addSelect("72_worries_about_their_family", "72. Worries about his/her family", $options);

        $this->addSelect("73_meets_responsibilities_to_their_family", "73. Meets responsibilities to his/her family", $options);

        $this->addSelect("74_showing_off", "74. Showing off or clowning", $options);

        $this->addSelect("75_too_shy_or_timid", "75. Too shy or timid", $options);

        $this->addSelect("76_irresponsible_behavior", "76. Irresponsible behavior", $options);

        $this->addSelect("77_sleeps_more_than_most_others", "77.(i) Sleeps more than most other people during day and/or night (describe)", $options);

        $this->addBasicText("77_continued", "77.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "77_continued",
            array("77_sleeps_more_than_most_others{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("78_has_trouble_making_decisions", "78. Has trouble making decisions", $options);

        $this->addSelect("79_speech_problem", "79.(i) Speech problem (describe)", $options);

        $this->addBasicText("79_continued", "79.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "79_continued",
            array("79_speech_problem{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("80_stares_blankly", "80. Stares blankly", $options);

        $this->addSelect("81_very_changeable_behaavior", "81. Very changeable behavior", $options);

        $this->addSelect("82_steals", "82. Steals", $options);

        $this->addSelect("83_easily_bored", "83. Is easily bored", $options);

        $this->addSelect("84_strange_behavior", "84.(i) Strange behavior (describe)", $options);

        $this->addBasicText("84_continued", "84.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "84_continued",
            array("84_strange_behavior{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("85_strange_ideas", "85.(i) Strange ideas (describe)", $options);

        $this->addBasicText("85_continued", "85.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "85_continued",
            array("85_strange_ideas{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("86_stubborn_sullen_irritable", "86. Stubborn, sullen, or irritable", $options);

        $this->addSelect("87_sudden_changes_in_mood_or_feelings", "87. Sudden changes in mood or feelings", $options);

        $this->addSelect("88_enjoys_being_with_people", "88. Enjoys being with people", $options);

        $this->addSelect("89_rushes_into_things_without_considering_risks", "89. Rushes into things without considering the risks", $options);

        $this->addSelect("90_drinks_too_much_alcohol", "90. Drinks too much alcohol or gets drunk", $options);

        $this->addSelect("91_talks_about_killing_self", "91. Talks about killing self", $options);

        $this->addSelect("92_does_things_that_may_cause_trouble_with_law", "92(i). Does things that may cause trouble with the law (describe)", $options);

        $this->addBasicText("92_continued", "92.(ii)Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "92_continued",
            array("92_does_things_that_may_cause_trouble_with_law{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->form->addFormRule(array(&$this, 'abcl_special_rules'));
    }

    /**
    * Generates the sixth page of the form.
    *
    * @return void
    */
    function _page6()
    {
        $this->addHeader("ABCL (Adult Behavior Checklist For Ages 18-59)");

        $options = array(
                    null => "",
                    "2"  => "2-Very True or Often True",
                    "1"  => "1-Somewhat or Sometimes True",
                    "0"  => "0-Not True (as far as you know)",
                   );

        $this->addSelect("93_walks_too_much", "93. Talks too much", $options);

        $this->addSelect("94_teases_a_lot", "94. Teases a lot", $options);

        $this->addSelect("95_temper_tantrums", "95. Temper tantrums or hot temper", $options);

        $this->addSelect("96_passive_or_lacks_initiative", "96. Passive or lacks initiative", $options);

        $this->addSelect("97_threatens_to_hurt_people", "97. Threatens to hurt people", $options);

        $this->addSelect("98_likes_to_help_others", "98. Likes to help others", $options);

        $this->addSelect("99_dislikes_staying_in_one_place_for_long", "99. Dislikes staying in one place for very long", $options);

        $this->addSelect("100_trouble_sleeping", "100. Has trouble sleeping", $options);

        $this->addSelect("101_stays_away_from_job_even_when_not_sick_or_on_vacation", "101. Stays away from job even when not sick and not on vacation", $options);

        $this->addSelect("102_underactive_slow_moving_lacks_energy", "102. Underactive, slow moving, or lacks energy", $options);

        $this->addSelect("103_unhappy_sad_depressed", "103. Unhappy, sad, or depressed", $options);

        $this->addSelect("104_unusually_loud", "104. Is unusually loud", $options);

        $this->addSelect("105_disorganized", "105. Is disorganized", $options);

        $this->addSelect("106_tries_to_be_fair", "106. Tries to be fair to others", $options);

        $this->addSelect("107_feels_they_cant_succeed", "107. Feels he/she can't succeed", $options);

        $this->addSelect("108_tends_to_lose_things", "108. Tends to lose things", $options);

        $this->addSelect("109_likes_to_try_new_things", "109. Likes to try new things", $options);

        $this->addSelect("110_makes_good_decisions", "110. Makes good decisions", $options);

        $this->addSelect("111_withdrawn_not_involved_with_others", "111. Withdrawn, doesn't get involved with others", $options);

        $this->addSelect("112_worries", "112. Worries", $options);

        $this->addSelect("113_sulks_a_lot", "113. Sulks a lot", $options);

        $this->addSelect("114_fails_to_pay_debts_or_meet_financial_responsibilities", "114. Fails to pay his/her debts or meet other financial responsibilities", $options);

        $this->addSelect("115_restless_or_fidgety", "115. Is restless or fidgety", $options);

        $this->addSelect("116_gets_upset_too_easily", "116. Gets upset too easily", $options);

        $this->addSelect("117_trouble_managing_money_or_credit_cards", "117. Has trouble managing money or credit cards", $options);

        $this->addSelect("118_too_impatient", "118. Is too impatient", $options);

        $this->addSelect("119_not_good_at_details", "119. He/she is not good at details", $options);

        $this->addSelect("120_drives_too_fast", "120. Drives too fast", $options);

        $this->addSelect("121_tends_to_be_late_for_appointments", "121. Tends to be late for appointments", $options);

        $this->addSelect("122_trouble_keeping_job", "122. Has trouble keeping a job", $options);

        $this->addSelect("123_is_happy_person", "123. He/she is a happy person", $options);

        $this->addBasicText("124_how_many_times_per_day_did_they_use_tobacco", "124. <i>In the past 6 months,</i> about how many times per day did he/she use tobacco (including smokeless tobacco)?");

        $this->addBasicText("125_how_many_days_were_they_drunk", "125. <i>In the past 6 months,</i> on how many days was he/she drunk?");

        $this->addBasicText("126_how_many_days_use_drugs_for_nonmedical_purposes", "126. <i>In the past 6 months,</i> on how many days did he/she use drugs for nonmedical purposes (including marijuana, cocaine, and other drugs, except alcohol and nicotine)?");

        $this->addBasicText("VI_comments", "Additional Comments (optional):");

        $this->XINRegisterRule(
            "VI_comments",
            array("VI_comments{@}=={@}NEVER_REQUIRED"),
            "Not required."
        );
    }

    function abcl_special_rules($values)
    {
        $errors = array();
        //any page1 value is set
        if (isset($values['adult_age'])) {
            if (is_numeric($values['adult_age'])) {
                if (intval($values['adult_age']) > 100 || intval($values['adult_age']) < 0) {

                    $errors['adult_age'] = "Specify age between 0 and 100 or NA";
                }
            } else {
                if ($values['adult_age'] != 'NA') {
                    $errors['adult_age'] = "Specify age between 0 and 100 or NA";
                }
            }

            $blank_restricted_spouse_array = array(
                                              'a_gets_along_well_with_partner',
                                              'b_trouble_sharing_responsibilities',
                                              'c_seems_satisfied_with_spouse_or_partner',
                                              'd_enjoys_similar_activities_as_partner',
                                              'e_disagrees_with_partner_about_living_arrangements',
                                              'g_likes_friends_of_partner',
                                              'f_has_trouble_with_family_of_partner',
                                              'h_annoyed_by_behavior_of_spouse',
                                             );

            foreach ($blank_restricted_spouse_array as $value) {
                if ($values['live_with_partner'] == 'no' && $values[$value] != "") {
                    $errors[$value] = "This field should be left blank OR change the response in the above question of the applicable subset.";
                }
            }

            if ($values['marital_status_user'] != 'other' && $values['if_other_marital'] != "") {
                $errors['if_other_marital'] = "This field should be left blank OR change the response in the above question.";
            }

            if ($values['user_education'] != 'other' && $values['if_other_education'] != "") {
                $errors['if_other_education'] = "This field should be left blank OR change the response in the above question.";
            }

            if ($values['relationship_to_adult'] != 'other' && $values['if_other_relationship'] != "") {
                $errors['if_other_relationship'] = "This field should be left blank OR change the response in the above question.";
            }
        }

        //any page2 value is set
        if (isset($values['user_concerns'])) {
            $yes_restricted_array = array(
                                     'user_concerns',
                                     'user_handicap',
                                    );
            foreach ($yes_restricted_array as $val) {
                if ($values[$val] == 'no' && $values[$val . '_yes'] != "") {
                    $errors[$val . '_yes'] = "This field should be left blank OR change the response in the above question.";
                }
            }
        }

        //any page3 val is set
        if (isset($values['6_uses_drugs_for_nonmedical_purposes'])) {
            $blank_restricted_array_page3 = array(
                                             '6_uses_drugs_for_nonmedical_purposes',
                                             'user_handicap',
                                             '9_cant_get_mind_off_certain_thoughts',
                                             '29_fears_certain_animals_situations_places',
                                            );
            foreach ($blank_restricted_array_page3 as $val) {
                $question_description_split = explode("_", $val);
                $question_number            =$question_description_split[0];
                if ($values[$val] == '0' && $values[$question_number . '_continued'] != "") {
                    $errors[$question_number . '_continued'] = "This field should be left blank OR change the response in the above question.";
                }
            }
        }

        //any page4 val is set
        if (isset($values['40_hears_sounds_or_voices'])) {
            $blank_restricted_array_page4 = array(
                                             '40_hears_sounds_or_voices',
                                             '46_nervous_movements',
                                             'd_problems_witih_eyes',
                                             '58_picks_skin_or_other_parts_of_body',
                                            );
            foreach ($blank_restricted_array_page4 as $val) {
                $question_description_split = explode("_", $val);
                $question_number            =$question_description_split[0];
                if ($values[$val] == '0' && $values[$question_number . '_continued'] != "") {
                    $errors[$question_number . '_continued'] = "This field should be left blank OR change the response in the above question.";
                }
            }
        }

        //any page5 val is set
        if (isset($values['66_repeats_certain_acts'])) {
            $blank_restricted_array_page5 = array(
                                             '66_repeats_certain_acts',
                                             '70_sees_things_that_are_not_there',
                                             '77_sleeps_more_than_most_others',
                                             '79_speech_problem',
                                             '84_strange_behavior',
                                             '85_strange_ideas',
                                             '92_does_things_that_may_cause_trouble_with_law',
                                            );

            foreach ($blank_restricted_array_page5 as $val) {
                $question_description_split = explode("_", $val);
                $question_number            =$question_description_split[0];

                if ($values[$val] == '0' && $values[$question_number . '_continued'] != "") {
                    $errors[$question_number . '_continued'] = "This field should be left blank OR change the response in the above question.";
                }
            }
        }

        return $errors;
    }
}
?>
