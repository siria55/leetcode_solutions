from typing import *


class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x:x[1])
        res = 1
        size = len(points)
        tail = points[0][1]
        for i in range(1, size):
            if tail < points[i][0]:
                res += 1
                tail = points[i][1]
        return res


def test(test_name, points, expected):
    res = Solution().findMinArrowShots(points)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    points1 = [[10,16],[2,8],[1,6],[7,12]]
    expected1 = 2
    test('test1', points1, expected1)

    points2 = [[1,2],[3,4],[5,6],[7,8]]
    expected2 = 4
    test('test2', points2, expected2)

    points3 = [[1,2],[2,3],[3,4],[4,5]]
    expected3 = 2
    test('test3', points3, expected3)

    points4 = [[1,2]]
    expected4 = 1
    test('test4', points4, expected4)

    points5 = [[2,3],[2,3]]
    expected5 = 1
    test('test5', points5, expected5)

    points6 = [[1,2],[2,3],[3,4],[4,5]]
    expected6 = 2
    test('test6', points6, expected6)

    points7 = [[-2147483648,2147483647]]
    expected7 = 1
    test('test7', points7, expected7)

    points8 = [[3,9],[7,12],[3,8],[6,8],[9,10],[2,9],[0,9],[3,9],[0,6],[2,8]]
    expected8 = 2
    test('test8', points8, expected8)
