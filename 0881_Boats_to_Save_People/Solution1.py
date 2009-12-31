from typing import *


class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        res = 0
        l, r = 0, len(people) - 1
        while l <= r:
            if people[r] + people[l] <= limit:
                l += 1
            r -= 1
            res += 1
        return res


def test(test_name, people, limit, expected):
    res = Solution().numRescueBoats(people, limit)
    print(f'res = {res}')
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    people1 = [1,2]
    limit1 = 3
    expected1 = 1
    test('test1', people1, limit1, expected1)

    people2 = [3,2,2,1]
    limit2 = 3
    expected2 = 3
    test('test2', people2, limit2, expected2)

    people3 = [3,5,3,4]
    limit3 = 5
    expected3 = 4
    test('test3', people3, limit3, expected3)

    people4 = [5,1,4,2]
    limit4 = 6
    expected4 = 2
    test('test4', people4, expected4)
