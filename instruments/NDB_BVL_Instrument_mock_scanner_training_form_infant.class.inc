<?php

require_once "AbstractNDB_BVL_Instrument_Mock_Scanner_Training_Version_2.class.inc";

/**
 * This file contains the NDB_BVL_mock_scanner_training_form_infant class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Nicolas Brossard
 */
class NDB_BVL_Instrument_mock_scanner_training_form_infant extends AbstractNDB_BVL_Instrument_Mock_Scanner_Training_Version_2
{
    /**
     * {@inheritDoc}
     */
    function getTestName() : string
    {
        return 'mock_scanner_training_form_infant';
    }

    /**
     * {@inheritDoc}
     */
    function getTableName() : string
    {
        return 'mock_scanner_training_form_infant';
    }
}

?>
