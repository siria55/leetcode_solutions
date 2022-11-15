/**
 * @param {string} s
 * @return {boolean}
 */
 var validPalindrome = function(s) {
  function isPal(s, l, r) {
    while (l < r) {
      if (s[l++] !== s[r--])
        return false;
    }
    return true;
  }

  let l = 0, r = s.length - 1;
  while (l < r) {
    if (s[l] !== s[r])
      return isPal(s, l+1, r) || isPal(s, l, r-1);
    l++;
    r--;
  }
  return true;
};

function test(test_name, s, expected) {
const res = validPalindrome(s);
if (res === expected)
  console.log(test_name + " succeed");
else
  console.log(test_name + " fail");
}

const s1 = "aba";
const expected1 = true;
test("test1", s1, expected1);

const s2 = "abca";
const expected2 = true;
test("test2", s2, expected2);

const s3 = "abc";
const expected3 = false;
test("test3", s3, expected3);
