from typing import *
from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        if not root:
            return res

        stk = [root]
        while len(stk):
            node = stk.pop()
            res.append(node.val)
            if node.right:
                stk.append(node.right)
            if node.left:
                stk.append(node.left)
        return res


def test(test_name, root, expected):
    res = Solution().preorderTraversal(root)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == "__main__":
    # 1
    #  \
    #   2
    #  /
    # 3
    root1 = TreeNode(1)
    root1.right = TreeNode(2)
    root1.right.left = TreeNode(3)
    expected1 = [1,2,3]
    test("test1", root1, expected1)

    #   1
    #  /
    # 2
    root2 = TreeNode(1)
    root2.left = TreeNode(2)
    expected2 = [1,2]
    test("test2", root2, expected2)

