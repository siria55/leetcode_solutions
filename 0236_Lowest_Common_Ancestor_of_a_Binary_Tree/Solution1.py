from typing import *
from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root:
            return
        if p == root or q == root:
            return root
        l = self.lowestCommonAncestor(root.left, p, q)
        r = self.lowestCommonAncestor(root.right, p, q)
        if not l:
            return r
        if not r:
            return l
        return root


def test(test_name, root, p, q, expected):
    res = Solution().lowestCommonAncestor(root, p, q)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    #        3
    #      /   \
    #     5     1
    #    / \   / \
    #   6   2 0   8
    #      / \
    #     7   4
    root1 = TreeNode(3)
    root1.left = TreeNode(5)
    root1.left.left = TreeNode(6)
    root1.left.right = TreeNode(2)
    root1.left.right.left = TreeNode(7)
    root1.left.right.right = TreeNode(4)
    root1.right = TreeNode(1)
    root1.right.left = TreeNode(0)
    root1.right.right = TreeNode(8)
    p1 = root1.left
    q1 = root1.right
    expected1 = root1
    test('tset1', root1, p1, q1, expected1)

    root2 = root1
    p2 = root2.left
    q2 = root2.left.right.right.right
    expected2 = root2.left
    test('test2', root2, p2, q2, expected2)

    root3 = TreeNode(1)
    root3.left = TreeNode(2)
    p3 = root3
    q3 = root3.left
    expected3 = root3
    test('test3', root3, p3, q3, expected3)

