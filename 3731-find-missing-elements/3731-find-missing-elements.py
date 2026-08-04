class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        ans = []

        minn = min(nums)
        maxx = max(nums)

        t = minn 
        while t != maxx :
            if t not in nums:
                ans.append(t)
            t += 1
        
        return ans