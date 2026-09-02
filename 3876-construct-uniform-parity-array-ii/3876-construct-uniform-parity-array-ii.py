class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        min_odd = float('inf')
        min_even = float('inf')

        for num in nums1:
            if num & 1:
                min_odd = min(min_odd , num)
            else:
                min_even = min(min_even , num)
            
        # we found all one sided number (all even or all odd)
        if min_odd == float('inf') or min_even == float("inf"):
            return True
        
        # if min even is greater then odd then we can make all the values odd 
        return min_even > min_odd
        