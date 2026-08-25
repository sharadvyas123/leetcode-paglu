class Solution {
private:
    bool kWorks(int k , vector<int>&nums , int h){
        int hours = 0;
        for(int p : nums){
            hours += (p + k - 1) / k;
        }

        return hours <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin() , piles.end());

        while(l < r){
            int k = l + (r - l)/2;
            if(kWorks(k , piles, h)){
                r = k;
            }
            else{
                l = k + 1;
            }
        }

        return l;
    }
};