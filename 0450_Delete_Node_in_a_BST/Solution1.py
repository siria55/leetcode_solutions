from typing import *
from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root:
            return
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
        if key > root.val:
            root.right = self.deleteNode(root.right, key)
        if key == root.val:
            if not root.left:
                return root.right
            if not root.right:
                return root.left
            left_most = root.right
            while left_most.left:
                left_most = left_most.left
            left_most.left = root.left
            root = root.right
        return root


def test(test_name, root, key):
    old_l = get_inorder_list(root)
    res_t = Solution().deleteNode(root, key)
    new_l = get_inorder_list(res_t)
    if key in old_l:
        old_l.remove(key)
    if old_l == new_l:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    #       5
    #     /   \
    #    3     6
    #   / \     \
    #  2   4     7
    root1 = TreeNode(5)
    root1.left = TreeNode(3)
    root1.left.left = TreeNode(2)
    root1.left.right = TreeNode(4)
    root1.right = TreeNode(6)
    root1.right.right = TreeNode(7)
    key1 = 3
    test('test1', root1, key1)

    #       5
    #     /   \
    #    3     6
    #   / \     \
    #  2   4     7
    root2 = TreeNode(5)
    root2.left = TreeNode(3)
    root2.left.left = TreeNode(2)
    root2.left.right = TreeNode(4)
    root2.right = TreeNode(6)
    root2.right.right = TreeNode(7)
    key2 = 0
    test('test2', root2, key2)

    root3 = None
    key3 = 0
    test('test3', root3, key3)

