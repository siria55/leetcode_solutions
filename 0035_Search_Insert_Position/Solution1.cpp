#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return l;
    }
};


void test(string test_name, vector<int> &nums, int target, int expected)
{
    int res = Solution().searchInsert(nums, target);
    if (res == expected) {
        cout << test_name << " succeed" << endl;
    } else {
        cout << test_name << " fail" << endl;
    }

}

int main()
{
    vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 2;
    int expected1 = 1;
    test("test1", nums1, target1, expected1);

    vector<int> nums2 = {1,3,5,6};
    int target2 = 7;
    int expected2 = 4;
    test("test2", nums2, target2, expected2);

    vector<int> nums3 = {1,3,5,6};
    int target3 = 7;
    int expected3 = 4;
    test("test3", nums3, target3, expected3);

    vector<int> nums4 = {1,3,5,6};
    int target4 = 0;
    int expected4 = 0;
    test("test4", nums4, target4, expected4);

    vector<int> nums5 = {1};
    int target5 = 0;
    int expected5 = 0;
    test("test5", nums5, target5, expected5);

    vector<int> nums6 = {1};
    int target6 = 1;
    int expected6 = 0;
    test("test6", nums6, target6, expected6);

    return 0;
}