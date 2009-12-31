#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp.back().back();
    }
};

void test(string test_name, string text1, string text2, int expected)
{
    int res = Solution().longestCommonSubsequence(text1, text2);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());

}

int main()
{
    string text11{"abcde"};
    string text21{"ace"};
    int expected1{3};
    test("test1", text11, text21, expected1);

    string text12{"abc"};
    string text22{"abc"};
    int expected2{3};
    test("test2", text12, text22, expected2);

    string text13{"abc"};
    string text23{"def"};
    int expected3{0};
    test("test3", text13, text23, expected3);

    return 0;
}

