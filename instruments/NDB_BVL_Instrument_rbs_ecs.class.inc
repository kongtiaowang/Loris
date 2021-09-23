<?php
/**
 * This file contains the NDB_BVL_Instrument_rbs_ecs
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  IBIS
 * @author   Ling Ma <lingyun.ma@mcin.ca>
 * @date     2019 Dec 4
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

class NDB_BVL_Instrument_rbs_ecs extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    var $ValidityRequired = false;

    private $score_options = array(
            '' => '',
            '0' => 'behavior does not occur',
            '1' => 'behavior occurs about weekly or less',
            '2' => 'behavior occurs several times a week',
            '3' => 'behavior occurs about daily',
            '4' => 'behavior occurs many times a day'
        );

    private $evaluation_options = array(
            '' => '',
            '0' => 'Never',
            '1' => 'Rarely',
            '2' => 'Sometimes',
            '3' => 'Often',
            '4' => 'Always'
        );

    private $question_grp1 = [
            '1_legs' => '1. LEGS (kicking, flexing, bouncing, swinging, foot tapping)',
            '2_head' => '2. HEAD (head rolling, nodding, shaking - do not count nodding or shaking to communicate \'yes\' or \'no\')',
            '3_whole_body' => '3. WHOLE BODY/TORSO (rocking, bouncing, swaying, arching)',
            '4_arms_hands' => '4. ARMS/HANDS/FINGERS (flaps or flutters hands or arms in air; wiggles or flicks fingers; shakes or claps - do not count social clapping or waving \'hello\' or \'goodbye\')',
            '5_arms_hands' => '5. ARMS/HANDS/FINGERS ON SURFACES (slaps, taps, or drums against objects, walls, floors, tables, or other furniture',
            '6_object_usage' => '6. OBJECT USAGE (bangs, spins, twirls, shakes, or rolls toys or other objects)',
            '7_mouthing_objects' => '7. MOUTHING OBJECTS (mouths, bites, licks, or sucks objects - do not count bottles, pacifiers, cups or utensils)',
            '8_locomotion' => '8. LOCOMOTION (repeatedly spins, scoots, crawls, walks, hops or runs in circles/back & forth)',
            '9_vocalizations' => '9. VOCALIZATIONS (repeats same sound, word or phrase - do not count attempts at communication)'
        ];

    private $question_grp2 = [
            '10_hits_with_body_part' => '10. HITS SELF WITH BODY PART (hits or slaps head, arms, legs or other body part)',
            '11_hits_with_object' => '11. HITS SELF WITH OBJECT (hits or bangs head or other body area with objects, e.g. toys)',
            '12_hits_against_surface' => '12. HITS SELF AGAINST SURFACE/OBJECT (hits or bangs head or other body part on furniture, walls, floors, or other surfaces)',
            '13_bites' => '13. BITES SELF (bites hand, arm, lips, tongue)',
            '14_rubs_pokes' => '14. RUBS, SCRATCHES, POKES OR PINCHES SELF',
            '15_pulls_hair' => '15. PULLS OWN HAIR',
            '16_skin_picking' => '16. SKIN PICKING (picks at marks, scabs, or healthy skin on face, hands, arms or torso)'
        ];

    private $question_grp3 = [
            '17_limited_interests' => '17. LIMITED & INTENSE INTERESTS (narrow preoccupation with one subject or activity, e.g., trains, dinosaurs, collecting items, e.g. rocks, sticks, strings; plays only with specific toys)',
            '18_restricted_use_media' => '18. RESTRICTED USE OF MEDIA (strongly insists on same music, book, app, program, movie or part of program/movie etc.; firmly refuses new books/apps/movies etc.)',
            '19_sensory_interests' => '19. SENSORY INTERESTS (seeks specific tactile, auditory, or visual sensations, e.g. smells or rubs specific objects; intense fascination with specific sounds, lights, or textures)',
            '20_attach_to_specific_obj' => '20. STRONGLY ATTACHED TO SPECIFIC OBJECT (insists on bringing/carrying one specific toy or other object)',
            '21_focus_parts_of_obj' => '21. PREOCCUPATION W/ PARTS OF OBJECTS (focuses on parts of objects rather than the whole object, e.g. wheels on toy cars, eyes on dolls or stuffed animals)',
            '22_stillness' => '22. STILLNESS (lays or sits still for extended periods of time while alone; content to do “nothing” – do not count naps/bedtime)',
            '23_visual_inspection' => '23. VISUAL INSPECTION (closely inspects objects; views toys and other objects from an unusual angle)',
            '24_fascination_with_movement' => '24. FASCINATION WITH MOVEMENT (intense interest or preoccupation with things that move, e.g. fans, clocks)'
        ];

    private $question_grp4 = [
            '25_arranging' => '25. ARRANGING (lines up or arranges toys or other objects)',
            '26_placement_of_objects' => '26. PLACEMENT OF OBJECTS (insists that things remain in the same place, e.g. toys, furniture; returns items to “correct” location when disturbed by others)',
            '27_upset_visiting_new_places' => '27. UPSET VISITING NEW PLACES (cries or “melts down” when visiting an unfamiliar place; refuses to enter new settings)',
            '28_upset_if_interrupted' => '28. UPSET IF INTERRUPTED (cries or “melts down” when an activity is interrupted; difficulty with transitions even with advance warning)',
            '29_appearance_of_others' => '29. APPEARANCE OF OTHERS (upset by change in appearance of others, e.g. hairstyle, hats, clothes)',
            '30_inflexible_routine' => '30. INFLEXIBLE ROUTINE (overly upset by changes to daily routine, e.g. schedule, people involved, or order of activities; insists that events occur in a specific order)',
            '31_eating_mealtime' => '31. EATING/MEALTIME (strongly insists on set meal routine, e.g. eats only specific foods or brands, eats/drinks in a set order, or at a specific place/time)',
            '32_sleeping_bedtime' => '32. SLEEPING/BEDTIME (refuses to sleep in new places; strongly insists that room or bed is “just so” at bedtime; strongly insists that specific activities precede bedtime)',
            '33_play' => '33. PLAY (follows a rigid play routine; insists that others play in a specific way; upset if play routine is altered)',
            '34_social_interaction' => '34. SOCIAL INTERACTION (insists that others respond in a specific way; follows a set verbal script or routine regardless of context or social behavior of other children or adults)'
        ];

    private $question_grp_frequency = [
            ['repetitive_motor', 'I. Repetitive Motor Behavior', 'Raw score / 9 ='],
            ['self_directed_injurious', 'II. Self-Directed & Self-Injurious Behavior', 'Raw score / 7 ='],
            ['restricted', 'III. Restricted Behavior', 'Raw score / 8 ='],
            ['ritual_routine', 'IV. Ritual & Routine Behavior', 'Raw score / 10 ='],
            ['composite_score', 'Composite Score', 'Raw score / 34 =']
        ];

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID The CommentID identifying the data to load
     * @param string $page      If a multipage form, the page to show
     *
     * @return   void
     * @access   public
     * @abstract
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = 'XIN';
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;

        // set the object properties
        $this->testName  = 'rbs_ecs'; // test_names.Test_name
        $this->table     = 'rbs_ecs';
        $this->commentID = $commentID; // data keyed by commentID

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        // 'date_of_birth',
        $this->dateTimeFields = array(
            'Date_taken'
        );

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        //$this->_selectMultipleElements = array();

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
        if (preg_match("/rbs_ecs(_page[0-9]+)/",
            $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

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
        // Header
        $this->addHeader('Scoring sheet for RBS-ECS');
        $this->form->addElement('static', null, "<i><h3>*Please fill this form out with regard to your child who has enrolled in our study, NOT their older sibling with autism</i></h3>");

        $config      =& NDB_Config::singleton();
        $dateOptions = array(
            'language'         => 'en',
            'format'           => 'YMd',
            'minYear'          => $config->getSetting('startYear'),
            'maxYear'          => $config->getSetting('endYear'),
            'addEmptyOption'   => true,
            'emptyOptionValue' => null,
        );
        $this->addBasicDate('Date_taken', 'Date Taken', $dateOptions, ['required' => true]);

        $this->addLabel('<strong>Items Endorsed & Interference Rating</strong>');
        $group = array();
        //scoring column headers
        $group[] = $this->form->createElement('static', null, null, 'Subscale');
        $group[] = $this->form->createElement('static', null, null, 'Number of items endorsed');
        $group[] = $this->form->createElement('static', null, null, 'Interference rating');
        $this->form->addGroup($group, 'score_group1_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);

        $count = 0;
        foreach ($this->question_grp_frequency as list($key, $label, $info)) {

            $count += 1;
            $group = array();
            $group[] = $this->createLabel($label);
            $group[] = $this->form->createElement('static', "{$key}_number", null, null);
            $group[] = $this->form->createElement('static', "{$key}_interfere_rating", null, null);

            $this->form->addGroup(
                    $group,
                    "score_group1_row{$count}",
                    null,
                    $this->_GUIDelimiter,
                    false
                );

            unset($group);
        }

        $this->addLabel('<strong>Frequency Scores</strong>');
        //scoring column headers
        $group[] = $this->form->createElement('static', null, null, 'Subscale');
        $group[] = $this->form->createElement('static', null, null, 'Raw frequency score');
        $group[] = $this->form->createElement('static', null, null, 'Adjustment');
        $group[] = $this->form->createElement('static', null, null, 'Mean frequency score');
        $this->form->addGroup($group, 'score_group2_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);

        $count = 0;
        foreach ($this->question_grp_frequency as list($key, $label, $adjust)) {

            $count += 1;
            $group = array();
            $group[] = $this->createLabel($label);
            $group[] = $this->form->createElement('static', "{$key}_raw", null, null);
            $group[] = $this->form->createElement('static', null, null, $adjust);
            $group[] = $this->form->createElement('static', "{$key}_mean", null, null);

            $this->form->addGroup(
                    $group,
                    "score_group2_row{$count}",
                    null,
                    $this->_GUIDelimiter,
                    false
                );
            unset($group);
        }

        $this->addLabel('<strong>Comments</strong>');
        $group = array();
        //scoring column headers

        $group[] = $this->form->createElement('static', null, null, 'I. Repetitive Motor');
        $group[] = $this->form->createElement('static', null, null, 'II. Self-Directed & Self-Injurious Behavior');
        $group[] = $this->form->createElement('static', null, null, 'III. Restricted Behavior');
        $group[] = $this->form->createElement('static', null, null, 'IV. Ritual & Routine Behavior');
        $this->form->addGroup($group, 'cpomments_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);

        $section_lst = ['repetitive_motor',
                'self_directed_injurious',
                'restricted',
                'ritual_routine'];

        $group = array();
        foreach ($section_lst as $key) {
            $name = "{$key}_comments";
            $group[] = $this->form->createElement('static', $name, null, null);
        }

        $this->form->addGroup(
                $group,
                'comments_row',
                null,
                $this->_GUIDelimiter,
                false
            );

        unset($group);
    }


    function _comment($key) {
        $val = 'In total, how often do the above behaviors interfere with other activities or interactions? Circle the best answer';
        $name = "{$key}_interfere";
        $this->addSelect($name, $val, $this->evaluation_options, ['required' => true]);

        $name = "{$key}_comment";

        $this->addBasicTextArea($name, 'Comments (optional)');
        $this->XINRegisterRule(
                $name,
                array("$name{@}=={@}NEVER_REQUIRED"),
                'Not required'
            );
    }


    private function _page_instruction() {
        return '<br><br><b>Instructions:</b><br>
        Read each of the items listed and circle the score that best describes how <b>often</b> the behavior occurs. Be sure to read and score all items.
        Make your ratings based on your observations and interactions with your child over the past <b>month</b>.<br><br>';
    }

    /**
     * Page 1
     *
     * @return void
     */
    function _page1()
    {
        $title = 'I. Repetitive Motor';
        $this->addHeader($title);

        $this->form->addElement('static','lorisSubHeader', '<b>DEFINITION: consecutive, non-social movements or actions that are repeated in a similar manner</b>' . $this->_page_instruction());

        foreach ($this->question_grp1 as $key => $val) {
            $this->addSelect($key, $val, $this->score_options);
            $this->form->addRule($key, $val . ' must be set', 'required');
        }

        $key = 'repetitive_motor';
        $this->_comment($key);
    }


    /**
     * Page 2
     *
     * @return void
     */
    function _page2() {
        $title = 'II. Self-Directed & Self-Injurious Behavior';
        $this->addHeader($title);

        $this->form->addElement('static', 'lorisSubHeader', '<b>DEFINITION: movement or actions with the potential to cause redness, bruising, or other injury to the body that are repeated in a similar manner.</b>' . $this->_page_instruction());

        foreach ($this->question_grp2 as $key => $val) {
            $this->addSelect($key, $val, $this->score_options);
            $this->form->addRule($key, $val . ' must be set', 'required');
        }

        $key = 'self_directed_injurious';
        $this->_comment($key);
    }


    /**
     * Page 3
     *
     * @return void
     */
    function _page3()
    {
        $title = 'III. Restricted Behavior';
        $this->addHeader($title);

        $this->form->addElement('static', 'lorisSubHeader', '<b>DEFINITION: behaviors with a limited and inflexible range of focus, interest, or activity</b>' . $this->_page_instruction());

        foreach ($this->question_grp3 as $key => $val) {
            $this->addSelect($key, $val, $this->score_options);
            $this->form->addRule($key, $val . ' must be set', 'required');
        }

        $key = 'restricted';
        $this->_comment($key);
    }

    /**
     * Page 4
     *
     * @return void
     */
    function _page4()
    {
        $title = 'IV. Ritual & Routine Behavior';
        $this->addHeader($title);

        $this->form->addElement('static', 'lorisSubHeader', '<b>DEFINITION: resistant to change; engages in fixed patterns of behavior; strongly insists that daily activities are performed in the same way</b>' . $this->_page_instruction());

        foreach ($this->question_grp4 as $key => $val) {
            $this->addSelect($key, $val, $this->score_options);
            $this->form->addRule($key, $val . ' must be set', 'required');
        }

        $key = 'ritual_routine';
        $this->_comment($key);
    }


    /**
     * Score
     */
    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == 'Incomplete') {
            return;
        }

        $sections = [
            'repetitive_motor' => 9,
            'self_directed_injurious' => 7,
            'restricted' => 8,
            'ritual_routine' => 10
        ];
        // and 'composite_score' => 34, the last one is written below in hard code. The information is saved here for reference.

        $score_arr = [];
        foreach ($sections as $section => $adjustment) {
            $score_arr[] = "{$section}_number";
            $score_arr[] = "{$section}_interfere_rating";
            $score_arr[] = "{$section}_raw";
            $score_arr[] = "{$section}_mean";
        }

        $this->_nullScores($score_arr);

        $db =& Database::singleton();
        $score_record = $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid", array('cid' => $this->getCommentID() ));

        $calculated_scores = [];
        $score_accumulated_cnt = 0;
        $score_accumulated_interfere_rating = 0;
        $score_accumulated_raw = 0;
        $section_id = 0;
        foreach ($sections as $section => $adjustment) {
            $section_id ++;
            $arr_name = "question_grp{$section_id}";
            $keys = array_keys($this->$arr_name);

            $score_cnt = 0;
            $score_sum = 0;
            foreach ($keys as $key) {
                if (!empty($score_record[$key])) {
                    $score_cnt ++;
                    $score_sum += $score_record[$key];
                }
            }
            $score_accumulated_cnt += $score_cnt;
            $calculated_scores["{$section}_number"] = $score_cnt;
            $calculated_scores["{$section}_raw"] = $score_sum;
            $calculated_scores["{$section}_mean"] = round((int)$score_sum / $adjustment, 2);
            $calculated_scores["{$section}_interfere_rating"] = $score_record["{$section}_interfere"];
            $score_accumulated_interfere_rating += $score_record["{$section}_interfere"];

            $score_accumulated_raw += $score_sum;
        }

        $calculated_scores['composite_score_number'] = $score_accumulated_cnt;
        $calculated_scores['composite_score_raw'] = $score_accumulated_raw;
        $calculated_scores['composite_score_interfere_rating'] = $score_accumulated_interfere_rating;
        $calculated_scores['composite_score_mean'] = round((int)$score_accumulated_raw / 34, 2);

        if (!empty($calculated_scores)) {
            $result = $db->update($this->table, $calculated_scores, array('CommentID'=>$this->getCommentID()));
        }
    }
}
