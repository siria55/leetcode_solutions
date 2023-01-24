/**
 * @param {number[][]} intervals
 * @return {number}
 */
var eraseOverlapIntervals = function(intervals) {
  intervals.sort(function(a, b) {
    if (a[1] < b[1])
      return -1;
    return 1;
  });
  let removed = 0, prev = intervals[0][1];
  for (let i = 1; i < intervals.length; ++i) {
    if (prev > intervals[i][0]) {
      ++removed;
    } else {
      prev = intervals[i][1];
    }
  }
  return removed;
};

function test(test_name, intervals, expected) {
  const res = eraseOverlapIntervals(intervals);
  if (res === expected)
    console.log(test_name + ' succeed')
  else
    console.log(test_name + ' fail')
}

const intervals1 = [[1,2], [2,3], [3,4], [1,3]];
const expected1 = 1;
test('test1', intervals1, expected1);

const intervals2 = [[1,2], [1,2], [1,2]];
const expected2 = 2;
test('test2', intervals2, expected2);

const intervals3 = [[1,2],[2,3]];
const expected3 = 0;
test('test3', intervals3, expected3);

const intervals4 = [[1,100],[11,22],[1,11],[2,12]];
const expected4 = 2;
test('test4', intervals4, expected4);
