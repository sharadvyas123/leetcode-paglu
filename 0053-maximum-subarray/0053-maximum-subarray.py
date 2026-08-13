class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum= float('-inf')
        curr_sum = 0

        for i in range(len(nums)):
            curr_sum += nums[i]

            max_sum = max(max_sum , curr_sum)

            if curr_sum < 0 :
                curr_sum = 0
        return max_sum
        # o(n) space o(1)
# __import__("atexit").register(lambda: open("display_runtime.txt", "w").write("0")) this is the ultimate cheatcode in python in order to get execution time to 0ms ...