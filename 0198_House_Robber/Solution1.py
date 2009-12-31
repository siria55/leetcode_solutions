from typing import *

class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]

        dp = [0] * n
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])
        for i in range(2, n):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i])
        return dp[-1]


def test(test_name, nums, expected):
    res = Solution().rob(nums)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    nums1 = [1,2,3,1]
    expected1 = 4
    test('test1', nums1, expected1)

    nums2 = [2,7,9,3,1]
    expected2 = 12
    test('test2', nums2, expected2)

    nums3 = [2,1,1,2]
    expected3 = 4
    test('test3', nums3, expected3)

