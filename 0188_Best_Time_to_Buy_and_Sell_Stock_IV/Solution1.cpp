#include <cstdio>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k * 2 >= n) {
            int res = 0;
            for (int i = 1; i < n; ++i)
                if (prices[i] > prices[i-1])
                    res += prices[i] - prices[i-1];
            return res;
        }
        vector<int> buy(k+1, INT_MIN), sell(k+1, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                buy[j] = max(buy[j], sell[j-1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
};

void test(string test_name, int k, vector<int>& prices, int expected)
{
    int res = Solution().maxProfit(k, prices);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    int k1{2};
    vector<int> prices1{2,4,1};
    int expected1{2};
    test("test1", k1, prices1, expected1);

    int k2{2};
    vector<int> prices2{3,2,6,5,0,3};
    int expected2{7};
    test("test2", k2, prices2, expected2);

    return 0;
}

