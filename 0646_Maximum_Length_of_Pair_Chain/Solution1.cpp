#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int> dp(n, 1);
        int res = dp[0];

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }
};

void test(string test_name, vector<vector<int>>& pairs, int expected)
{
    int res = Solution().findLongestChain(pairs);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());

}

int main()
{
    vector<vector<int>> pairs1{{1,2},{2,3},{3,4}};
    int expected1{2};
    test("test1", pairs1, expected1);

    vector<vector<int>> pairs2{{1,2},{7,8},{4,5}};
    int expected2{3};
    test("test2", pairs2, expected2);

    return 0;
}

