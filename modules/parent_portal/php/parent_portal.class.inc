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
            "parentID",
            "ParentID",
            array("placeholder" => "")
        );

        $this->addBasicText(
            "email",
            "Email",
            array("placeholder" => "")
        );
        $this->form->addFormRule(array(&$this, '_validate'));

    }
    function _validate($values)
    {
        $errors = array();
        if (empty($values['email'])) {
            $errors['email'] = " Email is required!";
        }
        if (empty($values['parentID'])) {
            $errors['parentID'] = " ParentID is required!";
        }
        else {
            $db = \Database::singleton();

            $numSurveys = $db->pselectOne(
                "SELECT COUNT(*) FROM participant_accounts  
            WHERE Email=:surv_email",
                array(
                    'surv_email' => $values['email'],
                )
            );
            if ($numSurveys <= 1) {
                $errors['email'] = "Oops..Something Went Wrong";
            }
        }

            return $errors;

    }


    /**
     * _process redirects to the parent portal view surveys page if
     * validation is correct for the email entered.
     *
     * @param array $values The values that were submitted to the page.
     *
     * @return none
     */
    function _process($values)
    {
        $factory = \NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $key=$values['email'];
        $url= $baseURL. "/parent_portal/view_surveys/?identifier=".base64_encode($key);
        header("Location:$url");

    }
}
?>