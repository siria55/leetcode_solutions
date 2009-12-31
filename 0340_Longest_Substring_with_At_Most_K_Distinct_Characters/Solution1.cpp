#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int l = 0, res = 0;
        int N = s.size();
        unordered_map<char, int> mp;
        for (int r = 0; r < N; r++) {
            ++mp[s[r]];
            while (mp.size() > k) {
                if (--mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }
            res = max(res, r + 1 - l);
        }
        return res;
    }
};


void test(const string& test_name,
          string s,
          int k,
          const int expected)
{
    int res = Solution().lengthOfLongestSubstringKDistinct(s, k);
    if (res == expected) {
        cout << test_name + " succeed" << endl;
    } else {
        cout << test_name + " fail" << endl;
    }
}

int main()
{
    string s1("eceba");
    int k1(2);
    int expected1(3);    // The substring is "ece" with length 3.
    test("test1", s1, k1, expected1);

    string s2("aa");
    int k2(1);
    int expected2(2);
    test("test2", s2, k2, expected2);

    return 0;
}
