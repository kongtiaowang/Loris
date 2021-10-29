<?php
function getDirectDDE_DSInfant()
{
    $DB =& \Database::singleton();

    $visits = array(
            "'V06'",
            "'V06-CVD'",
            "'V12'",
            "'V12-CVD'",
            "'V24'",
            "'V06', 'V06-CVD'",
            "'V12', 'V12-CVD'",
            );

    $test_names = array(
                   "aims",
                   "aosi",
                   "csbs",
                   "DSMV_Checklist",
                   "ESCS",
                   "head_measurements",
                   "head_measurements_proband",
                   "neuro_screen",
                   "ados2_module1",
                  );

    $record1 = array();

    // Example:
    // Counts
    // Admin = All
    // DDE = Complete
    // Validity = Valid
    // for a given instrument and timepoint for each site
    $query1 = "
        SELECT
            psc.name as Site, COUNT(flag.SessionID) as n
        FROM
            psc
        LEFT JOIN
            session
        ON
            session.CenterID = psc.CenterID
        LEFT JOIN
            flag
        ON
            session.ID = flag.SessionID
        WHERE
            psc.CenterID IN (2, 3, 4, 5, 11) AND
            (
            (flag.SessionID IS NULL) OR
            (
                flag.Test_name = :test_name AND
                flag.CommentID LIKE 'DDE_%' AND
                session.CenterID  IN (2, 3, 4, 5, 11) AND
                session.Visit_label IN (:visit) AND
                flag.Administration = 'All' AND
                flag.Validity = 'Valid' AND
                session.SubprojectID IN (20, 23) AND
                flag.Data_entry = 'Complete'
            )
            )
        GROUP BY
            psc.CenterID
        ORDER BY
            psc.name ASC
        ";

    // 7 timepoints * 9 instruments
    // 63 rows
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
            session.SubprojectID IN (20, 23) AND
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

$x = getDirectDDE_DSInfant();
print json_encode($x);
