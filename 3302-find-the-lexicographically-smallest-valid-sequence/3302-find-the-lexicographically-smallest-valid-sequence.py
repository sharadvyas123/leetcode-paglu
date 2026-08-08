class Solution:
    def validSequence(self, word1: str, word2: str) -> list[int]:
        n, m = len(word1), len(word2)
        last = [-1] * m
        
        ptr = n - 1
        for j in range(m - 1, -1, -1):
            while ptr >= 0 and word1[ptr] != word2[j]:
                ptr -= 1
            if ptr >= 0:
                last[j] = ptr
                ptr -= 1

        result = []
        changed = False
        word1_idx = 0

        for word2_idx in range(m):
            found = False

            while word1_idx < n:
                if word1[word1_idx] == word2[word2_idx]:
                    result.append(word1_idx)
                    word1_idx += 1
                    found = True
                    break
                
                if not changed:
                    if word2_idx == m - 1 or last[word2_idx + 1] > word1_idx:
                        result.append(word1_idx)
                        word1_idx += 1
                        changed = True
                        found = True
                        break

                word1_idx += 1

            if not found:
                return []

        return result