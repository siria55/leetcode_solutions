#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdio>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;

        for (int type : candyType) {
            st.insert(type);
        }
        return min(st.size(), candyType.size()/2);
    }
};

void test(string test_name, vector<int>& candyType, int expected)
{
    int res = Solution().distributeCandies(candyType);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<int> candyType1{1,1,2,2,3,3};
    int expected1{3};
    test("test1", candyType1, expected1);

    vector<int> candyType2{1,1,2,3};
    int expected2{2};
    test("test2", candyType2, expected2);

    vector<int> candyType3{6,6,6,6};
    int expected3{1};
    test("test3", candyType3, expected3);

    vector<int> candyType4{100000,0,100000,0,100000,0,100000,0,100000,0,100000,0};
    int expected4 = 2;
    test("test4", candyType4, expected4);

    return 0;
}

