class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        N = len(s)
        dp = [[0] * N for _ in s]
        for i in range(N-1, -1, -1):
            dp[i][i] = 1
            for j in range(i+1, N):
                if s[i] == s[j]:
                    dp[i][j] = dp[i+1][j-1] + 2
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        return dp[0][N-1]


def test(test_name, s, expected):
    res = Solution().longestPalindromeSubseq(s)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    s1 = 'bbbab'
    expected1 = 4
    test('test1', s1, expected1)

    s2 = 'cbbd'
    expected2 = 2
    test('test2', s2, expected2)
