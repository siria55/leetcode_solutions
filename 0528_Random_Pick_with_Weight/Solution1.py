import random

class Solution:

    def __init__(self, w: List[int]):
        self.N = len(w)
        self.presum = [0] * (self.N + 1)
        for i in range(1, self.N + 1):
            self.presum[i] = self.presum[i-1] + w[i-1]

    def pickIndex(self) -> int:
        target = random.randint(1, self.presum[-1])
        l, r = 1, self.N + 1
        while l < r:
            mid = l + (r - l) // 2
            if self.presum[mid] >= target:
                r = mid
            else:
                l = mid + 1

        return r - 1



# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
