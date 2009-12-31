#include <iostream>
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }

    bool dfs(TreeNode *node, int remain) {
        if (node == nullptr) return false;

        remain -= node->val;
        if (node->left == nullptr && node->right == nullptr) {
            return remain == 0;
        }

        return dfs(node->left, remain) || dfs(node->right, remain);
    }
};


void test(string test_name, TreeNode *root, int sum, bool expected)
{
    bool res = Solution().hasPathSum(root, sum);
    if (res == expected) {
        cout << test_name << " succeed" << endl;
    } else {
        cout << test_name << " fail" << endl;
    }
}


int main()
{
    //       5
    //      / \
    //     4   8
    //    /   / \
    //   11  13  4
    //  /  \      \
    // 7    2      1
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(8);
    root1->left->left = new TreeNode(11);
    root1->left->left->left = new TreeNode(7);
    root1->left->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(13);
    root1->right->right = new TreeNode(4);
    root1->right->right->right = new TreeNode(1);
    int targetSum1 = 22;
    bool expected1 = true;
    test("test1", root1, targetSum1, expected1);

    TreeNode* root2 = nullptr;
    int targetSum2 = 1;
    bool expected2 = false;
    test("test2", root2, targetSum2, expected2);

    return 0;
}
