### Solution 1 Boyer-Moore Algorithm

- t-complexity: $O(N)$
- s-complexity: $O(1)$

If you aren't familiar with Boyer-Moore Algorithm, please read [this article](https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html) first.

since the requirement is finding the majority for more than floor of [n/3], the answer would be less than or equal to two numbers. So we can modify the algorithm to maintain two counters for two majorities.

majorities count in 1/2 could at most be 1.
majorities count in 1/3 could at most be 2.
...

