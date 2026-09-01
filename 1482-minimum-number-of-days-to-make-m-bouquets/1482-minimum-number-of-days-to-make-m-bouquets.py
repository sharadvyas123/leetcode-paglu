class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        n = len(bloomDay)

        if m * k > n:
            return -1
        
        def canMake(day):
            bouquets= 0
            count = 0

            for b in bloomDay:
                if b <= day:
                    count += 1
                    if count == k:
                        bouquets += 1
                        count = 0
                else:
                    count = 0

            return bouquets >= m

        low , high = min(bloomDay) , max(bloomDay)
        ans = high

        while low <= high:
            mid = (low + high) // 2

            if canMake(mid):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        
        return ans