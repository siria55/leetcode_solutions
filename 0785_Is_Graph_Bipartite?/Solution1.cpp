#include <cstdio>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> colors(n, 0);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (colors[i] == 0) {
                colors[i] = 1;
                q.push(i);
            }
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int j : graph[node]) {
                    if (colors[j] == colors[node])
                        return false;
                    if (colors[j] == 0) {
                        q.push(j);
                        colors[j] = colors[node] == 1 ? 2 : 1;
                    }
                }
            }
        }
        return true;
    }
};

void test(string test_name, vector<vector<int>>& graph, bool expected)
{
    bool res = Solution().isBipartite(graph);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<vector<int>> graph1 = {{1,2,3},{0,2},{0,1,3},{0,2}};
    bool expected1{false};
    test("test1", graph1, expected1);

    vector<vector<int>> graph2 = {{1,3},{0,2},{1,3},{0,2}};
    bool expected2{true};
    test("test2", graph2, expected2);

    return 0;
}

