#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> score2 = score;
        int len = score.size();
        sort(score2.begin(), score2.end(), greater<>());
        unordered_map<int, int> score2rank;

        for (int i = 0; i < len; ++i) {
            score2rank[score2[i]] = i+1;
        }
        vector<string> res;
        vector<string> names{"Gold Medal", "Silver Medal", "Bronze Medal"};
        for (int i = 0; i < len; ++i) {
            int rank = score2rank[score[i]];
            if (rank <= 3)
                res.push_back(names[rank-1]);
            else
                res.push_back(to_string(rank));
        }
        return res;
    }
};

void test(string test_name, vector<int>& score, vector<string> expected)
{
    auto res = Solution().findRelativeRanks(score);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<int> score1{5,4,3,2,1};
    vector<string> expected1{"Gold Medal","Silver Medal","Bronze Medal","4","5"};
    test("test1", score1, expected1);

    vector<int> score2{10,3,8,9,4};
    vector<string> expected2{"Gold Medal","5","Bronze Medal","Silver Medal","4"};
    test("test2", score2, expected2);

    return 0;
}

