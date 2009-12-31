from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getValidCount(self, node, targetSum):
        if not node:
            return 0
        count = 1 if node.val == targetSum else 0
        count += self.getValidCount(node.left, targetSum-node.val)
        count += self.getValidCount(node.right, targetSum-node.val)
        return count

    def pathSum(self, root: TreeNode, targetSum: int) -> int:
        if not root:
            return 0
        return self.getValidCount(root, targetSum) +\
               self.pathSum(root.left, targetSum) +\
               self.pathSum(root.right, targetSum)

def test(test_name, root, targetSum, expected):
    res = Solution().pathSum(root, targetSum)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')

if __name__ == '__main__':
    #         10
    #        /   \
    #       5     -3
    #     /   \     \
    #    3     2     11
    #   / \     \
    #  3  -2     1
    root1 = TreeNode(10)
    root1.left = TreeNode(5)
    root1.left.left = TreeNode(3)
    root1.left.left.left = TreeNode(3)
    root1.left.right = TreeNode(2)
    root1.left.right.right = TreeNode(1)
    root1.right = TreeNode(-3)
    root1.right.right = TreeNode(11)
    targetSum1 = 8
    expected1 = 3
    test('test1', root1, targetSum1, expected1)

