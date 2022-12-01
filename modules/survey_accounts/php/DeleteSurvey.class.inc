<?php
/**
 * This class handles a post request to delete a survey
 * PHP Version 7
 *
 * @category Main
 * @package  survey
 * @author   Loris Team <loris.mni@bic.mni.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */
namespace LORIS\survey_accounts;

use \Psr\Http\Message\ServerRequestInterface;
use \Psr\Http\Message\ResponseInterface;

/**
 * This class handles a post request to upload a new category.
 * PHP Version 7
 *
 * @category Main
 * @package  Document_Repository
 * @author   Loris Team <loris.mni@bic.mni.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */
class DeleteSurvey extends \NDB_Page
{
    public $skipTemplate = true;

    /**
     * Same as the permissions for the main menu filter page.
     *
     * @param \User $user The user whose access is being checked
     *
     * @return bool true if the user has access to this page.
     */
    function _hasAccess(\User $user) : bool
    {
        return $user->hasPermission('user_accounts');
    }


    /**
     * Handle a post form
     *
     * @param ServerRequestInterface $request The incoming PSR7 request
     *
     * @return ResponseInterface The outgoing PSR7 response
     */
    public function handle(ServerRequestInterface $request) : ResponseInterface
    {
        if ($request->getMethod() == "DELETE") {
            $id = basename($request->getUri()->getPath());
            $route= explode('/', $request->getUri()->getPath()); 
            if ($this->dodeleteSurvey($route[2],$id)) {
                return (new \LORIS\Http\Response())
                    ->withStatus(200)
                    ->withHeader("Content-Type", "text/plain")
                    ->withBody(
                        new \LORIS\Http\StringStream(
                            json_encode("delete successfully")
                        )
                    );
            }
            return (new \LORIS\Http\Response())
                ->withStatus(403)
                ->withHeader("Content-Type", "text/plain")
                ->withHeader("Allow", "can't delete");

        } else {
            return (new \LORIS\Http\Response())
                ->withStatus(405)
                ->withHeader("Content-Type", "text/plain")
                ->withHeader("Allow", "GET");
        }
    }
    /**
     * Handles the upload category process
     *
     * @param ServerRequestInterface $request The incoming PSR7 request
     *
     * @return bool
     */
    function dodeleteSurvey($instrument,$id): bool
    {
        $DB            = \NDB_Factory::singleton()->database();
        //check duplicate name category
        try{
        $DB->delete(
                   $instrument,
            [   
                "CommentID"      => $id,
            ]
        );
        $DB->delete(
                   "flag",
            [   
                "CommentID"      => $id,
            ]             
        );
        $DB->delete(
            "participant_accounts",
            [
                "CommentID"      => $id,
            ]
        );
        return true;
        } catch (Exception $e) {
        return false;}
    }
}
