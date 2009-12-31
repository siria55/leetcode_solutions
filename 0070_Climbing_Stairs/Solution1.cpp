#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;

        int one_before{2}, two_before{1};
        int all;
        for (int i = 2; i < n; ++i) {
            all = one_before + two_before;
            two_before = one_before;
            one_before = all;
        }
        return all;
    }
};

void test(string test_name, int n, int expected)
{
    int res = Solution().climbStairs(n);
    if (res == expected) {
        printf("%s succeed\n", test_name.c_str());
    } else {
        printf("%s fail\n", test_name.c_str());
    }
}

int main()
{
    int n1 = 2;
    int expected1 = 2;
    // Explanation: There are two ways to climb to the top.
    // 1. 1 step + 1 step
    // 2. 2 steps
    test("test1", n1, expected1);

    int n2 = 3;
    int expected2 = 3;
    // Explanation: There are three ways to climb to the top.
    // 1. 1 step + 1 step + 1 step
    // 2. 1 step + 2 steps
    // 3. 2 steps + 1 step
    test("test2", n2, expected2);

    int n3 = 1;
    int expected3 = 1;
    test("test3", n3, expected3);

    return 0;
}
