class Solution:
    def countDigitOne(self, n: int) -> int:
        res, digit = 0, 1
        while n // digit:
            high = n // (digit * 10)
            cur = (n // digit) % 10
            low = n - (n // digit) * digit

            res += high * digit
            if cur == 1:
                res += low + 1
            elif cur > 1:
                res += digit
            digit *= 10
        return res


def test(test_name, n, expected):
    res = Solution().countDigitOne(n)
    if res == expected:
        print(test_name + ' success.')
    else:
        print(test_name + ' failed.')


if __name__ == "__main__":

    n1 = 12
    expected1 = 5
    test("test1", n1, expected1)

    n2 = 13
    expected2 = 6
    test("test2", n2, expected2)

    n3 = 5014
    expected3 = 2507
    test('test3', n3, expected3)


# 输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

# 例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

# 示例 1：
# 输入：n = 12
# 输出：5

# 示例 2：
# 输入：n = 13
# 输出：6
#  

# 限制：
# 1 <= n < 2^31
