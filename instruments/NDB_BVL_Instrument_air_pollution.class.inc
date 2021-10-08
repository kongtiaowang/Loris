<?php
/**
 *
 * @category Instrument
 * @author   Gregory Luneau <gluneau.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

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
    use LegacyInstrumentTrait;

    var $ValidityRequired = false;

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
        
if ($commentID!='' || $commentID!=NULL) {
    $timepoint =& TimePoint::singleton($this->getSessionID());
    $candidate =& Candidate::singleton($timepoint->getCandID());
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
        //determine page to display
        if (preg_match("/air_pollution(_page[0-9]+)/", $this->page, $matches)) {
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
    function _main(){
      $this->form->addElement('header', 'instrument_title', "IBIS Environment Residential History");

      $yesNo = array(null=>"", 'yes'=>"Yes", 'no'=>"No");
      $this->form->addElement("hidden","commentId", $this->commentID);

      $content = <<< 'HTML'
        <center><textarea cols=120 rows=20>
        We invite you to participate in a research study being conducted by investigators from Washington University in St. Louis.  You are invited because you have participated in our Infant Brain Imaging Study (IBIS).  Currently, IBIS investigators are working to explore how factors in the environment (including air pollution and metals, like lead) can affect the brain as children grow.  The purpose of the study is to connect environmental information with the MRI imaging data we have already acquired to understand more about this interaction.  The National Institutes of Health is funding this research study.

        If you agree to participate, we would like to collect two things from you: 1.) A list of places where you lived while you were pregnant with the child enrolled in our IBIS study and where they lived for their first three years and 2.) baby teeth, which the child enrolled in the IBIS study may have already lost or is in the process of losing now.  Because parts of teeth are formed right before birth and in the first 6 months of infancy, your child’s teeth can tell us what metals your child may have been exposed to before and after birth.  

        We will also send you a “tooth fairy kit” in the mail with tooth storage tubes, a tooth donation form, a tooth fairy receipt, a dollar bill, and a postage-paid padded envelope.  If you would like to participate in this project, please mail us as many as 5 baby teeth lost by your child who has taken part in IBIS research.  When you donate your child’s teeth to the study team, we will send you a check for $20.  You will not get the teeth back.  If you do not have any teeth to send at this point, you can hold onto the kit and send us teeth as your child loses them in the future.  Full instructions will be provided in the “tooth fairy kit” we send you.  

        The residential survey will ask you to list your addresses as indicated on the form.  This should only take around 5 minutes to complete. Once we have your addresses, we are able to determine air pollution rates in those areas.  You are free to skip any questions you prefer not to answer.  If you do not want to participate, you can simply reply to this email and tell us that.  If we don’t get a response to this email, we will call you to explain what we are doing and to see if you would like to participate.  Approximately 242 people will take part in this study at Washington University.

        As part of this study, we are obtaining address information and teeth from you and your child. We would like to use these data and samples for studies going on right now as well as studies that are conducted in the future.  These studies may provide additional information that will be helpful in understanding how air pollution could affect ASD, or other diseases or conditions, including research to develop investigational tests, treatments, drugs or devices that are not yet approved by the U.S. Food and Drug Administration.  It is unlikely that what we learn from these studies will have a direct benefit to you.  There are no plans to provide financial compensation to you should this occur.  By allowing us to use your data and samples you give up any property rights you may have in the data and samples.


        We will share your samples and data with other researchers. They may be doing research in areas similar to this research or in other unrelated areas.  These researchers may be at Washington University, at other research centers and institutions, or industry sponsors of research.  We may also share your research data with large data repositories (a repository is a database of information) for broad sharing with the research community.  If your individual research data is placed in one of these repositories only qualified researchers, who have received prior approval from individuals that monitor the use of the data, will be able to look at your information.  

        If you change your mind and do not want us to store and use your data and samples for future research you should contact the research team member identified at the top of this document.  The data and samples will no longer be used for research purposes. However, if some research with your data and samples has already been completed, the information from that research may still be used. Also, if the data and samples have been shared with other researchers it might not be possible to withdraw the data and samples to the extent they have been shared.

        The only risk from being in this study is a possible breach of confidentiality.  You will not benefit personally.  However we hope that others may benefit in the future from what we learn as a result of this study. 

        You will not have any costs for being in this research study.

        You will be paid for being in this research study. You will need to provide your social security number (SSN) in order for us to pay you. If your social security number is obtained for payment purposes only, it will not be retained for research purposes. You may also need to provide your address if a check will be mailed to you.  After sending back baby teeth, you will receive a check for $20.  You should receive your payment in 4-6 weeks after sending in the teeth 

        We will keep the information you provide confidential by assigning you a study ID to keep your name private.  After you provide your address history, the information will be stored on a secure server and encrypted.  Only your IBIS site and IBIS-approved researchers outside of Washington University who will geocode the addresses will know your information.  For the baby teeth, your child’s samples will be identified by a code, not a name.  The tooth samples will be securely stored at a laboratory collaborating with and authorized by the study.  Identifying information will be removed from the samples and replaced with the code.  Only research staff will be able to connect that code number with identifying information.  You will not own the baby teeth after you give them to the study and they cannot be returned.

        However, federal regulatory agencies and Washington University, including the Washington University Institutional Review Board (a committee that reviews and approves research studies) and the Human Research Protection Office may inspect and copy records pertaining to this research.  If we write a report about this study we will do so in such a way that you cannot be identified.

        As part of this study we will generate Protected Health Information, or PHI.  PHI is health information that identifies you and is protected by law under HIPAA (the Health Insurance Portability and Accountability Act). To take part in this study you must give the research team permission to use and disclose your PHI as explained in this letter.  The research team will follow state and federal laws and it is possible that other people may become aware of your participation in this study and may inspect records pertaining to the research. This could include university representatives, to complete university responsibilities and government representatives, (including the Office for Human Research Protections and the Food and Drug Administration) to complete federal or state responsibilities, the National Institutes of Health and other study sites directly involved in the IBIS study including University of North Carolina, Children’s Hospital of Pennsylvania, the University of Wisconsin, and Montreal Neurological Institute. 

        Once your health information is shared with someone outside of the research team, it may no longer be protected by HIPAA. 

        The research team will only use and share your information as talked about in this letter.  When possible, the research team will make sure information cannot be linked to you (de-identified).  Once information is de-identified, it may be used and shared for other purposes not discussed in this letter.  If you have questions or concerns about your privacy and the use of your PHI, please contact the University’s Privacy Officer at 866-747-4975. 

        Although you will not be allowed to see the study information, you may be given access to your health care records by contacting your health care provider. 

        If you do not provide authorization for us to use your PHI it will not affect your treatment or the care given by your health provider, insurance payments or enrollment in any health plans, or any benefits to which you are entitled.  However, it will not be possible for you to take part in the study.  If you verbally agree, you authorize the use of your PHI for this research, and your authorization will not expire.  You may later change your mind and not let the research team use or share your information.  

        In order to revoke your authorization, you will need to complete a withdrawal letter.  Please contact the Human Research Protection Office for more information on how to revoke your authorization or contact the research team to request the withdrawal letter.  If you revoke your authorization, the research team may only use and share information already collected for the study. Your information may still be used and shared as necessary to maintain the integrity of the research, for example, to account for a participant’s withdrawal from the research study or for safety reasons.  You will not be allowed to continue to participate in the study.

        Your participation in this study is completely voluntary.  You may choose not to take part at all.  If you decide to participate in the study you may stop participating at any time. Any data that was collected as part of this study will remain as part of the study records and cannot be removed.  If you decide not to take part in the study or if you stop participating at any time, you won’t be penalized or lose any benefits for which you otherwise qualify.  

        If you do not wish to participate in this study or want to end your participation in the study, you may send us a reply to this email stating so. You will not be penalized or lose any benefits for which you otherwise qualify.

        We encourage you to ask questions.  If you have any questions about the research study itself, please contact: Lisa Flake at 314-747-6759. If you feel you have been harmed from being in the study, please contact: Kelly Botteron, MD, at 314-747-6790.  If you have questions, concerns, or complaints about your rights as a research participant, please contact the Human Research Protection Office at 660 South Euclid Avenue, Campus Box 8089, St. Louis, MO  63110, 1-(800)-438-0445 or email hrpo@wustl.edu.   General information about being a research participant can be found on the Human Research Protection Office web site, http://hrpo.wustl.edu.  To offer input about your experiences as a research participant or to speak to someone other than the research staff, call the Human Research Protection Office at the number above.

        Thank you very much for your consideration of this research study.
        </textarea></center>
HTML;
   
      switch ($this->centerID) {
        case 1: // DCC
          $this->form->addElement('static', 'lorisSubHeader', $content);
          break;
        case 2: // SEA
          $this->form->addElement('static', 'lorisSubHeader', "<center><embed src='../images/SEA_toothfairy_consent_form.pdf' width=\"800px\" height=\"400px\" /></center>");
          break;
        case 3: // PHI
          $this->form->addElement('static', 'lorisSubHeader', "<center><embed src='../images/PHI_toothfairy_consent_form.pdf' width=\"800px\" height=\"400px\" /></center>");
          break;
        case 4: // STL
          $this->form->addElement('static', 'lorisSubHeader', $content);
          break;   
        case 5: // UNC
          $this->form->addElement('static', 'lorisSubHeader', "<center><embed src='../images/UNC_toothfairy_consent_form.pdf' width=\"800px\" height=\"400px\" /></center>");
          break;                 
      }
      $group[]=$this->form->createElement("select", 'mail_tooth_kit', '',$yesNo);
      $this->XINRegisterRule("mail_tooth_kit", array("mail_tooth_kit{@}=={@}"), "Required.", "mail_tooth_kit_group");
      $this->form->addGroup($group, "mail_tooth_kit_group", "Do you wish to recieve the 'Tooth fairy Kit?'", null, false);
      unset($group);
      $group[] =& $this->form->createElement("select","consent", "", $yesNo);
      $this->XINRegisterRule("consent", array("code{@}=={@}"), "Required.", "consent_group");
      $this->form->addGroup($group, "consent_group", "By selecting 'Yes' you agree to the above information and give your consent for us to use the information in this survey.", null, false);
      unset($group);

      $this->form->addElement("static", null, '<div id="air_pollution"><script type="text/javascript" src="/js/air_pollution_consent.js"></script></div>');
    }

    function _page2(){

        $this->form->addElement('header', 'instrument_title_main', "IBIS Environment Residential History");
        $this->form->addElement('header', 'instrument_inst1','</b><h5>Thank you for agreeing to participate in this very important study! <br><br>We would like to know the home addresses of biological mothers starting one year before the birth of your child. Having these addresses will help us study how prenatal exposures, such as air pollution, affect children’s development. ' .
            '<br><br> Please start with your main residence at the time of your child’s birth and end with the residence where you lived one year before your child’s birth. <br><br>On Section 2, we ask where your child lived when he or she turned 3 YEARS old back to birth.</h5><b>');
       
        $this->form->addElement("static", null, '<div id="sjcl"><script type="text/javascript" src="/js/sjcl.js"></script></div><div id="site" style="display: none;">' . $this->siteName . '</div>');
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
        $this->form->addElement('header', 'instrument_title_mom', "<h5>MOM’s Home at child’s birth #1 (Required)</h5>");
        $this->addCheckbox('living1yb4m1', 'Check if you were living here 1 year before child’s birth', array('value' => '1'));

        $this->form->addElement("text", 'address_line1m1_remove', "Address (Line 1)", array("class" => "encrypt required"));
        $this->form->addElement("text", 'address_line2m1_remove', "Address (Line 2)", array("class" => "encrypt"));
        $this->form->addElement("text", 'citym1_remove', "City", array("class" => "encrypt required"));
        $this->form->addElement("text", 'statem1_remove', "State", array("class" => "encrypt required"));
        $this->form->addElement("text", 'zip_codem1_remove', "Zip Code", array("class" => "encrypt required"));

        $this->addMonthYear('from1b41', 'From', $dateOptionsYM);
        $this->addMonthYear('to1b41', 'To', $dateOptionsYM);
        $this->addCheckbox('livinghere3bd1', 'Check if you were living in the above address at the time of child’s 3rd birthday.', array('value' => '1'));
     
        
        // Address Mom 2-5
        for ($i=2; $i<6; $i++)
        {
            $this->form->addElement('header', 'instrument_title_mom'.$i, "<h5>MOM’s Home Previous #" . $i . " (Optional)</h5>");
            $this->addCheckbox('living1yb4m' . $i, 'Check if you were living here 1 year before child’s birth', array('value' => '1'));

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
        $this->form->addElement('header', 'instrument_instruction_child', '<h4>Section 2</h4><h5>We would like to know all the addresses where your child lived until turning AGE 3. Please start below with the address where your child lived on his or her 3rd BIRTHDAY.  Then, list your child’s previous addresses, back until the date of your child’s birth.   If your child was in shared custody, please list both home addresses.</h5><b>');

        $this->form->addElement('header', 'instrument_title_child', "<h5>Child’s home address on his or her 3rd Birthday #1 (Required)</h5>");
        $this->addCheckbox('livingatb1', 'Check if this address was your child’s main home at time of birth', array('value' => '1'));

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
            $this->form->addElement('header', 'instrument_title_child'.$i, "<h5>Child’s home address previous to his or her 3rd Birthday #". $i ." (Optional)</h5>");
            $this->addCheckbox('livingatb' . $i, 'Check if this address was your child’s main home at time of birth', array('value' => '1'));

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

        $this->form->addElement("static", null, '<div id="air_pollution"><script type="text/javascript" src="/js/air_pollution.js"></script></div><div id="air_pollution_decrypt"><script type="text/javascript" src="/js/air_pollution_decrypt.js"></script></div>');
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

}
