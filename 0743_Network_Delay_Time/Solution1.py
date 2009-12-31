from typing import *
from math import inf


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj_matrix = [[0] * (n+1) for _ in range(n+1)]

        # 初始化邻接矩阵
        for i in range(1, n+1):
            for j in range(1, n+1):
                adj_matrix[i][j] = adj_matrix[j][i] = 0 if i == j else float('inf')
        for time in times:
            start, end, weight = time[0], time[1], time[2]
            adj_matrix[start][end] = weight

        def dijkstra(end):
            visit = [False] * (n+1)
            dist = [float('inf')] * (n+1)
            dist[k] = 0
            for p in range(1, n+1):
                t = -1
                # 选择当前回合能走的最小距离，存在 t 里
                for i in range(1, n+1):
                    if not visit[i] and (t == -1 or dist[i] < dist[t]):
                        t = i
                visit[t] = True

                # 更新到 i 的距离
                # case1 原来的距离就最小
                # case2 从 t 到 i 能更小
                for i in range(1, n+1):
                    dist[i] = min(dist[i], dist[t] + adj_matrix[t][i])
            return dist[end]

        res = 0
        for end in range(1, n+1):
            if end == k:
                continue
            res = max(res, dijkstra(end))
        return -1 if res == float('inf') else res


def test(test_name, times, n, k, expected):
    res = Solution().networkDelayTime(times, n, k)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    times1 = [[2,1,1],[2,3,1],[3,4,1]]
    n1 = 4
    k1 = 2
    expected1 = 2
    test('test1', times1, n1, k1, expected1)

    times2 = [[1,2,1]]
    n2 = 2
    k2 = 1
    expected2 = 1
    test('test2', times2, n2, k2, expected2)

    times3 = [[1,2,1]]
    n3 = 2
    k3 = 2
    expected3 = -1
    test('test3', times3, n3, k3, expected3)
