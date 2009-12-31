from typing import *
from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        res = 0
        if not root:
            return res
        if (root.left and
                not root.left.left and
                not root.left.right):
            res += root.left.val

        res += self.sumOfLeftLeaves(root.left)
        res += self.sumOfLeftLeaves(root.right)
        return res


def test(test_name, root, expected):
    res = Solution().sumOfLeftLeaves(root)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    #      3
    #    /   \
    #   9    20
    #       /  \
    #      15   7
    root1 = TreeNode(3)
    root1.left = TreeNode(9)
    root1.right = TreeNode(20)
    root1.right.left = TreeNode(15)
    root1.right.right = TreeNode(7)
    expected1 = 24
    test('test1', root1, expected1)

    root2 = TreeNode(1)
    expected2 = 0
    test('test2', root2, expected2)

