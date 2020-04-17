<?php
/*
 * This file contains the NDB_BVL_Instrument_apsi_survey
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mathew@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the apsi_survey instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mathew@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

class NDB_BVL_Instrument_apsi_survey extends NDB_BVL_Instrument
{
    private const questions_loss = ['speech_loss' => 'Did loss involve speech?',
        'eye_contact_social_emot_loss' => 'And/or eye contact and social-emotional connectedness?'];

    private const relevant_questions = ['speech_loss_occurred_before_eye_loss' => 'Speech Loss occured BEFORE loss of eye contact and social-emotional connectedness',
        'speech_loss_occurred_after_eye_loss' => 'Speech Loss occured AFTER loss of eye contact and social-emotional connectedness',
        'speech_loss_occurred_close_to_eye_loss' => 'Speech loss and loss of eye contact and social-emotional connectedness closely together in time'];

    private const options =
        [
            null => "",
            'n' => "No",
            'p' => "Possibly",
            'd' => "Definitely"
            //'NA' => "Not applicable"
        ];

    public function getFullName(): string
    {
        return 'Autism Parent Screen for Infants Survey (APSI Survey)';
    }

    function getSubtestList(): array {
        return [['Name' => 'apsi_survey_page1', 'Description' => "Page 1"]];
    }

    /**
     * sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(string $commentID = NULL, string $page = NULL): void
    {
        $this->formType = "XIN";
        $this->form = new LorisForm('apsi_survey_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "apsi_survey";           // test_names.Test_name
        $this->table = 'apsi_survey';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array('CommentID');

        // setup the form
        $this->_setupForm();
    }

    /**
     * method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        //determine page to display
        if (preg_match(
            "/apsi_survey(_page[0-9]+)/",
            $this->page,
            $matches
        )) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    /**
     * generates the main page of the form.
     *
     * @return void
     * @access private
     *
     */
    function _main()
    {
        // display test name
        $this->addHeader("Autism Parent Screen for Infants Survey (APSI Survey)");

        $this->addLabel('Instructions: Please answer each of the questions below, based on your child’s <u>current</u> (not past) behaviour, by placing a check beside the box that most applies (either “No”, “Possibly” or “Definitely”). We appreciate that some of the questions refer to behaviours not expected in very young infants, notably 6- to 9-month-olds; your responses to those questions will be treated accordingly. Thank you for assisting us in monitoring your child’s development.');
        $config      =& NDB_Config::singleton();
        $dateOptions = array(
            'language'         => 'en',
            'format'           => 'YMd',
            'minYear'          => $config->getSetting('startYear'),
            'maxYear'          => $config->getSetting('endYear'),
            'addEmptyOption'   => true,
            'emptyOptionValue' => null,
        );

        $this->addBasicDate('Date_taken', 'Date Taken', $dateOptions);

        $opts = array(
            null => "",
            "m" => "Mother",
            "f" => "Father",
            "s_m" => "Step Mother",
            "s_f" => "Step Father",
            "oth" => "Other",
        );
        $this->addSelect("filling_out_form", "Completed by:", $opts);
        $this->addBasicText("other_filling_out_form", $this->indent . "If Other, please describe:");
        $this->XINRegisterRule(
            "other_filling_out_form",
            array("filling_out_form{@}=={@}other"),
            "Required",
            "other_filling_out_form"
        );
    }

    function _page1()
    {
        $this->addHeader("<h3>Autism Parent Screen for Infants Survey (APSI Survey)</h3>");

        $optionsYesNo =
            [
                null => '',
                'n'  => 'No',
                'y'  => 'Yes',
            ];

        $page1_questions =
            array(
                'q1' => '1) Does your child have difficulty visually tracking a moving object, that is, smoothly moving his/her eyes to follow an object’s direction of movement?',
                'q2' => '2) Does your child visually fixate on, or stare at, certain objects such as lights, or objects with patterns?',
                'q3' => '3) Does your child frequently fail to respond, or show a delay in responding, when you call his/her name?',
                'q4' => '4) Does your child react to changes in your facial expression (i.e., without changes in your voice) when you are upset or distressed?',
                'q5' => '5) Does your child enjoy and anticipate the pleasure of social games such as “peek-a- boo” or “Ring around the Rosie”?',
                'q6' => '6) Does your child imitate the sounds or actions of others?',
                'q7' => '7) Does your child vocalize back-and-forth with you, either by babbling or speaking in response to your attempts to converse and interact with him/her?',
                'q8' => '8) Is it difficult to establish eye contact with your child, or does he/she look only briefly at others in face-to-face contact?',
                'q9' => '9) Does your child generally smile in response to your smiles?',
                'q10' => '10) Does your child have difficulty coordinating his/her actions with eye gaze; that is, are there times that he/she plays with or manipulates objects without looking at them?',
                'q11' => '11) Does your child tend to be over-reactive and/or under-reactive to his/her environment (events or people), that is, show little reaction to what is happening, or startle easily and become distressed or upset?',
                'q12' => '12) Does your child cuddle into your body when you are holding him/her?',
                'q13' => '13) Is it difficult to soothe your child when he/she is upset?',
                'q14' => '14) Does your child show sustained interest and pleasure in interacting with others?',
                'q15' => '15) Does your child have difficulty with change, such as moving from one activity to another, giving up a toy, using a new cup, or other changes in routine?',
                'q16' => '16) Compared to other children his/her age, does your child have difficulty using his/her hands or controlling his/her movements (e.g., grasping something small, rolling over, sitting up or walking)?',
                'q17' => '17) Does your child have unusual or repetitive motor behaviours such as walking on his/her toes, hand posturing or flapping, or flicking fingers close to his/her eyes?',
                'q18' => '18) Does your child ever take someone else’s hand and place it on an object, or use another’s hand for actions such as opening a door?',
                'q19' => '19) Does your child have any unusual sensory behaviours such as smelling of toys or objects, feeling or avoiding certain textures, or seeking out or avoiding particular sounds?',
                'q20' => '20) Does your child have difficulty focusing his/her attention on objects or events for a sustained period of time?',
                'q21' => '21) Does your child insist on holding on to, or playing with a particular toy, blanket or other object?',
                'q22' => '22) Does your child resist others joining into his/her play, or have fixed play routines that he/she does not want others to disrupt?',
                'q23' => '23) Does your child share interest in an object or event with others by moving his/her eyes between the object and the person?',
                'q24' => '24) Does your child point at a distance to objects or events such as an airplane or a balloon, specifically to “show” and share with you, rather than to “ask” for the object?',
                'q25' => '25) Does your child use gestures such as waving good-bye, nodding his/her head or blowing a kiss?',
                'q26' => '26) Over the past 2-3 months, has your child lost any skills, either words spoken or his/her ability to look at and establish a social-emotional connection with others?',
            );

         foreach ($page1_questions as $question => $label) {
             $this->addSelect($question, $label, self::options);
         }

         foreach (self::questions_loss as $question => $label) {
             $this->addSelect($question, $label, $optionsYesNo);
             $this->XINRegisterRule($question, array("q26{@}=={@}p|d"), "Required");
         }

         $this->addBasicTextArea("other_skills_lost","If other, please identify skill(s) lost:");
         $this->XINRegisterRule('other_skills_lost',array("other_skills_lost{@}=={@}NEVER_REQUIRED"));

         foreach (self::relevant_questions as $question => $label) {
             $this->addSelect($question, $label, $optionsYesNo);
             $this->XINRegisterRule($question, array("q26{@}=={@}p|d"), "Required");
         }

         $this->form->addFormRule(array(&$this, 'conflict_rules'));
    }

    /**
     * Conflict check
     */
    function conflict_rules($values) {
        $errors = [];
        if (in_array($values['q26'], ['n'])) {
            $check_fields = array_merge(array_keys(self::questions_loss), ['other_skills_lost'], array_keys(self::relevant_questions));
            foreach ($check_fields as $key) {
                if (!empty($values[$key])) {
                    $errors[$key] = "You should not answer this question if the answer of the question 26 is No";
                }
            }
        }
        return $errors;
    }
}
