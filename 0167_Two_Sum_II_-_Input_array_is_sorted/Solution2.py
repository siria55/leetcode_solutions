from typing import *


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l, r = 0, len(numbers) - 1
        while l < r:
            s = numbers[l] + numbers[r]
            if s > target:
                r -= 1
            elif s < target:
                l += 1
            else:
                return [l+1, r+1]
        return []


def test(test_name, numbers, target, expected):
    res = Solution().twoSum(numbers, target)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    numbers1 = [2,7,11,15]
    target1 = 9
    expected1 = [1,2]
    test('test1', numbers1, target1, expected1)

    numbers2 = [2,3,4]
    target2 = 6
    expected2 = [1,3]
    test('test2', numbers2, target2, expected2)

    numbers3 = [-1, 0]
    target3 = -1
    expected3 = [1,2]
    test('test3', numbers3, target3, expected3)
