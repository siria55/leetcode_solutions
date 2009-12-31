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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *ohead = head, *ehead = head->next;
        ListNode *p1 = ohead, *p2 = ehead;
        while (p2 && p2->next) {
            p1->next = p1->next->next;
            p2->next = p2->next->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = ehead;
        return head;
    }
};

void test(string test_name, ListNode* head, ListNode* expected)
{
    ListNode* res = Solution().oddEvenList(head);
    if (is_equal_list(res, expected))
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    ListNode* head1 = build_from_vector({1,2,3,4,5});
    ListNode* expected1 = build_from_vector({1,3,5,2,4});
    test("test1", head1, expected1);

    ListNode* head2 = build_from_vector({2,1,3,5,6,4,7});
    ListNode* expected2 = build_from_vector({2,3,6,7,1,5,4});
    test("test2", head2, expected2);

    return 0;
}

