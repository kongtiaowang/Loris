<?php
/**
 * LorisForm with specific overrides for IBIS.
 * 
 * PHP Version 7
 *
 * @category Main
 * @package  Main
 * @author   Nicolas Brossard 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */

/**
 * Reimplementation of QuickForm API from scratch
 *
 * @category Main
 * @package  Main
 * @author   Dave MacFarlane <david.macfarlane2@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */

class LorisFormIBIS extends LorisForm
{
	/**
     * Iterates through an array of elements and populates the array
     * passed as a reference with the values that come from the POST
     * request.
     *
     * This may recursively call itself to also get the values out of
     * groups, or be called directly by getSubmitValues() with the
     * whole form as the "group".
     *
     * @param array $submitKeys The elements that need to have their
     *                             values extracted.
     * @param array $arr        A reference to an array to store the
     *                             extracted values into.
     *
     * @return none, but will modify &$arr parameter passed as a side-effect
     */
    function getGroupValues($submitKeys, &$arr)
    {
        foreach ($submitKeys as $key) {
            if (!isset($this->form[$key])) {
                $tp = $this->groupMapping[$key] ?? null;
                $el = is_null($tp) ?
                    null :
                    $this->form[$tp['groupName']]['elements'][$tp['index']];
                if (!$el) {
                    $arr[$key] = $_REQUEST[$key];
                    continue;
                }
            } else {
                $el = $this->form[$key];
            }
            // If it's a group, recursively go through the elements
            // of that group.
            if ($el['type'] === 'group') {
                $this->getGroupValues(array_keys($el['elements']), $arr);
                continue;
            }

            // If it was an element of the form $elemname[idx],
            // which PHP converts to an array of $elemname, then
            // we need to check for $elemname, not $elemname[idx]
            $name       = $el['name'];
            $bracketIdx = strpos($name, '[');
            if ($bracketIdx !== false) {
                $fieldName = substr($name, 0, $bracketIdx);
                $fieldIdx  = substr($name, $bracketIdx+1);
                $fieldIdx  = strstr($fieldIdx, ']', true);
                if (!isset($arr[$fieldName])) {
                    $arr[$fieldName] = $this->getValue($fieldName);
                }
                continue;
            }
            
            if($el['type'] === 'radio') {
				$arr[$name] = $this->getValue($name);
				continue;
			}

            if ($el['type'] === 'file') {
                $file       = $this->getElement($name);
                $arr[$name] = $file->getValue();
                continue;
            }

            if ($el['type'] === 'time') {
                $value = $this->getValue($name);
                if (($value['H'] || $value['H'] === '0')
                    && ($value['i'] || $value['i'] === '0')
                ) {
                    $arr[$name] = sprintf("%s:%s:00", $value['H'], $value['i']);
                } else {
                    $arr[$name] = null;
                }
                continue;
            }

            if ($el['type'] === 'date' && array_key_exists('options', $el)) {
                $value = $this->getValue($name);
                $date  = $value;

                if (!$value) {
                    $arr[$name] = '';
                    continue;
                }

                // Convert year to a valid SQL format (i.e yyyy-mm-dd)
                if (strtolower($el['options']['format']) === 'y') {
                    $date = sprintf("%s-01-01", $value);
                }
                // Convert month-year to a valid SQL format (i.e yyyy-mm-dd)
                if ((strtolower($el['options']['format']) === 'my')
                    || (strtolower($el['options']['format']) === 'ym')
                ) {
                    $date = sprintf("%s-01", $value);
                }

                $arr[$name] = $date;

                continue;
            }

            // Check to see it the element type is a header or is a static
            // element without a request variable. If so do not add to the
            // reference array
            if (!($el['type'] === 'header'
                || ($el['type'] === 'static' && empty($_REQUEST[$name])))
            ) {
                  $arr[$name] = $this->getValue($name);
            }
        }
    }
}

?>
