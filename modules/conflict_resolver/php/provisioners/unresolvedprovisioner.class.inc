<?php declare(strict_types=1);
/**
 * PHP version 7
 *
 * @category ConflictResolver
 * @package  Main
 * @author   Xavier Lecours <xavier.lecours@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/Loris-Trunk
 */

namespace LORIS\conflict_resolver\Provisioners;

/**
 * Conflict Resolver module
 *
 * PHP version 7
 *
 * @category ConflictResolver
 * @package  Main
 * @author   Xavier Lecours <xavier.lecours@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/Loris-Trunk
 */
class UnresolvedProvisioner extends \LORIS\Data\Provisioners\DBObjectProvisioner
{
    /**
     * Create a RowProvisioner
     */
    function __construct()
    {
        parent::__construct(
            '
             SELECT
              conflicts_unresolved.ConflictID as conflictid,
              conflicts_unresolved.TestName as instrument,
              session.CandID as candid,
              candidate.PSCID as pscid,
              session.Visit_label as visitlabel,
              Project.Name as project,
              conflicts_unresolved.FieldName as question,
              conflicts_unresolved.Value1 as value1,
              conflicts_unresolved.Value2 as value2,
              psc.name as site,
              session.CenterID as centerid,
              Project.ProjectID as projectid
             FROM
              conflicts_unresolved
             LEFT JOIN flag ON (conflicts_unresolved.CommentId1=flag.CommentID)
             LEFT JOIN session ON (flag.SessionID=session.ID)
             LEFT JOIN candidate ON (candidate.CandID=session.CandID)
             LEFT JOIN Project ON (session.ProjectID=Project.ProjectID)
             LEFT JOIN psc ON (session.CenterID = psc.CenterID)
             WHERE session.Active="Y" AND candidate.Active ="Y"
            ',
            [],
            '\LORIS\conflict_resolver\Models\UnresolvedDTO'
        );
    }
}
