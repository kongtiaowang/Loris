<?php
/*
 * This file contains the Infant_social_motivation instrument
 * class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   sruthy.mathew@mcin.ca
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
/**
 * Creates the form elements for the Infant_social_motivation instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   sruthy.mathew@mcin.ca
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_Infant_social_motivation extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

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
        $this->form = new LorisForm('Infant_social_motivation_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)
        // set the object properties
        $this->testName = "Infant_social_motivation";           // test_names.Test_name
        $this->table = 'Infant_social_motivation';              // name of database table corresponding to instrument
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
            "/Infant_social_motivation(_page[0-9]+)/",
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
        $this->addHeader("Infant Social Motivation Questionnaire");
        $this->_addMetadataFields();
        $opts = array(
            null => "",
            "mother" => "Mother",
            "father" => "Father",
            "step_mother" => "Step Mother",
            "step_father" => "Step Father",
            "other" => "Other",
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
        $this->addHeader("Infant Social Motivation Questionnaire");
        $this->addHeader("<h3>For each question, please check the box that best describes your child's behavior <u>over the last month.</u></h3>");
        $options =
            array(
                null => "",
                'not_true' => "Not True",
                'sometimes_true' => "Sometimes True",
                'often_true' => "Often True",
                'almost_always_true' => "Almost Always True",
                'not_answered'      => "Not Answered"
            );

        $page1_questions =
            array(
                'q1'  =>  '1. Looks at your face when you engage or speak with him/her.',
                'q2'  =>  '2. Readily turns towards you when you call his/her name.',
                'q3'  =>  '3. Becomes excited when he/she spots a familiar person.',
                'q4'  =>  '4. Smiles in response to you or others smiling at him/her.',
                'q5'  =>  '5. Is interested in other children.',
                'q6'  =>  '6. Withdraws or resists when others attempt to engage him/her.',
                'q7'  =>  '7. Gives items to caregivers/others.',
                'q8'  =>  '8. Vocalizes back-and-forth with others.',
                'q9'  =>  '9. Becomes happy when you or another caregiver approaches him/her.',
                'q10'  =>  '10. Looks up from what he/she is doing when someone attempts to engage him/her.',
                'q11'  =>  '11. Tries to start interactions with you or other adults.',
                'q12'  =>  '12. Tries to start interactions with other children.',
                'q13'  =>  '13. Does not appear to notice when others are looking at him/her.',
                'q14'  =>  '14. Tends to avoid eye contact.',
                'q15'  =>  '15. Enjoys playful interactions.',
                'q16'  =>  '16. Appears comfortable in a group of people.',
                'q17'  =>  '17. Looks with interest towards groups of people talking.',
                'q18'  =>  '18. Responds positively when adults attempt to engage him/her.',
                'q19'  =>  '19. Responds positively when other children approach him/her.',
                'q20'  =>  '20. Stops what he/she is doing to watch other children play.',
                'q21'  =>  '21. Prefers to play by him/herself.',
                'q22'  =>  '22. Appears in his/her "own world" when in the company of familiar people.',
                'q23'  =>  '23. Does not seem to notice if people stop paying attention to him/her.',
                'q24'  =>  '24. Likes to watch you or another familiar person playfully make faces.'
            );
        foreach ($page1_questions as $question => $label) {
            $this->addSelect(
                $question,
                $label,
                $options
            );
        }
    }
    function _page2() {
        $this->addHeader("Infant Social Motivation Questionnaire");
        $this->addHeader("<h3>For each question, please check the box that best describes your child's behavior <u>over the last month.</u></h3>");
        $options =
            array(
                null => "",
                'not_true' => "Not True",
                'sometimes_true' => "Sometimes True",
                'often_true' => "Often True",
                'almost_always_true' => "Almost Always True",
                'not_answered'      => "Not Answered"
            );
        $page2_questions =
            array(
                'q25'  =>  '25. Engages with you by imitating your facial expressions or sounds.',
                'q26'  =>  '26. Smiles or laughs in anticipation of interacting with trusted adults or other children.',
                'q27'  =>  '27. Makes eye contact and smiles during social interactions.',
                'q28'  =>  '28. Appears curious about group activities.',
                'q29'  =>  '29. Looks at what others are looking at or attending to.',
                'q30'  =>  '30. Is persistent when trying to engage someone.',
                'q31'  =>  '31. Prefers focusing on objects over interacting with others.',
                'q32'  =>  '32. Avoids looking at other children.',
                'q33'  =>  '33. Shows shared enjoyment during interactions.',
                'q34'  =>  '34. Plays near other children rather than keep his/her distance.',
                'q35'  =>  '35. Spontaneously smiles and greets you, even when engaged in another activity.',
                'q36'  =>  '36. Seems to ignore others when they attempt to engage him/her.',
                'q37'  =>  '37. Wants to approach other children.',
                'q38'  =>  '38. Wants to share an event or experience with you.',
                'q39'  =>  '39. Responds positively to you when you point out something to share interest.',
                'q40'  =>  '40. Appears indifferent when a familiar person approaches or greets him/her.',
                'q41'  =>  '41. Likes being praised.',
                'q42'  =>  '42. Does not smile or laugh when you attempt to engage him/her.',
                'q43'  =>  '43. Shows items to share interest with others.',
                'q44'  =>  '44. Interacts with you for the purpose of sharing enjoyment.',
                'q45'  =>  '45. Repeats a behavior which gets a positive response or encouragement from others.',
                'q46'  =>  '46. Loses interest quickly during social interactions.',
                'q47'  =>  '47. Is affectionate with you and other family members.',
                'q48'  =>  '48. Protests or attempts to re-engage you when you stop paying attention to him/her.',
                'q49'  =>  '49. Moves towards you or reaches towards you when you approach him/her.'
            );
        foreach ($page2_questions as $question => $label) {
            $this->addSelect(
                $question,
                $label,
                $options
            );
        }
    }
}
