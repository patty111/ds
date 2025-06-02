class Solution:
    def isArraySpecial(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True
        stat = -1
        for i in nums:
            prev = stat
            if i % 2 == 0:
                stat = 2
            else:
                stat = 1
            if stat == prev:
                return False
        return True
            