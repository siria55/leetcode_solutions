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

        vector<int> dp1(n), dp2(n);
        dp1[0] = dp1[1] = nums[0];
        dp2[1] = nums[1];
        for (int i = 2; i < n; ++i) {
            dp1[i] = max(dp1[i-1], dp1[i-2] + nums[i]);
            dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i]);
        }
        return max(dp1[n-2], dp2[n-1]);
    }
};

void test(string test_name, vector<int>& nums, int expected)
{
    int res = Solution().rob(nums);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<int> nums1{2,3,2};
    int expected1{3};
    test("test1", nums1, expected1);

    vector<int> nums2{1,2,3,1};
    int expected2{4};
    test("test2", nums2, expected2);

    vector<int> nums3{4,1,2,7,5,3,1};
    int expected3{14};
    test("test3", nums3, expected3);

    return 0;
}

