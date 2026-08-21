class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        def merge_sort(low , high):
            if low >= high:
                return 0
            
            mid = (low + high) // 2

            count = merge_sort(low , mid)  + merge_sort(mid + 1 , high)

            j = mid + 1
            for i in range(low , mid + 1):
                while j <= high and nums[i] > 2*nums[j]:
                    j += 1
                count += j - (mid +1)
            
            temp = []
            left , right = low , mid + 1

            while left <= mid and right <= high:
                if nums[left] <= nums[right]:
                    temp.append(nums[left])
                    left += 1
                else:
                    temp.append(nums[right])
                    right += 1
            while left <= mid:
                temp.append(nums[left])
                left += 1
            while right <= high:
                temp.append(nums[right])
                right += 1
            
            for i in range(len(temp)):
                nums[low + i] = temp[i]
            
            return count

        return merge_sort(0,len(nums)- 1)