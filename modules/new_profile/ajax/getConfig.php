<?php
/**
 * Media downloader.
 *
 * This ensures that the file exists and the user is logged in to
 * Loris before trying to return the file to the user.
 *
 * PHP Version 5
 *
 * @category Loris
 * @package  Media
 * @author   Alex I. <ailea.mcin@gmail.com>
 * @license  Loris license
 * @link     https://github.com/aces/Loris-Trunk
 */
ini_set('default_charset', 'utf-8');
require_once "Utility.class.inc";
$user =& User::singleton();
if (!$user->hasPermission('media_write')) {
    header("HTTP/1.1 403 Forbidden");
    exit;
}
        $result    = array();
        $config    =& \NDB_Config::singleton();
        $result['startYear'] = $config->getSetting('startYear');
        $result['endYear']   = $config->getSetting('endYear');
        $result['ageMax']    = $config->getSetting('ageMax');
        $result['ageMin']    = $config->getSetting('ageMin');
        $result['dobFormat'] = $config->getSetting('dobFormat');
        $result['edc']       = $config->getSetting('useEDC');
        $result['gender']    = ['male' =>  "Male",'female' =>  "Female"];

        //returned as a string
        echo json_encode($result);
?>
