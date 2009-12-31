from typing import *
from collections import deque
from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        res = root.val
        q = deque()
        q.append(root)
        while q:
            cnt = len(q)
            for i in range(cnt):
                node = q.popleft()
                if i == 0:
                    res = node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        return res


def test(test_name, root, expected):
    res = Solution().findBottomLeftValue(root)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    #    2
    #   / \
    #  1   3
    root1 = TreeNode(2)
    root1.left = TreeNode(1)
    root1.right = TreeNode(3)
    expected1 = 1
    test('test1', root1, expected1)

    #      1
    #    /   \
    #   2     3
    #  /     / \
    # 4     5   6
    #      /
    #     7
    root2 = TreeNode(1)
    root2.left = TreeNode(2)
    root2.left.left = TreeNode(4)
    root2.right = TreeNode(3)
    root2.right.left = TreeNode(5)
    root2.right.left.left = TreeNode(7)
    root2.right.right = TreeNode(6)
    expected2 = 7
    test('test2', root2, expected2)

