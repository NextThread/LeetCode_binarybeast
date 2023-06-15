SELECT 
    score, 
    DENSE_RANK() OVER(ORDER BY score desc) AS `rank` 
FROM scores
ORDER BY `rank`