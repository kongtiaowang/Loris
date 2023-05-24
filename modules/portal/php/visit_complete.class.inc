<?php declare(strict_types=1);
namespace LORIS\portal;
use \Psr\Http\Message\ServerRequestInterface;
use \Psr\Http\Message\ResponseInterface;
use \LORIS\Middleware\ETagCalculator;

class Visit_Complete extends \NDB_Page implements ETagCalculator
{
    /**
     * This function will return a json object for Visit Complete Form.
     *
     * @param ServerRequestInterface $request The incoming PSR7 request
     *
     * @return ResponseInterface The outgoing PSR7 response
     */
    public function handle(ServerRequestInterface $request) : ResponseInterface
    {
        // Ensure POST request.
        switch ($request->getMethod()) {
            case 'POST':
                return $this->_handlePOST($request);
            default:
                return new \LORIS\Http\Response\JSON\MethodNotAllowed(
                    $this->allowedMethods()
                );
        }
    }

    /**
     * Processes the values & saves to database and return a json response.
     *
     * @param ServerRequestInterface $request The incoming PSR7 request.
     *
     * @return ResponseInterface The outgoing PSR7 response
     */
    private function _handlePOST(ServerRequestInterface $request) : ResponseInterface
    {
        $value = json_decode((string) $request->getBody(), true) ?? [];
	    parse_str($value, $values);
        if (isset($values['update'])
            && $values['update'] === 'UpdateVisitComplete'
        ) {
            return $this->updateVisitCompleteForm($request);
        }

        return new \LORIS\Http\Response\JSON\BadRequest(
            'Error'
        );
    }

    /**
     * Update Visit Complete Form.
     *
     * @param ServerRequestInterface $request The incoming PSR7 request.
     *
     * @return ResponseInterface The outgoing PSR7 response
     */
    function  updateVisitCompleteForm(ServerRequestInterface $request) : ResponseInterface
    {
        $db = \NDB_Factory::singleton()->database();
        // Parse POST request body.
	    $value = json_decode((string) $request->getBody(), true);
	    parse_str($value, $values);
        $candID = $values['candID'];
        $session = $values['session'];
        error_log($candID);
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

        $collection = $db->pselect(
            "SELECT
            f.CommentID AS commentID
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
            c.CandID=:cid AND
            s.ID=:sid AND
            f.CommentID NOT LIKE '%DDE_%'",
            [
                'cid' => $candID,
                'sid' => $sessionID,
            ]
        );
	//error_log(print_r($collection,true));
	//error_log("----------------------");
	//error_log(print_r($values,true));
        foreach ($collection as $row) {
            $commentID = $row['commentID'];
            // Always Required
            $admin_status    = $values[$commentID.'_Administration'];
            $data_entry_status    = $values[$commentID.'_Data_entry'];

            if($admin_status=='All')
            {
                $not_completed_reason =null;
                $not_completed_reason_other  = null;

            }
            else{
                $not_completed_reason = $values[$commentID.'_Administration_incomplete_reason'];
                if ($not_completed_reason =='Other')
                {
                    $not_completed_reason_other = $values[$commentID . '_Administration_incomplete_reason_other'];
                }
                else{
                    $not_completed_reason_other = null;
                }
            }

            $updateValues
                = [
                'Administration'    => $admin_status,
                'Data_entry' => $data_entry_status,
                'Administration_incomplete_reason'       => $not_completed_reason,
                'Administration_incomplete_reason_other' => $not_completed_reason_other,
            ];
            $updateSession
                = [
                    'Visit_completed'    => 'Y'
                ];

            $db->update(
                'flag', $updateValues, ['CommentID' => $commentID]
            );
            $db->update(
                'session', $updateSession, [
                    'CandID' => $candID,
                    'ID' => $sessionID,
                ]
            );
	}
            return (new \LORIS\Http\Response())
                ->withStatus(200)
                ->withHeader("Content-Type", "text/plain");

        // Always claim success to avoid providing user info to attackers.

    }

    /**
     * An ETagCalculator provides the ability to calculate an ETag for
     * an incoming HTTP request.
     *
     * @param ServerRequestInterface $request The incoming PSR7 request.
     *
     * @return string The value to use for the ETag header.
     */
    public function ETag(ServerRequestInterface $request): string
    {
        if ($request->getMethod() === 'POST') {
            return '';
        }
    }

    /**
     * Return an array of valid HTTP methods for this endpoint
     *
     * @return string[] Valid versions
     */
    protected function allowedMethods(): array
    {
        return [
            'POST',
        ];
    }

    /**
     * Returns true if the user has permission to access
     * the Module
     *
     * @param \User $user The user whose access is being checked
     *
     * @return bool true if user has permission
     */
    function _hasAccess(\User $user) : bool
    {
        return true;
    }

}
