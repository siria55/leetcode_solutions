from typing import *

class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        size = len(flowerbed)
        i = 0
        while i < size:
            if flowerbed[i]:
                i += 2
            else:
                if i == size - 1 or flowerbed[i+1] == 0:
                    i += 2
                    n -= 1
                else:
                    i += 3
        return n <= 0


def test(test_name, flowerbed, n, expected):
    res = Solution().canPlaceFlowers(flowerbed, n)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    flowerbed1 = [1,0,0,0,1]
    n1 = 1
    expected1 = True
    test('test1', flowerbed1, n1, expected1)

    flowerbed2 = [1,0,0,0,1]
    n2 = 2
    expected2 = False
    test('test2', flowerbed2, n2, expected2)

    flowerbed3 = [1,0,0,0,1,0,0]
    n3 = 2
    expected3 = True
    test('test3', flowerbed3, n3, expected3)
