#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(NULL) {}
    TreeNode(int x) : val(x), left(nullptr), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

enum class orderType
{
    pre, in, post
};

bool is_equal_tree(TreeNode* t1, TreeNode* t2);
bool is_balanced_tree(TreeNode* root);
vector<int> get_order(TreeNode* root, orderType order_type);

#endif
