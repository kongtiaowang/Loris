# Survey Accounts

## Purpose

The survey accounts module is intended to manage the surveys which
are sent to participants in a study. It is used to generate a survey
key, and (optionally) automatically send it to the participant, if
their email address is provided.

## Intended Users

The survey accounts module is primarily used by study coordinators
in order to generate a survey key to send to participants.

## Scope

The survey accounts module only generates new survey keys. It does
*not* collect the data for the surveys, which are written as LORIS
instruments and collected via a different survey.php script in the
LORIS `htdocs` directory.

## Permissions

Accessing the survey accounts module requires the `user_accounts`
LORIS permission.

## Configurations

Each survey must be created as a LORIS instrument, and the
"IsDirectEntry" column in the `test_names` table in MySQL must be
set to "true" in order for the survey to show the instrument in the
dropdown for the list of available surveys in the `add_survey` page.


## Interactions with LORIS

The module validates that surveys have not already been sent to a
participant by comparing the test_name against the LORIS `flag`
table. As a result, surveys should not be inserted into the LORIS
`test_battery` table or attempting to send a survey will result in
an error.

The `add_survey` page generates a link to `$LORIS/survey.php?key=....`
in the email that it sends after generating a new survey key.

## Overridden Reasons

Jordan's NEW Survey Module(the new GUI) is not yet in Loris; so we have to redirect the survey to the new link(air pollution should be in old GUI)
(Ref: jsx/columnFormatter.js :lines 22-31)

Link to Parent Portal: A column named Parent_Portal is added to redirect to the Parent Portal (Ref php/survey_accounts.class.inc:lines 56-30 & line 69)

Surveys which is not created under VSA or without email id will have 'NA' under Parent portal column (Ref: jsx/columnFormatter.js :lines 32-41)

Email Column should be hidden from Survey accounts column as it may contain PII(but searchable) (Ref:jsx/columnFormatter.js :line 11)

Instrument dropdown has list of instruments which has no particular order which is very difficult; so made the list to appear in alphabetic order 
(Ref: php/survey_accounts.class.inc :lines 91 -104 & line 129)

SurveyName column is updated to show the full name intead of the database abbreviation

