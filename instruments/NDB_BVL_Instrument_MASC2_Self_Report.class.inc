<?php
/*
 * This file contains the NDB_BVL_Instrument_MASC2_Self_Report
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

class NDB_BVL_Instrument_MASC2_Self_Report extends NDB_BVL_Instrument
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
        $this->form = new LorisForm('MASC2_Self_Report_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = 'MASC2_Self_Report';           // test_names.Test_name
        $this->table = 'MASC2_Self_Report';              // name of database table corresponding to instrument
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
            "/MASC2_Self_Report(_page[0-9]+)/",
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
        $this->addHeader("MASC2: SELF-REPORT");
        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
    }

    function _page1() {
        $this->addLabel("<h4>Instructions: These sentences ask how you might have been thinking, feeling, or acting recently.  
                         For each item, please circle the number that describes how often the statement is true about 
                         your child.</h4>");
        $this->addLabel("$this->indent Circle 0 if a sentence is Never true about you.");
        $this->addLabel("$this->indent Circle 1 if a sentence is Rarely true about you.");
        $this->addLabel("$this->indent Circle 2 if a sentence is Sometimes true about you.");
        $this->addLabel("$this->indent Circle 3 if a sentence is Often true about you.");
        $this->addLabel("<h4>Remember, there are no right or wrong answers, just answer how you might have been feeling recently.</h4>");

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
                "q1" => "1. I feel tense or uptight.",
                "q2" => "2. I usually ask permission to do things.",
                "q3" => "3. I worry about other people.",
                "q4" => "4. I get scared when my parents go away.",
                "q5" => "5. I keep my eyes open for danger.",
                "q6" => "6. I have trouble getting his/her breath.",
                "q7" => "7. The idea of going away to camp scares me.",
                "q8" => "8. I get shaky or jittery.",
                "q9" => "9. I try to stay near my mom or dad.",
                "q10" => "10. I'm afraid that other kids will make fun of me.",
                "q11" => "11. I try hard to obey my parents and teachers.",
                "q12" => "12. I get dizzy or faint feelings.",
                "q13" => "13. I check things out first.",
                "q14" => "14. I worry about getting called on in class.",
                "q15" => "15. I'm jumpy.",
                "q16" => "16. I'm afraid other people will think I'm is stupid.",
                "q17" => "17. I keep the light on at night.",
                "q18" => "18. I have pains in my chest.",
                "q19" => "19. I avoid going places without my family.",
                "q20" => "20. I feel strange, weird, or unreal.",
                "q21" => "21. I try to do things other people will like.",
                "q22" => "22. I worry about what other people think of me.",
                "q23" => "23. I avoid watching scary movies or TV shows.",
                "q24" => "24. My heart races or skips beat.",
                "q25" => "25. I stay away from things that upset him/her."
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
                "q26" => "26. I sleep next to someone from my family.",
                "q27" => "27. I feel restless and on edge.",
                "q28" => "28. I try to do everything exactly right.",
                "q29" => "29. I worry about doing something stupid or embarrassing.",
                "q30" => "30. I get scared riding in the car or on the bus.",
                "q31" => "31. I feel sick to my stomach.",
                "q32" => "32. I get nervous if I have to perform in public.",
                "q33" => "33. Bad weather, the dark, heights, animals, or bugs scare me.",
                "q34" => "34. My hands shake.",
                "q35" => "35. I check to make sure things are safe.",
                "q36" => "36. I have trouble asking other kids to play with me.",
                "q37" => "37. My hands feel sweaty or cold.",
                "q38" => "38. I feel shy.",
                "q39" => "39. I have trouble making up my mind about simple things.",
                "q40" => "40. I get upset over the thought that I might get sick.",
                "q41" => "41. I have bad or silly thoughts that I can't stop.",
                "q42" => "42. I have to do things over and over again for no reason.",
                "q43" => "43. I get really upset about dirt, germs, chemicals, radiation or sticky things.",
                "q44" => "44. I feel that I have to wash or clean more than I really need to.",
                "q45" => "45. I fear I'll be responsible for something bad happening.",
                "q46" => "46. I have to check that nothing terrible has happened.",
                "q47" => "47. I have to check things several times or more.",
                "q48" => "48. I count things for no reason.",
                "q49" => "49. I get too concerned with sin or wrongdoing.",
                "q50" => "50. I have to repeat things until it feels just right."
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
