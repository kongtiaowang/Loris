<?php
/**
 * This file contains the NDB_BVL_Instrument_TADULT_SELF_REPORT
 * class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/
 */
/**
 * Creates the form elements for the ADULT_SELF_REPORT instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv_
 * @link     https://www.github.com/aces/
 */
class NDB_BVL_Instrument_CCC2 extends NDB_BVL_Instrument
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
        $this->formType = 'XIN';
        $this->form = new LorisForm('CCC2_form');
        $this->page = $page;
        // set the object properties
        $this->testName = 'CCC2'; // test_names.Test_name
        $this->table = 'CCC2'; // name of database
        // table corresponding to instrument
        $this->commentID = $commentID; // data keyed by commentID
        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array("Date_taken");
        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
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

    /**
     * Method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        //determine page to display
        if (preg_match(
            "/CCC2(_page[0-9]+)/",
            $this->page,
            $matches
        )) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    /**
     * Generates the main page of the form.
     *
     * @return void
     * @access private
     */
    function _main()
    {
        // display test name
        $this->addHeader("Children's Communication Checklist 2- Caregiver Respose Form");
        $this->_addMetadataFields();
        //$this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
        // Header
        $this->addHeader("Information About The Child");
        $this->addTextElement("child_name", "Child's Name ");
        $opts = array(
            null => "",
            "male" => "Male",
            "female" => "Female",
        );
        $opts1 = array(
            null => "",
            "yes" => "Yes",
            "no" => "No",
        );
        $opts2 = array(
            null => "",
            "parent" => "Parent",
            "caregiver" => "Caregiver",
            "teacher" => "Teacher",
            "other" => "Other"
        );
        $this->addSelect("child_gender", "Child's Gender: ", $opts);
        $this->addDateElement("user_birthdate", "Child's Birthdate:");
        $this->addSelect("hear_loss", "Does the child have a permanent hear loss? ", $opts1);
        $this->addTextAreaElement("hear_loss_yes", "If Yes, give further details ");
        $this->XINRegisterRule(
            "hear_loss_yes",
            array("hear_loss{@}=={@}yes"),
            "Required",
            "hear_loss_yes_group"
        );
        $this->addSelect("lang_eng", "Does the child speak English as his or her primary language? ", $opts1);
        $this->addTextAreaElement("lang_eng_no", "If No, give further details ");
        $this->XINRegisterRule(
            "lang_eng_no",
            array("lang_eng{@}=={@}no"),
            "Required",
            "lang_eng_no_group"
        );
        $this->addSelect("word_to_sent", "Is the child able to put words together in a sentence? ", $opts1);
        $this->addTextAreaElement("word_to_sent_no", "If No, give further details ");
        $this->XINRegisterRule(
            "word_to_sent_no",
            array("word_to_sent{@}=={@}no"),
            "Required",
            "word_to_sent_no_group"
        );
        $this->addHeader("Information About The Person Completing The Caregiver Response Form");
        $this->addTextElement("responder_name", "Name: ");
        $this->addTextAreaElement("responder_address", "Address: ");
        $this->addSelect("responder_realtionship", "Relationship to child:", $opts2);
        $this->addTextElement("responder_relationship_other", "Other: ");
        $this->XINRegisterRule(
            "responder_relationship_other",
            array("responder_realtionship{@}=={@}other"),
            "Required",
            "responder_relationship_other_group"
        );
        $this->addTextElement("responder_know_period", "How long have you known this child?: ");
        $this->addTextAreaElement("comments", "Comments: ");
    }

    /**
     * Page 1
     *
     * @return void
     */
    function _page1()
    {
        $this->addLabel("<h1>Directions of Statements</h1>");
        $this->form->addElement('static', 'lorisSubHeader', "<strong>Instructions:</strong>
<br>The Children's Communication Checklist was developed to gain a better understanding
<br>of children's communication strengths and difficulties in everyday settings.
<br>Statements 1-50 refer to difficulties children may have that affect their ability to communicate.
<br>Statements 51-71 refer to strengths the child may have when communicating with others.. 
<br>Please use the rating key provided to indicate how often you have observed the behavior and write 
<br>the number in the Rating column to the left of the statements<br>
        RATING KEY<br>
       0 = less than once a week (or never)<br>
1= at least once a week, but not everyday (or occasionally)<br>
2 = once or twice a day (or frequently)<br>
3 = several times (more than twice) a day (or always)<br><br>");
        $opts = array(null => " ",
            "0.less than once a week (or never)" => "0.less than once a week (or never)",
            "1.at least once a week, but not everyday (or occasionally)" => "1.at least once a week, but not everyday (or occasionally)",
            "2.once or twice a day (or frequently)" => "2.once or twice a day (or frequently)",
            "3.several times (more than twice) a day (or always)" => "3.several times (more than twice) a day (or always)");


        $questions = [
            "1. Gets mixed up between he and she (e.g., says 'he' when talking about a girl or 'she' when talking about a boy)",
            "2. Simplifies words by leaving out some sounds (e.g., pronounces 'crocodile' as 'cockodile,' or 'stranger' as 'staynger')",
            "3. Appears anxious in the company of other children",
            "4. Makes false starts, and seems to search for the right words (e.g., says 'can I—can I—can I—can I—can I have an—have ice cream')",
            "5. Talks repetitively about things that no one is interested in",
            "6. Forgets words he or she knows (e.g., instead of 'rhinoceros' may say 'you know, the animal with the horn on its nose...')",
            "7. With familiar adults, seems inattentive, distant, or preoccupied",
            "8. Looks blank in a situation where most children would show a clear facial expression (e.g., when angry, fearful, or happy)",
            "9. When given the opportunity to do what he or she likes, chooses the same favorite activity (e.g., playing a specific computer game)",
            "10. Uses terms like he or it without making it clear what he or she is talking about (e.g., when talking about a movie, says 'he was really great' without explaining who 'he' is)",
            "11. Says things he or she does not seem to fully understand or seems to be repeating something he or she heard an adult say (e.g., a 5-year-old describing a teacher by saying, 'she's got a very good reputation')",
            "12. Mixes up words of similar meaning (e.g., says 'dog' for 'fox,' or 'screwdriver' for 'hammer')",
            "13. Is babied, teased, or bullied by other children')",
            "14. Does not look at the person he or she is talking to",
            "15. Misses the point of jokes and puns (though may be amused by nonverbal humor such as slapstick)",
            "16. Is left out of joint activities by other children",
            "17. Gets mixed up between he/him or she/her (e.g., says 'him is working' rather than 'he is working,' or 'her has a cake' rather than 'she has a cake')",
            "18. Uses favorite phrases, sentences, or longer sequences in inappropriate contexts (e.g., says 'all of a sudden' instead of 'then,'as in 'We went to the park and all of a sudden we had a picnic;' or routinely starts utterances with 'by the way')",
            "19. Gets confused when a word is used differently from its usual meaning (e.g., does not understand when an unfriendly person is described as 'cold' and assumes the person is shivering)",
            "20. Stands too close to other people when talking to them"
        ];
        for ($i = 0; $i < count($questions); $i++) {
            $n = $i + 1;
            $this->addSelect("CCC2_response_{$n}", "{$questions[$i]}", $opts);


        }
    }

    function _page2()
    {

        $this->addLabel("<h1>Directions of Statements</h1><h3>(continued)</h3>");
        $opts = array(null => " ",
            "0.less than once a week (or never)" => "0.less than once a week (or never)",
            "1.at least once a week, but not everyday (or occasionally)" => "1.at least once a week, but not everyday (or occasionally)",
            "2.once or twice a day (or frequently)" => "2.once or twice a day (or frequently)",
            "3.several times (more than twice) a day (or always)" => "3.several times (more than twice) a day (or always)");


        $questions = [
            "21. Talks to people without any encouragement or starts conversations with strangers",
            "22. Talks about lists of things he or she has memorized (e.g., the names of state capitals or the names of dinosaurs)",
            "23. Pronounces words in an over-precise manner (e.g., as if child is mimicking a TV personality rather than talking like those around him or her)",
            "24. Pronounces words in a babyish way (e.g., 'chimbley' for 'chimney' or 'bokkle' for 'bottle')",
            "25. It is difficult to tell if he or she is talking about something real or make-believe",
            "26. Moves the conversation to a favorite topic, even if others do not seem interested in it",
            "27. Utterances sound babyish because they are just two or three words long (e.g., 'me got ball' instead of 'I've got a ball' or 'give doll' instead of 'give me the doll')",
            "28. Ability to communicate varies from situation to situation (e.g., talks easily one-to-one with a familiar adult, but has difficultyexpressing himself or herself in a group of children)",
            "29. Leaves off beginnings or endings of words (e.g., says 'roe' instead of 'road' or 'nana' instead of 'banana')",
            "30. Repeats what others have just said (e.g., if asked 'What did you eat?' says, 'What did you eat?')",
            "31. Ignores conversational overtures from others (e.g., if asked, 'What are you making?' does not look up and just continues working)",
            "32. Mixes up words that sound similar (e.g., says 'telephone' for 'television' or 'magician' for 'musician')",
            "33. Hurts or upsets other children without meaning to",
            "34. Takes in just one to two words in a sentence, and so misinterprets what has been said (e.g., if someone says, 'I want to go skating next week,' the child may think that person has been skating or wants to go now)",
            "35. It is difficult to stop him or her from talking",
            "36. Leaves off past tense —ed endings on words (e.g., says 'John kick the ball' instead of 'John kicked the ball,' or 'Sally play over
there' instead of 'Sally played over there')",
            "37. Tells people things they know already",
            "38. Makes mistakes in pronouncing long words (e.g., says 'vegebable' instead of 'vegetable' or 'trellistope' instead of 'telescope')",
            "39. Does not recognize when other people are upset or angry",
            "40. Confuses the sequence of events when trying to tell a story or describe a recent event (e.g., if describing a movie, might talk about
the ending before the beginning)"

        ];
        for ($i = 0; $i < count($questions); $i++) {
            $n = $i + 21;
            $this->addSelect("CCC2_response_{$n}", "{$questions[$i]}", $opts);

        }


    }

    function _page3()
    {
        $this->addLabel("<h1>Directions of Statements</h1><h3>(continued)</h3>");
        $opts = array(null => " ",
            "0.less than once a week (or never)" => "0.less than once a week (or never)",
            "1.at least once a week, but not everyday (or occasionally)" => "1.at least once a week, but not everyday (or occasionally)",
            "2.once or twice a day (or frequently)" => "2.once or twice a day (or frequently)",
            "3.several times (more than twice) a day (or always)" => "3.several times (more than twice) a day (or always)");


        $questions = [
            "41. Is too literal (e.g., if asked 'Is it hard to get up in the morning?' replies, 'No, you just put one leg out of the bed and then the other
and stand up;' or if told 'watch your hands' when using scissors, proceeds to stare at his or her fingers)",
            "42. Provides over-precise information in his or her talk (e.g., if asked 'When did you go on vacation?' may say 'July 13, 2005' instead
of 'in the summer')",
            "43. Leaves out 'is' (e.g., says 'Daddy going to work' instead of 'Daddy is going to work' or 'Daddy's going to work,' or says 'the boy
big' instead of 'the boy is big')",
            "44. Mispronounces th for s or w for r (e.g., 'thoap' instead of 'soap' or 'wabbit' instead of 'rabbit')",
            "45. Asks a question, even though he or she has been given the answer",
            "46. Is vague in choice of words, making it unclear what he or she is talking about (e.g., says 'that thing' rather than 'pan')",
            "47. Shows interest in things or activities that most people would find unusual (e.g., traffic lights, washing machines, weather)",
            "48. Does not explain what he or she is talking about to someone who does not share his or her experiences (e.g., talks about 'Johnny'
without explaining who Johnny is)",
            "49. Surprises people by his or her knowledge of unusual words (e.g., uses terms you expect to hear from an adult rather than a child)",
            "50	It is hard to make sense of what he or she is saying, even though the words are clearly spoken",
            "51	Speaks clearly so that the words can easily be understood by someone who does not know him or her well",
            "52	Reacts positively when a new and unfamiliar activity is suggested",
            "53	Talks clearly about what he or she plans to do in the future (e.g., what he or she will do tomorrow or plans for
