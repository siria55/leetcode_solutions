#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; ++i)
            for (int j = 1; j < i; ++j)
                dp[i] = max(dp[i], max(j * (i-j), j * dp[i-j]));
        return dp[n];
    }
};

void test(string test_name, int n, int expected)
{
    int res = Solution().integerBreak(n);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    int n1 = 2;
    int expected1 = 1;
    test("test1", n1, expected1);

    int n2 = 10;
    int expected2 = 36;
    test("test2", n2, expected2);

    return 0;
}

