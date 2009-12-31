#include <cstdio>
#include <string>
#include <vector>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            res.push_back(node->val);
            if (node->right)                // 先右后左，出栈的时候先左后右
                stk.push(node->right);
            if (node->left)
                stk.push(node->left);
        }
        return res;
    }
};

void test(string test_name, TreeNode* root, vector<int> expected)
{
    vector<int> res = Solution().preorderTraversal(root);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    //    1
    //     \
    //      2
    //     /
    //    3
    TreeNode *root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->right->left = new TreeNode(3);
    vector<int> expected1{1,2,3};
    test("test1", root1, expected1);

    //    1
    //   /
    //  2
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    vector<int> expected2{1,2};
    test("test2", root2, expected2);

    return 0;
}
