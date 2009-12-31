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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int len = preorder.size();
        if (!len)
            return nullptr;
        TreeNode* node = new TreeNode(preorder[0]);
        if (len == 1)
            return node;

        // e.g. pre [1] + [2, 4, 5] + [3, 6, 7]
        // post [4, 5, 2] + [6, 7, 3] + [1]
        // left count = pre[1] at post + 1
        int left_count{0};
        for (int i = 0; i < len; ++i)
            if (preorder[1] == postorder[i]) {
                left_count = i + 1;
                break;
            }
        vector<int> pre_l = vector<int>(preorder.begin()+1, preorder.begin()+1+left_count);
        vector<int> pre_r = vector<int>(preorder.begin()+1+left_count, preorder.end());
        vector<int> pos_l = vector<int>(postorder.begin(), postorder.begin()+left_count);
        vector<int> pos_r = vector<int>(postorder.begin()+left_count, postorder.end()-1);
        node->left = constructFromPrePost(pre_l, pos_l);
        node->right = constructFromPrePost(pre_r, pos_r);
        return node;
    }
};

// this question does not test

