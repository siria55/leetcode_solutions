#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N = flowerbed.size();
        for (int i = 0; i < N;) {
            if (flowerbed[i] == 1) {
                i += 2;
            } else {
                if (i == N - 1 || flowerbed[i+1] == 0) {
                    i += 2;
                    n--;
                } else {
                    i += 3;
                }
            }
        }
        return n <= 0;
    }
};

void test(string test_name, vector<int>& flowerbed, int n, bool expected) {
    bool res = Solution().canPlaceFlowers(flowerbed, n);
    if (res == expected) {
        cout << test_name + " succeed" << endl;
    } else {
        cout << test_name + " fail" << endl;
    }
}

int main() {
    vector<int> flowerbed1 = {1,0,0,0,1};
    int n1 = 1;
    bool expected1 = true;
    test("test1", flowerbed1, n1, expected1);

    vector<int> flowerbed2 = {1,0,0,0,1};
    int n2 = 2;
    bool expected2 = false;
    test("test2", flowerbed2, n2, expected2);

    vector<int> flowerbed3 = {1,0,0,0,1,0,0};
    int n3 = 2;
    bool expected3 = true;
    test("test3", flowerbed3, n3, expected3);

    return 0;
}
