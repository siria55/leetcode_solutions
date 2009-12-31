### 思路1

先找出有5个下属的经理的Id

```sql
SELECT name
FROM Employee
WHERE id IN (
SELECT managerId
FROM Employee
GROUP BY managerId
HAVING COUNT(*)>=5);
```

