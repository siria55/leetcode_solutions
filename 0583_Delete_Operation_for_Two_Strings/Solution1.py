from typing import *


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        s1, s2 = len(word1), len(word2)
        dp = [[0] * (s2+1) for _ in range(s1+1)]

        for i in range(s1+1):
            dp[i][0] = i
        for j in range(s2+1):
            dp[0][j] = j

        for i in range(1, s1+1):
            for j in range(1, s2+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j-1] + 2, dp[i-1][j] + 1, dp[i][j-1] + 1)
        return dp[s1][s2]


def test(test_name, word1, word2, expected):
    res = Solution().minDistance(word1, word2)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')

if __name__ == '__main__':
    word11 = 'sea'
    word21 = 'eat'
    expected1 = 2
    test('test1', word11, word21, expected1)

    word12 = 'leetcode'
    word22 = 'etco'
    expected2 = 4
    test('test2', word12, word22, expected2)

