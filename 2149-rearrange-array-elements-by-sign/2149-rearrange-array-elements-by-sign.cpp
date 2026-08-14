class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n , 0);
        int pos_idx = 0;
        int neg_idx = 1;

        for(int num : nums){
            if (num > 0){
                ans[pos_idx] = num;
                pos_idx += 2;
            }
            else if(num < 0){
                ans[neg_idx] = num;
                neg_idx += 2;
            }
        }
        return ans;
    }
};