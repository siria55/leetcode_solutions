class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        s = list(s)

        def reverseS(l, r):
            while l < r:
                s[l], s[r] = s[r], s[l]
                l += 1
                r -= 1

        l, r = 0, k - 1
        N = len(s)
        while r < N:
            reverseS(l, r)
            l += 2 * k
            r += 2 * k
        reverseS(l, min(N-1, l + k - 1))
        return ''.join(s)


def test(test_name, s, k, expected):
    res = Solution().reverseStr(s, k)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    s1 = "abcdefg"
    k1 = 2
    expected1 = 'bacdfeg'
    test('test1', s1, k1, expected1)

    s2 = "abcd"
    k2 = 2
    expected2 = 'bacd'
    test('test2', s2, k2, expected2)

    s3 = 'abcdefg'
    k3 = 8
    expected3 = 'gfedcba'
    test('test3', s3, k3, expected3)
