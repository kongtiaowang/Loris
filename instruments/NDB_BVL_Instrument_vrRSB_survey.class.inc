<?php
/**
 * This file contains the NDB_BVL_Instrument_vrRSB_survey class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  IBIS
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the Video Referenced Ratings of Reciprocal Social Behavior - Survey
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_vrRSB_survey extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('vrRSB_survey', "Video-Referenced Rating of Reciprocal Social Behavior", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('vrRSB_survey', 'vrRSB_survey_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('vrRSB_survey', 'vrRSB_survey_page2', "Page 2", 2);
     * INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('vrRSB_survey', 'V18');
     * INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('vrRSB_survey', 'V18-CVD');
     * INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('vrRSB_survey', 'V24');
     * INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('vrRSB_survey', 'V24-CVD');
     *
     */

    /**
     * sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = "XIN";
        $this->form = new LorisForm('vrRSB_survey');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "vrRSB_survey";           // test_names.Test_name
        $this->table = 'vrRSB_survey';              // name of database table corresponding to instrument
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

    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

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
            "/vrRSB_survey(_page[0-9]+)/",
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
        $this->addHeader("Video-Referenced Rating of Reciprocal Social Behavior");
        $this->_addMetadataFields();
        $opts = array(
            null => "",
            "mother" => "Mother",
            "father" => "Father",
            "day_care_provider" => "Day care Provider",
            "other" => "Other",
        );
        $this->addSelect("filling_out_form", "This form filled out by:", $opts);
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
        $this->addHeader("Video-Referenced Rating of Reciprocal Social Behavior");
        $this->addHeader("<h3>Instructions for Section I:</h3><br>
                         <h4>You are about to view a brief video segment that shows the social behaviors of a child who has not
yet begun to talk (other than a few simple words). Then you will complete a series of questions,
some of which ask you to compare your child’s behavior to the child in the video.<br></h4>");

        $this->addSelect(
            "q0",
            "I have watched the video for this questionnaire",
            array(
                null => "",
                0 => "No",
                1 => "Yes"
            )
        );

//As per NDAR Data Dictionary:https://ndar.nih.gov/data_structure.html?short_name=vrrsb01
        $options_1 =
            array(
                null => "",
                0 => "Not at all",
                1 => "Somewhat but less than child in video",
                2 => "About the same as child in video",
                3 => "More than child in video"
            );

        $sect1_questions =
            array(
                'q1' => '1) Is your child able to express feelings by changes in facial expression?',
                'q2' => '2) Is it typical for your child to be “on the same wavelength” with you?',
                'q3' => '3) Is your child able to pretend (engage in make-believe play)?',
                'q4' => '4) Does your child have a sense of humor?',
                'q5' => '5) Does your child try to involve others in play?',
                'q6' => '6) Does your child respond positively to adults who are trying to hold his/her attention?',
                'q7' => '7) Does your child look at you (making eye contact) when you are playing together?',
                'q8' => '8) When you approach your child to play with him or her, does he/she seem happy to include you or glad that you are involved?',
                'q9' => '9) Does your child seem interested in whether you are paying attention to what he or she is doing?',
                'q10' => '10) Is your child able to let you know what he or she DOESN’T want?',
                'q11' => '11) Is your child able to let you know what he or she DOES want?',
                'q12' => '12) Does your child cooperate with an adult’s request for help (e.g., clean-up, picking up toys)?',
                'q13' => '13) Does your child understand simple verbal requests?'
            );

        foreach ($sect1_questions as $question => $label) {
            $this->addSelect(
                $question,
                $label,
                $options_1
            );
        }
    }

    function _page2()
    {
        $this->addHeader("<br>Video-Referenced Rating of Reciprocal Social Behavior<br>");

        $this->addHeader("<h3>Instructions for Section II and Appendix Items:</h3><br>
                         <h4>For each question, please check the box that best describes your child’s behavior over the last
Month. Note that the headings for the answers are different from Section I:<br></h4>"
        );

        $options_2 =
            array(
                null => "",
                0 => "Not TRUE",
                1 => "Sometimes TRUE",
                2 => "Often TRUE",
                3 => "Almost Always TRUE"
            );

        $sect2_questions =
            array(
                'q14' => '14) Reacts to changes in other’s tone of voice and facial expressions',
                'q15' => '15) Avoids eye contact or has unusual eye contact',
                'q16' => '16) Seems obsessed with certain sensory interests (e.g., mouthing or spinning objects for prolonged periods of time)',
                'q17' => '17) Is able to imitate others’ actions',
                'q18' => '18) Has more difficulty than other children his/her age with changes in his/her routine',
                'q19' => '19) Avoids starting social interactions with peers or adults',
                'q20' => '20) Seems odd or weird',
                'q21' => '21) Avoids people who try to be emotionally close to him/her',
                'q22' => '22) Has an unusually narrow range of things that he/she is interested in',
                'q23' => '23) Behaves in ways which seem strange or bizarre',
                'q24' => '24) Seems uncoordinated for his/her age',
                'q25' => '25) Wanders aimlessly from one activity to another',
                'q26' => '26) Seems overly sensitive to sounds, textures, or smells',
                'q27' => '27) Focuses his/her attention on the same thing that others are looking at or listening to',
                'q28' => '28) Has overly serious facial expressions',
                'q29' => '29) Has repetitive, odd behaviors such as hand flapping or rocking',
                'q30' => '30) Seems to interact with people as if they are objects',
                'q31' => '31) Concentrates too much on parts of toys rather than using the whole toy for its intended purpose',
                'q32' => '32) Is emotionally distant, doesn’t show his/her feelings',
                'q33' => '33) Stares or gazes off into space',
                'q34' => '34) When seeing a spinning object (e.g. a fan or mobile), may stare at it for more than five minutes',
                'q35' => '35) Is interested in what people around him/her are doing',
                'q36' => '36) Shows unusual responses to being held / cuddled',
                'q37' => '37) Is capable of expressing joy by smiling or facial gestures',
                'q38' => '38) When offered a stuffed animal, will try to interact or pretend with it (hug it, pet it, or feed it)',
                'q39' => '39) Responds to his/her name being called',
                'q40' => '40) Seems to prefer to be by himself/herself',
                'q41' => '41) Has strange ways of playing with toys',
                'q42' => '42) Indicates, by pointing, when he/she wants something or is interested in something',
                'q43' => '43) Has unusual sleep patterns/ wakes up repeatedly in middle of night',
                'q44' => '44) Can assemble a puzzle with 8 or more inter-locking pieces',
                'q45' => '45) Seems eager to explore new play materials',
                'q46' => '46) Seems inquisitive or fascinated by complicated toys or materials',
                'q47' => '47) Is content to play with the same toy for hours',
                'q48' => '48) Able to perform simple construction tasks, such as placing four different shapes into the correct place in an inset (wooden) puzzle',
            );

        foreach ($sect2_questions as $question => $label) {
            $this->addSelect(
                $question,
                $label,
                $options_2
            );
        }

        $this->addTextElement('q49', '49) Please estimate approx. total # of words your child uses TO COMMUNICATE with you/anyone:');
        $this->addTextElement('q50', '50) In the space provided, please write the most sophisticated sentence your child has spoken in the past 2 months—if he/she ONLY speaks in phrases, please write the most sophisticated phrase your child has spoken in the past 2 months:');

        $this->addHeader('<h6><b>Appendix Items:</b></h6>');
        $this->addSelect("app_1",'Tends to withdraw or isolate him/her self when you attempt to play with him/her?', $options_2);
    }
}
