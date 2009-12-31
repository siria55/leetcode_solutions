#include <cstdio>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        if (n == 1)
            return 0;

        int dp[n+1][n+1];

        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                dp[i][j] = INT_MAX;

        for (int i = 0; i <= n; ++i)
            dp[i][i] = 0;

        // from 2nd col begin
        for (int j = 2; j <= n; ++j) {
            // from bottom to top rows
            for (int i = j-1; i >= 1; --i) {
                // compute middle points
                for (int k=i+1; k <= j-1; ++k) {
                    dp[i][j] = min(k + max(dp[i][k-1], dp[k+1][j]), dp[i][j]);
                }
                // compute endpoints
                dp[i][j] = min(dp[i][j], i+dp[i+1][j]);
                dp[i][j] = min(dp[i][j], j+dp[i][j-1]);
            }
        }
        return dp[1][n];
    }
};

void test(string test_name, int n, int expected)
{
    int res = Solution().getMoneyAmount(n);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    int n1 = 10;
    int expected1 = 16;
    test("test1", n1, expected1);

    int n2 = 1;
    int expected2 = 0;
    test("test2", n2, expected2);

    int n3 = 2;
    int expected3 = 1;
    test("test3", n3, expected3);

    return 0;
}

