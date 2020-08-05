<?php

require_once('NDB_BVL_Instrument_scq.class.inc');

class NDB_BVL_Instrument_scq_subject extends NDB_BVL_Instrument_scq
{
    use LegacyInstrumentTrait;
/*
INSERT INTO test_names VALUES ('', 'scq_subject', 'SCQ (Subject)', '0', '1');

INSERT INTO instrument_subtests VALUES('', 'scq_subject', 'scq_subject_page1', 'Page 1', 1);

INSERT INTO test_battery VALUES ('', 'scq_subject', '1050', '1140', 'Y', 'Visit', '3');

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
        // set the object properties
        $this->testName = "scq_subject";           // test_names.Test_name
        $this->table = 'scq_subject';              // name of database table corresponding to instrument

        $this->_setupForm();
    }
}
?>
