from typing import *


class Solution:
    def smallestK(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        return arr[:k]


def test(test_name, arr, k, expected):
    res = Solution().smallestK(arr, k)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    arr1 = [1,3,5,7,2,4,6,8]
    k1 = 4
    expected1 = [1,2,3,4]
    test('tset1', arr1, k1, expected1)
