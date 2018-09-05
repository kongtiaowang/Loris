<?php
/**
 * Genomic_browser automated integration tests
 *
 * PHP Version 5
 *
 * @category Test
 * @package  Loris
 * @author   Wang Shen <shen.wang2@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/Loris
 */
require_once __DIR__
    . "/../../../test/integrationtests/LorisIntegrationTest.class.inc";

/**
 * GenomicBrowserTestIntegrationTest
 *
 * PHP Version 5
 *
 * @category Test
 * @package  Loris
 * @author   Wang Shen <shen.wang2@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/Loris
 */
class GenomicBrowserTestIntegrationTest extends LorisIntegrationTest
{

    /**
     * Provide a list of the CNV form filters
     *
     * @return array The filters list
    */
    private function _getCNVFilters()
    {
        return array(
                'centerID',
                'SubprojectID',
                'DCCID',
                'gender',
                'External_ID',
                'PSCID',
                'Gene_Symbol',
                'Gene_Name',
                'Chromosome',
                'Platform',
                'CNV_Type',
                'Event_Name',
                'Characteristics',
                'Common_CNV',
                'Copy_Num_Change',
                'Inheritance',
                'CNV_Description',
               );
    }

    /**
     * Provide a list of the SNP form filters
     *
     * @return array The filters list
    */
    private function _getSNPFilters()
    {
        return array(
                'centerID',
                'DCCID',
                'PSCID',
                'gender',
                'SubprojectID',
                'dob',
                'External_ID',
                'rsID',
                'SNP_Name',
                'SNP_Description',
                'SNP_External_Source',
                'Allele_A',
                'Allele_B',
                'Reference_Base',
                'Minor_Allele',
                'Array_Report',
                'Markers',
                'Validation_Method',
                'Validated',
                'Function_Prediction',
                'Damaging',
                'Genotype_Quality',
                'Exonic_Function',
                'Chromosome',
                'Gene_Symbol',
                'Platform',
               );
    }


    /**
     * An helper function to ensure the new page is load after a click.
     *
     * @param WebDriverElement $webDriverElement the element to click.
     *
     * @return void
     */
    public function clickToLoadNewPage($webDriverElement)
    {
        $webDriverElement->click();
        try {
            while (true) {
                $webDriverElement->getText();
            }
        } catch (StaleElementReferenceException $e) {
            return;
        }
    }

    /**
     * Helper function to assert the culumn content is sorted
     * upon click on the header.
     *
     * @param string $header     The header label
     * @param int    $col_number The column index (1 based)
     * @param string $asc        The expected value on ascending sort
     * @param string $desc       The expected value on descending sort
     *
     * @return void
     */
    public function assertColumnSorting($header, $col_number, $asc, $desc)
    {

        // ASC sorting
        $header_link = $this->webDriver->findElement(
            WebDriverBy::xPath(
                "
                //div[@id='lorisworkspace']
                //table[contains(@class, 'dynamictable')]
                /thead
                /tr
                /th
                /a[text()='$header']
            "
            )
        );
        $this->clickToLoadNewPage($header_link);
        $body            = $this->webDriver->findElement(
            WebDriverBy::xPath("//body")
        );
        $first_row_value = $body->findElement(
            WebDriverBy::xPath(
                "
                //div[@id='lorisworkspace']
                //table[contains(@class, 'dynamictable')]
                /tbody
                /tr[1]
                /td[$col_number]
            "
            )
        )->getText();
        $this->assertEquals($first_row_value, $asc);

        // DESC sorting
        $header_link = $this->webDriver->findElement(
            WebDriverBy::xPath(
                "
                //div[@id='lorisworkspace']
                //table[contains(@class, 'dynamictable')]
                /thead
                /tr
                /th
                /a[text()='$header']
            "
            )
        );
        $this->clickToLoadNewPage($header_link);
        $body            = $this->webDriver->findElement(
            WebDriverBy::xPath("//body")
        );
        $first_row_value = $body->findElement(
            WebDriverBy::xPath(
                "
                //div[@id='lorisworkspace']
                //table[contains(@class, 'dynamictable')]
                /tbody
                /tr[1]
                /td[$col_number]
            "
            )
        )->getText();
        $this->assertEquals($first_row_value, $desc);
    }

