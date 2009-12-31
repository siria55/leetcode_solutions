#include <cstdio>
#include <string>
#include <vector>
#include <numeric>
using namespace std;


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        int target = sum / 2;
        int n = nums.size();

        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= target; ++j) {
                if (j < nums[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][target];
    }
};

void test(string test_name, vector<int>& nums, int expected)
{
    bool res = Solution().canPartition(nums);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<int> nums1{1,5,11,5};
    bool expected1{true};
    test("test1", nums1, expected1);

    vector<int> nums2{1,2,3,5};
    bool expected2{false};
    test("test2", nums2, expected2);

    return 0;
}

