class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1

        water = (r - l) * min(height[l], height[r])

        while l != r:
            if height[l] > height[r]:
                r = r-1
            else:
                l = l+1
            water = max(abs(l-r) * min(height[l], height[r]), water)

        return water