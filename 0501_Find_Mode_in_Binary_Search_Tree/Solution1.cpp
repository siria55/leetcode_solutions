#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdio>
#include "util_cpp/tree.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    unordered_map<int, int> mp;
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        vector<int> res = {};
        int max_cnt = 0;
        for (const auto &pair : mp) {
            max_cnt = max(max_cnt, pair.second);
        }
        for (const auto &pair : mp) {
            if (max_cnt == pair.second) res.push_back(pair.first);
        }
        return res;
    }
    void dfs(TreeNode *node) {
        if (node == nullptr)
            return;
        mp[node->val]++;
        if (node->left) dfs(node->left);
        if (node->right) dfs(node->right);
    }
};

void test(string test_name, TreeNode* root, vector<int> expected) {
    vector<int> res = Solution().findMode(root);
    sort(res.begin(), res.end());
    sort(expected.begin(), expected.end());
    if (res == expected)
        cout << test_name + " succeed" << endl;
    else
        cout << test_name + " fail" << endl;
}

int main() {
    TreeNode *root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->right->left = new TreeNode(2);
    vector<int> expected1 = {2};
    test("test1", root1, expected1);

    TreeNode *root2 = new TreeNode(0);
    vector<int> expected2 = {0};
    test("test2", root2, expected2);


    return 0;
}
