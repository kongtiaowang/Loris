<?php
/**
*  Move instrument data from one candidate to another
*
*  PHP Version 7
*
*  @category Tools
*  @package  Tools
*  @author   Gregory Luneau <gregory.luneau@mcgill.ca>
*  @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
*  @version  GIT: <git_id>
*  @link     https://www.github.com/aces/IBIS/
**/
set_include_path(get_include_path().":../libraries:../../php/libraries:");
require_once '../../vendor/autoload.php';

// Main
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../config.xml');
$db = Database::singleton();

$confirm = false;
if (!empty($argv[2]) && $argv[2] == 'confirm') {
    $confirm = true;
}

// CandidateGUID, ProbandGUID
// php moveInstrumentToOtherCandidate.php UNC0236_55555_V06 UNC0235_444444_V06 aosi

$column = $argv[1];


$results = $db->pselect(
    "SELECT PSCID, CandID, Testdate, {$column} from candidate " .
    "WHERE {$column} != :notEmpty ORDER BY PSCID",
    array('notEmpty' => '')
);

$ParameterTypeID = $db->pselectOne(
    "SELECT ParameterTypeID FROM parameter_type " .
    "WHERE name = :cld",
    array('cld' => $column)
);

if (empty($ParameterTypeID)) {
    print "It can't be done until a ParameterTypeID for {$column} is created.\n";
    exit;
}


foreach ($results as $r) {
    print "{$r['PSCID']}-{$column}-{$ParameterTypeID}-{$r[$column]}\n";

    $count = $db->pselectOne(
        "SELECT count(*) from parameter_candidate WHERE CandID = :CID " .
        "AND ParameterTypeID = :prtid",
        array(
         'CID'   => $r['CandID'],
         'prtid' => $ParameterTypeID,
        )
    );

    if (empty($count)) {
        if ($confirm) {
            $db->insert(
                'parameter_candidate',
                array(
                 'CandID'          => $r['CandID'],
                 'ParameterTypeID' => $ParameterTypeID,
                 'Value'           => $r[$column],
                 'InsertTime'      => strtotime($r['Testdate']),
                )
            );
        }
    } else {
        if ($confirm) {
            $db->update(
                'parameter_candidate',
                array(
                 'Value'      => $r[$column],
                 'InsertTime' => strtotime($r['Testdate']),
                ),
                array(
                 'CandID'          => $r['CandID'],
                 'ParameterTypeID' => $ParameterTypeID,
                )
            );
        }
    }
}

if (!$confirm) {
    print "\nRun this tool again with the argument 'confirm' to " .
        "move copy the {$column} data.\n";
} else {
    print "\nThe copy for {$column} is complete.\n";
}
