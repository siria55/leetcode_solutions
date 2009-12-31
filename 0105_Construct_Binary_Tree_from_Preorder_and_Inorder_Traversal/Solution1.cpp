#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
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
    TreeNode* builder(unordered_map<int, int>& in2idx,
                      vector<int>& preorder,
                      int sin, int ein, int spre)
    {
        if (sin > ein)
            return nullptr;
        int mid_val = preorder[spre];
        int mid_idx = in2idx[mid_val];
        int left_count = mid_idx - sin;

        TreeNode *node = new TreeNode(mid_val);
        node->left = builder(in2idx, preorder, sin, mid_idx-1, spre+1);
        node->right = builder(in2idx, preorder, mid_idx+1, ein, spre+1+left_count);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> in2idx;
        int len = preorder.size();
        for (int i = 0; i < len; ++i)
            in2idx[inorder[i]] = i;
        return builder(in2idx, preorder, 0, len-1, 0);
    }
};

void get_postorder(TreeNode *T, vector<int> &postorder)
{
    if (T == nullptr)
        return;
    get_postorder(T->left, postorder);
    get_postorder(T->right, postorder);
    postorder.push_back(T->val);
}

void test(string test_name, vector<int> &preorder, vector<int> &inorder, vector<int> &expected_post)
{
    Solution s;
    vector<int> postorder;
    TreeNode *tree = s.buildTree(preorder, inorder);

    get_postorder(tree, postorder);
    if (postorder == expected_post)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    // preorder = [3,9,20,15,7]
    // inorder = [9,3,15,20,7]
    // Return the following binary tree:
    //     3
    //    / \
    //   9  20
    //     /  \
    //    15   7
    vector<int> pre1{3,9,20,15,7};
    vector<int> in1{9,3,15,20,7};
    vector<int> expected1{9, 15, 7, 20, 3};
    test("test1", pre1, in1, expected1);

    vector<int> pre2;
    vector<int> in2;
    vector<int> expected2;
    test("test2", pre2, in2, expected2);

    return 0;
}
