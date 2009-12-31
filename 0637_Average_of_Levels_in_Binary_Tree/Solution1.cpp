#include <cstdio>
#include <string>
#include <vector>
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {
            int cnt = q.size();
            double sum{0.0};
            for (int i = 0; i < cnt; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res.push_back(sum / cnt);
        }

        return res;
    }
};

void test(string test_name, TreeNode* root, vector<double> expected)
{
    auto res = Solution().averageOfLevels(root);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    //     3
    //   /   \
    //  9    20
    //      /  \
    //     15   7
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    vector<double> expected1{3.0, 14.5, 11.0};
    test("test1", root1, expected1);

    //         3
    //       /   \
    //      9    20
    //    /   \
    //   15    7
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(9);
    root2->left->left = new TreeNode(15);
    root2->left->right = new TreeNode(7);
    root2->right = new TreeNode(20);
    vector<double> expected2{3.0, 14.5, 11.0};
    test("test2", root2, expected2);

    return 0;
}

