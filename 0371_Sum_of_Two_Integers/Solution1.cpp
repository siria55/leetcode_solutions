#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int res{0}, carry{0};
        int b1, b2;
        for (int i = 0; i < 32; i++) {
            b1 = (a >> i) & 1;
            b2 = (b >> i) & 1;
            if (b1 == 1 && b2 == 1) {
                res |= (carry << i);
                carry = 1;
            } else if (b1 == 1 || b2 == 1) {
                res |= ((1^carry) << i);
            } else {
                res |= (carry << i);
                carry = 0;
            }
        }
        return res;
    }
};

void test(string test_name, int a, int b, int expected)
{
    int res = Solution().getSum(a, b);
    if (res == expected) {
        cout << test_name + " succeed\n";
    } else {
        cout << test_name + " fail\n";
    }
}


int main()
{
    int a1{1}, b1{2}, expected1{3};
    test("test1", a1, b1, expected1);

    int a2{2}, b2{3}, expected2{5};
    test("test2", a2, b2, expected2);

}

