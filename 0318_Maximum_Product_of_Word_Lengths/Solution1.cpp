#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
    bool hasSameChar(string s1, string s2)
    {
        char mp[26] = {0};
        for (auto ch : s1)
            ++mp[ch-'a'];
        for (auto ch : s2)
            if (mp[ch-'a'])
                return true;
        return false;
    }
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        int res = 0;
        for (int i = 0; i < len; ++i)
            for (int j = 0; j < i; ++j)
                if (!hasSameChar(words[i], words[j]))
                    res = max(res, int(words[i].size() * words[j].size()));
        return res;
    }
};

void test(string test_name, vector<string>& words, int expected)
{
    int res = Solution().maxProduct(words);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<string> words1{"abcw","baz","foo","bar","xtfn","abcdef"};
    int expected1 = 16;
    test("test1", words1, expected1);

    vector<string> words2{"a","ab","abc","d","cd","bcd","abcd"};
    int expected2 = 4;
    test("test2", words2, expected2);

    vector<string> words3{"a","aa","aaa","aaaa"};
    int expected3 = 0;
    test("test3", words3, expected3);

    return 0;
}

