from typing import *
from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def trimBST(self, root: Optional[TreeNode], low: int, high: int) -> Optional[TreeNode]:
        if not root:
            return None
        if root.val < low:
            return self.trimBST(root.right, low, high)
        if root.val > high:
            return self.trimBST(root.left, low, high)
        root.left = self.trimBST(root.left, low, high)
        root.right = self.trimBST(root.right, low, high)
        return root


def test(test_name, root, low, high, expected):
    res = Solution().trimBST(root, low, high)
    if is_equal_tree(res, expected):
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    #      1
    #     / \
    #    0   2
    root1 = TreeNode(1)
    root1.left = TreeNode(0)
    root1.right = TreeNode(2)
    low1, high1 = 1, 2
    #      1
    #       \
    #        2
    expected1 = TreeNode(1)
    expected1.right = TreeNode(2)
    test('test1', root1, low1, high1, expected1)

    #       3
    #      / \
    #     0   4
    #      \
    #       2
    #      /
    #     1
    root2 = TreeNode(3)
    root2.left = TreeNode(0)
    root2.left.right = TreeNode(2)
    root2.left.right.left = TreeNode(1)
    root2.right = TreeNode(4)
    low2, high2 = 1, 3
    #        3
    #       /
    #      2
    #     /
    #    1
    expected2 = TreeNode(3)
    expected2.left = TreeNode(2)
    expected2.left.left = TreeNode(1)
    test('test2', root2, low2, high2, expected2)

