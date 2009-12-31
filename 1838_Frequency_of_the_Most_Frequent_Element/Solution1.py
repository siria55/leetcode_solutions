from typing import *


class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        pre_sum = [0] * (len(nums) + 1)
        for i in range(1, len(nums)+1):
            pre_sum[i] = pre_sum[i-1] + nums[i-1]

        res = 0
        for i in range(len(nums)):
            l, r = 0, i
            cur = -1
            while l <= r:
                m = l + (r-l) // 2
                area = nums[i] * (i - m + 1) - (pre_sum[i+1] - pre_sum[m])
                if area > k:
                    l = m + 1
                else:
                    cur = m
                    r = m - 1
            if cur != -1:
                res = max(res, i - cur + 1)
        return res


def test(test_name, nums, k, expected):
    res = Solution().maxFrequency(nums, k)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    nums1 = [1,2,4]
    k1 = 5
    expected1 = 3
    test('test1', nums1, k1, expected1)

    nums2 = [1,4,8,13]
    k2 = 5
    expected2 = 2
    test('test2', nums2, k2, expected2)

    nums3 = [3,9,6]
    k3 = 2
    expected3 = 1
    test('test3', nums3, k3, expected3)
