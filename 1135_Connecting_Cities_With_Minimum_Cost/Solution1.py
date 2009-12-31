from typing import *


class Solution:
    def minimumCost(self, n: int, connections: List[List[int]]) -> int:
        roots = [i for i in range(n+1)]
        def findRoot(node):
            if roots[node] == node:
                return node
            return findRoot(roots[node])

        connections.sort(key=lambda x:x[2])
        res, edge_cnt = 0, 0
        for a, b, cost in connections:
            roota, rootb = findRoot(a), findRoot(b)
            if rootb != roota:
                roots[rootb] = roota
                res += cost
                edge_cnt += 1
            if edge_cnt == n - 1:
                return res

        return -1


def test(test_name, n, connections, expected):
    res = Solution().minimumCost(n, connections)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    n1 = 3
    connections1 = [[1,2,5],[1,3,6],[2,3,1]]
    expected1 = 6
    test('test1', n1, connections1, expected1)

    n2 = 4
    connections2 = [[1,2,3],[3,4,4]]
    expected2 = -1
    test('test2', n2, connections2, expected2)

