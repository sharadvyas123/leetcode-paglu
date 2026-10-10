from collections import Counter

class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int], k1: int, k2: int) -> int:
        k = k1 + k2
        
        # Calculate absolute differences
        diffs = [abs(a - b) for a, b in zip(nums1, nums2)]
        
        total_diff = sum(diffs)
        # If total operations available exceed total difference, result is 0
        if total_diff <= k:
            return 0
        
        # Count frequency of each difference value
        count = Counter(diffs)
        max_diff = max(count.keys())
        
        # Bucket-sort / Counting array approach: diff_count[d] = frequency of difference d
        diff_count = [0] * (max_diff + 1)
        for diff, cnt in count.items():
            diff_count[diff] = cnt
            
        # Greedily reduce the largest differences first
        for d in range(max_diff, 0, -1):
            if diff_count[d] == 0:
                continue
                
            cnt = diff_count[d]
            if k >= cnt:
                # We can reduce all elements of magnitude 'd' down to 'd - 1'
                k -= cnt
                diff_count[d - 1] += cnt
                diff_count[d] = 0
            else:
                # We can only reduce 'k' elements of magnitude 'd' down to 'd - 1'
                diff_count[d] -= k
                diff_count[d - 1] += k
                k = 0
                break
                
        # Calculate final sum of squared differences
        return sum(d * d * cnt for d, cnt in enumerate(diff_count))