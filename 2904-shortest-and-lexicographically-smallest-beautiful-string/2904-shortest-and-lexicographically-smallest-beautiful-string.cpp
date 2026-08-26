class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int totalOnes = 0;
        for(char c : s){
            if (c == '1') totalOnes++;
        }

        if( totalOnes < k) return "";

        int n = s.length();
        int left = 0;
        int onesCount = 0;
        int minLen = n + 1;
        string ans = "";

        for(int right = 0 ; right < n ; right++){
            if(s[right]== '1'){
                onesCount++;
            }

            while (onesCount == k) {
                while (s[left] == '0') {
                    left++;
                }
                int currLen = right - left + 1;
                string sub = s.substr(left , currLen);

                if (currLen < minLen){
                    minLen = currLen;
                    ans = sub;
                }
                else if (currLen== minLen){
                    if(ans.empty() || sub < ans){
                        ans = sub;
                    }
                }

                onesCount--;
                left++;
            }
        }

        return ans;
    }
};