from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getDepth(self, node):
        if not node:
            return 0
        l_depth = self.getDepth(node.left)
        r_depth = self.getDepth(node.right)
        self.res = max(self.res, l_depth + r_depth)
        return max(l_depth, r_depth) + 1

    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.res = 0
        self.getDepth(root)
        return self.res


def test(test_name, root, expected):
    res = Solution().diameterOfBinaryTree(root)
    print(res)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    #      1
    #    /  \
    #   2    3
    #  / \
    # 4   5
    root1 = TreeNode(1)
    root1.left = TreeNode(2)
    root1.left.left = TreeNode(4)
    root1.left.right = TreeNode(5)
    root1.right = TreeNode(3)
    expected1 = 3
    test('test1', root1, expected1)

    #   1
    #  /
    # 2
    root2 = TreeNode(1)
    root2.left = TreeNode(2)
    expected2 = 1
    test('test2', root2, expected2)

