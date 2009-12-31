#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
    vector<string> res = {};
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return res;
        string path = "";
        dfs(root, path);
        return res;
    }

    void dfs(TreeNode *node, string path) {
        if (node == nullptr) {
            return;
        }
        path += to_string(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            res.push_back(path);
            return;
        }
        path += "->";
        if (node->left != nullptr)
            dfs(node->left, path);
        if (node->right != nullptr)
            dfs(node->right, path);
    }
};

void test(string test_name, TreeNode *root, vector<string> expected) {
    vector<string> res = Solution().binaryTreePaths(root);
    sort(res.begin(), res.end());
    sort(expected.begin(), expected.end());
    for (auto iter = res.begin(); iter != res.end(); iter++) {
        cout << *iter << endl;
    }
    if (res == expected)
        cout << test_name << " succeed" << endl;
    else
        cout << test_name << " fail" << endl;
}

int main() {
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->left->right = new TreeNode(5);
    root1->right = new TreeNode(3);
    vector<string> expected1 = {"1->2->5","1->3"};
    test("test1", root1, expected1);

    TreeNode *root2 = new TreeNode(1);
    vector<string> expected2 = {"1"};
    test("test2", root2, expected2);

    return 0;
}