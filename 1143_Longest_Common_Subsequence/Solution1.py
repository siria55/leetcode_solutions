class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        dp = [[0] * (n+1) for _ in range(m+1)]

        for i in range(1, m+1):
            for j in range(1, n+1):
                if text1[i-1] == text2[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j])

        return dp[-1][-1]


def test(test_name, text1, text2, expected):
    res = Solution().longestCommonSubsequence(text1, text2)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')

if __name__ == '__main__':
    text11 = 'abcde'
    text21 = 'ace'
    expected1 = 3
    test('test1', text11, text21, expected1)

    text12 = 'abc'
    text22 = 'abc'
    expected2 = 3
    test('test2', text12, text22, expected2)

    text13 = 'abc'
    text23 = 'def'
    expected3 = 0
    test('test3', text13, text23, expected3)

    text14 = 'bsbininm'
    text24 = 'jmjkbkjkv'
    expected4 = 1
    test('test4', text14, text24, expected4)

