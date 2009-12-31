#include <cstdio>
#include <string>
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

class Solution {
    ListNode* recursiveReverse(ListNode* node, ListNode* prev=nullptr)
    {
        if (!node)
            return prev;
        ListNode* next = node->next;
        node->next = prev;
        return recursiveReverse(next, node);
    }
public:
    ListNode* reverseList(ListNode* head) {
        return recursiveReverse(head, nullptr);
    }
};

void test(string test_name, ListNode* head, ListNode* expected)
{
    ListNode* res = Solution().reverseList(head);
    if (is_equal_list(res, expected))
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    ListNode* head1 = build_from_vector(vector<int>{1,2,3,4,5});
    ListNode* expected1 = build_from_vector(vector<int>{5,4,3,2,1});
    test("test1", head1, expected1);

    ListNode* head2 = build_from_vector(vector<int>{1,2});
    ListNode* expected2 = build_from_vector(vector<int>{2,1});
    test("test2", head2, expected2);

    ListNode* head3 = build_from_vector(vector<int>{});
    ListNode* expected3 = build_from_vector(vector<int>{});
    test("test3", head3, expected3);

    return 0;
}

