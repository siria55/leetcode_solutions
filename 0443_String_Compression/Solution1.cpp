#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int tail = 0, N = chars.size();
        int cnt = 1;
        if (N == 1) {
            return 1;
        }
        for (int i = 1; i < N; i++) {
            if (i == N - 1) {
                if (chars[i] != chars[i-1]) {
                    // 最后两个不一样，都要加
                    // 1. 加倒数第二个
                    chars[tail++] = chars[i-1];
                    if (cnt != 1) {
                        string n_str = to_string(cnt);
                        int M = n_str.size();
                        for (int j = 0; j < M; j++) chars[tail++] = n_str[j];
                    }
                    // 2. 加最后一个
                    chars[tail++] = chars[i];
                } else {
                    // 最后一个和前面一样，直接 cnt + 1 算
                    chars[tail++] = chars[i-1];
                    string n_str = to_string(cnt+1);
                    int M = n_str.size();
                    for (int j = 0; j < M; j++) chars[tail++] = n_str[j];
                }
                break;
            }
            if (chars[i] != chars[i-1]) {
                chars[tail++] = chars[i-1];
                if (cnt != 1) {
                    string n_str = to_string(cnt);
                    int M = n_str.size();
                    for (int j = 0; j < M; j++) chars[tail++] = n_str[j];
                    cnt = 1;
                }
            } else {
                cnt++;
            }
        }
        return tail;
    }
};

void test(const string& test_name,
          vector<char>& chars,
          const vector<char>& expected)
{
    int len = Solution().compress(chars);
    for (int i = 0; i < len; i++) cout << chars[i];
    cout << endl;
    if (vector<char>(chars.begin(), chars.begin() + len) == expected) {
        cout << test_name + " succeed" << endl;
    } else {
        cout << test_name + " fail" << endl;
    }
}

int main() {
    vector<char> chars1{'a','a','b','b','c','c','c'};
    vector<char> expected1{'a','2','b','2','c','3'};
    test("test1", chars1, expected1);

    vector<char> chars2{'a'};
    vector<char> expected2{'a'};
    test("test2", chars2, expected2);

    vector<char> chars3{'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    vector<char> expected3{'a','b','1','2'};
    test("test3", chars3, expected3);

    vector<char> chars4{'a','a','a','b','b','a','a'};
    vector<char> expected4{'a','3','b','2','a','2'};
    test("test4", chars4, expected4);

    vector<char> chars5{'a', 'b', 'c'};
    vector<char> expected5{'a', 'b', 'c'};
    test("test5", chars5, expected5);

    return 0;
}

