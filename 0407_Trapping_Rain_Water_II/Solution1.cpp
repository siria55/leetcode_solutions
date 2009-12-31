#include <cstdio>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m <= 2 || n <= 2)
            return 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // put rim blocks in heap
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                    heap.push({heightMap[i][j], i * n + j});
                    visited[i][j] = true;
                }
            }
        }

        int res = 0;
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        while (!heap.empty()) {
            pair<int, int> cur = heap.top();
            heap.pop();

            for (int k = 0; k < 4; ++k) {
                int dx = cur.second / n + dirs[k][0];
                int dy = cur.second % n + dirs[k][1];
                if (dx >= 0 && dx < m && dy >= 0 && dy < n && !visited[dx][dy]) {
                    if (heightMap[dx][dy] < cur.first)
                        res += cur.first - heightMap[dx][dy];
                    visited[dx][dy] = true;
                    heap.push({max(heightMap[dx][dy], cur.first), dx * n + dy});
                }
            }
        }
        return res;
    }
};

void test(string test_name, vector<vector<int>>& heightMap, int expected)
{
    int res = Solution().trapRainWater(heightMap);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<vector<int>> heightMap1 = {
        {1,4,3,1,3,2},
        {3,2,1,3,2,4},
        {2,3,3,2,3,1}};
    int expected1 = 4;
    test("test1", heightMap1, expected1);

    vector<vector<int>> heightMap2 = {
        {3,3,3,3,3},
        {3,2,2,2,3},
        {3,2,1,2,3},
        {3,2,2,2,3},
        {3,3,3,3,3}};
    int expected2 = 10;
    test("test2", heightMap2, expected2);

    return 0;
}

