# Write your MySQL query statement below
SELECT v.customer_id,count(v.visit_id)as count_no_trans
FROM Visits v
left join Transactions t
on v.visit_id=t.visit_id
WHERE t.visit_id is NULL
GROUP BY v.customer_id;