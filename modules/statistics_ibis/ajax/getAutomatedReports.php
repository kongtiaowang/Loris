<?php
function getDirectDataSA()
{
    $DB =& \Database::singleton();

    $visits = array(
               "VSA"             => "'VSA'",
               "VSA_CVD"         => "'VSA-CVD'",
               "VSA_and_VSA_CVD" => "'VSA', 'VSA-CVD'",
              );

    $test_names = array(
                   "ADOS_Derived"               => "ADOS",
                   "BOT2_Short"                 => "BOT2",
                   "DAS_SA"                     => "DAS",
                   "DSMIV_SA"                   => "DSM-IV",
                   "DSMV_Checklist"             => "DSM-V",
                   "SA_Intervention_History"    => "Interv hx",
                   "MASC2_Self_Report"          => "MASC-2 Self",
                   "mQST"                       => "mQST",
                   "NIHToolBox_Assessment_Data" => "NIH-TB",
                   "WIAT_III_SA"                => "WIAT-III",
                  );

    $record = array();

    $query = "
        SELECT
            psc.name as Site, administration.Administration, COUNT(flag.SessionID) AS n
        FROM
            psc
        CROSS JOIN
            (
                SELECT 'None' AS Administration
                UNION
                SELECT 'Partial'
                UNION
                SELECT 'All'
                UNION
                SELECT NULL
            ) AS administration
        LEFT JOIN
            session
        ON
            session.CenterID = psc.CenterID
        LEFT JOIN
            flag
        ON
            session.ID = flag.SessionID AND
            administration.Administration <=> flag.Administration
        WHERE
            psc.CenterID IN (2, 3, 4, 5) AND
            (
            (flag.SessionID IS NULL) OR
            (
                flag.Test_name = :test_name AND
                flag.CommentID NOT LIKE 'DDE_%' AND
                session.CenterID  IN (2, 3, 4, 5) AND
                session.Visit_label IN (:value) AND
                    (flag.Administration IN ('All', 'Partial', 'None') OR flag.Administration IS NULL)
            )
            ) AND
            session.SubprojectID IN (1, 2, 3, 7, 9, 10, 12, 13)
        GROUP BY
            psc.CenterID,
            administration.Administration
        ORDER BY
            psc.name ASC,
            administration.Administration ASC
        ";

    foreach ($visits as $key => $value) {
        foreach ($test_names as $test_name => $test_name_label) {
            $tmp = $DB->pselect(
                str_replace(":value", $value, $query),
                array("test_name" => $test_name)
            );

            array_push($record, $tmp);
        }
    }

    // error_log(print_r($data));

    return $record;
}

$x = getDirectDataSA();
print json_encode($x);