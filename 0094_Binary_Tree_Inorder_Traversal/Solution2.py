from typing import *
from util_py.tree import *
from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        if not root:
            return res
        stk = deque()
        p = root
        while len(stk) or p:
            while p:
                stk.append(p)
                p = p.left
            p = stk.pop()
            res.append(p.val)
            p = p.right
        return res


def test(test_name, root, expected):
    res = Solution().inorderTraversal(root)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == "__main__":
    root1 = TreeNode(1)
    root1.right = TreeNode(2)
    root1.right.left = TreeNode(3)
    expected1 = [1,3,2]
    test('test1', root1, expected1)

