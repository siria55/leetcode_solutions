from typing import *
from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def in_dfs(self, node):
        if not node:
            return
        self.in_dfs(node.left)
        node.left = None
        self.prev.right = node
        self.prev = node
        self.in_dfs(node.right)

    def increasingBST(self, root: TreeNode) -> TreeNode:
        dummy = TreeNode(0)
        self.prev = dummy
        self.in_dfs(root)
        return dummy.right


def test(test_name, root, expected):
    res = Solution().increasingBST(root)
    if is_equal_tree(res, expected):
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    #          5
    #        /   \
    #       3     6
    #      / \     \
    #     2   4     8
    #    /         / \
    #   1         7   9
    root1 = TreeNode(5)
    root1.left = TreeNode(3)
    root1.left.left = TreeNode(2)
    root1.left.left.left = TreeNode(1)
    root1.left.right = TreeNode(4)
    root1.right = TreeNode(6)
    root1.right.right = TreeNode(8)
    root1.right.right.left = TreeNode(7)
    root1.right.right.right = TreeNode(9)
    expected1 = TreeNode(1)
    expected1.right = TreeNode(2)
    expected1.right.right = TreeNode(3)
    expected1.right.right.right = TreeNode(4)
    expected1.right.right.right.right = TreeNode(5)
    expected1.right.right.right.right.right = TreeNode(6)
    expected1.right.right.right.right.right.right = TreeNode(7)
    expected1.right.right.right.right.right.right.right = TreeNode(8)
    expected1.right.right.right.right.right.right.right.right = TreeNode(9)
    test('test1', root1, expected1)

    #     5
    #    / \
    #   1   7
    root2 = TreeNode(5)
    root2.left = TreeNode(1)
    root2.right = TreeNode(7)
    expected2 = TreeNode(1)
    expected2.right = TreeNode(5)
    expected2.right.right = TreeNode(7)
    test('test2', root2, expected2)

