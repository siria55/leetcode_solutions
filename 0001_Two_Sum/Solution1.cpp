#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map = {};
        for (int i = 0; i < nums.size(); i++) {
            int n2find = target - nums[i];
            if (map.find(n2find) != map.end()) {
                return {map[n2find], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

void test(string test_name, vector<int> &nums, int target, vector<int> expected)
{
    vector<int> res = Solution().twoSum(nums, target);
    sort(res.begin(), res.end());
    sort(expected.begin(), expected.end());
    if (res == expected) {
        cout << test_name << " succeed" << endl;
    } else {
        cout << test_name << " fail" << endl;
    }
}

int main()
{
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> expected1 = {0, 1};
    test("test1", nums1, target1, expected1);
    return 0;
}
