#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, m;
        bool rightEven;
        while (l < r) {
            m = l + (r - l) / 2;
            rightEven = (r - m) % 2 == 0;
            if (nums[m+1] == nums[m]) {
                if (rightEven) {    // 右边是偶，中间一个在右，右边变成奇
                    l = m + 2;
                } else {
                    r = m - 1;      // 右边是奇，中间一个在右，右边变成偶
                }
            } else if (nums[m-1] == nums[m]) {
                if (rightEven) {
                    r = m - 2;
                } else {
                    l = m + 1;
                }
            } else {
                return nums[m];
            }
        }
        return nums[l];  // l == r
    }
};

void test(const string& test_name,
          vector<int>& nums,
          int expected) {
    int res = Solution().singleNonDuplicate(nums);
    if (res == expected) {
        cout << test_name + " succeed" << endl;
    } else {
        cout << test_name + " fail" << endl;
    }
}

int main() {
    vector<int> nums1{1,1,2,3,3,4,4,8,8};
    int expected1 = 2;
    test("test1", nums1, expected1);

    vector<int> nums2{3,3,7,7,10,11,11};
    int expected2 = 10;
    test("test2", nums2, expected2);

    vector<int> nums3{1,1,2,3,3,4,4,8,8};
    int expected3 = 2;
    test("test3", nums3, expected3);

    return 0;
}

