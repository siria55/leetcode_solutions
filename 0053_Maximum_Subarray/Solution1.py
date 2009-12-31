from typing import *


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0] * n
        dp[0] = nums[0]

        for i in range(1, n):
            dp[i] = max(dp[i-1], 0) + nums[i]
        return max(dp)


def test(test_name, nums, expected):
    res = Solution().maxSubArray(nums)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == "__main__":
    nums1 = [-2,1,-3,4,-1,2,1,-5,4]
    expected1 = 6
    test('test1', nums1, expected1)

    nums2 = [1]
    expected2 = 1
    test('test2', nums2, expected2)

