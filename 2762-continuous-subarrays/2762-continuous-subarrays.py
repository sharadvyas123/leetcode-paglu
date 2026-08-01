class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        left = 0
        ans = 0
        max_q = deque()
        min_q = deque()

        for right in range(len(nums)):
            while max_q and max_q[-1] < nums[right]:
                max_q.pop()
            max_q.append(nums[right])
        
            while min_q and min_q[-1] >nums[right]:
                min_q.pop()
            min_q.append(nums[right])

        
            while max_q[0] - min_q[0] > 2:
                if max_q[0] == nums[left]:
                    max_q.popleft()
                if min_q[0] == nums[left]:
                    min_q.popleft()
                
                left += 1
            
            ans += (right - left + 1)

        return ans