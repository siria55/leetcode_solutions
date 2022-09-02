#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int size = prices.size();
        for (int i = 1; i < size; ++i)
            res += max(prices[i]-prices[i-1], 0);
        return res;
    }
};

void test(string test_name, vector<int>& prices, int expected)
{
    Solution s;
    int res = Solution().maxProfit(prices);

    if (res == expected) {
        printf("%s succeed\n", test_name.c_str());
    } else {
        printf("%s fail\n", test_name.c_str());
    }
}

int main()
{
    vector<int> prices1{7,1,5,3,6,4};
    int expected1 = 7;
    test("test1", prices1, expected1);

    vector<int> prices2{1,2,3,4,5};
    int expected2 = 4;
    test("test2", prices2, expected2);

    vector<int> prices3{7,6,4,3,1};
    int expected3 = 0;
    test("test3", prices3, expected3);

    return 0;
}
