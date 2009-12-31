/**
 * @param {number} n
 * @return {number}
 */
var trailingZeroes = function(n) {
  let res = 0, base = 5;
  while (Math.floor(n/base)) {
    res += Math.floor(n/base);
    n = Math.floor(n/base);

  }
  return res;
};

var test = function(test_name, n, expected) {
  let res = trailingZeroes(n);
  if (res == expected)
    console.log(test_name + ' succeed');
  else
    console.log(test_name + ' fail');
}

test('test1', 3, 0);
test('test2', 5, 1);
test('test3', 10, 2);
test('test4', 30, 7);
