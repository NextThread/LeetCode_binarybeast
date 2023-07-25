# Write your MySQL query statement below
select 
    d.name AS Department,
    e.name as Employee,
    e.salary
from 
    employee e 
    join department d on e.departmentId = d.id
where e.salary = (select max(salary) from employee where departmentId = e.departmentId)