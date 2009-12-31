#include <cstdio>
#include <string>
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
    unordered_set<int> s;
    int k;
    bool in_dfs(TreeNode* node)
    {
        if (!node)
            return false;
        if (in_dfs(node->left))
            return true;

        int n2find = k - node->val;
        if (s.find(n2find) != s.end())
            return true;
        s.insert(node->val);

        if (in_dfs(node->right))
            return true;
        return false;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        this->k = k;
        return in_dfs(root);
    }
};

void test(string test_name, TreeNode* root, int k, bool expected)
{
    bool res = Solution().findTarget(root, k);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    //      5
    //    /   \
    //   3     6
    //  / \     \
    // 2   4     7
    TreeNode *root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);
    root1->right = new TreeNode(6);
    root1->right->right = new TreeNode(7);
    int k1{9};
    bool expected1{true};
    test("test1", root1, k1, expected1);

    TreeNode *root2 = root1;
    int k2{28};
    bool expected2{false};
    test("test2", root2, k2, expected2);

    return 0;
}

