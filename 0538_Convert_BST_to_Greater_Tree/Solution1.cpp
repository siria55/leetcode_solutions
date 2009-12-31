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
    int sum{0};
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root)
            return root;
        convertBST(root->right);
        int val = root->val;
        root->val += sum;
        sum += val;
        convertBST(root->left);
        return root;
    }
};

void test(string test_name, TreeNode* root, TreeNode* expected)
{
    TreeNode *res = Solution().convertBST(root);
    if (is_equal_tree(res, expected))
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    //        4
    //      /   \
    //     1     6
    //    / \   / \
    //   0   2 5   7
    //        \     \
    //         3     8
    TreeNode *root1 = new TreeNode(4);
    root1->left = new TreeNode(1);
    root1->left->left = new TreeNode(0);
    root1->left->right = new TreeNode(2);
    root1->left->right->right = new TreeNode(3);
    root1->right = new TreeNode(6);
    root1->right->left = new TreeNode(5);
    root1->right->right = new TreeNode(7);
    root1->right->right->right = new TreeNode(8);
    //        30
    //      /    \
    //     36     21
    //    /  \   /  \
    //   36  35 26  15
    //        \       \
    //         33      8
    TreeNode *expected1 = new TreeNode(30);
    expected1->left = new TreeNode(36);
    expected1->left->left = new TreeNode(36);
    expected1->left->right = new TreeNode(35);
    expected1->left->right->right = new TreeNode(33);
    expected1->right = new TreeNode(21);
    expected1->right->left = new TreeNode(26);
    expected1->right->right = new TreeNode(15);
    expected1->right->right->right = new TreeNode(8);
    test("test1", root1, expected1);

    //      0
    //       \
    //        1
    TreeNode *root2 = new TreeNode(0);
    root2->right = new TreeNode(1);
    //      1
    //       \
    //        1
    TreeNode *expected2 = new TreeNode(1);
    expected2->right = new TreeNode(1);
    test("test2", root2, expected2);

    return 0;

}

