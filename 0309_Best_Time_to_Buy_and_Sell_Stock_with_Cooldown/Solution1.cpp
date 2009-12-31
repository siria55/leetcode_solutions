#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = -prices[0];

        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i]);
            dp[i][1] = dp[i-1][0] + prices[i];
            dp[i][2] = max(dp[i-1][1], dp[i-1][2]);
        }

        return max(dp[n-1][1], dp[n-1][2]);
    }
};

void test(string test_name, vector<int>& prices, int expected)
{
    int res = Solution().maxProfit(prices);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<int> prices1{1,2,3,0,2};
    int expected1{3};
    test("test1", prices1, expected1);

    vector<int> prices2{1};
    int expected2{0};
    test("test2", prices2, expected2);

    return 0;
}

