from typing import *

class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        lasts = [0] * 26
        res = []

        for i, ch in enumerate(s):
            lasts[ord(ch)-ord('a')] = i

        start, end = 0, 0
        for i, ch in enumerate(s):
            end = max(end, lasts[ord(s[i])-ord('a')])
            if end == i:
                res.append(end + 1 - start)
                start = end + 1
        return res


def test(test_name, s, expected):
    res = Solution().partitionLabels(s)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    s1 = 'ababcbacadefegdehijhklij'
    expected1 = [9,7,8]
    test('test1', s1, expected1)

    s2 = 'eccbbbbdec'
    expected2 = [10]
    test('test2', s2, expected2)
