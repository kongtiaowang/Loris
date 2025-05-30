<?php declare(strict_types=1);

/**
 * This file provides an implementation of the hide files filter.
 *
 * PHP Version 7
 *
 * @category   Data
 * @package    Main
 * @subpackage Data
 * @author     Henri Rabalais <henri.rabalais@mcin.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris/
 */
namespace LORIS\media;

/**
 * HideFilesFilter filters out data for any resource that has a value of 1
 * for the attribute 'hide_file'.
 *
 * @category   Data
 * @package    Main
 * @subpackage Data
 * @author     Henri Rabalais <henri.rabalais@mcin.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris/
 */
class HideFileFilter implements \LORIS\Data\Filter
{
    const HIDE = 1;

    /**
     * Implements the HideFileFilter interface
     *
     * @param \User                    $user     The user that the data is being
     *                                           filtered for.
     * @param \LORIS\Data\DataInstance $resource The data being filtered.
     *
     * @return bool Whether the file should be shown.
     */
    public function filter(\User $user, \Loris\Data\DataInstance $resource) : bool
    {
        // phan only understands method_exists on simple variables, not
        // Assigning to a variable is the a workaround
        // for false positive 'getCenterIDs doesn't exist errors suggested
        // in https://github.com/phan/phan/issues/2628
        $res = $resource;
        '@phan-var object $res';

        return method_exists($res, 'getHideFile')
            && $res->getHideFile() !== self::HIDE;
    }
}
