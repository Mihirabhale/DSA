# Write your MySQL query statement below
SELECT eu.unique_id, em.name
FROM Employees AS em
LEFT JOIN EmployeeUNI AS eu ON em.id=eu.id;