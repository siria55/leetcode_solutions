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
    bool isMirror(TreeNode* l, TreeNode* r)
    {
        if (!l && !r)
            return true;
        if (!l || !r)
            return false;
        if (l->val != r->val)
            return false;
        return isMirror(l->left, r->right) &&
               isMirror(l->right, r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return isMirror(root->left, root->right);
    }
};

void test(string test_name, TreeNode *root, bool expected)
{
    Solution s;
    if (s.isSymmetric(root) == expected) {
        printf("%s succeed\n", test_name.c_str());
    } else {
        printf("%s fail\n", test_name.c_str());
    }
}

int main()
{
    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(3);
    t1->left->right = new TreeNode(4);
    t1->right->left = new TreeNode(4);
    t1->right->right = new TreeNode(3);
    bool expected1 = true;
    //     1
    //    / \
    //   2   2
    //  / \ / \
    // 3  4 4  3
    test("test1", t1, expected1);

    TreeNode *t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->left->right = new TreeNode(3);
    t2->right = new TreeNode(2);
    t2->right->right = new TreeNode(3);
    bool expected2 = false;
    //     1
    //    / \
    //   2   2
    //    \   \
    //     3    3
    test("test2", t2, expected2);

    TreeNode *t3 = nullptr;
    bool expected3 = true;
    test("test3", t3, expected3);

    return 0;
}
