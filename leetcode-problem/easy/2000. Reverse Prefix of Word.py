class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        if ch not in word:
            return word
        idx = word.index(ch)

        result = word[0:idx+1][::-1] + word[idx+1:]
        
        return result