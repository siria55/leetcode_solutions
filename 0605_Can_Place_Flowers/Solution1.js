/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function(flowerbed, n) {
  let i = 0;
  while (i < flowerbed.length) {
    if (flowerbed[i] === 1) {
      i += 2;
    } else {
      if (i === flowerbed.length - 1 || flowerbed[i+1] === 0) {
        --n;
        i += 2;
      } else
        i += 3;
    }
  }
  return n <= 0;
};

function test(test_name, flowerbed, n, expected) {
  const res = canPlaceFlowers(flowerbed, n);
  if (res == expected)
    console.log(test_name + ' succeed');
  else
    console.log(test_name + ' fail');
}

const flowerbed1 = [1,0,0,0,1];
const n1 = 1;
const expected1 = true;
test('test1', flowerbed1, n1, expected1);

const flowerbed2 = [1,0,0,0,1];
const n2 = 2;
const expected2 = false;
test('test2', flowerbed2, n2, expected2);

const flowerbed3 = [1,0,0,0,1,0,0];
const n3 = 2;
const expected3 = true;
test('test3', flowerbed3, n3, expected3);
