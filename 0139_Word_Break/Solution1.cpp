#include <cstdio>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && st.count(s.substr(j, i-j)) > 0) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};


void test(string test_name, string s, vector<string>& wordDict, bool expected)
{
    bool res = Solution().wordBreak(s, wordDict);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    string s1 = "leetcode";
    vector<string> wordDict1 = {
        "leet", "code"
    };
    bool expected1 = true;
    test("test1", s1, wordDict1, expected1);

    string s2 = "applepenapple";
    vector<string> wordDict2 = {
        "apple", "pen"
    };
    bool expected2 = true;
    test("test2", s2, wordDict2, expected2);

    string s3 = "catsandog";
    vector<string> wordDict3 = {
        "cats", "dog", "sand", "and", "cat"
    };
    bool expected3 = false;
    test("test3", s3, wordDict3, expected3);

    return 0;
}
