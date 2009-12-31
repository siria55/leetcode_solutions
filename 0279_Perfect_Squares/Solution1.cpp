#include <cstdio>
#include <string>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j * j <= i; ++j)
                dp[i] = min(dp[i], dp[i-j*j]+1);
        return dp.back();
    }
};

void test(string test_name, int n, int expected)
{
    int res = Solution().numSquares(n);
    if (Solution().numSquares(n) == expected) {
        printf("%s succeed\n", test_name.c_str());
    } else {
        printf("%s fail\n", test_name.c_str());
    }
}

int main()
{
    int n1 = 12;
    int expected1 = 3;
    test("test1", n1, expected1);

    int n2 = 13;
    int expected2 = 2;
    test("test2", n2, expected2);

    return 0;
}

