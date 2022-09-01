#include <cstdio>
#include <string>
#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int size = s.size();
        array<int, 26> lasts;
        vector<int> res;

        for (int i = 0; i < size; ++i)
            lasts[s[i] - 'a'] = i;

        int start = 0, end = 0;
        for (int i = 0; i < size; ++i) {
            end = max(end, lasts[s[i] - 'a']);
            if (end == i) {
                res.push_back(end + 1 - start);
                start = end + 1;
            }
        }
        return res;
    }
};

void test(string test_name, string s, vector<int>& expected) {
    vector<int> res = Solution().partitionLabels(s);
    if (res == expected) {
        printf("%s succeed\n", test_name.c_str());
    } else {
        printf("%s fail\n", test_name.c_str());
    }
}

int main() {
    string s1 = "ababcbacadefegdehijhklij";
    vector<int> expected1{9, 7, 8};
    test("test1", s1, expected1);

    string s2 = "eccbbbbdec";
    vector<int> expected2{10};
    test("test2", s2, expected2);

    return 0;
}
