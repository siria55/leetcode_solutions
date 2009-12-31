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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        if (p == root || q == root)
            return root;
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        if (!l) return r;
        if (!r) return l;
        return root;
    }
};

void test(string test_name,
          TreeNode* root,
          TreeNode* p,
          TreeNode* q,
          TreeNode* expected)
{
    TreeNode* res = Solution().lowestCommonAncestor(root, p, q);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    //        3
    //      /   \
    //     5     1
    //    / \   / \
    //   6   2 0   8
    //      / \
    //     7   4
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);
    root1->right = new TreeNode(1);
    root1->right->left = new TreeNode(0);
    root1->right->right = new TreeNode(8);
    TreeNode *p1 = root1->left;
    TreeNode *q1 = root1->right;
    TreeNode *expected1 = root1;
    test("test1", root1, p1, q1, expected1);

    TreeNode *root2 = root1;
    TreeNode *p2 = root2->left;
    TreeNode *q2 = root2->left->right->right->right;
    TreeNode *expected2 = root2->left;
    test("test2", root2, p2, q2, expected2);

    TreeNode *root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    TreeNode *p3 = root3;
    TreeNode *q3 = root3->left;
    TreeNode* expected3 = root3;
    test("test3", root3, p3, q3, expected3);

    return 0;
}

