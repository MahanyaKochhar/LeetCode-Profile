select nullif((select distinct Salary from Employee
order By Salary desc
limit 1 offset 1),null) as SecondHighestSalary

