class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>sett(nums.begin() , nums.end());

        int curr = k;

        while(sett.count(curr)){
            curr += k;
        }

        return curr;
    }
};