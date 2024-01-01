# Write your MySQL query statement below
SELECT id,
       SUM(if(month = 'Jan', revenue, null)) AS Jan_Revenue,
       SUM(if(month = 'Feb', revenue, null)) AS Feb_Revenue,
       SUM(if(month = 'Mar', revenue, null)) AS Mar_Revenue,
       SUM(if(month = 'Apr', revenue, null)) AS Apr_Revenue,
       SUM(if(month = 'May', revenue, null)) AS May_Revenue,
       SUM(if(month = 'Jun', revenue, null)) AS Jun_Revenue,
       SUM(if(month = 'Jul', revenue, null)) AS Jul_Revenue,
       SUM(if(month = 'Aug', revenue, null)) AS Aug_Revenue,
       SUM(if(month = 'Sep', revenue, null)) AS Sep_Revenue,
       SUM(if(month = 'Oct', revenue, null)) AS Oct_Revenue,
       SUM(if(month = 'Nov', revenue, null)) AS Nov_Revenue,
       SUM(if(month = 'Dec', revenue, null)) AS Dec_Revenue
FROM Department
GROUP BY id