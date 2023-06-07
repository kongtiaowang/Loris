<?php
/**
 * Mri_upload class file
 *
 * PHP version 5
 *
 * @category Behavioural
 * @package  Main
 * @author   Zia Mohaddes  <zia.mohades@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/mohadesz/Loris-Trunk
 */
namespace LORIS\imaging_uploader;
use LORIS\server_processes_manager as SP;
use \Psr\Http\Message\ServerRequestInterface;
use \Psr\Http\Message\ResponseInterface;

/**
 * Post method handles updating a file.
 * Delete method handles deleting a file.
 * Get method handles getting a file.
 * Put method handles editing a file.
 * This class contains functions providing upload and edit functionality for
 * files in the document_repository.
 *
 * @license http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 */
class Upload_Process extends \NDB_Page
{
    var $mri_upload_id;
    var $AjaxModule      = true;
    public $skipTemplate = true;
    var $show_queries    = true;
    var $temp_path       = null;	

    /**
     * Same as the permissions for the main menu filter page.
     *
     * @param \User $user The user whose access is being checked
     *
     * @return bool true only if the user has access to this page.
     */
    function _hasAccess(\User $user) : bool
    {
        return $user->hasPermission('imaging_uploader');
	    
    }

    /**
     * Handle how to operate all the files.
     * PUT method updates a file's info.
     * DELETE method deletes a file.
     * POST method uploads a file.
     * GET method gets a file.
     *
     * @param ServerRequestInterface $request The incoming PSR7 request
     *
     * @return ResponseInterface The outgoing PSR7 response
     */
    public function handle(ServerRequestInterface $request) :ResponseInterface
    {
        switch ($request->getMethod()) {
        case "POST":
		return $this->uploadFile($request);
        default:
            return (new \LORIS\Http\Response\JSON\MethodNotAllowed(
                ["POST"]
            ));
        }
    }
    /**
     * Handles the document editing process
     *
     * @param ServerRequestInterface $req The incoming PSR7 request
     *
     * @return ResponseInterface
     */
    function uploadFile(ServerRequestInterface $req)
    {

		       error_log(json_encode($_FILES));
		       //////////////////////////////////////////////////////////////////////
        //////////////////Upload-related Error messages ///////////////////////
        ///////////////////////////////////////////////////////////////////////
	         if (empty($_FILES) && empty($_POST)){   
	                   $upload_max_size = \Utility::getMaxUploadSize();
            $error_message   = "Please make sure files are not larger than " .
                                $upload_max_size;
            $errors = [
                'IsPhantom'  => [],
                'candID'     => [],
                'pSCID'      => [],
                'visitLabel' => [],
                'mriFile'    => [$error_message],
            ];
            return (new \LORIS\Http\Response())
            ->withStatus(400)
            ->withHeader("Content-Type", "text/plain")
            ->withBody(
                new \LORIS\Http\StringStream(
                    json_encode(['errors' => $errors])
                )
	    );} 
		 //  end check filesize
// check file name with .tgz, .tar.gz or .zip.
        $errors = [
            'IsPhantom'  => [],
            'candID'     => [],
            'pSCID'      => [],
            'visitLabel' => [],
            'mriFile'    => [],
        ];
		       // creates empty string variable to store error message for wrong file name
		       //
         $file_name = $_FILES['mriFile']['name']; // Replace with your file name

         $allowed_extensions = ['.tgz', '.tar.gz', '.zip'];

         $file_extension = pathinfo($file_name, PATHINFO_EXTENSION);

	 
	 if (!in_array('.' . $file_extension, $allowed_extensions)) {
	             array_push(
                $errors["mriFile"],
                "The file $file_name is not of type".
                " .tgz, .tar.gz or .zip."
            );
	 }

	$args=$req->getParsedBody(); 
	error_log("--------");
	error_log(json_encode($args));	
//	{"IsPhantom":"Y","fire_away":"Upload"}
	
	  return (new \LORIS\Http\Response())
            ->withStatus(400)
            ->withHeader("Content-Type", "text/plain")
            ->withBody(
                new \LORIS\Http\StringStream(
                    json_encode(['errors' => $errors])
                )
            );





    }
    /**
     * The function isCompressed returns true if the file is
     * compressed (gzip or zip) or false otherwise
     *
     * @param string $file The full filename including directory
     *
     * @return bool Whether the file is compressed
     */

}    
