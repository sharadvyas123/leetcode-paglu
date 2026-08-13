class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0

        for num in nums :
            ans = ans ^ num
        return ans
        
# have n ^ n = 0 thay so dups hati jaay ane khalie unique rai jaay 