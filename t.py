from typing import *


class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        if n < 2:
            return n
        alloc = [1] * n

        for i in range(1, n):
            if ratings[i] > ratings[i-1]:
                alloc[i] = alloc[i-1] + 1

        for i in range(n-2, -1, -1):
            if ratings[i] > ratings[i+1]:
                alloc[i] = max(alloc[i], alloc[i+1]+1)

        return sum(alloc)


def test(test_name, ratings, expected):
    res = Solution().candy(ratings)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    ratings1 = [1,0,2]
    expected1 = 5
    test('test1', ratings1, expected1)

    ratings2 = [1,2,2]
    expected2 = 4
    test('test2', ratings2, expected2)

    ratings3 = [1,3,4,5,2]
    expected3 = 11
    test('test3', ratings3, expected3)

    ratings4 = [1,2]
    expected4 = 3
    test('test4', ratings4, expected4)
