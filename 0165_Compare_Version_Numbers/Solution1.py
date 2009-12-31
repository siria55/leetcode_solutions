class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        d1s = version1.split('.')
        d2s = version2.split('.')
        N1, N2 = len(d1s), len(d2s)
        for i in range(max(N1, N2)):
            if i >= N1 or i >= N2:
                if i >= N2 and int(d1s[i]) != 0:
                    return 1
                if i >= N1 and int(d2s[i]) != 0:
                    return -1
                continue

            if int(d1s[i]) < int(d2s[i]):
                return -1
            elif int(d1s[i]) > int(d2s[i]):
                return 1
        return 0


def test(test_name, version1, version2, expected):
    res = Solution().compareVersion(version1, version2)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    version11 = "1.01"
    version21 = "1.001"
    expected1 = 0
    test('test1', version11, version21, expected1)

    version12 = "1.0"
    version22 = "1.0.0"
    expected2 = 0
    test('test2', version12, version22, expected2)

    version13 = "0.1"
    version23 = "1.1"
    expected3 = -1
    test('test3', version13, version23, expected3)

    version14 = "1.0.1"
    version24 = "1"
    expected4 = 1
    test('test4', version14, version24, expected4)

    version15 = "7.5.2.4"
    version25 = "7.5.3"
    expected5 = -1
    test('test5', version15, version25, expected5)
