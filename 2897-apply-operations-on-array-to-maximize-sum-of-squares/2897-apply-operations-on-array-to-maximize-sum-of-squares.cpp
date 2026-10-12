class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long MOD = 1e9 + 7;

        vector<int> bit_counts(31 , 0);

        for (int num : nums){
            for (int i = 0 ; i < 31 ; i++){
                if((num >> i) & 1){
                    bit_counts[i]++;
                }
            }
        }

        long long ans = 0;
        for(int step = 0; step < k ; step++){
            long long current_sum = 0;

            for(int i = 0 ; i < 31 ; i++){
                if(bit_counts[i] > 0){
                    current_sum |= (1LL << i);
                    bit_counts[i]--;
                }
            }
            ans = (ans + (current_sum* current_sum)) % MOD;
        }

        return ans;
    }
};