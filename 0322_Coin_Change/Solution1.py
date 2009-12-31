from typing import *

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        dp = [amount+1] * (amount + 1)
        dp[0] = 0

        for i in range(1, amount+1):
            for coin in coins:
                if i >= coin:
                    dp[i] = min(dp[i], 1 + dp[i-coin])

        return -1 if dp[-1] == amount+1 else dp[-1]


def test(test_name, coins, amount, expected):
    res = Solution().coinChange(coins, amount)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    coins1 = [1,2,5]
    amount1 = 11
    expected1 = 3
    test('test1', coins1, amount1, expected1)

    coins2 = [2]
    amount2 = 3
    expected2 = -1
    test('test2', coins2, amount2, expected2)

    coins3 = [1]
    amount3 = 0
    expected3 = 0
    test('test3', coins3, amount3, expected3)

