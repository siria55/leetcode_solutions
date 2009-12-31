/**
 * @param {number} columnNumber
 * @return {string}
 */
var convertToTitle = function(columnNumber) {
  let res = '';
  while (columnNumber) {
    --columnNumber;
    let mod = columnNumber % 26;
    columnNumber = Math.floor(columnNumber / 26);
    res = String.fromCharCode('A'.codePointAt() + mod) + res;
  }
  return res;
};

function test(test_name, columnNumber, expected) {
  let res = convertToTitle(columnNumber);
  if (res == expected)
    console.log(test_name + ' succeed');
  else
    console.log(test_name + ' fail');
}

test('test1', 1, 'A');
test('test2', 28, 'AB');
test('test3', 701, 'ZY');
