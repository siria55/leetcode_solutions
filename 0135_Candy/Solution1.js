/**
 * @param {number[]} ratings
 * @return {number}
 */
var candy = function(ratings) {
  if (ratings.length === 1)
    return 1;
  let num = Array(ratings.length).fill(1);
  for (let i = 1; i < ratings.length; ++i) {
    if (ratings[i] > ratings[i-1])
      num[i] = num[i-1] + 1;
  }
  console.log(num);
  for (let i = ratings.length - 2; i >= 0; --i) {
    if (ratings[i] >  ratings[i+1])
      num[i] = Math.max(num[i], num[i+1] + 1);
  }
  console.log(num);
  return num.reduce((partialSum, a) => partialSum + a, 0);
};

function test(test_name, ratings, expected) {
  const res = candy(ratings);
  if (res === expected) {
    console.log(test_name + ' succeed');
  } else {
    console.log(test_name + ' fail');
  }
}

const ratings1 = [1,0,2];
const expected1 = 5;
test('test1', ratings1, expected1);

const ratings2 = [1,2,2];
const expected2 = 4;
test('test2', ratings2, expected2);

const ratings3 = [1,3,4,5,2];
const expected3 = 11;
test('test3', ratings3, expected3);

const ratings4 = [1,2];
const expected4 = 3;
test('test4', ratings4, expected4);
