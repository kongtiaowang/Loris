<?php declare(strict_types=1);

/**
 * This class implements a data mapper which converts User ID to a boolean
 * in the Issue Tracker.
 *
 * PHP Version 7
 *
 * @category   Behavioural
 * @package    Main
 * @subpackage Tools
 * @author     Henri Rabalais <henri.rabalais@mcin.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris/
 */
namespace LORIS\issue_tracker;
use \LORIS\Data\{Mapper, DataInstance
};

/**
 * A IssueWatcherMapper is a \LORIS\Data\Mapper which maps User ID
 * by setting it to true if it belongs to the current user and false if not.
 *
 * @category   Behavioural
 * @package    Main
 * @subpackage Tools
 * @author     Henri Rabalais <henri.rabalais@mcin.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris/
 */
class IssueWatcherMapper implements Mapper
{
    /**
     * Maps the User ID to 'true' if it belongs to the current user and to 'false'
     * if it does not.
     *
     * @param \User                    $user     The user this data is being mapped
     *                                           for.
     * @param \LORIS\Data\DataInstance $resource The data instance being mapped.
     *
     * @return \LORIS\Data\DataInstance the mapped data
     */
    public function map(
        \User $user,
        DataInstance $resource
    ) : DataInstance {
        $res = $resource;
        assert($res instanceof IssueRow);

        static $config = null;
        if ($config === null) {
            $factory = \NDB_Factory::singleton();
            $config  = $factory->config()->getSetting("imaging_modules");
        }

        $newrow = json_decode(json_encode($resource), true);
        if (isset($newrow['userId'])
            && $newrow['userId'] === $user->getUsername()
        ) {
            $newrow['userId'] = true;
        } else {
            $newrow['userId'] = false;
        }

        return new IssueRow(
            $newrow,
            $res->getCenterIDs(),
            $res->getModule()
        );
    }
}
