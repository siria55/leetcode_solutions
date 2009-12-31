#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
    vector<int> original;
    int len;
public:
    Solution(vector<int>& nums) {
        this->original = nums;
        this->len = nums.size();
    }

    vector<int> reset() {
        return original;
    }

    vector<int> shuffle() {
        vector<int> res = original;
        for (int i = 0; i < len; ++i) {
            int j = i + rand() % (len-i);
            int tmp = res[i];
            res[i] = res[j];
            res[j] = tmp;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
