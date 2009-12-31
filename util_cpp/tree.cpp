#include <vector>
#include "tree.h"
using namespace std;

bool is_equal_tree(TreeNode* t1, TreeNode* t2)
{
    if (!t1 && !t2)
        return true;
    if (!t1 || !t2)
        return false;
    if (t1->val != t2->val)
        return false;
    return is_equal_tree(t1->left, t2->left) && is_equal_tree(t1->right, t2->right);
}

bool is_balanced_t(TreeNode* root)
{
    if (!root)
        return 0;
    int l = is_balanced_t(root->left);
    int r = is_balanced_t(root->right);
    if (l == -1 || r == -1)
        return -1;
    if (abs(l-r) > 1)
        return -1;
    return max(l, r) + 1;
}

bool is_balanced_tree(TreeNode* root)
{
    if (!root) return true;
    return is_balanced_t(root);
}

void pre_dfs(TreeNode* node, vector<int>& pre)
{
    if (!node) return;
    pre.push_back(node->val);
    pre_dfs(node->left, pre);
    pre_dfs(node->right, pre);
}

void in_dfs(TreeNode* node, vector<int>& in)
{
    if (!node) return;
    in_dfs(node->left, in);
    in.push_back(node->val);
    in_dfs(node->right, in);
}

void post_dfs(TreeNode* node, vector<int>& post)
{
    if (!node) return;
    post_dfs(node->left, post);
    post_dfs(node->right, post);
    post.push_back(node->val);
}

vector<int> get_order(TreeNode* root, orderType order_type)
{
    vector<int> res;
    switch (order_type) {
        case orderType::pre:
            pre_dfs(root, res);
            break;
        case orderType::in:
            in_dfs(root, res);
            break;
        case orderType::post:
            post_dfs(root, res);
            break;
    }
    return res;
}

