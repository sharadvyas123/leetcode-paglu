class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() -1;
        int m = 0;
        while(l <= r){
            m = l + (r - l) / 2;

            if(nums[m] == target){
                return m;
            }
            else if(nums[m] > target){
                r = m -1;
            }
            else{
                l = m +1;
            }
        }

        if (nums[m] > target){
            return m;
        }
        else{
            return m + 1;
        }
    }
};