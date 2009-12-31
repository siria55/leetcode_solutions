from typing import *
from collections import deque

class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n = len(graph)
        # 可以从任意点出发，所以一开始把所有点都加进去
        que = deque((i, 1 << i, 0) for i in range(n))
        seen = {(i, 1 << i) for i in range(n)}

        while que:
            u, mask, dist = que.popleft()
            if mask == (1 << n) - 1:
                return dist
            # 搜索相邻节点
            for v in graph[u]:
                mask_v = mask | (1 << v)
                if (v, mask_v) not in seen:
                    que.append((v, mask_v, dist + 1))
                    seen.add((v, mask_v))
        return 0


def test(test_name, graph, expected):
    res = Solution().shortestPathLength(graph)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    graph1 = [[1,2,3],[0],[0],[0]]
    expected1 = 4
    test('test1', graph1, expected1)

    graph2 = [[1],[0,2,4],[1,3,4],[2],[1,2]]
    expected2 = 4
    test('test2', graph2, expected2)
