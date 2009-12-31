#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int N = nums.size();
        bool moded = nums[0] > nums[1];   // flag 标志是否修改过

        // 遍历时，需要看三个元素
        for (int i = 1; i < N - 1; i++) {
            if (nums[i] <= nums[i+1]) continue;
            if (moded) return false;
            if (nums[i-1] <= nums[i+1])
                nums[i] = nums[i+1];
            else
                nums[i+1] = nums[i];
            moded = true;
        }
        return true;
    }
};

void test(string test_name, vector<int>& nums, bool expected) {
    bool res = Solution().checkPossibility(nums);
    if (res == expected) {
        cout << test_name + " succeed" << endl;
    } else {
        cout << test_name + " fail" << endl;
    }
}


int main() {
    vector<int> nums1 = {4,2,3};
    bool expected1 = true;
    test("test1", nums1, expected1);

    vector<int> nums2 = {4,2,1};
    bool expected2 = false;
    test("test2", nums2, expected2);

    vector<int> nums3 = {3,4,2,3};
    bool expected3 = false;
    test("test3", nums3, expected3);

    return 0;
}
