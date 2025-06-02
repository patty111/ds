class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        # Handle empty array case
        if not nums:
            return [-1, -1]
            
        l = 0
        r = len(nums) - 1
        
        left_bound = -1
        right_bound = -1
        
        # Find the leftmost index of target
        while l <= r:
            mid = (l + r) // 2

            if nums[mid] > target:
                r = mid - 1
            elif nums[mid] < target:
                l = mid + 1
            elif nums[mid] == target:
                left_bound = mid
                r = mid - 1
                
                
        # find the rightmost index of target
        l = 0
        r = len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] > target:
                r = mid - 1
            elif nums[mid] < target:
                l = mid + 1
            elif nums[mid] == target:
                right_bound = mid
                l = mid + 1

        # If target wasn't found at all
        if left_bound == -1 or right_bound == -1:
            return [-1, -1]
        
        return [left_bound, right_bound]