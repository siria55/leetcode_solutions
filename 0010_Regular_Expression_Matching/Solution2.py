from typing import *


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        dp = [[False] * (n+1) for _ in range(m+1)]
        dp[0][0] = True

        for i in range(1, m+1):
            dp[i][0] = False

        for j in range(1, n+1):
            dp[0][j] = j > 1 and p[j-1] == '*' and dp[0][j-2]

        for i in range(1, m+1):
            for j in range(1, n+1):
                if p[j-1] != '*':
                    dp[i][j] = dp[i-1][j-1] and p[j-1] in (s[i-1], '.')
                else:
                    dp[i][j] = dp[i][j-2] or (p[j-2] in (s[i-1], '.')) and dp[i-1][j]
        return dp[m][n]


def test(test_name, s, p, expected):
    res = Solution().isMatch(s, p)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    s1 = 'aa'
    p1 = 'a'
    expected1 = False
    test('test1', s1, p1, expected1)

    s2 = 'aa'
    p2 = 'a*'
    expected2 = True
    test('test2', s2, p2, expected2)

    s3 = 'ab'
    p3 = '.*'             # '.*' means 'zero or more (*) of any character (.)'
    expected3 = True
    test('test3', s3, p3, expected3)

    s4 = 'aab'
    p4 = 'c*a*b'
    expected4 = True
    test('test4', s4, p4, expected4)

    s5 = 'mississippi'
    p5 = 'mis*is*p*.'
    expected5 = False
    test('test5', s5, p5, expected5)

