import heapq

class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.q_min = list()
        self.q_max = list()
        heapq.heapify(self.q_min)
        heapq.heapify(self.q_max)

    def addNum(self, num: int) -> None:
        q_min, q_max = self.q_min, self.q_max
        if not q_min or num <= -q_min[0]:
            heapq.heappush(q_min, -num)
            if len(q_min) == len(q_max) + 2:
                heapq.heappush(q_max, -heapq.heappop(q_min))
        if num > -q_min[0]:
            heapq.heappush(q_max, num)
            if len(q_max) > len(q_min):
                heapq.heappush(q_min, - heapq.heappop(q_max))

    def findMedian(self) -> float:
        q_min, q_max = self.q_min, self.q_max
        if len(q_min) == len(q_max) + 1:
            return float(-q_min[0])
        else:
            return float((q_max[0] + -q_min[0]) / 2)


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()

def test1():
    obj = MedianFinder()
    obj.addNum(1)
    obj.addNum(2)
    res1 = obj.findMedian()  # 1.5
    obj.addNum(3)
    res2 = obj.findMedian()  # 2.0
    if (res1, res2) == (1.5, 2.0):
        print('test1 succeed')
    else:
        print('test1 fail')


if __name__ == '__main__':
    test1()
