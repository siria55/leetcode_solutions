#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> dirs = {
            {0,1},{0,-1},{1,0},{-1,0},
            {1,1},{1,-1},{-1,1},{-1,-1}
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = img[i][j], cnt = 1;
                for (int k = 0; k < dirs.size(); ++k) {
                    int x = i + dirs[k][0];
                    int y = j + dirs[k][1];
                    if (x < 0 || x >= m || y < 0 || y >= n)
                        continue;
                    sum += (img[x][y] & 0xFF);
                    cnt++;
                }
                img[i][j] |= ((sum/cnt)<<8);
            }
        }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                img[i][j] >>= 8;
        return img;
    }
};

void test(string test_name, vector<vector<int>>& img, vector<vector<int>>& expected)
{
    auto res = Solution().imageSmoother(img);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    vector<vector<int>> img1 = {
        {1,1,1},
        {1,0,1},
        {1,1,1},
    };
    vector<vector<int>> expected1 = {
        {0,0,0},
        {0,0,0},
        {0,0,0},
    };
    test("test1", img1, expected1);

    vector<vector<int>> img2 = {
        {100, 200, 100},
        {200, 50,  200},
        {100, 200, 100},
    };
    vector<vector<int>> expected2 = {
        {137, 141, 137},
        {141, 138, 141},
        {137, 141, 137},
    };
    test("test2", img2, expected2);

    return 0;
}

