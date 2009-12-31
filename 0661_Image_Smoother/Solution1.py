from typing import *

class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        m, n = len(img), len(img[0])
        dirs = [
            [0,1],[0,-1],[1,0],[-1,0],
            [1,1],[1,-1],[-1,1],[-1,-1]
        ]
        for i in range(m):
            for j in range(n):
                s, cnt = img[i][j], 1
                for k in range(len(dirs)):
                    x = i + dirs[k][0]
                    y = j + dirs[k][1]
                    if x < 0 or x >= m or y < 0 or y >= n:
                        continue
                    s += img[x][y] & 0xFF
                    cnt += 1
                img[i][j] |= ((s // cnt) << 8)
        for i in range(m):
            for j in range(n):
                img[i][j] >>= 8
        return img

def test(test_name, img, expected):
    res = Solution().imageSmoother(img)
    print(res)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')

if __name__ == '__main__':
    img1 = [[1,1,1],[1,0,1],[1,1,1]]
    expected1 = [[0,0,0],[0,0,0],[0,0,0]]
    test('test1', img1, expected1)

    img2 = [[100,200,100],[200,50,200],[100,200,100]]
    expected2 = [[137,141,137],[141,138,141],[137,141,137]]
    test('test2', img2, expected2)

