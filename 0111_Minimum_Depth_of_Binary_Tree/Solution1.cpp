#include <iostream>
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
public:
    int minDepth(TreeNode* root) {
        return get_depth(root);
    }
    int get_depth(TreeNode *node) {
        if (node == nullptr) return 0;
        if (node->left == nullptr)
            return get_depth(node->right) + 1;
        if (node->right == nullptr)
            return get_depth(node->left) + 1;
        return min(get_depth(node->left), get_depth(node->right)) + 1;
    }
};


void test(string test_name, TreeNode *root, int expected)
{
    int res = Solution().minDepth(root);
    if (res == expected) {
        cout << test_name << " succeed" << endl;
    } else {
        cout << test_name << " fail" << endl;
    }
}

int main()
{
    //     3
    //    / \
    //   9  20
    //     /  \
    //    15   7
    // return its minimum depth = 2.
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    int expected1 = 2;
    test("test1", root1, expected1);

    //   1
    //  /
    // 2
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    int expected2 = 2;
    test("test2", root2, expected2);

    //      2
    //       \
    //       3
    //        \
    //        4
    //         \
    //         5
    //          \
    //          6
    TreeNode *root3 = new TreeNode(3);
    root3->right = new TreeNode(3);
    root3->right->right = new TreeNode(4);
    root3->right->right->right = new TreeNode(5);
    root3->right->right->right->right = new TreeNode(6);
    int expected3 = 5;
    test("test3", root3, expected3);


    return 0;
}
