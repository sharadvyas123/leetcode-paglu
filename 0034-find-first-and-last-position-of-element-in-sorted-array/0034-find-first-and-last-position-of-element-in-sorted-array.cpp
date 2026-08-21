class Solution {
private:
int binarySearch(vector<int>&nums ,int target, bool is_true){
    int l = 0 , r = nums.size() -1;
    int idx = -1;

    while(l<= r){
        int m = l + (r - l) /2;
        if(nums[m] == target){
            idx = m;
            if(is_true){
                r = m -1;
            }
            else{
                l = m + 1;
            }
        }
        else if(nums[m] < target){
            l = m + 1;
        }
        else{
            r = m-1;
        }
    }

    return idx;
}
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarySearch(nums ,target,true) , binarySearch(nums,target,false)};
    }
};