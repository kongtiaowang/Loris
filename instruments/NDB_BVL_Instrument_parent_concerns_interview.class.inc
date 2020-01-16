<?php
/**
 * This file contains the code for the Biosample Collection Instrument
 *
 * PHP Version 5
 *
 * @category Main
 * @package  Behavioural
 * @author   Tara Campbell <tara.campbell@mail.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris-Trunk/
 */

/**
 * This file contains the code for the parent concern interview Instrument
 *
 * @category Main
 * @author   Rida Abou-Haidar
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */
class NDB_BVL_Instrument_parent_concerns_interview extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityEnabled = false;
    var $ValidityRequired = false;
    /**
     * sets up basic data, such as the HTML_Quickform object, and so on.
     *
     * @param string $commentID  the CommentID identifying the data to load
     * @param string $page       if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType="XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;            // page label (number or
        // set the object properties
        $this->testName = "parent_concerns_interview";
        $this->table = 'parent_concerns_interview';
        // data keyed by commentID
        $this->commentID = $commentID;
                   // setup the form
        $this->_setupForm();
    }
    /**
     * method to build the HTML_Quickform object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm(){
        if (preg_match("/parent_concerns_interview(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }
    /**
     * generates the main page of the form.
     *
     * @return void
     * @access private
     *
     */
    function _main(){
        $this->addHeader("Parent concerns associated with having an infant at ".
            "high risk for ASD <br>Part Two (V03 or V06)");
        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
        $this->addLabel(
            "<h3>**Please create and audio or video recording of this ".
            "interview for future transcription. Ensure that the parent ".
            "responses can be heard.**</h3>"
        );
        $this->addBasicTextArea(
            "q1_understanding",
            "1. What do you understand about the study we ".
            "are doing and our reasons for studying younger, infant brothers ".
            "and sisters of older children with autism ?"
        );
        $this->addLabel(
            "$this->indent <h4><b>Skip to question #2 if ‘risk’ is mentioned by the ".
            "parent.</b></h4>"
        );
        $this->addLabel(
            "In this study we are examining the early brain and behavior ".
            "development of younger children who have older brothers or sisters ".
            "with autism. <br>
            There has been some research done on subsequently born children".
            " after the birth of an older child with autism."
        );
        $this->addBasicText(
            "q1a_understanding_research",
            "1a. Do you know anything about this?"
        );
        $this->addLabel(
            "<h4><b>If 'Risk' is mentioned by the parent in Question #1, ".
            "or after asking Question #1a:</b></h4>"
        );
        $this->addBasicTextArea(
            "q2_familiar_risk",
            "2. How familiar are you with the information about 'risk' to your ".
            "later born child ?"
        );
        $this->addBasicTextArea(
            "q3_risk_effect",
            "3. How has the information you know about risk affected you and ".
            "your family?"
        );
        $this->addYesNoElement(
            "q4_worry",
            "4. In general, are you worried about your youngest child?"
        );
        $this->addBasicTextArea(
            "q4yes_worry",
            "If so, please describe these worries.",
            $rules = array("q4_worry{@}=={@}yes")
        );
        $this->addBasicTextArea(
            "q4no_worry",
            "If not, have you been in the past? When did that change?",
            $rules = array("q4_worry{@}=={@}no")
        );
        $this->addBasicTextArea(
            "q5_worry_affect_family",
            "5. How do your concerns affect you and your family?"
        );
        $this->addBasicTextArea(
            "q6_initial_thoughts_v1",
            "6. What are your initial thoughts, concerns, feelings about the ".
            "information you have received during this visit?"
        );
        $this->addLabel(
            "END OF FIRST VISIT SECTION"
        );
    }
    /**
     * parent concerns interview page 1
     *
     * @return void
     */
    function _page1()
    {
        $this->addHeader("Parent concerns associated with having an infant at ".
            "high risk for ASD<br>Part Two (V12 or V15)");
        $this->addBasicTextArea(
            "q7_past_visit_info",
            "7. Tell me about the information you received at your last visit ".
            "with us. What effects did that information have on you and your ".
            "family over the past # months?
"
        );
        $this->addBasicTextArea(
            "q8_initial_thoughts_v2",
            "8. What are your initial thoughts, concerns, feelings about the ".
            "information received during this visit?"
        );
    }
    /**
     * parent concerns interview page 2
     *
     * @return void
     */
    function _page2()
    {
        $this->addHeader("Parent concerns associated with having an infant at ".
            "high risk for ASD<br>*EXAMINER RATING*");
        $concernOptions = array(
            "" => "",
            "1_no" => "1. No concern",
            "2_little" => "2. Some concern",
            "3_high" => "3. High concern",
            "4_very_high" => "1. Very high concern"
        );
        $understandingOptions = array(
            "" => "",
            "1_no" => "1. No understanding",
            "2_little" => "2. Some understanding",
            "3_high" => "3. Good understanding",
            "4_very_high" => "1. Very strong understanding"
        );
        $copingOptions = array(
            "" => "",
            "1_no" => "1. Not coping well at all",
            "2_little" => "2. Barely coping",
            "3_high" => "3. Coping well",
            "4_very_high" => "1. Coping very well"
        );
        $this->addSelect(
            "examiner_concern_rating",
            "1. Rate the level of concern this parent seems to have about ".
            "their youngest child",
            $concernOptions
        );
        $this->addSelect(
            "examiner_understanding_rating",
            "2. Rate how well the parent seems to understand the risk ".
            "associated with having an older child with autism",
            $understandingOptions
        );
        $this->addSelect(
            "examiner_coping_rating",
            "3. How do you think the family is coping with having a child ".
            "at risk for autism?",
            $copingOptions
        );
    }
}