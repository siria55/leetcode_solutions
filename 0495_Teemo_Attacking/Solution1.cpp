#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        int last_end = 0;
        int len = timeSeries.size();
        for (int i = 0; i < len; ++i) {
            if (i && last_end >= timeSeries[i]) {
                res += timeSeries[i] - timeSeries[i-1];
            } else {
                res += duration;
            }
            last_end = timeSeries[i] + duration - 1;
        }
        return res;
    }
};

void test(string test_name, vector<int>& timeSeries, int duration, int expected)
{
    int res = Solution().findPoisonedDuration(timeSeries, duration);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<int> timeSeries1 = {1,4};
    int duration1 = 2;
    int expected1 = 4;
    test("test1", timeSeries1, duration1, expected1);

    vector<int> timeSeries2 = {1,2};
    int duration2 = 2;
    int expected2 = 3;
    test("test2", timeSeries2, duration2, expected2);
}

