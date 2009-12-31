#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();
        if (N < 2)
            return N;
        vector<int> alloc(N, 1);
        for (int i = 1; i < N; i++) {
            if (ratings[i] > ratings[i-1])
                alloc[i] = alloc[i-1] + 1;
        }
        for (int i = N - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1])
                alloc[i] = max(alloc[i], alloc[i+1] + 1);
        }
        return accumulate(alloc.begin(), alloc.end(), 0);
    }
};

void test(string test_name, vector<int>& ratings, int expected) {
    int res = Solution().candy(ratings);
    if (res == expected) {
        cout << test_name + " succeed" << endl;
    } else {
        cout << test_name + " fail" << endl;
    }
}

int main() {
    vector<int> ratings1 = {1,0,2};
    int expected1 = 5;
    test("test1", ratings1, expected1);

    vector<int> ratings2 = {1,2,2};
    int expected2 = 4;
    test("test2", ratings2, expected2);

    return 0;
}
