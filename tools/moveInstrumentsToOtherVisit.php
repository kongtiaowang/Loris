<?php
/**
*  Produce an SQL file on STDOUT with the instructions needed to move instruments 
*  from a visit VFROM to another visit VTO for a given candidate C. Conditions under
*  which such a move can take place:
*
*   - Candidate C has to be active.
*   - VFROM has to be active and must contain at least one instrument or survey.
*   - VTO must be active and must be in stage 'Visit'.
*   - Obviously, VFROM must be different than VTO.
*
*  The script will only move from VFROM the instruments that meet these criteria:
*  - The instrument is a survey and a survey with the same name does not exist in VTO
*       OR
*    The instrument is not a survey and there is an instrument with the same name in visit VTO
*  - The instrument's data entry status in VFROM is not null (i.e there's something in it).
*
* Note that instruments are *moved*, they are not copied (i.e they cease to be part of visit VFROM
* and will be part of visit VTO). 
* This script outputs should be redirected to a file, which can then be sourced in mysql to effectively
* accomplish the move. It is strongly recommended to run the SQL instructions produced by the script 
* inside a transaction such that if an error arises, the moved can be be rolled back and the database 
* left unchanged. 
*
* Usage: moveInstrumentsToOtherVisit CandID VisitLabelFrom VisitLabelTo
*
*  PHP Version 7
*
*  @category Tools
*  @package  Tools
*  @author   Nicolas Brossard
**/
set_include_path(get_include_path().":../libraries:../../php/libraries:");
require_once '../../vendor/autoload.php';

const NB_ARGUMENTS = 3;

// Main
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../config.xml');

//==============================//
// Validate script arguments    //
//==============================//

if ($argc != NB_ARGUMENTS+1) {
    exit("Usage: moveInstrumentsToOtherVisit.php CandID FromVisitLabel ToVisitLabel\n");
}

list($candID, $fromVisitLabel, $toVisitLabel) = array_slice($argv, 1);

//-----------------------------------------//
// Ensure candidate exists and is active   //
//-----------------------------------------//

try {
    $candidate = Candidate::singleton((int) $candID);
} catch(Exception $e) {
    exit("No active candidate with ID $candID was found in the database. Aborting\n");
}

$visitLabels = $candidate->getListOfVisitLabels();

//----------------------------------------------//
// Ensure visit label to and visit label from   //
// are valid                                    //
//----------------------------------------------//

$fromSessionID = array_search($fromVisitLabel, $visitLabels);
$fromSessionID or exit("No active visit $fromVisitLabel found for candidate $candID. Aborting.\n");

$toSessionID = array_search($toVisitLabel, $visitLabels);
$toSessionID or exit("No active visit $toVisitLabel found for candidate $candID. Aborting.\n");

//-------------------------------------------//
// Ensure $fromVisitLabel != $toVisitLabel   //
//-------------------------------------------//

$fromVisitLabel != $toVisitLabel
    or exit("From visit label and to visit label cannot be identical. Aborting.\n");

// Build test battery of session to move from and ensure it's not empty
$fromBattery = new NDB_BVL_Battery();
$fromBattery->selectBattery($fromSessionID);
$fromInstruments = $fromBattery->getBatteryVerbose();
!empty($fromInstruments)
    or exit("No instruments to move (maybe visit was not started?). Aborting.\n");

// Build test battery of session to move to
$toTimepoint = Timepoint::singleton($toSessionID);
$toTimepoint->getCurrentStage() == 'Visit'
    or exit("Visit $toVisitLabel is not in 'Visit' stage. Aborting.\n");

$toBattery = new NDB_BVL_Battery();
$toBattery->selectBattery($toSessionID);
$toInstruments = $toBattery->getBatteryVerbose();

//---------------------------------------------//
// Move all instruments that *can* be moved    //
//---------------------------------------------//
$notMovedComments = [];
foreach ($fromInstruments as $fromInstrument) {
    $fromInstrumentStatus = new NDB_BVL_InstrumentStatus();
    $fromInstrumentStatus->select($fromInstrument['CommentID']);

    // Empty instruments (i.e non-surveys) are not moved, but empty surveys are.
    if (is_null($fromInstrumentStatus->getDataEntryStatus()) && !$fromInstrument['isDirectEntry']) {
        $notMovedComments[] = "-- Instrument {$fromInstrument['Test_name']} has not "
                            . "been filled out yet. Skipping.\n";
        continue;
    }

    $toInstrument = getInstrument($fromInstrument['Test_name'], $toInstruments);
    // If the instrument to move is not a instrument and there's not an instrument
    // with the same name in the battery of session $toVisitLabel, skip this instrument
    if (!$fromInstrument['isDirectEntry'] && is_null($toInstrument)) {
        $notMovedComments[] = "-- Instrument {$fromInstrument['Test_name']} is not "
                            . "direct entry and is not in visit $toVisitLabel: skipping.\n";
    // If the instrumnent to move is a survey but there's already a survey with the same name
    // that was administered at visit $toVisitLabel
    } elseif ($fromInstrument['isDirectEntry'] && !is_null($toInstrument)) {
        exit("Cannot move direct entry instrument $testName from $fromVisitLavel "
           . "to $toVisitLabel: instrument already exists at that visit. Aborting.\n");
    // Instrument can be moved
    } else {
        print $fromInstrument['isDirectEntry']
           ? "-- Moving survey {$fromInstrument['Test_name']}.\n"
           : "-- Moving instrument {$fromInstrument['Test_name']}.\n";

        // This will link the "from" instrument to the "to" session
        print "UPDATE flag "
            . "SET SessionID = $toSessionID "
            . "WHERE CommentID IN ('{$fromInstrument['CommentID']}', '{$fromInstrument['DDECommentID']}');\n";
  
        // Instrument to move is a survey
        if ($fromInstrument['isDirectEntry']) {
            print "UPDATE participant_accounts "
                . "SET SessionID = $toSessionID "
                . "WHERE SessionID = $fromSessionID "
                . "AND test_name = '{$fromInstrument['Test_name']}';\n";
        // Instrument to move is not a survey
        } else {
            // Delete the instrument data in the instrument table.
            // For JSON instruments, this query will not do anything.
            print "DELETE FROM {$fromInstrument['Test_name']} "
                . "WHERE CommentID IN ('{$toInstrument['CommentID']}', '{$toInstrument['DDECommentID']}');\n";
            // Delete moved instrument from the flag table
            print "DELETE FROM flag "
                . "WHERE CommentID IN ('{$toInstrument['CommentID']}', '{$toInstrument['DDECommentID']}');\n";
        }
        print "\n";
    }
}

foreach($notMovedComments as $comment) {
    print $comment;
}

exit(0);

/**
 * Find an instrument with a given name in a battery of instruments.
 * 
 * @param $testName      string name of the test to search for.
 * @param $toInstruments array  list of instruments in which to perform the search.
 *
 * @return array matching element in battery $toInstruments or null if no match was found.
 */ 
function getInstrument(string $testName, array $toInstruments)
{
    foreach($toInstruments as $toInstrument) {
        if ($toInstrument['Test_name'] == $testName) {
            return $toInstrument;
        }
    }

    return null;
}
