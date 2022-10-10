#include <cstdio>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n < 2)
            return n;
        vector<int> alloc(n, 1);

        for (int i = 1; i < n; ++i)
            if (ratings[i] > ratings[i-1])
                alloc[i] = alloc[i-1] + 1;

        for (int i = n-2; i >= 0; --i)
            if (ratings[i] > ratings[i+1])
                alloc[i] = max(alloc[i], alloc[i+1]+1);

        return accumulate(alloc.begin(), alloc.end(), 0);
    }
};


void test(string test_name, vector<int>& ratings, int expected) {
    int res = Solution().candy(ratings);
    if (res == expected) {
        printf("%s succeed\n", test_name.c_str());
    } else {
        printf("%s fail\n", test_name.c_str());
    }
}

int main() {
    vector<int> ratings1{1,0,2};
    int expected1 = 5;
    test("test1", ratings1, expected1);

    vector<int> ratings2{1,2,2};
    int expected2 = 4;
    test("test2", ratings2, expected2);

    vector<int> ratings3{1,3,4,5,2};
    int expected3 = 11;
    test("test3", ratings3, expected3);

    return 0;
}