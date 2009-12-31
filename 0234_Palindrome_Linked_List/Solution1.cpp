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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr, *next;
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reverseList(slow->next);
        ListNode *p1 = head, *p2 = slow->next;
        while (p2) {
            if (p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};

void test(string test_name, ListNode* head, bool expected)
{
    bool res = Solution().isPalindrome(head);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    ListNode* head1 = build_from_vector({1,2,2,1});
    bool expected1 = true;
    test("test1", head1, expected1);

    ListNode* head2 = build_from_vector({1,2});
    bool expected2 = false;
    test("test2", head2, expected2);

    return 0;
}

