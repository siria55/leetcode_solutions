from typing import *
from collections import *
from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        res = []
        q = deque()

        q.append(root)
        while len(q):
            _sum = 0.0
            cnt = len(q)
            for _ in range(cnt):
                node = q.popleft()
                _sum += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            res.append(_sum / cnt)
        return res


def test(test_name, root, expected):
    res = Solution().averageOfLevels(root)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    #      3
    #    /   \
    #   9    20
    #       /  \
    #      15   7
    root1 = TreeNode(3)
    root1.left = TreeNode(9)
    root1.right = TreeNode(20)
    root1.right.left = TreeNode(15)
    root1.right.right = TreeNode(7)
    expected1 = [3.0, 14.5, 11.0]
    test('test1', root1, expected1)

    #          3
    #        /   \
    #       9    20
    #     /   \
    #    15    7
    root2 = TreeNode(3)
    root2.left = TreeNode(9)
    root2.left.left = TreeNode(15)
    root2.left.right = TreeNode(7)
    root2.right = TreeNode(20)
    expected2 = [3.0, 14.5, 11.0]
    test('test2', root2, expected2)

