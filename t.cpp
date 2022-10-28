#include <cstdio>
#include <string>
#include "util_cpp/list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast(head), *slow(head);
        do {
            if (!fast || !fast->next)
                return nullptr;
            fast = fast->next->next;
            slow = slow->next;
        } while (slow != fast);
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

void test(string test_name,
          ListNode* head,
          ListNode* expected) {
    ListNode *res = Solution().detectCycle(head);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main() {
    // [3,2,0,-4], pos = 1
    ListNode *head1 = build_from_vector({3,2,0,-4});
    head1->next->next->next->next = head1->next;
    ListNode *expected1 = head1->next;
    test("test1", head1, expected1);

    ListNode *head2 = build_from_vector({1, 2});
    head2->next->next = head2;
    ListNode *expected2 = head2;
    test("test2", head2, expected2);

    ListNode *head3 = build_from_vector({1});
    ListNode *expected3 = nullptr;
    test("test3", head3, expected3);

    return 0;
}
