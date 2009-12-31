class Solution:
    def integerBreak(self, n: int) -> int:
        dp = [0] * (n+1)
        dp[0] = dp[1] = 1

        for i in range(2, n+1):
            for j in range(1, i):
                dp[i] = max(dp[i], j * (i-j), j * dp[i-j])
        return dp[n]


def test(test_name, n, expected):
    res = Solution().integerBreak(n)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    n1 = 2
    expected1 = 1
    test('test1', n1, expected1)

    n2 = 10
    expected2 = 36
    test('test2', n2, expected2)

