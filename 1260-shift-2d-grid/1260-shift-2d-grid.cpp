class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int total_elements = m * n;

        k = k % total_elements;

        vector<vector<int>>result(m , vector<int>(n , 0));

        for(int r = 0; r < m ; r++){
            for(int c = 0 ; c < n ; c++){

                int old_1d_idx = r*n + c;

                int new_1d_idx = (old_1d_idx + k) % total_elements;

                int new_r = new_1d_idx / n;
                int new_c = new_1d_idx % n;

                result[new_r][new_c] =grid[r][c];
            }
        }

        return result;
    }
};