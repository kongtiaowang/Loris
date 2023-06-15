<?php declare(strict_types=1);
/**
 * This file implements a data provisioner to get all modules
 * for the Module Manager menu page.
 *
 * PHP Version 7
 *
 * @category   Core
 * @package    Main
 * @subpackage Core
 * @author     Shen Wang <wangshen.mcin@gmail.com>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris/
 */

namespace LORIS\imaging_uploader;

/**
 * This class implements a data provisioner to get all modules
 * for the module manager menu page.
 *
 * PHP Version 7
 *
 * @category   Core
 * @package    Main
 * @subpackage Core
 * @author     Shen Wang <wangshen.mcin@gmail.com>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris/
 */
class ImagingUploaderProvisioner extends \LORIS\Data\Provisioners\DBRowProvisioner
{
     /**
      * Create a ModuleManagerProvisioner, which gets modules for the
      * module manager menu table.
      */
    function __construct()
    {
        $progressSelectPart = "IF(ISNULL(Inserting), 'Not Started',"
            . "IF(Inserting=1, 'In Progress...', "
	    . "IF(InsertionComplete=0, 'Failure', 'Success'))) as Progress";
	
        parent::__construct(
		"SELECT
            UploadID AS Upload_ID,
	    {$progressSelectPart},
            s.CandID,
            c.PSCID,
            s.Visit_label AS Visit,
            UploadLocation AS Upload_Location,
            UploadDate AS Upload_Date,
            UploadedBy AS Uploaded_By,
            mu.TarchiveID AS Tarchive_Info,
            number_of_mincCreated AS Number_of_MINC_Created,
            number_of_mincInserted AS Number_of_MINC_Inserted,
            ta.PatientName,
	    s.ID AS SessionID
            FROM mri_upload mu LEFT JOIN session 
                               s ON (s.ID = mu.SessionID) 
                               LEFT JOIN candidate c ON (c.CandID = s.CandID) 
                               LEFT JOIN tarchive ta ON 
			       (mu.TarchiveID = ta.TarchiveID)
where 1=1
            ",
            [],
        );
    }

    /**
     * Returns an instance of a HelpRow object for a given
     * table row.
     *
     * @param array $row The database row from the LORIS Database class.
     *
     * @return \LORIS\Data\DataInstance An instance representing this row.
     */
    public function getInstance($row) : \LORIS\Data\DataInstance
    {
            return new ImagingRow($row);
    }
}
