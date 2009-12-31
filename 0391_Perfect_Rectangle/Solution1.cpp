#include <cstdio>
#include <climits>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int area = 0;

        // out most four corers
        int x1 = INT_MAX;
        int y1 = INT_MAX;
        int x2 = INT_MIN;
        int y2 = INT_MIN;
        int a, b, c, d;    // tmp points
        unordered_set<string> s;

        for (auto &rectangle : rectangles) {
            // update out most coordinates
            a = rectangle[0], b = rectangle[1];
            c = rectangle[2], d = rectangle[3];
            x1 = min(x1, a);
            y1 = min(y1, b);
            x2 = max(x2, c);
            y2 = max(y2, d);

            area += (d-b) * (c-a);

            // convert coordinates to string
            string p1 = to_string(a) + " " + to_string(b);
            string p2 = to_string(a) + " " + to_string(d);
            string p3 = to_string(c) + " " + to_string(b);
            string p4 = to_string(c) + " " + to_string(d);

            // update set, event count erase as zero
            if (!s.count(p1)) s.insert(p1);
            else s.erase(p1);
            if (!s.count(p2)) s.insert(p2);
            else s.erase(p2);
            if (!s.count(p3)) s.insert(p3);
            else s.erase(p3);
            if (!s.count(p4)) s.insert(p4);
            else s.erase(p4);
        }
        string p1 = to_string(x1) + " " + to_string(y1);
        string p2 = to_string(x1) + " " + to_string(y2);
        string p3 = to_string(x2) + " " + to_string(y1);
        string p4 = to_string(x2) + " " + to_string(y2);
        if (s.size() == 4 &&
                s.count(p1) && s.count(p2) && s.count(p3) && s.count(p4))
            return area == (y2-y1) * (x2-x1);
        return false;
    }
};

void test(string test_name, vector<vector<int>>& rectangles, bool expected)
{
    bool res = Solution().isRectangleCover(rectangles);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<vector<int>> rectangles1 = {{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};
    bool expected1 = true;
    test("test1", rectangles1, expected1);

    vector<vector<int>> rectangles2 = {{1,1,2,3},{1,3,2,4},{3,1,4,2},{3,2,4,4}};
    bool expected2 = false;
    test("test2", rectangles2, expected2);

    vector<vector<int>> rectangles3 = {{1,1,3,3},{3,1,4,2},{1,3,2,4},{3,2,4,4}};
    bool expected3 = false;
    test("test3", rectangles3, expected3);

    vector<vector<int>> rectangles4 = {{1,1,3,3},{3,1,4,2},{1,3,2,4},{2,2,4,4}};
    bool expected4 = false;
    test("test4", rectangles4, expected4);

    return 0;
}

