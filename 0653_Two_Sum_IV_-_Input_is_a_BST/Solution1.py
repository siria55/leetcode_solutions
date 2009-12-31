from typing import *
from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inDFS(self, node):
        if not node:
            return False

        if self.inDFS(node.left):
            return True

        n2find = self.k - node.val
        if n2find in self.occured:
            return True
        self.occured.add(node.val)

        if self.inDFS(node.right):
            return True
        return False

    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        self.occured = set()
        self.k = k
        return self.inDFS(root)


def test(test_name, root, k, expected):
    res = Solution().findTarget(root, k)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    #       5
    #     /   \
    #    3     6
    #   / \     \
    #  2   4     7
    root1 = TreeNode(5)
    root1.left = TreeNode(3)
    root1.left.left = TreeNode(2)
    root1.left.right = TreeNode(4)
    root1.right = TreeNode(6)
    root1.right.right = TreeNode(7)
    k1 = 9
    expected1 = True
    test('test1', root1, k1, expected1)

    root2 = root1
    k2 = 28
    expected2 = False
    test('test2', root2, k2, expected2)

