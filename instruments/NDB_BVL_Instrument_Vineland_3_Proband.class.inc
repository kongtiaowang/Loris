<?php
/*
 * This file contains the NDB_BVL_Instrument_Vineland_3_proband
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
 * Creates the form elements for the Vineland 3 Proband instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
require_once('NDB_BVL_Instrument_Vineland_3.class.inc');

class NDB_BVL_Instrument_Vineland_3_Proband extends NDB_BVL_Instrument_Vineland_3
{
    /**
     * {@inheritDoc}
     */
    function getTestName()
    {
        return 'Vineland_3_Proband';
    }

    /**
     * {@inheritDoc}
     */
    function getTableName()
    {
        return 'Vineland_3_Proband';
    }

    /**
     * {@inheritDoc}
     */
    function getInstrumentShortName()
    {
        return 'Vineland 3 Proband';
    }
}

?>
