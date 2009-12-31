#include <cstdio>
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
    void deleteNode(ListNode* node) {
        *(node) = *(node->next);
    }
};

void test(string test_name, ListNode* node, ListNode *expected, ListNode *head)
{
    Solution().deleteNode(node);
    if (is_equal_list(head, expected))
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    // head = [4,5,1,9], node = 5
    ListNode *head1 = build_from_vector(vector<int>{4,5,1,9});
    ListNode *expected1 = build_from_vector(vector<int>{4,1,9});
    test("test1", head1->next, expected1, head1);

    return 0;

}
