### 思路1 使用 JOIN

```sql
SELECT E1.name AS Employee
FROM Employee E1 JOIN Employee E2 ON
    E1.salary > E2.salary AND
    E1.managerId = E2.id;
```
