<?php
/**
 * This is used by the Loris survey module to retrieve the instruments
 * available for a candidate on selecting a visit label when
 * creating a survey
 *
 * PHP Version 5
 *
 * @category Survey
 * @package  Loris
 * @author   Sruthy Mathew <sruthy.mcin@gmail.com>
 * @license  Loris license
 * @link     https://www.github.com/aces/Loris-Trunk/
 */

$user =& User::singleton();
if (!$user->hasPermission('user_accounts')) {
    header("HTTP/1.1 403 Forbidden");
    exit;
}

set_include_path(get_include_path().":../project/libraries:../php/libraries:");
ini_set('default_charset', 'utf-8');

require_once "Database.class.inc";
require_once 'NDB_Config.class.inc';
require_once 'NDB_Client.class.inc';

$config =& NDB_Config::singleton();
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize();

$DB          = Database::singleton();

//---------------------------------------------//
// Get CandID and visit label from the request //
//---------------------------------------------//
$visitLabel = $_REQUEST['VL'];
$candid     = $_REQUEST['dccid'];

//-------------------------------------//
// Make sure there is a candidate with //
// this candidate ID, otherwise return //
// null                                //
//-------------------------------------//
$candidateCount = $DB->pselectOne(
    "SELECT
        count(*)
    FROM
        candidate
    WHERE
        candid = :candid",
    ['candid' => $candid]
);

if ($candidateCount == 0) {
    echo json_encode(['option_string' => null]);
    exit(0);
}

//-------------------------------------//
// Make sure that $visitLabel exists   //
// in table Visit_Windows, otherwise   //
// return null                         //
//-------------------------------------//
$visitCount = $DB->pselectOne(
    "SELECT
        count(*)
    FROM
        Visit_Windows
    WHERE
        visit_label = :vlabel",
    ['vlabel' => $visitLabel]
);

if ($visitCount == 0) {
    echo json_encode(['option_string' => null]);
    exit(0);
}

//--------------------------------------------------//
// Compute nb. of surveys survey with the specified //
// visit label in table survey_test_battery         //
//--------------------------------------------------//
$surveyTestBatteryCount = $DB->pselectOne(
    "SELECT
                count(*)
            FROM
                survey_test_battery
            WHERE
                Visit_label = :vl",
    ['vl' => $visitLabel]
);

//-------------------------------------------------------------------//
// If there's at least one survey with the specified visit label in  //
// table survey_test_battery                                         //
//-------------------------------------------------------------------//
if ($surveyTestBatteryCount != 0) {
    $result = $DB->pselect(
        "SELECT
            DISTINCT tn.Test_name, tn.Full_name
        FROM
            test_names AS tn
        INNER JOIN
            survey_test_battery AS stb
        USING
            (Test_name)
        WHERE
            stb.Visit_label = :vl
        AND (
            stb.SubprojectID IN (
                SELECT
                    CohortID
                FROM
                    session
                WHERE
                    CandID = :candid
                AND
                    Visit_label = :vl
            )
            OR
                stb.SubprojectID IS NULL
        )
        AND
            tn.Test_name NOT IN (
                SELECT
                    f.Test_name
                FROM
                    flag AS f
                JOIN
                    session AS s
                ON
                    s.ID = f.SessionID
                WHERE
                    s.CandID = :candid
                AND
                    UPPER(s.Visit_label) = UPPER(:vl)
                AND
                    s.Active = 'Y'
                AND
                    f.CommentID NOT LIKE '%DDE%'
            )
        ORDER BY
            tn.Full_name",
        [
            'candid' => $candid,
            'vl'     => $visitLabel,
        ]
    );

    if (empty($result)) {
         $result = $DB->pselect(
            "SELECT
                DISTINCT tn.Test_name, tn.Full_name
            FROM
                test_names tn
            JOIN
                survey_test_battery stb
            ON
                (stb.Test_name = tn.test_name)
            WHERE
                stb.Visit_label = :vl
            AND
                tn.Test_name NOT IN (
                    SELECT
                        f.Test_name
                    FROM
                        flag AS f
                    JOIN
                        session AS s
                    ON
                        s.ID = f.SessionID
                    WHERE
                        s.CandID = :candid
                    AND
                        UPPER(s.Visit_label) = UPPER(:vl)
                    AND
                        s.Active='Y'
                    AND
                        f.CommentID NOT LIKE '%DDE%'
                )
            ORDER BY tn.Full_name",
            [
                'candid' => $candid,
                'vl'     => $visitLabel
            ]
        );
    }
} else {
    $result = $DB->pselect(
        "SELECT
            Test_name, Full_name
        FROM test_names
        WHERE
            IsDirectEntry=1
        AND
            Test_name NOT IN (
                SELECT
                    f.Test_name
                FROM
                    flag f
                JOIN
                    session s
                ON
                    s.ID = f.SessionID
                WHERE
                    s.CandID = :candid
                AND
                    UPPER(s.Visit_label) = UPPER(:vl)
                AND
                    s.Active = 'Y'
                AND
                    f.CommentID NOT LIKE '%DDE%'
            )
        ORDER BY Full_name",
        [
            'candid' => $candid,
            'vl'     => $visitLabel
        ]
    );

    if (empty($result)) {
        $result = $DB->pselect(
            "SELECT
                Test_name, Full_name
            FROM
                test_names
            WHERE
                IsDirectEntry = 1
            ORDER BY Full_name",
            []
        );
    }
}

$availableSurveysHTML = '';
foreach ($result as $data) {
    $availableSurveysHTML .= "<option value=\"{$data['Test_name']}\">{$data['Full_name']}</option>";
}

echo  json_encode(['option_string' => $availableSurveysHTML]);

exit(0);
