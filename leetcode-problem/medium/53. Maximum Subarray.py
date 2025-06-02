class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curr_sum = 0
        m_sum = nums[0]
        

        for i in nums:
            if (i + curr_sum) > i:
                curr_sum = i + curr_sum
            else:
                curr_sum = i
            
            m_sum = max(curr_sum, m_sum)
        return m_sum