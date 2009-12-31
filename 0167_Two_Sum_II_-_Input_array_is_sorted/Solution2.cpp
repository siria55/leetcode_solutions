#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1, sum;
        while (l < r) {
            sum = numbers[l] + numbers[r];
            if (sum < target) l++;
            else if (sum > target) r--;
            else return {l+1, r+1};
        }
        return {-1, -1};
    }
};

void test(const string& test_name,
          vector<int>& numbers,
          int target,
          const vector<int>& expected) {
    vector<int> res = Solution().twoSum(numbers, target);
    if (res == expected) {
        cout << test_name + " succeed" << endl;
    } else {
        cout << test_name + " fail" << endl;
    }
}

int main() {
    vector<int> numbers1{2,7,11,15};
    int target1 = 9;
    vector<int> expected1{1,2};
    test("test1", numbers1, target1, expected1);

    vector<int> numbers2{2,3,4};
    int target2 = 6;
    vector<int> expected2{1,3};
    test("test2", numbers2, target2, expected2);

    vector<int> numbers3{-1, 0};
    int target3 = -1;
    vector<int> expected3{1,2};
    test("test3", numbers3, target3, expected3);

    return 0;
}
