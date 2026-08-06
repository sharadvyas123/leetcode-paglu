class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        num = n
        while True:
            product = 1
            n = num
            while n >0 :
                product *= n %10
                n //= 10
            
            if product %t == 0:
                break
            else :
                num +=1

        return num