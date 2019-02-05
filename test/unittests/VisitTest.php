<?php
/**
 * Unit test for Visit class
 *
 * PHP Version 5
 *
 * @category Tests
 * @package  Test
 * @author   Mélanie Legault <melanie.legault2@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */

require_once __DIR__ . '/../../vendor/autoload.php';
require_once __DIR__ . '/../../php/libraries/VisitController.class.inc';
require_once __DIR__ . '/../../php/libraries/Visit.class.inc';

use \LORIS\Visit;
//use \LORIS\VisitController;
use \PHPUnit\Framework\TestCase;

/**
 * Unit test for Candidate class
 *
 * @category Tests
 * @package  Test
 * @author   Mélanie Legault <melanie.legault2@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */
class VisitTest extends TestCase
{
    /**
     * Visit object use in tests
     *
     * @var Visit
     */
    private $_visit;

    protected function setUp()
    {
        $this->factory = NDB_Factory::singleton();
        $this->factory->reset();
        $this->factory->setTesting(false);
        $this->config = $this->factory->Config(CONFIG_XML);
        $database = $this->config->getSetting('database');
        $this->DB  = Database::singleton(
            $database['database'],
            $database['username'],
            $database['password'],
            $database['host'],
            1
        );
        $this->_visitController = new \Loris\VisitController($this->DB);


    }

    function testVisit()
    {
       $visit_name = "Visit 1";
       $visit = new Visit($visit_name);
       $this->assertEquals($visit_name, $visit->getName(), "the name of the visit does not match");
    }

    function testAllVisit()
    {
        $visits = $this->_visitController->getAllVisits();
        $this->assertContains("V3",json_encode($this->_listOfVisit));
    }  

    /**
     * Tears down the fixture, for example, close a network connection.
     * This method is called after a test is executed.
     *
     * @return void
     */
    protected function tearDown()
    {
        parent::tearDown();
        $this->factory->reset();
    }

}
