from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    res = -1
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        self.dfs(root, root.val)
        return self.res

    def dfs(self, node, cur):
        if not node: return
        if node.val != cur:
            if self.res == -1:
                self.res = node.val
            else:
                self.res = min(self.res, node.val)
            return

        self.dfs(node.left, cur)
        self.dfs(node.right, cur)


def test(test_name, root, expected):
    res = Solution().findSecondMinimumValue(root)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    #       2
    #      / \
    #     2  5
    #       / \
    #      5  7
    root1 = TreeNode(2)
    root1.left = TreeNode(2)
    root1.right = TreeNode(5)
    root1.right.left = TreeNode(5)
    root1.right.right = TreeNode(7)
    expected1 = 5
    test('test1', root1, expected1)

    #      2
    #     / \
    #    2   2
    root2 = TreeNode(2)
    root2.left = TreeNode(2)
    root2.right = TreeNode(2)
    expected2 = -1
    test('test2', root2, expected2)
