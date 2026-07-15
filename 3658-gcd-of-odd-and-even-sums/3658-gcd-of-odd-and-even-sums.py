class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        # return n can do it but for god sake ! 
        e = 0
        o = 0

        for num in range(1 , 2*n + 1):
            if num % 2 == 0 :
                e += num 
            else :
                o += num
        
        def g(a , b):
            if a > b: return g(a - b, b)
            elif b > a: return g(a, b - a)
            return b

        return g(e , o)