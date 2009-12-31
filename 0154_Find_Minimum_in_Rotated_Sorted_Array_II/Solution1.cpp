#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (nums[m] < nums[r]) r = m;
            else if (nums[m] > nums[r]) l = m + 1;
            else r--;
        }
        return nums[l];
    }
};


void test(const string& test_name,
          vector<int> numbers,
          int expected)
{
    int res = Solution().findMin(numbers);
    if (res == expected)
        cout << test_name << " succeed" << endl;
    else
        cout << test_name << " fail" << endl;
}

int main()
{
    vector<int> numbers1{3,4,5,1,2};
    int expected1 = 1;
    test("test1", numbers1, expected1);

    vector<int> numbers2{2,2,2,0,1};
    int expected2 = 0;
    test("test2", numbers2, expected2);

    return 0;
}


// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
// 例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

