class Solution:
    def checkRecord(self, n: int) -> int:
        MOD = 10 ** 9 + 7

        dp = [[[0 for _ in range(3)] for _ in range(2)] for _ in range(n+1)]
        dp[0][0][0] = 1

        for i in range(1, n+1):
            # current day is P
            for j in range(2):
                for k in range(3):
                    dp[i][j][0] += dp[i-1][j][k]
                    dp[i][j][0] %= MOD

            # current day is L
            for j in range(2):
                for k in range(1, 3):
                    dp[i][j][k] += dp[i-1][j][k-1]
                    dp[i][j][k] %= MOD

            # current day is A
            for k in range(3):
                dp[i][1][0] += dp[i-1][0][k]
                dp[i][1][0] %= MOD

        res = 0
        for absent in range(2):
            for last_late in range(3):
                res = (res + dp[n][absent][last_late]) % MOD
        return res % MOD



def test(test_name, n, expected):
    res = Solution().checkRecord(n)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    n1 = 2
    expected1 = 8
    test('test1', n1, expected1)

    n2 = 1
    expected2 = 3
    test('test2', n2, expected2)

    n3 = 10101
    expected3 = 183236316
    test('test3', n3, expected3)
