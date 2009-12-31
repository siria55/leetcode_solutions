from typing import *

class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        mined_max_pair_sum = 0
        nums.sort()

        l, r = 0, len(nums) - 1
        while l < r:
            cur_pair_sum = nums[l] + nums[r]
            mined_max_pair_sum = max(mined_max_pair_sum, cur_pair_sum)
            l += 1
            r -= 1

        return mined_max_pair_sum


def test(test_name, nums, expected):
    res = Solution().minPairSum(nums)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    nums1 = [3,5,2,3]
    expected1 = 7
    test('test1', nums1, expected1)

    nums2 = [3,5,4,2,4,6]
    expected2 = 8
    test('test2', nums2, expected2)
