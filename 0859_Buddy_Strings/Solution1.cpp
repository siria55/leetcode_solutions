#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int len1 = s.size();
        int len2 = goal.size();
        if (len1 != len2)
            return false;

        int cnt1[26] = {0};
        int cnt2[26] = {0};
        int diff_cnt = 0;
        for (int i = 0; i < len1; ++i) {
            int c1 = s[i] - 'a';
            int c2 = goal[i] - 'a';
            cnt1[c1]++, cnt2[c2]++;
            if (c1 != c2)
                ++diff_cnt;
        }
        bool has_twice_ch = false;
        for (int i = 0; i < 26; ++i) {
            if (cnt1[i] != cnt2[i])
                return false;
            if (cnt1[i] >= 2)
                has_twice_ch = true;
        }
        return diff_cnt == 2 || (diff_cnt == 0 && has_twice_ch);
    }
};

void test(string test_name, string s, string goal, bool expected)
{
    bool res = Solution().buddyStrings(s, goal);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    string s1 = "ab";
    string goal1 = "ba";
    bool expected1 = true;
    test("test1", s1, goal1, expected1);

    string s2 = "ab";
    string goal2 = "ab";
    bool expected2 = false;
    test("test2", s2, goal2, expected2);

    string s3 = "aa";
    string goal3 = "aa";
    bool expected3 = true;
    test("test3", s3, goal3, expected3);

    string s4 = "aaaaaaabc";
    string goal4 = "aaaaaaacb";
    bool expected4 = true;
    test("test4", s4, goal4, expected4);

    return 0;
}

