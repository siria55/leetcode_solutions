from collections import defaultdict


class Solution:
    def countArrangement(self, n: int) -> int:
        match = defaultdict(list)    # 预处理满足 i 的列表，列表中的 j 都满足 i
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if i % j == 0 or j % i == 0:
                    match[i].append(j)

        num = 0
        visited = set()

        def backtrack(idx):
            if idx == n + 1:
                nonlocal num
                num += 1
                return

            # 如果 match[idx] 列表能让 idx 加到 n+1，说明 1 到 n 都满足了。结果 count 可以加 1
            for x in match[idx]:
                if x not in visited:
                    visited.add(x)
                    backtrack(idx + 1)
                    visited.remove(x)
        backtrack(1)
        return num


def test(test_name, n, expected):
    res = Solution().countArrangement(n)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    n1 = 2
    expected1 = 2
    test('test1', n1, expected1)

    n2 = 1
    expected2 = 1
    test('test2', n2, expected2)
