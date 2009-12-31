from typing import *
from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def build(self, i1, i2, p1, p2):
        node = TreeNode(self.postorder[p2])
        root_idx = i1
        for i in range(i1, i2+1):
            if self.inorder[i] == node.val:
                root_idx = i
                break

        left_count = root_idx - i1
        if root_idx > i1:
            node.left = self.build(i1, root_idx-1, p1, p1+left_count-1)
        if root_idx < i2:
            node.right = self.build(root_idx+1, i2, p1+left_count, p2-1)
        return node

    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        self.inorder = inorder
        self.postorder = postorder
        _len = len(inorder)
        return self.build(0, _len-1, 0, _len-1)


def test(test_name, inorder, postorder, expected):
    res = Solution().buildTree(inorder, postorder)
    if is_equal_tree(res, expected):
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    #   inorder = [9,3,15,20,7]
    #   postorder = [9,15,7,20,3]
    #   Return the following binary tree:
    #       3
    #      / \
    #     9  20
    #       /  \
    #      15   7
    in1 = [9,3,15,20,7]
    post1 = [9,15,7,20,3]
    expected1 = TreeNode(3)
    expected1.left = TreeNode(9)
    expected1.right = TreeNode(20)
    expected1.right.left = TreeNode(15)
    expected1.right.right = TreeNode(7)
    test('test1', in1, post1, expected1)

