from typing import *

class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        res = []
        path = [0]
        N = len(graph)

        def dfs(start):
            if start == N - 1:
                res.append(path[:])     # copy its value
                return
            for _next in graph[start]:
                path.append(_next)
                dfs(_next)
                path.pop()

        dfs(0)
        return res


def test(test_name, graph, expected):
    res = Solution().allPathsSourceTarget(graph)
    res.sort(), expected.sort()
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    graph1 = [[1,2],[3],[3],[]]
    expected1 =  [[0,1,3],[0,2,3]]
    test('test1', graph1, expected1)

    graph2 = [[4,3,1],[3,2,4],[3],[4],[]]
    expected2 = [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
    test('test2', graph2, expected2)

    graph3 = [[1],[]]
    expected3 = [[0,1]]
    test('test3', graph3, expected3)

    graph4 = [[1,2,3],[2],[3],[]]
    expected4 = [[0,1,2,3],[0,2,3],[0,3]]
    test('test4', graph4, expected4)

    graph5 = [[1,3],[2],[3],[]]
    expected5 =  [[0,1,2,3],[0,3]]
    test('test5', graph5, expected5)
