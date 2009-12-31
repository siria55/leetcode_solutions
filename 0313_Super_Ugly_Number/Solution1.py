from typing import *


class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        dp = [0] * (n + 1)
        dp[1] = 1
        _len = len(primes)
        pointers = [1] * _len

        for i in range(2, n + 1):
            # 对于每个质因数，找到这个质因数 * 第几个 的最小值
            min_n = min(dp[pointers[j]] * primes[j] for j in range(_len))
            dp[i] = min_n
            # 再把等等于这个 min_n 的数的 质因数的 第几个 都 += 1
            for j in range(_len):
                if dp[pointers[j]] * primes[j] == min_n:
                    pointers[j] += 1
        return dp[-1]


def test(test_name, n, primes, expected):
    res = Solution().nthSuperUglyNumber(n, primes)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == "__main__":
    n1 = 12
    primes1 = [2,7,13,19]
    expected1 = 32
    test('test1', n1, primes1, expected1)

    n2 = 1
    primes2 = [2,3,5]
    expected2 = 1
    test('test2', n2, primes2, expected2)
