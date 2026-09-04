class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_length = INT_MAX;

        for(string s : strs){
            if(s.length() < min_length){
                min_length = s.length();
            }
        }

        int i = 0;

        while(i < min_length){
            for(string s :strs){
                if(s[i] != strs[0][i]){
                    return s.substr(0 , i);
                }
            }
            i++;
        }

        return strs[0].substr(0,i);
    }
};