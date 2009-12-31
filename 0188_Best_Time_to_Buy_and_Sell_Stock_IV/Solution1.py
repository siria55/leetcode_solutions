from typing import *


class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        if k * 2 >= n:
            res = 0
            for i in range(1, n):
                if prices[i] > prices[i-1]:
                    res += prices[i] - prices[i-1]
            return res

        buy = [-float('inf')] * (k+1)
        sell = [0] * (k+1)
        for i in range(n):
            for j in range(1, k+1):
                buy[j] = max(buy[j], sell[j-1] - prices[i])
                sell[j] = max(sell[j], buy[j] + prices[i])

        return sell[k]


def test(test_name, k, prices, expected):
    res = Solution().maxProfit(k, prices)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    k1 = 2
    prices1 = [2,4,1]
    expected1 = 2
    test('test1', k1, prices1, expected1)

    k2 = 2
    prices2 = [3,2,6,5,0,3]
    expected2 = 7
    test('test2', k2, prices2, expected2)

