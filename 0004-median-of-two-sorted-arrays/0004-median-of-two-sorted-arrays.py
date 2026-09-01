class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        
        m , n = len(nums1) , len(nums2)
        p1 = p2 = 0

        def get_min():
            nonlocal p1 , p2
            if p1 < m and p2 < n :
                if nums1[p1] < nums2[p2]:
                    val = nums1[p1]
                    p1 += 1
                    return val
                else:
                    val = nums2[p2]
                    p2 += 1
                    return val
            
            elif p1 < m :
                val = nums1[p1]
                p1 += 1
                return val
            elif p2 < n:
                val = nums2[p2]
                p2 += 1
                return val

        if (m + n) % 2 == 0:
            for _ in range(((m + n) // 2) - 1):
                get_min()
            return (get_min() + get_min()) / 2.0
        else:
            for _ in range((m + n) // 2):
                get_min()
            return float(get_min())