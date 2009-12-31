from typing import *


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res = []
        lines_of_words = []
        cur_line_words = []
        cur_width = 0

        # step1 add split words in lines
        idx = 0
        while idx < len(words):
            # new line
            if cur_width == 0:
                cur_width += len(words[idx])
                cur_line_words.append(words[idx])
                idx += 1
            elif cur_width <= maxWidth:
                cur_width += 1 + len(words[idx])
                cur_line_words.append(words[idx])
                idx += 1

            if cur_width >= maxWidth:
                if cur_width > maxWidth:
                    cur_line_words.pop()  # go back to last word
                    idx -= 1
                lines_of_words.append(cur_line_words[:])
                cur_line_words = []
                cur_width = 0
            elif idx == len(words):
                lines_of_words.append(cur_line_words[:])

        for line in lines_of_words[:-1]:
            origin_width = sum([len(w) for w in line]) + (len(line)-1)
            wid_diff = maxWidth - origin_width
            if len(line) == 1:
                res.append(line[0] + ' ' * wid_diff)
                continue

            if wid_diff > 0:
                q, r = divmod(wid_diff, len(line)-1)
            else:
                q, r = 0, 0
            cur_str = ''
            for i in range(len(line)-1):
                cur_str += line[i] + (q+1+(1 if r > 0 else 0)) * ' '
                r -= 1
            cur_str += line[-1]
            res.append(cur_str)

        # last line left justify
        last_str = ' '.join(lines_of_words[-1])
        wid_diff = maxWidth - len(last_str)
        if wid_diff > 0:
            last_str += ' ' * wid_diff
        res.append(last_str)

        return res



def test(test_name, words, maxWidth, expected):
    res = Solution().fullJustify(words, maxWidth)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')

if __name__ == '__main__':
    words1 = ['This', 'is', 'an', 'example', 'of', 'text', 'justification.']
    maxWidth1 = 16
    expected1 = [
        'This    is    an',
        'example  of text',
        'justification.  '
    ]
    test('test1', words1, maxWidth1, expected1)

    words2 = ['What','must','be','acknowledgment','shall','be']
    maxWidth2 = 16
    expected2 = [
        'What   must   be',
        'acknowledgment  ',
        'shall be        '
    ]
    test('test2', words2, maxWidth2, expected2)

    words3 = ['Science','is','what','we','understand','well','enough','to','explain','to','a','computer.','Art','is','everything','else','we','do']
    maxWidth3 = 20
    expected3 = [
        'Science  is  what we',
        'understand      well',
        'enough to explain to',
        'a  computer.  Art is',
        'everything  else  we',
        'do                  '
    ]
    test('test3', words3, maxWidth3, expected3)

    words4 = ['ask','not','what','your','country','can','do','for','you','ask','what','you','can','do','for','your','country']
    maxWidth4 = 16
    expected4 = [
        'ask   not   what',
        'your country can',
        'do  for  you ask',
        'what  you can do',
        'for your country'
    ]
    test('test4', words4, maxWidth4, expected4)
