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
    int getValidCount(TreeNode *node, int sum)
    {
        if (!node)
            return 0;
        int count = node->val == sum ? 1 : 0;
        count += getValidCount(node->left, sum - node->val);
        count += getValidCount(node->right, sum - node->val);
        return count;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;
        return getValidCount(root, targetSum) +
               pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }
};

void test(string test_name, TreeNode* root, int targetSum, int expected)
{
    int res = Solution().pathSum(root, targetSum);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    //          10
    //        /   \
    //       5     -3
    //     /   \     \
    //    3     2     11
    //   / \     \
    //  3  -2     1
    TreeNode *root1 = new TreeNode(10);
    root1->left = new TreeNode(5);
    root1->left->left = new TreeNode(3);
    root1->left->left->left = new TreeNode(3);
    root1->left->left->right = new TreeNode(-2);
    root1->left->right = new TreeNode(2);
    root1->left->right->right = new TreeNode(1);
    root1->right = new TreeNode(-3);
    root1->right->right = new TreeNode(11);
    int targetSum1 = 8;
    int expected1 = 3;
    test("test1", root1, targetSum1, expected1);

    return 0;
}

