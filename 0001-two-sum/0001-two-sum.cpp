class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int>h;
        vector<int>ans(2);
        for(int i = 0 ;i < nums.size() ; i++){
            h[nums[i]]= i;
        }

        for(int i = 0 ; i < nums.size() ; i++){
            int y = target - nums[i];

            if(h.find(y) != h.end() && h[y] != i){
                ans[0] = i;
                ans[1] = h[y];
                return ans;
            }
        }
        return ans;
    }
};