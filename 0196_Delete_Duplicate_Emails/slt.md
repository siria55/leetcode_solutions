### 思路1

使用内联结

```sql
DELETE P1
FROM Person P1 JOIN Person P2
ON
    P1.Email=P2.Email AND
    P1.Id>P2.Id;
```

先用Email内联结

```sql
MariaDB [test]> select * from Person p1 inner join Person p2 on p1.Email=p2.Email;
+----+------------------+----+------------------+
| Id | Email            | Id | Email            |
+----+------------------+----+------------------+
|  1 | john@example.com |  1 | john@example.com |
|  3 | john@example.com |  1 | john@example.com |
|  2 | bob@example.com  |  2 | bob@example.com  |
|  1 | john@example.com |  3 | john@example.com |
|  3 | john@example.com |  3 | john@example.com |
+----+------------------+----+------------------+
```

再加上Id大于的判断

```sql
MariaDB [test]> select * from Person p1 inner join Person p2 on p1.Email=p2.Email AND p1.Id>p2.Id;
+----+------------------+----+------------------+
| Id | Email            | Id | Email            |
+----+------------------+----+------------------+
|  3 | john@example.com |  1 | john@example.com |
+----+------------------+----+------------------+
```

最后把select改成delete就能删除了。注意delet后面跟的是表名。
