from typing import *


class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 3:
            return 0

        dp = [0] * n
        for i in range(2, n):
            if nums[i] - nums[i-1] == nums[i-1] - nums[i-2]:
                dp[i] = dp[i-1] + 1
        return sum(dp)


def test(test_name, nums, expected):
    res = Solution().numberOfArithmeticSlices(nums)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    nums1 = [1,2,3,4]
    expected1 = 3
    test('test1', nums1, expected1)

    nums2 = [1]
    expected2 = 0
    test('test2', nums2, expected2)

