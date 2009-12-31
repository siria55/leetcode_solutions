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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head;
        while (n--) {
            p1 = p1->next;
        }
        // n 保证了是合法的。这里如果没有fast，表示n == 链表长度。所以跳过第一个就可以了
        if (!p1) {
            return head->next;
        }
        ListNode *p2 = head;
        while (p1->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return head;
    }
};

void test(string test_name, ListNode* head, int n, ListNode* expected)
{
    ListNode* res = Solution().removeNthFromEnd(head, n);
    if (is_equal_list(res, expected))
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    ListNode* head1 = build_from_vector({1,2,3,4,5});
    int n1 = 2;
    ListNode* expected1 = build_from_vector({1,2,3,5});
    test("test1", head1, n1, expected1);

    ListNode* head2 = build_from_vector({1});
    int n2 = 1;
    ListNode* expected2 = build_from_vector({});
    test("test2", head2, n2, expected2);

    ListNode* head3 = build_from_vector({1,2});
    int n3 = 1;
    ListNode* expected3 = build_from_vector({1});
    test("test3", head3, n3, expected3);

    return 0;
}

