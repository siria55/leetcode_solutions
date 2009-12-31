### 思路1 使用WHERE子句

```sql
SELECT
    score,
    (SELECT COUNT(DISTINCT score) FROM Scores WHERE score >= s.score) AS `rank`
FROM Scores AS s
ORDER BY score DESC;
```

对于外部SELECT的每一条score，我们再用内部的SELECT，统计scores表中有多少个比外部记录大的记录的个数。

### 思路2 JOIN

```sql
SELECT s1.Score, COUNT(DISTINCT(s2.Score)) AS Rank
FROM Scores s1 JOIN Scores s2
WHERE s1.score<=s2.score
GROUP BY s1.Id
ORDER BY Rank;
```

