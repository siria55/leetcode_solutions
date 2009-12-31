from typing import *


class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        m, n = len(matrix), len(matrix[0])
        cur, pre = [0] * n, [0] * n
        size = 0

        for i in range(m):
            for j in range(n):
                if i == 0 or j == 0 or matrix[i][j] == '0':
                    cur[j] = ord(matrix[i][j]) - ord('0')
                else:
                    cur[j] = min(cur[j-1], pre[j], pre[j-1]) + 1
                size = max(cur[j], size)
            pre, cur = cur, [0] * n

        return size * size


def test(test_name, matrix, expected):
    res = Solution().maximalSquare(matrix)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    matrix1 = [
        ['1','0','1','0','0'],
        ['1','0','1','1','1'],
        ['1','1','1','1','1'],
        ['1','0','0','1','0']
    ]
    expected1 = 4
    test('test1', matrix1, expected1)

