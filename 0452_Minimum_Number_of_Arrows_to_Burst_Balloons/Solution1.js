/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function(points) {
  points.sort((x, y) => {
    if (x[1] < y[1])
      return -1;
    return 1;
  });
  let res = 1;
  let tail = points[0][1];
  for (let i = 1; i < points.length; ++i) {
    if (tail < points[i][0]) {
      ++res;
      tail = points[i][1];
    }
  };
  return res;
};

function test(test_name, points, expected) {
  const res = findMinArrowShots(points);
  if (res === expected)
    console.log(test_name + ' succeed');
  else
    console.log(test_name + ' fail');
}

const points1 = [[10,16],[2,8],[1,6],[7,12]];
const expected1 = 2;
test('test1', points1, expected1);

const points2 = [[1,2],[3,4],[5,6],[7,8]];
const expected2 = 4;
test('test2', points2, expected2);

const points3 = [[1,2],[2,3],[3,4],[4,5]];
const expected3 = 2;
test('test3', points3, expected3);

const points4 = [[1,2]];
const expected4 = 1;
test('test4', points4, expected4);

const points5 = [[2,3],[2,3]];
const expected5 = 1;
test('test5', points5, expected5);

const points6 = [[1,2],[2,3],[3,4],[4,5]];
const expected6 = 2;
test('test6', points6, expected6);

const points7 = [[-2147483648,2147483647]];
const expected7 = 1;
test('test7', points7, expected7);

const points8 = [[3,9],[7,12],[3,8],[6,8],[9,10],[2,9],[0,9],[3,9],[0,6],[2,8]];
const expected8 = 2;
test('test8', points8, expected8);