    /**
      * Tests that, when loading the genomic_browser module, the
      * breadcrumb is 'Genomic browser' or an error is given according
      * to the user's permissions.
      *
      * @return void
      */
    function testGenomicBrowserWithoutPermission()
    {
         $this->setupPermissions(array());
         $this->safeGet($this->url . "/genomic_browser/");
         $bodyText = $this->webDriver->findElement(
             WebDriverBy::cssSelector("body")
         )->getText();
         $this->assertContains("You do not have access to this page.", $bodyText);
         $this->resetPermissions();
    }
    /**
      * Tests that, when loading the genomic_browser module, the
      * breadcrumb is 'Genomic browser' or an error is given according
      * to the user's permissions.
      *
      * @return void
      */
    function testGenomicBrowserWithPermission()
    {
         $this->setupPermissions(
             array(
              "genomic_browser_view_allsites",
              "genomic_browser_view_site",
             )
         );
         $this->safeGet($this->url . "/genomic_browser/");
         $bodyText = $this->webDriver->findElement(
             WebDriverBy::cssSelector("body")
         )->getText();
         $this->assertNotContains("You do not have access to this page.", $bodyText);
         $this->resetPermissions();
    }
    /**
      * Tests that, when loading the genomic_browser module, the each Tab should
      * have their own UIs.
     *
      * @return void
      */
    function testGenomicBrowserEachTab()
    {
        $this->_testPageUIs("/genomic_browser/", $this->_loadingProfilesUI);
        $this->_testPageUIs("/genomic_browser/gwas_browser/", $this->_loadingGWASUI);
        $this->_testPageUIs("/genomic_browser/snp_browser/", $this->_loadingSNPUI);
        $this->_testPageUIs("/genomic_browser/cpg_browser/", $this->_MethylationUI);
        $this->_testPageUIs(
            "/genomic_browser/genomic_file_uploader/",
            $this->_FilesUI
        );
    }
    /**
      * Tests that, inputing test data and searching the data,
      * checking the results in the table.
      *
      * @return void
      */
    function testGenomicBrowserFilterEachTab()
    {
        $this->markTestSkipped("Skipping long test");
        return;
        // test filter in Profiles Tab
        $this->_testFilter("/genomic_browser/", "PSCID", "MTL001", "1 rows");
        $this->_testFilter("/genomic_browser/", "DCCID", "300001", "1 rows");
        $this->_testFilter(
            "/genomic_browser/",
            "PSCID",
            "999999",
            "No result found."
        );
        $this->_testFilter(
            "/genomic_browser/",
            "DCCID",
            "999999",
            "No result found."
        );
        // test filter in GWAS Tab
        $this->_testFilter(
            "/genomic_browser/gwas_browser/",
            "Chromosome",
            "chr14",
            "No result found."
        );
        $this->_testFilter(
            "/genomic_browser/gwas_browser/",
            "BP_Position",
            "19009011",
            "No result found."
        );
        $this->_testFilter(
            "/genomic_browser/gwas_browser/",
            "Chromosome",
            "999999",
            "No result found."
        );
        $this->_testFilter(
            "/genomic_browser/gwas_browser/",
            "BP_Position",
            "999999",
            "No result found."
        );
        // test filter in SNP Tab
        $this->_testFilter(
            "/genomic_browser/snp_browser/",
            "rsID",
            "MTL001",
            "No result found."
        );
        $this->_testFilter(
            "/genomic_browser/snp_browser/",
            "rsID",
            "999999",
            "No result found."
        );
    }
    /**
      * This function could test UI elemnts in each Tabs.
      *
      * @param string $url this is for the url which needs to be tested.
      * @param string $ui  UI elements in each Tabs.
      *
      * @return void
      */
    function _testPageUIs($url,$ui)
    {
        $this->safeGet($this->url . $url);
        foreach ($ui as $key => $value) {
            $text = $this->webDriver->executescript(
                "return document.querySelector('$value').textContent"
            );
            $this->assertContains($key, $text);
        }

    }
    /**
      * This function could test filter function in each Tabs.
      *
      * @param string $url            this is for the url which needs to be tested.
      * @param string $filter         the filter which needs to be tested.
      * @param string $testData       the test data.
      * @param string $expectDataRows the expect rows in the table.
      *
      * @return void
      */
    function _testFilter($url,$filter,$testData,$expectDataRows)
    {
        $this->safeGet($this->url . $url);
         $this->safeFindElement(
             WebDriverBy::Name($filter)
         )->sendKeys($testData);
         //click showdata button
                  $this->safeFindElement(
                      WebDriverBy::Name('filter')
                  )->click();
                  $text = $this->webDriver->executescript(
                      "return document.querySelector('#datatable').textContent"
                  );
                  $this->assertContains($expectDataRows, $text);
    }
    /**
      * Tests that, when clicking the upload button,the upload window should show up
      *
      * @return void
      */
    function testUploadFile()
    {
        $this->safeGet($this->url . "/genomic_browser/genomic_file_uploader/");
        $this->safeFindElement(
            WebDriverBy::Name("upload")
        )->click();
        $value    = "#myModalLabel";
            $text = $this->webDriver->executescript(
                "return document.querySelector('$value').textContent"
            );
            $this->assertContains("Upload File", $text);
    }
}
