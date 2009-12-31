from typing import *
import heapq


class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        N = len(profits)
        projects = sorted(zip(profits, capital), key=lambda i:i[1])

        cur = []
        idx = 0
        for _ in range(k):
            # 将所有需要的本金小于等于当前资本的项目加入最大堆
            while idx < N and projects[idx][1] <= w:
                heapq.heappush(cur, -projects[idx][0])
                idx += 1
            # 如果有项目在当前的大顶堆中，我们做利益最大的那一个
            if cur:
                w -= heapq.heappop(cur)
            else:
                break
        return w


def test(test_name, k, w, profits, capital, expected):
    res = Solution().findMaximizedCapital(k, w, profits, capital)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    k1 = 2
    w1 = 0
    profits1 = [1,2,3]
    capital1 = [0,1,1]
    expected1 = 4
    test('test1', k1, w1, profits1, capital1, expected1)

    k2 = 3
    w2 = 0
    profits2 = [1,2,3]
    capital2 = [0,1,2]
    expected2 = 6
    test('test2', k2, w2, profits2, capital2, expected2)

