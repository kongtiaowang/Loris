<?php
/**
 * This file contains the NDB_BVL_Instrument_SEQ3 class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the SEQ3 instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_SEQ3 extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityRequired = false;

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
        $this->formType ="XIN";
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "SEQ3";           // test_names.Test_name
        $this->table    = 'SEQ3';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields =array(
                                "Date_taken",
                                "child_birth_date",
                               );

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->selectMultipleElements = array();

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
        if (preg_match("/SEQ3(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        //Defines the call back function for HTML Quickform to use when validating the form.
        //$this->form->addFormRule(array(&$this, 'XINValidate'));
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
        $this->addHeader("Sensory Experiences Questionnaire Version 3.0");
        $this->form->addElement('static', null, "<i><h3>*Please fill this form out with regard to your child who has enrolled in our study, NOT their older sibling with autism</i></h3>");

        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);


        //SCORE HEADER 1 START
        $this->form->addElement('header', null, "SEQ Sensory Response Pattern Scores (4 Factor Model including HYPER, HYPO, SIRS, EP):");


        //scoring column headers
        $group[] = $this->form->createElement('static', "total_score", null, null);
        $this->form->addGroup($group, 'score_header_group', "<strong>Scale</strong>", $this->_GUIDelimiter, FALSE);
        unset($group);

        $domains = array("HYPER" => "Hyperresponsiveness", "HYPO" => "Hyporesponsiveness",
            "SIRS" => "SIRS (Sensory Interests, Repetitions, and Seeking
Behavior)", "EP" => "Enhanced Perception",
        );


        $columnHeaders = array("total_score" => "Total Score");

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
        //SCORE HEADER 1 FINISH
        //SCORE HEADER 2 START
        $this->form->addElement('header', null, "SEQ Context Scores (Social/Nonsocial) ");


        //scoring column headers
        $group[] = $this->form->createElement('static', "total_score", null, null);
        $this->form->addGroup($group, 'score_header_group_1', "<strong>Scale</strong>", $this->_GUIDelimiter, FALSE);
        unset($group);
        $domains = array("SOCIAL_SENSORY" => "SOCIAL sensory responsiveness",
            "NONSOCIAL_SENSORY" => "NONSOCIAL sensory responsiveness"
        );
        $columnHeaders = array("total_score" => "Total Score");

        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "   ";
        }
        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        foreach ($domains as $field => $label) {
            foreach ($columnHeaders as $scoreField => $scoreLabel) {

                $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
            }
            $this->form->addGroup($group, "{$label}_score_group_1", $label, $this->_GUIDelimiter, FALSE);
            unset($group);


        }
        //SCORE HEADER 2 FINISH
        //SCORE HEADER 3 START
        $this->form->addElement('header', null, "SEQ Sensory Modality Scores:");


        //scoring column headers
        $group[] = $this->form->createElement('static', "total_score", null, null);
        $this->form->addGroup($group, 'score_header_group_2', "<strong>Scale</strong>", $this->_GUIDelimiter, FALSE);
        unset($group);
        $domains = array("Auditory" => "Auditory",
            "Visual" => "Visual", "Tactile" => "Tactile",
            "Gustatory_or_Oflactory" => "Gustatory/Olfactory",
            "Vestibular" => "Vestibular/Proprioception"
        );
        $columnHeaders = array("total_score" => "Total Score");

        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "   ";
        }
        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        foreach ($domains as $field => $label) {
            foreach ($columnHeaders as $scoreField => $scoreLabel) {

                $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
            }
            $this->form->addGroup($group, "{$label}_score_group_2", $label, $this->_GUIDelimiter, FALSE);
            unset($group);


        }
        //SCORE HEADER 3 FINISH
    }


    /**
    * Generates the first page of the form.
    *
    *@return void
    */
    function _page1()
    {
        $this->addHeader("SEQ-3.0 (Sensory Experiences Questionnaire Version 3.0)");

        /* $this->form->addElement("static", null, "<br/>");*/

        $this->addBasicDate('child_birth_date', 'Child\'s Date of Birth:');

        $options = array(
                    null      => "",
                    "mother"  => "Mother",
                    "father"  => "Father",
                     "step_mother"  => "Step Mother",
                     "step_father"  => "Step Father",
                     "both"    => "Both Parents",
                     "teacher" => "Teacher",
                    "other"   => "Other (Describe:)",
                   );

        $this->addSelect("person_completing_form", "Person completing form:", $options);

        $this->addBasicText("if_other_person", "$this->indent If other, please specify:");

        $this->XINRegisterRule(
            "if_other_person",
            array("person_completing_form{@}=={@}other"),
            "Required."
        );
       // $this->form->addFormRule(array(&$this, 'SEQ3_special_rules'));
    }

    /**
    * Generates the second page of the form.
    *
    *@return void
    */
    function _page2()
    {
        $this->addHeader("SEQ-3.0 (Sensory Experiences Questionnaire Version 3.0)<br>
                         <h4>The following are questions about how your child uses his/her senses (such as hearing, vision, touch, etc.)
                         to experience the world. Using the following response options (<i>never/almostnever, once in a while, sometimes, 
                         frequently, almost always/always</i>), select the option that best fits the frequency of your child's experiences. Please answer all questions.<br>
                         </h4><h3>I. The following questions relate to your child's experiences with sound.<br><br>
                         How often does your child...</h3>");
	    
        $options = array(
                    null              => "",
                    "never"           => "Never/Almost Never",
                    "once_in_a_while" => "Once in a while",
                    "sometimes"       => "Sometimes",
                    "frequently"      => "Frequently",
                    "always"          => "Almost Always/Always",
                   );

        $this->addSelect("1_react_sensitively_to_sounds", "1. ... react sensitively (startle easily or cover ears) to unexpected or loud sounds (such as a vacuum cleaner, door closing, or siren)?", $options);

        $this->addSelect("2_make_nosie_to_avoid_other_sounds", "2. ... hum or make noises to tune out or avoid other sounds?", $options);

        $this->addSelect("3_notice_sounds_in_environment_before_others", "3. ... notice sounds in the environment (such as planes, trains, or thunder in the distance) before other people do?", $options);

        $this->addSelect("4_ignore_loud_noises", "4. ... ignore or tune-out loud noises? (For example: Doesn't react when alarms go off or objects fall to the floor.)", $options);

        $this->addSelect("5_make_accurate_impersonations", "5. ... make accurate impersonations of voices? (For example: Copies foreign accents, mimics sports entertainment announcer.)", $options);

        $this->addSelect("6_demonstrates_perfect_pitch", "6. ... demonstrate perfect musical pitch? (For example: Plays or hums tunes by ear without making mistakes.)", $options);

        $this->addSelect("7_fascinated_with_sounds", "7. ... seem fascinated with sounds?", $options);

        $this->addSelect("8_ignore_you_when_you_call_name", "8. ... ignore you when you call his/her name?", $options);

        $this->addSelect("9_bothered_by_everyday_sounds", "9. ... seem bothered by everyday sounds (such as a dishwasher, car radio, mixer/blender) that are not bothersome to others?", $options);

        $this->addSelect("10_show_distress", "10. ... show distress (startle easily or cover ears) during loud conversations or singing?", $options);

        $this->addSelect("11_fascinated_excited_by_others_singing", "11. ... seem fascinated with or excited by the sound of other people singing?", $options);

        $this->addSelect("12_ability_to_copy_environmental_sounds", "12. ... have the exceptional ability to copy environmental sounds? (For example: Mimics sound of musical toys, fax machine, chimes on clock, mechanical sounds)", $options);

        $this->addSelect("13_enjoy_listening_to_music", "13. ... enjoy listening to music?", $options);

        $this->addSelect("14_trouble_distinguishing_between_sounds", "14. ... have trouble distinguishing between different types of sounds?", $options);

    }

    /**
    * Generates the third page of the form.
    *
    *@return void
    */
    function _page3()
    {
        $this->addHeader("SEQ-3.0 (Sensory Experiences Questionnaire Version 3.0)
                         <h3>II. The following questions relate to your child's experiences with vision.<br><br>
                              How often does your child...</h3>");

        $options = array(
                    null              => "",
                    "never"           => "Never/Almost Never",
                    "once_in_a_while" => "Once in a while",
                    "sometimes"       => "Sometimes",
                    "frequently"      => "Frequently",
                    "always"          => "Almost Always/Always",
                   );

        $this->addSelect("15_disturbed_by_bright_lights", "15. ... appear to be disturbed by bright lights or sunlight?", $options);

        $this->addSelect("16_fascinated_by_own_reflection_in_persons_eyes", "16. ... seem fascinated by his/her own reflection in another person's eyes?", $options);

        $this->addSelect("17_stare_at_lights_or_moving_objects", "17. ... stare at lights or objects that spin or move?", $options);

        $this->addSelect("18_avoid_face_or_gaze_during_social_games", "18. ... avoid looking at your face or avert his/her gaze during social games/play?", $options);

        $this->addSelect("19_fascinated_by_visual_effect_of_water", "19. ... seem fascinated with or excited by the visual effect of water falling, swirling, or pouring?", $options);

        $this->addSelect("20_notice_minor_changes_in_physical_environment", "20. ... notice minor changes in the way the physical environment looks (such as rearranged furniture or objects displaced)?", $options);

        $this->addSelect("21_fascinated_with_lights", "21. ... seem fascinated with lights?", $options);

        $this->addSelect("22_slow_to_notice_new_objects_or_toys", "22. ... seem slow to notice new objects or toys in the room?", $options);

        $this->addSelect("23_slow_to_look_at_objects_near_them", "23. ... seem slow to look at objects that are placed or held near him/her", $options);

        $this->addSelect("24_notice_changes_in_visual_appearance_of_others", "24. ... notice minor changes in the visual appearances of other people (such as glasses/no glasses, hat/no hat, haircut)?", $options);

        $this->addSelect("25_look_at_objects_using_side_vision", "25. ... look at objects using side vision, out of the corner of his/her eyes?", $options);

        $this->addSelect("26_enjoy_children_videos_or_tv_programs", "26. ... enjoy watching children's videos or TV programs?", $options);

        $this->addSelect("27_watch_objects_they_move_rapidly", "27. ... watch objects that he/she moves rapidly in front of his/her eyes?", $options);

        $this->addSelect("28_fascinated_by_reflection_in_shiny_surfaces", "28. ... seem fascinated with or excited by his/her reflection in shiny surfaces (such as mirrors or sunglasses)?", $options);

        $this->addSelect("29_look_at_angles_or_corners_of_objects", "29. ... look at angles or corners of objects (such as a table leg)?", $options);

        $this->addSelect("30_fascinated_by_flickering_or_scrolling_motions", "30. ... seem fascinated with or excited by flickering or scrolling motions on a computer screen or TV?", $options);

        $this->addSelect("31_ignore_not_notice_someone_new_or_different", "31. ... seem to ignore or not notice someone new or different entering the room?", $options);

        $this->addSelect("32_watch_hands_or_fingers_move_or_flicker", "32. ... watch his/her hands or fingers move or flicker in front of the eyes?", $options);

        $this->addSelect("33_visually_distracted_by_little_things_moving", "33. ... seem visually distracted by every little thing moving around him/her?", $options);

        $this->addSelect("34_trouble_distinguishing_visual_sensations", "34. ... have trouble distinguishing between different types of visual sensations?", $options);

        $this->addSelect("35_enjoy_looking_at_picture_books", "35. ... enjoy looking at picture books?", $options);
    }

    /**
    * Generates the fourth page of the form.
    *
    *@return void
    */
    function _page4()
    {

        $this->addHeader("SEQ-3.0 (Sensory Experiences Questionnaire Version 3.0)<br>
                                <h3>III. The following questions relate to your child's experiences with touch.<br><br>
                                How often does your child...</h3>");
        $options = array(
                    null              => "",
                    "never"           => "Never/Almost Never",
                    "once_in_a_while" => "Once in a while",
                    "sometimes"       => "Sometimes",
                    "frequently"      => "Frequently",
                    "always"          => "Almost Always/Always",
                   );
        $NA_options = array(
            null              => "",
            "never"           => "Never/Almost Never",
            "once_in_a_while" => "Once in a while",
            "sometimes"       => "Sometimes",
            "frequently"      => "Frequently",
            "always"          => "Almost Always/Always",
            "NA"              => "Not Answered"
        );

        $this->addSelect("36_dislike_cuddling_or_being_held", "36. ... dislike cuddling or being held?", $options);

        $this->addSelect("37_crave_intense_firm_touch", "37. ... crave intense or firm touch? (For example: Can't get enough of back scratches, firm hugs, or squeezes.)", $options);

        $this->addSelect("38_avoid_touching_certain_textures", "38. ... avoid touching certain textures (such as fuzzy or squishy toys) or playing with messy materials (such as sand or lotion)?", $options);

        $this->addSelect("39_like_feeling_of_air_blowing", "39. ... like the feeling of air blowing from fans or wind on his/her face?", $options);

        $this->addSelect("40_trouble_adjusting_to_water_temperature", "40. ... have trouble adjusting to the water temperature during bath time?", $options);

        $this->addSelect("41_crave_being_tickled", "41. ... crave being tickled?", $options);

        $this->addSelect("42_dislike_being_in_water", "42. ... dislike being in water?", $options);

        $this->addSelect("43_ignore_or_not_notice_when_tap_shoulder", "43. ... ignore you or not notice when you tap him/her on the shoulder for attention?", $options);

        $this->addSelect("44_sensitive_to_bothered_by_sticky_material", "44. ... seem sensitive to or bothered by sticky materials (such as tape, stickers, or band-aids)?", $options);

        $this->addSelect("45_fascinated_with_touch", "45. ... seem fascinated with touch?", $options);

        $this->addSelect("46_bothered_by_tags_or_seams", "46. ... seem bothered by tags or seams on clothing?", $NA_options);

        $this->addSelect("47_bothered_by_tight_clothing", "47. ... seem bothered by tight clothing (such as turtlenecks, elastic, sleeves, or stocking caps)?", $options);

        $this->addSelect("48_easily_find_objects_by_feel", "48. ... easily find objects (such as coins or candy) in a bag by feel (without looking)?", $options);

        $this->addSelect("49_show_distress_during_grooming", "49. ... show distress during grooming? (For example: Cries or fusses during face washing, hair combing, fingernail cutting, teeth brushing.)", $options);

        $this->addSelect("50_touch_or_rub_certain_surfaces_or_materials", "50. ... touch or rub certain surfaces or materials (such as grooves, ridges, or very smooth surfaces)?", $options);

        $this->addSelect("51_react_negatively_pull_away_when_touched", "51. ... react negatively or pull away when touched by a person? (For example: Pulls away when head is patted.)", $options);

        $this->addSelect("52_dislike_being_tickled", "52. ... dislike being tickled?", $options);

        $this->addSelect("53_slow_to_react_to_pain", "53. ... seem slow to react to pain? (For example: Isn't bothered by bumps, scrapes, cuts, or falls.)", $options);

        $this->addSelect("54_react_negatively_to_haircuts", "54. ... react negatively to haircuts?", $options);

        $this->addSelect("55_fascinated_with_textures_or_surfaces", "55. ... seem fascinated with textures or surfaces, objects or clothing fabric?", $options);

        $this->addSelect("56_unaware_of_extreme_temperatures", "56. ... seem unaware of extreme temperatures? (For example: Doesn't react to hot water or tolerates very cold weather without a coat.)", $options);

        $this->addSelect("57_rub_wet_substances_on_smooth_surface", "57. ... rub wet substances (such as water, lotion, liquid soap, or pudding) on a table top or other smooth surface?", $options);

        $this->addSelect("58_trouble_distinguishing_between_different_touch_sensations", "58. ... have trouble distinguishing between different types of touch sensations", $options);
    }

    /**
    * Generates the fifth page of the form.
    *
    *@return void
    */
    function _page5()
    {
        $this->addHeader("SEQ-3.0 (Sensory Experiences Questionnaire Version 3.0)<br>
                          <h3>IV. The following questions relate to your child's experiences with taste/smell.<br><br>
                          How often does your child...</h3>");
	    
        $options = array(
                    null              => "",
                    "never"           => "Never/Almost Never",
                    "once_in_a_while" => "Once in a while",
                    "sometimes"       => "Sometimes",
                    "frequently"      => "Frequently",
                    "always"          => "Almost Always/Always",
                   );
        $NA_options = array(
            null              => "",
            "never"           => "Never/Almost Never",
            "once_in_a_while" => "Once in a while",
            "sometimes"       => "Sometimes",
            "frequently"      => "Frequently",
            "always"          => "Almost Always/Always",
            "NA"              => "Not Answered"
        );

        $this->addSelect("59_refuse_new_foods_or_avoids_certain_foods", "59. ... refuse to try new foods or avoid certain tastes, smells, or textures of food?", $options);

        $this->addSelect("60_smell_objects_or_toys_during_play", "60. ... smell objects or toys during play or other activities?", $options);

        $this->addSelect("61_sensitive_to_or_bothered_by_people_smell", "61. ... seem sensitive to or bothered by the way people smell?", $options);

        $this->addSelect("62_put_objects_toys_non_food_items_in_mouth", "62. ... put objects, toys, or other non-food items in his/her mouth to suck or chew?", $options);

        $this->addSelect("63_picky_eater", "63. ... seem to be a \"picky\" eater?", $options);

        $this->addSelect("64_crave_foods_with_strong_taste", "64. ... crave foods with a strong taste or flavor (such as spicy, sour, or bitter foods)?", $options);

        $this->addSelect("65_fascinated_with_particular_taste", "65. ... seem fascinated with particular tastes?", $options);

        $this->addSelect("66_notice_smells_before_other_people", "66. ... notice smells before other people do (such as perfume, smoke, or food)?", $options);

        $this->addSelect("67_fascinated_with_particular_smells", "67. ... seem fascinated with particular smells?", $options);

        $this->addSelect("68_mouth_suck_chew_hands_or_fingers", "68. ... mouth, suck, or chew his/her hands or fingers?", $options);

        $this->addSelect("69_unaware_of_strong_unpleasant_smells_others_notice", "69. ... seem to be unaware of strong or unpleasant smells that most other people notice (such as rotting food, ammonia, or perfume)?", $options);

        $this->addSelect("70_taste_difference_between_different_brands_same_food", "70. ... taste the difference between different brands of the same food or subtle recipe changes?", $options);

        $this->addSelect("71_lick_non_food_objects", "71. ... lick non-food objects?", $options);

        $this->addSelect("72_refuse_food_they_like_if_mixed_with_another", "72. ... refuse to eat food that he/she usually likes if it is mixed with another food?", $options);

        $this->addSelect("73_gag_in_response_to_certain_smells", "73. ... gag in response to certain smells?", $options);

        $this->addSelect("74_trouble_distinguishing_different_tastes_or_flavors", "74. ... have trouble distinguishing between different types of tastes or flavors?", $NA_options);
    }

    /**
    * Generates the sixth page of the form.
    *
    *@return void
    */
    function _page6()
    {
        $this->addHeader("SEQ-3.0 (Sensory Experiences Questionnaire Version 3.0)<br>
                         <h3>V. The following questions relate to your child's experiences with movement.<br><br>
                         How often does your child...</h3>");
	    
        $options = array(
                    null              => "",
                    "never"           => "Never/Almost Never",
                    "once_in_a_while" => "Once in a while",
                    "sometimes"       => "Sometimes",
                    "frequently"      => "Frequently",
                    "always"          => "Almost Always/Always",
                   );


        $this->addSelect("75_enjoy_long_car_rides", "75. ... enjoy long car rides?", $options);

        $this->addSelect("76_jump_rock_spin", "76. ... jump up/down, rock back/forth, or spin in circles?", $options);

        $this->addSelect("77_uneasy_or_dizzy_from_swing_merry_go_round_rocker", "77. ... seem uneasy or become dizzy from the movement of a swing, merry-go-round, or rocker?", $options);

        $this->addSelect("78_seek_physical_rough_housing_play", "78. ... seek out physical rough-housing play? (For example: Craves wrestling, being tossed in the air, or spun around.)", $options);

        $this->addSelect("79_enjoy_being_upside_down", "79. ... enjoy being upside-down?", $options);

        $this->addSelect("80_flaps_arms_or_hands_when_excited", "80. ... flap his/her arms or hands, particularly when excited?", $options);

        $this->addSelect("81_avoid_escalators_elevators_or_other", "81. ... avoid riding on escalators, elevators, or other moving surfaces?", $options);

        $this->addSelect("82_unaware_of_moving_unstable_surfaces", "82. ... seems unaware of moving or unstable surfaces?", $options);

        $this->addSelect("83_react_negatively_moved_quickly_tipped_backwards_spun_around", "83. ... react negatively to being moved quickly, tipped backwards, or spun around by a familiar adult?", $options);

        $this->addSelect("84_spin_self_around_without_becoming_dizzy", "84. ... spin self around without becoming dizzy?", $options);

        $this->addSelect("85_unusual_postures_with_hands_fingers_arms", "85. ... assume unusual postures with his/her hands, fingers, or arms?", $options);

        $this->addSelect("86_trouble_distinguishing_movement_sensations", "86. ... have trouble distinguishing between different types of movement sensations?", $options);
    }

    /**
    * Generates the seventh page of the form.
    *
    *@return void
    */
    function _page7()
    {
        $this->addHeader("SEQ-3.0 (Sensory Experiences Questionnaire Version 3.0)<br>
                         <h3>VI. Up to this point in the questionnaire, you've been answering questions about one sense
                         at a time (sight, touch, etc.). The questions in the following section deal with situations that
                         involve more than one sensory experience at the same time.<br><br>
                         How often does your child...</h3>");

        $options = array(
                    null              => "",
                    "never"           => "Never/Almost Never",
                    "once_in_a_while" => "Once in a while",
                    "sometimes"       => "Sometimes",
                    "frequently"      => "Frequently",
                    "always"          => "Almost Always/Always",
                   );

        $NA_options = array(
            null              => "",
            "never"           => "Never/Almost Never",
            "once_in_a_while" => "Once in a while",
            "sometimes"       => "Sometimes",
            "frequently"      => "Frequently",
            "always"          => "Almost Always/Always",
            "NA"              => "Not Answered"
        );

        $this->form->addElement("static", null, "<br/>");

        $this->addSelect("87_trouble_looking_and_listening_same_time", "87. ... seem to have trouble looking and listening at the same time? (For example: Shuts eyes to listen more closely or blocks out sound to focus on visual task.)", $options);

        $this->addSelect("88_report_certain_letters_or_numbers_particular_color", "88. ... report that certain letters or numbers are always seen in a particular color?", $options);

        $this->addSelect("89_overwhelmed_in_places_a_lot_of_activity", "89. ... get overwhelmed in places where there is a lot of activity going on (such as a sports stadium, shopping mall, fast food restaurant, or amusement park)?", $options);

        $this->addSelect("90_event_in_sense_causes_feeling_in_different_sense", "90. ... report that an event in one sense causes a feeling in a different sense? (For example: Musical notes have colors, or flavors have shapes.)", $options);

        $this->addSelect("91_confuse_which_sense_something_is_from", "91. ... seem to confuse which sense something is coming from? (For example: Turns up the volume if something is blocking the view of the TV.)", $NA_options);

        $this->addSelect("92_more_sensitive_to_social_touch", "92. ... seem more sensitive to social touch (such as a pat on the back, touch on the arm, or hug) in a noisy environment than in a quiet one?", $options);

        $this->addSelect("93_like_to_dance_to_particular_music", "93. ... like to dance to particular music? (For example: Asks for song or music, then dances with it.)", $options);

        $this->addSelect("94_increase_background_noise_to_improve_attention_to_activity", "94. ... try to increase background noise to improve his/her attention to another activity? (For example: Turns up volume on radio while doing homework or puzzles.)", $options);

        $this->addSelect("95_avoid_toys_make_noise_and_light_up_same_time", "95. ... avoid playing with toys or novel objects that make a lot of noise and light up at the same time?", $options);

        $this->addSelect("96_trouble_focusing_other_sounds_happening", "96. ... have trouble focusing on a conversation or social activity when other sounds are happening in the room at the same time?", $options);

        $this->addSelect("97_shut_down_when_too_much_stimulation", "97. ... seem to \"shut-down\" when there is too much stimulation?", $options);

    }

    /**
    * Generates the eighth page of the form.
    *
    *@return void
    */
    function _page8()
    {
        $this->addHeader("SEQ-3.0 (Sensory Experiences Questionnaire Version 3.0)<br>
                         <h3>VII. Additional questions. Please check one and comment below where applicable.</h3>");

        $options = array(
                    null              => "",
                    "never"           => "Never/Almost Never",
                    "once_in_a_while" => "Once in a while",
                    "sometimes"       => "Sometimes",
                    "frequently"      => "Frequently",
                    "always"          => "Almost Always/Always",
                   );
        $options_q100 = array(
            null              => "",
            "much_less_avoidant"           => "Much Less Avoidant/Sensitive",
            "somewhat_less_avoidant" => "Somewhat Less Avoidant/Sensitive",
            "unchanged"       => "Unchanged",
            "somewhat_more_avoidant"      => "Somewhat More Avoidant/Sensitive",
            "much_more_avoidant"          => "Much More Avoidant/Sensitive",
        );
        $options_q103 = array(
            null              => "",
            "much_less_intense"           => "Much Less Intense",
            "somewhat_less_avoidant" => "Somewhat Less Intense",
            "unchanged"       => "Unchanged",
            "somewhat_more_intense"      => "Somewhat More Intense",
            "much_more_intense"          => "Much More Intense",
        );
        $sub_note="<br><h5><i>(If your response to the above question is 'Never', please enter NA)</i></h5>";

        $this->addSelect("98_how_often_experienced_sensations_differently", "98. Thinking about your child's behaviors since birth, how often has your child experienced sensations (sound, sight, touch, taste, smell, or movement) differently from other children?", $options);

        $this->addBasicTextArea("98_describe_if_applicable", "$this->indent Describe (if applicable):$sub_note");


	$this->form->addElement("static", null, "<br/>");

        $applicable_opts = array(
                            null             => "",
                            "applicable"     => "Applicable",
                            "not_applicable" => "Not Applicable",
                           );

        $this->addSelect("99_first_noticed_differences_in_sensory_exp", "99. How old was your child when you first noticed any differences in your child's sensory experiences?", $applicable_opts);

        $this->addBasicText("99_years", "Years:<br><h5><i>(Please enter a numeric value between 0-100 or if you really don't wish to answer; enter NA)</i></h5>");

        $this->addBasicText("99_months", "Months:<br><h5><i>(Please enter a numeric value between 0-100 or if you really don't wish to answer; enter NA)</i></h5>");

        $this->XINRegisterRule(
            "99_years",
            array("99_first_noticed_differences_in_sensory_exp{@}=={@}applicable"),
            "Required."
        );

        $this->XINRegisterRule(
            "99_months",
            array("99_first_noticed_differences_in_sensory_exp{@}=={@}applicable"),
            "Required."
        );

	$this->form->addElement("static", null, "<br/>");

        $this->addLabel("<h3><u>Avoidances/Sensitivities</u></h3>");

        $this->addSelect("100_how_childs_sensory_avoidances_changed_1", "100. How have your child's sensory <b>avoidances or sensitivities</b> changed over time?", $options_q100);

        $this->addBasicTextArea("100_describe_if_changed", "$this->indent Describe (if changed):$sub_note");


	$this->form->addElement("static", null, "<br/>");

        $this->addSelect("101_how_often_childs_sensory_avoidances_interfere_daily", "101. How often do your child's sensory <b>avoidances or sensitivities</b> interfere with daily activities?", $options);

        $this->addBasicTextArea("101_describe_if_applicable", "$this->indent Describe (if applicable):$sub_note");


	$this->form->addElement("static", null, "<br/>");

        $this->addBasicTextArea("102_list_comments_avoidances_to_senses", "102. List additional comments about your child's <b>avoidances or sensitivities</b> to sound, sight, touch, smell, taste, or movement (if applicable).");

        $this->XINRegisterRule(
            "102_list_comments_avoidances_to_senses",
            array("102_list_comments_avoidances_to_senses{@}=={@}NEVER_REQUIRED"),
            "Required."
        );

	$this->form->addElement("static", null, "<br/>");

        $this->addLabel("<h3><u>Fascinations/Cravings</u></h3>");

        $this->addSelect("103_how_have_sensory_fascinations_changed_1", "103. How have your child's sensory <b> fascinations or cravings </b> changed over time?", $options_q103);

        $this->addBasicTextArea("103_describe_if_changed", "$this->indent Describe (if changed):$sub_note");


	$this->form->addElement("static", null, "<br/>");

        $this->addSelect("104_how_often_sensory_fascinations_interfere_daily", "104. How often do your child's sensory <b>fascinations or cravings</b> interfere with daily activities?</b>", $options);

        $this->addBasicTextArea("104_describe_if_applicable", "$this->indent Describe (if applicable):$sub_note");

	$this->form->addElement("static", null, "<br/>");

        $this->addBasicTextArea("105_list_comments_fascinations_cravings_to_senses", "105. List additional comments about your child's <b>fascinations or cravings</b> to sound, sight, touch, smell, taste, or movement (if applicable).");

        $this->XINRegisterRule(
            "105_list_comments_fascinations_cravings_to_senses",
            array("105_list_comments_fascinations_cravings_to_senses{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );
       // $this->form->addFormRule(array(&$this, 'SEQ3_special_rules'));
    }
function SEQ3_special_rules($values)
{
    $errors = array();
    $error_message =  "This field should be left blank OR the response in the above question should be changed";
        if(($values['if_other_person']?? '') != '') {
            if(($values['person_completing_form']?? '' )!="other") {
                $errors['if_other_person'] = $error_message;
            }
        }
$check_array = array("99_years", "99_months");
foreach ($check_array as $val) {
    if (($values[$val] ?? '') != '') {
        if (($values['99_first_noticed_differences_in_sensory_exp']?? '' )!= "applicable") {

                    $errors[$val] = $error_message;
            }
       }
}

                $this->ageValidator($values,'99_years',$errors);
                $this->ageValidator($values,'99_months',$errors);

    return $errors;
}
function ageValidator($array,$string, &$errors)
{
    if (isset($array[$string])) {
        if (is_numeric($array[$string])) {
            if (intval($array[$string]) > 100 || intval($array[$string]) < 0) {

                $errors[$string] = "Specify age between 0 to 100 or NA";
            }
        } else {
            if(strcasecmp($array[$string],"NA"))
            {
                $errors[$string] = "Specify age between 0 to 100 or NA";
            }
        }

    }
}


function score(): void
{

    //get the saved scores
    $db =& Database::singleton();
    $query = "SELECT * FROM $this->table WHERE CommentID = '$this->commentID'";
    $record = $db->pselectRow($query, array());

    $score_grid=array('never'=>1,'once_in_a_while'=>2,'
    sometimes'=>3,'frequently'=>4,'always'=>5);

    $Hyper_array=array(
        $score_grid[$record['1_react_sensitively_to_sounds']],
        $score_grid[$record['2_make_nosie_to_avoid_other_sounds']],
        $score_grid[$record['9_bothered_by_everyday_sounds']],
        $score_grid[$record['10_show_distress']],
        $score_grid[$record['15_disturbed_by_bright_lights']],
        $score_grid[$record['18_avoid_face_or_gaze_during_social_games']],
        $score_grid[$record['36_dislike_cuddling_or_being_held']],
        $score_grid[$record['38_avoid_touching_certain_textures']],
        $score_grid[$record['40_trouble_adjusting_to_water_temperature']],
        $score_grid[$record['42_dislike_being_in_water']],
        $score_grid[$record['44_sensitive_to_bothered_by_sticky_material']],
        $score_grid[$record['46_bothered_by_tags_or_seams']],
        $score_grid[$record['47_bothered_by_tight_clothing']],
        $score_grid[$record['49_show_distress_during_grooming`']],
        $score_grid[$record['51_react_negatively_pull_away_when_touched`']],
        $score_grid[$record['52_dislike_being_tickled']],
        $score_grid[$record['54_react_negatively_to_haircuts']],
        $score_grid[$record['59_refuse_new_foods_or_avoids_certain_foods']],
        $score_grid[$record['61_sensitive_to_or_bothered_by_people_smell']],
        $score_grid[$record['63_picky_eater']],
        $score_grid[$record['72_refuse_food_they_like_if_mixed_with_another']],
        $score_grid[$record['73_gag_in_response_to_certain_smells']],
        $score_grid[$record['77_uneasy_or_dizzy_from_swing_merry_go_round_rocker']],
        $score_grid[$record['81_avoid_escalators_elevators_or_other']],
        $score_grid[$record['83_react_negatively_moved_quickly_tipped_backwards_spun_around']],
        $score_grid[$record['87_trouble_looking_and_listening_same_time']],
        $score_grid[$record['89_overwhelmed_in_places_a_lot_of_activity']],
        $score_grid[$record['92_more_sensitive_to_social_touch']],
        $score_grid[$record['95_avoid_toys_make_noise_and_light_up_same_time']],
        $score_grid[$record['96_trouble_focusing_other_sounds_happening']],
        $score_grid[$record['97_shut_down_when_too_much_stimulation']],
    );
$Hypo_array=array(
    $score_grid[$record['4_ignore_loud_noises']],
    $score_grid[$record['8_ignore_you_when_you_call_name']],
    $score_grid[$record['14_trouble_distinguishing_between_sounds']],
    $score_grid[$record['22_slow_to_notice_new_objects_or_toys']],
    $score_grid[$record['23_slow_to_look_at_objects_near_them']],
    $score_grid[$record['31_ignore_not_notice_someone_new_or_different']],
    $score_grid[$record['34_trouble_distinguishing_visual_sensations']],
    $score_grid[$record['43_ignore_or_not_notice_when_tap_shoulder']],
    $score_grid[$record['53_slow_to_react_to_pain']],
    $score_grid[$record['56_unaware_of_extreme_temperatures']],
    $score_grid[$record['58_trouble_distinguishing_between_different_touch_sensations']],
    $score_grid[$record['69_unaware_of_strong_unpleasant_smells_others_notice']],
    $score_grid[$record['74_trouble_distinguishing_different_tastes_or_flavors']],
    $score_grid[$record['82_unaware_of_moving_unstable_surfaces']],
    $score_grid[$record['84_spin_self_around_without_becoming_dizzy']],
    $score_grid[$record['86_trouble_distinguishing_movement_sensations']],
    $score_grid[$record['91_confuse_which_sense_something_is_from']],
    $score_grid[$record['94_increase_background_noise_to_improve_attention_to_activity']],

);

$Sirs_array=
    array(
        $score_grid[$record['7_fascinated_with_sounds']],
        $score_grid[$record['11_fascinated_excited_by_others_singing']],
        $score_grid[$record['16_fascinated_by_own_reflection_in_persons_eyes']],
        $score_grid[$record['17_stare_at_lights_or_moving_objects']],
        $score_grid[$record['19_fascinated_by_visual_effect_of_water']],
        $score_grid[$record['21_fascinated_with_lights']],
        $score_grid[$record['25_look_at_objects_using_side_vision']],
        $score_grid[$record['27_watch_objects_they_move_rapidly']],
        $score_grid[$record['28_fascinated_by_reflection_in_shiny_surfaces']],
        $score_grid[$record['29_look_at_angles_or_corners_of_objects']],
        $score_grid[$record['30_fascinated_by_flickering_or_scrolling_motions']],
        $score_grid[$record['32_watch_hands_or_fingers_move_or_flicker']],
        $score_grid[$record['37_crave_intense_firm_touch']],
        $score_grid[$record['39_like_feeling_of_air_blowing']],
        $score_grid[$record['41_crave_being_tickled']],
        $score_grid[$record['45_fascinated_with_touch']],
        $score_grid[$record['50_touch_or_rub_certain_surfaces_or_materials']],
        $score_grid[$record['55_fascinated_with_textures_or_surfaces']],
        $score_grid[$record['57_rub_wet_substances_on_smooth_surface']],
        $score_grid[$record['60_smell_objects_or_toys_during_play']],
        $score_grid[$record['62_put_objects_toys_non_food_items_in_mouth']],
        $score_grid[$record['64_crave_foods_with_strong_taste']],
        $score_grid[$record['65_fascinated_with_particular_taste']],
        $score_grid[$record['67_fascinated_with_particular_smells']],
        $score_grid[$record['68_mouth_suck_chew_hands_or_fingers']],
        $score_grid[$record['71_lick_non_food_objects']],
        $score_grid[$record['76_jump_rock_spin']],
        $score_grid[$record['78_seek_physical_rough_housing_play']],
        $score_grid[$record['79_enjoy_being_upside_down']],
        $score_grid[$record['80_flaps_arms_or_hands_when_excited']],
        $score_grid[$record['85_unusual_postures_with_hands_fingers_arms']],
    );
    $Ep_array= array(
            $score_grid[$record['3_notice_sounds_in_environment_before_others']],
            $score_grid[$record['5_make_accurate_impersonations']],
            $score_grid[$record['6_demonstrates_perfect_pitch']],
            $score_grid[$record['12_ability_to_copy_environmental_sounds']],
            $score_grid[$record['20_notice_minor_changes_in_physical_environment']],
            $score_grid[$record['24_notice_changes_in_visual_appearance_of_others']],
            $score_grid[$record['33_visually_distracted_by_little_things_moving']],
            $score_grid[$record['48_easily_find_objects_by_feel']],
            $score_grid[$record['66_notice_smells_before_other_people']],
            $score_grid[$record['70_taste_difference_between_different_brands_same_food']],
            $score_grid[$record['88_report_certain_letters_or_numbers_particular_color']],
            $score_grid[$record['90_event_in_sense_causes_feeling_in_different_sense']],

        );
    $Auditory_array= array(
        $score_grid[$record['1_react_sensitively_to_sounds']],
        $score_grid[$record['2_make_nosie_to_avoid_other_sounds']],
        $score_grid[$record['3_notice_sounds_in_environment_before_others']],
        $score_grid[$record['4_ignore_loud_noises']],
        $score_grid[$record['5_make_accurate_impersonations']],
        $score_grid[$record['6_demonstrates_perfect_pitch']],
        $score_grid[$record['7_fascinated_with_sounds']],
        $score_grid[$record['8_ignore_you_when_you_call_name']],
        $score_grid[$record['9_bothered_by_everyday_sounds']],
        $score_grid[$record['10_show_distress']],
        $score_grid[$record['11_fascinated_excited_by_others_singing']],
        $score_grid[$record['12_ability_to_copy_environmental_sounds']],
        $score_grid[$record['14_trouble_distinguishing_between_sounds']],
    );
    $Visual_array= array(
        $score_grid[$record['15_disturbed_by_bright_lights']],
        $score_grid[$record['16_fascinated_by_own_reflection_in_persons_eyes']],
        $score_grid[$record['17_stare_at_lights_or_moving_objects']],
        $score_grid[$record['18_avoid_face_or_gaze_during_social_games']],
        $score_grid[$record['19_fascinated_by_visual_effect_of_water']],
        $score_grid[$record['20_notice_minor_changes_in_physical_environment']],
        $score_grid[$record['21_fascinated_with_lights']],
        $score_grid[$record['22_slow_to_notice_new_objects_or_toys']],
        $score_grid[$record['23_slow_to_look_at_objects_near_them']],
        $score_grid[$record['24_notice_changes_in_visual_appearance_of_others']],
        $score_grid[$record['25_look_at_objects_using_side_vision']],
        $score_grid[$record['27_watch_objects_they_move_rapidly']],
        $score_grid[$record['28_fascinated_by_reflection_in_shiny_surfaces']],
        $score_grid[$record['29_look_at_angles_or_corners_of_objects']],
        $score_grid[$record['30_fascinated_by_flickering_or_scrolling_motions']],
        $score_grid[$record['31_ignore_not_notice_someone_new_or_different']],
        $score_grid[$record['32_watch_hands_or_fingers_move_or_flicker']],
        $score_grid[$record['33_visually_distracted_by_little_things_moving']],
        $score_grid[$record['34_trouble_distinguishing_visual_sensations']],
    );
    $Tactile_array= array(
        $score_grid[$record['36_dislike_cuddling_or_being_held']],
        $score_grid[$record['37_crave_intense_firm_touch']],
        $score_grid[$record['38_avoid_touching_certain_textures']],
        $score_grid[$record['39_like_feeling_of_air_blowing']],
        $score_grid[$record['40_trouble_adjusting_to_water_temperature']],
        $score_grid[$record['41_crave_being_tickled']],
        $score_grid[$record['42_dislike_being_in_water']],
        $score_grid[$record['43_ignore_or_not_notice_when_tap_shoulder']],
        $score_grid[$record['44_sensitive_to_bothered_by_sticky_material']],
        $score_grid[$record['45_fascinated_with_touch']],
        $score_grid[$record['46_bothered_by_tags_or_seams']],
        $score_grid[$record['47_bothered_by_tight_clothing']],
        $score_grid[$record['48_easily_find_objects_by_feel']],
        $score_grid[$record['49_show_distress_during_grooming']],
        $score_grid[$record['50_touch_or_rub_certain_surfaces_or_materials']],
        $score_grid[$record['51_react_negatively_pull_away_when_touched']],
        $score_grid[$record['52_dislike_being_tickled']],
        $score_grid[$record['53_slow_to_react_to_pain']],
        $score_grid[$record['54_react_negatively_to_haircuts']],
        $score_grid[$record['55_fascinated_with_textures_or_surfaces']],
        $score_grid[$record['56_unaware_of_extreme_temperatures']],
        $score_grid[$record['57_rub_wet_substances_on_smooth_surface']],
        $score_grid[$record['58_trouble_distinguishing_between_different_touch_sensations']],
    );

    $Gustatory_array=array(
        $score_grid[$record['59_refuse_new_foods_or_avoids_certain_foods']],
        $score_grid[$record['60_smell_objects_or_toys_during_play']],
        $score_grid[$record['61_sensitive_to_or_bothered_by_people_smell']],
        $score_grid[$record['62_put_objects_toys_non_food_items_in_mouth']],
        $score_grid[$record['63_picky_eater']],
        $score_grid[$record['64_crave_foods_with_strong_taste']],
        $score_grid[$record['65_fascinated_with_particular_taste']],
        $score_grid[$record['66_notice_smells_before_other_people']],
        $score_grid[$record['67_fascinated_with_particular_smells']],
        $score_grid[$record['68_mouth_suck_chew_hands_or_fingers']],
        $score_grid[$record['69_unaware_of_strong_unpleasant_smells_others_notice']],
        $score_grid[$record['70_taste_difference_between_different_brands_same_food']],
        $score_grid[$record['71_lick_non_food_objects']],
        $score_grid[$record['72_refuse_food_they_like_if_mixed_with_another']],
        $score_grid[$record['73_gag_in_response_to_certain_smells']],
        $score_grid[$record['74_trouble_distinguishing_different_tastes_or_flavors']],
    );

    $Vestibular_array=array(
        $score_grid[$record['75_enjoy_long_car_rides']],
        $score_grid[$record['76_jump_rock_spin']],
        $score_grid[$record['77_uneasy_or_dizzy_from_swing_merry_go_round_rocker']],
        $score_grid[$record['78_seek_physical_rough_housing_play']],
        $score_grid[$record['79_enjoy_being_upside_down']],
        $score_grid[$record['80_flaps_arms_or_hands_when_excited']],
        $score_grid[$record['81_avoid_escalators_elevators_or_other']],
        $score_grid[$record['82_unaware_of_moving_unstable_surfaces']],
        $score_grid[$record['83_react_negatively_moved_quickly_tipped_backwards_spun_around']],
        $score_grid[$record['84_spin_self_around_without_becoming_dizzy']],
        $score_grid[$record['85_unusual_postures_with_hands_fingers_arms']],
        $score_grid[$record['86_trouble_distinguishing_movement_sensations']],

    );
    $Social_sensory_array=array(
        $score_grid[$record['5_make_accurate_impersonations']],
        $score_grid[$record['8_ignore_you_when_you_call_name']],
        $score_grid[$record['10_show_distress']],
        $score_grid[$record['11_fascinated_excited_by_others_singing']],
        $score_grid[$record['16_fascinated_by_own_reflection_in_persons_eyes']],
        $score_grid[$record['18_avoid_face_or_gaze_during_social_games']],
        $score_grid[$record['23_slow_to_look_at_objects_near_them']],
        $score_grid[$record['24_notice_changes_in_visual_appearance_of_others']],
        $score_grid[$record['31_ignore_not_notice_someone_new_or_different']],
        $score_grid[$record['36_dislike_cuddling_or_being_held']],
        $score_grid[$record['37_crave_intense_firm_touch']],
        $score_grid[$record['41_crave_being_tickled']],
        $score_grid[$record['43_ignore_or_not_notice_when_tap_shoulder']],
        $score_grid[$record['51_react_negatively_pull_away_when_touched']],
        $score_grid[$record['52_dislike_being_tickled']],
        $score_grid[$record['54_react_negatively_to_haircuts']],
        $score_grid[$record['61_sensitive_to_or_bothered_by_people_smell']],
        $score_grid[$record['78_seek_physical_rough_housing_play']],
        $score_grid[$record['83_react_negatively_moved_quickly_tipped_backwards_spun_around']],
        $score_grid[$record['92_more_sensitive_to_social_touch']],
    );

    $Nonsocial_sensory_array=array(
        $score_grid[$record['1_react_sensitively_to_sounds']],
        $score_grid[$record['2_make_nosie_to_avoid_other_sounds']],
        $score_grid[$record['3_notice_sounds_in_environment_before_others']],
        $score_grid[$record['4_ignore_loud_noises']],
        $score_grid[$record['6_demonstrates_perfect_pitch']],
        $score_grid[$record['7_fascinated_with_sounds']],
        $score_grid[$record['9_bothered_by_everyday_sounds']],
        $score_grid[$record['12_ability_to_copy_environmental_sounds']],
        $score_grid[$record['14_trouble_distinguishing_between_sounds']],
        $score_grid[$record['15_disturbed_by_bright_lights']],
        $score_grid[$record['17_stare_at_lights_or_moving_objects']],
        $score_grid[$record['19_fascinated_by_visual_effect_of_water']],
        $score_grid[$record['20_notice_minor_changes_in_physical_environment']],
        $score_grid[$record['21_fascinated_with_lights']],
        $score_grid[$record['22_slow_to_notice_new_objects_or_toys']],
        $score_grid[$record['25_look_at_objects_using_side_vision']],
        $score_grid[$record['27_watch_objects_they_move_rapidly']],
        $score_grid[$record['28_fascinated_by_reflection_in_shiny_surfaces']],
        $score_grid[$record['29_look_at_angles_or_corners_of_objects']],
        $score_grid[$record['30_fascinated_by_flickering_or_scrolling_motions']],
        $score_grid[$record['32_watch_hands_or_fingers_move_or_flicker']],
        $score_grid[$record['33_visually_distracted_by_little_things_moving']],
        $score_grid[$record['34_trouble_distinguishing_visual_sensations']],
        $score_grid[$record['38_avoid_touching_certain_textures']],
        $score_grid[$record['39_like_feeling_of_air_blowing']],
        $score_grid[$record['40_trouble_adjusting_to_water_temperature']],
        $score_grid[$record['42_dislike_being_in_water']],
        $score_grid[$record['44_sensitive_to_bothered_by_sticky_material']],
        $score_grid[$record['45_fascinated_with_touch']],
        $score_grid[$record['46_bothered_by_tags_or_seams']],
        $score_grid[$record['47_bothered_by_tight_clothing']],
        $score_grid[$record['48_easily_find_objects_by_feel']],
        $score_grid[$record['49_show_distress_during_grooming']],
        $score_grid[$record['50_touch_or_rub_certain_surfaces_or_materials']],
        $score_grid[$record['51_react_negatively_pull_away_when_touched']],
        $score_grid[$record['53_slow_to_react_to_pain']],
        $score_grid[$record['55_fascinated_with_textures_or_surfaces']],
        $score_grid[$record['56_unaware_of_extreme_temperatures']],
        $score_grid[$record['57_rub_wet_substances_on_smooth_surface']],
        $score_grid[$record['58_trouble_distinguishing_between_different_touch_sensations']],
        $score_grid[$record['59_refuse_new_foods_or_avoids_certain_foods']],
        $score_grid[$record['60_smell_objects_or_toys_during_play']],
        $score_grid[$record['62_put_objects_toys_non_food_items_in_mouth']],
        $score_grid[$record['63_picky_eater']],
        $score_grid[$record['64_crave_foods_with_strong_taste']],
        $score_grid[$record['65_fascinated_with_particular_taste']],
        $score_grid[$record['66_notice_smells_before_other_people']],
        $score_grid[$record['67_fascinated_with_particular_smells']],
        $score_grid[$record['68_mouth_suck_chew_hands_or_fingers']],
        $score_grid[$record['69_unaware_of_strong_unpleasant_smells_others_notice']],
        $score_grid[$record['70_taste_difference_between_different_brands_same_food']],
        $score_grid[$record['71_lick_non_food_objects']],
        $score_grid[$record['72_refuse_food_they_like_if_mixed_with_another']],
        $score_grid[$record['73_gag_in_response_to_certain_smells']],
        $score_grid[$record['74_trouble_distinguishing_different_tastes_or_flavors']],
        $score_grid[$record['76_jump_rock_spin']],
        $score_grid[$record['77_uneasy_or_dizzy_from_swing_merry_go_round_rocker']],
        $score_grid[$record['79_enjoy_being_upside_down']],
        $score_grid[$record['80_flaps_arms_or_hands_when_excited']],
        $score_grid[$record['81_avoid_escalators_elevators_or_other']],
        $score_grid[$record['82_unaware_of_moving_unstable_surfaces']],
        $score_grid[$record['84_spin_self_around_without_becoming_dizzy']],
        $score_grid[$record['85_unusual_postures_with_hands_fingers_arms']],
        $score_grid[$record['86_trouble_distinguishing_movement_sensations']],
        $score_grid[$record['87_trouble_looking_and_listening_same_time']],
        $score_grid[$record['88_report_certain_letters_or_numbers_particular_color']],
        $score_grid[$record['90_event_in_sense_causes_feeling_in_different_sense']],
        $score_grid[$record['91_confuse_which_sense_something_is_from']],
        $score_grid[$record['92_more_sensitive_to_social_touch']],
        $score_grid[$record['94_increase_background_noise_to_improve_attention_to_activity']],
        $score_grid[$record['95_avoid_toys_make_noise_and_light_up_same_time']],
    );


    $scores['HYPER_total_score'] =$this->findRowScore($Hyper_array);
    $scores['HYPO_total_score'] =$this->findRowScore($Hypo_array);
    $scores['SIRS_total_score'] =$this->findRowScore($Sirs_array);
    $scores['EP_total_score'] =$this->findRowScore($Ep_array);
    $scores['Auditory_total_score'] =$this->findRowScore($Auditory_array);
    $scores['Visual_total_score'] =$this->findRowScore($Visual_array);
    $scores['Tactile_total_score'] =$this->findRowScore($Tactile_array);
    $scores['Gustatory_or_Oflactory_total_score'] =$this->findRowScore($Gustatory_array);
    $scores['Vestibular_total_score'] =$this->findRowScore($Vestibular_array);
    $scores['SOCIAL_SENSORY_total_score'] =$this->findRowScore($Social_sensory_array);
    $scores['NONSOCIAL_SENSORY_total_score'] =$this->findRowScore($Nonsocial_sensory_array);


    $result = $db->update($this->table, $scores, array('CommentID'=>$this->getCommentID()));
}

    function findRowScore($scale_array)
    {
        $raw_score=0;
        foreach ($scale_array as $val)
        {
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
            if($val=='4')
            {
                $raw_score=$raw_score+4;
            }
            if($val=='3')
            {
                $raw_score=$raw_score+5;
            }
        }
        if($raw_score==0)
        {
            $raw_score="Unable to Score (Data Insufficient)";
        }

        return $raw_score;
    }
}
?>
