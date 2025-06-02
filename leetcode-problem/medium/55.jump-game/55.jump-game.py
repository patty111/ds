class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maximum = nums[0]
        for i in range(1, len(nums)):
            if maximum < i:
                return False
            maximum = max(maximum, i + nums[i])
        return True
