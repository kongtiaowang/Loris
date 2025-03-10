<?php declare(strict_types=1);

/**
 * PHP Version 7
 *
 * @category ApiViews
 * @package  Loris
 * @author   Xavier Lecours Boucher <xavier.lecours@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */

namespace LORIS\api\Views;

/**
 * Create a array representations of this LORIS instance projects
 *  suitable to the API specifications.
 *
 * @category ApiViews
 * @package  Loris
 * @author   Xavier Lecours Boucher <xavier.lecours@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */

class Projects
{
    private $_projects;

    /**
     * Create an api formated view of an array of projects
     *
     * @param \Project[] $projects The projects
     */
    public function __construct(array $projects)
    {
        $this->_projects = $projects;
    }

    /**
     * Gets the required data from the projects.
     *
     * @return array
     */
    public function toArray(): array
    {
        $config = \NDB_Factory::singleton()->config();

        $useEDC = $config->getSetting("useEDC");
        $PSCID  = $config->getSetting("PSCID");

        $PSCIDFormat = \Candidate::structureToPCRE($PSCID['structure'], "SITE");

        $type = $PSCID['generation'] == 'sequential' ? 'auto' : 'prompt';

        $settings = [
            "useEDC" => $useEDC,
            "PSCID"  => [
                "Type"  => $type,
                "Regex" => $PSCIDFormat,
            ],
        ];

        $projects = [];
        foreach ($this->_projects as $project) {
            // All projects have the same settings.
            $project_name            = $project->getName();
            $projects[$project_name] = $settings;
        }
        return ['Projects' => $projects];
    }
}
