<?php

require_once "NDB_BVL_Instrument_Radiology_Review_VSA.class.inc";

/**
 * This file contains the NDB_BVL_Instrument_radiology_review_infant class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Nicolas Brossard
 */
class NDB_BVL_Instrument_radiology_review_infant extends NDB_BVL_Instrument_Radiology_Review_VSA
{
    // Same implementation as the base class except that the test
    // long name (shown on the visit page) will be determined by
    // the record in table test_names for this instrument
}

?>
