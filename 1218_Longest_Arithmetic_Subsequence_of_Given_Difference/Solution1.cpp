#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int dp[40001] = {0};
        int res = 0;
        const int OFFSET = 20000;
        for (int n : arr) {
            dp[n+OFFSET] = dp[n+OFFSET-difference] + 1;
            res = max(res, dp[n+OFFSET]);
        }
        return res;
    }
};

void test(string test_name, vector<int>& arr, int difference, int expected)
{
    int res = Solution().longestSubsequence(arr, difference);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<int> arr1{1,2,3,4};
    int difference1 = 1;
    int expected1 = 4;
    test("test1", arr1, difference1, expected1);

    vector<int> arr2{1,3,5,7};
    int difference2 = 1;
    int expected2 = 1;
    test("test2", arr2, difference2, expected2);

    vector<int> arr3{1,5,7,8,5,3,4,2,1};
    int difference3 = -2;
    int expected3 = 4;
    test("test3", arr3, difference3, expected3);

    return 0;
}
