class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int L = 0;
        int R = n -1;

        while(L < R){
            if(!isalnum(s[L])){
                L++;
                continue;
            }
            if(!isalnum(s[R])){
                R--;
                continue;
            }

            if(tolower(s[L]) != tolower(s[R])){
                return false;
            }

            L++;
            R--;
        }
        return true;
    }
};