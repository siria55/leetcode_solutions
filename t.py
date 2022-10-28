from typing import *

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        p1, p2, k = m - 1, n - 1, m + n - 1
        while p1 >= 0 and p2 >= 0:
            if nums1[p1] >= nums2[p2]:
                nums1[k] = nums1[p1]
                p1 -= 1
            else:
                nums1[k] = nums2[p2]
                p2 -= 1
            k -= 1
        while p2 >= 0:
            nums1[k] = nums2[p2]
            p2 -= 1
            k -= 1


def test(test_name, nums1, m, nums2, n, expected):
    Solution().merge(nums1, m, nums2, n)
    if nums1 == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    nums11 = [1,2,3,0,0,0]
    m1 = 3
    nums21 = [2,5,6]
    n1 = 3
    expected1 = [1,2,2,3,5,6]
    test('test1', nums11, m1, nums21, n1, expected1)
