#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int steps = minutesToTest / minutesToDie + 1;
        int pigs = ceil(log(buckets) / log(steps));
        return pigs;
    }
};

void test(string test_name, int buckets, int minutesToDie, int minutesToTest, int expected)
{
    int res = Solution().poorPigs(buckets, minutesToDie, minutesToTest);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    int buckets1 = 1000, minutesToDie1 = 15, minutesToTest1 = 60;
    int expected1 = 5;
    test("test1", buckets1, minutesToDie1, minutesToTest1, expected1);

    int buckets2 = 4, minutesToDie2 = 15, minutesToTest2 = 15;
    int expected2 = 2;
    test("test2", buckets2, minutesToDie2, minutesToTest2, expected2);

    int buckets3 = 4, minutesToDie3 = 15, minutesToTest3 = 30;
    int expected3 = 2;
    test("test3", buckets3, minutesToDie3, minutesToTest3, expected3);

    return 0;
}

