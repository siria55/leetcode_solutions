class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n

        one_before = 2
        two_before = 1
        all_steps = 0
        for _ in range(2, n):
            all_steps = one_before + two_before
            two_before, one_before = one_before, all_steps
        return all_steps


def test(test_name, n, expected):
    res = Solution().climbStairs(n)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    n1 = 2
    expected1 = 2
    test('test1', n1, expected1)

    n2 = 3
    expected2 = 3
    test('test2', n2, expected2)

    n3 = 1
    expected3 = 1
    test('test3', n3, expected3)

