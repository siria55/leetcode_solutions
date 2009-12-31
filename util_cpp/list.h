#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
};

bool is_equal_list(ListNode* l1, ListNode* l2);

void print_list(ListNode *list);

ListNode* build_from_vector(std::vector<int> vec);
vector<int> build_vector(ListNode* list);

#endif

