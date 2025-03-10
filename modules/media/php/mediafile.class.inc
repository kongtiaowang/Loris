<?php declare(strict_types=1);

/**
 * This class implements a data Instance which represents a single
 * file in the media menu table.
 *
 * PHP Version 7
 *
 * @category   Behavioural
 * @package    Main
 * @subpackage Imaging
 * @author     Henri Rabalais <henri.rabalais@mcin.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris/
 */

namespace LORIS\media;

/**
 * A Meida File represents a row in the Media menu table.
 *
 * @category   Behavioural
 * @package    Main
 * @subpackage Imaging
 * @author     Henri Rabalais <henri.rabalais@mcin.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris/
 */
class MediaFile implements \LORIS\Data\DataInstance,
    \LORIS\StudyEntities\SiteHaver
{
    protected $DBRow;
    protected $CenterID;

    /**
     * Create a new Media File Instance.
     *
     * @param array $row The Media File Instance
     */
    public function __construct(array $row)
    {
        $this->DBRow = $row;
    }

    /**
     * Implements \LORIS\Data\DataInstance interface for this row.
     *
     * @return array which can be serialized by json_encode()
     */
    public function jsonSerialize() : array
    {
        return $this->DBRow;
    }

    /**
     * Returns the CenterID for this instance, for filters such as
     * \LORIS\Data\Filters\UserSiteMatch to match against.
     *
     * @return \CenterID
     */
    public function getCenterID(): \CenterID
    {
        return \CenterID::singleton($this->DBRow['centerId']);
    }

    /**
     * Returns the ProjectID for this instance, for filters such as
     * \LORIS\Data\Filters\UserProjectMatch to match against.
     *
     * @return integer The ProjectID
     */
    public function getProjectID(): int
    {
        return $this->DBRow['projectId'];
    }

    /**
     * Returns the value of the 'Hide File' variable. This is stored in the
     * database as a 0 or a 1. A value of 0 means the file should be shown and
     * a value of 1 means it should be hidden.
     *
     * @return int The value of hideFile.
     */
    public function getHideFile(): int
    {
        if ($this->DBRow['hideFile'] == 'hidden') {
            return 1;
        }
        return 0;
    }
}
