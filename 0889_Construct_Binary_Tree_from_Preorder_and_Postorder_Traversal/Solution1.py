# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> TreeNode:
        if not preorder:
            return

        node = TreeNode(preorder[0])
        _len = len(preorder)
        if _len == 1:
            return node

        left_count = 0
        for i in range(_len):
            if preorder[1] == postorder[i]:
                left_count = i + 1
                break

        pre_l = preorder[1:1+left_count]
        pre_r = preorder[1+left_count:]
        pos_l = postorder[:left_count]
        pos_r = postorder[left_count:-1]
        node.left = self.constructFromPrePost(pre_l, pos_l)
        node.right = self.constructFromPrePost(pre_r, pos_r)
        return node

