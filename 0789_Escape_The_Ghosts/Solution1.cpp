#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int me = abs(target[0]) + abs(target[1]);  // 玩家到终点的曼哈顿距离
        for (const vector<int>& ghost : ghosts) {
            if (abs(target[0] - ghost[0]) + abs(target[1] - ghost[1]) <= me)
                return false;
        }
        return true;
    }
};

void test(const string& test_name,
          vector<vector<int>>& ghosts,
          vector<int>& target,
          bool expected)
{
    bool res = Solution().escapeGhosts(ghosts, target);
    if (res == expected) {
        cout << test_name << " succeed" << endl;
    } else {
        cout << test_name << " fail" << endl;
    }
}

int main() {
    vector<vector<int>> ghosts1{{1,0}, {0,3}};
    vector<int> target1{0,1};
    bool expected1(true);
    test("test1", ghosts1, target1, expected1);

    vector<vector<int>> ghosts2{{1,0}};
    vector<int> target2{2,0};
    bool expected2(false);
    test("test2", ghosts2, target2, expected2);

    vector<vector<int>> ghosts3{{2,0}};
    vector<int> target3{1,0};
    bool expected3(false);
    test("test3", ghosts3, target3, expected3);

    vector<vector<int>> ghosts4{{5,0},{-10,-2},{0, -5}, {-2, -2}, {-7,1}};
    vector<int> target4{7,7};
    bool expected4(false);
    test("test4", ghosts4, target4, expected4);

    vector<vector<int>> ghosts5{{-1,0},{0,1},{-1,0},{0,1},{-1,0}};
    vector<int> target5{0,0};
    bool expected5(true);
    test("test5", ghosts5, target5, expected5);

    return 0;
}
