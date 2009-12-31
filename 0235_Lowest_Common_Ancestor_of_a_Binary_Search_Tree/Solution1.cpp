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
        // root is between p and q
        if ((root->val - p->val) * (root->val - q->val) <= 0)
            return root;
        // p and q are at same side of root
        TreeNode *node = root->val > p->val ? root->left : root->right;
        return lowestCommonAncestor(node, p, q);
    }
};

void test(string test_name,
          TreeNode *root,
          TreeNode *p,
          TreeNode *q,
          TreeNode *expected) {
    TreeNode *res = Solution().lowestCommonAncestor(root, p, q);
    if (res == expected) {
        printf("%s succeed\n", test_name.c_str());
    } else {
        printf("%s fail\n", test_name.c_str());
    }
}

int main() {
    //         6
    //       /   \
    //      2     8
    //     / \   / \
    //    0  4  7   9
    //      / \
    //     3  5
    TreeNode *root1 = new TreeNode(6);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(0);
    root1->left->right = new TreeNode(4);
    root1->left->right->left = new TreeNode(3);
    root1->left->right->right = new TreeNode(5);
    root1->right = new TreeNode(8);
    root1->right->left = new TreeNode(7);
    root1->right->right = new TreeNode(9);
    TreeNode *p1 = root1->left;          // 2
    TreeNode *q1 = root1->right;         // 8
    TreeNode *expected1 = root1;         // 6
    test("test1", root1, p1, q1, expected1);

    //         6
    //       /   \
    //      2     8
    //     / \   / \
    //    0   4 7   9
    //      / \
    //     3  5
    TreeNode *root2 = new TreeNode(6);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(0);
    root2->left->right = new TreeNode(4);
    root2->left->right->left = new TreeNode(3);
    root2->left->right->right = new TreeNode(5);
    root2->right = new TreeNode(8);
    root2->right->left = new TreeNode(7);
    root2->right->right = new TreeNode(9);
    TreeNode *p2 = root2->left;          // 2
    TreeNode *q2 = root2->left->right;   // 4
    TreeNode *expected2 = root2->left;   // 2
    test("test2", root2, p2, q2, expected2);

    TreeNode *root3 = new TreeNode(2);
    root3->left = new TreeNode(1);
    TreeNode *p3 = root3;
    TreeNode *q3 = root3->left;
    TreeNode *expected3 = root3;
    test("test3", root3, p3, q3, expected3);

    return 0;
}

