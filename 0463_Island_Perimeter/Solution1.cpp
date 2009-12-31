#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> m_grid;
    int dfs(int x, int y) {
        // 第一次进 dfs 必然是1，所以不会再前三个 return 返回
        if (x < 0 || y < 0 || x >= m || y >= n)
            return 1;   // 走到 grid 外面 +1
        if (m_grid[x][y] == 0)
            return 1;   // 走到水里面 +1
        if (m_grid[x][y] != 1)
            return 0;   // 走到陆地或者 走过的，则不统计
        m_grid[x][y] = 2; // 走过的标记为 2
        return dfs(x-1, y) + dfs(x+1, y) + dfs(x, y-1) + dfs(x, y+1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        m_grid = grid;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (m_grid[i][j] == 1) {
                    return dfs(i, j);  // 题目保证只有一个连通岛
                }
            }
        }
        return 0;
    }
};


void test(string test_name, vector<vector<int>>& grid, int expected) {
    int res = Solution().islandPerimeter(grid);
    if (res == expected)
        cout << test_name + " succeed" << endl;
    else
        cout << test_name + " fail" << endl;

}

int main() {
    vector<vector<int>> grid1 = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };
    int expected1 = 16;
    test("test1", grid1, expected1);

    vector<vector<int>> grid2 = {{1}};
    int expected2 = 4;
    test("test2", grid2, expected2);

    vector<vector<int>> grid3 = {{1,0}};
    int expected3 = 4;
    test("test3", grid3, expected3);

    return 0;
}
