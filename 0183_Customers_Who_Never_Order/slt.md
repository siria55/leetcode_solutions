### Solution 1 left join 并用 is null过滤

```sql
SELECT C.name AS Customers
FROM Customers C LEFT JOIN Orders O
ON C.id=O.customerId
WHERE O.id IS NULL;
```

### Solution 2 Use sub-query

```sql
SELECT Name AS Customers
FROM Customers WHERE Id NOT IN(
    SELECT DISTINCT CustomerId FROM Orders
);
```

