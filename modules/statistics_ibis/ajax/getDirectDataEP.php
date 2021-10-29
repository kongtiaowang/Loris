<?php
function getDirectDataEP()
{
    $DB =& \Database::singleton();

    $visits = array(
            // "Proband"         => "'Proband'",
            "'V06'",
            "'V06-CVD'",
            "'V12'",
            "'V12-CVD'",
            "'V24'",
            "'V06', 'V06-CVD'",
            "'V12', 'V12-CVD'",
            );

    $test_names = array(
                   //"elsi",
                   //"lena",
                   "aims",
                   "aosi",
                   "csbs",
                   "JointAttentionAssessment",
                   "DSMV_Checklist",
                   "ESCS",
                   "head_measurements",
                   "head_measurements_proband",
                   "neuro_screen",
                   "ados2_module1",
                  );

    $record1 = array();

    // Example:
    // Counts the # of each Administration value (All, Partial, None, Null)
    // for a given instrument and timepoint for each site
    $query1 = "
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
            psc.CenterID IN (2, 3, 4, 5, 11) AND
            (flag.SessionID IS NULL) OR
            (
                flag.Test_name = :test_name AND
                flag.CommentID NOT LIKE 'DDE_%' AND
                session.CenterID  IN (2, 3, 4, 5, 11) AND
                session.Visit_label IN (:visit) AND
                (flag.Administration IN ('All', 'Partial', 'None') OR flag.Administration IS NULL) AND
                session.SubprojectID = 18
            )
        GROUP BY
            psc.CenterID,
            administration.Administration
        ORDER BY
            psc.name ASC,
            administration.Administration ASC
        ";

    // 7 timepoints * 10 instruments
    // 70 rows
    foreach ($visits as $visit) {
        foreach ($test_names as $test_name) {
            $tmp = $DB->pselect(
                str_replace(":visit", $visit, $query1),
                array("test_name" => $test_name)
            );

            array_push($record1, $tmp);
        }
    }

    $sites = array(
              3, // PHI
              2, // SEA
              4, // STL
              11, // UMN
              5, // UNC
             );

    // Gets the total # of scheduled 'Behavioral' appointments (AppointmentTypeID = 3)
    // for a given Site, Visit label(s)
    $query2 = "
        SELECT
            COUNT(DISTINCT appointment.SessionID, appointment.AppointmentTypeID) as appointmentCount
        FROM
            `appointment`
        JOIN
            session
        ON
            session.ID = appointment.SessionID
        WHERE
            appointment.AppointmentTypeID = 3 AND
            session.Visit_label IN (:visit) AND
            session.SubprojectID = 18 AND
            session.CenterID = :site
        ";

    // 7 timepoints * 5 sites
    // 35 rows
    $record2 = array();

    foreach ($visits as $visit) {
        foreach ($sites as $site) {
            $tmp = $DB->pselect(
                str_replace(":visit", $visit, $query2),
                array("site" => $site)
            );

            array_push($record2, $tmp);
        }
    }

    return array("record1" => $record1, "record2" => $record2);
}

$x = getDirectDataEP();
print json_encode($x);
