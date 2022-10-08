from typing import *


class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        size = len(nums)
        if size <= 1:
            return True

        moded = nums[0] > nums[1]
        for i in range(1, size-1):
            if nums[i] <= nums[i+1]:
                continue
            if moded:
                return False
            if nums[i-1] <= nums[i+1]:
                nums[i] = nums[i+1]
            else:
                nums[i+1] = nums[i]
            moded = True
        return True


def test(test_name, nums, expected):
    res = Solution().checkPossibility(nums)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    nums1 = [4,2,3]
    expected1 = True
    test('test1', nums1, expected1)

    nums2 = [4,2,1]
    expected2 = False
    test('test2', nums2, expected2)

    nums3 = [3,4,2,3]
    expected3 = False
    test('test3', nums3, expected3)
