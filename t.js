/**
 * @param {number[]} nums
 * @return {boolean}
 */
var checkPossibility = function(nums) {
  if (nums.length === 1)
    return true;
  let moded = nums[0] > nums[1];
  for (let i = 1; i < nums.length - 1; ++i) {
    if (nums[i] <= nums[i+1])
      continue;
    if (moded)
      return false;
    if (nums[i-1] <= nums[i+1])
      nums[i] = nums[i+1];
    else
      nums[i+1] = nums[i];
    moded = true;
  }
  return true;
};

function test(test_name, nums, expected) {
  let res = checkPossibility(nums);
  if (res === expected)
    console.log(test_name + ' succeed');
  else
    console.log(test_name + ' fail');
}

const nums1 = [4,2,3];
const expected1 = true;
test('test1', nums1, expected1);

const nums2 = [4,2,1];
const expected2 = false;
test('test2', nums2, expected2);

const nums3 = [3,4,2,3];
const expected3 = false;
test('test3', nums3, expected3);

const nums4 = [1,4,1,2];
const expected4 = true;
test('test4', nums4, expected4);
