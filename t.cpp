#include <cstdio>
#include <string>
using namespace std;

class Solution {
    bool isPal(const string &s, int l, int r) {
        while (l < r)
            if (s[l++] != s[r--])
                return false;
        return true;
    }
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r])
                return isPal(s, l+1, r) || isPal(s, l, r-1);
            ++l;
            --r;
        }
        return true;
    }
};

void test(string test_name, string s, bool expected) {
    bool res = Solution().validPalindrome(s);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main() {
    string s1 = "aba";
    bool expected1 = true;
    test("test1", s1, expected1);

    string s2 = "abca";
    bool expected2 = true;
    test("test2", s2, expected2);

    string s3 = "abc";
    bool expected3 = false;
    test("test3", s3, expected3);

    return 0;
}
