# Write your MySQL query statement below
# Select (count(*)) from Activities group by sell_date
Select sell_date,count(distinct(product)) as num_sold,group_concat(distinct(product) order by product) as products from Activities group by sell_date
