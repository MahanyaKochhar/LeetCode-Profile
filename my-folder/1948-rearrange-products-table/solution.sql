# Write your MySQL query statement below
Select product_id,"store1" as store,store1 as price
from Products
where store1 IS  NOT NULL
union
Select product_id,"store2" as store,store2 as price
from Products
where store2 IS  NOT NULL
union 
Select product_id,"store3" as store,store3 as price
from Products
where store3 IS  NOT NULL
