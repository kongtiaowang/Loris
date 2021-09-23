<?php
/**
 * This file contains the NDB_BVL_Instrument_QRS_Proband class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the QRS_Proband instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_QRS_Proband extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    var $ValidityRequired = false;
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
        $this->form     = new LorisForm('QRS_Proband_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "QRS_Proband";           // test_names.Test_name
        $this->table    = 'QRS_Proband';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

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
        //determine page to display
        if (preg_match(
            "/QRS_Proband(_page[0-9]+)/",
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
     * Generates the main page of the form.
     *
     * @return void
     * @access private
     */
    function _main()
    {
        // display test name
        $this->addHeader("QRS - Proband (Questionnaire on Resources and Stress - Proband) - Survey");
        $config      =& NDB_Config::singleton();
        $dateOptions = array(
                        'language'         => 'en',
                        'format'           => 'YMd',
                        'minYear'          => $config->getSetting('startYear'),
                        'maxYear'          => $config->getSetting('endYear'),
                        'addEmptyOption'   => true,
                        'emptyOptionValue' => null,
                       );

        $this->form->addElement('static', null, "<i>*Please fill this form out with regard to your older child who has autism.</i>");

        $this->dateOptions = $dateOptions;

        $this->addBasicDate('Date_taken', 'Date of Administration', $dateOptions);
        $opts = array(
                 null          => "",
                 "mother"      => "Mother",
                 "father"      => "Father",
                 "step_mother" => "Step Mother",
                 "step_father" => "Step Father",
                 "other"       => "Other",
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
        $this->addHeader("QRS - Proband (Questionnaire on Resources and Stress - Proband) - Survey");

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            "<b>Instructions:</b>
            <br><br>
            <i>*Please fill this form out with regard to your older child who has autism.</i>
            <br><br>
            This questionnaire deals with your thoughts and opinions about
            you and your family.
            <br>
            Please respond to each question by picking only one of the
            four ratings, using the following scheme.
            <br><br>
            $this->indent 1 = <b><u>Strong agreement</u></b> with the statement.<br>

            $this->indent 2 = <b><u>Partial agreement</u></b> with the statement.<br>

            $this->indent 3 = <b><u>Partial disagreement</u></b> with the statement.<br>

	    $this->indent 4 = <b><u>Strong disagreement</u></b> with the statement.
	    <br><br>
	    Example: The family eats dinner together. 1 2 3 4
            <br><br>
            If the family always or almost always eats dinner together, the
            statement made is accurate, therefore you would <b>pick 1</b> to show
            that you strongly agree with it. If the family has dinner together
            frequently, you would <b>pick 2</b>, showing that you partly agree.
            If the family never or rarely has dinner together, then the statement
            is inaccurate and you would <b>pick 4</b>, showing that you strongly
            disagree. If, on the other hand, the family has dinner together sometimes,
            but less than 50% of the time, you would <b>circle 3</b>, indicating
	    that you partly disagree.
	    <br><br>
	    Please answer all questions, even if they do not seem to apply. The questions are general, 
            and sometimes refer to children who have characteristics that your child may not have. 
            In such instances you can still answer by circling 4, that is, strong disagreement with the statement.<br><br>"
        );

        $options = array(
                    null => "",
                    1    => "1 Strong agreement with the statement. ",
                    2    => "2 Partial agreement with the statement.",
                    3    => "3 Partial disagreement with the statement",
                    4    => "4 Strong disagreement with the statement",
                   );

        $options_na = array(
                       null => "",
                       1    => "1 Strong agreement with the statement. ",
                       2    => "2 Partial agreement with the statement.",
                       3    => "3 Partial disagreement with the statement",
                       4    => "4 Strong disagreement with the statement",
                       'na' => "Not Applicable",
                      );

        $page1_questions = array(
                            "q1"  => "1. My child demands that others do things for him/her more than is necessary.",
                            "q2"  => "2. My child understands the idea of time.",
                            "q3"  => "3. I have had to give up education (or a job) because of my child.",
                            "q4"  => "4. Members of the family share in the care of my child.",
                            "q5"  => "5. Even if people don't look at my child, I am always wondering what they might think.",
                            "q6"  => "6. My child does not have problems with seeing or hearing.",
                            "q7"  => "7. I take on responsibility for my child because I know how to deal with him/her.",
                            "q8"  => "8. My child has some unusual habits which draw attention.",
                            "q9"  => "9. A physician sees my child at least once a month.",
                            "q10" => "10. The special opportunities needed by my child are available in our community.",
                            "q11" => "11. I watch my child to make sure he/she does not do physical harm to himself/herself or others.",
                            "q12" => "12. My child would be in no danger if he/she could get out of the house or yard.",
                            "q13" => "13. I feel that our family situation will get better.",
                            "q14" => "14. Medicine does not have to be given to my child.",
                            "q15" => "15. My child doesn't communicate with others of his/her age group.",
                            "q16" => "16. Other members of the family have to do without things because of my child.",
                            "q17" => "17. My child's problems or illnesses do not stand in the way of our family progress.",
                            "q18" => "18. When others are around my child I cannot relax; I am always on guard.",
                            "q19" => "19. Professionals (nurses, etc.) in an institution would not understand my child better
                            than I do",
                            "q20" => "20. I worry about what will happen to my child when I can no longer take care of him/her.",
                            "q21" => "21. I would rather be caring for my child than doing some other kind of work.",
                            "q22" => "22. I have given up things I have really wanted to do in order to care for my child.",
                            "q23" => "23. My child is able to fit into the family social group.",
                            "q24" => "24. Some members of my family don't like the way I do things.",
                            "q25" => "25. It appears to me that it doesn't make any difference to my child if he/she is
                            with me or a stranger.",
                           );

        foreach ($page1_questions as $question => $label) {
            if ($question == 'q13') {
                $this->addSelect(
                    $question,
                    $label,
                    $options_na
                );
            } else {
                $this->addSelect(
                    $question,
                    $label,
                    $options
                );
            }
        }
    }


    /**
    * Generates the second page of the form.
    *
    * @return void
    */
    function _page2()
    {
        $this->addHeader("QRS - Proband (Questionnaire on Resources and Stress - Proband) - Survey");

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            "$this->indent 1 = <b><u>Strong agreement</u></b> with the statement.<br>

            $this->indent 2 = <b><u>Partial agreement</u></b> with the statement.<br>

	    $this->indent 3 = <b><u>Partial disagreement</u></b> with the statement.<br>

            $this->indent 4 = <b><u>Strong disagreement</u></b> with the statement.<br><br>"
        );

        $options = array(
                    null => "",
                    1    => "1 Strong agreement with the statement.",
                    2    => "2 Partial agreement with the statement.",
                    3    => "3 Partial disagreement with the statement.",
                    4    => "4 Strong disagreement with the statement.",
                   );

        $page2_questions = array(
                            "q26" => "26. My child knows the difference between strangers and friends.",
                            "q27" => "27. I am afraid that other members of the family will be hurt because they
                            are related to my child.",
                            "q28" => "28. I avoid taking my child out in public.",
                            "q29" => "29. People simply don't understand what it is like to live with my child.",
                            "q30" => "30. My child can feed himself/herself.",
                            "q31" => "31. There have been no emotional problems for anyone in our family.",
                            "q32" => "32. Our relatives have been helpful.",
                            "q33" => "33. It is easier for me to do something for my child than to let him/her do it himself/herself and make a mess.",
                            "q34" => "34. My child is easy to manage.",
                            "q35" => "35. I feel that I must protect my child from the remarks of children.",
                            "q36" => "36. I have difficulty in leaving the house because of my child.",
                            "q37" => "37. The community is used to people like my child.",
                            "q38" => "38. Some friends are helpful when it comes to my child.",
                            "q39" => "39. The family does as many things together now as we ever did.",
                            "q40" => "40. My child knows his/her address.",
                            "q41" => "41. My child is aware of who he/she is (for example, male, 14 years old).",
                            "q42" => "42. My spouse's poor understanding of my child's difficulties has been a source of stress to me.",
                            "q43" => "43. I feel embarrassed because of my child.",
                            "q44" => "44. Having to care for my child has enriched our family life.",
                            "q45" => "45. It makes me feel good to know I can take care of my child.",
                            "q46" => "46. My child does not interfere with our family's enjoyment of meals.",
                            "q47" => "47. I do not have enough time to give the other members of the family.",
                            "q48" => "48. There are places where we can enjoy ourselves as a family when my child comes along.",
                            "q49" => "49. It is not hard to think of enough things to keep my child busy.",
                            "q50" => "50. My child is over-protected.",
                            "q51" => "51. Some of our family do not bring friends into the home because of my child.",
                           );

        foreach ($page2_questions as $question => $label) {
             $this->addSelect(
                 $question,
                 $label,
                 $options
             );
        }
    }

    /**
    * Generates the third page of the form.
    *
    * @return void
    */
    function _page3()
    {
        $this->addHeader("QRS - Proband (Questionnaire on Resources and Stress - Proband) - Survey");

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            "$this->indent 1 = <b><u>Strong agreement</u></b> with the statement.<br>

            $this->indent 2 = <b><u>Partial agreement</u></b> with the statement.<br>

            $this->indent 3 = <b><u>Partial disagreement</u></b> with the statement.<br>

            $this->indent 4 = <b><u>Strong disagreement</u></b> with the statement.<br><br>"
        );

        $options = array(
                    null => "",
                    1    => "1 Strong agreement with the statement.",
                    2    => "2 Partial agreement with the statement.",
                    3    => "3 Partial disagreement with the statement.",
                    4    => "4 Strong disagreement with the statement.",
                   );

        $options_na = array(
                       null => "",
                       1    => "1 Strong agreement with the statement.",
                       2    => "2 Partial agreement with the statement.",
                       3    => "3 Partial disagreement with the statement.",
                       4    => "4 Strong disagreement with the statement.",
                       'na' => "Not Applicable",
                      );

        $page3_questions = array(
                            "q52" => "52. I participate in an organization for families who share our problems.",
                            "q53" => "53. If I were healthier it would be easier to care for my child.",
                            "q54" => "54. People in public places indicate they don't want my child around.",
                            "q55" => "55. My child can get around the neighborhood quite nicely.",
                            "q56" => "56. I have enough time to myself.",
                            "q57" => "57. I have too much responsibility.",
                            "q58" => "58. I am afraid that as my child gets older it will be harder to manage him/her.",
                            "q59" => "59. It is easy to keep my child entertained.",
                            "q60" => "60. My child wants to do things for himself/herself.",
                            "q61" => "61. I feel sad when I think of my child.",
                            "q62" => "62. The demands to care for my child limit my growth and development.",
                            "q63" => "63. I have become more understanding in my relationships with people as a result of my child.",
                            "q64" => "64. Our family should do more together.",
                            "q65" => "65. Caring for my child puts a strain on me.",
                            "q66" => "66. Members of our family get to do the same kinds of things other families do.",
                            "q67" => "67. My child embarrasses others in our family.",
                            "q68" => "68. The demands my child makes drive me out of my mind.",
                            "q69" => "69. My family understands the problems I have.",
                            "q70" => "70. I often have the desire to protect my child.",
                            "q71" => "71. My child's care falls on me.",
                            "q72" => "72. No one can understand what I go through.",
                            "q73" => "73. All members of the family are involved in household chores.",
                            "q74" => "74. My child is irritable.",
                            "q75" => "75. We have lost friends because of my child.",
                            "q76" => "76. I am worried much of the time.",
                            "q77" => "77. My child's needs come first.",
                            "q78" => "78. My spouse has a great deal of insight into my child's difficulties.",
                           );

        foreach ($page3_questions as $question => $label) {
            if ($question == 'q59') {
                $this->addSelect(
                    $question,
                    $label,
                    $options_na
                );
            } else {
                $this->addSelect(
                    $question,
                    $label,
                    $options
                );
            }
        }
    }
}
?>
