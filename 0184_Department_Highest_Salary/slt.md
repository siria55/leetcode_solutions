### 思路1 

利用子查询先找出每个部门的最高工资，再联结两个表查询

```sql
SELECT
    D.Name AS Department,
    E.Name AS Employee,
    E.Salary
FROM Department AS D JOIN Employee AS E
ON D.Id=E.DepartmentId
WHERE (E.Salary, D.Id) IN (
    SELECT MAX(Salary), DepartmentId
    FROM Employee
    GROUP BY DepartmentId);
```

