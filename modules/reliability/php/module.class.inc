<?php
/**
 * This serves as a hint to LORIS that this module is a real module.
 * It does nothing but implement the module class in the module's namespace.
 *
 * PHP Version 5
 *
 * @category   Module
 * @package    Main
 * @subpackage Reliability
 * @author     Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris-Trunk/
 */
namespace LORIS\reliability;

use Psr\Http\Message\ResponseInterface;
use Psr\Http\Message\ServerRequestInterface;

/**
 * Class module implements the basic LORIS module functionality
 *
 * @category   Module
 * @package    Main
 * @subpackage Reliability
 * @author     Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris-Trunk/
 */
class Module extends \Module
{
    /**
     * {@inheritDoc}
     *
     * @param \User $user The user whose access is being checked.
     *
     * @return bool whether access is granted
     */
    public function hasAccess(\User $user) : bool
    {
        return parent::hasAccess($user) &&
            $user->hasAnyPermission(['access_all_profiles', 'reliability_edit_all']);
    }

    /**
     * {@inheritDoc}
     *
     * @return string The menu category for this module
     */
    public function getMenuCategory() : string
    {
        return "Clinical";
    }

    /**
     * {@inheritDoc}
     *
     * @return string The human readable name for this module
     */
    public function getLongName() : string
    {
        return "Reliability";
    }

    /**
     * The instruments module loads instruments in LORIS.
     *
     * @param ServerRequestInterface $request The incoming PSR7 request
     *
     * @return ResponseInterface The outgoing PSR7 response
     */
    public function handle(ServerRequestInterface $request) : ResponseInterface
    {
        $resp = parent::handle($request);
        if ($resp->getStatusCode() != 404) {
            return $resp;
        }

        $path           = $request->getURI()->getPath();
        $params         = $request->getQueryParams();
        $pathComponents = array();

        // Breakdown path information from the request.
        preg_match(
            "#(/*)([a-zA-Z0-9_-]+)(/*)(.*)#",
            $path,
            $pathComponents
        );

        $instrumentName = $pathComponents[2];
        $page           = $pathComponents[4];

        $form = \NDB_Reliability::reliabilityfactory(
            $instrumentName,
            $page,
            $params['identifier'],
            $params['reliability_center_id']
        );

        return $form->process($request, $form);
    }
}
