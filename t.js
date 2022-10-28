import { ListUtils } from './util_js/list.js';

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
      if (!(fast && fast.next))
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

function test(test_name, head, expected) {
  let res = detectCycle(head);
  if (res === expected)
    console.log(test_name + ' succeed');
  else
    console.log(test_name + ' fail');
}

let head1 = ListUtils.buildList([3,2,0,-4]);
head1.next.next.next.next = head1.next;
let expected1 = head1.next;
test('test1', head1, expected1);

let head2 = ListUtils.buildList([1,2]);
head2.next.next = head2;
let expected2 = head2;
test('test2', head2, expected2);

let head3 = ListUtils.buildList([1]);
let expected3 = null;
test('test3', head3, expected3);
