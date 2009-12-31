class Solution:
    def balancedStringSplit(self, s: str) -> int:
        res, L_count = 0, 0
        for ch in s:
            if ch == 'L': L_count += 1
            else: L_count -= 1
            if L_count == 0:
                res += 1
        return res


def test(test_name, s, expected):
    res = Solution().balancedStringSplit(s)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    s1 = 'RLRRLLRLRL'
    expected1 = 4
    test('test1', s1, expected1)

    s2 = 'RLLLLRRRLR'
    expected2 = 3
    test('test2', s2, expected2)

    s3 = 'LLLLRRRR'
    expected3 = 1
    test('test3', s3, expected3)

    s4 = 'RLRRRLLRLL'
    exepcted4 = 2
    test('test4', s4, exepcted4)
