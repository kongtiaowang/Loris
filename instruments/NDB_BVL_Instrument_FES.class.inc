<?php
/**
 * This file contains the NDB_BVL_Instrument_FES class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  IBIS
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the FES instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_FES extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('FES', "FES (Family Environment Scale Form - Revised) - Survey", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('FES','FES_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('FES','FES_page2', "Page 2", 2);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('FES','FES_page3', "Page 3", 3);
     */

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
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
        $this->form     = new LorisForm('FES_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "FES";           // test_names.Test_name
        $this->table    = 'FES';           // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields =array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    'q1_family_help_support_one_another',
                                    'q31_feeling_of_togetherness',
                                    'q61_very_little_group_spirit',
                                   );

        // setup the form
        $this->_setupForm();
    }

    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

    /**
    * Method to build the LorisForm object into a paged form
    *
    * @return void
    * @access private
    */
    function _setupForm()
    {
        if (preg_match("/FES(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("FES (Family Environment Scale Form - Revised) - Survey");

        $this->addHeader(
            "<h3><b>Instructions:<br><br>
            <i>Please fill this form out with regard to your child who has enrolled in our study, NOT their older sibling with autism.</i><br><br>
            There are 90 statements in this survey.
            They are statements about families.
            You are to decide which of these statements are true of your family and which are false.
            If you think the statement is True or mostly True of your family, select the True option.
            If you think the statement is False or mostly False of your family, select the False option.
            You may feel that some of the statements are true for some family members and false for others.
            Mark True if the statement is true for most members.
            Mark False if the statement is false for most members.
            If the members are evenly divided, decide what is the stronger overall impression and answer accordingly.
            Remember, we would like to know what your family seems like to <i>you</i>.
            So do not try to figure out how other members see your family, but <i>do</i> give us your general impression of your family for each statement.
            </b></h3><br>"
        );
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
        $this->form->addElement(
            'select',
            'respondent',
            'What is your relationship to the child',
            array(
             ''            => '',
             'mother'      => 'Mother',
             'father'      => 'Father',
             'step_mother' => 'Step Mother',
             'step_father' => 'Step Father',
             'other'       => 'Other',
            )
        );

        $this->form->addElement('text', 'respondent_specify', 'If other, specify:');

        $this->XINRegisterRule('respondent_specify', array('respondent{@}=={@}other'), 'Required if other');
    }

    /**
    * Generates the first page of the form.
    *
    * @return void
    */
    function _page1()
    {
        $this->addHeader("FES (Family Environment Scale Form - Revised) - Survey");

        $options = array(
                    null           => '',
                    'true'         => "True",
                    'false'        => "False",
                    'not_answered' => "Not Answered",
                   );

        $page1_questions = array(
                            "q1_family_help_support_one_another"                 => "1. Family members really help and support one another.",
                            "q2_family_keep_feelings_to_themselves"              => "2. Family members often keep their feelings to themselves.",
                            "q3_fight_a_lot_in_our_family"                       => "3. We fight a lot in our family.",
                            "q4_dont_do_things_on_our_own_often"                 => "4. We don't do things on our own very often in our family.",
                            "q5_important_to_be_best_at_what_you_do"             => "5. We feel it is important to be the best at whatever you do.",
                            "q6_often_talk_about_political_social_problems"      => "6. We often talk about political and social problems.",
                            "q7_spend_most_weekends_and_evenings_at_home"        => "7. We spend most weekends and evenings at home.",
                            "q8_family_attend_church_synagogue_sunday_school"    => "8. Family members attend church, synagogue, or Sunday School fairly often.",
                            "q9_activities_carefully_planned"                    => "9. Activities in our family are pretty carefully planned.",
                            "q10_family_rarely_ordered_around"                   => "10. Family members are rarely ordered around.",
                            "q11_often_killing_time_at_home"                     => "11. We often seem to be killing time at home.",
                            "q12_say_anything_we_want"                           => "12. We say anything we want to around home.",
                            "q13_family_rarely_become_openly_angry"              => "13. Family members rarely become openly angry.",
                            "q14_strongly_encouraged_to_be_independent"          => "14. In our family, we are strongly encouraged to be independent.",
                            "q15_getting_ahead_in_life_very_important"           => "15. Getting ahead in life is very important in our family.",
                            "q16_rarely_go_to_lectures_plays_concerts"           => "16. We rarely go to lectures, plays or concerts.",
                            "q17_friends_often_come_over_dinner_visit"           => "17. Friends often come over for dinner or to visit.",
                            "q18_we_dont_say_prayers"                            => "18. We don't say prayers in our family.",
                            "q19_generally_very_neat_orderly"                    => "19. We are generally very neat and orderly.",
                            "q20_very_few_rules_to_follow"                       => "20. There are very few rules to follow in our family.",
                            "q21_put_lot_of_energy_into_what_we_do"              => "21. We put a lot of energy into what we do at home.",
                            "q22_hard_to_blow_off_steam_without_upsetting"       => "22. It's hard to \"blow off steam\" at home without upsetting somebody.",
                            "q23_family_get_so_angry_they_throw_things"          => "23. Family members sometimes get so angry they throw things.",
                            "q24_think_things_out_for_ourselves"                 => "24. We think things out for ourselves in our family.",
                            "q25_how_much_money_not_important"                   => "25. How much money a person makes is not very important to us.",
                            "q26_learning_new_different_things_important"        => "26. Learning about new and different things is very important in our family.",
                            "q27_nobody_is_active_in_sports"                     => "27. Nobody in our family is active in sports, Little League, bowling, etc.",
                            "q28_often_talk_about_religious_meaning_of_holidays" => "28. We often talk about the religious meaning of Christmas, Passover, or other holidays.",
                            "q29_hard_to_find_things_when_need"                  => "29. It's often hard to find things when you need them in our household.",
                            "q30_family_member_makes_most_decisions"             => "30. There is one family member who makes most of the decisions.",
                           );

        foreach ($page1_questions as $key => $question) {
            $this->addSelect($key, $question, $options);
        }
    }

    /**
    * Generates the second page of the form.
    *
    * @return void
    */
    function _page2()
    {
        $this->addHeader("FES (Family Environment Scale Form - Revised) - Survey");

        $options = array(
                    null           => '',
                    'true'         => "True",
                    'false'        => "False",
                    'not_answered' => "Not Answered",
                   );

        $page2_questions = array(
                            "q31_feeling_of_togetherness"                        => "31. There is a feeling of togetherness in our family.",
                            "q32_tell_each_other_about_personal_problems"        => "32. We tell each other about our personal problems.",
                            "q33_family_members_hardly_lose_tempers"             => "33. Family members hardly ever lose their tempers.",
                            "q34_come_and_go_as_we_want"                         => "34. We come and go as we want to in our family.",
                            "q35_believe_in_competition"                         => "35. We believe in competition and \"may the best man win.\"",
                            "q36_not_interested_in_cultural_activities"          => "36. We are not that interested in cultural activities.",
                            "q37_often_go_to_movies_sports_events_camping"       => "37. We often go to the movies, sports events, camping, etc.",
                            "q38_dont_believe_in_heaven_hell"                    => "38. We don't believe in heaven or hell.",
                            "q39_being_on_time_is_important"                     => "39. Being on time is very important in our family.",
                            "q40_set_ways_of_doing_things_at_home"               => "40. There are set ways of doing things at home.",
                            "q41_rarely_volunteer_when_something_has_to_be_done" => "41. We rarely volunteer when something has to be done at home.",
                            "q42_spur_of_moment_pick_up_and_go"                  => "42. If we feel like doing something on the spur of the moment we often pick up and go.",
                            "q43_family_often_criticize_each_other"              => "43. Family members often criticize each other.",
                            "q44_very_little_privacy"                            => "44. There is very little privacy in our family.",
                            "q45_strive_to_do_better_next_time"                  => "45. We always strive to do things just a little better the next time.",
                            "q46_rarely_have_intellectual_discussions"           => "46. We rarely have intellectual discussions.",
                            "q47_everyone_has_hobby_or_two"                      => "47. Everyone in our family has a hobby or two.",
                            "q48_strict_ideas_about_right_or_wrong"              => "48. Family members have strict ideas about what is right or wrong.",
                            "q49_people_change_their_minds_often"                => "49. People change their minds often in our family.",
                            "q50_strong_emphasis_on_following_rules"             => "50. There is a strong emphasis on following rules in our family.",
                            "q51_family_back_each_other_up"                      => "51. Family members really back each other up.",
                            "q52_someone_gets_upset_if_you_complain"             => "52. Someone usually gets upset if you complain in our family.",
                            "q53_family_sometimes_hit_each_other"                => "53. Family members sometimes hit each other.",
                            "q54_rely_on_themselves_when_problem_comes_up"       => "54. Family members almost always rely on themselves when a problem comes up.",
                            "q55_rarely_worry_about_job_school"                  => "55. Family members rarely worry about job promotions, school grades, etc.",
                            "q56_plays_musical_instrument"                       => "56. Someone in our family plays a musical instrument.",
                            "q57_not_involved_in_recreational_activities"        => "57. Family members are not very involved in recreational activities outside work or school.",
                            "q58_believe_some_things_take_on_faith"              => "58. We believe there are some things you just have to take on faith.",
                            "q59_make_sure_rooms_are_neat"                       => "59. Family members make sure their rooms are neat.",
                            "q60_everyone_has_equal_say_in_family_decisions"     => "60. Everyone has an equal say in family decisions.",
                           );

        foreach ($page2_questions as $key => $question) {
            $this->addSelect($key, $question, $options);
        }
    }

    /**
    * Generates the third page of the form.
    *
    * @return void
    */
    function _page3()
    {
        $this->addHeader("FES (Family Environment Scale Form - Revised) - Survey");

        $options = array(
                    null           => '',
                    'true'         => "True",
                    'false'        => "False",
                    'not_answered' => "Not Answered",
                   );

        $page3_questions = array(
                            "q61_very_little_group_spirit"                        => "61. There is very little group spirit in our family.",
                            "q62_money_paying_bills_openly_talked_about"          => "62. Money and paying bills is openly talked about in our family.",
                            "q63_if_disagreement_keep_the_peace"                  => "63. If there's a disagreement in our family, we try hard to smooth things over and keep the peace.",
                            "q64_strongly_encourage_to_stand_up_for_rights"       => "64. Family members strongly encourage each other to stand up for their rights.",
                            "q65_dont_try_that_hard_to_succeed"                   => "65. In our family, we don't try that hard to succeed.",
                            "q66_often_go_to_library"                             => "66. Family members often go to the library.",
                            "q67_courses_lessons_for_hobby_or_interest"           => "67. Family members sometimes attend courses or take lessons for some hobby or interest (outside of school).",
                            "q68_different_ideas_about_right_and_wrong"           => "68. In our family, each person has different ideas about what is right and wrong.",
                            "q69_each_persons_duties_clearly_defined"             => "69. Each person's duties are clearly defined in our family.",
                            "q70_can_do_whatever_we_want_to"                      => "70. We can do whatever we want to in our family.",
                            "q71_really_get_along_with_each_other"                => "71. We really get along well with each other.",
                            "q72_usually_careful_about_what_we_say"               => "72. We are usually careful about what we say to each other.",
                            "q73_often_try_to_one_up_or_out_do"                   => "73. Family members often try to one-up or out-do each other.",
                            "q74_hard_to_be_by_yourself_without_hurting_feelings" => "74. It's hard to be by yourself without hurting someone's feelings in our household.",
                            "q75_work_before_play_is_the_rule"                    => "75. \"Work before play\" is the rule in our family.",
                            "q76_watching_tv_more_important_than_reading"         => "76. Watching TV is more important than reading in our family.",
                            "q77_family_members_go_out_a_lot"                     => "77. Family members go out a lot.",
                            "q78_the_bible_is_very_important"                     => "78. The Bible is a very important book in our home.",
                            "q79_money_not_handled_carefully"                     => "79. Money is not handled very carefully in our family.",
                            "q80_rules_are_inflexible_in_household"               => "80. Rules are pretty inflexible in our household.",
                            "q81_plenty_of_time_and_attention_for_everyone"       => "81. There is plenty of time and attention for everyone in our family.",
                            "q82_a_lot_of_spontaneous_discussions"                => "82. There are a lot of spontaneous discussions in our family.",
                            "q83_believe_dont_get_anywhere_raising_voice"         => "83. In our family, we believe you don't ever get anywhere by raising your voice.",
                            "q84_not_encouraged_to_speak_up_for_ourselves"        => "84. We are not really encouraged to speak up for ourselves in our family.",
                            "q85_family_often_compared_with_others"               => "85. Family members are often compared with others as to how well they are doing at work or school.",
                            "q86_really_like_music_art_literature"                => "86. Family members really like music, art and literature.",
                            "q87_main_form_entertainment_is_tv_or_radio"          => "87. Our main form of entertainment is watching TV or listening to the radio.",
                            "q88_believe_if_you_sin_you_will_be_punished"         => "88. Family members believe that if you sin you will be punished.",
                            "q89_dishes_are_usually_done_immediately"             => "89. Dishes are usually done immediately after eating.",
                            "q90_cant_get_away_with_much"                         => "90. You can't get away with much in our family.",
                           );

        foreach ($page3_questions as $key => $question) {
            $this->addSelect($key, $question, $options);
        }
    }
}
?>
