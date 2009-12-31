from typing import *


class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        area = m * n
        dp = [[0] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    dp[i][j] = 0
                else:
                    top = area if i == 0 else dp[i-1][j]
                    left = area if j == 0 else dp[i][j-1]
                    dp[i][j] = min(top, left) + 1

        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                if mat[i][j] == 0:
                    dp[i][j] = 0
                else:
                    down = area if i == m-1 else dp[i+1][j]
                    right = area if j == n-1 else dp[i][j+1]
                    dp[i][j] = min(dp[i][j], min(down, right)+1)
        return dp


def test(test_name, mat, expected):
    res = Solution().updateMatrix(mat)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    matrix1 = [
        [0,0,0],
        [0,1,0],
        [0,0,0]
    ]
    expected1 = [
        [0,0,0],
        [0,1,0],
        [0,0,0]
    ]
    test('test1', matrix1, expected1)

    matrix2 = [
        [0,0,0],
        [0,1,0],
        [1,1,1]
    ]
    expected2 = [
        [0,0,0],
        [0,1,0],
        [1,2,1]
    ]
    test('test2', matrix2, expected2)

    matrix3 = [
        [1,0,1,1,0,0,1,0,0,1],
        [0,1,1,0,1,0,1,0,1,1],
        [0,0,1,0,1,0,0,1,0,0],
        [1,0,1,0,1,1,1,1,1,1],
        [0,1,0,1,1,0,0,0,0,1],
        [0,0,1,0,1,1,1,0,1,0],
        [0,1,0,1,0,1,0,0,1,1],
        [1,0,0,0,1,1,1,1,0,1],
        [1,1,1,1,1,1,1,0,1,0],
        [1,1,1,1,0,1,0,0,1,1]
    ]
    expected3 = [
        [1,0,1,1,0,0,1,0,0,1],
        [0,1,1,0,1,0,1,0,1,1],
        [0,0,1,0,1,0,0,1,0,0],
        [1,0,1,0,1,1,1,1,1,1],
        [0,1,0,1,1,0,0,0,0,1],
        [0,0,1,0,1,1,1,0,1,0],
        [0,1,0,1,0,1,0,0,1,1],
        [1,0,0,0,1,2,1,1,0,1],
        [2,1,1,1,1,2,1,0,1,0],
        [3,2,2,1,0,1,0,0,1,1]
    ]
    test('test3', matrix3, expected3)

