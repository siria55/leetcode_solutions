import ArrayUtils from './util_js/array.js';

/**
 * @param {string} s
 * @return {number[]}
 */
var partitionLabels = function(s) {
  let lastIndexOfChar = Array(26).fill(0);
  let res = Array();

  for (let i = 0; i < s.length; ++i)
    lastIndexOfChar[s.charCodeAt(i)-'a'.charCodeAt(0)] = i;

  let start = 0, end = 0;
  for (let i = 0; i < s.length; ++i) {
    end = Math.max(end, lastIndexOfChar[s.charCodeAt(i)-'a'.charCodeAt(0)]);
    if (end === i) {
      res.push(end + 1 - start);
      start = end + 1;
    }
  }
  return res;
};

function test(test_name, s, expected) {
  const res = partitionLabels(s);
  if (ArrayUtils.isEqualArray(res, expected))
    console.log(test_name + ' succeed');
  else
    console.log(test_name + ' fail');
}

test('test1', 'ababcbacadefegdehijhklij', [9,7,8]);
test('test2', 'eccbbbbdec', [10]);
