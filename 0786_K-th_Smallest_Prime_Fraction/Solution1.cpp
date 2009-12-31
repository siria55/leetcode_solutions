#include <cstdio>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int len = arr.size();
        auto cmp = [&](const pair<int, int>& x, const pair<int, int>& y)
        {
            return arr[x.first] * arr[y.second] > arr[x.second] * arr[y.first];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);

        for (int j = 1; j < len; ++j)
            q.emplace(0, j);

        for (int _ = 1; _ < k; ++_) {
            auto [i, j] = q.top();
            q.pop();
            if (i+1 < j)
                q.emplace(i+1, j);
        }
        return {arr[q.top().first], arr[q.top().second]};
    }
};

void test(string test_name, vector<int>& arr, int k, vector<int>& expected)
{
    vector<int> res = Solution().kthSmallestPrimeFraction(arr, k);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<int> arr1{1,2,3,5};
    int k1 = 3;
    vector<int> expected1{2,5};
    test("test1", arr1, k1, expected1);

    vector<int> arr2{1, 7};
    int k2 = 1;
    vector<int> expected2{1, 7};
    test("test2", arr2, k2, expected2);

    return 0;
}

