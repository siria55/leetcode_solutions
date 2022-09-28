from typing import *


class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key=lambda item : (item[0], -item[1]), reverse=True)
        res = []
        size = len(people)
        for i in range(size):
            res.insert(people[i][1], people[i])
        return res


def test(test_name, people, expected):
    res = Solution().reconstructQueue(people)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    people1 = [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
    expected1 = [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
    test('test1', people1, expected1)
