class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        dp = [0] * (n+1)
        dp[0] = 1
        dp[1] = 0 if s[0] == '0' else 1

        for i in range(1, n):
            first = int(s[i:i+1])
            second = int(s[i-1:i+1])
            if 1 <= first <= 9:
                dp[i+1] += dp[i]
            if 10 <= second <= 26:
                dp[i+1] += dp[i-1]
        return dp[-1]


def test(test_name, s, expected):
    res = Solution().numDecodings(s)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    s1 = '12'
    expected1 = 2
    test('test1', s1, expected1)

    s2 = '226'
    expected2 = 3
    test('test2', s2, expected2)

    s3 = '0'
    expected3 = 0
    test('test3', s3, expected3)

    s4 = '01'
    expected4 = 0
    test('test4', s4, expected4)

