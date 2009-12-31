from typing import *


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [grid[0][0]] * n

        for j in range(1, n):
            dp[j] = dp[j-1] + grid[0][j]

        for i in range(1, m):
            dp[0] += grid[i][0]
            for j in range(1, n):
                dp[j] = min(dp[j], dp[j-1]) + grid[i][j]

        return dp[-1]


def test(test_name, grid, expected):
    res = Solution().minPathSum(grid)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == "__main__":
    grid1 = [
        [1,3,1],
        [1,5,1],
        [4,2,1]
    ]
    expected1 = 7
    test('test1', grid1, expected1)

    grid2 = [
        [1,2,3],
        [4,5,6]
    ]
    expected2 = 12
    test('test2', grid2, expected2)

