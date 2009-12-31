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
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return nullptr;
        TreeNode *l = invertTree(root->left);
        TreeNode *r = invertTree(root->right);
        root->left = r;
        root->right = l;
        return root;
    }
};

void test(string test_name, TreeNode *root, TreeNode *expected) {
    TreeNode *res = Solution().invertTree(root);
    if (is_equal_tree(res, expected))
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main() {
    //         4
    //       /  \
    //      2    7
    //     / \  / \
    //    1   3 6  9
    TreeNode *root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    root1->right = new TreeNode(7);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(9);
    //         4
    //       /  \
    //      7    2
    //     / \  / \
    //    9   6 3  1
    TreeNode *expected1 = new TreeNode(4);
    expected1->left = new TreeNode(7);
    expected1->left->left = new TreeNode(9);
    expected1->left->right = new TreeNode(6);
    expected1->right = new TreeNode(2);
    expected1->right->left = new TreeNode(3);
    expected1->right->right = new TreeNode(1);
    test("test1", root1, expected1);

    //     2
    //    / \
    //   1   3
    TreeNode *root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    //    2
    //   / \
    //  3   1
    TreeNode *expected2 = new TreeNode(2);
    expected2->left = new TreeNode(3);
    expected2->right = new TreeNode(1);
    test("test2", root2, expected2);

    TreeNode *root3 = nullptr;
    TreeNode *expected3 = nullptr;
    test("test3", root3, expected3);

    return 0;
}
