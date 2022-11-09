/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var detectCycle = function(head) {
  let fast = head, slow = head;
  do {
    if (!fast || !fast.next)
      return null;
    fast = fast.next.next;
    slow = slow.next;
  } while (fast != slow);

  fast = head;
  while (fast != slow) {
    fast = fast.next;
    slow = slow.next;
  }
  return slow;
};
