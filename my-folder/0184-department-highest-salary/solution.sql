select d.name as Department, a.name as Employee, a.Salary
from employee a join department d on a.departmentid=d.id
where a.salary = (select max(b.salary)
from employee b
where a.departmentid=b.departmentid)


