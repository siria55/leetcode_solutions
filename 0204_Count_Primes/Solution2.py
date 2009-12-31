class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0
        count = 0
        prime = [True] * n

        for i in range(2, n):
            if prime[i]:
                count += 1
            for j in range(i * 2, n, i):
                prime[j] = False

        return count


def test(test_name, n, expected):
    res = Solution().countPrimes(n)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')

if __name__ == "__main__":
    n1, expected1 = 10, 4
    test('test1', n1, expected1)

    n2, expected2 = 0, 0
    test('test2', n2, expected2)

    n3, expected3 = 1, 0
    test('test3', n3, expected3)

    n4, expected4 = 2, 0
    test('test4', n4, expected4)

