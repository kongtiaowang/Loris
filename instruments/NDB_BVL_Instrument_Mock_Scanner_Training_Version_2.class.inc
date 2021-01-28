<?php

require_once "AbstractNDB_BVL_Instrument_Mock_Scanner_Training_Version_2.class.inc";

/*
 * This file contains the NDB_BVL_Instrument_Mock_Scanner_Training_Version_2
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the Mock_Scanner_Training_Version_2 instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

const YES_NO = array(null => "", "Yes" => "Yes", "No" => "No");


class NDB_BVL_Instrument_Mock_Scanner_Training_Version_2 extends AbstractNDB_BVL_Instrument_Mock_Scanner_Training_Version_2
{
    /**
     * {@inheritDoc}
     */
    function getTestName() : string
    {
        return 'Mock_Scanner_Training_Version_2';
    }

    /**
     * {@inheritDoc}
     */
    function getTableName() : string
    {
        return 'Mock_Scanner_Training_Version_2';
    }
}

?>
