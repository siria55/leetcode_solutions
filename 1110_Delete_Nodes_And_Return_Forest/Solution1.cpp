#include <cstdio>
#include <string>
#include <vector>
#include <unordered_set>
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
    TreeNode* dfs(TreeNode* node, unordered_set<int>& targets, vector<TreeNode*>& forest)
    {
        if (!node)
            return nullptr;
        node->left = dfs(node->left, targets, forest);
        node->right = dfs(node->right, targets, forest);
        if (targets.count(node->val)) {
            if (node->left)
                forest.push_back(node->left);
            if (node->right)
                forest.push_back(node->right);
            node = nullptr;
        }
        return node;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        unordered_set<int> targets(to_delete.begin(), to_delete.end());
        root = dfs(root, targets, forest);
        if (root)
            forest.push_back(root);
        return forest;
    }
};

// no tests
