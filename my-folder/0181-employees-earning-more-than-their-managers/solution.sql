# Write your MySQL query statement below
select name as Employee
from employee e
where Salary>(select salary from employee where Id=e.ManagerId)

