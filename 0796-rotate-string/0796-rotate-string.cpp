class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }

        string new_str = s + s;

        if(new_str.contains(goal)){
            return true;
        }
        else{
            return false;
        }
    }
};