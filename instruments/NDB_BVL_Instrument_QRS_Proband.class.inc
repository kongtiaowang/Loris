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
    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page      if a multipage form, the page to show
     *
     * @return void
     * @access public
     */
    function setup($commentID, $page)
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

        // required fields for data entry completion status
        $this->_requiredElements = array('CommentID');

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

        $this->form->addElement('static', null, "<i><h3>*Please fill this form out with regard to your older child who has autism.</i></h3>");

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
        $this->addHeader(
            "<h3>INSTRUCTIONS</h3><br>
                         <h4>This questionnaire deals with your thoughts and opinions about
                         you and your family. There are many blanks on the questionnaire. We would like
                         you to imagine your child's name on them.<br>
                         Please respond to each question by picking only one of the
                         four ratings, using the following scheme.<br></h4>
                         <h5><b>1 = Strong agreement with the statement.</b><br>
                         <b>2 = Partial agreement with the statement.</b><br>
                         <b>3 = Partial disagreement with the statement.</b><br>
                         <b>4 = Strong disagreement with the statement.</b></h5>
                         <h4>If the family always or almost always eats dinner together, the
                              statement made is accurate, therefore you would <b>pick 1</b> to show
                              that you strongly agree with it. If the family has dinner together
                              frequently, you would <b>pick 2</b>, showing that you partly agree.
                              If the family never or rarely has dinner together, then the statement
                              is inaccurate and you would <b>pick 4</b>, showing that you strongly
                              disagree. If, on the other hand, the family has dinner together sometimes,
                              but less than 50% of the time, you would <b>circle 3</b>, indicating
                              that you partly disagree.</h4>"
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
                            "q1"  => "1. ___ demands that others do things for him/her more than is necessary.",
                            "q2"  => "2. ___ understands the idea of time.",
                            "q3"  => "3. I have had to give up education (or a job) because of ___.",
                            "q4"  => "4. Members of the family share in the care of ___.",
                            "q5"  => "5. Even if people don't look at ___, I am always wondering what they might think.",
                            "q6"  => "6. ___ does not have problems with seeing or hearing.",
                            "q7"  => "7. I take on responsibility for ___ because I know how to deal with him/her.",
                            "q8"  => "8. ___ has some unusual habits which draw attention.",
                            "q9"  => "9. A physician sees ___ at least once a month.",
                            "q10" => "10. The special opportunities needed by ___ are available in our community.",
                            "q11" => "11. I watch ___ to make sure he/she does not do physical harm to himself/herself or others.",
                            "q12" => "12. ___ would be in no danger if he/she could get out of the house or yard.",
                            "q13" => "13. I feel that our family situation will get better.",
                            "q14" => "14. Medicine does not have to be given to ___.",
                            "q15" => "15. ___ doesn't communicate with others of his/her age group.",
                            "q16" => "16. Other members of the family have to do without things because of ___.",
                            "q17" => "17. ___'s problems or illnesses do not stand in the way of our family progress.",
                            "q18" => "18. When others are around ___ I cannot relax; I am always on guard.",
                            "q19" => "19. Professionals (nurses, etc.) in an institution would not understand ___ better
                            than I do",
                            "q20" => "20. I worry about what will happen to ___ when I can no longer take care of him/her.",
                            "q21" => "21. I would rather be caring for ___ than doing some other kind of work.",
                            "q22" => "22. I have given up things I have really wanted to do in order to care for ___.",
                            "q23" => "23. ___ is able to fit into the family social group.",
                            "q24" => "24. Some members of my family don't like the way I do things.",
                            "q25" => "25. It appears to me that it doesn't make any difference to ___ if he/she is
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
        $this->addHeader(
            "QRS - Proband (Questionnaire on Resources and Stress - Proband) - Survey<br>
            <h5><b>1 = Strong agreement with the statement.</b><br>
            <b>2 = Partial agreement with the statement.</b><br>
            <b>3 = Partial disagreement with the statement.</b><br>
            <b>4 = Strong disagreement with the statement.</b></h5>"
        );

        $options = array(
                    null => "",
                    1    => "1 Strong agreement with the statement.",
                    2    => "2 Partial agreement with the statement.",
                    3    => "3 Partial disagreement with the statement.",
                    4    => "4 Strong disagreement with the statement.",
                   );

        $page2_questions = array(
                            "q26" => "26. ___ knows the difference between strangers and friends.",
                            "q27" => "27. I am afraid that other members of the family will be hurt because they
                            are related to ___.",
                            "q28" => "28. I avoid taking ___ out in public.",
                            "q29" => "29. People simply don't understand what it is like to live with ___.",
                            "q30" => "30. ___ can feed himself/herself.",
                            "q31" => "31. There have been no emotional problems for anyone in our family.",
                            "q32" => "32. Our relatives have been helpful.",
                            "q33" => "33. It is easier for me to do something for ___ than to let him/her do it himself/herself and make a mess.",
                            "q34" => "34. ___ is easy to manage.",
                            "q35" => "35. I feel that I must protect ___ from the remarks of children.",
                            "q36" => "36. I have difficulty in leaving the house because of ___.",
                            "q37" => "37. The community is used to people like ___.",
                            "q38" => "38. Some friends are helpful when it comes to ___.",
                            "q39" => "39. The family does as many things together now as we ever did.",
                            "q40" => "40. ___ knows his/her address.",
                            "q41" => "41. ___ is aware of who he/she is (for example, male, 14 years old).",
                            "q42" => "42. My spouse's poor understanding of ___'s difficulties has been a source of stress to me.",
                            "q43" => "43. I feel embarrassed because of ___.",
                            "q44" => "44. Having to care for ___ has enriched our family life.",
                            "q45" => "45. It makes me feel good to know I can take care of ___.",
                            "q46" => "46. ___ does not interfere with our family's enjoyment of meals.",
                            "q47" => "47. I do not have enough time to give the other members of the family.",
                            "q48" => "48. There are places where we can enjoy ourselves as a family when ___ comes along.",
                            "q49" => "49. It is not hard to think of enough things to keep ___ busy.",
                            "q50" => "50. ___ is over-protected.",
                            "q51" => "51. Some of our family do not bring friends into the home because of ___.",
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
        $this->addHeader(
            "QRS - Proband (Questionnaire on Resources and Stress - Proband) - Survey<br>
            <h5><b>1 = Strong agreement with the statement.</b><br>
            <b>2 = Partial agreement with the statement.</b><br>
            <b>3 = Partial disagreement with the statement.</b><br>
            <b>4 = Strong disagreement with the statement.</b></h5>"
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
                            "q53" => "53. If I were healthier it would be easier to care for ___.",
                            "q54" => "54. People in public places indicate they don't want ___ around.",
                            "q55" => "55. ___ can get around the neighborhood quite nicely.",
                            "q56" => "56. I have enough time to myself.",
                            "q57" => "57. I have too much responsibility.",
                            "q58" => "58. I am afraid that as ___ gets older it will be harder to manage him/her.",
                            "q59" => "59. It is easy to keep ___ entertained.",
                            "q60" => "60. ___ wants to do things for himself/herself.",
                            "q61" => "61. I feel sad when I think of ___.",
                            "q62" => "62. The deamnds to care for ___ limit my growth and development.",
                            "q63" => "63. I have become more understanding in my relationships with people as a result of ___.",
                            "q64" => "64. Our family should do more together.",
                            "q65" => "65. Caring for ___ puts a strain on me.",
                            "q66" => "66. Members of our family get to do the same kinds of things other families do.",
                            "q67" => "67. ___ embarrasses others in our family.",
                            "q68" => "68. The demands ___ makes drive me out of my mind.",
                            "q69" => "69. My family understands the problems I have.",
                            "q70" => "70. I often have the desire to protect ___.",
                            "q71" => "71. ___'s care falls on me.",
                            "q72" => "72. No one can understand what I go through.",
                            "q73" => "73. All members of the family are involved in household chores.",
                            "q74" => "74. ___ is irritable.",
                            "q75" => "75. We have lost friends because of ___.",
                            "q76" => "76. I am worried much of the time.",
                            "q77" => "77. ___'s needs come first.",
                            "q78" => "78. My spouse has a great deal of insight into ___'s difficulties.",
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