class Solution:
    def checkRecord(self, s: str) -> bool:
        A_count, consecutive_L_count = 0, 0
        N = len(s)
        for i in range(N):
            if s[i] == 'A':
                A_count += 1
            if s[i] == 'L':
                if i == 0:
                    consecutive_L_count = 1
                elif s[i] == s[i-1]:
                    consecutive_L_count += 1
                else:
                    consecutive_L_count = 1
            else:
                consecutive_L_count = 0

            if A_count >= 2 or consecutive_L_count >= 3:
                return False
        return True


def test(test_name, s, expected):
    res = Solution().checkRecord(s)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    s1 = 'PPALLP'
    expected1 = True
    test('test1', s1, expected1)

    s2 = 'PPALLL'
    expected2 = False
    test('test2', s2, expected2)
