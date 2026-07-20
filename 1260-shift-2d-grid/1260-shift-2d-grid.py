class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m , n = len(grid) , len(grid[0])

        total_element = m * n

        k = k % total_element

        result = [[0] * n for _ in range(m)]

        for r in range(m):
            for c in range(n):

                old_1d_idx = r*n + c
                new_1d_idx = (old_1d_idx + k) % total_element

                new_r = new_1d_idx // n
                new_c = new_1d_idx % n

                result[new_r][new_c] = grid[r][c]

        return result