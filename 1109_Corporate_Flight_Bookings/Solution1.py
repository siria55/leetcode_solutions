from typing import *

class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        counter = [0] * n
        for booking in bookings:
            i, j = booking[0] - 1, booking[1] - 1
            counter[i] += booking[2]
            if j < n - 1:   # 最后一个站不下车
                counter[j+1] -= booking[2]

        for i in range(n-1):
            counter[i+1] += counter[i]
        return counter


def test(test_name, bookings, n, expected):
    res = Solution().corpFlightBookings(bookings, n)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    bookings1 = [[1,2,10],[2,3,20],[2,5,25]]
    n1 = 5
    expected1 = [10,55,45,25,25]
    test('test1', bookings1, n1, expected1)

    bookings2 = [[1,2,10],[2,2,15]]
    n2 = 2
    expected2 = [10, 25]
    test('test2', bookings2, n2, expected2)
