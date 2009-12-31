#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (const int& coin : coins) {
                if (i >= coin)
                    dp[i] = min(dp[i], 1+dp[i-coin]);

            }
        }
        return dp.back() == amount+1 ? -1 : dp.back();
    }
};

void test(string test_name, vector<int>& coins, int amount, int expected)
{
    int res = Solution().coinChange(coins, amount);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<int> coins1{1,2,5};
    int amount1{11};
    int expected1{3};
    test("test1", coins1, amount1, expected1);

    vector<int> coins2{2};
    int amount2{3};
    int expected2{-1};
    test("test2", coins2, amount2, expected2);

    vector<int> coins3{1};
    int amount3{0};
    int expected3{0};
    test("test3", coins3, amount3, expected3);

    return 0;
}

