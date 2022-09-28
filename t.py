from typing import *


class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        pass




class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key=functools.cmp_to_key(cmp_pair))
        res = []
        for pair in people:
            res.insert(pair[1], pair)
        return res


def test(test_name, people, expected):
    res = Solution().reconstructQueue(people)
    if res == expected:
        print(test_name + ' success.')
    else:
        print(test_name + ' failed.')


if __name__ == '__main__':
    people1 = [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
    expected1 = [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
    test('test1', people1, expected1)
