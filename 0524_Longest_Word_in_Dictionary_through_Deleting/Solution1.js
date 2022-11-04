/**
 * @param {string} s
 * @param {string[]} dictionary
 * @return {string}
 */
var findLongestWord = function(s, dictionary) {
  function isSubsequence(word, s) {
    let pw = 0;
    for (let ps = 0; ps < s.length; ++ps)
      if (word[pw] === s[ps]) ++pw;
    return pw === word.length;
  }

  let res = '';
  for (let word of dictionary) {
    if (!isSubsequence(word, s))
      continue;
    if (res.length < word.length || (res.length === word.length && word < res))
      res = word;
  }
  return res;
};
