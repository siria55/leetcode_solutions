from typing import *


class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        N = len(nums)
        res = 0
        for i in range(N-2):
            d = nums[i+1] - nums[i]
            for j in range(i+1, N-1):
                if nums[j+1] - nums[j] == d:
                    res += 1
                else:
                    break     # 若 nums[j+1] - nums[j] 不满足，则后面的都不满足了

        return res


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
