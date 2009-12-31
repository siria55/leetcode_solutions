from typing import *
from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    cur_sum = 0

    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return
        self.convertBST(root.right)
        v = root.val
        root.val += self.cur_sum
        self.cur_sum += v
        self.convertBST(root.left)
        return root


def test(test_name, root, expected):
    res = Solution().convertBST(root)
    if is_equal_tree(res, expected):
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    #        4
    #      /   \
    #     1     6
    #    / \   / \
    #   0   2 5   7
    #        \     \
    #         3     8
    root1 = TreeNode(4)
    root1.left = TreeNode(1)
    root1.left.left = TreeNode(0)
    root1.left.right = TreeNode(2)
    root1.left.right.right = TreeNode(3)
    root1.right = TreeNode(6)
    root1.right.left = TreeNode(5)
    root1.right.right = TreeNode(7)
    root1.right.right.right = TreeNode(8)
    #       30
    #     /    \
    #    36     21
    #   /  \   /  \
    #  36  35 26  15
    #        \      \
    #         33     8
    expected1 = TreeNode(30)
    expected1.left = TreeNode(36)
    expected1.left.left = TreeNode(36)
    expected1.left.right = TreeNode(35)
    expected1.left.right.right = TreeNode(33)
    expected1.right = TreeNode(21)
    expected1.right.left = TreeNode(26)
    expected1.right.right = TreeNode(15)
    expected1.right.right.right = TreeNode(8)
    test('test1', root1, expected1)

    #     0
    #      \
    #       1
    root2 = TreeNode(0)
    root2.right = TreeNode(1)
    #     1
    #      \
    #       1
    expected2 = TreeNode(1)
    expected2.right = TreeNode(1)
    test('test2', root2, expected2)

