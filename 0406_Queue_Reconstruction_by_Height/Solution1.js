import ArrayUtil from './util_js/array.js';

/**
 * @param {number[][]} people
 * @return {number[][]}
 */
var reconstructQueue = function(people) {
  people.sort((a, b) => {
    if (a[0] === b[0])
      return a[1] - b[1];
    return b[0] - a[0];
  });
  let res = [];
  for (const pair of people) {
    res.splice(pair[1], 0, pair);
  }
  return res;
};

function test(test_name, people, expected) {
  const res = reconstructQueue(people);
  if (ArrayUtil.isEqualArray(res, expected))
    console.log(test_name + ' succeed');
  else
    console.log(test_name + ' fail');
}

const people1 = [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]];
const expected1 = [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]];
test('test1', people1, expected1)
