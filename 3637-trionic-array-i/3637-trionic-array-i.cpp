class Solution {
public:
    bool isDescreasing(vector<int>& arr , int a , int b){
        if(a==0 || b==arr.size()-1) return false;
        for(int i = a; i < b ; i++){
            if(arr[i] <= arr[i+1])return false;
        }
        return true;
    }
    bool isTrionic(vector<int>& nums) {
        int n = nums.size() , peak = n-1 , valley = 0;
        for(int i=0;i < n-1 ;i++){
            if(peak == n-1  && nums[i] >= nums[i+1]){
                peak = i;
            }
            if(valley == 0 && nums[n-i-1] <= nums[n-2-i]){
                valley =n-i-1;
            }
            if(peak < valley){
                return isDescreasing(nums,peak , valley);
            }
        }
        return false;
    }
};