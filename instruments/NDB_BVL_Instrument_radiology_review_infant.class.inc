<?php

require_once "AbstractNDB_BVL_Instrument_Radiology_Review_VSA.class.inc";

/**
 * This file contains the NDB_BVL_Instrument_radiology_review_infant class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Nicolas Brossard
 */
class NDB_BVL_Instrument_radiology_review_infant extends AbstractNDB_BVL_Instrument_Radiology_Review_VSA
{
    /**
     * {@inheritDoc}
     */
    function getTestName() : string
    {
        return 'radiology_review_infant';
    }

    /**
     * {@inheritDoc}
     */
    function getTableName() : string
    {
        return 'radiology_review_infant';
    }

    /**
     * {@inheritDoc}
     */
    function getInstrumentTitle() : string
    {
        return 'Site Radiological Review Form';
    }
}

?>
