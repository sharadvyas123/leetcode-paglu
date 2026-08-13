class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxx = 0
        count = 0
        for i in nums:
            if i == 1:
                count += 1
            else:
                maxx = max(maxx , count)
                count = 0
        
        maxx = max(maxx , count)
        return maxx