class Solution:
    def maxProduct(self, n: int) -> int:
        m1 = m2 = 0

        for ch in str(n):
            d = int(ch)
            if d > m1:
                m2 = m1
                m1 = d
            elif d > m2:
                m2 = d
        
        return m1 *m2