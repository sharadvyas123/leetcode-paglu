class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        def canSplit(max_sum)->bool:
            subarrays = 1
            current_sum = 0

            for num in nums:
                if current_sum + num > max_sum:
                    subarrays += 1
                    current_sum = num
                else:
                    current_sum += num
            
            return subarrays <= k
        
        low = max(nums)
        high = sum(nums)
        ans = high

        while low <= high:
            mid = (low + high) // 2

            if canSplit(mid):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        
        return ans