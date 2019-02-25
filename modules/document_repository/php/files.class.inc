<?php
/**
 * It includes two functions.
 * Post method handles updating a file.
 * Delete method handles deleting a file.
 * Get method handles getting a file with ID or files.
 * Put method handles editing a file.
 *
 * PHP Version 7
 *
 * @category Main
 * @package  Document_Repository
 * @author   Loris Team <loris.mni@bic.mni.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */
namespace LORIS\document_repository;
use \Psr\Http\Message\ServerRequestInterface;
use \Psr\Http\Message\ResponseInterface;

/**
 * It includes two functions.
 * Post method handles updating a file.
 * Delete method handles deleting a file.
 *
 * PHP Version 7
 *
 * @category Main
 * @package  Document_Repository
 * @author   Loris Team <loris.mni@bic.mni.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */
class Files extends \NDB_Page
{
    public $skipTemplate = true;

    /**
     * Same as the permissions for the main menu filter page.
     *
     * @param \User $user The user whose access is being checked
     *
     * @return bool true iff the user has access to this page.
     */
    function _hasAccess(\User $user) : bool
    {
        return (
            $user->hasPermission('document_repository_delete')
            || $user->hasPermission('document_repository_view')

        );
    }

    /**
     * Handle how to operate all the files.
     *
     * @param ServerRequestInterface $request The incoming PSR7 request
     *
     * @return ResponseInterface The outgoing PSR7 response
     */
    public function handle(ServerRequestInterface $request) : ResponseInterface
    {
        switch ($request->getMethod()) {
        case "PUT":
            $this->editDocFile($request);
            return (new \LORIS\Http\Response())
                ->withHeader("Content-Type", "text/plain")
                ->withStatus(200)
                ->withBody(
                    new \LORIS\Http\StringStream(
                        json_encode("update a file")
                    )
                );
          break;
        case "DELETE":
            $path = $request->getQueryParams();
            $id   = basename($path['lorispath']);
            $this->deleteFile($id);
            return (new \LORIS\Http\Response())
                ->withHeader("Content-Type", "text/plain")
                ->withStatus(200)
                ->withBody(
                    new \LORIS\Http\StringStream(
                        json_encode("delete a file")
                    )
                );
          break;
        case "GET":
            $path = $request->getQueryParams();
            $id   = basename($path['lorispath']);
            return (new \LORIS\Http\Response())
                ->withHeader("Content-Type", "text/plain")
                ->withStatus(200)
                ->withBody(
                    new \LORIS\Http\StringStream(
                        json_encode($this->getUploadDocFields($id))
                    )
                );
          break;
        case "POST":
            $path = $request->getQueryParams();
            $id   = basename($path['lorispath']);
            $this->deleteFile($id);
            return (new \LORIS\Http\Response())
                ->withHeader("Content-Type", "text/plain")
                ->withStatus(200)
                ->withBody(
                    new \LORIS\Http\StringStream(
                        json_encode("delete")
                    )
                );
          break;
        default:
            // get all files
            return (new \LORIS\Http\Response())
                ->withHeader("Content-Type", "text/plain")
                ->withStatus(200);
        }
    }
    /**
 * Handles the document editing process
 *
 * @param ServerRequestInterface $request The incoming PSR7 request
 *
 * @throws \DatabaseException
 *
 * @return void
 */
    function editDocFile($request): void
    {
        $db           = \Database::singleton();
        $user         = \User::singleton();
        $req          = $request->getParsedBody();
        $updateValues = [
                         'File_category' => isset($req['category']) ?
                              $req['category'] : null,
                         'For_site'      => isset($req['forSite']) ?
                              $req['forSite'] : null,
                         'Instrument'    => isset($req['instrument']) ?
                              $req['instrument'] : null,
                         'comments'      => isset($req['comments']) ?
                              $req['comments'] : null,
                         'version'       => isset($req['version']) ?
                              $req['version'] : null,
                         'visitLabel'    => isset($req['visitLabel']) ?
                              $req['visitLabel'] : null,
                         'pscid'         => isset($req['pscid']) ?
                              $req['pscid'] : null,
                        ];
        try {
            $db->update(
                'document_repository',
                $updateValues,
                ['record_id' => $req['id']]
            );
        } catch (\DatabaseException $e) {
            showError("Could not update the file. Please try again!");
        }
    }
    /**
 * Handles the document deleting process
 *
 * @param string $rid the file id
 *
 * @throws \DatabaseException
 *
 * @return void
 */
    function deleteFile($rid): void
    {
        // create Database object
        $DB       = \Database::singleton();
        $user     = \User::singleton();
        $Notifier = new \NDB_Notifier(
            "document_repository",
            "delete"
        );

        $fileName = $DB->pselectOne(
            "SELECT File_name FROM document_repository
             WHERE record_id =:identifier",
            array(':identifier' => $rid)
        );
        $userName = $DB->pselectOne(
            "SELECT uploaded_by FROM document_repository
             WHERE record_id =:identifier",
            array(':identifier' => $rid)
        );
        $dataDir  = $DB->pselectOne(
            "SELECT Data_dir FROM document_repository WHERE record_id =:identifier",
            array(':identifier' => $rid)
        );

        //if user has document repository delete permission
        if ($user->hasPermission('document_repository_delete')) {
            $DB->delete("document_repository", array("record_id" => $rid));
            $msg_data['deleteDocument'] = $baseURL. "/document_repository/";
            $msg_data['document']       = $fileName;

            $Notifier->notify($msg_data);
        }

        $path = __DIR__ . "/../user_uploads/$dataDir";

        if (file_exists($path)) {
            unlink($path);
        }

    }
/**
 * Returns a list of categories fields from database
 *
 * @param String $id id of the Doc file
 *
 * @return array
 */
    function getUploadDocFields(string $id): array
    {
        $db    = \Database::singleton();
        $query = $db->pselect(
            "SELECT * FROM document_repository_categories",
            array()
        );
        //categories
        $categoriesList = array();
        foreach ($query as $value) {
             $arr = $this->parseCategory($value);
             $categoriesList[$arr['id']] =$arr['name'];
        }
        //site
        $siteList = \Utility::getSiteList(false);
        //instrument
        $instruments     = $db->pselect(
            "SELECT Test_name FROM test_names ORDER BY Test_name",
            array()
        );
        $instrumentsList = $this->toDocSelect($instruments, "Test_name", null);
        //docFile
        $docData = null;
        if (isset($id)) {
            $idDocFile = $id;
            $docData   = $db->pselectRow(
                "SELECT " .
                "record_id as id, " .
                "PSCID as pscid, " .
                "File_category as category," .
                "visitLabel, " .
                "Instrument as instrument, " .
                "For_site as forSite, " .
                "comments, " .
                "File_Name as fileName, " .
                "version " .
                "FROM document_repository " .
                " WHERE record_id = $idDocFile",
                array()
            );
        }
        $result = array(
                   'categories'  => $categoriesList,
                   'sites'       => $siteList,
                   'instruments' => $instrumentsList,
                   'docData'     => $docData,
                  );
        return $result;
    }
/**
 * Handler of parsing category
 *
 * @param string $value the value
 *
 * @return array
 */
    function parseCategory($value): array
    {
        $id    = $value['id'];
        $depth = 0;
        $DB    = \Database::singleton();
            $categoryName = $value['category_name'];
        do {
            if ($value['parent_id'] != 0) {
                $depth       += 1;
                $parent_id    = $value['parent_id'];
                $query        = "SELECT * FROM document_repository_categories".
                            " WHERE id=$parent_id";
                $value        = $DB->pselectRow($query, array());
                $categoryName = $value['category_name'] . ">" . $categoryName;
            }
        } while ($value['parent_id'] != 0);
         return array(
                 "name" => $categoryName,
                 "id"   => $id,
                );
    }
/**
 * Utility function to convert data from database to a
 * (select) dropdown friendly format
 *
 * @param array  $options array of options
 * @param string $item    key
 * @param string $item2   value
 *
 * @return array
 */
    function toDocSelect($options, $item, $item2): array
    {
        $selectOptions = array();

        $optionsValue = $item;
        if (isset($item2)) {
            $optionsValue = $item2;
        }

        foreach ($options as $key => $value) {
            $selectOptions[$options[$key][$optionsValue]] = $options[$key][$item];
        }

        return $selectOptions;
    }
/**
 * Check the find name in the database, if exists return false
 *
 * @param string $filename file name
 *
 * @return bool
 */
    function existFilename(string $filename): bool
    {
        $DB        = \Database::singleton();
        $fileCount =  $DB->pselectOne(
            "SELECT COUNT(*) FROM document_repository
             WHERE File_Name=:name",
            array('name' => $filename)
        );
        if ((int)$fileCount > 0) {
            return true;
        }
        return false;
    }
}
