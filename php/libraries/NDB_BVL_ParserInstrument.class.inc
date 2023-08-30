<?php
/**
 * This file contains the base class for instruments in Loris
 *
 * PHP Version 7
 *
 * @category Main
 * @package  Behavioural
 * @author   Loris team <info-loris.mni@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris-Trunk/
 */

/**
 * Base class for all NeuroDB behavioural instruments
 *
 * Throws PEAR errors. Also requires PEAR HTML_Quickform.
 *
 * @category Main
 * @package  Behavioural
 * @author   Loris team <info-loris.mni@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris-Trunk/
 */
abstract class NDB_BVL_ParserInstrument extends NDB_BVL_Instrument
{
    public function isParser(): bool
    {
        return true;
    }
}

