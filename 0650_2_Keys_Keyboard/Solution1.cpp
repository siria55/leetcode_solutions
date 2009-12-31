#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, 0);
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;
            for (int j = 2; j * j <= i; ++j)
                if (i % j == 0) {
                    dp[i] = dp[j] + dp[i/j];
                    break;
                }
        }
        return dp[n];
    }
};

void test(string test_name, int n, int expected)
{
    int res = Solution().minSteps(n);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    int n1{3};
    int expected1{3};
    test("test1", n1, expected1);

    int n2{1};
    int expected2{0};
    test("test2", n2, expected2);

    return 0;
}

