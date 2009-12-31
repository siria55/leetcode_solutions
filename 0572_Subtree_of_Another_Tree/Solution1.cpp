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
    bool isEqualTree(TreeNode* root1, TreeNode* root2)
    {
        if (!root1 && !root2)
            return true;
        if (!root1 || !root2)
            return false;
        if (root1->val != root2->val)
            return false;
        return isEqualTree(root1->left, root2->left) &&
               isEqualTree(root1->right, root2->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot)
            return true;
        if (!root)
            return false;
        return isEqualTree(root, subRoot) ||
               isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};

void test(string test_name, TreeNode* root, TreeNode* subRoot, bool expected)
{
    bool res = Solution().isSubtree(root, subRoot);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    //      3
    //    /   \
    //   4     5
    //  / \
    // 1   2
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(4);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(2);
    root1->right = new TreeNode(5);
    //   4
    //  / \
    // 1   2
    TreeNode *subRoot1 = new TreeNode(4);
    subRoot1->left = new TreeNode(1);
    subRoot1->right = new TreeNode(2);
    bool expected1{true};
    test("test1", root1, subRoot1, expected1);

    //       3
    //     /   \
    //    4     5
    //   / \
    //  1   2
    //     /
    //    0
    TreeNode *root2 = new TreeNode(3);
    root2->left = new TreeNode(4);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(2);
    root2->left->right->left = new TreeNode(0);
    root2->right = new TreeNode(5);
    //    4
    //   / \
    //  1   2
    TreeNode *subRoot2 = new TreeNode(4);
    subRoot2->left = new TreeNode(1);
    subRoot2->right = new TreeNode(2);
    bool expected2{false};
    test("test2", root2, subRoot2, expected2);

    TreeNode *root3 = new TreeNode(1);
    root3->right = new TreeNode(1);
    root3->right->right = new TreeNode(1);
    root3->right->right->right = new TreeNode(1);
    root3->right->right->right->right = new TreeNode(1);
    root3->right->right->right->right->right = new TreeNode(1);
    root3->right->right->right->right->right->right = new TreeNode(1);
    root3->right->right->right->right->right->right->right = new TreeNode(1);
    root3->right->right->right->right->right->right->right->left = new TreeNode(2);
    TreeNode *subRoot3 = new TreeNode(1);
    subRoot3->right = new TreeNode(1);
    subRoot3->right->right = new TreeNode(1);
    subRoot3->right->right->left = new TreeNode(2);
    bool expected3{true};
    test("test3", root3, subRoot3, expected3);

    return 0;
}

