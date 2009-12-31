#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int max_len{1};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j)
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};

void test(string test_name, vector<int>& nums, int expected)
{
    int res = Solution().lengthOfLIS(nums);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<int> nums1{10,9,2,5,3,7,101,18};
    int expected1{4};
    test("test1", nums1, expected1);

    vector<int> nums2{0,1,0,3,2,3};
    int expected2{4};
    test("test2", nums2, expected2);

    vector<int> nums3{7,7,7,7,7,7,7};
    int expected3{1};
    test("test3", nums3, expected3);

    return 0;
}

