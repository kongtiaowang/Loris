<?php



require_once 'NDB_BVL_Instrument_m_chat.class.inc';

class NDB_BVL_Instrument_m_chat_proband extends NDB_BVL_Instrument_m_chat
{
    use LegacyInstrumentTrait;
	/*
	INSERT INTO test_names VALUES ('', 'm_chat_proband', 'M-CHAT (Subject)', '0', '1');

	INSERT INTO instrument_subtests VALUES('', 'm_chat_proband', 'm_chat_page1', 'Questions', 1);
	*/

	/**
    * sets up basic data, such as the LorisForm object, and so on.
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
		// string - used by
		// user-defined child classes)

		// set the object properties
		$this->testName = "m_chat_proband";           // test_names.Test_name
		$this->table = 'm_chat_proband';              // name of database table corresponding to instrument
		// data keyed by commentID
		$this->commentID = $commentID;

		//The array of dates/timestamps to convert to database dates/timestamps
		//Any LorisForm date elements must be listed here
		$this->dateTimeFields=array("Date_taken");

		//The array of selects with multiple answers allowed
		//Any LorisForm multiple selects must be listed here
		$this->selectMultipleElements = array();

		// required fields for data entry completion status
		$this->_requiredElements = array('Examiner', "q1_swung_on_knee");
       
        $this->_doubleDataEntryDiffIgnoreColumns = array('CommentID', 'UserID', 'Testdate', 'Window_Difference', 'Candidate_Age','Data_entry_completion_status','total_item_fails','total_critical_fails','score');
		
        // setup the form
		$this->_setupForm();

	}
    function _addAdditionalComments() {
            $this->form->addElement('static',null,'<br>');
            $this->form->addElement("textarea", "other_comments", "Comments :", array('cols'=>25, 'rows'=>4));
            $this->XINRegisterRule("other_comments", array("{other_comments}{@}=={@}NEVER_REQUIRED"));
    }
}
?>