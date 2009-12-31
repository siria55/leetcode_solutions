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
    int dfs(TreeNode* node)
    {
        if (!node)
            return 0;
        int sum_l = dfs(node->left);
        int sum_r = dfs(node->right);
        res += abs(sum_l-sum_r);
        return sum_l + sum_r + node->val;
    }
public:
    int findTilt(TreeNode* root) {
        dfs(root);
        return res;
    }
};

void test(string test_name, TreeNode* root, int expected) {
    int res = Solution().findTilt(root);
    if (res == expected) {
        cout << test_name + " succeed" << endl;
    } else {
        cout << test_name + " fail" << endl;
    }
}

int main() {
    //     1
    //    / \
    //   2  3
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    int expected1 = 1;
    test("test1", root1, expected1);

    //      4
    //    /   \
    //   2    9
    //  / \    \
    // 3  5    7
    TreeNode *root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(5);
    root2->right = new TreeNode(9);
    root2->right->right = new TreeNode(7);
    int expected2 = 15;
    test("test2", root2, expected2);

    //         21
    //       /   \
    //      7    14
    //     / \  /  \
    //    1  1 2   2
    //   / \
    //  3  3
    TreeNode *root3 = new TreeNode(21);
    root3->left = new TreeNode(7);
    root3->left->left = new TreeNode(1);
    root3->left->right = new TreeNode(1);
    root3->left->left->left = new TreeNode(3);
    root3->left->left->right = new TreeNode(3);
    root3->right = new TreeNode(14);
    root3->right->left = new TreeNode(2);
    root3->right->right = new TreeNode(2);
    int expected3 = 9;
    test("test3", root3, expected3);

    return 0;
}
