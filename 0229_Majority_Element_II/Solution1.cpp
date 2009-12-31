#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1{0}, cand2{0}, count1{0}, count2{0};
        for (int n : nums) {
            if (n == cand1)
                count1++;
            else if (n == cand2)
                count2++;
            else if (count1 == 0) {
                count1 = 1;
                cand1 = n;
            } else if (count2 == 0) {
                count2 = 1;
                cand2 = n;
            } else {
                count1--, count2--;
            }
        }
        vector<int> res;
        int len = nums.size();
        if (count1 > 0 && count(nums.begin(), nums.end(), cand1) > len/3)
            res.push_back(cand1);
        if (count2 > 0 && count(nums.begin(), nums.end(), cand2) > len/3)
            res.push_back(cand2);
        return res;
    }
};

void test(string test_name, vector<int>& nums, vector<int> expected)
{
    vector<int> res = Solution().majorityElement(nums);
    if (res == expected)
        cout << test_name + " succeed\n";
    else
        cout << test_name + " fail\n";
}

int main()
{
    vector<int> nums1{3,2,3};
    vector<int> expected1{3};
    test("test1", nums1, expected1);

    vector<int> nums2{1};
    vector<int> expected2{1};
    test("test2", nums2, expected2);

    vector<int> nums3{1,2};
    vector<int> expected3{1,2};
    test("test3", nums3, expected3);

    return 0;
}
