from typing import *
import math


class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        dp = [[math.inf] * n for _ in range(k+2)]
        dp[0][src] = 0
        for t in range(1, k+2):
            for j, i, cost in flights:
                dp[t][i] = min(dp[t][i], dp[t-1][j] + cost)

        # src != dst，所以 t >= 1，至少 1 次航班
        res = min(dp[t][dst] for t in range(1, k+2))
        return res if res != math.inf else -1


def test(test_name, n, flights, src, dst, k, expected):
    res = Solution().findCheapestPrice(n, flights, src, dst, k)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')



if __name__ == '__main__':
    n1 = 3
    flights1 = [[0,1,100],[1,2,100],[0,2,500]]
    src1 = 0
    dst1 = 2
    k1 = 1
    expected1 = 200
    test('test1', n1, flights1, src1, dst1, k1, expected1)

    n2 = 3
    flights2 = [[0,1,100],[1,2,100],[0,2,500]]
    src2 = 0
    dst2 = 2
    k2 = 0
    expected2 = 500
    test('test2', n2, flights2, src2, dst2, k2, expected2)

