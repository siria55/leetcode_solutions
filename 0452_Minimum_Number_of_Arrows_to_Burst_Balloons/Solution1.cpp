#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
            [](vector<int>& a, vector<int>& b) {
                return a[1] < b[1];
            }
        );
        int arrow = 1;
        int tail = points[0][1];
        int N = points.size();
        for (int i = 1; i < N; i++) {
            if (tail < points[i][0]) {
                arrow++;
                tail = points[i][1];
            }
        }
        return arrow;
    }
};


void test(string test_name, vector<vector<int>>& points, int expected)
{
    int res = Solution().findMinArrowShots(points);
    if (res == expected)
        cout << test_name << " succeed" << endl;
    else
        cout << test_name << " fail" << endl;
}

int main()
{
    vector<vector<int>> points1 = {
        {10, 16}, {2, 8}, {1, 6}, {7, 12}
    };
    int expected1 = 2;
    test("test1", points1, expected1);

    vector<vector<int>> points2 = {
        {1,2}, {3,4}, {5,6}, {7,8}
    };
    int expected2 = 4;
    test("test2", points2, expected2);

    vector<vector<int>> points3 = {
        {1,2}, {2,3}, {3,4}, {4,5}
    };
    int expected3 = 2;
    test("test3", points3, expected3);

    return 0;
}
