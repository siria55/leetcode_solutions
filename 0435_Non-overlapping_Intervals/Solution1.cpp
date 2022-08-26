#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const vector<int> &a, const vector<int> &b) {
                return a[1] < b[1];
            }
        );
        int removed = 0, last_right = intervals[0][1];
        int n = intervals.size();
        for (int i = 1; i < n; ++i) {
            if (last_right > intervals[i][0])
                ++removed;
            else
                last_right = intervals[i][1];
        }
        return removed;
    }
};

void test(string test_name, vector<vector<int>>& intervals, int expected)
{
    int res = Solution().eraseOverlapIntervals(intervals);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<vector<int>> intervals1{
        {1,2}, {2,3}, {3,4}, {1,3}
    };
    int expected1 = 1;
    test("test1", intervals1, expected1);

    vector<vector<int>> intervals2{
        {1,2}, {1,2}, {1,2}
    };
    int expected2 = 2;
    test("test2", intervals2, expected2);

    vector<vector<int>> intervals3{
        {1,2}, {2,3}
    };
    int expected3 = 0;
    test("test3", intervals3, expected3);

    return 0;
}
