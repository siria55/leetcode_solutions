from typing import *
import math

class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        maxn, minn = -math.inf, math.inf
        l, r = -1, -1
        for i in range(len(nums)):
            if nums[i] >= maxn:
                maxn = nums[i]
            else:
                r = i
            if nums[len(nums)-i-1] <= minn:
                minn = nums[len(nums)-i-1]
            else:
                l = len(nums)-i-1
        return 0 if l == -1 else r - l + 1


def test(test_name, nums, expected):
    res = Solution().findUnsortedSubarray(nums)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    nums1 = [2,6,4,8,10,9,15]
    expected1 = 5
    test('test1', nums1, expected1)

    nums2 = [1,2,3,4]
    expected2 = 0
    test('test2', nums2, expected2)

    nums3 = [1]
    expected3 = 0
    test('test3', nums3, expected3)
