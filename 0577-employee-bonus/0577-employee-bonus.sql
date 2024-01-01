# Write your MySQL query statement below
SELECT name, bonus
FROM Employee NATURAL LEFT OUTER JOIN Bonus
WHERE bonus < 1000 OR bonus IS NULL;