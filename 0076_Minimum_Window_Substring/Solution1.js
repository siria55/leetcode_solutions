/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
  if (s.length < t.length)
    return "";

  let counter = Array(128).fill(0);
  let flag = Array(128).fill(false);
  for (const ch of t) {
    counter[ch.charCodeAt(0)]++;
    flag[ch.charCodeAt(0)] = true;
  }

  let l = 0;
  let cnt = 0, start = 0, minLength = s.length + 1;
  for (let r = 0; r < s.length; r++) {
    if (!flag[s.charCodeAt(r)])
      continue;
    if (--counter[s.charCodeAt(r)] >= 0)
      cnt++;
    while (cnt === t.length) {
      if (minLength > r + 1 - l) {
        minLength = r + 1 - l;
        start = l;
      }
      if (flag[s.charCodeAt(l)] && ++counter[s.charCodeAt(l)] > 0)
        cnt--;
      l++;
    }
  }
  return minLength === s.length + 1
    ? ""
    : s.substring(start, start + minLength);
};

function test(test_name, s, t, expected) {
  let res = minWindow(s, t);
  if (res === expected)
    console.log(test_name + ' succeed');
  else
    console.log(test_name + ' fail');
}

let s1 = 'ADOBECODEBANC';
let t1 = 'ABC';
let expected1 = 'BANC';
test('test1', s1, t1, expected1);

let s2 = 'a';
let t2 = 'a';
let expected2 = 'a';
test('test2', s2, t2, expected2);

let s3 = 'a';
let t3 = 'aa';
let expected3 = '';
test('test3', s3, t3, expected3);

let s4 = 'a';
let t4 = 'b';
let expected4 = '';
test('test4', s4, t4, expected4);
