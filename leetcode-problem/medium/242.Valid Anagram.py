from collections import defaultdict

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        d = defaultdict(int)
        
        for i in s:
            d[i] += 1
        for j in t:
            d[j] -= 1


        for i in d.values():
            if i != 0:
                return False

        return True