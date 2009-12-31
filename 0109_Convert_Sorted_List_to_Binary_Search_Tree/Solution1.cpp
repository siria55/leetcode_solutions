#include <cstdio>
#include <string>
#include <vector>
#include "util_cpp/tree.h"
#include "util_cpp/list.h"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* buildTree(ListNode* head, ListNode* tail)
    {
        if (head == tail)
            return nullptr;
        ListNode *fast{head}, *slow{head};
        while (fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode *node = new TreeNode(slow->val);
        node->left = buildTree(head, slow);
        node->right = buildTree(slow->next, tail);
        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, nullptr);
    }
};

void test(string test_name, ListNode* head)
{
    TreeNode* res = Solution().sortedListToBST(head);
    vector<int> in = get_order(res, orderType::in);
    vector<int> list_order = build_vector(head);
    if (in == list_order && is_balanced_tree(res))
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    ListNode *head1 = build_from_vector({-10,-3,0,5,9});
    test("test1", head1);

    ListNode *head2 = build_from_vector({});
    test("test2", head2);

    return 0;
}

