#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int len = arr.size();
        for (int i = 0; i < len-1; i++) {
            if (arr[i] > arr[i+1])
                return i;
        }
        return -1;
    }
};

void test(string test_name, vector<int>& arr, int expected)
{
    int res = Solution().peakIndexInMountainArray(arr);
    if (res == expected)
        cout << test_name + " succeed\n";
    else
        cout << test_name + " fail\n";
}

int main()
{
    vector<int> arr1{0,1,0};
    int expected1 = 1;
    test("test1", arr1, expected1);

    vector<int> arr2{1,3,5,4,2};
    int expected2 = 2;
    test("test2", arr2, expected2);

    vector<int> arr3{0,10,5,2};
    int expected3 = 1;
    test("test3", arr3, expected3);

    vector<int> arr4{3,4,5,1};
    int expected4 = 2;
    test("test4", arr4, expected4);

    vector<int> arr5{24,69,100,99,79,78,67,36,26,19};
    int expected5 = 2;
    test("test5", arr5, expected5);

    return 0;
}
