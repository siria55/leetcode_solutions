/**
 * @param {string} s
 * @param {string[]} dictionary
 * @return {string}
 */
 var findLongestWord = function(s, dictionary) {
  function isSubsequence(word, s) {
    let pw = 0;
    for (let ps = 0; ps < s.length; ps++)
      if (word[pw] == s[ps])
        pw++;
    return pw === word.length;
  }

  let res = "";
  for (let word of dictionary) {
    if (!isSubsequence(word, s))
      continue;
    if (res.length > word.length)
      continue;
    if (res.length < word.length || word < res)
      res = word;
  }
  return res;
};

function test(test_name, s, dictionary, expected) {
  const res = findLongestWord(s, dictionary);
  if (res === expected)
    console.log(test_name + " succeed");
  else
    console.log(test_name + " fail");
}

const s1 = "abpcplea";
const dictionary1 = ["ale","apple","monkey","plea"];
const expected1 = "apple";
test("test1", s1, dictionary1, expected1);

const s2 = "abpcplea";
const dictionary2 = ["a","b","c"];
const expected2 = "a";
test("test2", s2, dictionary2, expected2);
