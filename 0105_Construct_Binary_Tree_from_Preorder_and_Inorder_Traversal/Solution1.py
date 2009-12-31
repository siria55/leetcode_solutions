from typing import *
from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def builder(self, in2idx, preorder, sin, ein, spre):
        if sin > ein:
            return
        mid_val = preorder[spre]
        mid_idx = in2idx[mid_val]
        left_count = mid_idx - sin

        node = TreeNode(mid_val)
        node.left = self.builder(in2idx, preorder, sin, mid_idx-1, spre+1)
        node.right = self.builder(in2idx, preorder, mid_idx+1, ein, spre+1+left_count)
        return node

    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        in2idx = {}
        _len = len(preorder)
        for i in range(_len):
            in2idx[inorder[i]] = i
        return self.builder(in2idx, preorder, 0, _len-1, 0)


def test(test_name, preorder, inorder, expected):
    res = Solution().buildTree(preorder, inorder)
    if is_equal_tree(res, expected):
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == "__main__":
    #  preorder = [3,9,20,15,7]
    #  inorder = [9,3,15,20,7]
    #  Return the following binary tree:
    #      3
    #     / \
    #    9  20
    #      /  \
    #     15   7
    pre1 = [3,9,20,15,7]
    in1 = [9,3,15,20,7]
    expected1 = TreeNode(3)
    expected1.left = TreeNode(9)
    expected1.right = TreeNode(20)
    expected1.right.left = TreeNode(15)
    expected1.right.right = TreeNode(7)
    test("test1", pre1, in1, expected1)

    pre2 = []
    in2 = []
    expected2 = None
    test("test2", pre2, in2, expected2)
