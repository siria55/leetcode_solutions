/**
 * @param {number[]} nums
 * @return {boolean}
 */
 var checkPossibility = function(nums) {
  let size = nums.length;
  if (size <= 1)
    return true;
  let moded = nums[0] > nums[1];
  for (let i = 1; i < size - 1; ++i) {
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

let nums1 = [4,2,3];
let expected1 = true;
test('test1', nums1, expected1);

let nums2 = [4,2,1];
let expected2 = false;
test('test2', nums2, expected2);

let nums3 = [3,4,2,3];
let expected3 = false;
test('test3', nums3, expected3);
