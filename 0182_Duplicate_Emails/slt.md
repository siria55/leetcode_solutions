### 思路1 使用GROUP BY

```sql
SELECT email
FROM Person
GROUP BY email
HAVING COUNT(*)>1;
```
