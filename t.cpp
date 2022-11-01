#include <cstdio>
#include <string>
#include <array>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        array<int, 128> counter{0};
        array<bool, 128> flag{false};
        for (const auto& ch : t) {
            counter[ch]++;
            flag[ch] = true;
        }

        int len_s = s.size(), len_t = t.size();
        int l = 0, start = 0, min_size = len_s + 1, cnt = 0;
        for (int r = 0; r < len_s; ++r) {
            if (!flag[s[r]])
                continue;
            if (--counter[s[r]]>=0)
                cnt++;
            while (cnt == len_t) {
                if (min_size > r + 1 - l) {
                    min_size = r + 1 - l;
                    start = l;
                }
                if (flag[s[l]] && ++counter[s[l]] > 0)
                    --cnt;
                ++l;
            }
        }
        return min_size == len_s + 1 ? "" : s.substr(start, min_size);
    }
};

void test(string test_name, string s, string t, string expected)
{
    string res = Solution().minWindow(s, t);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    string s1("ADOBECODEBANC");
    string t1("ABC");
    string expected1("BANC");
    test("test1", s1, t1, expected1);

    string s2("a");
    string t2("a");
    string expected2("a");
    test("test2", s2, t2, expected2);

    string s3("a");
    string t3("aa");
    string expected3("");
    test("test3", s3, t3, expected3);

    return 0;
}
