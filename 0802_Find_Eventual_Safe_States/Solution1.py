from typing import *
from collections import defaultdict, deque

class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        adjvex = defaultdict(list)   # 反向建图，邻接表
        indegree = [0] * n

        # 反向建图
        for start in range(n):
            for end in graph[start]:
                adjvex[end].append(start)
                indegree[start] += 1

        que = deque()
        for x in range(n):
            if indegree[x] == 0:
                que.append(x)
        while que:
            y = que.popleft()
            for x in adjvex[y]:
                indegree[x] -= 1
                if indegree[x] == 0:
                    que.append(x)

        # 最后入度为 0 的节点肯定进过 que，直接返回这些节点就行了
        res = []
        for x in range(n):
            if indegree[x] == 0:
                res.append(x)
        return res


def test(test_name, graph, expected):
    res = Solution().eventualSafeNodes(graph)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    graph1 = [[1,2],[2,3],[5],[0],[5],[],[]]
    expected1 = [2,4,5,6]
    test('test1', graph1, expected1)

    graph2 = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
    expected2 = [4]
    test('test2', graph2, expected2)
