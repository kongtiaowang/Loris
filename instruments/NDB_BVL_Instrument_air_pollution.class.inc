<?php
/**
 *
 * @category Instrument
 * @author   Gregory Luneau <gluneau.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
require_once 'HTML/QuickForm.php';
require_once 'HTML/QuickForm/Renderer/Array.php';
/**
 * Creates the form elements for the ABC instrument
 *
 * @category Instrument
 * @author   Gregory Luneau <gluneau.mcin@gmail.com>
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
        $this->form = new HTML_Quickform('test_form');
        $this->page = $page; // page label (number or string - used by user-defined child classes)

        // set the object properties
        $this->testName = 'air_pollution'; // test_names.Test_name
        $this->table = 'air_pollution'; // name of database table corresponding to instrument
        $this->commentID = $commentID; // data keyed by commentID

        $this->dateTimeFields = array('proband_birthdate', 'from1b41', 'to1b41', 'from1b42', 'to1b42', 'from1b43', 'to1b43', 'from1b44', 'to1b44', 'from1b45', 'to1b45', 'fromatb1', 'toatb1', 'fromatb2', 'toatb2', 'fromatb3', 'toatb3', 'fromatb4', 'toatb4', 'fromatb5', 'toatb5', 'fromatb6', 'toatb6');

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
        //$this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    /**
     * generates the main page of the form.
     *
     * @return void
     * @access private
     */
    function _main(){
      $this->form->addElement('header', 'instrument_title', "IBIS Environment Residential History");

      $yesNo = array(null=>"", 'yes'=>"Yes", 'no'=>"No");

      $group[] =& $this->form->createElement("select","consent", "", $yesNo);
      $this->XINRegisterRule("consent", array("code{@}=={@}"), "Required.", "consent_group");
      $this->form->addGroup($group, "consent_group", "By selecting 'Yes' from the dropdown menu, you consent to give us the information in this questionnaire.", null, false);
      unset($group);
    }

    function _page2(){
        $this->form->addElement('header', 'instrument_title', "IBIS Environment Residential History");
        $this->form->addElement('header', 'instrument_inst1','</b><h5>We would like to know the home addresses of biological mothers starting one year before the birth of your child. Having these addresses will help us study how prenatal exposures, such as air pollution, affect children’s development. ' . 
          '<br><br> Please start with your main residence at the time of your child’s birth and end with the residence where you lived one year before your child’s birth. On Section 2, we ask where your child lived when he or she turned 3 YEARS old back to birth.</h5><b>');
       
        $this->form->addElement("static", null, '<div id="sjcl"><script type="text/javascript" src="/js/sjcl.js"></script></div>');

        $this->form->addElement("text", 'code', "Code (see email)", array("class" => "remove required"));
        $this->form->addElement("text", 'proband_name_remove', "Name of younger child enrolled in IBIS", array("class" => "encrypt required"));
 

        $dateOptions = array(
            'language'       => 'en',
            'format'         => 'YMd',
            'addEmptyOption' => true
        );
        
        $dateOptionsYM = array(
            'language'       => 'en',
            'format'         => 'YM',
            'addEmptyOption' => true
        );

        $this->addBasicDate('proband_birthdate', 'Birth date of younger child enrolled in IBIS', $dateOptions);

        // Address Mom 1
        $this->form->addElement('header', 'instrument_title', "<h5>MOM’s Home at child’s birth #1</h5>");
        $this->addCheckbox('living1yb4m1', 'Check if you were living here 1 year before child’s birth');

        $this->form->addElement("text", 'address_line1m1_remove', "Address (Line 1)", array("class" => "encrypt required"));
        $this->form->addElement("text", 'address_line2m1_remove', "Address (Line 2)", array("class" => "encrypt"));
        $this->form->addElement("text", 'citym1_remove', "City", array("class" => "encrypt required"));
        $this->form->addElement("text", 'statem1_remove', "State", array("class" => "encrypt required"));
        $this->form->addElement("text", 'zip_codem1_remove', "Zip Code", array("class" => "encrypt required"));

        $this->addMonthYear('from1b41', 'From', $dateOptionsYM);
        $this->addMonthYear('to1b41', 'To', $dateOptionsYM);
        $this->addCheckbox('livinghere3bd1', 'Check if you were living here at the time of child’s 3rd birthday');
     
        
        // Address Mom 2-5
        for ($i=2; $i<6; $i++)
        {
            $this->form->addElement('header', 'instrument_title', "<h5>MOM’s Home Previous #" . $i . "</h5>");
            $this->addCheckbox('living1yb4m' . $i, 'Check if you were living here 1 year before child’s birth');

            $this->form->addElement("text", 'address_line1m'. $i .'_remove', "Address (Line 1)", array("class" => "encrypt"));
            $this->form->addElement("text", 'address_line2m'. $i .'_remove', "Address (Line 2)", array("class" => "encrypt"));
            $this->form->addElement("text", 'citym'. $i .'_remove', "City", array("class" => "encrypt"));
            $this->form->addElement("text", 'statem'. $i .'_remove', "State", array("class" => "encrypt"));
            $this->form->addElement("text", 'zip_codem'. $i .'_remove', "Zip Code", array("class" => "encrypt"));

            $this->addMonthYear('from1b4' . $i, 'From', $dateOptionsYM);
            $this->addMonthYear('to1b4' . $i, 'To', $dateOptionsYM);
        }
        
        
        // Section 2        
        // BABY’s Home 0
        $this->form->addElement('header', 'instrument_instruction', '<h5>Section 2 <br><br> We would like to know all the addresses where your child lived until turning AGE 3. Please start below with the address where your child lived on his or her 3rd BIRTHDAY.  Then, list your child’s previous addresses, back until the date of your child’s birth.   If your child was in shared custody, please list both home addresses.</h5><b>');

        $this->form->addElement('header', 'instrument_title', "<h5>Child’s home address on his or her 3rd Birthday #1</h5>");
        $this->addCheckbox('livingatb1', 'Check if this address was your child’s main home at time of birth');

        $this->form->addElement("text", 'address_line1b1_remove', "Address (Line 1)", array("class" => "encrypt required"));
        $this->form->addElement("text", 'address_line2b1_remove', "Address (Line 2)", array("class" => "encrypt"));
        $this->form->addElement("text", 'cityb1_remove', "City", array("class" => "encrypt required"));
        $this->form->addElement("text", 'stateb1_remove', "State", array("class" => "encrypt required"));
        $this->form->addElement("text", 'zip_codeb1_remove', "Zip Code", array("class" => "encrypt required"));

        $this->addMonthYear('fromatb1', 'From', $dateOptionsYM);
        $this->addMonthYear('toatb1', 'To', $dateOptionsYM);      
     
        
        // BABY’s Home 2-6
        for ($i=2; $i<7; $i++)
        {        
            $this->form->addElement('header', 'instrument_title', "<h5>Child’s home address previous to his or her 3rd Birthday #". $i ."</h5>");
            $this->addCheckbox('livingatb' . $i, 'Check if this address was your child’s main home at time of birth');

            $this->form->addElement("text", 'address_line1b'. $i .'_remove', "Address (Line 1)", array("class" => "encrypt"));
            $this->form->addElement("text", 'address_line2b'. $i .'_remove', "Address (Line 2)", array("class" => "encrypt"));
            $this->form->addElement("text", 'cityb'. $i .'_remove', "City", array("class" => "encrypt"));
            $this->form->addElement("text", 'stateb'. $i .'_remove', "State", array("class" => "encrypt"));
            $this->form->addElement("text", 'zip_codeb'. $i .'_remove', "Zip Code", array("class" => "encrypt"));
            $this->addMonthYear('fromatb' . $i, 'From', $dateOptionsYM);
            $this->addMonthYear('toatb' . $i, 'To', $dateOptionsYM);    
        }
        
                       
        // Comment section
        $this->form->addElement('header', 'instrument_title', "IBIS Environment Residential History");
        $this->addTextAreaElement('additional_comments', 'Additional Comments');

        $this->form->addElement("static", null, '<div id="air_pollution"><script type="text/javascript" src="/js/air_pollution.js"></script></div>');
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
        return;
    }
}
