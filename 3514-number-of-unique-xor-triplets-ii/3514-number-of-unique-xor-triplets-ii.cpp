class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set <int> unique_set(nums.begin() , nums.end());
        vector<int>unique_nums(unique_set.begin() , unique_set.end());

        int m = unique_nums.size();

        unordered_set<int> pair_xors;

        for(int i = 0 ; i < m ; i++){
            for(int j = i ; j < m ; j++){
                pair_xors.insert(unique_nums[i]^ unique_nums[j]);
            }
        }

        unordered_set<int> triplet_xors;
        for(int px : pair_xors){
            for(int num : unique_nums){
                triplet_xors.insert(px ^ num);
            }
        }

        return triplet_xors.size();
    }
};