/**
 * @param {number} c
 * @return {boolean}
 */
 var judgeSquareSum = function(c) {
  let l = 0, r = Math.floor(Math.sqrt(c));
  while (l <= r) {
    const s = l * l + r * r;
    if (s > c)
      r--;
    else if (s < c)
      l++;
    else
      return true;
  }
  return false;
};

function test(test_name, c, expected) {
let res = judgeSquareSum(c);
if (res == expected)
  console.log(test_name + " succeed");
else
  console.log(test_name + " fail");
}

const c1 = 5;
const expected1 = true;
test("test1", c1, expected1);

const c2 = 3;
const expected2 = false;
test("test2", c2, expected2);

const c3 = 2;
const expected3 = true;
test("test3", c3, expected3);
