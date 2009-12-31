class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return '0'

        is_neg = num < 0
        if is_neg:
            num = -num

        res = ''
        while num:
            div, mod = divmod(num, 7)
            res = str(mod) + res
            num = div

        return '-' + res if is_neg else res

def test(test_name, num, expected):
    res = Solution().convertToBase7(num)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    num1 = 100
    expected1 = '202'
    test('test1', num1, expected1)

    num2 = -7
    expected2 = '-10'
    test('test2', num2, expected2)

