from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        d = defaultdict(list)

        for i in strs:
            d[''.join(sorted(i))].append(i)
            

        return d.values()