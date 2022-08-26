from typing import *


class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda item:item[1])
        removed, last_right = 0, intervals[0][1]
        for i in range(1, len(intervals)):
            if last_right > intervals[i][0]:
                removed += 1
            else:
                last_right = intervals[i][1]
        return removed


def test(test_name, intervals, expected):
    res = Solution().eraseOverlapIntervals(intervals)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == "__main__":
    intervals1 = [[1,2], [2,3], [3,4], [1,3]]
    expected1 = 1
    test('test1', intervals1, expected1)

    intervals2 = [[1,2], [1,2], [1,2]]
    expected2 = 2
    test('test2', intervals2, expected2)

    intervals3 = [[1,2], [2,3]]
    expected3 = 0
    test('test3', intervals3, expected3)

    intervals4 = [[1,100],[11,22],[1,11],[2,12]]
    expected4 = 2
    test('test4', intervals4, expected4)
