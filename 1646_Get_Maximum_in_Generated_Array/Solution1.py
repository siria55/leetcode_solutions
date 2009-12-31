class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        if n <= 1:
            return n
        res = 0
        arr = [0] * (n + 1)
        arr[1] = 1
        for i in range(2, n + 1):
            if i % 2 == 0:
                arr[i] = arr[i//2]
            else:
                arr[i] = arr[i//2] + arr[i//2 + 1]
            res = max(res, arr[i])
        return res


def test(test_name, n, expected):
    res = Solution().getMaximumGenerated(n)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    n1 = 7
    expected1 = 3
    test('test1', n1, expected1)

    n2 = 2
    expected2 = 1
    test('test2', n2, expected2)

    n3 = 3
    expected3 = 2
    test('test3', n3, expected3)

    n4 = 0
    expected4 = 0
    test('test4', n4, expected4)
