<?php
/**
 *
 * @category Instrument
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for IBIS_SA_SLEEP_Consent_Form
 *
 * @category Instrument
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_IBIS_SA_SLEEP_Consent_Form extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityRequired = false;

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = 'XIN';
        $this->form = new LorisForm('test_form');
        $this->page = $page; // page label (number or string - used by user-defined child classes)

        // set the object properties
        $this->testName = 'IBIS_SA_SLEEP_Consent_Form'; // test_names.Test_name
        $this->table = 'IBIS_SA_SLEEP_Consent_Form'; // name of database table corresponding to instrument
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

        if ($commentID != '' || $commentID != NULL) {
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
        if (preg_match("/IBIS_SA_SLEEP_Consent_Form(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->form->addElement('header', 'instrument_title', "IBIS SA-SLEEP - Consent Form");

        $yesNo = array(null => "", 'yes' => "Yes", 'no' => "No");
        $this->form->addElement("hidden", "commentId", $this->commentID);

        $content1 = <<< 'HTML'
        <center><textarea cols=100 rows=5>
        Sample SA Sleep Consent Text (Low Risk) For the study sites
        Your participation in this study is completely voluntary.  You may choose not to take part at all.  If you decide to participate in the study you may stop participating at any time. Any data that was collected as part of this study will remain as part of the study records and cannot be removed.  If you decide not to take part in the study or if you stop participating at any time, you won’t be penalized or lose any benefits for which you otherwise qualify.

        If you do not wish to participate in this study or want to end your participation in the study, you may send us a reply to this email stating so. You will not be penalized or lose any benefits for which you otherwise qualify.

        We encourage you to ask questions.  If you have any questions about the research study itself, please contact: Lisa Flake at 314-747-6759. If you feel you have been harmed from being in the study, please contact: Kelly Botteron, MD, at 314-747-6790.  If you have questions, concerns, or complaints about your rights as a research participant, please contact the Human Research Protection Office at 660 South Euclid Avenue, Campus Box 8089, St. Louis, MO  63110, 1-(800)-438-0445 or email hrpo@wustl.edu.   General information about being a research participant can be found on the Human Research Protection Office web site, http://hrpo.wustl.edu.  To offer input about your experiences as a research participant or to speak to someone other than the research staff, call the Human Research Protection Office at the number above.

        Thank you very much for your consideration of this research study.
        </textarea></center>
HTML;
        $content2 = <<< 'HTML'
        <center><textarea cols=100 rows=5>
        Sample SA Sleep Consent Text (High Risk) For the study sites.
        Your participation in this study is completely voluntary.  You may choose not to take part at all.  If you decide to participate in the study you may stop participating at any time. Any data that was collected as part of this study will remain as part of the study records and cannot be removed.  If you decide not to take part in the study or if you stop participating at any time, you won’t be penalized or lose any benefits for which you otherwise qualify.

        If you do not wish to participate in this study or want to end your participation in the study, you may send us a reply to this email stating so. You will not be penalized or lose any benefits for which you otherwise qualify.

        We encourage you to ask questions.  If you have any questions about the research study itself, please contact: Lisa Flake at 314-747-6759. If you feel you have been harmed from being in the study, please contact: Kelly Botteron, MD, at 314-747-6790.  If you have questions, concerns, or complaints about your rights as a research participant, please contact the Human Research Protection Office at 660 South Euclid Avenue, Campus Box 8089, St. Louis, MO  63110, 1-(800)-438-0445 or email hrpo@wustl.edu.   General information about being a research participant can be found on the Human Research Protection Office web site, http://hrpo.wustl.edu.  To offer input about your experiences as a research participant or to speak to someone other than the research staff, call the Human Research Protection Office at the number above.

        Thank you very much for your consideration of this research study.
        </textarea></center>
HTML;

        $LR_array = array(3, 10);
        $HR_array = array(1, 2, 9);
        $subproject = $this->getSubprojectIDD();
        switch ($this->centerID) {
            case 2: // SEA
                if (in_array($subproject, $HR_array)) {
                    $this->form->addElement('static', 'HR', "<center><embed src='../images/IBIS_Consent_SA_Sleep_HSAP_Language_Added_Parental_Permission_Form_HR_v10.pdf' width=\"800px\" height=\"600px\" /></center>");
                } else {
                    $this->form->addElement('static', 'LR', "<center><embed src='../images/IBIS_Consent_SA_Sleep_HSAP_non_Medical_Risks_Added_Parental_Permission_Form_LR_v10.pdf' width=\"800px\" height=\"600px\" /></center>");
                }
                break;
            case 1: // DCC
            case 3: // PHI
            case 4: // STL
            case 5: // UNC
                if (in_array($subproject, $HR_array)) {
                    $this->form->addElement('static', 'HR', $content2);
                }
                if (in_array($subproject, $LR_array)) {
                    $this->form->addElement('static', 'LR', $content1);
                }
                break;
        }
        $this->form->addElement('static', "lorisSubHeader", "By selecting 'Yes' you agree to the above information and give your consent.");
        $this->addSelect("IBIS_SA_SLEEP_Consent", "SA-Sleep Consent", $yesNo);
        $this->form->addElement("static", null, '<div id="IBIS_SA_SLEEP_Consent_Form"><script type="text/javascript" src="/js/IBIS_SA_SLEEP_Consent.js"></script></div>');
    }

    function _page2()
    {
        if ($this->getConsentVal() == 'yes') {
            $text = "</b><h5>Thank you for agreeing to participate in this very important study!</h5>";
        }
        if ($this->getConsentVal() == 'no') {
            $text = "</b><h5>Thank you for your time!</h5>";
        }
        $this->form->addElement('hidden', 'data_collection', "Remote");
        $this->form->addElement('header', 'instrument_title_main', 'IBIS SA-SLEEP - Consent Form');
        $this->form->addElement('header', 'instrument_inst1', $text);
        $this->form->addElement("static", null, '<div id="IBIS_SA_SLEEP_Consent"><script type="text/javascript" src="/js/IBIS_SA_SLEEP_Consent_final_submit.js"></script></div>');

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
        $SA_consent = $db->pselectRow(
            "select ccrel.Status from candidate_consent_rel ccrel
join consent cn on (cn.ConsentID=ccrel.ConsentID)
where cn.Name='IBIS_SA_SLEEP_Consent' and CandidateID=:candid",
            array('candid' => $this->candID)
        );
        return ($SA_consent['Status']);
    }
}