going on vacation)",
            "54	Appreciates the humor expressed by irony (e.g., would be amused rather than confused if someone said 'Isn't it
a nice day?' when it is pouring rain)",
            "55	Produces long and complicated sentences (e.g., 'When I went to the park I went on the swing,' or 'I saw this man
standing on the corner.')",
            "56	Makes good use of gestures to get his or her meaning across",
            "57	Shows concern when other people are upset",
            "58	Speaks fluently and clearly, producing all speech sounds accurately and without any hesitation",
            "59	Keeps quiet in situations when someone else is trying to talk or concentrate (e.g., when someone else is watching TV
or during formal occasions, such as a school assembly or a religious ceremony)",
            "60	Realizes the need to be polite (e.g., would act pleased if given a present he or she did not really like; would avoid making
personal comments about strangers)"

        ];
        for ($i = 0; $i < count($questions); $i++) {
            $n = $i + 41;
            $this->addSelect("CCC2_response_{$n}", "{$questions[$i]}", $opts);

        }


    }

    function _page4()
    {
        $this->addLabel("<h1>Directions of Statements</h1><h3>(continued)</h3>");
        $opts = array(null => " ",
            "0.less than once a week (or never)" => "0.less than once a week (or never)",
            "1.at least once a week, but not everyday (or occasionally)" => "1.at least once a week, but not everyday (or occasionally)",
            "2.once or twice a day (or frequently)" => "2.once or twice a day (or frequently)",
            "3.several times (more than twice) a day (or always)" => "3.several times (more than twice) a day (or always)");


        $questions = [
            "61. When answering a question, provides enough information without being over-precise",
            "62. You can have an enjoyable, interesting conversation with him or her",
            "63. Shows flexibility in adapting to unexpected situations (e.g., does not get upset if he or she planned to play on the computer
but has to do something else because it is not working)",
            "64. Uses abstract words that refer to general concepts rather than something you can see (e.g., knowledge, politics, courage)",
            "65. Smiles appropriately when talking to people",
            "66. Uses words that refer to whole classes of objects, rather than a specific item (e.g., refers to a table, chair, and drawers
as 'furniture' or to apples, bananas, and pears as 'fruit')",
            "67. Talks about his or her friends; shows interest in what they do and say",
            "68. Explains a past event clearly (e.g., what he or she did at school or what happened at a football game)",
            "69. Produces sentences containing 'because' (e.g., 'John got a cake because it was his birthday')",
            "70. Talks to others about their interests"

        ];
        for ($i = 0; $i < count($questions); $i++) {
            $n = $i + 61;
            $this->addSelect("CCC2_response_{$n}", "{$questions[$i]}", $opts);
        }
    }
}