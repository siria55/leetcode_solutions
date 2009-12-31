from typing import *
from util_py.tree import *
from util_py.list import *

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, head, tail):
        if head == tail:
            return None

        fast, slow = head, head
        while fast != tail and fast.next != tail:
            fast = fast.next.next
            slow = slow.next
        node = TreeNode(slow.val)
        node.left = self.buildTree(head, slow)
        node.right = self.buildTree(slow.next, tail)
        return node

    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        return self.buildTree(head, None)


def test(test_name, head):
    res_t = Solution().sortedListToBST(head)
    in_head = get_built_in_list(head)
    in_tree = get_inorder_list(res_t)
    if in_head == in_tree and is_balanced_tree(res_t):
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    head1 = build_list([-10,-3,0,5,9])
    test('test1', head1)

    head2 = build_list([])
    test('test2', head2)

