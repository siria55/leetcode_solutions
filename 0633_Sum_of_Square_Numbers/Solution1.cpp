#include <iostream>
#include <cmath>
using namespace std;


class Solution {
public:
    bool judgeSquareSum(int c) {
        long l = 0, r = sqrt(c), sum;
        while (l <= r) {
            sum = l * l + r * r;
            if (sum < c) l++;
            else if (sum > c) r--;
            else return true;
        }
        return false;
    }
};


void test(string test_name, int c, bool expected) {
    bool res = Solution().judgeSquareSum(c);
    if (res == expected) {
        cout << test_name + " succeed" << endl;
    } else {
        cout << test_name + " fail" << endl;
    }
}

int main() {
    int c1 = 5;
    bool expected1 = true;
    test("test1", c1, expected1);

    int c2 = 3;
    bool expected2 = false;
    test("test2", c2, expected2);

    int c3 = 4;
    bool expected3 = true;
    test("test3", c3, expected3);

    int c4 = 2;
    bool expected4 = true;
    test("test4", c4, expected4);

    int c5 = 1;
    bool expected5 = true;
    test("test5", c5, expected5);

    int c6 = 2147482647;
    bool expected6 = false;
    test("test6", c6, expected6);

    return 0;
}
