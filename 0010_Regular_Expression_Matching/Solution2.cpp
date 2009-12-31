#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;

        for (int i = 1; i <= m; ++i)
            dp[i][0] = false;

        // p[0.., j - 3, j - 2, j - 1] matches empty iff p[j - 1] is '*' and p[0..j - 3] matches empty
        for (int j = 1; j <= n; ++j)
            dp[0][j] = j > 1 && p[j-1] == '*' && dp[0][j-2];

        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                if (p[j-1] != '*')
                    dp[i][j] = dp[i-1][j-1] && (p[j-1] == s[i-1] || p[j-1] == '.');
                else
                    dp[i][j] = dp[i][j-2] || (p[j-2] == s[i-1] || p[j-2] == '.') && dp[i-1][j];
        return dp[m][n];
    }
};

void test(string test_name, string s, string p, bool expected)
{
    bool res = Solution().isMatch(s, p);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    string s1 = "aa";
    string p1 = "a";
    bool expected1 = false;
    test("test1", s1, p1, expected1);

    string s2 = "aa";
    string p2 = "a*";
    bool expected2 = true;
    test("test2", s2, p2, expected2);

    string s3 = "ab";
    string p3 = ".*";  // ".*" means "zero or more (*) of any character (.)".
    bool expected3 = true;
    test("test3", s3, p3, expected3);

    string s4 = "aab";
    string p4 = "c*a*b";
    bool expected4 = true;
    test("test4", s4, p4, expected4);

    string s5 = "mississippi";
    string p5 = "mis*is*p*.";
    bool expected5 = false;
    test("test5", s5, p5, expected5);

    return 0;
}

