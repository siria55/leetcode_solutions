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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        while (p1 != p2) {
            p1 = p1 ? p1->next : headB;
            p2 = p2 ? p2->next : headA;
        }
        return p1;
    }
};

void test(string test_name, ListNode *headA, ListNode *headB, ListNode* expected)
{
    ListNode* res = Solution().getIntersectionNode(headA, headB);
    if (is_equal_list(res, expected))
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    ListNode* headA1 = build_from_vector(vector<int>{4,1,8,4,5});
    ListNode* headB1 = new ListNode(5);
    headB1->next = new ListNode(6);
    headB1->next->next = new ListNode(1);
    headB1->next->next->next = headA1->next->next;
    ListNode* expected1 = build_from_vector(vector<int>{8,4,5});
    test("test1", headA1, headB1, expected1);

    ListNode* headA2 = build_from_vector(vector<int>{1,9,1,2,4});
    ListNode* headB2 = new ListNode(3);
    headB2->next = headA2->next->next->next;
    ListNode* expected2 = build_from_vector(vector<int>{2,4});
    test("test2", headA2, headB2, expected2);

    ListNode* headA3 = build_from_vector(vector<int>{2,6,4});
    ListNode* headB3 = build_from_vector(vector<int>{1,5});
    ListNode* expected3 = nullptr;
    test("test3", headA3, headB3, expected3);

    return 0;
}

