#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool res = false;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                i++;
            else
                j--;
        }
        return res;
    }
};

void test(string test_name, vector<vector<int>>& matrix, int target, bool expected)
{
    bool res = Solution().searchMatrix(matrix, target);
    if (res == expected)
        cout << test_name + " succeed\n";
    else
        cout << test_name + " fail\n";
}

int main()
{
    vector<vector<int>> matrix1 = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30},
    };
    int target1 = 5;
    bool expected1 = true;
    test("test1", matrix1, target1, expected1);

    vector<vector<int>> matrix2 = matrix1;
    int target2 = 20;
    bool expected2 = false;
    test("test2", matrix2, target2, expected2);
}

