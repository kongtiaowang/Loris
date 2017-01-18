<?php
/**
 * Training module: Allows examiners to undergo training in order
 * to receive certification to administer an instrument.
 *
 * PHP Version 5
 *
 * @category Behavioural
 * @package  Loris
 * @author   Tara Campbell <tara.campbell@mail.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/Loris
 */

/**
 * Training module: Allows examiners to undergo training in order
 * to receive certification to administer an instrument.
 *
 * PHP Version 5
 *
 * @category Behavioural
 * @package  Loris
 * @author   Tara Campbell <tara.campbell@mail.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/Loris
 */
class NDB_Form_Todo extends NDB_Form
{
    /**
     * Checks if the user has access to examiner forms (edit_examiner and training)
     *
     * @return boolean
     */
    function _hasAccess()
    {
        $user = User::singleton();
        return true;
    }

    /**
     * Construct the template variables for the training page.
     *
     * @return void
     */
    function todo()
    {
    }

    /**
     * Gathers JS dependecies and merge them with the parent
     *
     * @return array of javascript to be inserted
     */
    function getJSDependencies()
    {
        $factory = NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $deps    = parent::getJSDependencies();
        return array_merge(
            $deps,
            array(
             $baseURL . "/todo/js/script.js",
            )
        );
    }

    /**
     * Gathers CSS dependecies and merge them with the parent
     *
     * @return array of javascript to be inserted
     */
    function getCSSDependencies()
    {
        $factory = NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $deps    = parent::getCSSDependencies();
        return array_merge(
            $deps,
            array(
             $baseURL . "/training/css/training.css",
            )
        );
    }
}
?>
