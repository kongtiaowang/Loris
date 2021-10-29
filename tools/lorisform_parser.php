<?php
/**
 * This script takes a list of files on the command line, parses them and generates a
 * staging file (ip_output.txt) which can be used by data_dictionary_builder.php and
 * generate_tables_sql.php
 *
 * Ex. call: find ../project/instruments/*.inc | php lorisform_parser.php
 *
 * When parsing a file, the script will only generate information for classes defined
 * inside that file that inherit from NDB_BVL_Instrument and that are not abstract. It will
 * also ignore those instrument classes listed in config setting 'excluded_instruments'.
 *
 * PHP version 7
 *
 * @category Behavioural
 * @package  Loris_Script
 * @author   Loris Team <loris.mni@bic.mni.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/Loris-Trunk
 */

set_include_path(get_include_path().":../libraries:../../php/libraries");
require_once __DIR__ . "/../../vendor/autoload.php";

$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize("../config.xml");

$instrumentsToSkip = array();
$instruments       = getExcludedInstruments();
foreach ($instruments as $instrument) {
    if (isset($instrument)) {
        $instrumentsToSkip[] = $instrument;
    }
}

//Get the list of files from STDIN
while ($file=fgets(STDIN)) {
    $file    =trim($file);
    $files[] =$file;
    echo $file;
}

// Get the array of classes currently loaded by the class loader
$declaredClassNames = get_declared_classes();

//Process the files
foreach ($files AS $file) {
    echo "\n";
    echo "Requiring file $file...\n";
    include_once $file;

    // Get the set of classes that had to be loaded following the inclusion
    // of $file
    $newDeclaredClassNames = get_declared_classes();
    $newClassNames = array_diff($newDeclaredClassNames, $declaredClassNames);

    if (empty($newClassNames)) {
        echo "File $file does not contain any class declarations. Skipping.\n";
    }

    foreach ($newClassNames as $newClassName) {
        $newClass = new ReflectionClass($newClassName);
        // When requiring $file, all included/required classes inside the class
        // are also loaded. We only want to process the classes that are
        // actually defined inside the current file, not the dependencies
        if ($newClass->getFileName() !== realpath($file)) {
            continue;
        }

        if ($newClass->isAbstract()) {
            echo "Class $newClassName is an abstract class. Skipping.\n";
            continue;
        }

        echo "Instantiating new instance of class $newClassName...\n";
        $obj = new $newClassName(new Module("", ""), "", "", "", "");
        if (!is_subclass_of($obj, 'NDB_BVL_Instrument')) {
            echo "Class $newClassName is not a descendant of class NDB_BVL_Instrument...Skipping.\n";
            continue;
        }
        echo "Initializing instrument object...\n";
        $obj->setup(null, null);

        // Some instruments ought not to be parsed with the lorisform_parser
        if ((in_array($obj->testName, $instrumentsToSkip))) {
            echo "lorisform_parser will skip file {$file}\n";
            continue;
        }

        $subtests = $obj->getSubtestList();
        foreach ($subtests as $subtest) {
            $obj->page = $subtest['Name'];
            echo "Building instrument page '$subtest[Name]'...\n";
            $obj->_setupForm();
        }

        if (is_array($obj->getFullName())) {
            echo "Could not find row for $matches[1] in table test_names,
            please populate test_names, instrument_subtests\n";
            continue;
        }

        $output .= !empty($output) ? "{-@-}" : '';

        echo "Processing instrument $newClassName...\n";

        $output .="table{@}".$obj->table."\n";

        $output .="title{@}".$obj->getFullName()."\n";

        $formElements = $obj->form->toElementArray();
        $output      .=parseElements($formElements["elements"]);
        echo "Finished processing instrument  $newClassName\n---------------------------------------------------\n\n";
    }
}
if (empty($output)) {
    echo "Nothing to output, 'ip_output.txt' not created\n";
} else {
    $fp =fopen("ip_output.txt", "w");
    fwrite($fp, $output);
    fclose($fp);
}

/**
 * Create a linst formated string for an LorisForm element.
 *
 * @param LorisFormElement $elements   The element to parse.
 * @param String           $groupLabel The group label
 *
 * @return string LINST formated element.
 */
