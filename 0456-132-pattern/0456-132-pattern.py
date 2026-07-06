class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        s3 = float("-inf")
        
        stk = []

        for i in range(len(nums) -1 , -1 , -1):
            if nums[i] < s3:
                return True
            else:
                while stk and nums[i] > stk[-1]:
                    s3 = stk[-1]
                    stk.pop()
            stk.append(nums[i])

        return False
