#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool isSubsequence(const string& word, const string& s) {
        int pw = 0, N = s.size();
        for (int ps = 0; ps < N; ps++) {
            if (word[pw] == s[ps]) pw++;
        }
        return pw == word.size();
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res("");
        for (const auto& word : dictionary) {
            if (!isSubsequence(word, s)) continue;
            if (res.size() < word.size() ||
                res.size() == word.size() && word < res
            )
                res = word;
        }
        return res;
    }
};


void
test(const string& test_name,
     string s,
     vector<string>& dictionary,
     const string& expected)
{
    string res = Solution().findLongestWord(s, dictionary);
    if (res == expected) {
        cout << test_name + " succeed" << endl;
    } else {
        cout << test_name + " fail" << endl;
    }
}

int
main()
{
    string s1("abpcplea");
    vector<string> dictionary1{"ale","apple","monkey","plea"};
    string expected1("apple");
    test("test1", s1, dictionary1, expected1);

    string s2("abpcplea");
    vector<string> dictionary2{"a","b","c"};
    string expected2("a");
    test("test2", s2, dictionary2, expected2);

    string s3("aewfafwafjlwajflwajflwafj");
    vector<string> dictionary3{"apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf"};
    string expected3("ewaf");
    test("test3", s3, dictionary3, expected3);

    return 0;
}
