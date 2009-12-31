#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int>dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i)
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        return dp.back();
    }
};

void test(string test_name, vector<int>& nums, int expected)
{
    int res = Solution().rob(nums);
    if (Solution().rob(nums) == expected) {
        printf("%s succeed\n", test_name.c_str());
    } else {
        printf("%s fail\n", test_name.c_str());
    }
}



int main()
{
    vector<int> nums1{1,2,3,1};
    int expected1 = 4;
    test("test1", nums1, expected1);

    vector<int> nums2{2,7,9,3,1};
    int expected2 = 12;
    test("test2", nums2, expected2);

    return 0;
}

