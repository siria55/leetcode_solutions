#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int len = digits.size();
        for (int i = len - 1; i >= 0; i--) {
            int sum = digits[i] + carry + (i == len-1 ? 1 : 0);
            carry = sum / 10;
            digits[i] =sum % 10;
        }
        if (carry)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};

void test(string test_name, vector<int> &digits, vector<int> &expected)
{
    vector<int> res = Solution().plusOne(digits);
    if (res == expected) {
        cout << test_name << " succeed" << endl;
    } else {
        cout << test_name << " fail" << endl;
    }
}

int main()
{
    vector<int> digits1{1,2,3};
    vector<int> expected1{1,2,4};
    test("test1", digits1, expected1);

    vector<int> digits2{4,3,2,1};
    vector<int> expected2{4,3,2,2};
    test("test2", digits2, expected2);

    vector<int> digits3{9};
    vector<int> expected3{1,0};
    test("test3", digits3, expected3);

    return 0;
}

