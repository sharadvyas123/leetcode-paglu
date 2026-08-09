class Solution {
private:
    int dp[105][105];
    int suffixSum[105];

    int solve(int i, int m, int n) {
        if (i + 2 * m >= n) {
            return suffixSum[i];
        }

        if (dp[i][m] != -1) {
            return dp[i][m];
        }

        int maxStones = 0;

        for (int x = 1; x <= 2 * m; ++x) {
            int currentStones = suffixSum[i] - solve(i + x, max(m, x), n);
            maxStones = max(currentStones, maxStones);
        }

        return dp[i][m] = maxStones;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        memset(dp, -1, sizeof(dp));

        suffixSum[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        return solve(0, 1, n);
    }
};