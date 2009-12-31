#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adjs;
        for (auto &edge : edges)
            adjs[edge[0]].push_back(edge[1]);

        if (adjs.count(destination) > 0)            // dest has successor, false
            return false;

        vector<bool> visited(n, false);
        function<bool(int)>dfs = [&](int node)
        {
            if (adjs.count(node) == 0)
                return node == destination;         // node is leaf, then the leaf must be destination
            for (int next : adjs[node]) {
                if (visited[next])
                    return false;                   // has loop, return false
                visited[next] = true;
                if (!dfs(next))
                    return false;
                visited[next] = false;
            }
            return true;
        };
        visited[source] = true;
        return dfs(source);
    }
};

void test(string test_name, int n, vector<vector<int>>& edges, int source, int destination, bool expected)
{
    bool res = Solution().leadsToDestination(n, edges, source, destination);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    int n1{3};
    vector<vector<int>> edges1{{0,1},{0,2}};
    int source1{0}, destination1{2};
    bool expected1{false};
    test("test1", n1, edges1, source1, destination1, expected1);

    int n2{4};
    vector<vector<int>> edges2{{0,1}, {0,3}, {1,2}, {2,1}};
    int source2{0}, destination2{3};
    bool expected2{false};
    test("test2", n2, edges2, source2, destination2, expected2);

    int n3{4};
    vector<vector<int>> edges3{{0,1}, {0,2}, {1,3}, {2,3}};
    int source3{0}, destination3{3};
    bool expected3{true};
    test("test3", n3, edges3, source3, destination3, expected3);

    return 0;
}

