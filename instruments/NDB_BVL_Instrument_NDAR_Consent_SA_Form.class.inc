<?php
/**
 *
 * @category Instrument
 * @author   Gregory Luneau <gluneau.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for NDAR_Consent_SA_Form
 *
 * @category Instrument
 * @author   Sruthy Mathew <sruthy.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_NDAR_Consent_SA_Form extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param  string $commentID the CommentID identifying the data to load
     * @param  string $page if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = 'XIN';
        $this->form = new LorisForm('test_form');
        $this->page = $page; // page label (number or string - used by user-defined child classes)

        // set the object properties
        $this->testName = 'NDAR_Consent_SA_Form'; // test_names.Test_name
        $this->table = 'NDAR_Consent_SA_Form'; // name of database table corresponding to instrument
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


        if ($commentID!='' || $commentID!=NULL) {
            $timepoint =& TimePoint::singleton($this->getSessionID());
            $candidate =& Candidate::singleton($timepoint->getCandID());
            $this->candID = $candidate->getData('CandID');
            $this->centerID = $candidate->getData('RegistrationCenterID');
            $this->siteName = Site::singleton($this->centerID)->getCenterName();
        }


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
        if (preg_match("/NDAR_Consent_SA_Form(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for LorisForm to use when validating the form.
        //$this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    /**
     * generates the main page of the form.
     *
     * @return void
     * @access private
     */
    function _main()
    {
        $this->form->addElement('header', 'instrument_title', "NDAR Consent SA Form");

        $yesNo = array(null => "", 'yes' => "Yes", 'no' => "No");
        $this->form->addElement("hidden", "commentId", $this->commentID);

        $this->form->addElement('static', 'lorisSubHeader', "<center><embed src='../images/NDAR_Consent_SA.pdf' width=\"800px\" height=\"600px\" /></center>");

              $group[] =& $this->form->createElement("select", "NDAR_consent_SA", "", $yesNo);
              $this->form->addGroup($group, "NDAR_consent_SA_group", "By selecting 'Yes' you agree to the above information and give your consent.", null, false);
              unset($group);

              $this->form->addElement("static", null, '<div id="NDAR_consent_SA_Form"><script type="text/javascript" src="/js/ndar_consent_sa.js"></script></div>');
      }
    function _page2(){

        if($this->getConsentVal()=='yes')
        {
            $text="</b><h5>Thank you for agreeing to participate in this very important study!</h5>";
        }
        if($this->getConsentVal()=='no')
        {
            $text="</b><h5>Thank you for your time!</h5>";
        }
        $this->form->addElement('hidden', 'data_collection', "Remote");

        $this->form->addElement('header', 'instrument_title_main', 'IBIS School Age Study -Consent Form');
        $this->form->addElement('header', 'instrument_inst1',$text);
        $this->form->addElement("static", null, '<div id="sa_consent"><script type="text/javascript" src="/js/ndar_consent_sa_final_submit.js"></script></div>');

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
    function getReview(): string
    {
        return '';
    }


    function getSubprojectIDD()
    {

        $db =& Database::singleton();

        $query = "SELECT SubprojectID FROM session WHERE ID = :SID";
        $fieldValue = $db->pselectOne($query, array('SID' => $this->getSessionID()));
        return $fieldValue;

    }

    function getConsentVal()
    {

        $db =& Database::singleton();

        $NDAR_SA_consent = $db->pselectRow(
            "select ccrel.Status from candidate_consent_rel ccrel
join consent cn on (cn.ConsentID=ccrel.ConsentID)
where cn.Name='NDAR_consent_SA' and CandidateID=:candid",
            array('candid' => $this->candID)
        );

        return ($NDAR_SA_consent['Status']);

    }

}
