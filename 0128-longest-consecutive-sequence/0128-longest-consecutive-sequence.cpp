class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin() , nums.end());
        int longest = 0;

        for(const auto& num : s){
            if(!s.count(num-1)){
                int nextNum = num + 1;
                int length = 1;
                while (s.count(nextNum)){
                    nextNum++;
                    length++;
                }
                longest =max(longest , length); 
            }
        }
        return longest;
    }
};