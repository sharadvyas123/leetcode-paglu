class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        ans = nums[0]

        i = 1
        while i < len(nums) and nums[i] == nums[i-1] + 1:
            ans += nums[i]
            i += 1
    
        sett = set(nums)

        while ans in sett:
            ans += 1
        return ans