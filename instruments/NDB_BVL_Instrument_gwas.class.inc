<?php

/*
 * This file contains the NDB_BVL_Instrument_gwas
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Nicolas Brossard 
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the gwas instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Nicolas Brossard 
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_gwas extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    const YES_NO_OPTIONS = array(
        null  => '',
        'yes' => 'Yes',
        'no'  => 'No'
    );

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID  the CommentID identifying the data to load
     * @param string $page       if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;

        // set the object properties
        $this->testName  = "gwas";
        $this->table     = "gwas";
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array();

        $this->_doubleDataEntryDiffIgnoreColumns = array();

        // setup the form
        $this->_setupForm();
    }

    /**
     * Method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        $this->_main();

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array($this,'XINValidate'));
        $this->form->addFormRule(array($this,'validate_main'));
    }

    /**
     * Generates the main (and only) page of the form.
     *
     * @return void
     * @access private
     *
     */
    function _main()
    {
        // display test name
        $this->form->addElement('header', 'instrument_title', "Genome-wide Association Study");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $who = ['subject', 'proband', 'mother', 'father'];
        for ($i=1; $i <= count($who); $i++) {
            $whoString = $who[$i-1] == 'subject' ? 'subject' : "subject's {$who[$i-1]}";
            $this->addSelect("{$who[$i-1]}_qc", "$i) Was GWAS data QC'd from this $whoString?", self::YES_NO_OPTIONS);
            $this->form->addElement("text", "{$who[$i-1]}_gwasid", "{$this->indent}If yes, enter the GWAS ID:");
            $this->XINRegisterRule("{$who[$i-1]}_gwasid", array("{$who[$i-1]}_qc{@}=={@}yes"), "Required if answered yes to question $i");
        }

        $this->addBasicTextArea('comment', "Comments:");
        $this->XINRegisterRule("comment", array("comment{@}=={@}NEVER_REQUIRED"));
    }

    /**
     * Performs additionnal validation on the main page.
     *
     * @param array $values submitted values.
     * @return array errors found.
     */
    function validate_main(array $values)
    {
        $errors = [];

        $persons = ['subject', 'proband', 'mother', 'father'];
        foreach ($persons as $p) {
            if ($values["{$p}_qc"] == 'no' && $values["{$p}_gwasid"] != '') {
                $errors["{$p}_gwasid"] =
                    "This field must be left blank since you answered 'No' above";
            }
        }

        return $errors;
    }
}

?>
