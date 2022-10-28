import { ArrayUtils } from './util_js/array.js';

/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
  let l = 0, r = numbers.length - 1;
  while (l < r) {
    let s = numbers[l] + numbers[r];
    if (s < target)
      ++l;
    else if (s > target)
      --r;
    else
      return [l+1, r+1];
  }
  return [];
};

function test(test_name, numbers, target, expected) {
  let res = twoSum(numbers, target);
  if (ArrayUtils.isEqualArray(res, expected))
    console.log(test_name + ' succeed');
  else
    console.log(test_name + ' fail');
}

let numbers1 = [2,7,11,15];
let target1 = 9;
let expected1 = [1,2];
test('test1', numbers1, target1, expected1);

let numbers2 = [2,3,4];
let target2 = 6;
let expected2 = [1,3];
test('test2', numbers2, target2, expected2);

let numbers3 = [-1, 0];
let target3 = -1;
let expected3 = [1,2];
test('test3', numbers3, target3, expected3);