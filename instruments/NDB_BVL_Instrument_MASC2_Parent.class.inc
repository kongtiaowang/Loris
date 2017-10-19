<?php
/*
 * This file contains the NDB_BVL_Instrument_MACS2_Parent
 * class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the CDI_Words_Sentences instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

class NDB_BVL_Instrument_MASC2_Parent extends NDB_BVL_Instrument
{

    var $ValidityEnabled = false;
    var $ValidityRequired = false;

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     *
     * @return void
     * @access public
     */
    function setup($commentID, $page)
    {
        $this->formType = "XIN";
        $this->form = new LorisForm('MASC2_Parent_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = 'MASC2_Parent';           // test_names.Test_name
        $this->table = 'MASC2_Parent';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
            'Examiner',
            'CommentID',
        );

        $config = NDB_Config::singleton();
        $this->dateOptions = array(
            'language' => 'en',
            'format' => 'YMd',
            'minYear' => $config->getSetting('startYear'),
            'maxYear' => $config->getSetting('endYear'),
            'addEmptyOption' => true,
            'emptyOptionValue' => null,
        );

        // setup the form
        $this->_setupForm();

    }

    /*
    * Method to build the LorisForm object into a paged form
    *
    * @return void
    * @access private
    */
    function _setupForm()
    {
        //determine page to display
        if (preg_match(
            "/MASC2_Parent(_page[0-9]+)/",
            $this->page,
            $matches
        )) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    function displayHeaders($headerNum) {
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Never/Rarely/Sometimes/Often");
        $this->form->addGroup(
            $group,
            "headers_" . $headerNum,
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
    }

    function _main()
    {
        // display test name
        $this->addHeader("MASC2: PARENT");
        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
    }

    function _page1() {
        $this->addLabel("<h4>Instructions: These sentences ask how your child might have been thinking, feeling, or acting recently.  
                         For each item, please circle the number that describes how often the statement is true about 
                         your child.</h4>");
        $this->addLabel("$this->indent Circle 0 if a sentence is Never true about your child.");
        $this->addLabel("$this->indent Circle 1 if a sentence is Rarely true about your child.");
        $this->addLabel("$this->indent Circle 2 if a sentence is Sometimes true about your child.");
        $this->addLabel("$this->indent Circle 3 if a sentence is Often true about your child.");
        $this->addLabel("<h4>Remember, there are no right or wrong answers, just answer how your child has been feeling recently.</h4>");

        $options =
            array(
                null=>"",
                0 => 0,
                1 => 1,
                2 => 2,
                3 => 3
            );

        $questions =
            array(
                "q1" => "1. My child feels tense or uptight.",
                "q2" => "2. My child usually aks permission to do things.",
                "q3" => "3. My child worries about other people.",
                "q4" => "4. My child gets scared when his/her parents go away.",
                "q5" => "5. My child keeps his/her eyes open for danger.",
                "q6" => "6. My child has trouble getting his/her breath.",
                "q7" => "7. The idea of going away to camp scares my child.",
                "q8" => "8. My child gets shaky or jittery.",
                "q9" => "9. My child tries to stay near mom or dad.",
                "q10" => "10. My child is afraid that other kids will make fun of him/her.",
                "q11" => "11. My child tries hard to obey his/her parents and teachers.",
                "q12" => "12. My child gets dizzy or faint feelings.",
                "q13" => "13. My child checks things out first.",
                "q14" => "14. My child worries about getting called on in class.",
                "q15" => "15. My child is jumpy.",
                "q16" => "16. My child is afraid other people will think he/she is stupid.",
                "q17" => "17. My child keeps the light on at night.",
                "q18" => "18. My child has pains in his/her chest.",
                "q19" => "19. My child avoids going places without the family.",
                "q20" => "20. My child feels strange, weird, or unreal.",
                "q21" => "21. My child tries to do things other people will like.",
                "q22" => "22. My child worries about what other people think of him/her.",
                "q23" => "23. My child avoids watching scary movies or TV shows.",
                "q24" => "24. My child's heart races or skips beat.",
                "q25" => "25. My child stays away from things that upset him/her."
            );

        $this->displayHeaders(1);
        foreach ($questions as $qNum=>$qLabel) {
            $group[] =& $this->createLabel($qLabel);
            $group[] =& $this->createSelect($qNum, "", $options);
            $this->form->addGroup(
                $group,
                "page1_questions_" . $qNum,
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
    }

    function _page2() {
        $options =
            array(
                null => "",
                0 => 0,
                1 => 1,
                2 => 2,
                3 => 3
            );

        $this->displayHeaders(2);
        $questions =
            array(
                "q26" => "26. My child sleeps next to someone from the family.",
                "q27" => "27. My child feels restless and on edge.",
                "q28" => "28. My child tries to do everything exactly right.",
                "q29" => "29. My child worries about doing something stupid or embarrassing.",
                "q30" => "30. My child gets scared riding in the car or on the bus.",
                "q31" => "31. My child feels sick to his/her stomach.",
                "q32" => "32. My child get nervous if he/she have to perform in public.",
                "q33" => "33. Bad weather, the dark, heights, animals, or bugs scare my child.",
                "q34" => "34. My hands shake.",
                "q35" => "35. My child checks to make sure things are safe.",
                "q36" => "36. My child has trouble asking other kids to play with him/her.",
                "q37" => "37. My child's hands feel sweaty or cold.",
                "q38" => "38. My child feels shy.",
                "q39" => "39. My child has trouble making up his/her mind about simple things.",
                "q40" => "40. My child gets upset over the thought that he/she might get sick.",
                "q41" => "41. My child has bad or silly thoughts that he/she can't stop.",
                "q42" => "42. My child has to do things over and over again for no reason.",
                "q43" => "43. My child gets really upset about dirt, germs, chemicals, radiation or sticky things.",
                "q44" => "44. My child feels that he/she has to wash or clean more than he/she really needs to.",
                "q45" => "45. My child fears that he/she will be responsible for something bad happening.",
                "q46" => "46. My child has to check that nothing terrible has happened.",
                "q47" => "47. My child has to check things several times or more.",
                "q48" => "48. My child counts things for no reason.",
                "q49" => "49. My child get too concerned with sin or wrongdoing.",
                "q50" => "50. My child has to repeat things until it feels just right."
            );

        foreach ($questions as $qNum=>$qLabel) {
            $group[] =& $this->createLabel($qLabel);
            $group[] =& $this->createSelect($qNum, "", $options);
            $this->form->addGroup(
                $group,
                "page2_questions_" . $qNum,
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
    }

}
