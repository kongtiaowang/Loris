<?php
namespace LORIS\reliability;

/**
 * The welcome menu
 * @package main
 */
class Reliability_diagnostic_calls extends \NDB_Menu
{
    function setup()
    {   
       $DB =& \Database::singleton();
       
        $result = $DB->pselect("SELECT * FROM reliability_diagnostic_calls", array());
            foreach($result as $row){          
               $data[] = array('date_of_review' => $row['date_of_review'], 'caseID_1' => $row['caseID_1'], 'caseID_2' => $row['caseID_2'], 'caseID_3' => $row['caseID_3']);
            }
            $this->tpl_data["data"] = $data;      
      
           
    } // End function
} // End class
?>