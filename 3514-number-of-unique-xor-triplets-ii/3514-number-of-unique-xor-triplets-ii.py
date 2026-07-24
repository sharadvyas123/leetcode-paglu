class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        unique_nums = list(set(nums))

        m = len(unique_nums)

        pair_xors = set()
        for i in range(m):
            for j in range(i , m):
                pair_xors.add(unique_nums[i] ^ unique_nums[j])

        triplet_xors = set()

        for px in pair_xors:
            for num in unique_nums:
                triplet_xors.add(px ^ num)
        
        return len(triplet_xors)