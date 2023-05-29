<?php declare(strict_types=1);
namespace LORIS\portal;
use \Psr\Http\Message\ServerRequestInterface;
use \Psr\Http\Message\ResponseInterface;

class Portal_Util extends \NDB_Page
{

    public $AjaxModule   = true;
    public $skipTemplate = true;

    /**
     * Same as the permissions for the main menu filter page.
     *
     * @param \User $user The user whose access is being checked
     *
     * @return bool true only if the user has access to this page.
     */
    function _hasAccess(\User $user) : bool
    {
        return true;
    }

    /**
     * Handle how to operate all the files.
     * GET method gets a file.
     *
     * @param ServerRequestInterface $request The incoming PSR7 request
     *
     * @return ResponseInterface The outgoing PSR7 response
     */
    public function handle(ServerRequestInterface $request): ResponseInterface
    {
        switch ($request->getMethod()) {
        case "GET":
            return $this->getVisitCompletionFormFields($request);
        default:
            return (new \LORIS\Http\Response\JSON\MethodNotAllowed(
                ["GET"]
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
    function getVisitCompletionFormFields(ServerRequestInterface $req): ResponseInterface
    {
        $db = \NDB_Factory::singleton()->database();

        $candID = $req->getQueryParams()['candID'];
        $session = $req->getQueryParams()['session'];
        $data = $req->getQueryParams()['data'] ?? '';
        $sessionID = $db->pselectOne(
            'SELECT
                    s.ID
                FROM
                    candidate c
                JOIN
                    session s
                ON
                    (c.CandID=s.CandID)
                WHERE
                    c.CandID= :candID AND
                    s.Visit_label= :vl
                ',
            [
                'candID'    => $candID,
                'vl' => $session
            ]
        );
        if ($data == '') {
            header("HTTP/1.1 403 Bad Request");
            exit;
	}
        if($data == "get_visit_status") {

            $vstatus = $db->pselect(
                'SELECT
                    s.Visit_completed,
                    s.Current_stage
                FROM
                    candidate c
                JOIN
                    session s
                ON
                    (c.CandID=s.CandID)
                WHERE
                    c.CandID= :candID AND
                    s.ID= :sid
                ',
                [
                    'candID'    => $candID,
                    'sid' => $sessionID
                ]
            );
            //error_log(print_r($vstatus,true));


            //$vstatus['Visit_completed'] = $vstatus['Visit_completed'];
            return (new \LORIS\Http\Response())
                ->withStatus(200)
                ->withHeader("Content-Type", "text/plain")
                ->withBody(
                    new \LORIS\Http\StringStream(
                        json_encode($vstatus)
                    )
                );
        }
	if($data == "get_instrument_incomplete_reasons_option") {

		// todo get option from instrument_incomplete_reasons table

            $result = $db->pselect(
		    "SELECT
		     ID,
		     Reason
		     from instrument_incomplete_reasons
                     WHERE
                    Active = 'Y'",
                []
	);

	    foreach ($result as $row) {
		    $opt[$row["ID"]] = $row["Reason"];
		}

             $visit_completion['instrument_incomplete_reasons_option'] = $opt;
            return (new \LORIS\Http\Response())
                ->withStatus(200)
                ->withHeader("Content-Type", "text/plain")
                ->withBody(
                    new \LORIS\Http\StringStream(
                        json_encode($visit_completion)
                    )
                );
        }
        if($data == "VisitCompletion") {

            $visit_completion = $db->pselect(
                "SELECT
                    tn.Full_name AS Instrument,
                    f.CommentID,
                    f.Administration,
                    f.Data_entry,
                    f.Administration_incomplete_reason,
                    f.Administration_incomplete_reason_other
                FROM
                    candidate c
                JOIN
                    session s
                ON
                    (c.CandID=s.candID)
                JOIN
                    flag f
                ON
                    (f.sessionID=s.ID)
                JOIN
                    test_names tn
                ON
                    (tn.test_name=f.test_name)
                WHERE
                    c.CandID= :candID AND
                    f.sessionID= :sessionID AND
                    tn.IsDuplicatedInstrument IS NULL AND
                    f.CommentID NOT LIKE '%DDE_%'",
                ['candID' => $candID,
                'sessionID'  => $sessionID]
	);
            return (new \LORIS\Http\Response())
                ->withStatus(200)
                ->withHeader("Content-Type", "text/plain")
                ->withBody(
                    new \LORIS\Http\StringStream(
                        json_encode($visit_completion)
                    )
                );

        }


    }
}


