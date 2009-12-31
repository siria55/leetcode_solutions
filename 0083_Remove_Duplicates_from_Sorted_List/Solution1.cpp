#include <cstdio>
#include <string>
#include <vector>
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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        while (p && p->next) {
            while (p->next && p->val == p->next->val) {
                ListNode *tmp = p->next;
                p->next = tmp->next;
                delete tmp;
            }
            p = p->next;
        }
        return head;
    }
};

void test(string test_name, ListNode* head, ListNode* expected)
{
    ListNode* res = Solution().deleteDuplicates(head);
    if (is_equal_list(res, expected))
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    ListNode *head1 = build_from_vector({1,1,2});
    ListNode *expected1 = build_from_vector({1,2});
    test("test1", head1, expected1);

    ListNode *head2 = build_from_vector({1,1,2,3,3});
    ListNode *expected2 = build_from_vector({1,2,3});
    test("test2", head2, expected2);

    ListNode *head3 = build_from_vector({0,0,0,0,0});
    ListNode *expected3 = build_from_vector({0});
    test("test3", head3, expected3);

    return 0;
}

