from typing import *

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l, r = 0 , len(nums) - 1
        while l < r:
            m = l + (r - l) // 2
            if nums[m] < nums[m+1]:
                l = m + 1
            else:
                r = m
        return l


def test(test_name, nums, expected):
    res = Solution().findPeakElement(nums)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    nums1 = [1,2,3,1]
    expected1 = 2
    test('test1', nums1, expected1)

    nums2 = [1,2,1,3,5,6,4]
    expected2 = 5
    test('test2', nums2, expected2)
