class Solution:
    def maxProduct(self, n: int) -> int:
        digits = sorted(list(int(d) for d in str(n)))

        return digits[-1] * digits[-2]