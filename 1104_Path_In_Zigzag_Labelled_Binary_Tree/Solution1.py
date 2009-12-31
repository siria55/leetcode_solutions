from typing import *
from math import log2


class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        res = []
        while label > 1:
            res.append(label)
            parent = label // 2                  # label 在正常的完全二叉树中的父节点
            if parent == 1:
                break
            # 求 层数 的公式：log 后向下取整再 + 1
            h = int((log2(parent))) + 1            # 求 parent 所在正常完全二叉树层 h
            mid = (pow(2, h-1) + pow(2, h)-1) // 2 # h 层的中间节点
            # 求 label 在之字形二叉树的父结点
            # 即以 mid 中中心的镜像距离的节点
            # 上下两层由于 zigzag，一定是和正常镜像的
            if parent < mid:
                parent = mid + (mid - parent) + 1
            else:
                parent = mid - (parent - mid) + 1
            label = parent
        res.append(1)
        res.reverse()
        return res


def test(test_name, label, expected):
    res = Solution().pathInZigZagTree(label)
    if res == expected:
        print(test_name + ' succeed')
    else:
        print(test_name + ' fail')


if __name__ == '__main__':
    label1 = 14
    expected1 = [1,3,4,14]
    test('test1', label1, expected1)

    label2 = 26
    expected2 = [1,2,6,10,26]
    test('test2', label2, expected2)

    label3 = 16
    expected3 = [1,3,4,15,16]
    test('test3', label3, expected3)
