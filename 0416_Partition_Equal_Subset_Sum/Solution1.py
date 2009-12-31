from typing import *


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s = sum(nums)
        if s % 2:
            return False

        target = s // 2
        n = len(nums)
        dp = [[False] * (target+1) for _ in range(n+1)]
        dp[0][0] = True

        for i in range(1, n+1):
            for j in range(target+1):
                if j < nums[i-1]:
                    dp[i][j] = dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i-1]]
        return dp[n][target]


def test(test_name, nums, expected):
    res = Solution().canPartition(nums)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    nums1 = [1,5,11,5]
    expected1 = True
    test('test1', nums1, expected1)

    nums2 = [1,2,3,5]
    expected2 = False
    test('test2', nums2, expected2)

