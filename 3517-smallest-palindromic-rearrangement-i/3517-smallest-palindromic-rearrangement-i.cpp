class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();

        int half_len = n /2;
        string left_half =s.substr(0 ,half_len);

        sort(left_half.begin() , left_half.end());

        string right_half = left_half;
        reverse(right_half.begin() , right_half.end());

        string mid = (n%2 != 0) ? string(1 , s[half_len]) : "";

        return left_half + mid + right_half;

    }
};