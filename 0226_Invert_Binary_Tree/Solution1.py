from typing import *
from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        l = self.invertTree(root.right)
        r = self.invertTree(root.left)
        root.left, root.right = l, r
        return root


def test(test_name, root, expected):
    res= Solution().invertTree(root)
    if is_equal_tree(res, expected):
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    #         4
    #       /  \
    #      2    7
    #     / \  / \
    #    1   3 6  9
    root1 = TreeNode(4)
    root1.left = TreeNode(2)
    root1.left.left = TreeNode(1)
    root1.left.right = TreeNode(3)
    root1.right = TreeNode(7)
    root1.right.left = TreeNode(6)
    root1.right.right = TreeNode(9)
    #         4
    #       /  \
    #      7    2
    #     / \  / \
    #    9   6 3  1
    expected1 = TreeNode(4)
    expected1.left = TreeNode(7)
    expected1.left.left = TreeNode(9)
    expected1.left.right = TreeNode(6)
    expected1.right = TreeNode(2)
    expected1.right.left = TreeNode(3)
    expected1.right.right = TreeNode(1)
    test('test1', root1, expected1)

    #     2
    #    / \
    #   1   3
    root2 = TreeNode(2)
    root2.left = TreeNode(1)
    root2.right = TreeNode(3)
    #    2
    #   / \
    #  3   1
    expected2 = TreeNode(2)
    expected2.left = TreeNode(3)
    expected2.right = TreeNode(1)
    test('test2', root2, expected2)

    root3 = None
    expected3 = None
    test('test3', root3, expected3)

