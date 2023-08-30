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
    use LegacyInstrumentTrait;
    use \LorisFormDictionaryImpl;

    function ADOS_SA_RRB_CSS($ADOS_Version, $ados_a1, $ADOS_overall_total, $age)
    {
	    $ADOS_SA_RRB_CSS = '';
	     $ADOS_mod = '';

       if($ADOS_Version == "ADOS2_Toddler_Module") {
                if($ados_a1 == 3 or $ados_a1 == 4)
                    $ADOS_mod = "fewNoWords";
                elseif ($ados_a1 == 0 or $ados_a1 == 1 or $ados_a1 == 2)
                    $ADOS_mod = "olderSomeWords";
       }

       if (in_array($age, range(12,20))) {
                if (in_array($ADOS_overall_total, range(0,2))) {$ADOS_SA_RRB_CSS = 1;}
                elseif (in_array($ADOS_overall_total, range(3,5))) {$ADOS_SA_RRB_CSS = 2;}
                elseif (in_array($ADOS_overall_total, range(6,9))) {$ADOS_SA_RRB_CSS = 3;}
                elseif (in_array($ADOS_overall_total, range(10,11))) {$ADOS_SA_RRB_CSS = 4;}
                elseif (in_array($ADOS_overall_total, range(12,13))) {$ADOS_SA_RRB_CSS = 5;}
                elseif (in_array($ADOS_overall_total, range(14,16))) {$ADOS_SA_RRB_CSS = 6;}
                elseif (in_array($ADOS_overall_total, range(17,18))) {$ADOS_SA_RRB_CSS = 7;}
                elseif (in_array($ADOS_overall_total, range(19,21))) {$ADOS_SA_RRB_CSS = 8;}
                elseif (in_array($ADOS_overall_total, range(22,23))) {$ADOS_SA_RRB_CSS = 9;}
                elseif (in_array($ADOS_overall_total, range(24,28))) {$ADOS_SA_RRB_CSS = 10;}
        }
       if ($ADOS_mod == "fewNoWords") {
            if (in_array($age, range(21,30))) {
                if (in_array($ADOS_overall_total, range(0,2))) {$ADOS_SA_RRB_CSS = 1;}
                elseif (in_array($ADOS_overall_total, range(3,5))) {$ADOS_SA_RRB_CSS = 2;}
                elseif (in_array($ADOS_overall_total, range(6,9))) {$ADOS_SA_RRB_CSS = 3;}
                elseif (in_array($ADOS_overall_total, range(10,11))) {$ADOS_SA_RRB_CSS = 4;}
		elseif (in_array($ADOS_overall_total, range(12,13))) {$ADOS_SA_RRB_CSS = 5;}
		elseif (in_array($ADOS_overall_total, range(14,16))) {$ADOS_SA_RRB_CSS = 6;}
                elseif (in_array($ADOS_overall_total, range(17,18))) {$ADOS_SA_RRB_CSS = 7;}
                elseif (in_array($ADOS_overall_total, range(19,21))) {$ADOS_SA_RRB_CSS = 8;}
                elseif (in_array($ADOS_overall_total, range(22,23))) {$ADOS_SA_RRB_CSS = 9;}
                elseif (in_array($ADOS_overall_total, range(24,28))) {$ADOS_SA_RRB_CSS = 10;}
	    }
       } elseif ($ADOS_mod == "olderSomeWords") {
	       if (in_array($age, range(21,30))) {
                if (in_array($ADOS_overall_total, range(0,3))) {$ADOS_SA_RRB_CSS = 1;}
                elseif (in_array($ADOS_overall_total, range(4,6))) {$ADOS_SA_RRB_CSS = 2;}
                elseif ($ADOS_overall_total == 7) {$ADOS_SA_RRB_CSS = 3;}
                elseif (in_array($ADOS_overall_total, range(8,9))) {$ADOS_SA_RRB_CSS = 4;}
                elseif (in_array($ADOS_overall_total, range(10,11))) {$ADOS_SA_RRB_CSS = 5;}
                elseif ($ADOS_overall_total == 12) {$ADOS_SA_CSS = 6;}
                elseif (in_array($ADOS_overall_total, range(13,15))) {$ADOS_SA_RRB_CSS = 7;}
                elseif (in_array($ADOS_overall_total, range(16,17))) {$ADOS_SA_RRB_CSS = 8;}
                elseif (in_array($ADOS_overall_total, range(18,20))) {$ADOS_SA_RRB_CSS = 9;}
                elseif (in_array($ADOS_overall_total, range(21,28))) {$ADOS_SA_RRB_CSS = 10;}
	    }
        }
        return($ADOS_SA_RRB_CSS);
    }

    function ADOS_SA_CSS($ADOS_Version, $ados_a1, $ADOS_social_affect_total, $age)
    {
        $ADOS_mod = '';
        if ( $ADOS_Version == "ados_module1" or $ADOS_Version == "ados2_module1" or $ADOS_Version == "ADOS2_Toddler_Module") {
            if($ADOS_Version == "ADOS2_Toddler_Module") {
                if($ados_a1 == 3 or $ados_a1 == 4)
                    $ADOS_mod = "fewNoWords";
                elseif ($ados_a1 == 0 or $ados_a1 == 1 or $ados_a1 == 2)
                    $ADOS_mod = "olderSomeWords";
            } else {
                if ($ados_a1 == 0) {
                    $ADOS_mod = "Module1somewords";
                } elseif ($ados_a1 == 1) {
                    $ADOS_mod = "Module1somewords";
                } elseif ($ados_a1 == 2) {
                    $ADOS_mod = "Module1somewords";
                } elseif ($ados_a1 == 3) {
                    $ADOS_mod = "Module1nowords";
                } elseif ($ados_a1 == 8 and $ADOS_Version == "ados_module1") {
                    $ADOS_mod = "Module1nowords";
                } elseif ($ados_a1 == 4 and $ADOS_Version == "ados2_module1") {
                    $ADOS_mod = "Module1nowords";
                }
            }
        }

        if ( $ADOS_Version == "ados_module2" ) { $ADOS_mod = "Module2"; }
        elseif ( $ADOS_Version == "ados2_module2" ) { $ADOS_mod = "Module2"; }
        elseif ( $ADOS_Version == "ados_module3" ) {$ADOS_mod = "Module3"; }
        elseif ( $ADOS_Version == "ados2_module3" ) {$ADOS_mod = "Module3"; }
        elseif ( $ADOS_Version == "." ) { $ADOS_mod = "."; }

        $ADOS_SA_CSS = '';

        if ($ADOS_mod == "Module1nowords") {
            if (in_array($age, range(24, 35)) ) {
                if (in_array($ADOS_social_affect_total, range(0,3))) {$ADOS_SA_CSS = 1;}
                elseif (in_array($ADOS_social_affect_total, range(4,5))) {$ADOS_SA_CSS = 2;}
                elseif (in_array($ADOS_social_affect_total, range(6,8))) {$ADOS_SA_CSS = 3;}
                elseif ($ADOS_social_affect_total == 9) {$ADOS_SA_CSS = 4;}
                elseif (in_array($ADOS_social_affect_total, range(10,13))) {$ADOS_SA_CSS = 5;}
                elseif (in_array($ADOS_social_affect_total, range(14,16))) {$ADOS_SA_CSS = 6;}
                elseif ($ADOS_social_affect_total == 17) {$ADOS_SA_CSS = 7;}
                elseif ($ADOS_social_affect_total == 18) {$ADOS_SA_CSS = 8;}
                elseif ($ADOS_social_affect_total == 19) {$ADOS_SA_CSS = 9;}
                elseif ($ADOS_social_affect_total == 20) {$ADOS_SA_CSS = 10;}
            } elseif (in_array($age, range(36, 47))) {
                if (in_array($ADOS_social_affect_total, range(0,3))) {$ADOS_SA_CSS = 1;}
                elseif (in_array($ADOS_social_affect_total, range(4,5))) {$ADOS_SA_CSS = 2;}
                elseif (in_array($ADOS_social_affect_total, range(6,9))) {$ADOS_SA_CSS = 3;}
                elseif ($ADOS_social_affect_total == 10) {$ADOS_SA_CSS = 4;}
                elseif (in_array($ADOS_social_affect_total, range(11,12))) {$ADOS_SA_CSS = 5;}
                elseif (in_array($ADOS_social_affect_total, range(13,16))) {$ADOS_SA_CSS = 6;}
                elseif ($ADOS_social_affect_total == 17) {$ADOS_SA_CSS = 7;}
                elseif ($ADOS_social_affect_total == 18) {$ADOS_SA_CSS = 8;}
                elseif ($ADOS_social_affect_total == 19) {$ADOS_SA_CSS = 9;}
                elseif ($ADOS_social_affect_total == 20) {$ADOS_SA_CSS = 10;}
            } elseif (in_array($age, range(48, 179))) {
                if (in_array($ADOS_social_affect_total, range(0,2))) {$ADOS_SA_CSS = 1;}
                elseif (in_array($ADOS_social_affect_total, range(3,5))) {$ADOS_SA_CSS = 2;}
                elseif (in_array($ADOS_social_affect_total, range(6,9))) {$ADOS_SA_CSS = 3;}
                elseif ($ADOS_social_affect_total == 10) {$ADOS_SA_CSS = 4;}
                elseif (in_array($ADOS_social_affect_total, range(11,12))) {$ADOS_SA_CSS = 5;}
                elseif (in_array($ADOS_social_affect_total, range(13,14))) {$ADOS_SA_CSS = 6;}
                elseif (in_array($ADOS_social_affect_total, range(15,16))) {$ADOS_SA_CSS = 7;}
                elseif (in_array($ADOS_social_affect_total, range(17,18))) {$ADOS_SA_CSS = 8;}
                elseif ($ADOS_social_affect_total == 19) {$ADOS_SA_CSS = 9;}
                elseif ($ADOS_social_affect_total == 20) {$ADOS_SA_CSS = 10;}
            }
        } elseif ($ADOS_mod == "Module1somewords") {
            if (in_array($age, range(24,47))) {
                if (in_array($ADOS_social_affect_total, range(0,1))) {$ADOS_SA_CSS = 1;}
                elseif (in_array($ADOS_social_affect_total, range(2,4))) {$ADOS_SA_CSS = 2;}
                elseif ($ADOS_social_affect_total == 5) {$ADOS_SA_CSS = 3;}
                elseif (in_array($ADOS_social_affect_total, range(6,7))) {$ADOS_SA_CSS = 4;}
                elseif ($ADOS_social_affect_total == 8) {$ADOS_SA_CSS = 5;}
                elseif (in_array($ADOS_social_affect_total, range(9,11))) {$ADOS_SA_CSS = 6;}
                elseif (in_array($ADOS_social_affect_total, range(12,13))) {$ADOS_SA_CSS = 7;}
                elseif (in_array($ADOS_social_affect_total, range(14,15))) {$ADOS_SA_CSS = 8;}
                elseif (in_array($ADOS_social_affect_total, range(16,17))) {$ADOS_SA_CSS = 9;}
                elseif (in_array($ADOS_social_affect_total, range(18,20))) {$ADOS_SA_CSS = 10;}
            } elseif (in_array($age, range(48,59))) {
                if (in_array($ADOS_social_affect_total, range(0,1))) {$ADOS_SA_CSS = 1;}
                elseif (in_array($ADOS_social_affect_total, range(2,3))) {$ADOS_SA_CSS = 2;}
                elseif (in_array($ADOS_social_affect_total, range(4,5))) {$ADOS_SA_CSS = 3;}
                elseif (in_array($ADOS_social_affect_total, range(6,7))) {$ADOS_SA_CSS = 4;}
                elseif (in_array($ADOS_social_affect_total, range(8,9))) {$ADOS_SA_CSS = 5;}
                elseif (in_array($ADOS_social_affect_total, range(10,12))) {$ADOS_SA_CSS = 6;}
                elseif ($ADOS_social_affect_total == 13) {$ADOS_SA_CSS = 7;}
                elseif (in_array($ADOS_social_affect_total, range(14,15))) {$ADOS_SA_CSS = 8;}
                elseif (in_array($ADOS_social_affect_total, range(16,17))) {$ADOS_SA_CSS = 9;}
                elseif (in_array($ADOS_social_affect_total, range(18,20))) {$ADOS_SA_CSS = 10;}
            } elseif (in_array($age, range(60,179))) {
                if (in_array($ADOS_social_affect_total, range(0, 1))) {
                    $ADOS_SA_CSS = 1;
                } elseif (in_array($ADOS_social_affect_total, range(2, 3))) {
                    $ADOS_SA_CSS = 2;
                } elseif (in_array($ADOS_social_affect_total, range(4, 5))) {
                    $ADOS_SA_CSS = 3;
                } elseif (in_array($ADOS_social_affect_total, range(6, 7))) {
                    $ADOS_SA_CSS = 4;
                } elseif (in_array($ADOS_social_affect_total, range(8, 9))) {
                    $ADOS_SA_CSS = 5;
                } elseif (in_array($ADOS_social_affect_total, range(10, 13))) {
                    $ADOS_SA_CSS = 6;
                } elseif (in_array($ADOS_social_affect_total, range(14, 15))) {
                    $ADOS_SA_CSS = 7;
                } elseif ($ADOS_social_affect_total == 16) {
                    $ADOS_SA_CSS = 8;
                } elseif (in_array($ADOS_social_affect_total, range(17, 18))) {
                    $ADOS_SA_CSS = 9;
                } elseif (in_array($ADOS_social_affect_total, range(19, 20))) {
                    $ADOS_SA_CSS = 10;
                }
            }
        } elseif ($ADOS_mod == "Module2") {
            if (in_array($age, range(24,47))) {
                if (in_array($ADOS_social_affect_total, range(0,1))) {$ADOS_SA_CSS = 1;}
                elseif (in_array($ADOS_social_affect_total, range(2,3))) {$ADOS_SA_CSS = 2;}
                elseif ($ADOS_social_affect_total == 4) {$ADOS_SA_CSS = 3;}
                elseif ($ADOS_social_affect_total == 5) {$ADOS_SA_CSS = 4;}
                elseif ($ADOS_social_affect_total == 6) {$ADOS_SA_CSS = 5;}
                elseif (in_array($ADOS_social_affect_total, range(7,8))) {$ADOS_SA_CSS = 6;}
                elseif (in_array($ADOS_social_affect_total, range(9,10))) {$ADOS_SA_CSS = 7;}
                elseif ($ADOS_social_affect_total == 11) {$ADOS_SA_CSS = 8;}
                elseif (in_array($ADOS_social_affect_total, range(12,14))) {$ADOS_SA_CSS = 9;}
                elseif (in_array($ADOS_social_affect_total, range(15,20))) {$ADOS_SA_CSS = 10;}
            } elseif (in_array($age, range(48,59))) {
                if (in_array($ADOS_social_affect_total, range(0,1))) {$ADOS_SA_CSS = 1;}
                elseif ($ADOS_social_affect_total == 2) {$ADOS_SA_CSS = 2;}
                elseif (in_array($ADOS_social_affect_total, range(3,4))) {$ADOS_SA_CSS = 3;}
                elseif (in_array($ADOS_social_affect_total, range(5,6))) {$ADOS_SA_CSS = 4;}
                elseif ($ADOS_social_affect_total == 7) {$ADOS_SA_CSS = 5;}
                elseif (in_array($ADOS_social_affect_total, range(8,9))) {$ADOS_SA_CSS = 6;}
                elseif (in_array($ADOS_social_affect_total, range(10,11))) {$ADOS_SA_CSS = 7;}
                elseif (in_array($ADOS_social_affect_total, range(12,13))) {$ADOS_SA_CSS = 8;}
                elseif (in_array($ADOS_social_affect_total, range(14,15))) {$ADOS_SA_CSS = 9;}
                elseif (in_array($ADOS_social_affect_total, range(16,20))) {$ADOS_SA_CSS = 10;}
            } elseif (in_array($age, range(60,83))) {
                if (in_array($ADOS_social_affect_total, range(0,1))) {$ADOS_SA_CSS = 1;}
                elseif (in_array($ADOS_social_affect_total, range(2,3))) {$ADOS_SA_CSS = 2;}
                elseif (in_array($ADOS_social_affect_total, range(4,5))) {$ADOS_SA_CSS = 3;}
                elseif ($ADOS_social_affect_total == 6) {$ADOS_SA_CSS = 4;}
                elseif ($ADOS_social_affect_total == 7) {$ADOS_SA_CSS = 5;}
                elseif (in_array($ADOS_social_affect_total, range(8,9))) {$ADOS_SA_CSS = 6;}
                elseif (in_array($ADOS_social_affect_total, range(10,11))) {$ADOS_SA_CSS = 7;}
                elseif (in_array($ADOS_social_affect_total, range(12,15))) {$ADOS_SA_CSS = 8;}
                elseif ($ADOS_social_affect_total == 16) {$ADOS_SA_CSS = 9;}
                elseif (in_array($ADOS_social_affect_total, range(17,20))) {$ADOS_SA_CSS = 10;}
            } elseif (in_array($age, range(84,203))) {
                if (in_array($ADOS_social_affect_total, range(0,1))) {$ADOS_SA_CSS = 1;}
                elseif ($ADOS_social_affect_total == 2) {$ADOS_SA_CSS = 2;}
                elseif (in_array($ADOS_social_affect_total, range(3,4))) {$ADOS_SA_CSS = 3;}
                elseif ($ADOS_social_affect_total == 5) {$ADOS_SA_CSS = 4;}
                elseif (in_array($ADOS_social_affect_total, range(6,7))) {$ADOS_SA_CSS = 5;}
                elseif (in_array($ADOS_social_affect_total, range(8,10))) {$ADOS_SA_CSS = 6;}
                elseif (in_array($ADOS_social_affect_total, range(11,13))) {$ADOS_SA_CSS = 7;}
                elseif (in_array($ADOS_social_affect_total, range(14,15))) {$ADOS_SA_CSS = 8;}
                elseif (in_array($ADOS_social_affect_total, range(16,17))) {$ADOS_SA_CSS = 9;}
                elseif (in_array($ADOS_social_affect_total, range(18,20))) {$ADOS_SA_CSS = 10;}
            }
        } elseif ($ADOS_mod == "Module3") {
            if (in_array($age, range(36,83))) {
                if (in_array($ADOS_social_affect_total, range(0,2))) {$ADOS_SA_CSS = 1;}
                elseif ($ADOS_social_affect_total == 3) {$ADOS_SA_CSS = 2;}
                elseif ($ADOS_social_affect_total == 4) {$ADOS_SA_CSS = 3;}
                elseif ($ADOS_social_affect_total == 5) {$ADOS_SA_CSS = 4;}
                elseif ($ADOS_social_affect_total == 6) {$ADOS_SA_CSS = 5;}
                elseif (in_array($ADOS_social_affect_total, range(7,8))) {$ADOS_SA_CSS = 6;}
                elseif (in_array($ADOS_social_affect_total, range(9,10))) {$ADOS_SA_CSS = 7;}
                elseif (in_array($ADOS_social_affect_total, range(11,12))) {$ADOS_SA_CSS = 8;}
                elseif (in_array($ADOS_social_affect_total, range(13,14))) {$ADOS_SA_CSS = 9;}
                elseif (in_array($ADOS_social_affect_total, range(15,20))) {$ADOS_SA_CSS = 10;}
            } elseif (in_array($age, range(84,203))) {
                if (in_array($ADOS_social_affect_total, range(0,1))) {$ADOS_SA_CSS = 1;}
                elseif ($ADOS_social_affect_total == 2) {$ADOS_SA_CSS = 2;}
                elseif (in_array($ADOS_social_affect_total, range(3,4))) {$ADOS_SA_CSS = 3;}
                elseif ($ADOS_social_affect_total == 5) {$ADOS_SA_CSS = 4;}
                elseif ($ADOS_social_affect_total == 6) {$ADOS_SA_CSS = 5;}
                elseif ($ADOS_social_affect_total == 7) {$ADOS_SA_CSS = 6;}
                elseif (in_array($ADOS_social_affect_total, range(8,9))) {$ADOS_SA_CSS = 7;}
                elseif (in_array($ADOS_social_affect_total, range(10,11))) {$ADOS_SA_CSS = 8;}
                elseif (in_array($ADOS_social_affect_total, range(12,14))) {$ADOS_SA_CSS = 9;}
                elseif (in_array($ADOS_social_affect_total, range(15,20))) {$ADOS_SA_CSS = 10;}
            }
        } elseif ($ADOS_mod == "fewNoWords") {
            if (in_array($age, range(24,30))) {
                if (in_array($ADOS_social_affect_total, range(0,2))) {$ADOS_SA_CSS = 1;}
                elseif (in_array($ADOS_social_affect_total, range(3,4))) {$ADOS_SA_CSS = 2;}
                elseif (in_array($ADOS_social_affect_total, range(5,6))) {$ADOS_SA_CSS = 3;}
                elseif (in_array($ADOS_social_affect_total, range(7,9))) {$ADOS_SA_CSS = 4;}
		elseif ($ADOS_social_affect_total == 10) {$ADOS_SA_CSS = 5;}
		elseif (in_array($ADOS_social_affect_total, range(11,12))) {$ADOS_SA_CSS = 6;}
                elseif (in_array($ADOS_social_affect_total, range(13,14))) {$ADOS_SA_CSS = 7;}
                elseif (in_array($ADOS_social_affect_total, range(15,16))) {$ADOS_SA_CSS = 8;}
                elseif (in_array($ADOS_social_affect_total, range(17,18))) {$ADOS_SA_CSS = 9;}
                elseif (in_array($ADOS_social_affect_total, range(19,20))) {$ADOS_SA_CSS = 10;}
            } elseif (in_array($age, range(31,47))) {
                if (in_array($ADOS_social_affect_total, range(0,3))) {$ADOS_SA_CSS = 1;}
                elseif (in_array($ADOS_social_affect_total, range(4,5))) {$ADOS_SA_CSS = 2;}
                elseif (in_array($ADOS_social_affect_total, range(6,9))) {$ADOS_SA_CSS = 3;}
                elseif ($ADOS_social_affect_total == 10) {$ADOS_SA_CSS = 4;}
                elseif (in_array($ADOS_social_affect_total, range(11,12))) {$ADOS_SA_CSS = 5;}
                elseif (in_array($ADOS_social_affect_total, range(13,16))) {$ADOS_SA_CSS = 6;}
                elseif ($ADOS_social_affect_total == 17) {$ADOS_SA_CSS = 7;}
                elseif ($ADOS_social_affect_total == 18) {$ADOS_SA_CSS = 8;}
                elseif ($ADOS_social_affect_total == 19) {$ADOS_SA_CSS = 9;}
                elseif ($ADOS_social_affect_total == 20) {$ADOS_SA_CSS = 10;}
            } elseif (in_array($age, range(48,173))) {
                if (in_array($ADOS_social_affect_total, range(0,2))) {$ADOS_SA_CSS = 1;}
                elseif (in_array($ADOS_social_affect_total, range(3,5))) {$ADOS_SA_CSS = 2;}
                elseif (in_array($ADOS_social_affect_total, range(6,9))) {$ADOS_SA_CSS = 3;}
                elseif ($ADOS_social_affect_total == 10) {$ADOS_SA_CSS = 4;}
                elseif (in_array($ADOS_social_affect_total, range(11,12))) {$ADOS_SA_CSS = 5;}
                elseif (in_array($ADOS_social_affect_total, range(13,14))) {$ADOS_SA_CSS = 6;}
                elseif (in_array($ADOS_social_affect_total, range(15,16))) {$ADOS_SA_CSS = 7;}
                elseif (in_array($ADOS_social_affect_total, range(17,18))) {$ADOS_SA_CSS = 8;}
                elseif ($ADOS_social_affect_total == 19) {$ADOS_SA_CSS = 9;}
                elseif ($ADOS_social_affect_total == 20) {$ADOS_SA_CSS = 10;}
            }
	} elseif ($ADOS_mod == "olderSomeWords") {
	     if (in_array($age, range(24,30))) {
                if (in_array($ADOS_social_affect_total, range(0,1))) {$ADOS_SA_CSS = 1;}
                elseif (in_array($ADOS_social_affect_total, range(2,3))) {$ADOS_SA_CSS = 2;}
                elseif (in_array($ADOS_social_affect_total, range(4,5))) {$ADOS_SA_CSS = 3;}
                elseif (in_array($ADOS_social_affect_total, range(6,8))) {$ADOS_SA_CSS = 4;}
                elseif (in_array($ADOS_social_affect_total, range(9,10))) {$ADOS_SA_CSS = 5;}
                elseif ($ADOS_social_affect_total == 11) {$ADOS_SA_CSS = 6;}
                elseif (in_array($ADOS_social_affect_total, range(12,13))) {$ADOS_SA_CSS = 7;}
                elseif (in_array($ADOS_social_affect_total, range(14,15))) {$ADOS_SA_CSS = 8;}
                elseif (in_array($ADOS_social_affect_total, range(16,18))) {$ADOS_SA_CSS = 9;}
                elseif (in_array($ADOS_social_affect_total, range(19,22))) {$ADOS_SA_CSS = 10;}
	    } elseif (in_array($age, range(31, 47))) {
                if (in_array($ADOS_social_affect_total, range(0,1))) {$ADOS_SA_CSS = 1;}
                elseif (in_array($ADOS_social_affect_total, range(2,4))) {$ADOS_SA_CSS = 2;}
                elseif ($ADOS_social_affect_total == 5) {$ADOS_SA_CSS = 3;}
                elseif (in_array($ADOS_social_affect_total, range(6, 7))) {$ADOS_SA_CSS = 4;}
                elseif ($ADOS_social_affect_total == 8) {$ADOS_SA_CSS = 5;}
                elseif (in_array($ADOS_social_affect_total, range(9,11))) {$ADOS_SA_CSS = 6;}
                elseif (in_array($ADOS_social_affect_total, range(12,13))) {$ADOS_SA_CSS = 7;}
                elseif (in_array($ADOS_social_affect_total, range(14,15))) {$ADOS_SA_CSS = 8;}
                elseif (in_array($ADOS_social_affect_total, range(16,17))) {$ADOS_SA_CSS = 9;}
                elseif (in_array($ADOS_social_affect_total, range(18,20))) {$ADOS_SA_CSS = 10;}
            } elseif (in_array($age, range(48,59))) {
                if (in_array($ADOS_social_affect_total, range(0,1))) {$ADOS_SA_CSS = 1;}
                elseif (in_array($ADOS_social_affect_total, range(2,3))) {$ADOS_SA_CSS = 2;}
                elseif (in_array($ADOS_social_affect_total, range(4,5))) {$ADOS_SA_CSS = 3;}
                elseif (in_array($ADOS_social_affect_total, range(6, 7))) {$ADOS_SA_CSS = 4;}
                elseif (in_array($ADOS_social_affect_total, range(8, 9))) {$ADOS_SA_CSS = 5;}
                elseif (in_array($ADOS_social_affect_total, range(10,12))) {$ADOS_SA_CSS = 6;}
                elseif ($ADOS_social_affect_total == 13) {$ADOS_SA_CSS = 7;}
                elseif (in_array($ADOS_social_affect_total, range(14,15))) {$ADOS_SA_CSS = 8;}
                elseif (in_array($ADOS_social_affect_total, range(16,17))) {$ADOS_SA_CSS = 9;}
                elseif (in_array($ADOS_social_affect_total, range(18,20))) {$ADOS_SA_CSS = 10;}
            } elseif (in_array($age, range(60,179))) {
                if (in_array($ADOS_social_affect_total, range(0,1))) {$ADOS_SA_CSS = 1;}
                elseif (in_array($ADOS_social_affect_total, range(2,3))) {$ADOS_SA_CSS = 2;}
                elseif (in_array($ADOS_social_affect_total, range(4,5))) {$ADOS_SA_CSS = 3;}
                elseif (in_array($ADOS_social_affect_total, range(6, 7))) {$ADOS_SA_CSS = 4;}
                elseif (in_array($ADOS_social_affect_total, range(8, 9))) {$ADOS_SA_CSS = 5;}
                elseif (in_array($ADOS_social_affect_total, range(10,13))) {$ADOS_SA_CSS = 6;}
                elseif (in_array($ADOS_social_affect_total, range(14,15))) {$ADOS_SA_CSS = 7;}
                elseif ($ADOS_social_affect_total == 16) {$ADOS_SA_CSS = 8;}
                elseif (in_array($ADOS_social_affect_total, range(17,18))) {$ADOS_SA_CSS = 9;}
                elseif (in_array($ADOS_social_affect_total, range(19,20))) {$ADOS_SA_CSS = 10;}
            }
        }
        return($ADOS_SA_CSS);
    }


    function ADOS_RRB_CSS($ADOS_Version, $ados_a1, $ADOS_RRB_total, $age)
    {
        $ADOS_mod = '';

        if ( $ADOS_Version == "ados_module1" or $ADOS_Version == "ados2_module1" or $ADOS_Version == "ADOS2_Toddler_Module") {
            if ( $ados_a1 == 0 ) { $ADOS_mod = "Module1somewords"; }
            elseif ( $ados_a1 == 1 ) { $ADOS_mod = "Module1somewords"; }
            elseif ( $ados_a1 == 2 ) { $ADOS_mod = "Module1somewords"; }
            elseif ( $ados_a1 == 3 ) { $ADOS_mod = "Module1nowords"; }
            elseif ( $ados_a1 == 8 and $ADOS_Version == "ados_module1" ) { $ADOS_mod = "Module1nowords"; }
            elseif ( $ados_a1 == 4 and $ADOS_Version == "ados2_module1" ) { $ADOS_mod = "Module1nowords"; }
        }

        if ( $ADOS_Version == "ados_module2" ) { $ADOS_mod = "Module2"; }
        elseif ( $ADOS_Version == "ados2_module2" ) { $ADOS_mod = "Module2"; }
        elseif ( $ADOS_Version == "ados_module3" ) {$ADOS_mod = "Module3"; }
        elseif ( $ADOS_Version == "ados2_module3" ) {$ADOS_mod = "Module3"; }
        elseif ( $ADOS_Version == "." ) { $ADOS_mod = "."; }

        $ADOS_RRB_CSS = '';

        if ($ADOS_mod == "Module1nowords") {
            if (in_array($age, range(24,35))) {
		if ($ADOS_RRB_total == 0) {$ADOS_RRB_CSS = 1;}
		elseif (in_array($ADOS_RRB_total, range(1, 2))) {$ADOS_RRB_CSS = 5;}
                elseif ($ADOS_RRB_total == 3) {$ADOS_RRB_CSS = 6;}
                elseif ($ADOS_RRB_total == 4) {$ADOS_RRB_CSS = 7;}
                elseif ($ADOS_RRB_total == 5) {$ADOS_RRB_CSS = 8;}
                elseif ($ADOS_RRB_total == 6) {$ADOS_RRB_CSS = 9;}
                elseif (in_array($ADOS_RRB_total, range(7, 8))) {$ADOS_RRB_CSS = 10;}
            } elseif (in_array($age, range(36,47))) {
                if ($ADOS_RRB_total == 0) {$ADOS_RRB_CSS = 1;}
                elseif ($ADOS_RRB_total == 1) {$ADOS_RRB_CSS = 5;}
                elseif (in_array($ADOS_RRB_total, range(2, 3))) {$ADOS_RRB_CSS = 6;}
                elseif ($ADOS_RRB_total == 4) {$ADOS_RRB_CSS = 7;}
                elseif ($ADOS_RRB_total == 5) {$ADOS_RRB_CSS = 8;}
                elseif ($ADOS_RRB_total == 6) {$ADOS_RRB_CSS = 9;}
                elseif (in_array($ADOS_RRB_total, range(7, 8))) {$ADOS_RRB_CSS = 10;}
            } elseif (in_array($age, range(48, 179))) {
                if ($ADOS_RRB_total == 0) {$ADOS_RRB_CSS = 1;}
                elseif (in_array($ADOS_RRB_total, range(1,2))) {$ADOS_RRB_CSS = 5;}
                elseif ($ADOS_RRB_total == 3) {$ADOS_RRB_CSS = 6;}
                elseif ($ADOS_RRB_total == 4) {$ADOS_RRB_CSS = 7;}
                elseif (in_array($ADOS_RRB_total, range(5,6))) {$ADOS_RRB_CSS = 8;}
                elseif ($ADOS_RRB_total == 7) {$ADOS_RRB_CSS = 9;}
                elseif ($ADOS_RRB_total == 8) {$ADOS_RRB_CSS = 10;}
            }
        } elseif ($ADOS_mod == "Module1somewords") {
            if (in_array($age, range(24,47))) {
                if ($ADOS_RRB_total == 0) {$ADOS_RRB_CSS = 1;}
                elseif ($ADOS_RRB_total == 1) {$ADOS_RRB_CSS = 5;}
                elseif ($ADOS_RRB_total == 2) {$ADOS_RRB_CSS = 6;}
                elseif ($ADOS_RRB_total == 3) {$ADOS_RRB_CSS = 7;}
                elseif ($ADOS_RRB_total == 4) {$ADOS_RRB_CSS = 8;}
                elseif ($ADOS_RRB_total == 5) {$ADOS_RRB_CSS = 9;}
                elseif (in_array($ADOS_RRB_total, range(6, 8))) {$ADOS_RRB_CSS = 10;}
            } elseif (in_array($age, range(48,59))) {
                if ($ADOS_RRB_total == 0) {$ADOS_RRB_CSS = 1;}
                elseif ($ADOS_RRB_total == 1) {$ADOS_RRB_CSS = 5;}
                elseif ($ADOS_RRB_total == 2) {$ADOS_RRB_CSS = 6;}
                elseif (in_array($ADOS_RRB_total, range(3, 4))) {$ADOS_RRB_CSS = 7;}
                elseif ($ADOS_RRB_total == 5) {$ADOS_RRB_CSS = 8;}
                elseif ($ADOS_RRB_total == 6) {$ADOS_RRB_CSS = 9;}
                elseif (in_array($ADOS_RRB_total, range(7, 8))) {$ADOS_RRB_CSS = 10;}
            } elseif (in_array($age, range(60,179))) {
                if ($ADOS_RRB_total == 0) {$ADOS_RRB_CSS = 1;}
                elseif ($ADOS_RRB_total == 1) {$ADOS_RRB_CSS = 5;}
                elseif (in_array($ADOS_RRB_total, range(2,3))) {$ADOS_RRB_CSS = 6;}
                elseif ($ADOS_RRB_total == 4) {$ADOS_RRB_CSS = 7;}
                elseif ($ADOS_RRB_total == 5) {$ADOS_RRB_CSS = 8;}
                elseif ($ADOS_RRB_total == 6) {$ADOS_RRB_CSS = 9;}
                elseif (in_array($ADOS_RRB_total, range(7, 8))) {$ADOS_RRB_CSS = 10;}
            }
        } elseif ($ADOS_mod == "Module2") {
            if (in_array($age, range(24,47))) {
                if ($ADOS_RRB_total == 0) {$ADOS_RRB_CSS = 1;}
                elseif ($ADOS_RRB_total == 1) {$ADOS_RRB_CSS = 5;}
                elseif ($ADOS_RRB_total == 2) {$ADOS_RRB_CSS = 6;}
                elseif ($ADOS_RRB_total == 3) {$ADOS_RRB_CSS = 7;}
                elseif ($ADOS_RRB_total == 4) {$ADOS_RRB_CSS = 8;}
                elseif (in_array($ADOS_RRB_total, range(5,6))) {$ADOS_RRB_CSS = 9;}
                elseif (in_array($ADOS_RRB_total, range(7,8))) {$ADOS_RRB_CSS = 10;}
            } elseif (in_array($age, range(48,203))) {
                if ($ADOS_RRB_total == 0) {$ADOS_RRB_CSS = 1;}
                elseif ($ADOS_RRB_total == 1) {$ADOS_RRB_CSS = 5;}
                elseif (in_array($ADOS_RRB_total, range(2,3))) {$ADOS_RRB_CSS = 6;}
                elseif ($ADOS_RRB_total == 4) {$ADOS_RRB_CSS = 7;}
                elseif ($ADOS_RRB_total == 5) {$ADOS_RRB_CSS = 8;}
                elseif ($ADOS_RRB_total == 6) {$ADOS_RRB_CSS = 9;}
                elseif (in_array($ADOS_RRB_total, range(7, 8))) {$ADOS_RRB_CSS = 10;}
            }
        } elseif ($ADOS_mod == "Module3") {
            if (in_array($age, range(36,83))) {
                if ($ADOS_RRB_total == 0) {$ADOS_RRB_CSS = 1;}
                elseif ($ADOS_RRB_total == 1) {$ADOS_RRB_CSS = 5;}
                elseif ($ADOS_RRB_total == 2) {$ADOS_RRB_CSS = 7;}
                elseif ($ADOS_RRB_total == 3) {$ADOS_RRB_CSS = 8;}
                elseif ($ADOS_RRB_total == 4) {$ADOS_RRB_CSS = 9;}
                elseif (in_array($ADOS_RRB_total, range(5,8))) {$ADOS_RRB_CSS = 10;}
            } elseif (in_array($age, range(84,203))) {
                if ($ADOS_RRB_total == 0) {$ADOS_RRB_CSS = 1;}
                elseif ($ADOS_RRB_total == 1) {$ADOS_RRB_CSS = 5;}
                elseif ($ADOS_RRB_total == 2) {$ADOS_RRB_CSS = 7;}
                elseif ($ADOS_RRB_total == 3) {$ADOS_RRB_CSS = 8;}
                elseif (in_array($ADOS_RRB_total, range(4, 5))) {$ADOS_RRB_CSS = 9;}
                elseif (in_array($ADOS_RRB_total, range(6,8))) {$ADOS_RRB_CSS = 10;}
            }
        }
        return($ADOS_RRB_CSS);
    }
}

?>
