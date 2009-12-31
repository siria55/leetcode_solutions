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
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        ListNode *p1 = list1, *p2 = list2;
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
};

void test(string test_name, ListNode* list1, ListNode* list2, ListNode* expected)
{
    ListNode* res = Solution().mergeTwoLists(list1, list2);
    if (is_equal_list(res, expected))
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    ListNode* list11 = build_from_vector({1,2,4});
    ListNode* list21 = build_from_vector({1,3,4});
    ListNode* expected1 = build_from_vector({1,1,2,3,4,4});
    test("test1", list11, list21, expected1);

    ListNode* list12 = build_from_vector({});
    ListNode* list22 = build_from_vector({});
    ListNode* expected2 = build_from_vector({});
    test("test2", list12, list22, expected2);

    ListNode* list13 = build_from_vector({});
    ListNode* list23 = build_from_vector({0});
    ListNode* expected3 = build_from_vector({0});
    test("test3", list13, list23, expected3);

    return 0;
}

