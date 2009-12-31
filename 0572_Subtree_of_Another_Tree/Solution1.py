from typing import *
from util_py.tree import *


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEqualTree(self, t1, t2):
        if not t1 and not t2:
            return True
        if not t1 or not t2:
            return False
        if t1.val != t2.val:
            return False
        return self.isEqualTree(t1.left, t2.left) and\
               self.isEqualTree(t1.right, t2.right)

    def isSubtree(self, root: TreeNode, subRoot: TreeNode) -> bool:
        if not subRoot:
            return True
        if not root:
            return False
        return self.isEqualTree(root, subRoot) or\
               self.isSubtree(root.left, subRoot) or \
               self.isSubtree(root.right, subRoot)


def test(test_name, root, subRoot, expected):
    res = Solution().isSubtree(root, subRoot)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    #      3
    #    /   \
    #   4     5
    #  / \
    # 1   2
    root1 = TreeNode(3)
    root1.left = TreeNode(4)
    root1.left.left = TreeNode(1)
    root1.left.right = TreeNode(2)
    root1.right = TreeNode(5)
    #   4
    #  / \
    # 1   2
    subRoot1 = TreeNode(4)
    subRoot1.left = TreeNode(1)
    subRoot1.right = TreeNode(2)
    expected1 = True
    test('test1', root1, subRoot1, expected1)

    #       3
    #     /   \
    #    4     5
    #   / \
    #  1   2
    #     /
    #    0
    root2 = TreeNode(3)
    root2.left = TreeNode(4)
    root2.left.left = TreeNode(1)
    root2.left.right = TreeNode(2)
    root2.left.right.left = TreeNode(0)
    root2.right = TreeNode(5)
    #    4
    #   / \
    #  1   2
    subRoot2 = subRoot1
    expected2 = False
    test('test2', root2, subRoot2, expected2)

