#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len1{nums1.size()}, len2{nums2.size()};
        deque<int> stk;
        unordered_map<int, int> mp;
        for (int n : nums2) {
            while (!stk.empty() && stk.back() < n) {
                mp[stk.back()] = n;
                stk.pop_back();
            }
            stk.push_back(n);
        }
        vector<int> res(len1, 0);
        for (int i = 0; i < len1; i++)
            res[i] = mp.count(nums1[i]) ? mp[nums1[i]] : -1;
        return res;
    }
};

void test(
    string test_name,
    vector<int> &nums1,
    vector<int> &nums2,
    vector<int> &expected)
{
    vector<int> res = Solution().nextGreaterElement(nums1, nums2);
    if (res == expected)
        cout << test_name + " succeed\n";
    else
        cout << test_name + " fail\n";
}

int main()
{
    vector<int> nums11{4,1,2}, nums21{1,3,4,2};
    vector<int> expected1{-1,3,-1};
    test("test1", nums11, nums21, expected1);

    vector<int> nums12{2,4}, nums22{1,2,3,4};
    vector<int> expected2{3,-1};
    test("test2", nums12, nums22, expected2);

    return 0;
}

