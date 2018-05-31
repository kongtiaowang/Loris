<?php

/**
 * IBIS module.
 *
 * PHP Version 5
 *
 * @category   Module
 * @package    Main
 * @subpackage Parent Portal
 * @author     Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris-Trunk/
 */
namespace LORIS\parent_portal;

/**
 *
 * @category   Module
 * @package    Main
 * @subpackage Parent Portal
 * @author     Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris-Trunk/
 */
class parent_portal extends \NDB_Form
{
    /**
     * Determine whether the user has permission to view this page
     *
     * @return bool whether the user has access
     */
    function _hasAccess()
    {
        return true;
    }

    /**
     * CommonPageSetup sets up the common form elements which
     * are on the page, regardless of HTTP request method.
     *
     * @return none
     */
    function setup()
    {
        $config = \NDB_Config::singleton();
        $this->tpl_data['page_title'] = 'Parent Portal';

        $this->addBasicText(
            "pscid",
            "PSCID",
            array("placeholder" => "")
        );
        $this->form->addFormRule(array(&$this, '_validate'));

    }
    function _validate($values)
    {
        $errors = array();
        if (empty($values['pscid'])) {
            $errors['pscid'] = " PSCID is required!";
        }
        else {
            $db = \Database::singleton();

            $numCandidates = $db->pselectOne(
                "SELECT COUNT(*) FROM candidate 
            WHERE PSCID=:v_PSCID AND Active='Y'",
                array(
                    'v_PSCID' => $values['pscid'],
                )
            );
            if ($numCandidates != 1) {
                $errors['pscid'] = "Invalid PSCID";
            }
        }

            return $errors;

    }


    /**
     * _process redirects to the parent portal view surveys page if
     * valiadtion is correct for the value/pscid entered.
     *
     * @param array $values The values that were submitted to the page.
     *
     * @return none
     */
    function _process($values)
    {
        $factory = \NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $key=$values['pscid'];
        $url= $baseURL. "/parent_portal/view_surveys/?identifier=".base64_encode($key);
        header("Location:$url");

    }
//TO DO
    function encode($val)
    {
        $hashstring1 =base64_encode("ibis123hashing");
        $connector = "J345916";
        $hashstring2 =base64_encode($val);
        $final_string=$hashstring1.$connector.$hashstring2;
        return $final_string;

    }

}
?>