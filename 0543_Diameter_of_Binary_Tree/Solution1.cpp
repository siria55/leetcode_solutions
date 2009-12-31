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
    int res = 0;
    int getDepth(TreeNode* node)
    {
        if (!node)
            return 0;
        int l_depth = getDepth(node->left);
        int r_depth = getDepth(node->right);
        res = max(res, l_depth + r_depth);
        return max(l_depth, r_depth) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        getDepth(root);
        return res;
    }
};

void test(string test_name, TreeNode *root, int expected) {
    int res = Solution().diameterOfBinaryTree(root);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main() {
    //       1
    //     /  \
    //    2    3
    //   / \
    //  4  5
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right = new TreeNode(3);
    int expected1 = 3;
    test("test1", root1, expected1);

    //   1
    //  /
    // 2
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    int expected2 = 1;
    test("test2", root2, expected2);

    //             1
    //           /   \
    //          2     3
    //              /   \
    //             4     5
    //           /   \    \
    //          6     7     8
    //         /     /  \
    //        9     10  11
    //      /  \   /    /
    //    12   13 14   15
    //   /            /
    //  16           17
    TreeNode *root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->right->right = new TreeNode(5);
    root3->right->right->right = new TreeNode(8);
    root3->right->left = new TreeNode(4);
    root3->right->left->left = new TreeNode(6);
    root3->right->left->left->left = new TreeNode(9);
    root3->right->left->left->left->left = new TreeNode(12);
    root3->right->left->left->left->left->left = new TreeNode(16);
    root3->right->left->left->left->right = new TreeNode(13);
    root3->right->left->right = new TreeNode(7);
    root3->right->left->right->left = new TreeNode(10);
    root3->right->left->right->left->left = new TreeNode(14);
    root3->right->left->right->right = new TreeNode(11);
    root3->right->left->right->right->left = new TreeNode(15);
    root3->right->left->right->right->left->left = new TreeNode(17);
    int expected3 = 8;  // 16 -> 12 -> 9 -> 6 -> 4 -> 7 -> 11 -> 15 -> 17
    test("test3", root3, expected3);

    return 0;
}
