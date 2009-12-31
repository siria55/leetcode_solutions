class Solution:
    def trailingZeroes(self, n: int) -> int:
        res, base = 0, 5
        while n // base:
            res += n // base
            n //= base
        return res


def test(test_name, n, expected):
    res = Solution().trailingZeroes(n)
    if type(res) == type(expected) and res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == "__main__":
    n1, expected1 = 3, 0
    test('test1', n1, expected1)

    n2, expected2 = 5, 1
    test('test2', n2, expected2)

    n3, expected3 = 10, 2
    test('test3', n3, expected3)

    n4, expected4 = 30, 7
    test('test4', n4, expected4)
