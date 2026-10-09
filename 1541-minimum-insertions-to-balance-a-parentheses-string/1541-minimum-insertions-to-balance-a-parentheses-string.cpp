class Solution {
public:
    int minInsertions(string s) {
        int right = 0;
        int res = 0;

        for(char c : s){
            if(c == '('){
                right += 2;
                if(right % 2 == 1){
                    res++;
                    right--;;
                }
            }

            else{
                right--;
                if(right < 0){
                    res++;
                    right += 2;
                }
            }

        }
        return right + res;
    }
};