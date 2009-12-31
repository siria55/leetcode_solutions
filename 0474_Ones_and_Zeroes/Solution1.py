from typing import *


class Solution:
    def get_count(self, s):
        c0, c1 = len(s), 0
        for c in s:
            if c == '1':
                c0 -= 1
                c1 += 1
        return c0, c1

    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = [[0] * (n+1) for _ in range(m+1)]
        for s in strs:
            c0, c1 = self.get_count(s)
            for i in range(m, c0-1, -1):
                for j in range(n, c1-1, -1):
                    dp[i][j] = max(dp[i][j], 1 + dp[i-c0][j-c1])
        return dp[m][n]


def test(test_name, strs, m, n, expected):
    res = Solution().findMaxForm(strs, m, n)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    strs1 = ['10','0001','111001','1','0']
    m1, n1 = 5, 3
    expected1 = 4
    test('test1', strs1, m1, n1, expected1)

    strs2 = ['10','0','1']
    m2, n2 = 1, 1
    expected2 = 2
    test('test2', strs2, m2, n2, expected2)

