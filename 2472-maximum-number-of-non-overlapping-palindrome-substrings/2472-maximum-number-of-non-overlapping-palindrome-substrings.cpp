class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n= s.length();
        int ans = 0;
        int last_end = 0;

        for(int i = 0 ; i < n ; i++){
            vector<pair<int,int>>centers = {{i,i} , {i,i+1}};
            for(auto&[l,r] : centers){
                while(l>= last_end && r < n && s[l]== s[r]){
                    if(r - l + 1 >= k){
                        ans++;
                        last_end = r +1;
                        break;
                    }
                    l--;
                    r++;
                }

                if(l >= 0 && r < n && last_end == r + 1){
                    break;
                }
            }
        }

        return ans;

    }
};