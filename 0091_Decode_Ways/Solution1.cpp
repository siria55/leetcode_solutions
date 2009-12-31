#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;

        for (int i = 1; i < n; ++i) {
            int first = stoi(s.substr(i, 1));
            int second = stoi(s.substr(i-1, 2));
            if (first >= 1 && first <= 9)
                dp[i+1] += dp[i];
            if (second >= 10 && second <= 26)
                dp[i+1] += dp[i-1];
        }
        return dp.back();
    }
};

void test(string test_name, string s, int expected)
{
    Solution slt;
    int res = Solution().numDecodings(s);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    string s1 = "12";
    int expected1 = 2;
    test("test1", s1, expected1);

    string s2 = "226";
    int expected2 = 3;
    test("test2", s2, expected2);

    string s3 = "12345";
    int expected3 = 3;
    test("test3", s3, expected3);

    string s4 = "01";
    int expected4 = 0;
    test("test4", s4, expected4);

    return 0;
}

