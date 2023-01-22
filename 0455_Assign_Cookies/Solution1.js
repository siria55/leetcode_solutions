function compareNumbers(a, b) {
  return a - b;
}

/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function(g, s) {
  g.sort(compareNumbers);
  s.sort(compareNumbers);
  let child = 0, cookie = 0;
  while (child < g.length && cookie < s.length) {
    if (g[child] <= s[cookie++]) {
      ++child;
    }
  }
  return child;
};

function test(test_name, g, s, expected) {
  let res = findContentChildren(g, s);
  if (res === expected)
    console.log(test_name + ' succeed');
  else
    console.log(test_name + ' fail');
}

const g1 = [1,2,3];
const s1 = [1,1];
test('test1', g1, s1, 1);

const g2 = [1,2];
const s2 = [1,2,3];
test('test2', g2, s2, 2);

const g3 = [10,9,8,7];
const s3 = [5,6,7,8];
test('test3', g3, s3, 2);
