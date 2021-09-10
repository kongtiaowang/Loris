<?php
/**
 * This file contains the NDB_BVL_Instrument_EEG_QC
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  IBIS
 * @author   Shen Wang <wangshen.mcin@gmail.ca>
 * @date     2021 May 05
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

class NDB_BVL_Instrument_EEG_QC extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;
    var $ValidityEnabled  = false;
    var $ValidityRequired = false;
    const A1_A3 = array(
                               ""            => "",
                               "1"           => "1 (Great Placement)",
                               "2"           => "2 (Acceptable Placement)",
                               "3"           => "3 (Poor Placement)",
                              );
    const R1_R3 = array(
                               ""            => "",
                               "1"           => "1 (Great Data there is minimal noise and minimal artifact present)",
                               "2"           => "2 (Sufficient Data, Some Noise or some artifact present)",
                               "3"           => "3 (Poor Data, and Substantial Noise or substantial Artifact Present)",
                              );

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID The CommentID identifying the data to load
     * @param string $page      If a multipage form, the page to show
     *
     * @return   void
     * @access   public
     * @abstract
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = 'XIN';
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;

        // set the object properties
        $this->testName  = 'EEG_QC'; // test_names.Test_name
        $this->table     = 'EEG_QC';
        $this->commentID = $commentID; // data keyed by commentID

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array(
            'Date_taken'
        );

        // required fields for data entry completion status
        $this->_requiredElements = array(
            'Examiner',
            'CommentID',
        );

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = [
            'study',
            ];

        // setup the form
        $this->_setupForm();
    }

    /**
     * Method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        //determine page to display
        if (preg_match("/EEG_QC(_page[0-9]+)/",
            $this->page, $matches)) {
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
        $this->_addMetadataFields();

        $this->form->addElement('header', 'instrument_title', "EEG QC FORM");


        $this->form->addElement('text','name_did_qc','Name of Person who did the QC :');
    }
    function _page1(){

                $this->form->addElement('header', 'instrument_title1', "SUBSECTION 1: Resting");

               $this->form->addElement('select','r_1','1. Please rate the Net Placement Quality:',self::A1_A3);
               $this->form->addElement('text','r_2','2. What percentage of the data was collected (this can be over 100)');
               $this->form->addElement('text','r_3','3. What percentage of the data was retained (up to 100%)');
               $this->form->addElement('select','r_4','4. What is the overall quality rating?',self::R1_R3);
               $this->form->addElement('text','r_5','5. Behavioral Management');
               $this->form->addFormRule(array(&$this, 'validate_positive_number'));
    }


    function _page2(){

               $this->form->addElement('header', 'instrument_title2', "SUBSECTION 2: VEP");

               $this->form->addElement('select','v_1','6. Please rate the Net Placement Quality:',self::A1_A3);
               $this->form->addElement('text','v_2','7. What percentage of the data was collected (this can be over 100)');
               $this->form->addElement('text','v_3','8. What percentage of the data was retained (up to 100%)');
               $this->form->addElement('select','v_4','9. What is the overall quality rating?',self::R1_R3);
               $this->form->addElement('text','v_5','10. Behavioral Management');
               $this->form->addFormRule(array(&$this, 'validate_positive_number'));

    }

    function _page3(){

               $this->form->addElement('header', 'instrument_title3', "SUBSECTION 3: AEP");

               $this->form->addElement('select','a_1','11. Please rate the Net Placement Quality:',self::A1_A3);
               $this->form->addElement('text','a_2','12. What percentage of the data was collected (this can be over 100)');
               $this->form->addElement('text','a_3','13. What percentage of the data was retained (up to 100%)');
               $this->form->addElement('select','a_4','14. What is the overall quality rating?',self::R1_R3);
               $this->form->addElement('text','a_5','15. Behavioral Management');
               $this->form->addFormRule(array(&$this, 'validate_positive_number'));

    }
    function validate_positive_number($values)
    {
        $errors = [];
        $this->validate_positive_numeric($values, "r_2", $errors);

        $this->validate_positive_numeric($values, "r_3", $errors);

        $this->validate_less_100($values, "r_3", $errors);


        $this->validate_positive_numeric($values, "v_2", $errors);

        $this->validate_positive_numeric($values, "v_3", $errors);

        $this->validate_less_100($values, "v_3", $errors);


        $this->validate_positive_numeric($values, "a_2", $errors);

        $this->validate_positive_numeric($values, "a_3", $errors);

        $this->validate_less_100($values, "a_3", $errors);


        return $errors;

    }


    function validate_positive_numeric($values, $question, &$errors)
    {
        if (isset($values[$question])) {
            $user_input = $values[$question];
            if ((!is_numeric($user_input) || (is_numeric($user_input) && $user_input < 0)) && $user_input != "") {
                $errors[$question] = "You can only enter a positive number.";
            }
        }
    }

    function validate_less_100($values, $question, &$errors)
    {
        if (isset($values[$question])) {
            $user_input = $values[$question];
            if ( $user_input > 100 ) {
                $errors[$question] = "Specify a number inferior or equal to 100.";
            }
        }
    }

    /**
     * Override to send email when new value for question 14 is answered.
     *
     * @param array $values the new values saved
     * @throws DatabaseException
     */
    function _save(array $values): void
    {
        // Get the old value.
        $db        =& Database::singleton();
        $old_value = $db->pselectOne("
            SELECT a_4
            FROM EEG_QC
            WHERE CommentID = :CommentID
        ", array("CommentID" => $this->getCommentID()));

        // Check if the new value has been set and if it differs from the old value.
        if (isset($values['a_4']) && $old_value != $values['a_4']) {
            $config    = NDB_Config::singleton();
            $session   = $this->getSessionID();
            $timepoint = \TimePoint::singleton($session);
            $candidate = \Candidate::singleton($timepoint->getCandID());

            $emails = "santiago.torres@mcin.ca";
            switch ($candidate->getCandidateSite()) {
                case "PHI":
                    $emails = "bordaa@chop.edu,carneyh2@email.chop.edu";
                    break;
                case "STL":
                    $emails = "babbc@wustl.edu,klohrc@wustl.edu,zempelj@wustl.edu";
                    break;
                case "SEA":
                    $emails = "kemmons2@uw.edu,blau@uw.edu";
                    break;
                case "UMN":
                    $emails = "mill1425@umn.edu";
                    break;
                case "UNC":
                    $emails = "alana_campbell@med.unc.edu";
                    break;
            }

            // Get the file name from the media module.
            $file_name = $db->pselectOne("
                SELECT file_name
                FROM media
                WHERE instrument = 'EEG'
                    AND session_id = :session
            ", array("session" =>$session));

            $email_data = array(
                "candID"      => $candidate->getCandID(),
                "PSCID"       => $candidate->getPSCID(),
                "visit_label" => $timepoint->getVisitLabel(),
                "file_name"   => $file_name,
                "url"         => $config->getSetting("www")['url'],
                "commentID"   => $this->getCommentID()
            );

            Email::send($emails, "EEG_QC_notification.tpl", $email_data, "", "IBIS Team <noreply@ibis.loris.ca>", "", "", "text/html");

        }

        parent::_save($values);
    }

}
