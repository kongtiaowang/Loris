<?php
/**
 * This file contains the base class for instruments with additional functions in Loris
 *
 * @category Main
 * @package  Behavioural
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris-Trunk/
 */


/**
 * Base class for instruments with additional options in Loris
 *
 *
 * @category Main
 * @package  Behavioural
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris-Trunk/
 */
class NDB_BVL_Instrument_IBIS extends NDB_BVL_Instrument
{

    function ADOS_SA_CSS($ADOS_Version, $ados_a1, $ADOS_social_affect_total)
    {
        $ADOS_mod = '';
        if ( $ADOS_Version == "ados_module1" or $ADOS_Version == "ados2_module1") {
            if ( $ados_a1 == 0 ) { $ADOS_mod = "Module1somewords"; }
            elseif ( $ados_a1 == 1 ) { $ADOS_mod = "Module1somewords"; }
            elseif ( $ados_a1 == 2 ) { $ADOS_mod = "Module1somewords"; }
            elseif ( $ados_a1 == 3 ) { $ADOS_mod = "Module1nowords"; }
            elseif ( $ados_a1 == 8 and $ADOS_Version == "ados_module1" ) { $ADOS_mod = "Module1nowords"; }
            elseif ( $ados_a1 == 4 and $ADOS_Version == "ados2_module1" ) { $ADOS_mod = "Module1nowords"; }
        }

        if ( $ADOS_Version == "ados_module2" ) { $ADOS_mod = "Module2"; }
        elseif ( $ADOS_Version == "ados2_module2" ) { $ADOS_mod = "Module2"; }
        elseif ( $ADOS_Version == "." ) { $ADOS_mod = "."; }

        $ADOS_SA_CSS = '';

        if ( $ADOS_mod == "Module1nowords" and in_array($ADOS_social_affect_total, range(0, 3)) ) { $ADOS_SA_CSS = 1; }
        elseif ( $ADOS_mod == "Module1nowords" and in_array($ADOS_social_affect_total, range(4, 5)) ) { $ADOS_SA_CSS = 2; }
        elseif ( $ADOS_mod == "Module1nowords" and in_array($ADOS_social_affect_total, range(6, 8)) ) { $ADOS_SA_CSS = 3; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_social_affect_total == 9 ) { $ADOS_SA_CSS = 4; }
        elseif ( $ADOS_mod == "Module1nowords" and in_array($ADOS_social_affect_total, range(10, 13)) ) { $ADOS_SA_CSS = 5; }
        elseif ( $ADOS_mod == "Module1nowords" and in_array($ADOS_social_affect_total, range(14, 16)) ) { $ADOS_SA_CSS = 6; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_social_affect_total == 17 ) { $ADOS_SA_CSS = 7; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_social_affect_total == 18 ) { $ADOS_SA_CSS = 8; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_social_affect_total == 19 ) { $ADOS_SA_CSS = 9; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_social_affect_total == 20 ) { $ADOS_SA_CSS = 10; }

        if ( $ADOS_mod == "Module1somewords" and in_array($ADOS_social_affect_total, range(0, 1)) ) { $ADOS_SA_CSS = 1; }
        elseif ( $ADOS_mod == "Module1somewords" and in_array($ADOS_social_affect_total, range(2, 4)) ) { $ADOS_SA_CSS = 2; }
        elseif ( $ADOS_mod == "Module1somewords" and $ADOS_social_affect_total == 5 ) { $ADOS_SA_CSS = 3; }
        elseif ( $ADOS_mod == "Module1somewords" and in_array($ADOS_social_affect_total, range(6, 7)) ) { $ADOS_SA_CSS = 4; }
        elseif ( $ADOS_mod == "Module1somewords" and $ADOS_social_affect_total == 8 ) { $ADOS_SA_CSS = 5; }
        elseif ( $ADOS_mod == "Module1somewords" and in_array($ADOS_social_affect_total, range(9, 11)) ) { $ADOS_SA_CSS = 6; }
        elseif ( $ADOS_mod == "Module1somewords" and in_array($ADOS_social_affect_total, range(12, 13)) ) { $ADOS_SA_CSS = 7; }
        elseif ( $ADOS_mod == "Module1somewords" and in_array($ADOS_social_affect_total, range(14, 15)) ) { $ADOS_SA_CSS = 8; }
        elseif ( $ADOS_mod == "Module1somewords" and in_array($ADOS_social_affect_total, range(16, 17)) ) { $ADOS_SA_CSS = 9; }
        elseif ( $ADOS_mod == "Module1somewords" and in_array($ADOS_social_affect_total, range(18, 20)) ) { $ADOS_SA_CSS = 10; }

        if ( $ADOS_mod == "Module2" and in_array($ADOS_social_affect_total, range(0, 1)) ) { $ADOS_SA_CSS = 1; }
        elseif ( $ADOS_mod == "Module2" and in_array($ADOS_social_affect_total, range(2, 3)) ) { $ADOS_SA_CSS = 2; }
        elseif ( $ADOS_mod == "Module2" and $ADOS_social_affect_total == 4 ) { $ADOS_SA_CSS = 3; }
        elseif ( $ADOS_mod == "Module2" and $ADOS_social_affect_total == 5 ) { $ADOS_SA_CSS = 4; }
        elseif ( $ADOS_mod == "Module2" and $ADOS_social_affect_total == 6 ) { $ADOS_SA_CSS = 5; }
        elseif ( $ADOS_mod == "Module2" and in_array($ADOS_social_affect_total, range(7, 8)) ) { $ADOS_SA_CSS = 6; }
        elseif ( $ADOS_mod == "Module2" and in_array($ADOS_social_affect_total, range(9, 10)) ) { $ADOS_SA_CSS = 7; }
        elseif ( $ADOS_mod == "Module2" and $ADOS_social_affect_total == 11 ) { $ADOS_SA_CSS = 8; }
        elseif ( $ADOS_mod == "Module2" and in_array($ADOS_social_affect_total, range(12, 14)) ) { $ADOS_SA_CSS = 9; }
        elseif ( $ADOS_mod == "Module2" and in_array($ADOS_social_affect_total, range(15, 20)) ) { $ADOS_SA_CSS = 10; }

        return ($ADOS_SA_CSS);
    }

