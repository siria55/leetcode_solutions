from typing import *


class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort()
        n = len(pairs)
        dp = [1] * n

        for i in range(1, n):
            for j in range(i):
                if pairs[j][1] < pairs[i][0]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)


def test(test_name, pairs, expected):
    res = Solution().findLongestChain(pairs)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    pairs1 = [[1,2],[2,3],[3,4]]
    expected1 = 2
    test('test1', pairs1, expected1)

    pairs2 = [[1,2],[7,8],[4,5]]
    expected2 = 3
    test('test2', pairs2, expected2)

