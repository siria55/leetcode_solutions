/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function(s) {
    let l = 0, r = s.length - 1;

    function isPal(s, l, r) {
      while (l < r)
        if (s[l++] !== s[r--])
          return false;
      return true;
    }

    while (l < r) {
      if (s[l] !== s[r])
        return isPal(s, l+1, r) || isPal(s, l, r-1);
      ++l;
      --r;
    }
    return true;
};

function test(test_name, s, expected) {
  let res = validPalindrome(s);
  if (res === expected)
    console.log(test_name + ' succeed');
  else
    console.log(test_name + ' fail');
}

let s1 = 'aba';
let expected1 = true;
test('test1', s1, expected1);

let s2 = 'abca';
let expected2 = true;
test('test2', s2, expected2);

let s3 = 'abc';
let expected3 = false;
test('test3', s3, expected3);
