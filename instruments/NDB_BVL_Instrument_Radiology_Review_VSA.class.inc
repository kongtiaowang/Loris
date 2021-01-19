<?php

require_once "AbstractNDB_BVL_Instrument_Radiology_Review_VSA.class.inc";

class NDB_BVL_Instrument_Radiology_Review_VSA extends AbstractNDB_BVL_Instrument_Radiology_Review_VSA
{
    /**
     * {@inheritDoc}
     */
    function getTestName() : string
    {
        return 'Radiology_Review_VSA';
    }

    /**
     * {@inheritDoc}
     */
    function getTableName() : string
    {
        return 'Radiology_Review_VSA';
    }
}
