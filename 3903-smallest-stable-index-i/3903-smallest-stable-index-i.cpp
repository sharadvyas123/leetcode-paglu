class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>min_suffix(n , 0);
        min_suffix[n-1] = nums[n-1];

        for(int i = n-2 ; i >= 0 ; i--){
            min_suffix[i] = min(nums[i] , min_suffix[i+1]);
        }
        
        int prefix_max = INT_MIN;

        for(int i = 0 ; i < n ; i++){
            prefix_max = max(prefix_max , nums[i]);

            if (prefix_max - min_suffix[i] <= k){
                return i;
            }
        }
        return -1;
    }
};