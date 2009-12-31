#include <iostream>
#include <array>
using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        array<int, 128> count{0};       // 记录 t 中已经出现的各个字符，但窗口中还差的个数
        array<bool, 128> flags{false};  // 记录字符是否在 t 中
        for (const auto& ch : t) {
            flags[ch] = true;
            count[ch]++;
        }

        int len_s = s.size(), len_t = t.size();
        int l = 0, start = 0, min_size = len_s + 1, cnt = 0;
        // cnt 记录 [l, r] 中出现的 t 中字符的个数
        for (int r = 0; r < len_s; r++) {
            if (!flags[s[r]])           // 如果当前字符不再 t 中，直接跳过
                continue;
            if (--count[s[r]] >= 0)
                cnt++;

            // [l, r] 中出现的 t 中字符的个数 == len_t 后
            // 在优化左边，找最小值
            while (cnt == len_t) {
                if (min_size > r + 1 - l) {
                    min_size = r + 1 - l;
                    start = l;
                }
                // 排出 s[l] 后不满足 count 了
                if (flags[s[l]] && ++count[s[l]] > 0)
                    cnt--;
                l++;
            }
        }
        return min_size == len_s + 1 ? "" : s.substr(start, min_size);
    }
};


void test(string test_name, string s, string t, string expected)
{
    string res = Solution().minWindow(s, t);
    if (res == expected) {
        cout << test_name << " succeed" << endl;
    } else {
        cout << test_name << " fail" << endl;
    }
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
