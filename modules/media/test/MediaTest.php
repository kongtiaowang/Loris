<?php
/**
 * Media module automated integration tests
 *
 * PHP Version 5
 *
 * @category Test
 * @package  Loris
 * @author   Wang Shen <wangshen.mcin@gmail.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/Loris
 */

require_once __DIR__ .
    "/../../../test/integrationtests/LorisIntegrationTest.class.inc";

/**
 * Media module automated integration tests
 *
 * PHP Version 5
 *
 * @category Test
 * @package  Loris
 * @author   Wang Shen <wangshen.mcin@gmail.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/Loris
 */
class MediaTest extends LorisIntegrationTest
{
    /**
     * UI elements and locations
     * breadcrumb - 'Access Profile'
     * Table headers
     */
    private $_loadingBrowseUI
        =  array(
            //Browse UIs
            'Browse'  => '#tab-browse',
            //Browse table header
            'No.'     => '#dynamictable > thead:nth-child(1) > tr:nth-child(1)',
            'File Name' => '#dynamictable > thead:nth-child(1) > tr:nth-child(1)',
            'PSCID'  => '#dynamictable > thead:nth-child(1) > tr:nth-child(1)',
            'Visit Label' => '#dynamictable > thead:nth-child(1) > tr:nth-child(1)',
            'Instrument' => '#dynamictable > thead:nth-child(1) > tr:nth-child(1)',
            'Site' => '#dynamictable > thead:nth-child(1) > tr:nth-child(1)',
            'Uploaded By' => '#dynamictable > thead:nth-child(1) > tr:nth-child(1)',
            'Date Taken'=>'#dynamictable > thead:nth-child(1) > tr:nth-child(1)',
            'Comments'=> '#dynamictable > thead:nth-child(1) > tr:nth-child(1)',
           );
    private $_loadingUploadUI
        =  array(
//            'Date Uploaded'=>'#dynamictable > thead > tr > th.dynamictableFrozenColumn',
            //Upload UIs
            'Upload a media file' => '#upload > div > div > form > div > div:nth-child(1) > h3',
            'PSCID' => '#upload > div > div > form > div > div:nth-child(4) > div > label',
            'Visit Label' => '#upload > div > div > form > div > div:nth-child(5) > div > label',
            'Instrument' => '#upload > div > div > form > div > div:nth-child(7) > div > label',
            'Browse' => '#upload > div > div > form > div > div:nth-child(10) > div > div > div > div.input-group-btn > div',
            'Upload File' => '#upload > div > div > form > div > div:nth-child(11) > div > div > button',
           );
    /**
     * Tests that the page does not load if the user does not have correct
     * permissions
     *
     * @return void
     */
    function testLoadsWithPermissionRead()
    {
        $this->setupPermissions(array("media_read"));
        $this->safeGet($this->url . "/media/");
        $bodyText = $this->webDriver->findElement(
            WebDriverBy::cssSelector("body")
        )->getText();
        $this->assertNotContains("You do not have access to this page.", $bodyText);
        $this->resetPermissions();
    }
    /**
     * Tests that the page does not load if the user does not have correct
     * permissions
     *
     * @return void
     */
    function testDoesNotLoadWithoutPermission()
    {
        $this->setupPermissions(array());
        $this->safeGet($this->url . "/media/");
        $bodyText = $this->webDriver->findElement(
            WebDriverBy::cssSelector("body")
        )->getText();
        $this->assertContains("You do not have access to this page.", $bodyText);
        $this->resetPermissions();
    }
    /**
      * Testing UI elements when page loads
      *
      * @return void
      */
    function testPageBrowseUIs()
    {
        $this->safeGet($this->url . "/media/");
        sleep(1);
        foreach ($this->_loadingBrowseUI as $key => $value) {
            $text = $this->webDriver->executescript(
                "return document.querySelector('$value').textContent"
            );
            $this->assertContains($key, $text);
        }
    }   
    /**
      * Testing UI elements when page loads
      *
      * @return void
      */
    function testPageUploadUIs()
    {
        $this->safeGet($this->url . "/media/#upload");
        $page = $this->webDriver->getPageSource();
        $var_dump($page);
        sleep(1);
        foreach ($this->_loadingUploadUI as $key => $value) {
            $text = $this->webDriver->executescript(
                "return document.querySelector('$value').textContent"
            );
            $this->assertContains($key, $text);
        }
    }
}
?>
