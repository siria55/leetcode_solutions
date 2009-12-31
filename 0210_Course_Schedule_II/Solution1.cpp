#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 1)
            return {0};

        vector<int> indegs(numCourses, 0);
        vector<unordered_set<int>> adjs(numCourses);

        for (auto &prerequisite : prerequisites) {
            int end{prerequisite[0]}, start{prerequisite[1]};
            indegs[end]++;
            adjs[start].insert(end);
        }

        queue<int> q;
        vector<int> res;
        for (int i = 0; i < numCourses; ++i) {
            if (indegs[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (int next : adjs[node]) {
                if (--indegs[next] == 0) {
                    q.push(next);
                }
            }

        }
        if (res.size() == numCourses)
            return res;
        return {};
    }
};

void test(string test_name, int numCourses, vector<vector<int>>& prerequisites, vector<int> expected)
{
    vector<int> res = Solution().findOrder(numCourses, prerequisites);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());

}

int main()
{
    int numCourses1{2};
    vector<vector<int>> prerequisites1{{1,0}};
    vector<int> expected1{0,1};
    test("test1", numCourses1, prerequisites1, expected1);

    int numCourses2{4};
    vector<vector<int>> prerequisites2{{1,0},{2,0},{3,1},{3,2}};
    vector<int> expected2{0,2,1,3};
    test("test2", numCourses2, prerequisites2, expected2);

    int numCourses3{1};
    vector<vector<int>> prerequisites3{};
    vector<int> expected3{0};
    test("test3", numCourses3, prerequisites3, expected3);

    return 0;
}

