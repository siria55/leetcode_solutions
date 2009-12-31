#include <cstdio>
#include <string>
#include <queue>
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
    int findBottomLeftValue(TreeNode* root) {
        int res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if (i == 0)
                    res = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return res;
    }
};

void test(string test_name, TreeNode* root, int expected)
{
    int res = Solution().findBottomLeftValue(root);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    //    2
    //   / \
    //  1   3
    TreeNode *root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    int expected1{1};
    test("test1", root1, expected1);

    //      1
    //    /   \
    //   2     3
    //  /     / \
    // 4     5   6
    //      /
    //     7
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(4);
    root2->right = new TreeNode(3);
    root2->right->left = new TreeNode(5);
    root2->right->left->left = new TreeNode(7);
    root2->right->right = new TreeNode(6);
    int expected2{7};
    test("test2", root2, expected2);

    return 0;
}

