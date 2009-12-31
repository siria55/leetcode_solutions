from typing import *
from collections import defaultdict


class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        N = len(points)
        res = 0
        if N < 3:
            return res

        for i in range(N):
            dist_count = defaultdict(int)
            for j in range(N):
                dx, dy = points[i][0] - points[j][0], points[i][1] - points[j][1]
                dist = dx * dx + dy * dy   # 不需要 sqrt 节省时间
                dist_count[dist] += 1
            for m in dist_count.values():
                res += m * (m-1)
        return res


def test(test_name, points, expected):
    res = Solution().numberOfBoomerangs(points)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    points1 = [[0,0],[1,0],[2,0]]
    expected1 = 2
    test('test1', points1, expected1)

    points2 = [[1,1],[2,2],[3,3]]
    expected2 = 2
    test('test2', points2, expected2)

    points3 = [[1,1]]
    expected3 = 0
    test('test3', points3, expected3)
