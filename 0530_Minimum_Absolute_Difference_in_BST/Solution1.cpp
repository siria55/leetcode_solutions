#include <cstdio>
#include <string>
#include <climits>
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
    int res{INT_MAX}, pre{-1};
    void dfs(TreeNode* node)
    {
        if (!node)
            return;
        dfs(node->left);
        if (pre != -1)
            res = min(res, abs(node->val - pre));
        pre = node->val;
        dfs(node->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return res;
    }
};

void test(string test_name, TreeNode *root, int expected)
{
    int res = Solution().getMinimumDifference(root);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}


int main()
{
    //      4
    //     / \
    //    2   6
    //   / \
    //  1  3
    TreeNode *root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    root1->right = new TreeNode(6);
    int expected1{1};
    test("test1", root1, expected1);

    //       1
    //     /  \
    //    0   48
    //       /  \
    //      12  49
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(48);
    root2->right->left = new TreeNode(12);
    root2->right->right = new TreeNode(49);
    int expected2{1};
    test("test2", root2, expected2);
}

