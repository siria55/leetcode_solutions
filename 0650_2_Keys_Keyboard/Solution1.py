from typing import *


class Solution:
    def minSteps(self, n: int) -> int:
        dp = [0] * (n+1)
        for i in range(2, n+1):
            dp[i] = i
            j = 2
            while j * j <= i:
                if i % j == 0:
                    dp[i] = dp[j] + dp[int(i/j)]
                    break
                j += 1

        return dp[n]


def test(test_name, n, expected):
    res = Solution().minSteps(n)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')



if __name__ == '__main__':
    n1 = 3
    expected1 = 3
    test('test1', n1, expected1)

    n2 = 1
    expected2 = 0
    test('test2', n2, expected2)

    n3 = 4
    expected3 = 4
    test('test3', n3, expected3)

