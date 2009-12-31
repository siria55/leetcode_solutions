from typing import *


class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        def is_sub_seq(word, s):
            pw, ps = 0, 0
            Nw, Ns = len(word), len(s)
            while pw < Nw and ps < Ns:
                if word[pw] == s[ps]:
                    pw += 1
                ps += 1
            return pw == Nw

        res = ''
        for word in dictionary:
            if not is_sub_seq(word, s): continue
            if len(res) < len(word) or len(res) == len(word) and res > word:
                res = word
        return res



def test(test_name, s, dictionary, expected):
    res = Solution().findLongestWord(s, dictionary)
    print(res)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    s1 = 'abpcplea'
    dictionary1 = ['ale','apple','monkey','plea']
    expected1 = 'apple'
    test('test1', s1, dictionary1, expected1)

    s2 = 'abpcplea'
    dictionary2 = ['a','b','c']
    expected2 = 'a'
    test('test2', s2, dictionary2, expected2)
