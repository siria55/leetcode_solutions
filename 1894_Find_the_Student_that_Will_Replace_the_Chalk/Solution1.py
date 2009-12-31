from typing import *


class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        _sum = sum(chalk)
        remainder = k % _sum
        N = len(chalk)
        for i in range(N):
            remainder -= chalk[i]
            if remainder < 0:
                return i


def test(test_name, chalk, k, expected):
    res = Solution().chalkReplacer(chalk, k)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    chalk1 = [5,1,5]
    k1 = 22
    expected1 = 0
    test('test1', chalk1, k1, expected1)

    chalk2 = [3,4,1,2]
    k2 = 25
    expected2 = 1
    test('test2', chalk2, k2, expected2)
