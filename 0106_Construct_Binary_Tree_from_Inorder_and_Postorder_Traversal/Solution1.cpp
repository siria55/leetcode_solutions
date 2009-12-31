#include <cstdio>
#include <string>
#include <vector>
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
    vector<int> inorder, postorder;

    TreeNode *build(int i1, int i2, int p1, int p2)
    {
        TreeNode *node = new TreeNode(postorder[p2]);
        int root_idx{i1};
        for (int i = i1; i <= i2; ++i)
            if (inorder[i] == node->val) {
                root_idx = i;
                break;
            }
        int left_count = root_idx-i1;
        if (root_idx > i1)
            node->left = build(i1, root_idx-1, p1, p1+left_count-1);
        if (root_idx < i2)
            node->right = build(root_idx+1, i2, p1+left_count, p2-1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        int len = inorder.size();
        return build(0, len-1, 0, len-1);
    }
};

void test(string test_name,
          vector<int> &inorder,
          vector<int> &postorder,
          TreeNode* expected)
{
    TreeNode *res = Solution().buildTree(inorder, postorder);
    if (is_equal_tree(res, expected)) {
        printf("%s succeed\n", test_name.c_str());
    } else {
        printf("%s fail\n", test_name.c_str());
    }
}

int main()
{

    // inorder = [9,3,15,20,7]
    // postorder = [9,15,7,20,3]
    // Return the following binary tree:
    //     3
    //    / \
    //   9  20
    //     /  \
    //    15   7
    vector<int> in1{9,3,15,20,7};
    vector<int> post1{9, 15, 7, 20, 3};
    TreeNode *expected1 = new TreeNode(3);
    expected1->left = new TreeNode(9);
    expected1->right = new TreeNode(20);
    expected1->right->left = new TreeNode(15);
    expected1->right->right = new TreeNode(7);
    test("test1", in1, post1, expected1);

    return 0;
}

