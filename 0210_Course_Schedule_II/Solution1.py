from typing import *
from collections import deque


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        if numCourses == 1:
            return [0]

        indegs = [0] * numCourses
        adjs = [set() for _ in range(numCourses)]

        for end, start in prerequisites:
            indegs[end] += 1
            adjs[start].add(end)

        q = deque()
        res = []
        for i in range(numCourses):
            if indegs[i] == 0:
                q.append(i)

        while q:
            node = q.pop()
            res.append(node)
            for j in adjs[node]:
                indegs[j] -= 1
                if indegs[j] == 0:
                    q.append(j)
        if len(res) == numCourses:
            return res
        return []


def test(test_name, numCourses, prerequisites, expecteds):
    res = Solution().findOrder(numCourses, prerequisites)
    if res in expecteds:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    numCourses1 = 2
    prerequisites1 = [[1,0]]
    expected1 = [[0,1]]
    test('test1', numCourses1, prerequisites1, expected1)

    numCourses2 = 4
    prerequisites2 = [[1,0],[2,0],[3,1],[3,2]]
    expected2 = [[0,1,2,3], [0,2,1,3]]
    test('test2', numCourses2, prerequisites2, expected2)

    numCourses3 = 1
    prerequisites3 = []
    expected3 = [[0]]
    test('test3', numCourses3, prerequisites3, expected3)

