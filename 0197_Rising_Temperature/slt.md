### Solution 1 JOIN

使用内联结，然后用DATEDIFF或TO_DAYS比较日期。

DATEDIFF(A, B)的结果是A-B。如A="2019-10-11", B="2019-10-10",则DATEDIFF(A, B)=1, DATEDIFF(B, A)=-1

```sql
SELECT W2.Id
FROM Weather W1 JOIN Weather W2
ON
    DATEDIFF(W2.recordDate, W1.recordDate)=1 AND
    W2.temperature>W1.temperature;
```
