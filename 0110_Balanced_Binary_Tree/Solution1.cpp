#include <cstdio>
#include <string>
#include <cmath>
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
    int depth(TreeNode* node)
    {
        if (!node)
            return 0;
        int l = depth(node->left);
        int r = depth(node->right);
        if (l == -1 || r == -1)
            return -1;
        if (abs(l-r) > 1)
            return -1;
        return max(l, r) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
};

void test(string test_name, TreeNode *root, bool expected)
{
    bool res = Solution().isBalanced(root);
    if (res == expected) {
        printf("%s succeed\n", test_name.c_str());
    } else {
        printf("%s fail\n", test_name.c_str());
    }
}

int main()
{
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    bool expected1 = true;
    //     3
    //    / \
    //   9  20
    //     /  \
    //    15   7
    test("test1", root1, expected1);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);
    root2->left->left->right = new TreeNode(4);
    //        1
    //       / \
    //      2   2
    //     / \
    //    3   3
    //   / \
    //  4   4
    bool expected2 = false;
    test("test2", root2, expected2);

    return 0;
}
