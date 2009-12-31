from typing import *
import collections
from util_py.tree import *

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        # 先用 dfs 遍历树来建图
        node_parent = {}  # 当成图，k 是 child， val 是 parent
        def dfs(node):
            if not node:
                return
            if node.left:
                node_parent[node.left] = node
            if node.right:
                node_parent[node.right] = node
            dfs(node.left)
            dfs(node.right)
        dfs(root)

        # bfs波纹法， 先 visit& 先判适应于距离大于1
        if k == 0:
            return [target.val]

        res = []
        deq = collections.deque()
        visited = set()
        deq.append(target)
        visited.add(target)
        level = 0

        while deq and level < k:
            level += 1
            # x 是最外面一层的节点
            for _ in range(len(deq)):
                x = deq.popleft()
                # 对于 x，遍历其相邻的三个节点
                for y in [node_parent[x] if x in node_parent else None, x.left, x.right]:
                    if not y: continue
                    if y in visited: continue
                    if level == k:
                        res.append(y.val)
                    deq.append(y)
                    visited.add(y)
        return res


def test(test_name, root, target, k, expected):
    res = Solution().distanceK(root, target, k)
    res.sort()
    expected.sort()
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    #       3
    #     /   \
    #    5     1
    #   / \   / \
    #  6  2  0  8
    #    / \
    #   7  4
    root1 = TreeNode(3)
    root1.left = TreeNode(5)
    root1.left.left = TreeNode(6)
    root1.left.right = TreeNode(2)
    root1.left.right.left = TreeNode(7)
    root1.left.right.right = TreeNode(4)
    root1.right = TreeNode(1)
    root1.right.left = TreeNode(0)
    root1.right.right = TreeNode(8)
    target1 = root1.left
    k1 = 2
    expected1 = [7,4,1]
    test('test1', root1, target1, k1, expected1)

    root2 = TreeNode(1)
    target2 = root2
    k2 = 3
    expected2 = []
    test('test2', root2, target2, k2, expected2)
