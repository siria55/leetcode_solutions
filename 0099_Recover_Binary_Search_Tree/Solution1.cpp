#include <cstdio>
#include <string>
#include <vector>
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
    void inorder(TreeNode* node, TreeNode*& mistake1,
                 TreeNode*& mistake2, TreeNode*& prev)
    {
        if (node->left)
            inorder(node->left, mistake1, mistake2, prev);

        if (prev && prev->val > node->val) {
            if (mistake1) {      // 第一次是 prev 的问题，第二次是 node 的问题
                mistake2 = node;
            } else {
                mistake1 = prev;
                mistake2 = node;
            }
        }
        prev = node;

        if (node->right)
            inorder(node->right, mistake1, mistake2, prev);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode *mistake1{nullptr}, *mistake2{nullptr}, *prev{nullptr};
        inorder(root, mistake1, mistake2, prev);
        swap(mistake1->val, mistake2->val);
    }
};

void test(string test_name, TreeNode* root, TreeNode* expected)
{
    Solution().recoverTree(root);
    if (is_equal_tree(root, expected))
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    //    1
    //   /
    //  3
    //   \
    //    2
    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->left->right = new TreeNode(2);

    //    3
    //   /
    //  1
    //   \
    //    2
    TreeNode *expected1 = new TreeNode(3);
    expected1->left = new TreeNode(1);
    expected1->left->right = new TreeNode(2);
    test("test1", t1, expected1);

    //    3
    //   / \
    //  1   4
    //     /
    //    2
    TreeNode *t2 = new TreeNode(3);
    t2->left = new TreeNode(1);
    t2->right = new TreeNode(4);
    t2->right->left = new TreeNode(2);

    //     2
    //    / \
    //   1   4
    //      /
    //     3
    TreeNode *expected2 = new TreeNode(2);
    expected2->left = new TreeNode(1);
    expected2->right = new TreeNode(4);
    expected2->right->left = new TreeNode(3);
    test("test2", t2, expected2);

    return 0;
}

