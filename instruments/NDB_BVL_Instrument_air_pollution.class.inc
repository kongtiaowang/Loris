<?php
/**
 *
 * @category Instrument
 * @author   Stella Lee <slee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
require_once 'HTML/QuickForm.php';
require_once 'HTML/QuickForm/Renderer/Array.php';
/**
 * Creates the form elements for the ABC instrument
 *
 * @category Instrument
 * @author   Stella Lee <slee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_air_pollution extends NDB_BVL_Instrument
{

    /**
     * Sets up basic data, such as the HTML_Quickform object, and so on.
     *
     * @param  string $commentID the CommentID identifying the data to load
     * @param  string $page if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup($commentID, $page)
    {
        $this->formType = 'XIN';
        $this->form = new HTML_Quickform('air_pollution');
        $this->page = $page; // page label (number or string - used by user-defined child classes)

        // set the object properties
        $this->testName = 'air_pollution'; // test_names.Test_name
        $this->table = 'air_pollution'; // name of database table corresponding to instrument
        $this->commentID = $commentID; // data keyed by commentID

        $config = NDB_Config::singleton();
        $this->dateOptions = array(
            'language' => 'en',
            'format' => 'YMd',
            'minYear' => $config->getSetting('startYear'),
            'maxYear' => $config->getSetting('endYear'),
            'addEmptyOption' => true,
            'emptyOptionValue' => null
        );

        // setup the form
        $this->_setupForm();
    }

    /**
     * method to build the HTML_Quickform object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        //determine page to display
        if (preg_match("/air_pollution(_page[0-9]+)/", $this->page, $matches)) {
            call_user_method($matches[1], $this);
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
     */
    function _main()
    {
        $group[] =& $this->form->createElement("text", 'code', "");
        $this->XINRegisterRule("code", array("code{@}=={@}"), "Required.", "code_group");
        $this->form->addGroup($group, "code_group", 'Code (see email)', null, false);
        unset($group);

        $group[] =& $this->form->createElement("text", 'name', "");
        $this->XINRegisterRule("name", array("name{@}=={@}"), "Required.", "name_group");
        $this->form->addGroup($group, "name_group", 'Name', null, false);
        unset($group);

        $this->addBasicDate('Date_taken', 'Date', null, false);

    }

    function _page2()
    {

        $group[]=&$this->form->createElement("text", 'address_line1', "");
        $this->XINRegisterRule("address_line1", array("address_line1{@}=={@}"), "Required.", "address_line1_group");
        $this->form->addGroup($group, "address_line1_group", 'Address (Line 1)', null, false);
        unset($group);

        $group[]=&$this->form->createElement("text", 'address_line2', "");
        $this->XINRegisterRule("address_line2", array("address_line2{@}=={@}"), "Required.", "address_line2_group");
        $this->form->addGroup($group, "address_line2_group", 'Address (Line 2)', null, false);
        unset($group);

        $group[]=&$this->form->createElement("text", 'city', "");
        $this->XINRegisterRule("city", array("city{@}=={@}"), "Required.", "city_group");
        $this->form->addGroup($group, "city_group", 'City', null, false);
        unset($group);

        $group[]=&$this->form->createElement("text", 'state', "");
        $this->XINRegisterRule("state", array("state{@}=={@}"), "Required.", "state_group");
        $this->form->addGroup($group, "state_group", 'State', null, false);
        unset($group);

        $group[]=&$this->form->createElement("text", 'zip_code', "");
        $this->XINRegisterRule("zip_code", array("zip_code{@}=={@}"), "Required.", "zip_code_group");
        $this->form->addGroup($group, "zip_code_group", 'Zip Code', null, false);
        unset($group);

        $this->addTextAreaElement('additional_comments', 'Additional Comments');
//        $this->XINRegisterRule('additional_comments', array("additional_comments{@}=={@}NEVER_REQUIRED"));
    }

    /**
     * Return the HTML for the review section of the survey module
     * By default, this will show every question from the parameter_type
     * table for this instrument, but it can be overridden/customized by
     * a instrument if that isn't the desired behaviour.
     *
     * @return string The HTML to be inserted into the review section of
     *                the final page of the survey module for this instrument.
     */
    function getReview()
    {
        $DB = Database::singleton();

        $smarty   = new Smarty_neurodb();
        $tpl_data = array();

        $tpl_data['questions'] = $DB->pselect(
            "SELECT Description as question,
            SourceField FROM parameter_type
            WHERE SourceFrom=:TN AND
            SourceField NOT IN ('Validity', 'Administration')",
            array('TN' => $this->testName)
        );

        $Responses = $DB->pselectRow(
            "SELECT * FROM " . $this->testName . " WHERE CommentID=:CID",
            array('CID' => $this->getCommentID())
        );

        foreach ($tpl_data['questions'] as &$row) {
            if (isset($Responses[$row['SourceField']])) {
                $row['response'] = $Responses[$row['SourceField']];
            }
        }

        $smarty->assign($tpl_data);
        $html = $smarty->fetch("directentry_review.tpl");
        return $html;
    }
}