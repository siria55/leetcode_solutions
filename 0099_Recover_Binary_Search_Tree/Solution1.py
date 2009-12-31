from typing import *
from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorder(self, node):
        if node.left:
            self.inorder(node.left)

        if self.prev and self.prev.val > node.val:
            if self.mistaka1:
                self.mistaka2 = node
            else:
                self.mistaka1 = self.prev
                self.mistaka2 = node
        self.prev = node

        if node.right:
            self.inorder(node.right)

    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.prev = None
        self.mistaka1, self.mistaka2 = None, None
        self.inorder(root)
        self.mistaka1.val, self.mistaka2.val = self.mistaka2.val, self.mistaka1.val


def test(test_name, root, expected):
    Solution().recoverTree(root)
    if is_equal_tree(root, expected):
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')

if __name__ == '__main__':

    #     1
    #    /
    #   3
    #    \
    #     2
    root1 = TreeNode(1)
    root1.left = TreeNode(3)
    root1.left.right = TreeNode(2)

    #     3
    #    /
    #   1
    #    \
    #     2
    expected1 = TreeNode(3)
    expected1.left = TreeNode(1)
    expected1.left.right = TreeNode(2)
    test('test1', root1, expected1)

    #     3
    #    / \
    #   1   4
    #      /
    #     2
    root2 = TreeNode(3)
    root2.left = TreeNode(1)
    root2.right = TreeNode(4)
    root2.right.left = TreeNode(2)

    #      2
    #     / \
    #    1   4
    #       /
    #      3
    expected2 = TreeNode(2)
    expected2.left = TreeNode(1)
    expected2.right = TreeNode(4)
    expected2.right.left = TreeNode(3)
    test('test2', root2, expected2)

