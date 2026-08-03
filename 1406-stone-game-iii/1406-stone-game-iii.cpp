class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int>dp(n+1 , 0);

        for(int i = n-1 ; i >=0 ; i--){
            dp[i] = INT_MIN;
            int take_sum = 0;

            for(int k = 1 ; k < 4 ; k++){
                if(i+k <= n){
                    take_sum += stoneValue[i+k-1];
                    dp[i] = max(dp[i] , take_sum - dp[i+k]);
                }
            }
        }

        if(dp[0] >0){
            return "Alice";
        }
        else if(dp[0] < 0){
            return "Bob";
        }
        else{
            return "Tie";
        }
    }
};