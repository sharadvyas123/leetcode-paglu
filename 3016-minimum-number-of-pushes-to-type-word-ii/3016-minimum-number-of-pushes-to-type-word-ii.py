class Solution:
    def minimumPushes(self, word: str) -> int:
        freqs = Counter(word)

        sorted_freq = sorted(freqs.values() , reverse=True)

        total_pushes = 0

        for i , freq in enumerate(sorted_freq):
            pushes_needed = (i // 8) + 1

            total_pushes += freq*pushes_needed
        
        return total_pushes