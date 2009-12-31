#include <cstdio>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        // r set plus 1, for num = 1
        int l = 1, r = num / 2 + 1;
        int mid;
        long sq;
        while (l <= r) {
            mid = l + (r - l) / 2;
            sq = (long)mid * mid;   // convert long then compute, otherwise overflow happens
            if (sq < num)
                l = mid + 1;
            else if (sq > num)
                r = mid - 1;
            else
                return true;
        }
        return false;
    }
};

void test(string test_name, int num, bool expected)
{
    bool res = Solution().isPerfectSquare(num);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    int num1 = 16;
    bool expected1 = true;
    test("test1", num1, expected1);

    int num2 = 14;
    bool expected2 = false;
    test("test2", num2, expected2);

    int num3 = 1;
    bool expected3 = true;
    test("test3", num3, expected3);

    int num4 = 2000105819;
    bool expected4 = false;
    test("test4", num4, expected4);

    return 0;
}

