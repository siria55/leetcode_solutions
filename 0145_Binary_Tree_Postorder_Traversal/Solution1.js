/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {
  let res = '';
  let p1 = num1.length - 1, p2 = num2.length - 1
  let carry = 0;
  while (p1 >= 0 || p2 >= 0 || carry) {
    let v1 = 0, v2 = 0;
    if (p1 >= 0)
      v1 = parseInt(num1[p1--]);
    if (p2 >= 0)
      v2 = parseInt(num2[p2--]);
    sum = v1 + v2 + carry;
    res = String(sum%10) + res;
    carry = Math.floor(sum/10);
  }
  return res;
};

var test = function(test_name, num1, num2, expected) {
  let res = addStrings(num1, num2);
  if (res === expected)
    console.log(test_name + ' succeed')
  else
    console.log(test_name + ' fail')
}

test('test1', '11', '123', '134')
test('test2', '456', '77', '533')
test('test3', '0', '0', '0')
