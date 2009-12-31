#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.size(), s2 = word2.size();
        vector<vector<int>> dp(s1+1, vector<int>(s2+1, 0));

        for (int i = 0; i <= s1; ++i)
            dp[i][0] = i;
        for (int j = 0; j <= s2; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= s1; ++i) {
            for (int j = 1; j <= s2; ++j) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            }
        }
        return dp.back().back();
    }
};

void test(string test_name, string word1, string word2, int expected)
{
    int res = Solution().minDistance(word1, word2);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    string word11{"horse"};
    string word21{"ros"};
    int expected1{3};
    test("test1", word11, word21, expected1);


    string word12{"intention"};
    string word22{"execution"};
    int expected2{5};
    test("test2", word12, word22, expected2);
    return 0;
}

