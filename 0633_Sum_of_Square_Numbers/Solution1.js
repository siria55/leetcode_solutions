/**
 * @param {number} c
 * @return {boolean}
 */
var judgeSquareSum = function(c) {
    let l = 0, r = Math.floor(Math.sqrt(c));
    let sum;
    while (l <= r) {
      sum = l * l + r * r;
      if (sum < c)
        ++l;
      else if (sum > c)
        --r;
      else
        return true;
    }
    return false;
};

function test(test_name, c, expected) {
  let res = judgeSquareSum(c);
  if (res == expected)
    console.log(test_name + ' succeed');
  else
    console.log(test_name + ' fail');
}

let c1 = 5;
let expected1 = true;
test('test1', c1, expected1);

let c2 = 3;
let expected2 = false;
test('test2', c2, expected2)
