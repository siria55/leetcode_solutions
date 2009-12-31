from typing import *
from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    res, pre = float('inf'), -1

    def dfs(self, node):
        if not node:
            return
        self.dfs(node.left)
        if self.pre != -1:
            self.res = min(self.res, abs(node.val - self.pre))
        self.pre = node.val
        self.dfs(node.right)

    def getMinimumDifference(self, root: TreeNode) -> int:
        self.dfs(root)
        return self.res


def test(test_name, root, expected):
    res = Solution().getMinimumDifference(root)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    #      4
    #     / \
    #    2   6
    #   / \
    #  1   3
    root1 = TreeNode(4)
    root1.left = TreeNode(2)
    root1.left.left = TreeNode(1)
    root1.left.right = TreeNode(3)
    root1.right = TreeNode(6)
    expected1 = 1
    test('test1', root1, expected1)

    #       1
    #     /  \
    #    0   48
    #       /  \
    #      12  49
    root2 = TreeNode(1)
    root2.left = TreeNode(0)
    root2.right = TreeNode(48)
    root2.right.left = TreeNode(12)
    root2.right.right = TreeNode(49)
    expected2 = 1
    test('test2', root2, expected2)

