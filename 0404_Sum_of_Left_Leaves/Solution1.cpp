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
    int sumOfLeftLeaves(TreeNode* root) {
        int res{0};
        if (!root)
            return res;
        if (root->left &&
            !root->left->left &&
            !root->left->right)
            res += root->left->val;
        res += sumOfLeftLeaves(root->left);
        res += sumOfLeftLeaves(root->right);
        return res;
    }
};

void test(string test_name, TreeNode *root, int expected) {
    int res = Solution().sumOfLeftLeaves(root);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main() {
    //      3
    //    /   \
    //   9    20
    //       /  \
    //      15   7
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    int expected1 = 24;
    test("test1", root1, expected1);

    TreeNode *root2 = new TreeNode(1);
    int expected2 = 0;
    test("test2", root2, expected2);

    return 0;
}
