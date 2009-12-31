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
        if (root.val - p.val) * (root.val - q.val) <= 0:
            return root
        node = root.left if root.val > p.val else root.right
        return self.lowestCommonAncestor(node, p, q)


def test(test_name, root, p, q, expected):
    res = Solution().lowestCommonAncestor(root, p, q)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    #         6
    #       /   \
    #      2     8
    #     / \   / \
    #    0   4 7   9
    #       / \
    #      3   5
    root1 = TreeNode(6)
    root1.left = TreeNode(2)
    root1.left.left = TreeNode(0)
    root1.left.right = TreeNode(4)
    root1.left.right.left = TreeNode(3)
    root1.left.right.right = TreeNode(5)
    root1.right = TreeNode(8)
    root1.right.left = TreeNode(7)
    root1.right.right = TreeNode(9)
    p1 = root1.left       # 2
    q1 = root1.right      # 8
    expected1 = root1     # 6
    test('test1', root1, p1, q1, root1)

    #         6
    #       /   \
    #      2     8
    #     / \   / \
    #    0   4 7   9
    #       / \
    #      3   5
    root2 = TreeNode(6)
    root2.left = TreeNode(2)
    root2.left.left = TreeNode(0)
    root2.left.right = TreeNode(4)
    root2.left.right.left = TreeNode(3)
    root2.left.right.right = TreeNode(5)
    root2.right = TreeNode(8)
    root2.right.left = TreeNode(7)
    root2.right.right = TreeNode(9)
    p2 = root2.left          # 2
    q2 = root2.left.right    # 4
    expected2 = root2.left   # 2
    test('test2', root2, p2, q2, expected2)

    root3 = TreeNode(2)
    root3.left = TreeNode(1)
    p3 = root3
    q3 = root3.left
    expected3 = root3
    test('test3', root3, p3, q3, expected3)

