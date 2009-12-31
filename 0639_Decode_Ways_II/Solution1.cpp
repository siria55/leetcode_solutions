#include <iostream>
using namespace std;

class Solution {
int MOD{(int)1e9+7};

public:
    int numDecodings(string s) {
        int N = s.length();
        long *f = new long[3];
        f[0] = 1;

        for (int i = 1; i <= N; i++) {
            char c = s[i-1];
            int t = c - '0';
            long cnt = 0;
            int p1 = (i-1) % 3, p2 = (i-2) % 3;
            for (int item = 1; item <= 26; item++) {
                if (item < 10) {                // current item formed by one char
                    if (c == '*' || t == item) cnt += f[p1];
                } else {                        // current item formed by two chars
                    if (i < 2) break;
                    char prev = s[i-2];
                    int u = prev - '0';
                    int a = item / 10, b = item % 10;
                    if ((prev == '*' || u == a) && (t == b || (c == '*' && b != 0)))
                        cnt += f[p2];
                }
            }
            f[i%3] = cnt % MOD;
        }
        return int(f[N%3]);
    }
};

void test(string test_name, string s, int expected)
{
    int res = Solution().numDecodings(s);
    if (res == expected)
        cout << test_name + " succeed\n";
    else
        cout << test_name + " fail\n";
}

int main()
{
    string s1 = "*";
    int expected1 = 9;
    test("test1", s1, expected1);

    string s2 = "1*";
    int expected2 = 18;
    test("test2", s2, expected2);

    string s3 = "2*";
    int expecteed3 = 15;
    test("test3", s3, expecteed3);

    return 0;
}

