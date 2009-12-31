#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int bits[31]{0};
        for (int i = 30; i && num; i--) {
            int r = num % 2;
            num /= 2;
            bits[i] = !(r == 1);
        }
        int res = 0;
        for (int i = 30; i; i--) {
            res += bits[i] * pow(2, 30-i);
        }
        return res;
    }
};

void test(string test_name, int num, int expected)
{
    int res = Solution().findComplement(num);
    if (res == expected)
        cout << test_name + " succeed\n";
    else
        cout << test_name + " fail\n";
}

int main()
{
    int num1{5};
    int expected1{2};
    test("test1", num1, expected1);

    int num2{1};
    int expected2{0};
    test("test2", num2, expected2);

    return 0;
}
