<?php declare(strict_types=1);

/**
 * Page used to view/manage the processes launched asynchronously by LORIS users.
 *
 * PHP Version 5
 *
 * @category ServerProcessLauncher
 * @package  Loris
 * @author   Nicolas Brossard <nicolasbrossard.mni@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/Loris
 */
namespace LORIS\server_processes_manager;

/**
 * Builds a new filter to view/manage processes launched asynchronously by LORIS
 * users.
 *
 * PHP Version 5
 *
 * @category ServerProcessLauncher
 * @package  Loris
 * @author   Nicolas Brossard <nicolasbrossard.mni@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/Loris
 */
class Server_Processes_Manager extends \NDB_Menu_Filter
{
    public $fieldOptions;

    public $skipTemplate = true;

    /**
     * Determines whether the current user has access to the page.
     *
     * @param \User $user The user whose access is being checked
     *
     * @return bool true if the user has access, false otherwise
     */
    function _hasAccess(\User $user) : bool
    {
        return $user->hasPermission('server_processes_manager');
    }

    /**
     * Sets up the filter and result table layout.
     *
     * @return void
     */
    function _setupVariables()
    {
        // Get processes pending resolution
        $DB           = $this->loris->getDatabaseConnection();
        $idsToMonitor = $DB->pselect(
            "SELECT id
            FROM server_processes
            WHERE end_time IS NULL
            OR exit_code IS NULL",
            []
        );

        if (count($idsToMonitor) > 0) {
            // Update information of processes pending resolution
            // Ensures data is up-to-date
            $serverProcessesMonitor = new ServerProcessesMonitor();
            $serverProcessesMonitor->getProcessesState(
                array_map(
                    function ($row) {
                        return strval($row['id']);
                    },
                    iterator_to_array($idsToMonitor)
                )
            );
        }

        // Columns displayed in the result table
        $this->columns = [
            'pid',
            'type',
            'stdout_file',
            'stderr_file',
            'exit_code_file',
            'exit_code',
            'userid',
            'start_time',
            'end_time',
            'exit_text',
        ];

        // Allow to sort on pid, type and userid
        $this->validFilters = [
            'pid',
            'type',
            'userid',
        ];

        $this->query = " FROM server_processes
                         WHERE 1=1";

        $this->formToFilter = [
            'pid'    => 'pid',
            'type'   => 'type',
            'userid' => 'userid',
        ];

    }

    /**
     * Gathers JS dependecies and merge them with the parent
     *
     * @return array of javascript to be inserted
     */
    function getJSDependencies()
    {
        $factory = \NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $deps    = parent::getJSDependencies();
        return array_merge(
            $deps,
            [
                $baseURL .
             "/server_processes_manager/js/server_processes_managerIndex.js",
            ]
        );
    }

}