    function ADOS_RRB_CSS($ADOS_Version, $ados_a1, $ADOS_RRB_total)
    {
        $ADOS_mod = '';

        if ( $ADOS_Version == "ados_module1" or $ADOS_Version == "ados2_module1") {
            if ( $ados_a1 == 0 ) { $ADOS_mod = "Module1somewords"; }
            elseif ( $ados_a1 == 1 ) { $ADOS_mod = "Module1somewords"; }
            elseif ( $ados_a1 == 2 ) { $ADOS_mod = "Module1somewords"; }
            elseif ( $ados_a1 == 3 ) { $ADOS_mod = "Module1nowords"; }
            elseif ( $ados_a1 == 8 and $ADOS_Version == "ados_module1" ) { $ADOS_mod = "Module1nowords"; }
            elseif ( $ados_a1 == 4 and $ADOS_Version == "ados2_module1" ) { $ADOS_mod = "Module1nowords"; }
        }

        if ( $ADOS_Version == "ados_module2" ) { $ADOS_mod = "Module2"; }
        elseif ( $ADOS_Version == "ados2_module2" ) { $ADOS_mod = "Module2"; }
        elseif ( $ADOS_Version == "." ) { $ADOS_mod = "."; }

        $ADOS_RRB_CSS = '';

        if ( $ADOS_mod == "Module1nowords" and $ADOS_RRB_total == 0 ) { $ADOS_RRB_CSS = 1; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_RRB_total == 1 ) { $ADOS_RRB_CSS = 5; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_RRB_total == 2 ) { $ADOS_RRB_CSS = 6; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_RRB_total == 3 ) { $ADOS_RRB_CSS = 7; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_RRB_total == 4 ) { $ADOS_RRB_CSS = 8; }
        elseif ( $ADOS_mod == "Module1nowords" and $ADOS_RRB_total == 5 ) { $ADOS_RRB_CSS = 9; }
        elseif ( $ADOS_mod == "Module1nowords" and in_array($ADOS_RRB_total, range(6, 8)) ) { $ADOS_RRB_CSS = 10; }

        if ( $ADOS_mod == "Module1somewords" and $ADOS_RRB_total == 0 ) { $ADOS_RRB_CSS = 1; }
        elseif ( $ADOS_mod == "Module1somewords" and $ADOS_RRB_total == 1 ) { $ADOS_RRB_CSS = 5; }
        elseif ( $ADOS_mod == "Module1somewords" and $ADOS_RRB_total == 2 ) { $ADOS_RRB_CSS = 6; }
        elseif ( $ADOS_mod == "Module1somewords" and $ADOS_RRB_total == 3 ) { $ADOS_RRB_CSS = 7; }
        elseif ( $ADOS_mod == "Module1somewords" and $ADOS_RRB_total == 4 ) { $ADOS_RRB_CSS = 8; }
        elseif ( $ADOS_mod == "Module1somewords" and $ADOS_RRB_total == 5 ) { $ADOS_RRB_CSS = 9; }
        elseif ( $ADOS_mod == "Module1somewords" and in_array($ADOS_RRB_total, range(6, 8)) ) { $ADOS_RRB_CSS = 10; }

        if ( $ADOS_mod == "Module2" and $ADOS_RRB_total == 0 ) { $ADOS_RRB_CSS = 1; }
        elseif ( $ADOS_mod == "Module2" and $ADOS_RRB_total == 1 ) { $ADOS_RRB_CSS = 5; }
        elseif ( $ADOS_mod == "Module2" and $ADOS_RRB_total == 2 ) { $ADOS_RRB_CSS = 6; }
        elseif ( $ADOS_mod == "Module2" and $ADOS_RRB_total == 3 ) { $ADOS_RRB_CSS = 7; }
        elseif ( $ADOS_mod == "Module2" and $ADOS_RRB_total == 4 ) { $ADOS_RRB_CSS = 8; }
        elseif ( $ADOS_mod == "Module2" and in_array($ADOS_RRB_total, range(5, 6)) ) { $ADOS_RRB_CSS = 9; }
        elseif ( $ADOS_mod == "Module2" and in_array($ADOS_RRB_total, range(7, 8)) ) { $ADOS_RRB_CSS = 10; }

        return($ADOS_RRB_CSS);
    }
}

?>
