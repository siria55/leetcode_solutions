#include <cstdio>
#include <string>
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root)
            return nullptr;
        if (root->val < low)
            return trimBST(root->right, low, high);
        if (root->val > high)
            return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

void test(string test_name,
          TreeNode* root,
          int low,
          int high,
          TreeNode* expected)
{
    auto res = Solution().trimBST(root, low, high);
    if (is_equal_tree(res, expected))
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    //     1
    //    / \
    //   0   2
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(0);
    root1->right = new TreeNode(2);
    int low1{1}, high1{2};
    //     1
    //      \
    //       2
    TreeNode* expected1 = new TreeNode(1);
    expected1->right = new TreeNode(2);
    test("test1", root1, low1, high1, expected1);

    //      3
    //     / \
    //    0   4
    //     \
    //      2
    //     /
    //    1
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(0);
    root2->left->right = new TreeNode(2);
    root2->left->right->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    int low2{1}, high2{3};
    //       3
    //      /
    //     2
    //    /
    //   1
    TreeNode* expected2 = new TreeNode(3);
    expected2->left = new TreeNode(2);
    expected2->left->left = new TreeNode(1);
    test("test2", root2, low2, high2, expected2);

    return 0;
}

