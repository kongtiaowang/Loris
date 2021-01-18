<?php

require_once "NDB_BVL_Instrument_Mock_Scanner_Training_Version_2.class.inc";

/**
 * This file contains the NDB_BVL_mock_scanner_training_form_infant class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Nicolas Brossard
 */
class NDB_BVL_Instrument_mock_scanner_training_form_infant extends NDB_BVL_Instrument_Mock_Scanner_Training_Version_2
{
    // Same implementation as the base class except that the test
    // long name (shown on the visit page) will be determined by
    // the record in table test_names for this instrument
}

?>
