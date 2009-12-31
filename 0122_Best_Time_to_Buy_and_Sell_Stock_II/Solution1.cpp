#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int N = prices.size();
        for (int i = 1; i < N; i++) {
            res += max(prices[i] - prices[i-1], 0);
        }
        return res;
    }
};


void test(string test_name, vector<int>& prices, int expected)
{
    Solution s;
    if (s.maxProfit(prices) == expected) {
        cout << test_name << " succeed" << endl;
    } else {
        cout << test_name << " fail" << endl;
    }
}

int main()
{
    vector<int> prices1 = {7,1,5,3,6,4};
    int expected1 = 7;
    test("test1", prices1, expected1);

    vector<int> prices2 = {1,2,3,4,5};
    int expected2 = 4;
    test("test2", prices2, expected2);

    vector<int> prices3 = {7,6,4,3,1};
    int expected3 = 0;
    test("test3", prices3, expected3);

    return 0;
}
