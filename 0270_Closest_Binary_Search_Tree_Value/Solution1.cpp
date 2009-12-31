#include <iostream>
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
    int closestValue(TreeNode* root, double target) {
        TreeNode *p = root;
        int closest = p->val;
        while (p != nullptr) {
            closest = abs(p->val - target) < abs(closest - target) ? p->val : closest;
            p = target < p->val ? p->left : p->right;
        }
        return closest;
    }
};

void test(string test_name, TreeNode *root, double target, int expected) {
    int res = Solution().closestValue(root, target);
    if (res == expected)
        cout << test_name + " succeed" << endl;
    else
        cout << test_name + " fail" << endl;
}

int main() {
    //       4
    //      / \
    //     2  5
    //    / \
    //   1  3
    TreeNode *root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    root1->right = new TreeNode(5);
    double target1 = 3.714286;
    int expected1 = 4;
    test("test1", root1, target1, expected1);

    TreeNode *root2 = new TreeNode(1);
    double target2 = 4.428571;
    int expected2 = 1;
    test("test2", root2, target2, expected2);

    return 0;
}
