class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        memo = {}

        def maxDiff(i , j):
            if i == j:
                return nums[i]
            
            if (i , j) in memo:
                return memo[(i,j)]
            

            left = nums[i] - maxDiff(i+1 , j)
            right = nums[j] - maxDiff(i , j-1)
        
            memo[(i,j)] = max(left , right)
        
            return memo[(i,j)]
        
        return maxDiff(0,len(nums) -1) >=0
        
