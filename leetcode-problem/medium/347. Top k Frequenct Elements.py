from collections import defaultdict

class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        d = defaultdict(int)

        for i in nums:
            d[i] += 1
        
        d = sorted(d.items(), key=lambda x:x[1], reverse=True)
        
        ans = []
        for i in range(k):
            ans.append(d[i][0])
        
        return ans
