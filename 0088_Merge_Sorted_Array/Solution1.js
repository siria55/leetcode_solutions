import { ArrayUtils } from './util_js/array.js';

/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    let p1 = m - 1, p2 = n - 1, k = m + n - 1;
    while (p1 >= 0 && p2 >= 0)
      nums1[k--] = nums1[p1] > nums2[p2] ? nums1[p1--] : nums2[p2--];
    while (p2 >= 0)
      nums1[k--] = nums2[p2--];
};

function test(test_name, nums1, m, nums2, n, expected) {
  merge(nums1, m, nums2, n);
  if (ArrayUtils.isEqualArray(nums1, expected))
    console.log(test_name + ' succeed');
  else
    console.log(test_name + ' fail');
}

let nums11 = [1,2,3,0,0,0];
let m1 = 3;
let nums21 = [2,5,6];
let n1 = 3;
let expected1 = [1,2,2,3,5,6];
test('test1', nums11, m1, nums21, n1, expected1);
