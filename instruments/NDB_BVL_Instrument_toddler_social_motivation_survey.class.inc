<?php


/*
 * This file contains the toddler_social_motivation_survey instrument
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
 * Creates the form elements for the toddler_social_motivation_survey instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   sruthy.mathew@mcin.ca
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

class NDB_BVL_Instrument_toddler_social_motivation_survey extends NDB_BVL_Instrument
{
    /**
     * sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup($commentID, $page)
    {
        $this->formType = "XIN";
        $this->form = new LorisForm('toddler_social_motivation_survey_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "toddler_social_motivation_survey";           // test_names.Test_name
        $this->table = 'toddler_social_motivation_survey';              // name of database table corresponding to instrument
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
            "/toddler_social_motivation_survey(_page[0-9]+)/",
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
        $this->addHeader("Toddler Social Motivation Questionnaire");
        $this->form->addElement('static', null, "<i><h3>*Please fill this form out with regard to your child who has enrolled in our study, NOT their older sibling with autism</i></h3>");
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
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
        $this->addHeader("Toddler Social Motivation Questionnaire");
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
                'q1' => '1. Looks at your face when you engage or speak with him/her.',
                'q2' => '2. Readily turns towards you when you call his/her name.',
                'q3' => '3. Becomes excited when he/she spots a familiar person.',
                'q4' => '4. Smiles when you or others smile at him/her.',
                'q5' => '5. Is interested in playing with other children.',
                'q6' => '6. Withdraws or resists when others attempt to engage him/her.',
                'q7' => '7. Gives items to caregivers/others.',
                'q8' => '8. Engages in back and forth interactions (for example, conversations, games, other joint activities).',
                'q9' => '9. Seems happy when you or another caregiver approaches him/her.',
                'q10' => '10. Looks up from what he/she is doing when someone attempts to engage him/her.',
                'q11' => '11. Does not mind being apart from others.',
                'q12' => '12. Attempts to initiate interactions with you or other adults.',
                'q13' => '13. Attempts to initiate interactions with other children.',
                'q14' => '14. Does not appear to notice when others are looking at him/her.',
                'q15' => '15. Tends to avoid eye contact.',
                'q16' => '16. Enjoys playful interactions.',
                'q17' => '17. Appears comfortable when with a group of people.',
                'q18' => '18. Looks with interest towards groups of people talking.',
                'q19' => '19. Responds positively when adults attempt to engage him/her.',
                'q20' => '20. Responds positively when other children approach him/her.',
                'q21' => '21. Stops what he/she is doing to watch other children play.',
                'q22' => '22. Prefers to play by him/herself versus playing with others.',
                'q23' => '23. Looks bored when in the company of others.',
                'q24' => '24. Does not seem to notice if people stop paying attention to him/her.',
                'q25' => '25. Enjoys watching you or another familiar person playfully make faces.',

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
        $this->addHeader("Toddler Social Motivation Questionnaire");
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
                'q26' => '26. Engages with you by imitating your facial expressions or sounds.',
                'q27' => '27. Smiles or laughs in anticipation of interacting with trusted adults or other children.',
                'q28' => '28. Makes eye contact and smiles when playing with you or others.',
                'q29' => '29. Wants to be a part of group activities.',
                'q30' => '30. Looks at what other people are looking at or attending to.',
                'q31' => '31. Is persistent when trying to engage someone.',
                'q32' => '32. Prefers focusing on objects over interacting with others.',
                'q33' => '33. Avoids interacting with groups of children.',
                'q34' => '34. Shows shared enjoyment during interactions.',
                'q35' => '35. Chooses to play near other children rather than keep his/her distance.',
                'q36' => '36. Seems disappointed or sad when playful interactions end.',
                'q37' => '37. Spontaneously smiles and greets you, even when engaged in another activity.',
                'q38' => '38. Seems to ignore others when they attempt to engage him/her.',
                'q39' => '39. Attempts to befriend other children, for example, by following them or asking to play.',
                'q40' => '40. Attempts to get your attention to share an event or experience with you.',
                'q41' => '41. Responds positively to you when you point out something to share interest.',
                'q42' => '42. Appears indifferent when a familiar person approaches or greets him/her.',
                'q43' => '43. Likes being praised.',
                'q44' => '44. Does not smile or laugh when you attempt to engage him/her.',
                'q45' => '45. Shows items to share interest with others.',
                'q46' => '46. Engages you for the purpose of sharing enjoyment.',
                'q47' => '47. Repeats a behavior which gets a positive response or encouragement from others.',
                'q48' => '48. Focuses intently on toys or objects but loses interest quickly during social interactions.',
                'q49' => '49. Shows affection to you and other family members.',
                'q50' => '50. Protests or attempts to re-engage you when you stop paying attention to him/her.',
                'q51' => '51. Plays cooperatively with other children.',
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


