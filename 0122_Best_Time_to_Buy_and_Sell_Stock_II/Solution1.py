from typing import *

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0

        res = 0
        for i in range(1, len(prices)):
            res += max(0, prices[i] - prices[i-1])
        return res


def test(test_name, prices, expected):
    res = Solution().maxProfit(prices)
    if res == expected:
        print(test_name + ' success.')
    else:
        print(test_name + ' failed.')


if __name__ == "__main__":
    prices1 = [7,1,5,3,6,4]
    expected1 = 7
    test('test1', prices1, expected1)

    prices2 = [1,2,3,4,5]
    expected2 = 4
    test('test2', prices2, expected2)

    prices3 = [7,6,4,3,1]
    expected3 = 0
    test('test3', prices3, expected3)
