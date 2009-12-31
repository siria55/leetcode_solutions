#include <cstdio>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        int res = 0;
        if (n == INT_MAX) {
            return 32;
        }
        n = (unsigned)n;

        while (n != 1) {
            if ((n&1) == 0)
                n >>= 1;
            else if (n != 3 && (n>>1)&1==1)
                ++n;
            else
                --n;
            ++res;
        }
        return res;
    }
};

void test(string test_name, int n, int expected)
{
    int res = Solution().integerReplacement(n);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    int n1 = 8;
    int expected1 = 3;
    test("test1", n1, expected1);

    int n2 = 7;
    int expected2 = 4;
    test("test2", n2, expected2);

    int n3 = 4;
    int expected3 = 2;
    test("test3", n3, expected3);

    return 0;
}

