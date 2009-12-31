### Solution 1 by cases

- t-complexity: $O(n)$
- s-complexity: %O(1)%

three cases that will not self crossing:

- always out: dist[i] > dist[i-2]
- always in: dist[i] < dist[i-2]
- first out then in:

see graph at:
https://leetcode-cn.com/problems/self-crossing/solution/tong-ge-lai-shua-ti-la-san-chong-bu-xian-w80r/

