#include <cstdio>
#include <string>
#include <vector>
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        if (key > root->val)
            root->right = deleteNode(root->right, key);
        if (key == root->val) {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            TreeNode *left_most = root->right;
            while (left_most->left)
                left_most = left_most->left;
            left_most->left = root->left;
            root = root->right;
        }
        return root;
    }
};

void test(string test_name, TreeNode* root, int key)
{
    vector<int> old_vec = get_order(root, orderType::in);
    TreeNode *res_t = Solution().deleteNode(root, key);
    vector<int> res_vec = get_order(res_t, orderType::in);
    auto it = remove_if(old_vec.begin(), old_vec.end(), [=](const int& x){ return x == key; });
    old_vec.erase(it, old_vec.end());
    if (old_vec == res_vec)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    //      5
    //    /   \
    //   3     6
    //  / \     \
    // 2   4     7
    TreeNode *root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);
    root1->right = new TreeNode(6);
    root1->right->right = new TreeNode(7);
    int key1 = 3;
    test("test1", root1, key1);

    //      5
    //    /   \
    //   3     6
    //  / \     \
    // 2   4     7
    TreeNode *root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(4);
    root2->right = new TreeNode(6);
    root2->right->right = new TreeNode(7);
    int key2 = 0;
    test("test2", root2, key2);

    TreeNode *root3{nullptr};
    int key3 = 0;
    test("test3", root3, key3);

    return 0;
}

