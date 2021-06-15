# Survey Accounts

This module is used to create and manage survey forms that are sent to participants in a study.

## View Surveys

Each survey form is generated with a unique URL. This survey link URL can be emailed directly to respondents for survey completion from home, or can be used in the clinic to capture data directly from participants, i.e. on a tablet in the waiting room during a study visit. 

Use the *Selection Filter* section to search for existing surveys.

The resulting table will display your results, which includes a unique URL for each survey generated. Click on this link to access the online survey form.

The *Status* column tells you whether the survey has been accessed. This column will display one of the following options:

**Created**: Survey was created. This is the default status once a survey is created using the "Add Survey" page.<br>
**Sent**: Survey was created, and an email with the unique survey URL was sent to the survey respondent. This is the default status once a survey is created and sent by email within LORIS.<br>
**In Progress**: Survey was opened and accessed by anyone with the link, including study personnel (not just the intended respondent).<br>
**Complete**: Survey was completed and submitted. After this stage, the respondent will not be able to go back and change any entries. No data will be visible via the URL once a survey is completed: clicking on the URL will display a page with the message *"Data has already been submitted"*

## Create Surveys

You can create a new survey manually with data that hasn’t yet been entered into LORIS. Click **Add Survey**, which takes you to a new page. Populate the fields and click **Create Survey** to generate a URL, which you can send to the candidate, or **Email Survey** to send the URL to the candidate. If you choose Email Survey, you’ll be able to customize the content of the email in a pop-up window (which will contain an editable generic message).

## Overridden Reasons

Jordan's NEW Survey Module(the new GUI) is not yet in Loris; so we have to redirect the survey to the new link(air pollution should be in old GUI)
(Ref: jsx/columnFormatter.js :lines 22-31)

Link to Parent Portal: A column named Parent_Portal is added to redirect to the Parent Portal (Ref php/survey_accounts.class.inc:lines 56-30 & line 69)

Surveys which is not created under VSA or without email id will have 'NA' under Parent portal column (Ref: jsx/columnFormatter.js :lines 32-41)

Email Column should be hidden from Survey accounts column as it may contain PII(but searchable) (Ref:jsx/columnFormatter.js :line 11)

Instrument dropdown has list of instruments which has no particular order which is very difficult; so made the list to appear in alphabetic order
(Ref: php/survey_accounts.class.inc :lines 91 -104 & line 129)

SurveyName column is updated to show the full name intead of the database abbreviation
