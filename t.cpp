class Solution {
    bool isSubsequence(string word, string s) {
        int pw = 0, size = s.size();
        for (int ps = 0; ps < size; ++ps)
            if (word[pw] == s[ps]) ++pw;
        return pw == word.size();
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        for (const string& word : dictionary) {
            if (!isSubsequence(word, s))
                continue;
            if (res.size() < word.size() ||
                    res.size() == word.size() && word < res)
                res = word;
        }
        return res;
    }
};
