# Write your MySQL query statement below
select b.Name as Department, a.Name as Employee, Salary
from
(select *, dense_rank() over(partition by DepartmentId order by Salary DESC) as ranks
from Employee) a
join Department b
on a.DepartmentId = b.Id
where ranks <= 3