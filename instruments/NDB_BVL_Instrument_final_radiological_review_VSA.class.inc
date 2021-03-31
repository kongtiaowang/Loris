<?php

require_once "AbstractNDB_BVL_Instrument_Radiology_Review_VSA.class.inc";

class NDB_BVL_Instrument_final_radiological_review_VSA extends AbstractNDB_BVL_Instrument_Radiology_Review_VSA
{
    /**
     * {@inheritDoc}
     */
    function getTestName() : string
    {
        return 'final_radiological_review_VSA';
    }

    /**
     * {@inheritDoc}
     */
    function getTableName() : string
    {
        return 'final_radiological_review_VSA';
    }

    /**
     * {@inheritDoc}
     */
    function getInstrumentTitle() : string
    {
        return 'Final Study Radiological Review';
    }
}
