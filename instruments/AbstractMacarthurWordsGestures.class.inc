<?php

/**
 * AbstractMacarthurWordsGestures class.
 *
 * Contains common methods to all the Macarthur questionnaires (survey and non-survey).
 */
abstract class AbstractMacarthurWordsGestures extends NDB_BVL_Instrument
{
    // Max percentile for all subscales
    const MAX_PERCENTILE = 99;

    /**
     * Computes the percentile for an age in months, gender, scale and raw score.
     *
     * @param string $scale      the macarthur scale.
     * @param int    $age_months candidate age in months.
     * @param string $gender     male or female.
     * @param array  $scores     the candidate scores for all scales.
     *
     * @return string the computed percentile (not necessarily a number).
     */
    function getPercentile($scale, $age_months, $gender, &$scores) {
        $db = Database::singleton();

        $scale_number     = "{$scale}_number";
        $scale_percentile = "{$scale}_percentile";

        $query_scores = "
            SELECT *
            FROM macarthur_lookup
            WHERE age_months = '$age_months'
            AND sex          = '$gender'
            AND score_raw    = '{$scores[$scale_number]}'
            AND subscale     = '$scale_number'
        ";
        $row = $db->pselectRow($query_scores, array());

        // If an exact match for the given raw score was found, return it
        if(!is_null($row)) {
            return $row["score_percentile"] > self::MAX_PERCENTILE
                ? self::MAX_PERCENTILE
                : $row["score_percentile"];
        }

        $score_holder = $scores[$scale_number];

        //----------------------------------------------//
        // Find the record with the lowest raw score    //
        // bigger than the candidate's raw score for    //
        // that subscale                                //
        //----------------------------------------------//
        $query_scores1a = "
            SELECT *
            FROM macarthur_lookup
            WHERE age_months = $age_months
            AND sex          = '$gender'
            AND subscale     = '$scale_number'
            AND score_raw    > $score_holder
            ORDER BY score_raw ASC
            LIMIT 1
        ";
        $record_1a = $db->pselect($query_scores1a, []);

        // If there are no scores bigger than the candidate's score return the max percentile
        if(empty($record_1a)) {
            return self::MAX_PERCENTILE;
        }

        $highScore = $record_1a[0]['score_raw'];
        $highPerc  = $record_1a[0]['score_percentile'];

        //----------------------------------------------//
        // Find the record with the highest raw score   //
        // lower than the candidate's raw score for     //
        // that subscale                                //
        //----------------------------------------------//
        $query_scores1b = "
            SELECT *
            FROM macarthur_lookup
            WHERE age_months = $age_months
            AND sex          = '$gender'
            AND subscale     = '$scale_number'
            AND score_raw    < $score_holder
            ORDER BY score_raw DESC
            LIMIT 1
        ";
        $record_1b = $db->pselect($query_scores1b, []);

        // If there are no scores lower than the candidate score return '<5'
        if( empty($record_1b)) {
            return "<5";
        }

        //----------------------------------------//
        // So we have candidate score > $lowScore //
        // and candidate score < $highScore.      //
        // Compute the weighted average           //
        //----------------------------------------//
        $lowScore = $record_1b[0]['score_raw'];
        $lowPerc  = $record_1b[0]['score_percentile'];

        $averagePerc = (($score_holder - $lowScore) / ($highScore - $lowScore)) * ($highPerc - $lowPerc) + $lowPerc;
        $averagePerc = abs(round($averagePerc));

        return $averagePerc > self::MAX_PERCENTILE
            ? self::MAX_PERCENTILE
            : $averagePerc;
    }
}

?>
