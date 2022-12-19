# Write your MySQL query statement below

Select Employees.employee_id as employee_id from Employees
Left Join Salaries ON
Employees.employee_id=Salaries.employee_id
where salary is NULL
Union
Select Salaries.employee_id as employee_id from Employees
Right Join Salaries ON
Employees.employee_id=Salaries.employee_id
where name is NULL
order by employee_id
