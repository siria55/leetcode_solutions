# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self, node):
        if not node:
            return
        node.left = self.dfs(node.left)
        node.right = self.dfs(node.right)
        if node.val in self.targets:
            if node.left:
                self.forest.append(node.left)
            if node.right:
                self.forest.append(node.right)
            node = None
        return node

    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        self.targets = set(to_delete)
        self.forest = []
        root = self.dfs(root)
        if root:
            self.forest.append(root)
        return self.forest

