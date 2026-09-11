class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        freq = Counter(digits)
        ans = 0

        for num in range(100, 1000, 2):
            d1, d2, d3 = num // 100, (num // 10) % 10, num % 10

            needed = Counter([d1, d2, d3])
            
            if all(freq[d] >= count for d, count in needed.items()):
                ans += 1

        
        return ans