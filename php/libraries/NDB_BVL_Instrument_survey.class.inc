<?php

class NDB_BVL_Instrument_survey extends \NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    /**
     * Wrapper to create an Hour/Minute field, with an accompanying status field.
     *
     * @param string $field        Name given to the HTML QuickForm Element
     *                             being created
     * @param string $label        The question text to display
     * @param array  $rules        Additional rules to apply to the element
     *                             being added,{@} delimited
     * @param string $rule_message Message to display upon rule violation.
     *
     * @return none
     */
    function addHourMinElement(
        $field,
        $label,
        $rules = array(),
        $rule_message = null,
        $with_status_field = false  //toggles an optional NA dropdown for HourMin element
    ): void
    {
        if ($rule_message === null) {
            if ($with_status_field === true) {
                $rule_message = "You are required to select a status if you want to leave this time blank.";
            } elseif ($with_status_field === false) {
                $rule_message = "Required.";
            }
        }

        $group[] =& $this->form->createElement(
            "time",
            $field,
            null,
            null,
            null
        );

        if ($with_status_field) {     //if passing parameter as true, then add NA dropdown
            $group[] =& $this->createSelect(
                $field . "_status",
                "",
                array(
                 null           => '',
                 'not_answered' => 'Not Answered',
                )
            );
            $this->XINRegisterRule(
                $field,
                array_merge($rules, array($field."_status{@}=={@}")),
                $rule_message,
                $field.'_group'
            );
        } else {                       //otherwise only need to validate time field
            $this->XINRegisterRule(
                $field,
                array_merge($rules, array($field."{@}=={@}")),
                $rule_message,
                $field.'_group'
            );
        }

        $this->addGroup($group, $field . "_group", $label, null, false);
        unset($group);
    }

    /**
     * Tells if this is a survey instrument or not. Survey instruments should
     * extend this class to apply this change.
     *
     * @return bool true if this is a survey instrument, false otherwise.
     */
    function isSurvey() : bool
    {
        return true;
    }
    public function getDataDictionary() : iterable
    {
        return [];
    }    
}
?>
