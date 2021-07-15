<?php
/*
 * This file contains the NDB_BVL_Instrument_Vineland_DS_Infant
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the Vineland DS-Infant Proband instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
require_once('AbstractNDB_BVL_Instrument_Vineland_3_1.class.inc');

class NDB_BVL_Instrument_Vineland_DS_Infant extends AbstractNDB_BVL_Instrument_Vineland_3_1
{
    /**
     * {@inheritDoc}
     */
    function getTestName() : string
    {
        return 'Vineland_DS_Infant';
    }

    /**
     * {@inheritDoc}
     */
    function getTableName() : string
    {
        return 'Vineland_DS_Infant';
    }

    /**
     * {@inheritDoc}
     */
    function getInstrumentShortName() : string
    {
        return 'Vineland DS-Infant';
    }
}

?>
