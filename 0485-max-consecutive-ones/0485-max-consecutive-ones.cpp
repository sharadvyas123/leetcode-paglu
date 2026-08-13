class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxx = 0;

        for(int i : nums){
            if(i == 1){
                count++;
            }
            else{
                if(count>maxx){
                    maxx = count;
                }
                count = 0;
            }
        }

        if(count > maxx){
            maxx = count;
        }
        return maxx;
    }
};