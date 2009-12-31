#include <cstdio>
#include <string>
#include <vector>
using namespace std;


class Solution {

pair<int, int> get_count(const string& str)
{
    int c0 = str.size(), c1 = 0;
    for (const char& c : str) {
        if (c == '1') {
            --c0;
            ++c1;
        }
    }
    return make_pair(c0, c1);
}

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (const string& str : strs) {
            auto [c0, c1] = get_count(str);
            for (int i = m; i >= c0; --i) {
                for (int j = n; j >= c1; --j) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i-c0][j-c1]);
                }
            }
        }
        return dp[m][n];
    }
};

void test(string test_name, vector<string>& strs, int m, int n, int expected)
{
    int res = Solution().findMaxForm(strs, m, n);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<string> strs1{"10","0001","111001","1","0"};
    int m1{5}, n1{3};
    int expected1{4};
    test("test1", strs1, m1, n1, expected1);

    vector<string> strs2{"10","0","1"};
    int m2{1}, n2{1};
    int expected2{2};
    test("test2", strs2, m2, n2, expected2);

    return 0;
}

