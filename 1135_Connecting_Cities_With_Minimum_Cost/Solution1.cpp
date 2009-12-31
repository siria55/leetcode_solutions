#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    vector<int> roots;

    int find(int node)
    {
        if (node == roots[node])
            return node;
        return find(roots[node]);
    }
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        roots = vector<int>(n+1, 0);
        sort(connections.begin(), connections.end(), [&](auto &a, auto &b){ return a[2]<b[2]; });

        for (int i = 0; i <= n; ++i)
            roots[i] = i;

        int res{0}, edge_cnt{0};
        for (auto &conn : connections) {
            int a{conn[0]}, b{conn[1]}, cost{conn[2]};
            int roota = find(a), rootb = find(b);
            if (rootb != roota) {
                roots[rootb] = roota;
                res += cost;
                edge_cnt++;
            }
            if (edge_cnt == n - 1)
                return res;
        }
        return -1;
    }
};

void test(string test_name, int n, vector<vector<int>>& connections, int expected)
{
    int res = Solution().minimumCost(n, connections);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    int n1{3};
    vector<vector<int>> connections1{{1,2,5},{1,3,6},{2,3,1}};
    int expected1{6};
    test("test1", n1, connections1, expected1);

    int n2{4};
    vector<vector<int>> connections2{{1,2,3},{3,4,4}};
    int expected2{-1};
    test("test2", n2, connections2, expected2);

    return 0;
}

