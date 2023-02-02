import ArrayUtils from './util_js/array.js';

/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
  let l = 0, r = numbers.length - 1;
  while (l < r) {
    const s = numbers[l] + numbers[r];
    if (s == target)
      return [l+1, r+1];
    else if (s < target)
      ++l;
    else
      --r;
  }
};

function test(test_name, numbers, target, expected) {
  const res = twoSum(numbers, target);
  if (ArrayUtils.isEqualArray(res, expected))
    console.log(test_name + ' succeed');
  else
    console.log(test_name + ' fail')
}

const numbers1 = [2,7,11,15];
const target1 = 9;
const expected1 = [1,2];
test('test1', numbers1, target1, expected1);

const numbers2 = [2,3,4];
const target2 = 6;
const expected2 = [1,3];
test('test2', numbers2, target2, expected2);

const numbers3 = [-1, 0];
const target3 = -1;
const expected3 = [1,2];
test('test3', numbers3, target3, expected3);
