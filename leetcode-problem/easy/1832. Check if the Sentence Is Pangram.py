class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        a = set(chr(i+ord('a')) for i in range(0, 26))

        for i in a:
            if i in sentence:
                continue
            return False
        return True
