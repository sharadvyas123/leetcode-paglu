class Solution {
public:
    int beautySum(string s) {
        int total_beauty = 0;
        int n = s.length();

        for(int i = 0; i < n ; i++){
            vector<int>freq(26,0);

            for(int j = i ; j < n ; j++){
                freq[s[j] - 'a']++;

                int max_freq = 0;
                int min_freq = INT_MAX;

                for(int count: freq){
                    if(count > 0){
                        max_freq = max(max_freq , count);
                        min_freq = min(min_freq , count);
                    }
                }

                total_beauty += (max_freq - min_freq);
            }
        }

        return total_beauty;
    }
};