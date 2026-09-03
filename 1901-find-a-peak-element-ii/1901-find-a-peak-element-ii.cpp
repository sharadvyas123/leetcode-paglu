class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int left = 0;
        int right = n -1;

        while(left <= right){
            int mid_col = left + (right - left) / 2;
            int max_row = 0;

            for(int r = 0 ; r <m ; r++){
                if(mat[r][mid_col] > mat[max_row][mid_col]){
                    max_row = r;
                }
            }
            
            int left_val = mid_col >0 ? mat[max_row][mid_col - 1] : -1;
            int right_val = mid_col < n-1 ? mat[max_row][mid_col + 1] : -1;
            if(mat[max_row][mid_col] > left_val  && mat[max_row][mid_col] > right_val){
                return {max_row , mid_col};
            }
            else if(right_val > mat[max_row][mid_col]){
                left = mid_col +1 ;
            }
            else{
                right = mid_col - 1;
            }
        }

        return {};
    }
};