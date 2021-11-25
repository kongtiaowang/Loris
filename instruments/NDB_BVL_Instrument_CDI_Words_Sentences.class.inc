<?php
/*
 * This file contains the NDB_BVL_Instrument_CDI_Words_Sentences
 * class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/CCNA/
 */

/**
 * Creates the form elements for the CDI_Words_Sentences instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/CCNA/
 */

class NDB_BVL_Instrument_CDI_Words_Sentences extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    /*
   INSERT INTO instrument_subtests VALUES('', 'CDI_Words_Sentences', 'CDI_Words_Sentences_page1', 'PART I - A. VOCABULARY CHECKLIST 1-4', 1);
   INSERT INTO instrument_subtests VALUES('', 'CDI_Words_Sentences', 'CDI_Words_Sentences_page2', 'PART I - A. VOCABULARY CHECKLIST 5-7', 2);
   INSERT INTO instrument_subtests VALUES('', 'CDI_Words_Sentences', 'CDI_Words_Sentences_page3', 'PART I - A. VOCABULARY CHECKLIST 8-10', 3);
   INSERT INTO instrument_subtests VALUES('', 'CDI_Words_Sentences', 'CDI_Words_Sentences_page4', 'PART I - A. VOCABULARY CHECKLIST 11-14', 4);
   INSERT INTO instrument_subtests VALUES('', 'CDI_Words_Sentences', 'CDI_Words_Sentences_page5', 'PART I - A. VOCABULARY CHECKLIST 15-19', 5);
   INSERT INTO instrument_subtests VALUES('', 'CDI_Words_Sentences', 'CDI_Words_Sentences_page6', 'PART I - A. VOCABULARY CHECKLIST 20-22', 6);
   INSERT INTO instrument_subtests VALUES('', 'CDI_Words_Sentences', 'CDI_Words_Sentences_page7', 'PART I - B. HOW CHILDREN USE WORDS', 7);
   INSERT INTO instrument_subtests VALUES('', 'CDI_Words_Sentences', 'CDI_Words_Sentences_page8', 'PART II - A-C', 8);
   INSERT INTO test_battery VALUES ('', 'macarthur_words_gestures', '1050', '1140', 'Y', 'Visit', '2');
   */

    var $ValidityEnabled = false;
    var $ValidityRequired = false;
    var $scoreLabels = array(
        "part_2_e_first_choice_count",
        "part_2_e_second_choice_count",
        "word_endings_plural_percentage",
        "word_endings_possessive_percentage",
        "word_endings_past_percentage",
        "word_endings_progressive_percentage",
        "how_use_absent_comp_percentage",
        "how_use_absent_owner_percentage",
        "how_use_absent_production_percentage",
        "how_use_future_percentage",
        "how_use_past_percentage",
        "words_produced_percentile",
        "word_forms_percentile",
        "grammatical_complexity_percentile",
        "part1_wpNum",
        "part_2_b_nouns",
        "part_2_b_verbs"

    );
    
    private const NoYesCheckbox   = [
                                     '0',
                                     '1',
                                    ];

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     *
     * @return void
     * @access public
     */

    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {

        $this->formType = "XIN";
        $this->form = new LorisForm('CDI_Words_Sentences_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = 'CDI_Words_Sentences';           // test_names.Test_name
        $this->table = 'CDI_Words_Sentences';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;


        // required fields for data entry completion status
        $this->_requiredElements = array(
            'Examiner',
            'CommentID',
        );

        // setup the form
        $this->_setupForm();

    }


    /**
     * Answers to often asked questions
     *
     *
     */

    var $frequency =
        array(
            null => "",
            "not_yet" => "Not Yet",
            "sometimes" => "Sometimes",
            "often" => "Often"
        );

    /*
     Calculates the percentile for a specific subscale of the CDI: Words & Sentences instrument
     *
     * @param string $scale the scale to reference
     * @param int $age_months the participant's age in months
     * @param string $gender the participant's gender
     * @param string $scores the participant's total score
     *
     * @return void
     * @access public
     */

    function CalculatePercentile($scale, $age_months, $gender, &$scores)
    {
        $db = Database::singleton();
        if($scale=='words_produced')
        { $scale_number = $scale . "_number";
        }
        else {
            $scale_number = $scale;
        }
        $scale_percentile = $scale . "_percentile";

        $query_scores = "SELECT * FROM CDI_WS_percentiles_lookup WHERE age_months=" . $age_months . " AND sex='$gender' AND score_raw=" . $scores[$scale_number] . " AND subscale='$scale_number'";
        $PercentileScore = $db->pselectRow($query_scores, array());


        $scores[$scale_percentile] = $PercentileScore['score_percentile'];

        if ($PercentileScore == NULL) {
            $score_holder = $scores[$scale_number];
            $query_scores1a = "SELECT * FROM CDI_WS_percentiles_lookup WHERE age_months=$age_months AND sex='$gender' AND subscale='$scale_number' AND score_raw>$score_holder ORDER BY score_raw ASC";
            $record_1a = $db->pselectRow($query_scores1a, array());
            if (empty($record_1a)) {

                $db->pselectRow("SELECT * from CDI_WS_percentiles_lookup WHERE age_months=$age_months AND sex='$gender' AND subscale='$scale_number' ORDER BY score_raw ASC", array());
            }

            $query_scores1b = "SELECT * FROM CDI_WS_percentiles_lookup WHERE age_months=" . $age_months . " AND sex='$gender' AND subscale='$scale_number' AND score_raw<$score_holder ORDER BY score_raw DESC";
            $record_1b = $db->pselectRow($query_scores1b, array());

            //print "scale: $scale_number score: " . $scores[$scale_number] . " x< " . $record_1b['score_raw'] . " x> " . $record_1a['score_raw'] . " Y> " . $record_1b['score_percentile'] . " Y< " . $record_1b['score_percentile'] . '<br />';
            if ($record_1a['score_raw'] != $record_1b['score_raw']){
                 $percentile_calculation1 = (
                    ($scores[$scale_number] - $record_1b['score_raw']) / 
                    ($record_1a['score_raw'] - $record_1b['score_raw'])
                ) * ($record_1a['score_percentile'] - $record_1b['score_percentile']) + $record_1b['score_percentile'];

            $scores[$scale_percentile] = round($percentile_calculation1);
            } else {
                $scores[$scale_percentile] = 0;
            }

        }
        if ($scores[$scale_percentile] > 99) {
            $scores[$scale_percentile] = 99;
        }
    }

    function ReturnPercentage($scale, $age_months, $gender,&$scores) {
        $db = Database::singleton();
        $scale_number = $scale . "_number";
        $scale_percentage = $scale . "_percentage";

        $query_scores = "SELECT * FROM CDI_WS_percent_affirmative_lookup WHERE age_months=" . $age_months . " AND sex='$gender' AND subscale='$scale_number'";
        $PercentageScore  = $db->pselectRow($query_scores, array());
        $scores[$scale_percentage] = $PercentageScore['percentage_affirmative'];

    }

    /*
    * Returns the total number of words
    *
    *
    *
    */
    function SumWords($questions, &$record, $question_prefix, &$affirmative) {
        $affirmative = 0;
        for($qNum = 1; $qNum <= $questions; $qNum++) {
            if($record[$question_prefix . $qNum] == '1') {
                $affirmative++;
            }

        }
    }

    /*
     * Return # of Yes/No answers for Questions
     * with Not Yet/Sometimes/Often answer choices
     */

    function SumYesNo($questions, &$record, $question_prefix, &$yes_count, &$no_count) {
        $yes_count = 0;
        $no_count = 0;
        for ($qNum = 1; $qNum <= $questions; $qNum++) {
            if($record[$question_prefix . $qNum] == "not_yet") {
                $no_count++;
            } else {
                $yes_count++;
            }
        }
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
            "/CDI_Words_Sentences(_page[0-9]+)/",
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
     * generates the main page of the form.
     *
     * @return void
     * @access private
     */
    function _main()
    {
        // display test name
        $this->addHeader("MacArthur-Bates CDI: Words and Sentences");
        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
      /*  $this->addLabel("<h3><b>PART I: WORDS CHILDREN USE</b></h3>");
        $this->addLabel("<h4><b>Vocabulary Checklist</b></h4>");
        $group[] =& $this->form->createElement("static", null, null,
                                               "Words Produced");
        $group[] =& $this->form->createElement("static", null, null,
                                               "Number: (of 680)");
        $group[] =& $this->form->createElement("static", null, null, "Percentile");
        $this->form->addGroup(
            $group,
            "part_1_vocab_checklist_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group); */


        $scores['part1_wpNum'] = 0;
        $scores['part_2_b_nouns'] = 0;
        $scores['part_2_b_verbs'] = 0;

        $score_columns
            = array(
            "words_produced_number" => "Vocab Checklist: Words Produced (Total)",
            "words_produced_percentile" => "Words Produced Percentile",
            "word_forms"     => "Word Forms Count",
            "word_forms_percentile"     => "Word Forms Percentile",
            "grammatical_complexity"     => "Grammatical Complexity",
            "grammatical_complexity_percentile"    => "Grammatical Complexity Percentile",
            "word_endings_part2" => "Word Endings/Part2",
            "how_use_past_percentage" => "How Children Use Words: Past (Percentage)",
            "how_use_future_percentage" => "How Children Use Words: Future (Percentage)",
            "how_use_absent_production_percentage" =>
                "How Children Use Words: Absent Object Production (Percentage)",
            "how_use_absent_comp_percentage" =>
                "How Children Use Words: Absent Object Comprehension (Percentage)",
            "how_use_absent_owner_percentage" =>
                "How Children Use Words: Absent Owner (Percentage)",
            "word_endings_plural_percentage" => "Word Endings: Plural (Percentage)",
            "word_endings_possessive_percentage" => "Word Endings: Possessive (Percentage)",
            "word_endings_progressive_percentage" => "Word Endings: Progressive (Percentage)",
            "word_endings_past_percentage" => "Word Endings: Past tense (Percentage)",
            "part_2_b_nouns" => "",
            "part_2_e_second_choice_count" =>
                "Number of times the more complex sentence is selected"
        );

        while ($i = current($score_columns)) {
            $this->addScoreColumn(
                key($score_columns),
                $i
            );
            next($score_columns);
        }
    }


    /**
     * Function to display checkbox for Part I - A
     * @param section_names takes as input an array of words
     * @return void
     *
     */

    function displayCheckbox($section_names, $section_number)
    {
        $qNum = 1;
        for ($i = 0; $i < sizeof($section_names); $i++) {
            $section_labels[$i] = str_replace('_', ' ', $section_names[$i]);
      /**      $this
                ->addCheckbox(
                    $section_number . "_" . $qNum,
                    $section_labels[$i],
                    array('value'=>'1'));
	 
       */   
	    $column = $section_number . "_" . $qNum;
	    $this->form->addElement('advcheckbox', $column , $section_labels[$i], $section_labels[$i], null, self::NoYesCheckbox);
	    $this->XINRegisterRule($section_names[$i], array("$section_names{[$i]}{@}=={@}NEVER_REQUIRED"));
	    $qNum++;
        }
    }  

    /**
     * Page 1
     *
     * @return void
     */
    function _page1()
    {

        // Header
        $this->addHeader("MacArthur-Bates CDI: Words and Sentences");
        $this->addHeader("Part I: Words Children Use");
        $this->addLabel("<h3>A. Vocabulary Checklist</h3>");

        $this->form->addElement(
            "static",
            null,
            "Children understand many more words than they say. We are particularly
            interested in the words your child SAYS. Please go through the list 
            and mark the words you have heard your child use. If your child uses a
            different pronunciation of a word (for example, 'raffe' instead of 
            'giraffe' or 'sketti' for 'spaghetti'), mark the word anyway."
        );

        //  $this->form->addElement('static', null, "In the list below, please mark the phrases that your child seems to understand.");
        /* 1. Sound Effects and Animal Sounds */
        $this->addLabel("<h4><u>1. Sound Effects and Animal Sounds (12)</u></h4>");

        $part_1_names =
            array(
                "baa_baa", "choo_choo", "cockadoodledoo", "grrr",
                "meow", "moo", "ouch", "quack_quack", "uh_oh",
                "vroom", "woof_woof", "yum_yum",
            );

        $this->displayCheckbox($part_1_names, "part_1");

        /* 2. Animals (Real or Toy) (43) */

        $this->addLabel("<h4><u>2. Animals (Real or Toy) (43)</u></h4>");
        $part_2_names =
            array(
                "alligator", "animal", "ant", "bear", "bee", "bird", "bug",
                "bunny", "butterfly", "cat", "chicken", "cow", "deer", "dog","donkey","duck",
                 "elephant","fish","frog",
                "giraffe", "goose", "hen", "horse", "kitty", "lamb", "lion",
                "monkey", "moose", "mouse", "owl", "penguin", "pig", "pony",
                "puppy", "rooster", "sheep", "squirrel", "teddybear", "tiger", "turkey",
                "turtle", "wolf", "zebra"
            );

	$this->displayCheckbox($part_2_names, "part_2");

        /* 3. Vehicles (Real or Toy) (14) */

        $this->addLabel("<h4><u>3. Vehicles (Real or Toy) (14)</u></h4>");

        $part_3_names =
            array(
                "airplane", "bicycle", "boat", "bus", "car",
                "firetruck", "helicopter", "motorcycle", "sled",
                "stroller", "tractor", "train", "tricycle", "truck"
            );

	$this->displayCheckbox($part_3_names, "part_3");

        /* 4. Toys (18) */

        $this->addLabel("<h4><u>4. Toys (18)</u></h4>");

        $part_4_names =
            array(
                "ball", "balloon", "bat", "block", "book", "bubbles",
                "chalk", "crayon", "doll", "game", "glue", "pen", "pencil",
                "play_dough", "present", "puzzle", "story", "toy"
            );

	$this->displayCheckbox($part_4_names, "part_4");
    }

    function _page2()
    {
        $this->form->addElement('static', null, "In the list below, please mark the phrases that your child says.");
        /* 5. Food and Drink (68) */
        $this->addLabel("<h3><u>5. Food and Drink (68)</u></h3>");

        $part_5_names =
            array(
                "apple", "applesauce", "banana", "beans", "bread", "butter", "cake","candy",
                "carrots", "cereal", "cheerios", "cheese", "chicken", "chocolate",
                "coffee", "coke", "cookie", "corn", "cracker", "donut", "drink",
                "egg", "fish", "food", "french_fries", "grapes", "green_beans",
                "gum", "hamburger", "ice", "ice_cream", "jello", "jelly", "juice",
                "lollilop", "meat", "melon", "milk", "muffin", "noodles", "nuts",
                "orange", "pancake", "peanut_butter", "peas", "pickle", "pizza",
                "popcorn", "popsicle", "potato", "popsicle", "potato",
                "potato_chip", "pretzel", "pudding", "pumpkin", "raisin",
                "salt", "sandwich", "sauce", "soda/pop", "soup", "spaghetti",
                "strawberry", "toast", "tuna", "vanilla", "vitamins", "water",
                "yogurt"
            );

        $this->displayCheckbox($part_5_names, "part_5");

        /* 6. Clothing (28) */
        $this->addLabel("<h3><u>6. Clothing (28)</u></h3>");

        $part_6_names =
            array(
                "beads", "belt", "bib", "boots", "button", "coat", "diaper",
                "dress", "gloves", "hat", "jacket", "jeans", "mittens",
                "necklace", "pajamas", "pants", "scarf", "shirt", "shoe",
                "shorts", "slipper", "sneaker", "snowsuit", "sock", "sweater",
                "tights", "underpants", "zipper"
            );

        $this->displayCheckbox($part_6_names, "part_6");

        /* 7. Body Parts (27) */

        $this->addLabel("<h3><u>7. Body Parts (27)</u></h3>");

        $part_7_names =
            array(
                "ankle", "arm", "belly_button", "buttocks/bottom*", "cheek", "chin",
                "ear", "eye", "face", "feet", "finger", "hair", "hand", "head",
                "knee", "leg", "lips", "mouth", "nose", "owie/boo_boo", "penis*",
                "shoulder", "tooth", "toe", "tongue", "tummy", "vagina*"
            );

        $this->displayCheckbox($part_7_names, "part_7");
        $this->addLabel("* or word used in your family");

    }

    function _page3()
    {

        $this->form->addElement('static', null, "In the list below, please mark the phrases that your child says.");
        /* 8. Small Household Items (50) */
        $this->addLabel("<h3><u>8. Small Household Items (50)</u></h3>");
        $part_8_names =
            array(
                "basket", "blanket", "bottle", "box", "bowl", "broom", "brush",
                "bucket", "camera", "can", "clock", "comb", "cup", "dish",
                "fork", "garbage", "glass", "glasses", "hammer", "jar", "keys",
                "knife", "lamp", "light", "medicine", "money", "mop",
                "nail", "napkin", "paper", "penny", "picture",
                "pillow", "plant", "plate", "purse", "radio", "scissors", "soap",
                "spoon", "tape", "telephone", "tissue/kleenex", "toothbrush",
                "towel", "trash", "tray", "vacuum", "walker", "watch"
            );

        $this->displayCheckbox($part_8_names, "part_8");

        /* 9. Furniture and Rooms (33) */

        $this->addLabel("<h3><u>9. Furniture and Rooms (33)</u></h3>");
        $part_9_names =
            array(
                "basement", "bathroom", "bathtub", "bed", "bedroom",
                "bench", "chair", "closet", "couch", "crib", "door",
                "drawer", "dryer", "garage", "high_chair", "kitchen",
                "living_room", "oven", "play_pen", "porch", "potty",
                "refrigerator", "rocking_chair", "room", "shower",
                "sink", "sofa", "stairs", "stove", "table", "TV",
                "washing_machine", "window"
            );

        $this->displayCheckbox($part_9_names, "part_9");

        /* 10. Outside Things (31) */

        $this->addLabel("<h3><u>10. Outside Things (31)</u></h3>");
        $part_10_names =
            array(
                "backyard", "cloud", "flag", "flower", "garden", "grass", "hose",
                "ladder", "lawn_mower", "moon", "pool", "rain", "rock", "roof",
                "sandbox", "shovel", "sidewalk", "sky", "slide", "snow", "snowman",
                "sprinkler", "star", "stick", "stone", "street", "sun", "swing",
                "tree", "water", "wind"
            );

        $this->displayCheckbox($part_10_names, "part_10");
    }

    function _page4()
    {
        $this->form->addElement('static', null, "In the list below, please mark the phrases that your child says.");
        /* 11. Places to Go (22) */
        $this->addLabel("<h3><u>11. Places to Go (22)</u></h3>");

        $part_11_names =
            array(
                "beach", "camping", "church*", "circus", "country", "downtown",
                "farm", "gas_station", "home", "house", "movie", "outside",
                "park", "party", "picnic", "playground", "school", "store",
                "woods", "work", "yard", "zoo"
            );

        $this->displayCheckbox($part_11_names, "part_11");
        $this->addLabel("* or word used in your family");

        /* 12. People (29) */
        $this->addLabel("<h3><u>12. People (29)</u></h3>");
        $part_12_names =
            array(
                "aunt", "baby", "babysitter", "babysitter's_name", "boy",
                "brother", "child", "clown", "cowboy", "daddy*", "doctor",
                "fireman", "friend", "girl", "grandma*", "grandpa*", "lady",
                "mailman", "man", "mommy*", "nurse", "child's_own_name", "people",
                "person", "pet's_name", "police", "sister", "teacher", "uncle"
            );
        $this->displayCheckbox($part_12_names, "part_12");
        $this->addLabel("* or word used in your family");

        /* 13. Games and Routines (25) */
        $this->addLabel("<h3><u>13. Games and Routines (25)</u></h3>");
        $part_13_names =
            array(
                "bath", "breakfast", "bye", "call_(on_phone)", "dinner",
                "give_me_five!", "gonna_get_you!", "go_potty", "hi", "hello",
                "lunch", "nap", "night_night", "no", "patty_cake", "peekaboo",
                "please", "shh/shush", "shopping", "snack", "so_big!",
                "thank_you", "this_little_piggy", "turn_around", "yes"
            );
        $this->displayCheckbox($part_13_names, "part_13");

        /* 14. Action Words (103) */
        $this->addLabel("<h3><u>14. Action Words (103)</u></h3>");
        $part_14_names =
            array(
                "bite", "blow", "break", "bring", "build", "bump", "buy",
                "carry", "catch", "chase", "clap", "clean", "climb", "close",
                "cook", "cover", "cry", "cut", "dance", "draw", "drink",
                "drive", "drop", "dry", "dump", "eat", "fall", "feed", "find",
                "finish", "fit", "fix", "get", "give", "go", "hate", "have",
                "hear", "help", "hide", "hit", "hold", "hug", "hurry", "jump",
                "kick", "kiss", "knock", "lick", "like", "listen", "look",
                "love", "make", "open", "paint", "pick", "play", "pour", "pretend",
                "pull", "push", "put", "read", "ride", "rip", "run", "say", "see",
                "shake", "share", "show", "sing", "sit", "skate", "sleep", "slide",
                "smile", "spill", "splash", "stand", "stay", "stop", "sweep",
                "swim", "swing", "take", "talk", "taste", "tear", "think", "throw",
                "think", "throw", "tickle", "touch", "wait", "wake", "walk",
                "wash", "watch", "wipe", "wish", "work", "write"
            );
        $this->displayCheckbox($part_14_names, "part_14");
    }

    function _page5()
    {
        $this->form->addElement('static', null, "In the list below, please mark the phrases that your child says.");

        /* 15. Descriptive Words (63) */
        $this->addLabel("<h3><u>15. Descriptive Words (63)</u></h3>");
        $part_15_names =
            array(
                "allgone", "asleep", "awake", "bad", "better", "big", "black",
                "blue", "broken", "brown", "careful", "clean", "cold", "cute",
                "dark", "dirty", "dry", "empty", "fast", "fine", "first", "full",
                "gentle", "good", "green", "happy", "hard", "heavy", "high", "hot",
                "hungry", "hurt", "last", "little", "long", "loud", "mad",
                "naughty", "new", "nice", "noisy", "old", "orange", "poor",
                "pretty", "quiet", "red", "sad", "scared", "sick", "sleepy",
                "slow", "soft", "sticky", "stuck", "thirsty", "tiny", "tired",
                "wet", "white", "windy", "yellow", "yucky"
            );
        $this->displayCheckbox($part_15_names, "part_15");

        /* 16. Words About Time (12) */
        $this->addLabel("<h3><u>16. Words About Time (12)</u></h3>");
        $part_16_names =
            array(
                "after", "before", "day", "later", "morning", "night",
                "now", "time", "today", "tomorrow", "tonight", "yesterday"
            );
        $this->displayCheckbox($part_16_names, "part_16");

        /* 17. Pronouns (25) */
        $this->addLabel("<h3><u>17. Pronouns (25)</u></h3>");
        $part_17_names =
            array(
                "he", "her", "hers", "him", "his", "I", "it", "me", "mine", "my",
                "myself", "our", "she", "that", "their", "them", "these", "they",
                "this", "those", "us", "we", "you", "your", "yourself"
            );
        $this->displayCheckbox($part_17_names, "part_17");


        /* 18. Question Words (7) */
        $this->addLabel("<h3><u>18. Question Words (7)</u></h3>");
        $part_18_names =
            array(
                "how", "what", "when", "where", "which", "who", "why"
            );
        $this->displayCheckbox($part_18_names, "part_18");

        /* 19. Prepositions and Locations (26) */
        $this->addLabel("<h3><u>19. Prepositions and Locations (26)</u></h3>");
        $part_19_names =
            array(
                "about", "above", "around", "at", "away", "back", "behind",
                "beside", "by", "down", "for", "here", "inside/in", "into",
                "next_to", "of", "off", "on", "on_top_of", "out", "over",
                "there", "to", "under", "up", "with"
            );
        $this->displayCheckbox($part_19_names, "part_19");
    }

    function _page6()
    {
        $this->form->addElement('static', null, "In the list below, please mark the phrases that your child says.");

        /* 20. Quantifiers and Articles (17)  */
        $this->addLabel("<h3><u>20. Quantifiers and Articles (17)</u></h3>");
        $part_20_names =
            array(
                "a", "all", "a_lot", "an", "another", "any", "each",
                "every", "more", "much", "not", "none", "other", "same",
                "some", "the", "too"
            );
        $this->displayCheckbox($part_20_names, "part_20");

        /* 21. Helping Verbs (21) */
        $this->addLabel("<h3><u>21. Helping Verbs (21)</u></h3>");
        $part_21_names =
            array(
                "am", "are", "be", "can", "could", "did/did_ya", "do", "does",
                "don't", "gonna/going_to", "gotta/got_to", "hafta/have_to", "is",
                "lemme/let_me", "need/need_to", "try/try_to", "wanna/want_to",
                "was", "were", "will", "would"
            );
        $this->displayCheckbox($part_21_names, "part_21");


        /* 22. Connecting Words (6) */
        $this->addLabel("<h3><u>22. Connecting Words (6)</u></h3>");
        $part_22_names =
            array(
                "and", "because", "but", "if", "so", "then"
            );
        $this->displayCheckbox($part_22_names, "part_22");
    }

    function _page7()
    {
        $this->addHeader("Part I - B. How Children Use Words");
        $part_1_b_questions =
            array(
                "1. Does your child ever talk about past events or people
                who are not present? For example, a child who saw a parade last
                week might later say parade, clown, or band.",
                "2. Does your child ever talk about something that's going to
                happen in the future, for example, saying \"choo choo\" or 
                \"airplane\" before you leave the house for a trip, or saying
                \"swing\" when you are going to the park?",
                "3. Does your child talk about objects that are not present
                such as asking about a missing or absent toy, referring to 
                a pet out of view, or asking about someone not present?",
                "4. Does your child understand if you ask for something that
                is not in the room, for example, by going to the bathroom to get a
                teddy bear when you say 'where's the bear?'",
                "5. Does your child ever pick up or point to an object and name
                an absent person to whom the object belongs? For example, 
                a child might point to mommy's shoe and say \"mommy\"."
            );

        for ($i = 0; $i < sizeof($part_1_b_questions); $i++) {
            $this->addSelect(
                "part_1_b_" . $i,
                $part_1_b_questions[$i],
                $this->frequency
            );
        }
    }

    function _page8()
    {
        $this->addHeader("Part II - Sentences and Grammar");

        $this->addLabel("<h3>A. Word Endings/Part 1</h3>");
        $part_2_a_questions =
            array(
                "1. To talk about more than one thing, we add an \"s\" to 
                many words. Examples include cars (for more than one car), shoes,
                dogs, and keys. Has your child begun to do this?",
                "2. To talk about ownership, we add an \"s\", for example, 
                Daddy's key, kitty's dish, and baby's bottle. Has your child begun
                to do this?",
                "3. To talk about activities, we sometimes add \"ing\" to verbs.
                Examples include looking, running, and crying. Has your child begun
                to do this?",
                "4. To talk about things that happened in the past, we often add
                \"ed\" to the verb. Examples include kissed, opened, and pushed. Has
                your child begun to do this?"
            );
        for ($i = 0; $i < sizeof($part_2_a_questions); $i++) {
            $this->addSelect(
                "part_2_a_" . $i,
                $part_2_a_questions[$i],
                $this->frequency
            );
        }

        $this->addLabel("<h3>B. Word Forms</h3>");
        $this->addLabel("<h4>$this->indent Following are some of the words children learn. Please mark any of these words that your child uses</h4>");
        $part_2_b_nouns =
            array(
                "children", "feet", "men", "mice", "teeth"
            );
        $part_2_b_verbs =
            array(
                "ate", "blew", "bought", "broke", "came", "drank", "drove",
                "fell", "flew", "got", "had", "heard", "held", "lost", "made",
                "ran", "sat", "saw", "took", "went"
            );
        $this->addLabel("<h4><i>Nouns</i></h4>");
        $this->displayCheckbox($part_2_b_nouns, "part_2_b_nouns");
        $this->addLabel("<h4><i>Verbs</i></h4>");
        $this->displayCheckbox($part_2_b_verbs, "part_2_b_verbs");

        $this->addLabel("<h3>C. Word Endings/Part 2</h3>");
        $this->addLabel("<h4>$this->indent  Young children often place the wrong endings
                        on words. For example, a child might say \"Auntie goed
                        home.\" Mistakes like this are often a sign of progress
                        in language. In the following lists, please mark all the
                        mistakes of this kind you have heard.</h4>");
        $this->addLabel("<h4><i>Nouns</i></h4>");
        $part_2_c_nouns =
            array(
                "blockses", "childrens", "childs", "feets", "foots",
                "mans", "mens", "mices", "mouses", "shoeses", "sockses",
                "teeths", "toeses", "tooths"
            );
        $this->displayCheckbox($part_2_c_nouns, "part_2_c_nouns");
        $this->addLabel("<h4><i>Verbs</i></h4>");
        $part_2_c_verbs =
            array(
                "ated", "blewed", "blowed", "bringed", "buyed", "breaked",
                "broked", "camed", "comed", "doed", "dranked", "drinked",
                "eated", "failed", "flied", "getted", "goed", "gotted",
                "haved", "heared", "holded", "losed", "losted", "maked",
                "ranned", "runned", "seed", "satted", "sitted", "taked",
                "wented"
            );
        $this->displayCheckbox($part_2_c_verbs, "part_2_c_verbs");

        $this->addSelect(
            "part_2_c_last_question",
            "Has your child begun to combine words yet, such as \"nother cracker\",
            or \"doggie bite?\"",
            $this->frequency
        );

        $this->addLabel("<h3>D. Examples</h3>");
        $this->addLabel("<h4>$this->indent  Please list three of the longest sentences you have 
                         heard your child say recently.</h4>");
        for ($i = 1; $i < 4; $i++) {
            $this->addBasicText("part_2_d_" . $i, $i . ".");
            $this->XINRegisterRule(
                "part_2_d_" . $i,
                array("part_2_c_last_question{@}=={@}not_yet|sometimes"),
                "Required if 'Not Yet' or 'Sometimes' selected for the
                question following Part II - Section C."
            );
        }

        $this->addLabel("<h3>E. Complexity</h3>");
        $this->addLabel("<h4>In each of the following pairs, please mark
                         the one that sounds MOST like the way your child
                         talks right now. If your child is saying sentences
                         even more complicated than the two provided, just
                         pick the second one.</h4>");

        $part_2_e_pairs =
            array(
                array(
                    null => "",
                    "two_foot" => "Two foot.",
                    "two_feet" => "Two feet."
                ),
                array(
                    null => "",
                    "kitty_sleep" => "Kitty sleep.",
                    "kitty_sleeping" => "Kitty sleeping."
                ),
                array(
                    null => "",
                    "i_make_tower" => "I make tower.",
                    "i_making_tower" => "I making tower."
                ),
                array(
                    null => "",
                    "i_fall_down" => "I fall down.",
                    "i_fell_down" => "I fell down."
                ),
                array(
                    null => "",
                    "more_cookie" => "More cooke!",
                    "more_cookies" => "More cookies!"
                ),
                array(
                    null => "",
                    "these_my_tooth" => "These my tooth.",
                    "these_my_teeth" => "These my teeth."
                ),
                array(
                    null => "",
                    "baby_blanket" => "Baby blanket",
                    "babys_blanket" => "Baby's blanket"
                ),
                array(
                    null => "",
                    "doggie_kiss_me" => "Doggie kiss me.",
                    "doggie_kissed_me" => "Doggie kissed me.",
                ),
                array(
                    null => "",
                    "daddy_pick_me_up" => "Daddy pick me up.",
                    "daddy_picked_me_up" => "Daddy picked me up."
                ),
                array(
                    null => "",
                    "kitty_go_away" => "Kitty go away.",
                    "kitty_went_away" => "Kitty went away."
                ),
                array(
                    null => "",
                    "doggie_table" => "Doggie table.",
                    "doggie_on_table" => "Doggie on table."
                ),
                array(
                    null => "",
                    "that_my_truck" => "That my truck.",
                    "thats_my_truck" => "That's my truck."
                ),
                array(
                    null => "",
                    "baby_crying" => "Baby crying.",
                    "baby_is_crying" => "Baby is crying."
                ),
                array(
                    null => "",
                    "you_fix_it" => "You fix it?",
                    "can_you_fix_it" => "Can you fix it?"
                ),
                array(
                    null => "",
                    "read_me_story_mommy" => "Read me story, Mommy.",
                    "read_me_a_story_mommy" => "Read me a story, Mommy."
                ),
                array(
                    null => "",
                    "no_wash_dolly" => "No wash dolly.",
                    "dont_wash_dolly" => "Don't wash dolly."
                ),
                array(
                    null => "",
                    "want_more_juice" => "Want more juice.",
                    "want_juice_in_there" => "Want juice in there."
                ),
                array(
                    null => "",
                    "there_a_kitty" => "There a kitty.",
                    "theres_a_kitty" => "There's a kitty."
                ),
                array(
                    null => "",
                    "go_bye_bye" => "Go bye-bye.",
                    "wanna_go_bye_bye" => "Wanna go bye-bye."
                ),
                array(
                    null => "",
                    "where_mommy_go" => "Where mommy go?",
                    "where_did_mommy_go" => "Where did mommy go?"
                ),
                array(
                    null => "",
                    "coffee_hot" => "Coffee hot.",
                    "that_coffee_hot" => "That coffee hot."
                ),
                array(
                    null => "",
                    "i_no_do_it" => "I no do it.",
                    "i_cant_do_it" => "I can't do it."
                ),
                array(
                    null => "",
                    "i_like_read_stories" => "I like read stories.",
                    "i_like_to_read_stories" => "I like to read stories."
                ),
                array(
                    null => "",
                    "dont_read_book" => "Don't read book.",
                    "dont_want_you_read_that_book" => "Don't want you read that book."
                ),
                array(
                    null => "",
                    "turn_on_light" => "Turn on light.",
                    "turn_on_the_light_so_i_can_see" => "Turn on the light so I can see."
                ),
                array(
                    null => "",
                    "i_want_that" => "I want that.",
                    "i_want_that_one_you_got" => "I want that one you got."
                ),
                array(
                    null => "",
                    "want_cookies" => "Want cookies.",
                    "want_cookies_and_milk" => "Want cookies and milk."
                ),
                array(
                    null => "",
                    "cookie_mommy" => "Cookie mommy.",
                    "cookie_for_mommy" => "Cookie for mommy."
                ),
                array(
                    null => "",
                    "baby_want_eat" => "Baby want eat.",
                    "baby_want_to_eat" => "Baby want to eat."
                ),
                array(
                    null => "",
                    "lookit_me" => "Lookit me!",
                    "lookit_me_dancing" => "Lookit me dancing!"
                ),
                array(
                    null => "",
                    "lookit" => "Lookit!",
                    "lookit_what_i_got_" => "Lookit what I got!"
                ),
                array(
                    null => "",
                    "wheres_my_dolly" => "Where's my dolly?",
                    "wheres_my_dolly_name_sam" => "Where's my dolly name Sam?"
                ),
                array(
                    null => "",
                    "we_made_this" => "We made this.",
                    "me_and_paul_made_this" => "Me and Paul made this."
                ),
                array(
                    null => "",
                    "i_sing_song" => "I sing song.",
                    "i_sing_song_for_you" => "I sing song for you."
                ),
                array(
                    null => "",
                    "baby_crying" => "Baby crying.",
                    "baby_crying_cuz_shes_sad" => "Baby crying cuz she's sad."
                ),
                array(
                    null => "",
                    "two_shoe" => "Two shoe.",
                    "two_shoes" => "Two shoes."
                ),
                array(
                    null => "",
                    "daddy_car" => "Daddy car.",
                    "daddys_car" => "Daddy's car."
                ),
            );

        for ($i = 0; $i < sizeof($part_2_e_pairs); $i++) {

            // index remapping
            if ($i == 0) {
                $j = 35;
            }
            else if ($i == 1) {
                $j = 0;
            }
            else if ($i == 2) {
                $j = 36;
            }
            else {
                $j = $i - 2;
            }

            $idx = $i + 1;

            $variableIdx = $j + 1;
            // index remapping

            $label_txt = '';
            foreach ($part_2_e_pairs[$j] as $key => $val) {
                if (!is_null($key)) {
                    if (!empty($label_txt)) {
                        $label_txt .= " / ";
                    }
                    $label_txt .= $val;
                }
            }

            if ($i == 3 || $i == 4) {
                $this->addSelect(
                    "part_2_e_" . $variableIdx,
                    $idx . ". (Talking about something happening right now) " . $label_txt,
                    $part_2_e_pairs[$j]
                );

            } elseif (in_array($i, [5, 9, 10, 11])) {
                $this->addSelect(
                    "part_2_e_" . $variableIdx,
                    $idx . ". (Talking about something that already happened) " . $label_txt,
                    $part_2_e_pairs[$j]
                );

            } else {
                $this->addSelect(
                    "part_2_e_" . $variableIdx,
                    $idx . "." . $label_txt,
                    $part_2_e_pairs[$j]
                );
            }

            $this->XINRegisterRule(
                "part_2_e_" . $variableIdx,
                array("part_2_c_last_question{@}=={@}not_yet|sometimes"),
                "Required if 'Not Yet' or 'Sometimes' selected for the
                question following Part II - Section C."
            );

        }
    }


    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        //null scores
        $this->_nullScores($this->scoreLabels);

        //get the saved scores
        $db = Database::singleton();

        $record =$db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid", array("cid" =>$this->getCommentID()));

        // Get gender
        $query_gender = "SELECT Sex FROM candidate as c, session as s, flag as f, $this->table as t WHERE t.CommentID=:cid AND f.CommentID=t.CommentID AND s.ID=f.SessionID AND s.CandID=c.CandID";
        $record_gender = $db->pselectRow($query_gender,array("cid" =>$this->getCommentID() ));
        $gender = strtolower($record_gender['Gender']);

        // Get the subject age in months for scoring
        $timepoint = TimePoint::singleton($this->getSessionID());
        $dob = $timepoint->getEffectiveDateOfBirth();

        $age = Utility::calculateAge($dob, $record["Date_taken"]);
        $age_months = $age['year'] * 12 + $age['mon'];

        /***** Part I - Vocab Checklist *****/


        $scores = array();
        $scores['part1_wpNum'] = 0;
        $scores['part_2_b_nouns'] = 0;
        $scores['part_2_b_verbs'] = 0;
        $scores['part_2_c_nouns'] = 0;
        $scores['part_2_c_verbs'] = 0;
        $scores['words_produced_number']=0;

        $part_1_section_length =
            array(
                1 => 12, 2 => 43, 3 => 14, 4 => 18, 5 => 68, 6 => 28, 7 => 27, 8 => 50,
                9 => 33, 10 => 31, 11 => 22, 12 => 29, 13 => 25, 14 => 103, 15 => 63,
                16 => 12, 17 => 25, 18 => 7, 19 => 26, 20 => 17, 21 => 21, 22 => 6);


        foreach($part_1_section_length as $section => $numWords) {
                $this->SumWords($numWords, $record, "part_" . $section . "_", $scores[$section]);
            }

        /* How Children Use Words  */
        for($qNum = 1; $qNum <= 22; $qNum++) {
            $scores['words_produced_number']+=$scores[$qNum];
        }

        $part_2_section_length =
            array(
                "part_2_b_nouns" => 5, "part_2_b_verbs" => 20
            );
        foreach ($part_2_section_length as $section => $numWords) {
            $this->SumWords($numWords, $record, $section . "_", $scores[$section]);}
        $scores['word_forms'] =  $scores['part_2_b_nouns'] +   $scores['part_2_b_verbs'];

        $part_3_section_length =
            array(
                "part_2_c_nouns" => 14, "part_2_c_verbs" => 31
            );


        foreach ($part_3_section_length as $section => $numWords) {
            $this->SumWords($numWords, $record, $section . "_", $scores[$section]);
        }
        $scores['word_endings_part2'] =  $scores['part_2_c_nouns'] +   $scores['part_2_c_verbs'];
        /*
        * E. Complexity - # of times the more complex sentence is selected
        */

        $part_2_e_first_options =
            array(
                "two_foot", "kitty_sleep", "i_make_tower",
                "i_fall_down", "more_cookie", "these_my_tooth", "baby_blanket",
                "doggie_kiss_me", "daddy_pick_me_up", "kitty_go_away",
                "doggie_table", "that_my_truck", "baby_crying", "you_fix_it",
                "read_me_story_mommy", "no_wash_dolly", "want_more_juice",
                "there_a_kitty", "go_bye_bye", "where_mommy_go", "coffee_hot",
                "i_no_do_it", "i_like_read_stories", "dont_read_book",
                "turn_on_light", "i_want_that", "want_cookies",
                "cookie_mommy", "baby_want_eat", "lookit_me", "lookit",
                "wheres_my_dolly", "we_made_this", "i_sing_song",
                "baby_crying","two_shoe","daddy_car"
            );

        $part_2_e_second_options =
              array(
                  "two_feet", "kitty_sleeping",
                  "i_making_tower", "i_fell_down", "more_cookies",
                  "these_my_teeth", "babys_blanket", "doggie_kissed_me",
                  "daddy_picked_me_up", "kitty_went_away", "doggie_on_table",
                  "thats_my_truck", "baby_is_crying", "can_you_fix_it",
                  "read_me_a_story_mommy", "dont_wash_dolly", "want_juice_in_there",
                  "theres_a_kitty", "wanna_go_bye_bye", "where_did_mommy_go",
                  "that_coffee_hot", "i_cant_do_it", "i_like_to_read_stories",
                  "dont_want_you_read_that_book", "turn_on_the_light_so_i_can_see",
                  "i_want_that_one_you_got", "want_cookies_and_milk",
                  "cookie_for_mommy", "baby_want_to_eat", "lookit_me_dancing",
                  "lookit_what_i_got", "wheres_my_dolly_name_sam",
                  "me_and_paul_made_this", "i_sing_song_for_you",
                  "baby_crying_cuz_she's_sad","two_shoes","daddys_car"
              );

        $scores['part_2_e_first_choice_count'] = 0;
        $scores['part_2_e_second_choice_count'] = 0;

        for ($i = 1; $i <= 37; $i++) {
            $curr_q = "part_2_e_" . $i;
            if (in_array($record[$curr_q], $part_2_e_second_options)) {
                $scores['part_2_e_second_choice_count']++;

            }
        }
        $scores['grammatical_complexity']=$scores['part_2_e_second_choice_count'];

        /* Calculate Percentiles */
        $scales_percentile =
            array(
                "words_produced",
                "word_forms",
                "grammatical_complexity",
                );
        foreach($scales_percentile as $scale) {
            if($age_months >= 16 && $age_months <= 30) {
                if ($scale == "words_produced" || $scale == "grammatical_complexity") {
                    $this->CalculatePercentile($scale, $age_months, $gender, $scores);
                } else {
                    $this->CalculatePercentile($scale, $age_months, "both_sexes", $scores);
                }
            } else {
                $scale_percentile = $scale . "_percentile";
                $scores[$scale_percentile] = "Candidate is too old to score.";
            }
        }


        /* Percentage of Affirmative Answers at this Child's Age for each subscale */

        $scales_percentage =
            array(
                "word_endings_plural",
                "word_endings_possessive",
                "word_endings_past",
                "word_endings_progressive",
                "how_use_absent_comp",
                "how_use_absent_owner",
                "how_use_absent_production",
                "how_use_future",
                "how_use_past"
            );

        foreach ($scales_percentage as $scale) {
            if($age_months >= 16 && $age_months <= 30) {
                $this->ReturnPercentage($scale, $age_months, "both_sexes", $scores);
            } else {
                $scale_percentage = $scale . "_percentage";
                $scores[$scale_percentage] = "Candidate is too old to score.";
            }
        }

     for($s=1;$s<=22; $s++)
     {
         unset($scores[$s]);
     }

        $result = $db->update($this->table, $scores, array("CommentID"=>$this->getCommentID()));
    }
}
