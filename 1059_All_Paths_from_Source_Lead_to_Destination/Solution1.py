from typing import *
from collections import defaultdict


class Solution:
    def leadsToDestination(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        adjs = defaultdict(list)
        for start, end in edges:
            adjs[start].append(end)

        if destination in adjs:
            return False

        visited = [False] * n
        def dfs(node):
            if node not in adjs:
                return node == destination
            for j in adjs[node]:
                if visited[j]:
                    return False
                visited[j] = True
                if not dfs(j):
                    return False
                visited[j] = False
            return True
        visited[source] = True
        return dfs(source)


def test(test_name, n, edges, source, destination, expected):
    res = Solution().leadsToDestination(n, edges, source, destination)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    n1 = 3
    edges1 = [[0,1],[0,2]]
    source1, destination1 = 0, 2
    expected1 = False
    test('test1', n1, edges1, source1, destination1, expected1)

    n2 = 4
    edges2 = [[0,1],[0,3],[1,2],[2,1]]
    source2, destination2 = 0, 3
    expected2 = False
    test('test2', n2, edges2, source2, destination2, expected2)

    n3 = 4
    edges3 = [[0,1],[0,2],[1,3],[2,3]]
    source3, destination3 = 0, 3
    expected3 = True
    test('test3', n3, edges3, source3, destination3, expected3)

