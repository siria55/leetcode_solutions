/**
 * @param {number} num
 * @return {string}
 */
var convertToBase7 = function(num) {
  if (num == 0)
    return '0';

  let is_neg = num < 0;
  if (is_neg)
    num = -num;

  let res = '';
  while (num) {
    let div = Math.floor(num/7);
    let mod = num % 7;
    res = mod + res;
    num = div;
  }
  return is_neg ? '-' + res : res;
};

test = function(test_name, num, expected) {
  let res = convertToBase7(num);
  if (res === expected)
    console.log(test_name + ' succeed');
  else
    console.log(test_name + ' fail');
}

test('test1', 100, '202');
test('test2', -7, '-10');
