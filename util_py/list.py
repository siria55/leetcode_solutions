# Definition for singly-linked list.

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


Node = ListNode


def is_equal_list(l1: ListNode, l2: ListNode):
    if not l1 and not l2:
        return True
    if not l1 or not l2:
        return False
    if l1.val != l2.val:
        return False
    return is_equal_list(l1.next, l2.next)


def print_list(lst: ListNode, length=None):
    res = get_built_in_list(lst)
    print(res[:length])


def build_list(arr):
    head = ListNode(0)
    p = head
    for n in arr:
        p.next = ListNode(n)
        p = p.next
    return head.next


def get_built_in_list(head):
    p = head
    res = []
    while p:
        res.append(p.val)
        p = p.next;
    return res

