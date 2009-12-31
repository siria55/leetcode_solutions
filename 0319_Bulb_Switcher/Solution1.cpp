#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

void test(string test_name, int n, int expected)
{
    int res = Solution().bulbSwitch(n);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    int n1 = 3;
    int expected1 = 1;
    test("test1", n1, expected1);

    int n2 = 0;
    int expected2 = 0;
    test("test2", n2, expected2);

    int n3 = 1;
    int expected3 = 1;
    test("test3", n3, expected3);

    return 0;
}

