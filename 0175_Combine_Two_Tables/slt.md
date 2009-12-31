### 思路1 直接用left join

```sql
SELECT P.firstName, P.lastName, A.city, A.state
FROM Person AS P LEFT JOIN Address AS A
ON P.personId=A.personId;
```

