class Solution:

    def __init__(self, nums: List[int]):
        self.origin = nums
        self.l = len(nums)

    def reset(self) -> List[int]:
        return self.origin

    def shuffle(self) -> List[int]:
        res = self.origin[:]
        for i in range(self.l):
            j = randint(i, self.l-1)
            res[i], res[j] = res[j], res[i]
        return res

# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()