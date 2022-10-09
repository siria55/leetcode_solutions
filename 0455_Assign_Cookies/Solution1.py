from typing import *


class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        s1, s2 = len(g), len(s)
        p1, p2 = 0, 0
        g.sort()
        s.sort()
        while p1 < s1 and p2 < s2:
            if g[p1] <= s[p2]:
                p1 += 1
            p2 += 1
        return p1


def test(test_name, g, s, expected):
    res = Solution().findContentChildren(g, s)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    g1 = [1,2,3]
    s1 = [1,1]
    expected1 = 1
    test('test1', g1, s1, expected1)

    g2 = [1,2]
    s2 = [1,2,3]
    expected2 = 2
    test('test2', g2, s2, expected2)
    
    g3 = [10, 9, 8, 7]
    s3 = [5,6,7,8]
    expected3 = 2
    test('test3', g3, s3, expected3)
