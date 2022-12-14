# Write your MySQL query statement below
Select name as Customers from customers where id NOT IN (Select customerId from Orders)
