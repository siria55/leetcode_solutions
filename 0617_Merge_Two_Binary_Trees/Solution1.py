from typing import *
from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, root1: TreeNode, root2: TreeNode) -> TreeNode:
        if not root1 or not root2:
            return root1 or root2

        root1.val += root2.val
        root1.left = self.mergeTrees(root1.left, root2.left)
        root1.right = self.mergeTrees(root1.right, root2.right)
        return root1


def test(test_name, root1, root2, expected):
    res = Solution().mergeTrees(root1, root2)
    if is_equal_tree(res, expected):
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    #       1
    #     /   \
    #    3     2
    #   /
    #  5
    root11 = TreeNode(1)
    root11.left = TreeNode(3)
    root11.left.left = TreeNode(5)
    root11.right = TreeNode(2)
    #       2
    #     /   \
    #    1     3
    #     \     \
    #      4     7
    root21 = TreeNode(2)
    root21.left = TreeNode(1)
    root21.left.right = TreeNode(4)
    root21.right = TreeNode(3)
    root21.right.right = TreeNode(7)
    #        3
    #      /   \
    #     4     5
    #    / \     \
    #   5   4     7
    expected1 = TreeNode(3)
    expected1.left = TreeNode(4)
    expected1.left.left = TreeNode(5)
    expected1.left.right = TreeNode(4)
    expected1.right = TreeNode(5)
    expected1.right.right = TreeNode(7)
    test('test1', root11, root21, expected1)

    #    1
    root12 = TreeNode(1)
    #    1
    #   /
    #  2
    root22 = TreeNode(1)
    root22.left = TreeNode(2)
    #    2
    #   /
    #  2
    expected2 = TreeNode(2)
    expected2.left = TreeNode(2)
    test("test2", root12, root22, expected2)

