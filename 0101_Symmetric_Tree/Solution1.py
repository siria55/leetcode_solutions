from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isMirror(self, l, r):
        if not l and not r:
            return True
        if not l or not r:
            return False
        if l.val != r.val:
            return False
        return self.isMirror(l.left, r.right) and\
               self.isMirror(l.right, r.left)

    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        return self.isMirror(root.left, root.right)


def test(test_name, root, expected):
    res = Solution().isSymmetric(root)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == "__main__":
    t1 = TreeNode(1)
    t1.left = TreeNode(2)
    t1.right = TreeNode(2)
    t1.left.left = TreeNode(3)
    t1.left.right = TreeNode(4)
    t1.right.left = TreeNode(4)
    t1.right.right = TreeNode(3)
    expected1 = True
    #     1
    #    / \
    #   2   2
    #  / \ / \
    # 3  4 4  3
    test("test1", t1, expected1);

    t2 = TreeNode(1);
    t2.left = TreeNode(2);
    t2.left.right = TreeNode(3);
    t2.right = TreeNode(2);
    t2.right.right = TreeNode(3);
    expected2 = False;
    #     1
    #    / \
    #   2   2
    #    \   \
    #    3    3
    test("test2", t2, expected2);

    t3 = None;
    expected3 = True;
    test("test3", t3, expected3);
