### Solution 1 use max

```sql
SELECT MAX(Salary) AS SecondHighestSalary
FROM Employee
WHERE Salary <
(SELECT MAX(Salary) AS max_salary
FROM Employee);
```
