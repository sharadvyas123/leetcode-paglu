class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int bal = 0;

        for(char c : s){
            if(c == '('){
                bal++;
            }
            else{
                bal--;

                if(bal < 0){
                    ans++;
                    bal = 0;
                }
            }
        }

        ans += bal;
        return ans;
    }
};