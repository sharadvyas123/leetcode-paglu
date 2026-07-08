class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0 or x == 1 :
            return x
        
        start = 1
        end = x
        mid = -1


        while start <= end :
            mid = start + (end - start ) // 2

            sqr_mid = mid *mid

            if sqr_mid > x :
                end = mid -1
            elif sqr_mid == x :
                return mid
            else :
                start = mid +1

        return round(int(end))