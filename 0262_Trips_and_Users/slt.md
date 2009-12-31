### Solution 1

```sql
SELECT
    t.Request_at AS Day,
    ROUND(SUM(IF(T.STATUS = "completed",0,1))/COUNT(*), 2) AS `Cancellation Rate`
FROM Trips T JOIN
Users AS U1 ON (T.client_id = U1.users_id AND U1.banned ='No') JOIN
Users AS U2 ON (T.driver_id = U2.users_id AND U2.banned ='No')
WHERE T.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY t.Request_at;
```
