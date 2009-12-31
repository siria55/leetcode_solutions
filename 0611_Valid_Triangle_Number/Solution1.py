from typing import *

class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        res = 0
        for i in range(2, len(nums)):
            l, r = 0, i - 1
            while l < r:
                if nums[l] + nums[r] > nums[i]:
                    res += r - l
                    r -= 1
                else:
                    l += 1
        return res


def test(test_name, nums, expected):
    res = Solution().triangleNumber(nums)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    nums1 = [2,2,3,4]
    expected1 = 3
    test('test1', nums1, expected1)

    nums2 = [4,2,3,4]
    expected2 = 4
    test('test2', nums2, expected2)
