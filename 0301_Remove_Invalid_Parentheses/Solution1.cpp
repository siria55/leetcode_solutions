#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    vector<string> res;

    bool is_valid(string s)
    {
        int count{0};
        for (char c : s) {
            if (c == '(')
                count++;
            else if (c == ')') {
                count--;
                if (count < 0)
                    return false;
            }
        }
        return count == 0;
    }

    void dfs(string s, int start, int left, int right)
    {
        if (left == 0 && right == 0) {
            if (is_valid(s)) {
                res.push_back(s);
                return;
            }
        }
        int len = s.size();
        for (int i = start; i < len; i++) {
            if (i != start && s[i] == s[i-1])
                continue;
            if (left > 0 && s[i] == '(')   // delete (
                dfs(s.substr(0, i)+s.substr(i+1,len-i-1), i, left-1, right);
            if (right > 0 && s[i] == ')')  // delete )
                dfs(s.substr(0, i)+s.substr(i+1,len-i-1), i, left, right-1);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int left{0}, right{0};
        // find invalid left and right parentheses count
        for (char c : s) {
            if (c == '(')
                left++;
            else if (c == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }
        dfs(s, 0, left, right);
        return res;
    }
};

void test(string test_name, string s, vector<string> expected)
{
    vector<string> res = Solution().removeInvalidParentheses(s);
    sort(res.begin(), res.end());
    sort(expected.begin(), expected.end());
    if (res == expected)
        cout << test_name + " succeed\n";
    else
        cout << test_name + " fail\n";
}

int main()
{
    string s1 = "()())()";
    vector<string> expected1{"(())()","()()()"};
    test("test1", s1, expected1);

    string s2 = "(a)())()";
    vector<string> expected2{"(a())()","(a)()()"};
    test("test2", s2, expected2);

    string s3 = ")(";
    vector<string> expected3{""};
    test("test3", s3, expected3);

    return 0;
}

