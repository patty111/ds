class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        tmp = heights
        tmp = sorted(tmp)

        count = 0
        for i in range(len(tmp)):
            if tmp[i] != heights[i]:
                count += 1
        
        return count