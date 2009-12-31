/**
 * @param {number[]} nums
 */
var Solution = function(nums) {
  this.origin = nums.slice();
};

/**
 * @return {number[]}
 */
Solution.prototype.reset = function() {
  return this.origin.slice();
};

/**
 * @return {number[]}
 */
Solution.prototype.shuffle = function() {
  let res = this.origin.slice();
  for (let i = 0; i < res.length; ++i) {
    let j = Math.floor(Math.random() * (res.length - i)) + i;
    let tmp = res[i];
    res[i] = res[j];
    res[j] = tmp;
  }
  return res;
};

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(nums)
 * var param_1 = obj.reset()
 * var param_2 = obj.shuffle()
 */