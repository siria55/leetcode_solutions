#include <cstdio>
#include <string>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit{0}, min_price{INT_MAX};
        for (const int& p : prices) {
            min_price = min(min_price, p);
            max_profit = max(max_profit, p - min_price);
        }
        return max_profit;
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
    vector<int> prices1{7,1,5,3,6,4};
    int expected1{5};
    test("test1", prices1, expected1);

    vector<int> prices2{7,6,4,3,1};
    int expected2{0};
    test("test2", prices2, expected2);

    return 0;
}

