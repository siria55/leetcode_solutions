#include "list.h"
using namespace std;

bool is_equal_list(ListNode *l1, ListNode *l2)
{
    while (true) {
        if (!l1 && !l2)
            return true;
        if (!l1 || !l2)
            return false;
        if (l1->val != l2->val)
            return false;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
}

void print_list(ListNode *list)
{
    while(list) {
        std::cout << list->val << " ";
        list = list->next;
    }
    std::cout << std::endl;
}

ListNode* build_from_vector(vector<int> vec)
{
    ListNode* dummy = new ListNode(0);
    ListNode* p = dummy;
    for (int n : vec) {
        p->next = new ListNode(n);
        p = p->next;
    }
    return dummy->next;
}

vector<int> build_vector(ListNode* list)
{
    vector<int> res;
    ListNode *p = list;
    while (p) {
        res.push_back(p->val);
        p = p->next;
    }
    return res;
}

