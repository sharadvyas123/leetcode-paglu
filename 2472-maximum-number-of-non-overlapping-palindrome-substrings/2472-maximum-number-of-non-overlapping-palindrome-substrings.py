class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        n = len(s)
        ans = 0
        last_end = 0

        for i in range(n):
            for l , r in [(i,i) , (i,i+1)]:
                while l >= last_end and r < n and s[l]==s[r]:
                    if r - l + 1 >= k:
                        ans += 1
                        last_end = r + 1
                        break
                    
                    l -= 1
                    r += 1
        
                if l >= 0 and r < n and last_end == r + 1:
                    break
        
        return ans