function parseElements($elements, $groupLabel="")
{
    global $obj;
    $output = '';
    foreach ($elements AS $element) {
        if ($element['label'] != "" ) {
            $label = str_replace("&nbsp;", "", $element['label']);
            $label = trim(preg_replace('/\s+/', ' ', $label));
        } else {
            $label = trim(preg_replace('/\s+/', ' ', $groupLabel));
        }

        switch ($element['type']) {
        case "select":
            $output .="select";
            if (array_key_exists('multiple', $element)) {
                $output .="multiple";
            }
            $output       .="{@}".$element['name']."{@}".$label."{@}";
            $optionsOutput ="";
            foreach ($element['options'] AS $key => $option) {
                if (!empty($optionsOutput)) {
                    $optionsOutput .="{-}";
                }
                if (is_null($option) || $option==='') {
                    $optionsOutput .="NULL";
                } else {
                    $optionsOutput .="'".$key."'";
                }
                $optionsOutput .="=>'".addslashes($option)."'";
            }
            $output .=$optionsOutput."\n";
            break;

        case "text":
            $output .="text{@}".$element['name']."{@}".$label."\n";
            break;

        case "textarea":
            $output .="textarea{@}".$element['name']."{@}".$label."\n";
            break;

        case "date":
            $options = "{@}";
            if (array_key_exists('options', $element)
                && isset($el['options']['minYear'])
                && isset($el['options']['maxYear'])
            ) {
                $options = $element['options']['minYear']
                    ."{@}"
                    .$element['options']['maxYear'];
            }
            $output .="date{@}".$element['name']."{@}".$label."{@}".$options."\n";
            break;

        case "group":
            $output .=parseElements($element['elements'], $label);
            break;

        case "header":
            $name = '';
            if (array_key_exists('name', $element)) {
                $name = $element['name'];
            }
            $output .="header{@}".$name."{@}".$element['label']."\n";
            break;

        case "static":
            //see how static element is used...
            if (!array_key_exists('name', $element)) {
                $output .="header{@}{@}".$label."\n";
            } elseif (($element['name'] == null)
                || array_key_exists($element['name'], $obj->localDefaults)
                || $element['name'] =='lorisSubHeader'
            ) {
                //element is plain form text, or a header.
                $output .="header{@}".$element['name']."{@}".$label."\n";
            } else {
                //element reports a database score
                $output .="static{@}".$element['name']."{@}".$label."\n";
            }

            break;

        case "advcheckbox":
            $output .="checkbox{@}".$element['name']."{@}".$label."\n";
            break;

        case "html_quickform_radio":
            $mainquestion = addslashes($element->_label);
            $optionfield  = addslashes($element->_text);
            if ($element->_attributes['position'] == "first") {
                $output .= "radio{@}";
                $output .= $element->_attributes['name'] . "{@}";
                $output .= $mainquestion . "{@}";
            }
            $output .= "'" . $element->_attributes['value']
                   . "'=>'" . $optionfield . "'";
            if ($element->_attributes['position'] == "last") {
                $output .="\n";
            } else {
                $output .="{-}";
            }
            break;
        case "time":
            $output .="time{@}".$element['name']."{@}".$label."\n";
            break;
        case "html":
        case "file":
        case "hidden":
                // skip because it's useless
                echo "SKIP: skipping quickform element type: ".$element['type']."\n";
            break;

        default:
            echo "WARNING:  Unknown form element type: ".$element['type']."\n";
            break;
        }
    }
    return $output;
}

/**
 * Get the excluded instruments from the config file
 *
 * @return Array   List of instruments to be skipped
 */
function getExcludedInstruments()
{

    // Get the abbreviated instruments
    $config =& NDB_Config::singleton();
    $excluded_instruments = $config->getSetting('excluded_instruments');

    $ex_instruments =array();
    foreach ($excluded_instruments as $instruments) {
        foreach (Utility::asArray($instruments) as $instrument) {
            $ex_instruments[$instrument] = $instrument;
        }

    }
    return $ex_instruments;
}

?>

