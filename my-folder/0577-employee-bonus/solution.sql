# Write your MySQL query statement below
SELECT Employee.name,Bonus.bonus FROM Employee
LEFT JOIN Bonus on Employee.empId = Bonus.empId
where Bonus IS NULL OR BONUS < 1000;
