#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int res = dp[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i-1], 0) + nums[i];
            res = max(res, dp[i]);
        }
        return res;
    }
};

void test(string test_name, vector<int> &nums, int expected)
{
    int res = Solution().maxSubArray(nums);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<int> nums1{-2,1,-3,4,-1,2,1,-5,4};
    int expected1{6};
    test("test1", nums1, expected1);

    vector<int> nums2{1};
    int expected2{1};
    test("test2", nums2, expected2);

    vector<int> nums3{5,4,-1,7,8};
    int expected3{23};
    test("test3", nums3, expected3);

    return 0;
}

