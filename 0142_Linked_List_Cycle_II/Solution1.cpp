#include <iostream>
#include "util_cpp/list.h"
using namespace std;


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
            if (!fast || !fast->next) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

void test(const string& test_name,
          ListNode* head,
          ListNode* expected) {
    ListNode* res = Solution().detectCycle(head);
    if (res == expected) {
        cout << test_name + " succeed" << endl;
    } else {
        cout << test_name + " fail" << endl;
    }
}

int main() {
    // [3,2,0,-4], pos = 1
    ListNode *head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = head1->next;
    ListNode *expected1 = head1->next;
    test("test1", head1, expected1);

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = head2;
    ListNode *expected2 = head2;
    test("test2", head2, expected2);

    ListNode *head3 = new ListNode(1);
    ListNode *expected3 = nullptr;
    test("test3", head3, expected3);

    return 0;
}
