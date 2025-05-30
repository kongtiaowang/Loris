<?php declare(strict_types=1);

/**
 * This file implements a data provisioner to get all possible rows
 * for the datadict menu page.
 *
 * PHP Version 7
 *
 * @category   Behavioural
 * @package    Main
 * @subpackage Behavioural
 * @author     Dave MacFarlane <david.macfarlane2@mcgill.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris/
 */

namespace LORIS\datadict;

/**
 * This class implements a data provisioner to get all possible rows
 * for the datadict menu page.
 *
 * PHP Version 7
 *
 * @category   Behavioural
 * @package    Main
 * @subpackage Behavioural
 * @author     Dave MacFarlane <david.macfarlane2@mcgill.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris/
 */
class DataDictRowProvisioner extends \LORIS\Data\Provisioners\DBRowProvisioner
{
    /**
     * Create a DataDictRowProvisioner, which gets rows for
     * the datadict menu table.
     *
     * @param \LORIS\LorisInstance $loris The LORIS instance to retrieve data
     *                                    from.
     */
    function __construct(protected \LORIS\LorisInstance $loris)
    {
        parent::__construct(
            $loris,
            "SELECT DISTINCT
                pt.sourceFrom as source_from,
                pt.name as name,
                pt.sourceField as source_field,
                coalesce(pto.description,pt.description) as description,
                CASE
                    WHEN COALESCE(pto.description,pt.description) = '' THEN 'Empty'
                    WHEN pto.name IS NOT NULL THEN 'Modified'
                    WHEN pto.name IS NULL THEN 'Unchanged'
                END as description_status,
                GROUP_CONCAT(DISTINCT c.title) AS Cohort
            FROM parameter_type pt
            LEFT JOIN parameter_type_override pto USING (Name)
            LEFT JOIN test_battery tb ON pt.sourceFrom=tb.Test_name
            LEFT JOIN cohort c ON tb.CohortID=c.CohortID
            WHERE pt.Queryable=1
            GROUP BY pt.sourceFrom, pt.name, pt.sourceField,
            description, description_status",
            []
        );
    }

    /**
     * Returns an instance of a DataDict object for a given
     * table row.
     *
     * @param array $row The database row from the LORIS Database class.
     *
     * @return \LORIS\Data\DataInstance An instance representing this row.
     */
    public function getInstance($row) : \LORIS\Data\DataInstance
    {
        return new DataDictRow($row);
    }
}
