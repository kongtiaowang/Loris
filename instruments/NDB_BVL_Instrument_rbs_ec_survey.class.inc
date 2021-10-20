<?php
/**
 * This file contains the NDB_BVL_Instrument_rbs_ec_survey
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  IBIS
 * @author   Ling Ma <lingyun.ma@mcin.ca>
 * @date     2020 Apr 22
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

class NDB_BVL_Instrument_rbs_ec_survey extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;
    var $ValidityRequired = false;

    private const Score_Options = [
            '' => '',
            '0' => '0 - behavior does not occur',
            '1' => '1 - behavior occurs about weekly or less',
            '2' => '2 - behavior occurs several times a week',
            '3' => '3 - behavior occurs about daily',
            '4' => '4 - behavior occurs many times a day',
            'nk' => 'Not Known'
        ];

    private const Question_Grp1 = [
            '1_legs' => '1. LEGS (kicking, flexing, bouncing, swinging, foot tapping)',
            '2_head' => '2. HEAD (head rolling, nodding, shaking - <i>do not count nodding or shaking to communicate \'yes\' or \'no\'</i>)',
            '3_whole_body' => '3. WHOLE BODY/TORSO (rocking, bouncing, swaying, arching)',
            '4_arms_hands' => '4. ARMS/HANDS/FINGERS (flaps or flutters hands or arms in air; wiggles or flicks fingers; shakes or claps - <i>do not count social clapping or waving \'hello\' or \'goodbye\'</i>)',
            '5_arms_hands' => '5. ARMS/HANDS/FINGERS ON SURFACES (slaps, taps, or drums against objects, walls, floors, tables, or other furniture)',
            '6_object_usage' => '6. OBJECT USAGE  (bangs, spins, twirls, shakes, drops or rolls toys or other objects)',
            '7_mouthing_objects' => '7. MOUTHING OBJECTS (mouths, bites, licks, or sucks objects - <i>do not count bottles, pacifiers, cups or utensils</i>)',
            '8_locomotion' => '8. LOCOMOTION (repeatedly spins, scoots, crawls, walks, hops or runs in circles or back & forth)',
            '9_vocalizations' => '9. VOCALIZATIONS (repeats same sound, word or phrase - <i>do not count attempts at communication</i>)',
            '10_hits_self_with_obj' => '10. HITS SELF WITH OBJECTS (hits or bangs head or other body area with objects, e.g. toys)'
        ];

    private const Question_Grp2 = [
            '11_sensory_interests' => '11. SENSORY INTERESTS (seeks specific tactile, auditory, or visual sensations, e.g. smells or rubs specific objects; intense fascination with specific sounds, lights, or textures)',
            '12_visual_inspection' => '12. VISUAL INSPECTION (closely inspects objects; views toys and other objects from an unusual angle)',
            '13_stillness' => '13. STILLNESS (lays or sits still for extended periods of time while alone; content to do “nothing” – <i>do not count naps/bedtime</i>)',
            '14_fascination_movement' => '14. FASCINATION WITH MOVEMENT (intense interest or focus on things that move; e.g. fans, toys that spin, bounce, roll, flutter, etc.)'
        ];

    private const ScoresInstruction = '0 – behavior <u>does not occur</u><br>
1 – behavior occurs about weekly or less<br>
2 – behavior occurs several times a week<br>
3 – behavior occurs about daily<br>
4 – behavior occurs many times a day<br>';

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
    function setup(?string $commentID = null, ?string $page = null): void
    {
        $this->formType = 'XIN';
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;

        // set the object properties
        $this->testName  = 'rbs_ec_survey'; // test_names.Test_name
        $this->table     = 'rbs_ec_survey';
        $this->commentID = $commentID; // data keyed by commentID

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        // 'date_of_birth',
        $this->dateTimeFields = array(
            'Date_taken'
        );

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        //$this->selectMultipleElements = array();

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
        if (preg_match("/rbs_ec_survey(_page[0-9]+)/",
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
        $this->addHeader('REPETITIVE BEHAVIOR SCALE for Early Childhood (Infant Items)');

        $this->addLabel('<p><b>This is a measure of repetitive behaviors for use in infants. Repetitive behaviors can range from simple motor movements to complex patterns of interests and routines. Many of these behaviors are very common in children and occur as part of healthy development.</b></p><br>
         <p><b>INSTRUCTIONS</b>: Please rate your child’s behavior for each of the 14 items listed by circling the score that best describes how <u>often</u> the behavior occurs. Be sure to read and score all items. Make your ratings based on your child’s behavior over the past <u>month</u>. Use the definitions in the box given below to score each item:</p>'
            . self::ScoresInstruction .
        '<p>If an item is “not applicable” because your child cannot yet perform a particular behavior (for instance, he or she is not yet grasping objects), the item should be scored as “0” (behavior does not occur).</p>');
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

        $opts = array(
            null => "",
            "m"  => "Mother",
            "f"  => "Father",
            "o"  => "Other",
        );
        $this->addSelect("relationship_to_child", "What is your relationship to the child?", $opts);
        $this->XINRegisterRule(
            "relationship_to_child",
            array("relationship_to_child{@}=={@}"),
            "Required"
        );

        $this->addBasicText("other_relationship_to_child", $this->indent."If Other, please describe:");
        $this->XINRegisterRule(
            "other_relationship_to_child",
            array("relationship_to_child{@}=={@}o"),
            "Required",
            "other_relationship_to_child"
        );
    }

    private const PageInstruction =
        '<br><br><b>Instructions:</b> Read each of the items listed and circle the score that best describes how <u>often</u> the behavior occurs. Be sure to read and score all items.
        Make your ratings based on your observations and interactions with your child over the past <u>month</u>.<br>' . self::ScoresInstruction . '<br>';

    /**
     * Page 1
     *
     * @return void
     */
    function _page1()
    {
        $this->form->addElement('static','lorisSubHeader', self::PageInstruction);
        $this->addHeader('<u>I. Repetitive Motor</u>');

        $this->addLabel('<b>DEFINITION: consecutive, non-social movements or actions that are repeated in a similar manner</b>');

        foreach (self::Question_Grp1 as $key => $val) {
            $this->addSelect($key, $val, self::Score_Options);
            $this->form->addRule($key, $val . ' must be set', 'required');
        }
    }


    /**
     * Page 2
     *
     * @return void
     */
    function _page2() {
        $this->form->addElement('static', 'lorisSubHeader', self::PageInstruction);

        $this->addHeader('<u>II. Restricted Interests & Behavior</u>');

        $this->addLabel('<b>DEFINITION: behaviors with a limited or inflexible range of focus; intense or unique interests or activities.</b>');

        foreach (self::Question_Grp2 as $key => $val) {
            $this->addSelect($key, $val, self::Score_Options);
            $this->form->addRule($key, $val . ' must be set', 'required');
        }

        $name = "comments";

        $this->addBasicTextArea($name, 'Comments (optional)');
        $this->XINRegisterRule(
            $name,
            array("$name{@}=={@}NEVER_REQUIRED"),
            'Not required'
        );
    }
}


