#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int min = *min_element(nums.begin(), nums.end());
        return sum - min * nums.size();
    }
};

void test(string test_name, vector<int>& nums, int expected)
{
    int res = Solution().minMoves(nums);
    if (res == expected)
        cout << test_name + " succeed\n";
    else
        cout << test_name + " fail\n";
}

int main() {
    vector<int> nums1{1,2,3};
    int expected1{3};
    test("test1", nums1, expected1);

    vector<int> nums2{1,1,1};
    int expected2{0};
    test("test2", nums2, expected2);

    return 0;
}

