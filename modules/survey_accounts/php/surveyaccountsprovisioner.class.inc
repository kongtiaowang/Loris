<?php declare(strict_types=1);
/**
 * This file implements a data provisioner to get all possible rows
 * for the survey accounts menu page.
 *
 * PHP Version 7
 *
 * @category   Behavioural
 * @package    Main
 * @subpackage Core
 * @author     Dave MacFarlane <dave.macfarlane@mcin.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris/
 */

namespace LORIS\survey_accounts;

/**
 * This class implements a data provisioner to get all possible rows
 * for the survey accounts menu page.
 *
 * PHP Version 7
 *
 * @category   Behavioural
 * @package    Main
 * @subpackage Core
 * @author     Dave MacFarlane <dave.macfarlane@mcin.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris/
 */
class SurveyAccountsProvisioner
    extends \LORIS\Data\Provisioners\DBRowProvisioner
{
    /**
     * Create a SurveyAccountsProvisioner, which gets rows for the
     * survey accounts menu table.
     */
    // IBIS SPECIFIC OVERRIDE CODE
    // Add additional elements to query to retrieve survey's
    // full name and parent portal.
    function __construct()
    {
        parent::__construct(
            "SELECT
                c.PSCID AS PSCID,
                s.Visit_label AS Visit,
                tn.Test_name as SurveyName,
                p.OneTimePassword as URL,
                p.Status,
                s.CenterID,
                s.ProjectID,
                CASE
                    WHEN (
                        (s.Visit_label='VSA' || s.Visit_label like '%CVD%')
                        AND p.Email!=''
                    ) THEN c.ParentID
                    WHEN (
                        s.Visit_label IN ('V06', 'V12','V24','V36')
                        AND c.RegistrationProjectID IN('5','8','10')
                        AND p.Email != ''
                    ) THEN c.ParentID
                    ELSE 'NA'
                END AS Parent_Portal
             FROM participant_accounts p
                JOIN session s ON (p.SessionID=s.ID)
                JOIN candidate c ON (c.CandID=s.CandID)
                JOIN test_names tn ON(tn.Test_name=p.Test_name)
             WHERE c.Active = 'Y'
                AND s.Active = 'Y'
             ORDER BY PSCID",
            []
        );
    }
    // IBIS SPECIFIC OVERRIDE CODE ENDS HERE

    /**
     * Returns an instance of a SurveyAccountsRow object for a given
     * table row.
     *
     * @param array $row The database row from the LORIS Database class.
     *
     * @return \LORIS\Data\DataInstance An instance representing this row.
     */
    public function getInstance($row) : \LORIS\Data\DataInstance
    {
        $cid = (int )$row['CenterID'];
        $pid = (int )$row['ProjectID'];
        return new SurveyAccountsRow($row, $cid, $pid);
    }
}
