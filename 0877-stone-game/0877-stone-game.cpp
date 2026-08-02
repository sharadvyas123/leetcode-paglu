class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        
        // dp[i][j] stores the max net score difference (current player - opponent) for piles[i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: subproblems of length 1 (only one pile remaining)
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        // Build the table for subproblem lengths from 2 up to n
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;
                
                dp[i][j] = max(
                    piles[i] - dp[i + 1][j],
                    piles[j] - dp[i][j - 1]
                );
            }
        }

        // If the score difference for the whole array is > 0, Alice wins
        return dp[0][n - 1] > 0;
    }
};