from typing import *


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n
        max_len = 1

        for i in range(n):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
            max_len = max(max_len, dp[i])
        return max_len


def test(test_name, nums, expected):
    res = Solution().lengthOfLIS(nums)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    nums1 = [10,9,2,5,3,7,101,18]
    expected1 = 4
    test('test1', nums1, expected1)

    nums2 = [0,1,0,3,2,3]
    expected2 = 4
    test('test2', nums2, expected2)

    nums3 = [7,7,7,7,7,7,7]
    expected3 = 1
    test('test3', nums3, expected3)

