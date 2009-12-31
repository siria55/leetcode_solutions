from typing import *
from collections import defaultdict

class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        res = 0
        # 压缩 f[i][d] 的第二维为哈希表
        f = [defaultdict(int) for _ in nums]
        for i, n in enumerate(nums):
            for j in range(i):
                d = n - nums[j]
                res += f[j][d]
                f[i][d] += f[j][d] + 1
        return res


def test(test_name, nums, expected):
    res = Solution().numberOfArithmeticSlices(nums)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    nums1 = [2,4,6,8,10]
    expected1 = 7
    test('test1', nums1, expected1)

    nums2 = [7,7,7,7,7]
    expected2 = 16
    test('test2', nums2, expected2)
