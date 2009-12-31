from typing import *


class Solution:
    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        ranges.sort()
        for i in range(left, right + 1):
            covered = False
            for ran in ranges:
                if ran[0] <= i <= ran[1]:
                    covered = True
                    break
            if covered == False:
                return False
        return True


def test(test_name, ranges, left, right, expected):
    res = Solution().isCovered(ranges, left, right)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    ranges1 = [[1,2],[3,4],[5,6]]
    left1 = 2
    right1 = 5
    expected1 = True
    test('test1', ranges1, left1, right1, expected1)

    ranges2 = [[1,10],[10,20]]
    left2 = 21
    right2 = 21
    expected2 = False
    test('test2', ranges2, left2, right2, expected2)

    ranges3 = [[1,1]]
    left3 = 1
    right3 = 50
    expected3 = False
    test('test3', ranges3, left3, right3, expected3)

