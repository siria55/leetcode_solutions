#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int size_g = g.size(), size_s = s.size();
        int i{0}, j{0};
        while (i < size_g && j < size_s) {
            if (g[i] <= s[j++]) i++;
        }
        return i;
    }
};

void test(string test_name, vector<int>& g, vector<int>& s, int expected) {
    int res = Solution().findContentChildren(g, s);
    if (res == expected) {
        cout << test_name + " succeed" << endl;
    } else {
        cout << test_name + " fail" << endl;
    }
}


int main() {
    vector<int> g1{1,2,3};
    vector<int> s1{1,1};
    int expected1 = 1;
    test("test1", g1, s1, expected1);

    vector<int> g2{1,2};
    vector<int> s2{1,2,3};
    int expected2 = 2;
    test("test2", g2, s2, expected2);

    vector<int> g3{10, 9, 8, 7};
    vector<int> s3{5, 6, 7, 8};
    int expected3{2};
    test("test3", g3, s3, expected3);

    return 0;
}
