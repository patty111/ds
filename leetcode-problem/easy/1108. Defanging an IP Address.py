class Solution:
    def defangIPaddr(self, address: str) -> str:
        w = []
        for i in address:
            if i != '.':
                w.append(i)
            else:
                w.append('[')
                w.append('.')
                w.append(']')
        return ''.join(w)