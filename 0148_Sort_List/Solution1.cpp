#include <cstdio>
#include <string>
#include <vector>
#include <climits>
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
    // [head, tail)
    ListNode* splitAndMerge(ListNode* head, ListNode* tail)
    {
        if (!head)
            return head;
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode *slow = head, *fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
                fast = fast->next;
        }
        return merge(splitAndMerge(head, slow),
                     splitAndMerge(slow, tail));
    }
    ListNode* merge(ListNode* h1, ListNode* h2)
    {
        ListNode *dummy = new ListNode();
        ListNode *p1 = h1, *p2 = h2;
        ListNode *cur = dummy;
        while (p1 || p2) {
            int v1 = p1 ? p1->val : INT_MAX;
            int v2 = p2 ? p2->val : INT_MAX;
            if (v1 < v2) {
                cur->next = p1;
                p1 = p1->next;
            } else {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        return splitAndMerge(head, nullptr);
    }
};

void test(string test_name, ListNode* head, ListNode* expected)
{
    ListNode* res = Solution().sortList(head);
    if (is_equal_list(res, expected))
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    ListNode* head1 = build_from_vector({4,2,1,3});
    ListNode* expected1 = build_from_vector({1,2,3,4});
    test("test1", head1, expected1);

    ListNode* head2 = build_from_vector({-1,5,3,4,0});
    ListNode* expected2 = build_from_vector({-1,0,3,4,5});
    test("test2", head2, expected2);

    ListNode* head3 = nullptr;
    ListNode* expected3 = nullptr;
    test("test3", head3, expected3);

    return 0;
}

