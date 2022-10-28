from typing import *
from util_py.list import *


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast, slow = head, head
        if not (fast and fast.next):
            return None
        fast = fast.next.next
        slow = slow.next
        while fast != slow:
            if not (fast and fast.next):
                return None
            fast = fast.next.next
            slow = slow.next
        fast = head
        while fast != slow:
            fast = fast.next
            slow = slow.next
        return slow


def test(test_name, head, expected):
    res = Solution().detectCycle(head)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    head1 = build_list([3,2,0,-4])
    head1.next.next.next.next = head1.next
    expected1 = head1.next
    test('test1', head1, expected1)

    head2 = build_list([1,2])
    head2.next.next = head2
    expected2 = head2
    test('test2', head2, expected2)
    
    head3 = build_list([1])
    expected3 = None
    test('test3', head3, expected3)
