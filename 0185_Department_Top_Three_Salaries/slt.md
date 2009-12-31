### Solution 1

先用 join 构建一个(机构名, 员工名, 工资)的表。再利用子查询，同部门工资大于的数量小于3，自然就是这个部门的前三。卧槽。

```sql
SELECT
    D.name AS Department,
    E.name AS Employee,
    E.Salary AS Salary
FROM Employee AS E JOIN Department AS D
ON E.DepartmentId=D.Id
WHERE (
    SELECT COUNT(DISTINCT Ein.Salary)
    FROM Employee AS Ein
    WHERE Ein.Salary > E.Salary AND Ein.DepartmentId=E.DepartmentId
)<3;
```

