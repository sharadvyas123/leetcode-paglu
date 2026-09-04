class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)

        min_suffix = [0] * n
        min_suffix[-1] = nums[-1]

        for i in range(n-2 , -1 , -1):
            min_suffix[i] = min(nums[i] , min_suffix[i+1])
        
        prefix_max = float('-inf')

        for i in range(n):
            prefix_max = max(prefix_max , nums[i])

            score = prefix_max - min_suffix[i]

            if score <= k:
                return i
        
        return -1