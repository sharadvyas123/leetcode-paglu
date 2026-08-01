class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>>memo(nums.size() , vector<int>(nums.size() , -1));

        int res = solve(0,nums.size() -1 , nums , memo);
        return res >= 0 ? true : false; 

    }
private:
    int solve(int i , int j , vector<int> & nums, vector<vector<int>>& memo){
        if(i == j){
            return nums[i];
        }

        if(memo[i][j] != -1){
            return memo[i][j];
        }

        int left = nums[i] - solve(i+1 , j , nums,memo);
        int right = nums[j]-solve(i , j -1 , nums , memo);

        memo[i][j] = max(left , right);

        return memo[i][j];
    }
};