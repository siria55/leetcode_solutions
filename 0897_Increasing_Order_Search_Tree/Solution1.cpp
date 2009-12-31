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
    TreeNode *prev{nullptr};

    void inDFS(TreeNode* node)
    {
        if (!node)
            return;
        inDFS(node->left);
        node->left = nullptr;
        prev->right = node;
        prev = node;
        inDFS(node->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *dummy = new TreeNode(0);
        prev = dummy;
        inDFS(root);
        return dummy->right;
    }
};

void test(string test_name, TreeNode* root, TreeNode* expected)
{
    TreeNode *res = Solution().increasingBST(root);
    if (is_equal_tree(res, expected))
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{

    //         5
    //       /   \
    //      3     6
    //     / \     \
    //    2   4     8
    //   /         / \
    //  1         7   9
    TreeNode *root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->left->left = new TreeNode(2);
    root1->left->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(4);
    root1->right = new TreeNode(6);
    root1->right->right = new TreeNode(8);
    root1->right->right->left = new TreeNode(7);
    root1->right->right->right = new TreeNode(9);
    TreeNode* expected1 = new TreeNode(1);
    expected1->right = new TreeNode(2);
    expected1->right->right = new TreeNode(3);
    expected1->right->right->right = new TreeNode(4);
    expected1->right->right->right->right = new TreeNode(5);
    expected1->right->right->right->right->right = new TreeNode(6);
    expected1->right->right->right->right->right->right = new TreeNode(7);
    expected1->right->right->right->right->right->right->right = new TreeNode(8);
    expected1->right->right->right->right->right->right->right->right = new TreeNode(9);
    test("test1", root1, expected1);

    //    5
    //   / \
    //  1   7
    TreeNode *root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(7);
    TreeNode *expected2 = new TreeNode(1);
    expected2->right = new TreeNode(5);
    expected2->right->right = new TreeNode(7);
    test("test2", root2, expected2);

    return 0;
}

