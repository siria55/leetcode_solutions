/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfThree = function(n) {
  if (n <= 0)
    return false;
  while (n % 3 == 0) {
    n /= 3;
  }
  return n == 1;
};

function test(test_name, n, expected) {
  let res = isPowerOfThree(n);
  if (res === expected)
    console.log(test_name + ' succeed');
  else
    console.log(test_name + ' fail');
}

test('test1', 27, true);
test('test2', 0, false);
test('test3', 9, true);
test('test4', 45, false);
