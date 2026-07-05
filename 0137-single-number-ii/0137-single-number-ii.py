class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0

        for i in range(32):
            bit_sum = 0
            for num in nums :
                bit_sum += (num >> i) & 1
            
            if bit_sum % 3 != 0:

                if i == 31 :
                    ans -= ( 1 << i)
                else :
                    ans |= (1 << i)
        
        return ans