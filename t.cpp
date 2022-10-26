#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
        });
        vector<vector<int>> res;
        int size = people.size();
        for (int i = 0; i < size; ++i) {
            res.insert(res.begin() + people[i][1], people[i]);
        }
        return res;
    }
};

void test(string test_name, vector<vector<int>>& people, vector<vector<int>>& expected)
{
    vector<vector<int>> res = Solution().reconstructQueue(people);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<vector<int>> people1{
        {7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}
    };
    vector<vector<int>> expected1{
        {5,0}, {7,0}, {5,2}, {6,1}, {4,4}, {7,1}
    };
    test("test1", people1, expected1);

    vector<vector<int>> people2{
        {6,0},{5,0},{4,0},{3,2},{2,2},{1,4}
    };
    vector<vector<int>> expected2{
        {4,0},{5,0},{2,2},{3,2},{1,4},{6,0}
    };
    test("test2", people2, expected2);

    return 0;
}
