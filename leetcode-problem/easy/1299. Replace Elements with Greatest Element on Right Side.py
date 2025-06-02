class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        n = len(arr)

        res = []
        for i in range(n-1):
            res.append(max(arr[i+1:]))
            print(res)

        res.append(-1)
        
        return res