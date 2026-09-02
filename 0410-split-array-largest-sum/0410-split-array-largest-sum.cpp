class Solution {
private:
    bool canSplit(vector<int>&nums , int k , int max_sum){
        int subarrays = 1;
        int currentSum = 0;

        for(int num : nums){
            if(currentSum + num > max_sum){
                subarrays++;
                currentSum = num;
            }
            else{
                currentSum += num;
            }
        }

        return subarrays <= k;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin() , nums.end());
        int high = accumulate(nums.begin() , nums.end() , 0);
        int ans = high;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canSplit(nums , k , mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};