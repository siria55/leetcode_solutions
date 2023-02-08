/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
  if (s.length < t.length)
    return '';

  const counter = Array(128).fill(0);     // 记录 t 中已经出现的各个字符，但窗口中还差的个数
  const flags = Array(128).fill(false);   // 记录字符是否在 t 中
  for (const ch of t) {
    counter[ch.charCodeAt(0)]++;
    flags[ch.charCodeAt(0)] = true;
  }

  let l = 0;
  let cnt = 0, start = 0, minLength = s.length + 1; // cnt 表示 s 窗口中满足 t 的个数
  for (let r = 0; r < s.length; ++r) {
    if (!flags[s.charCodeAt(r)])
      continue;
    if (--counter[s.charCodeAt(r)] >= 0)
      ++cnt;
    while (cnt == t.length) {
      if (minLength > r + 1 - l) {
        minLength = r + 1 - l;
        start = l;
      }
      if (flags[s.charCodeAt(l)] && ++counter[s.charCodeAt(l)] > 0)
        --cnt;
      ++l;
    }
  }
  return minLength === s.length + 1 ? '' : s.slice(start, start + minLength);
};

function test(test_name, s, t, expected) {
  const res = minWindow(s, t);
  if (res === expected)
    console.log(test_name + ' succeed');
  else
    console.log(test_name + ' fail');
}

const s1 = 'ADOBECODEBANC';
const t1 = 'ABC';
const expected1 = 'BANC';
test('test1', s1, t1, expected1);

const s2 = 'a';
const t2 = 'a';
const expected2 = 'a';
test('test2', s2, t2, expected2);

const s3 = 'a';
const t3 = 'aa';
const expected3 = '';
test('test3', s3, t3, expected3);

const s4 = 'a';
const t4 = 'b';
const expected4 = '';
test('test4', s4, t4, expected4);
