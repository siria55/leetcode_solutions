from typing import *
from collections import deque


class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        colors = [0] * n
        q = deque()

        for i in range(n):
            if colors[i] == 0:
                colors[i] = 1
                q.append(i)
            while q:
                node = q.pop()
                for j in graph[node]:
                    if colors[j] == colors[node]:
                        return False
                    if colors[j] == 0:
                        colors[j] = 1 if colors[node] == 2 else 2
                        q.append(j)
        return True


def test(test_name, graph, expected):
    res = Solution().isBipartite(graph)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    graph1 = [[1,2,3],[0,2],[0,1,3],[0,2]]
    expected1 = False
    test('test1', graph1, expected1)

    graph2 = [[1,3],[0,2],[1,3],[0,2]]
    expected2 = True
    test('test2', graph2, expected2)

