UPDATE DAS_SA 
SET 
    verbal_PERCENTILE = REPLACE(verbal_PERCENTILE,
        '&gt;',
        'greater than '),
    verbal_PERCENTILE = REPLACE(verbal_PERCENTILE,
        '&lt;',
        'less than '),
    verbal_similarities_PERCENTILE = REPLACE(verbal_similarities_PERCENTILE,
        '&gt;',
        'greater than '),
    verbal_similarities_PERCENTILE = REPLACE(verbal_similarities_PERCENTILE,
        '&lt;',
        'less than ');
