class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;

        vector<long long>dp(26 , 0);

        for(char c : s){
            int idx = c - 'a';

            long long current_sum = 0;
            for(int count : dp){
                current_sum = (current_sum + count) % MOD;
            }

            dp[idx] = (current_sum + 1) % MOD;
        }

        long long ans = 0;
        for (int count : dp) {
            ans = (ans + count) % MOD;
        }

        return ans;
    }
};