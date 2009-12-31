#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, grid[0][0]);

        for (int j = 1; j < n; j++)
            dp[j] = dp[j-1] + grid[0][j];

        for (int i = 1; i < m; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; ++j)
                dp[j] = min(dp[j-1], dp[j]) + grid[i][j];

        }
        return dp.back();
    }
};


void test(string test_name, vector<vector<int>>& grid, int expected)
{
    int res = Solution().minPathSum(grid);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<vector<int>> grid1{
        {1,3,1},
        {1,5,1},
        {4,2,1},
    };
    int expected1 = 7;
    test("test1", grid1, expected1);

    vector<vector<int>> grid2{
        {1,2,3},
        {4,5,6},
    };
    int expected2 = 12;
    test("test2", grid2, expected2);

    return 0;
}

