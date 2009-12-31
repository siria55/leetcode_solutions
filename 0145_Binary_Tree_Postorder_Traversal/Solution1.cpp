#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;

        TreeNode *p = root;
        stack<TreeNode*> stk;
        while (p || !stk.empty()) {
            while (p) {
                stk.push(p);
                res.push_back(p->val);
                p = p->right;
            }
            p = stk.top();
            stk.pop();
            p = p->left;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

void test(string test_name, TreeNode *root, vector<int> expected) {
    vector<int> res = Solution().postorderTraversal(root);
    if (res == expected) {
        printf("%s succeed\n", test_name.c_str());
    } else {
        printf("%s fail\n", test_name.c_str());
    }
}

int main() {
    //    1
    //     \
    //      2
    //     /
    //    3
    TreeNode *root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->right->left = new TreeNode(3);
    vector<int> expected1{3,2,1};
    test("test1", root1, expected1);

    //    1
    //   /
    //  2
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    vector<int> expected2{2,1};
    test("test2", root2, expected2);

    //    1
    //     \
    //      2
    TreeNode *root3 = new TreeNode(1);
    root3->right = new TreeNode(2);
    vector<int> expected3{2,1};
    test("test3", root3, expected3);

    //    1
    TreeNode *root4 = new TreeNode(1);
    vector<int> expected4{1};
    test("test4", root4, expected4);

    TreeNode *root5 = nullptr;
    vector<int> expected5;
    test("test5", root5, expected5);

    return 0;
}

