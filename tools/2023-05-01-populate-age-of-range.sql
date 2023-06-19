#!/usr/bin/env php
<?php

/**
 *
 * PHP version 7
 *
 * @category Behavioural
 * @package  Main
 * @author   Shen
 * @license  Loris License
 * @link     https://github.com/kongtiaowang/Loris
 */

require_once __DIR__ . "/../../vendor/autoload.php";
require_once 'generic_includes.php';
require_once 'CouchDB.class.inc';
require_once 'Database.class.inc';
require_once "NDB_Client.class.inc";
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize();


$db = Database::singleton();

$instrumentLists =  $db->pselect("select Test_name from participant_accounts where Status='Complete'",array());

$CommentIDLists =  $db->pselect("select CommentID from participant_accounts where Status='Complete'",array());

$wb=0;
   foreach ($instrumentLists as $instrument) {
   print_r($instrument['Test_name']);
            foreach ($CommentIDLists as $CommentID) {
               print_r($CommentID);
               $query = "select * from ".$instrument['Test_name']." where CommentID=:CommentID";
         	$WhereCriteria = array('CommentID'=>$CommentID['CommentID']);

               $row = $db->pselectRow( 
                $query,
		$WhereCriteria
               );
                
                if (intval($row['Window_Difference']) == 0 && intval($row['Candidate_Age']) > 16*12 ) {
		print_r($CommentID['CommentID']);
                    $db->update(
                        $instrument['Test_name'],
                        array(

                            'Window_Difference'       => abs(16*12 - intval($row['Candidate_Age'])),
                        ),
                        array(

                            'CommentID'       => $CommentID['CommentID'],
                        )
                    );
                }    
            }
    }
    print_r("Done!");
   
