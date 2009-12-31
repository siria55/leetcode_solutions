#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int len = distance.size();
        if (len < 4)
            return false;
        int i = 2;

        // always out
        while (i < len && distance[i] > distance[i-2])
            ++i;
        if (i == len)
            return false;

        // first out then in
        if (distance[i] >= distance[i-2] - (i < 4 ? 0 : distance[i-4]))
            distance[i-1] -= i < 3 ? 0 : distance[i-3];

        // in
        ++i;
        while (i < len && distance[i] < distance[i-2])
            ++i;
        return i != len;    // if i == n, there's not crossing
    }
};

void test(string test_name, vector<int>& distance, bool expected)
{
    bool res = Solution().isSelfCrossing(distance);
    if (res == expected)
        cout << test_name + " succeed\n";
    else
        cout << test_name + " fail\n";
}

int main()
{
    vector<int> distance1{2,1,1,2};
    bool expected1{true};
    test("test1", distance1, expected1);

    vector<int> distance2{1,2,3,4};
    bool expected2{false};
    test("test2", distance2, expected2);

    vector<int> distance3{1,1,1,1};
    bool expected3{true};
    test("test3", distance3, expected3);

    vector<int> distance4{3,3,3,2,1,1};
    bool expected4{false};
    test("test4", distance4, expected4);

    return 0;
}
