class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_dict = {}
        for i, num in enumerate(nums):
            tmp = target - num
            if tmp in nums_dict:
                return [nums_dict[tmp], i]
            nums_dict[num] = i
        return []