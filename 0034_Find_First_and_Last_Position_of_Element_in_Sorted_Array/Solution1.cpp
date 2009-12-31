#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int getLowerBound(const vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (target <= nums[m]) r = m;
            else l = m + 1;
        }
        return l;
    }

    int getUpperBound(const vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        while (l < r) {
            m = l + (r - l) / 2 + 1;
            if (target >= nums[m]) l = m;
            else r = m - 1;
        }
        return r;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        if (nums.empty()) return res;
        int lower = getLowerBound(nums, target);
        int upper = getUpperBound(nums, target);
        if (lower == nums.size() || nums[lower] != target) return res;
        return {lower, upper};
    }
};

void test(const string& test_name,
          vector<int> &nums,
          int target,
          const vector<int>& expected)
{
    vector<int> res = Solution().searchRange(nums, target);
    if (res == expected) {
        cout << test_name << " succeed" << endl;
    } else {
        cout << test_name << " fail" << endl;
    }
}

int main()
{
    vector<int> nums1 = {5,7,7,8,8,10};
    int target1 = 8;
    vector<int> expected1 = {3,4};
    test("test1", nums1, target1, expected1);

    vector<int> nums2 = {5,7,7,8,8,10};
    int target2 = 6;
    vector<int> expected2 = {-1, -1};
    test("test2", nums2, target2, expected2);

    vector<int> nums3 = {};
    int target3 = 0;
    vector<int> expected3 = {-1, -1};
    test("test3", nums3, target3, expected3);

    vector<int> nums4 = {1};
    int target4 = 1;
    vector<int> expected4 = {0,0};
    test("test4", nums4, target4, expected4);

    return 0;
}
