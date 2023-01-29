/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  let res = 0;
  for (let i = 1; i < prices.length; ++i) {
    res += Math.max(0, prices[i] -prices[i-1]);
  }
  return res;
};

function test(test_name, prices, expected) {
  const res = maxProfit(prices);
  if (res === expected)
    console.log(test_name + ' succeed');
  else
    console.log(test_name + ' fail');
}

test('test1', [7,1,5,3,6,4], 7);
test('test2', [1,2,3,4,5], 4);
test('test3', [7,6,4,3,1], 0);
