#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
    string countDigits(int n)
    {
        string cnt(10, 0);
        while (n) {
            ++cnt[n%10];
            n /= 10;
        }
        return cnt;
    }
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string> powerOf2Digits{};
        for (int n = 1; n <= 1e9; n <<= 1)
            powerOf2Digits.insert(countDigits(n));

        return powerOf2Digits.count(countDigits(n));
    }
};

void test(string test_name, int n, bool expected)
{
    bool res = Solution().reorderedPowerOf2(n);
    if (res == expected)
        cout << test_name + " succeed\n";
    else
        cout << test_name + " fail\n";
}

int main()
{
    int n1{1};
    bool expected1{true};
    test("test1", n1, expected1);

    int n2{10};
    bool expected2{false};
    test("test2", n2, expected2);

    int n3{16};
    bool expected3{true};
    test("test3", n3, expected3);

    int n4{24};
    bool expected4{false};
    test("test4", n4, expected4);

    int n5{46};
    bool expected5{true};
    test("test5", n5, expected5);

    return 0;
}
