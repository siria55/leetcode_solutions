from typing import *
from util_py.list import *

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: ListNode, k: int) -> List[ListNode]:
        p = head
        N = 0
        while p:
            N += 1
            p = p.next

        each_len, remainder = divmod(N, k)
        res = []
        p = head
        while p:
            cur_head = p
            for i in range(each_len-1):
                p = p.next
            if remainder > 0 and each_len > 0:
                p = p.next
                remainder -= 1
            if not p:
                res.append(None)
                continue

            last = p
            p = p.next
            last.next = None
            res.append(cur_head)
        return res + (k - len(res)) * [None]


def test(test_name, head, k, expected):
    res = Solution().splitListToParts(head, k)
    success = True
    if len(res) == len(expected):
        for i in range(len(expected)):
            if not is_equal_list(res[i], expected[i]):
                success = False
                break
    else:
        success = False

    if success:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    head1 = build_list([1,2,3])
    k1 = 5
    expected1 = [build_list([1]), build_list([2]), build_list([3]), None, None]
    test('test1', head1, k1, expected1)

    head2 = build_list([1,2,3,4,5,6,7,8,9,10])
    k2 = 3
    expected2 = [build_list(item) for item in [[1,2,3,4],[5,6,7],[8,9,10]]]
    test('test2', head2, k2, expected2)
