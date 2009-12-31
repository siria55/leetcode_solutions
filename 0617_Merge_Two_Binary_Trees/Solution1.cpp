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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 || !root2)
            return root1 ? root1 : root2;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

void test(string test_name, TreeNode* root1, TreeNode* root2, TreeNode* expected)
{
    TreeNode* res = Solution().mergeTrees(root1, root2);
    if (is_equal_tree(res, expected))
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    //       1
    //     /   \
    //    3     2
    //   /
    //  5
    TreeNode *root11 = new TreeNode(1);
    root11->left = new TreeNode(3);
    root11->left->left = new TreeNode(5);
    root11->right = new TreeNode(2);
    //       2
    //     /   \
    //    1     3
    //     \     \
    //      4     7
    TreeNode *root21 = new TreeNode(2);
    root21->left = new TreeNode(1);
    root21->left->right = new TreeNode(4);
    root21->right = new TreeNode(3);
    root21->right->right = new TreeNode(7);
    //        3
    //      /   \
    //     4     5
    //    / \     \
    //   5   4     7
    TreeNode *expected1 = new TreeNode(3);
    expected1->left = new TreeNode(4);
    expected1->left->left = new TreeNode(5);
    expected1->left->right = new TreeNode(4);
    expected1->right = new TreeNode(5);
    expected1->right->right = new TreeNode(7);
    test("test1", root11, root21, expected1);

    //    1
    TreeNode *root12 = new TreeNode(1);
    //    1
    //   /
    //  2
    TreeNode *root22 = new TreeNode(1);
    root22->left = new TreeNode(2);

    //    2
    //   /
    //  2
    TreeNode *expected2 = new TreeNode(2);
    expected2->left = new TreeNode(2);
    test("test2", root12, root22, expected2);

    return 0;
}

