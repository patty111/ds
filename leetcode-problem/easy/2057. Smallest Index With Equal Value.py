class Solution:
    def smallestEqual(self, nums: List[int]) -> int:
        idx = 2147483647

        for i in range(len(nums)):
            if i % 10 == nums[i]:
                idx = min(idx, i)
        
        if idx == 2147483647:
            return -1
        return idx
