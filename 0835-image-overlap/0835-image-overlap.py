class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n = len(img1)

        p1 = [( r,c) for r in range(n) for c in range(n) if img1[r][c] == 1]
        p2 = [( r,c) for r in range(n) for c in range(n) if img2[r][c] == 1]

        shift_counts = Counter()

        for r1 , c1 in p1:
            for r2 , c2 in p2:
                shift_counts[(r2-r1 , c2-c1)] += 1
        
        return max(shift_counts.values())if shift_counts else 0
