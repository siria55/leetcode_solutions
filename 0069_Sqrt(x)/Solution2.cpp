#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        long long len = x;
        while (len * len > x) {
            len = (len + x / len) / 2;
        }
        return len;
    }
};


void test(const string& test_name,
          int x,
          int expected)
{
    Solution s;
    int res = s.mySqrt(x);
    if (res == expected) {
        cout << test_name << " succeed" << endl;
    } else {
        cout << test_name << " fail" << endl;
    }
}

int main()
{
    int x1 = 4;
    int expected1 = 2;
    test("test1", x1, expected1);

    int x2 = 8;
    int expected2 = 2;
    test("test2", x2, expected2);

    int x3 = 2147395600;
    int expected3 = 46340;
    test("test3", x3, expected3);

    return 0;
}
