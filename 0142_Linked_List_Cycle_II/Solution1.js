import ListUtils from './utils_js/list.js';

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

function test(testName, head, expected) {
  const res = detectCycle(head);
  if (res == expected) {
    console.log(testName + ' succeed');
  } else {
    console.log(testName + ' fail');
  }
}

const head1 = ListUtils.buildList([3,2,0,-4]);
head1.next.next.next.next = head1.next;
const expected1 = head1.next;
test('test1', head1, expected1);

const head2 = ListUtils.buildList([1,2]);
head2.next.next = head2;
const expected2 = head2;
test('test2', head2, expected2);

const head3 = ListUtils.buildList([1]);
const expected3 = null;
test('test3', head3, expected3);
