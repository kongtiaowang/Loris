<?php declare(strict_types=1);

/**
 * AcknowledgementsIntegrationTest automated integration tests
 *
 * PHP Version 5
 *
 * @category Test
 * @package  Loris
 * @author   Wang Shen <wangshen.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/Loris
 */
use Facebook\WebDriver\WebDriverBy;
require_once __DIR__ . "/../../../test/integrationtests/LorisIntegrationTest.class.inc";

/**
 * AcknowledgementsIntegrationTest
 *
 * @category Test
 * @package  Loris
 * @author   Wang Shen <wangshen.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/Loris
 */
class AcknowledgementsIntegrationTest extends LorisIntegrationTest
{
    // Filter locations
    private static array $selectors = [
        'fullname' => 'input[name="fullName"]',
        'citationName' => 'input[name="citationName"]',
        'startDate' => 'input[name="startDate"]',
        'endDate' => 'input[name="endDate"]',
        'present' => 'select[name="present"]',
        'display' => '.table-header > .row > div > div:nth-child(1)',
        'clearFilter' => 'a[name="reset"]',
    ];

    // Initial array data
    private static array $testData = [
        'ID' => '999',
        'ordering' => '999',
        'full_name' => 'Demo Test',
        'citation_name' => "Demo's Citation",
        'affiliations' => 'mcgill',
        'degrees' => 'bachelors',
        'roles' => 'investigators',
        'start_date' => '2015-01-01',
        'end_date' => '2016-01-01',
        'present' => 'Yes',
    ];

    private static array $newData = [
        'ordering' => '9999',
        'full_name' => 'Test Test',
        'citation_name' => "Test's Citation",
        'affiliations' => 'McGill',
        'degrees' => 'Bachelors',
        'roles' => 'Investigators',
        'start_date' => '2016-11-11',
        'end_date' => '2017-11-11',
        'present' => 'Yes',
    ];

    /**
     * Insert testing data into the database.
     *
     * @return void
     */
    protected function setUp(): void
    {
        parent::setUp();
        $this->setUpConfigSetting("citation_policy", "citation policy test text");
        $this->DB->insert("acknowledgements", self::$testData);
    }

    /**
     * Delete testing data from database.
     *
     * @return void
     */
    protected function tearDown(): void
    {
        $this->restoreConfigSetting("citation_policy");
        $this->DB->delete("acknowledgements", ['ID' => '999']);
        $this->DB->delete("acknowledgements", ['full_name' => 'Test Test']);
        parent::tearDown();
    }

    /**
     * Tests that the Acknowledgements module loads correctly with view permission.
     *
     * @return void
     */
    function testAcknowledgementsPageLoadWithView(): void
    {
        $this->checkPageLoad('acknowledgements_view', 'Acknowledgements');
    }

    /**
     * Tests that the Acknowledgements module loads correctly with edit permission.
     *
     * @return void
     */
    function testAcknowledgementsPageLoadWithEdit(): void
    {
        $this->checkPageLoad('acknowledgements_edit', 'Acknowledgements');
    }

    /**
     * Helper function to check page load.
     *
     * @param string $permission
     * @param string $expectedText
     * @return void
     */
    private function checkPageLoad(string $permission, string $expectedText): void
    {
        $this->setupPermissions([$permission]);
        $this->safeGet($this->url . "/acknowledgements/");
        $bodyText = $this->safeFindElement(WebDriverBy::cssSelector("body"))->getText();

        $this->assertStringContainsString($expectedText, $bodyText);
        $this->assertStringNotContainsString("You do not have access to this page.", $bodyText);
        $this->assertStringNotContainsString("An error occurred while loading the page.", $bodyText);
    }

    /**
     * Ensures that the module loads if the user has one of the permissions.
     *
     * @return void
     */
    public function testPermissions(): void
    {
        $this->checkPagePermissions('/acknowledgements/', ['acknowledgements_view', 'acknowledgements_edit'], "Acknowledgements");
    }

    /**
     * Tests filter and clear filter functionality.
     *
     * @return void
     */
    function testFilters(): void
    {
        $this->safeGet($this->url . "/acknowledgements/");

        foreach (self::$selectors as $key => $selector) {
            if (in_array($key, ['display', 'clearFilter'])) {
                continue; // Skip display and clearFilter selectors.
            }
            $this->_filterTest(
                $selector,
                self::$selectors['display'],
                self::$selectors['clearFilter'],
                self::$testData[$key],
                $key === 'present' ? "30" : "1 row"
            );
        }
    }

    /**
     * Tests that the Add Acknowledgement button is not visible without edit permission.
     *
     * @return void
     */
    function testCantAddNewRecord(): void
    {
        $this->setupPermissions(["acknowledgements_view"]);
        $this->safeGet($this->url . "/acknowledgements/");
        $bodyText = $this->safeFindElement(WebDriverBy::cssSelector("body"))->getText();
        $this->assertStringNotContainsString("Add Acknowledgement", $bodyText);
    }

    /**
     * Tests that the citation policy setting is displayed on the page.
     *
     * @return void
     */
    function testConfigSettingPolicy(): void
    {
        $this->safeGet($this->url . "/acknowledgements/");
        $bodyText = $this->safeFindElement(WebDriverBy::cssSelector("#citationPolicy"))->getText();
        $this->assertStringContainsString("citation policy test text", $bodyText);
    }
}

