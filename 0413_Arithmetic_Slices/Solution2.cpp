#include <cstdio>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0;

        vector<int> dp(n, 0);
        for (int i = 2; i < n; ++i)
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
                dp[i] = dp[i-1] + 1;

        return accumulate(dp.begin(), dp.end(), 0);
    }
};

void test(string test_name, vector<int>& nums, int expected)
{
    int res = Solution().numberOfArithmeticSlices(nums);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<int> nums1{1,2,3,4};
    int expected1{3};
    test("test1", nums1, expected1);

    vector<int> nums2{1};
    int expected2{0};
    test("test2", nums2, expected2);

    vector<int> nums3{1,2,3,8,9,10};
    int expected3{2};
    test("test3", nums3, expected3);

    return 0;
}

