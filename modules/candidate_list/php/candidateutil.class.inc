<?php declare(strict_types=1);
namespace LORIS\candidate_list;
use \Psr\Http\Message\ServerRequestInterface;
use \Psr\Http\Message\ResponseInterface;
/**
 * Create the form for schedule_module/add page
 * It includes three functions.
 * Post method handles updating and add an appointment.
 * Delete method handles deleting an appointment.
 * get method handles get an appointments.*
 * PHP Version 7
 *
 * @category Loris
 * @package  Candidate_util
 * @author   Shen Wang <wangshen.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */

class CandidateUtil extends \NDB_Page
{
    public $skipTemplate = true;
    function _hasAccess(\User $user) : bool
    {
        return true;
    }

    public function handle(ServerRequestInterface $request) : ResponseInterface
    {
        switch ($request->getMethod()) {
	case "GET":
            // todo get session or pscid or dcciid
            $url  = $request->getUri()->getPath();
            $type = "Edit";
            $id   = basename($request->getUri()->getPath());
            if (strpos($url, 'PSCID') !== false) {
                $type = "PSCID";
            }
            if (strpos($url, 'DCCID') !== false) {
                $type = "DCCID";
            }
            $res = "";
            if ($type !== "Edit") {
                $res = $this->getMetaForm($type, $id);
            }
            return (new \LORIS\Http\Response())
                ->withHeader("Content-Type", "text/plain")
                ->withBody(
                    new \LORIS\Http\StringStream(
                        json_encode($res)
                    )
		);
        case "POST":
            return $this->handleNextStageAutomatic();	    
        default:
            return (new \LORIS\Http\Response())
                ->withHeader("Content-Type", "text/plain")
		->withAddedHeader("Allow", "GET")
	        ->withAddedHeader("Allow", "POST");
        }
    }
    
    /**
     * Handles the get all pscid, dccid relative data and session
     * ex. .../dccid/300001 will return pscid mtl001 and session id
     * ex. .../pscid/mtl001 will return dccid 300001 and session id
     *
     * @param string $type the tpye  (dccid or pscid)
     * @param string $id   the id   id of dccid or pscid
     *
     * @return array all the meta form
     */
    public function getMetaForm(string $type,string $id): array
    {
        $factory = \NDB_Factory::singleton();
        $DB      = $factory->database();
        // Check if candidate is valid
        // (CandID/DCCID and PSCID must belong to same candidate)
        if ($type == "DCCID" ) {
            $candidate = $DB->pselectRow(
                "
    	SELECT 
    	 	* 
        FROM 
    	  	candidate 
    	WHERE 
    		CandID = :candId
       ",
                [
                    "candId" => $id,
                ]
            );
            $res       = ['PSCID'=>$candidate['PSCID'] ?? ''];
        } else {
            $candidate = $DB->pselectRow(
                "
            SELECT 
                    * 
            FROM 
                    candidate 
            WHERE 
                    PSCID = :pscid
            ",
                [
                    "pscid" => $id,
                ]
            );
            $res       = ['DCCID'=>$candidate['CandID'] ?? ''];
        }

        $sessionlist = $DB->pselect(
            "
        SELECT
            ID,
	    Visit_label,
            Current_stage
        FROM
            session
        WHERE 
    		CandID =:Id
    ",
            [
                'Id' => $candidate['CandID'] ?? ''
            ]
        );
	$sessions    = [];
        $sessionIDs  = [];	
        foreach ($sessionlist as $session) {
           // $k            = $session['ID'];
            $v            = $session['Visit_label'];
	    $sessions[$v] = $session['Current_stage'];
	    $sessionIDs[$v] = $session['ID'];

        }
	$res['visit_label'] = $sessions;
	$res['session'] = $sessionIDs;

        return $res;
    }
    public function handleNextStageAutomatic() {
$requestPayload = file_get_contents('php://input');
// Decode the JSON payload into an associative array
$data = json_decode($requestPayload, true);


$DCCID = $data['DCCID'];
$PSCID = $data['PSCID'];
$Visit = $data['Visit'];
$sessionID = $data['sessionID'];

try {
$timePoint = \TimePoint::singleton(intval($sessionID));
        $battery   = new \NDB_BVL_Battery;
        $timePoint->startStage('Visit');
        $timePoint->setData(['Date_visit' =>  date('Y-m-d')]);
        $battery->selectBattery($timePoint->getSessionID());
    $battery->createBattery(
        $timePoint->getSubprojectID(),
        'Visit',
        $timePoint->getVisitLabel(),
        $timePoint->getCenterID(),
        true
    );

        return new \LORIS\Http\Response\JSON\OK();

} catch (Exception $e) {
	    return new \LORIS\Http\Response\JSON\BadRequest(
                "Can not insert Cannot insert automatically!!"
            );
}



        /*    return (new \LORIS\Http\Response())
                ->withHeader("Content-Type", "text/plain")
                ->withBody(
                    new \LORIS\Http\StringStream(
                        json_encode($data)
                    )
                );
	 */       
    }
}
